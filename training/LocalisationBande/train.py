import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader
import torchvision
from torchvision.models.detection import maskrcnn_resnet50_fpn
from torchvision.models.detection.faster_rcnn import FastRCNNPredictor
from torchvision.models.detection.mask_rcnn import MaskRCNNPredictor
import json
import os
from PIL import Image
import numpy as np
from pycocotools import mask as coco_mask
import albumentations as A
from albumentations.pytorch import ToTensorV2
import cv2

class COCODataset(Dataset):
    def __init__(self, img_dir, ann_file, transforms=None):
        self.img_dir = img_dir
        self.transforms = transforms
        
        # Load COCO annotations
        with open(ann_file, 'r') as f:
            self.coco_data = json.load(f)
        
        # Create image id to annotations mapping
        self.imgs = {img['id']: img for img in self.coco_data['images']}
        self.img_ids = list(self.imgs.keys())
        
        # Group annotations by image
        self.img_to_anns = {}
        for ann in self.coco_data['annotations']:
            img_id = ann['image_id']
            if img_id not in self.img_to_anns:
                self.img_to_anns[img_id] = []
            self.img_to_anns[img_id].append(ann)
        
        # Get category info
        self.categories = {cat['id']: cat['name'] for cat in self.coco_data['categories']}
        self.num_classes = len(self.categories) + 1  # +1 for background
        
    def __len__(self):
        return len(self.img_ids)
    
    def __getitem__(self, idx):
        img_id = self.img_ids[idx]
        img_info = self.imgs[img_id]
        img_path = os.path.join(self.img_dir, img_info['file_name'])
        
        # Load image
        img = cv2.imread(img_path)
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        
        # Get annotations for this image
        anns = self.img_to_anns.get(img_id, [])
        
        boxes = []
        labels = []
        masks = []
        
        for ann in anns:
            # Get bounding box
            x, y, w, h = ann['bbox']
            boxes.append([x, y, x + w, y + h])
            labels.append(ann['category_id'])
            
            # Convert segmentation to mask
            if 'segmentation' in ann:
                if isinstance(ann['segmentation'], list):
                    # Polygon format
                    mask = np.zeros((img_info['height'], img_info['width']), dtype=np.uint8)
                    for seg in ann['segmentation']:
                        pts = np.array(seg).reshape(-1, 2).astype(np.int32)
                        cv2.fillPoly(mask, [pts], 1)
                    masks.append(mask)
                elif isinstance(ann['segmentation'], dict):
                    # RLE format
                    rle = ann['segmentation']
                    mask = coco_mask.decode(rle)
                    masks.append(mask)
        
        # Convert to tensors
        boxes = torch.as_tensor(boxes, dtype=torch.float32)
        labels = torch.as_tensor(labels, dtype=torch.int64)
        masks = torch.as_tensor(np.array(masks), dtype=torch.uint8)
        
        target = {
            'boxes': boxes,
            'labels': labels,
            'masks': masks,
            'image_id': torch.tensor([img_id])
        }
        
        # Apply transformations
        if self.transforms:
            transformed = self.transforms(image=img, masks=masks.numpy())
            img = transformed['image']
            target['masks'] = torch.as_tensor(transformed['masks'], dtype=torch.uint8)
        else:
            img = torch.from_numpy(img).permute(2, 0, 1).float() / 255.0
        
        return img, target


def get_model(num_classes):
    # Load pretrained Mask R-CNN model
    model = maskrcnn_resnet50_fpn(pretrained=True)
    
    # Replace box predictor
    in_features = model.roi_heads.box_predictor.cls_score.in_features
    model.roi_heads.box_predictor = FastRCNNPredictor(in_features, num_classes)
    
    # Replace mask predictor
    in_features_mask = model.roi_heads.mask_predictor.conv5_mask.in_channels
    hidden_layer = 256
    model.roi_heads.mask_predictor = MaskRCNNPredictor(in_features_mask, hidden_layer, num_classes)
    
    return model


def get_transforms(train=True):
    if train:
        return A.Compose([
            A.HorizontalFlip(p=0.5),
            A.RandomBrightnessContrast(p=0.2),
            A.Resize(800, 800),
            A.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]),
            ToTensorV2()
        ])
    else:
        return A.Compose([
            A.Resize(800, 800),
            A.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]),
            ToTensorV2()
        ])


def collate_fn(batch):
    return tuple(zip(*batch))


def train_one_epoch(model, optimizer, data_loader, device, epoch):
    model.train()
    total_loss = 0
    
    for i, (images, targets) in enumerate(data_loader):
        images = list(img.to(device) for img in images)
        targets = [{k: v.to(device) for k, v in t.items()} for t in targets]
        
        loss_dict = model(images, targets)
        losses = sum(loss for loss in loss_dict.values())
        
        optimizer.zero_grad()
        losses.backward()
        optimizer.step()
        
        total_loss += losses.item()
        
        if i % 10 == 0:
            print(f"Epoch [{epoch}], Step [{i}/{len(data_loader)}], Loss: {losses.item():.4f}")
    
    return total_loss / len(data_loader)


def main():
    # Configuration
    IMG_DIR = 'data/images'
    ANN_FILE = 'data/masks/annotations.json'
    OUTPUT_DIR = 'models'  # Directory to save trained models
    BATCH_SIZE = 2
    NUM_EPOCHS = 50
    LEARNING_RATE = 0.005
    DEVICE = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    
    # Create output directory if it doesn't exist
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    
    print(f"Using device: {DEVICE}")
    print(f"Models will be saved to: {OUTPUT_DIR}")
    
    # Create dataset
    dataset = COCODataset(
        img_dir=IMG_DIR,
        ann_file=ANN_FILE,
        transforms=get_transforms(train=True)
    )
    
    print(f"Dataset size: {len(dataset)} images")
    print(f"Number of classes: {dataset.num_classes}")
    
    # Split dataset (80% train, 20% validation)
    train_size = int(0.8 * len(dataset))
    val_size = len(dataset) - train_size
    train_dataset, val_dataset = torch.utils.data.random_split(dataset, [train_size, val_size])
    
    # Create data loaders
    train_loader = DataLoader(
        train_dataset,
        batch_size=BATCH_SIZE,
        shuffle=True,
        num_workers=4,
        collate_fn=collate_fn
    )
    
    val_loader = DataLoader(
        val_dataset,
        batch_size=BATCH_SIZE,
        shuffle=False,
        num_workers=4,
        collate_fn=collate_fn
    )
    
    # Create model
    model = get_model(dataset.num_classes)
    model.to(DEVICE)
    
    # Optimizer
    params = [p for p in model.parameters() if p.requires_grad]
    optimizer = optim.SGD(params, lr=LEARNING_RATE, momentum=0.9, weight_decay=0.0005)
    lr_scheduler = optim.lr_scheduler.StepLR(optimizer, step_size=10, gamma=0.1)
    
    # Training loop
    best_loss = float('inf')
    
    for epoch in range(NUM_EPOCHS):
        print(f"\n{'='*50}")
        print(f"Epoch {epoch+1}/{NUM_EPOCHS}")
        print(f"{'='*50}")
        
        train_loss = train_one_epoch(model, optimizer, train_loader, DEVICE, epoch)
        lr_scheduler.step()
        
        print(f"Average Training Loss: {train_loss:.4f}")
        
        # Save checkpoint
        if train_loss < best_loss:
            best_loss = train_loss
            model_path = os.path.join(OUTPUT_DIR, 'best_model.pth')
            torch.save({
                'epoch': epoch,
                'model_state_dict': model.state_dict(),
                'optimizer_state_dict': optimizer.state_dict(),
                'loss': train_loss,
                'num_classes': dataset.num_classes,
                'categories': dataset.categories
            }, model_path)
            print(f"✓ Saved best model to: {model_path} (loss: {train_loss:.4f})")
        
        # Save regular checkpoint every 5 epochs
        if (epoch + 1) % 5 == 0:
            checkpoint_path = os.path.join(OUTPUT_DIR, f'checkpoint_epoch_{epoch+1}.pth')
            torch.save({
                'epoch': epoch,
                'model_state_dict': model.state_dict(),
                'optimizer_state_dict': optimizer.state_dict(),
                'loss': train_loss,
                'num_classes': dataset.num_classes,
                'categories': dataset.categories
            }, checkpoint_path)
            print(f"✓ Saved checkpoint to: {checkpoint_path}")
    
    print("\n" + "="*50)
    print("Training completed!")
    print("="*50)


if __name__ == '__main__':
    main()