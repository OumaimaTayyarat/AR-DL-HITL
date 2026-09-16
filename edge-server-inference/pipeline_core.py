# ============================================================
#  PIPELINE CORE — chargement des modèles + fonctions de traitement
#  (sans la boucle vidéo — utilisé par serveur_api.py)
# ============================================================

import os
import cv2
import numpy as np
import torch
import torch.nn.functional as F
import albumentations as A
from albumentations.pytorch import ToTensorV2
import segmentation_models_pytorch as smp
from ultralytics import YOLO
from pathlib import Path
from torchvision import ops
from torchvision.models.detection import maskrcnn_resnet50_fpn
from torchvision.models.detection.faster_rcnn import FastRCNNPredictor
from torchvision.models.detection.mask_rcnn import MaskRCNNPredictor

# ============================================================
#  CONFIGURATION
# ============================================================
from pathlib import Path

BASE_DIR = Path(r"C:\Users\usermco\Documents\SegBande")

CFG = {
    "img_dir_lot1" : str(BASE_DIR / "Lot1" / "images"),
    "ann_lot1"     : str(BASE_DIR / "Lot1" / "instances_default.json"),
    "img_dir_lot3" : str(BASE_DIR / "Lot3" / "augmented_images_final"),
    "ann_lot3"     : str(BASE_DIR / "Lot3" / "augmented_annotations_final.json"),

    "stats_dir"        : str(BASE_DIR / "stats"),
    "yolo_dataset_dir" : str(BASE_DIR / "yolo_pantograph"),
    "yolo_output_dir"  : str(BASE_DIR / "runs" / "detect" / "yolo_runs"),
    "hard_neg_dir"     : str(BASE_DIR / "hard_negatives_v4"),
    "roi_crops_dir"    : str(BASE_DIR / "roi_crops_v4"),
    "merged_ann"       : str(BASE_DIR / "merged_v4_annotations.json"),
    "seg_output_dir"   : str(BASE_DIR / "models_v4"),

    "yolo_model"       : "yolov8n.pt",
    "yolo_epochs"      : 150,
    "yolo_imgsz"       : 640,
    "yolo_batch"       : 8,
    "yolo_conf_thresh" : 0.4,
    "roi_margin_pct"   : 0.15,

    "batch_size"      : 4,
    "num_epochs"      : 40,
    "lr_from_scratch" : 0.005,
    "lr_finetune"     : 0.0002,
    "weight_decay"    : 0.0005,
    "patience"        : 10,
    "pretrained_ckpt" : None,
    "w_lot1"          : 1.0,
    "w_lot3"          : 2.5,
    "n_hard_neg"      : 150,
    "seed"            : 42,
    "device"          : "cuda" if torch.cuda.is_available() else "cpu",

    "score_thresh"    : 0.7,

    # ── Seuils calibrés sur les vraies annotations (Lot1 + Lot3) ────
    # Calculés une fois hors-ligne via percentiles (p1/p99 + marge de
    # sécurité) sur les bounding boxes réelles. Ne pas recalculer à
    # chaque démarrage du serveur — uniquement si le dataset d'entraînement
    # change significativement.
    "min_aspect_ratio": 0.82,
    "min_area":         561,
    "max_area":         1652737,
}

device = torch.device(CFG["device"])

# ── Couleurs overlay (reprises telles quelles, utile si tu veux debug) ──
CRACK_COLOR     = (0, 0, 255)
ECAILLE_COLOR   = (0, 165, 255)
THICKNESS_COLOR = (255, 255, 0)
ALPHA_DEFECT    = 0.6

# ── Seuils déclenchement alerte ──────────────────────────────
DEFECT_PCT_ALERT  = 0.05
ECAILLE_PCT_ALERT = 0.5

# ── Mesure d'épaisseur — calibration px → mm ─────────────────
KNOWN_BAND_LENGTH_MM       = 500
PX_PER_MM_DEFAULT          = 8.7
MIN_THICKNESS_MM_THRESHOLD = 10.0


# ============================================================
#  0. CHARGEMENT DES MODÈLES
# ============================================================

# ── YOLO (détection de la bande / ROI) ───────────────────────
yolo_inf = YOLO('runs\detect\yolo_runs\pantograph_roi_zoomout-2\weights/best.pt')

# ── Modèle de segmentation (Mask R-CNN) ──────────────────────
def get_model(num_classes, pretrained_ckpt=None):
    model = maskrcnn_resnet50_fpn(weights="DEFAULT")
    in_feat = model.roi_heads.box_predictor.cls_score.in_features
    model.roi_heads.box_predictor = FastRCNNPredictor(in_feat, num_classes)
    in_feat_mask = model.roi_heads.mask_predictor.conv5_mask.in_channels
    model.roi_heads.mask_predictor = MaskRCNNPredictor(in_feat_mask, 256, num_classes)

    if pretrained_ckpt and Path(pretrained_ckpt).exists():
        ckpt = torch.load(pretrained_ckpt, map_location="cpu")
        state = ckpt.get("model_state_dict", ckpt)
        missing, unexpected = model.load_state_dict(state, strict=False)
        print(f"📥 Checkpoint chargé — missing={len(missing)} unexpected={len(unexpected)}")
    else:
        print("🆕 Entraînement from scratch (poids COCO ImageNet)")
    return model


def load_seg_model(ckpt_path, device):
    ckpt = torch.load(ckpt_path, map_location=device)
    n_cls = ckpt.get("num_classes", 2)
    model = get_model(n_cls)
    model.load_state_dict(ckpt["model_state_dict"])
    model.to(device); model.eval()
    print(f"✅ Modèle segmentation chargé — epoch {ckpt.get('epoch',0)+1} "
          f"| val_loss={ckpt.get('val_loss',0):.4f}")
    return model


seg_ckpt_path = os.path.join(CFG["seg_output_dir"], "best_model_v4_roi.pth")
seg_inf = load_seg_model(seg_ckpt_path, device)


# ── ThinCrackNet (fissures) ───────────────────────────────────
CRACK_CHECKPOINT = "ModelCrack/ThinCrackNet/best_thincracknet.pth"
CRACK_IMG_SIZE   = 512
CRACK_THRESHOLD  = 0.5

# ── Blocs de base de l'architecture ThinCrackNet ─────────────
class ConvBnRelu(torch.nn.Module):
    def __init__(self, in_ch, out_ch, dilation=1):
        super().__init__()
        self.block = torch.nn.Sequential(
            torch.nn.Conv2d(in_ch, out_ch, 3, padding=dilation, dilation=dilation, bias=False),
            torch.nn.BatchNorm2d(out_ch),
            torch.nn.ReLU(inplace=True),
        )
    def forward(self, x):
        return self.block(x)


class AttentionBlock(torch.nn.Module):
    def __init__(self, F_g, F_l, F_int):
        super().__init__()
        self.W_g  = torch.nn.Sequential(torch.nn.Conv2d(F_g,  F_int, 1, bias=True), torch.nn.BatchNorm2d(F_int))
        self.W_x  = torch.nn.Sequential(torch.nn.Conv2d(F_l,  F_int, 1, bias=True), torch.nn.BatchNorm2d(F_int))
        self.psi  = torch.nn.Sequential(torch.nn.Conv2d(F_int, 1,    1, bias=True), torch.nn.BatchNorm2d(1), torch.nn.Sigmoid())
        self.relu = torch.nn.ReLU(inplace=True)

    def forward(self, g, x):
        return x * self.psi(self.relu(self.W_g(g) + self.W_x(x)))


class ThinASPP(torch.nn.Module):
    def __init__(self, in_channels, out_channels=256):
        super().__init__()
        self.conv1 = torch.nn.Sequential(
            torch.nn.Conv2d(in_channels, out_channels, 1, bias=False),
            torch.nn.BatchNorm2d(out_channels), torch.nn.ReLU(inplace=True))
        self.conv2 = torch.nn.Sequential(
            torch.nn.Conv2d(in_channels, out_channels, 3, padding=2, dilation=2, bias=False),
            torch.nn.BatchNorm2d(out_channels), torch.nn.ReLU(inplace=True))
        self.conv3 = torch.nn.Sequential(
            torch.nn.Conv2d(in_channels, out_channels, 3, padding=4, dilation=4, bias=False),
            torch.nn.BatchNorm2d(out_channels), torch.nn.ReLU(inplace=True))
        self.conv4 = torch.nn.Sequential(
            torch.nn.Conv2d(in_channels, out_channels, 3, padding=8, dilation=8, bias=False),
            torch.nn.BatchNorm2d(out_channels), torch.nn.ReLU(inplace=True))
        self.pool  = torch.nn.Sequential(
            torch.nn.AdaptiveAvgPool2d(1),
            torch.nn.Conv2d(in_channels, out_channels, 1, bias=False),
            torch.nn.BatchNorm2d(out_channels), torch.nn.ReLU(inplace=True))
        self.project = torch.nn.Sequential(
            torch.nn.Conv2d(out_channels * 5, out_channels, 1, bias=False),
            torch.nn.BatchNorm2d(out_channels), torch.nn.ReLU(inplace=True),
            torch.nn.Dropout(0.3))

    def forward(self, x):
        size  = x.shape[-2:]
        pool  = F.interpolate(self.pool(x), size=size, mode='bilinear', align_corners=True)
        return self.project(torch.cat([
            self.conv1(x), self.conv2(x), self.conv3(x), self.conv4(x), pool
        ], dim=1))


class BoundaryHead(torch.nn.Module):
    def __init__(self, in_ch):
        super().__init__()
        self.head = torch.nn.Sequential(
            torch.nn.Conv2d(in_ch, 64, 3, padding=1, bias=False),
            torch.nn.BatchNorm2d(64), torch.nn.ReLU(inplace=True),
            torch.nn.Conv2d(64, 1, 1))
    def forward(self, x):
        return self.head(x)


class ThinCrackNet(torch.nn.Module):
    def __init__(self, encoder_name='efficientnet-b5', img_size=512):
        super().__init__()
        self.img_size = img_size

        self.backbone = smp.UnetPlusPlus(
            encoder_name=encoder_name,
            encoder_weights=None,
            in_channels=3,
            classes=1,
            activation=None
        )
        enc_ch = self.backbone.encoder.out_channels

        self.aspp         = ThinASPP(in_channels=enc_ch[-1], out_channels=256)
        self.adapt_feat2  = torch.nn.Conv2d(enc_ch[-2], 256, 1)
        self.adapt_feat3  = torch.nn.Conv2d(enc_ch[-3], 256, 1)
        self.adapt_feat4  = torch.nn.Conv2d(enc_ch[-4], 64,  1)
        self.att1         = AttentionBlock(F_g=256, F_l=256, F_int=128)
        self.att2         = AttentionBlock(F_g=256, F_l=256, F_int=128)
        self.skip_refine  = ConvBnRelu(64 + 64, 64)

        self.decoder = torch.nn.Sequential(
            torch.nn.Conv2d(256, 128, 3, padding=1), torch.nn.BatchNorm2d(128), torch.nn.ReLU(inplace=True),
            torch.nn.Conv2d(128, 64,  3, padding=1), torch.nn.BatchNorm2d(64),  torch.nn.ReLU(inplace=True),
            torch.nn.Conv2d(64,  1,   1)
        )
        self.deep_sup_head = torch.nn.Sequential(
            torch.nn.Conv2d(256, 64, 3, padding=1), torch.nn.BatchNorm2d(64), torch.nn.ReLU(inplace=True),
            torch.nn.Conv2d(64, 1, 1)
        )
        self.boundary_head = BoundaryHead(in_ch=64)
        self.skip_conv     = torch.nn.Conv2d(64, 1, 1)
        self.final_conv    = torch.nn.Conv2d(2, 1, 1)

    def forward(self, x):
        features = self.backbone.encoder(x)

        aspp_out = self.aspp(features[-1])

        feat3  = self.adapt_feat3(features[-3])
        ds_out = None
        if self.training:
            ds_out = F.interpolate(
                self.deep_sup_head(feat3),
                size=(self.img_size, self.img_size),
                mode='bilinear', align_corners=True
            )

        feat2 = self.adapt_feat2(features[-2])
        x_dec = F.interpolate(aspp_out, size=feat2.shape[2:], mode='bilinear', align_corners=True)
        x_dec = self.att1(x_dec, feat2)
        x_dec = F.interpolate(x_dec, size=feat3.shape[2:], mode='bilinear', align_corners=True)
        x_dec = self.att2(x_dec, feat3)
        x_dec = F.interpolate(x_dec, size=(self.img_size, self.img_size),
                               mode='bilinear', align_corners=True)

        main_logit = self.decoder(x_dec)

        feat4     = self.adapt_feat4(features[-4])
        feat4_up  = F.interpolate(feat4, size=(self.img_size, self.img_size),
                                  mode='bilinear', align_corners=True)
        dec_64    = x_dec[:, :64, :, :]
        skip_feat = self.skip_refine(torch.cat([feat4_up, dec_64], dim=1))

        boundary_logit = None
        if self.training:
            boundary_logit = self.boundary_head(skip_feat)

        skip_logit  = self.skip_conv(skip_feat)
        final_logit = self.final_conv(torch.cat([main_logit, skip_logit], dim=1))

        if self.training:
            return final_logit, ds_out, boundary_logit
        return final_logit


def load_thincracknet_from_checkpoint(checkpoint_path, device, img_size=512):
    model      = ThinCrackNet(encoder_name='efficientnet-b5', img_size=img_size).to(device)
    checkpoint = torch.load(checkpoint_path, map_location=device, weights_only=False)
    old_state  = checkpoint['model_state_dict']

    compatible = ['backbone.encoder', 'adapt_feat2', 'adapt_feat3', 'att1', 'att2', 'decoder']
    new_state  = model.state_dict()
    loaded, skipped = [], []

    for key, val in old_state.items():
        if any(key.startswith(p) for p in compatible):
            if key in new_state and new_state[key].shape == val.shape:
                new_state[key] = val
                loaded.append(key)
                continue
        skipped.append(key)

    model.load_state_dict(new_state, strict=False)
    print(f"✅ Checkpoint chargé : {checkpoint_path}")
    print(f"   IoU original    : {checkpoint.get('best_iou', 0):.4f}")
    print(f"   Poids chargés   : {len(loaded)}/{len(old_state)}")
    print(f"   Réinitialisés   : {len(skipped)} (aspp + nouveaux modules)")
    return model

crack_model = load_thincracknet_from_checkpoint(
    CRACK_CHECKPOINT, device, img_size=CRACK_IMG_SIZE
)
crack_model.eval()

crack_transform = A.Compose([
    A.Resize(CRACK_IMG_SIZE, CRACK_IMG_SIZE),
    A.Normalize(mean=(0.485, 0.456, 0.406), std=(0.229, 0.224, 0.225)),
    ToTensorV2(),
])

# ── UNet Écaillage ────────────────────────────────────────────
ECAILLE_CHECKPOINT = "ModelEcaillage/best_model_ecaillage_finetuned.pth"
ECAILLE_IMG_SIZE   = 256
ECAILLE_THRESHOLD  = 0.5

def load_ecaille_model(model_path, device):
    model = smp.Unet(
        encoder_name='resnet34',
        encoder_weights=None,
        in_channels=3,
        classes=1,
        activation=None
    )
    checkpoint  = torch.load(model_path, map_location=device, weights_only=False)
    state_dict  = checkpoint.get('model_state_dict', checkpoint)
    model.load_state_dict(state_dict)
    model = model.to(device)
    model.eval()
    print(f"✅ UNet écaillage chargé — Dice: {checkpoint.get('val_dice', 0):.4f}")
    return model

ecaille_model = load_ecaille_model(ECAILLE_CHECKPOINT, device)

ecaille_transform = A.Compose([
    A.Resize(ECAILLE_IMG_SIZE, ECAILLE_IMG_SIZE),
    A.Normalize(mean=(0.485, 0.456, 0.406), std=(0.229, 0.224, 0.225)),
    ToTensorV2(),
])

print(f"✅ ThinCrackNet prêt  (img_size={CRACK_IMG_SIZE})")
print(f"✅ UNet écaillage prêt (img_size={ECAILLE_IMG_SIZE})")


# ============================================================
#  0bis. PIPELINE D'INFÉRENCE ROI (YOLO + segmentation)
# ============================================================

def filter_predictions_geometric(preds, score_thresh, min_aspect_ratio,
                                  min_area, max_area, nms_iou_thresh=0.4):
    boxes = preds["boxes"].cpu(); scores = preds["scores"].cpu()
    masks = preds["masks"].cpu(); labels = preds["labels"].cpu()

    keep = []
    for i in range(len(scores)):
        if scores[i].item() < score_thresh:
            continue
        x1, y1, x2, y2 = boxes[i].tolist()
        w, h = x2 - x1, y2 - y1
        area = w * h
        ar = max(w, h) / (min(w, h) + 1e-6)
        if ar < min_aspect_ratio:
            continue
        if not (min_area <= area <= max_area):
            continue
        keep.append(i)

    if not keep:
        return {"boxes": torch.zeros((0, 4)), "scores": torch.zeros((0,)),
                "masks": torch.zeros((0, 1, *masks.shape[2:])),
                "labels": torch.zeros((0,), dtype=torch.int64)}

    keep_t = torch.tensor(keep)
    nms_keep = ops.nms(boxes[keep_t], scores[keep_t], nms_iou_thresh)
    final = keep_t[nms_keep]
    return {"boxes": boxes[final], "scores": scores[final],
            "masks": masks[final], "labels": labels[final]}


def full_pipeline_inference(img_bgr, yolo_model, seg_model, device, cfg, margin_pct=0.15):
    """
    1. YOLO détecte le ROI pantographe
    2. Crop l'image sur ce ROI (avec marge)
    3. Segmentation Mask R-CNN sur le crop
    4. Filtre géométrique calibré
    5. Reprojection des masques/boxes dans le repère original

    Retourne : dict avec roi_box, et liste de détections (box, mask, score)
    en coordonnées ORIGINALES.
    """
    h_orig, w_orig = img_bgr.shape[:2]

    # ── 1. Détection ROI ──────────────────────────────────────────
    yolo_res = yolo_model.predict(img_bgr, conf=cfg["yolo_conf_thresh"], verbose=False)[0]
    if len(yolo_res.boxes) == 0:
        return {"roi_box": None, "detections": [], "status": "no_pantograph_detected"}

    best_idx = yolo_res.boxes.conf.argmax().item()
    rx1, ry1, rx2, ry2 = yolo_res.boxes.xyxy[best_idx].cpu().numpy()

    rw, rh = rx2 - rx1, ry2 - ry1
    mx, my = rw * margin_pct, rh * margin_pct
    rx1 = max(0, rx1 - mx); ry1 = max(0, ry1 - my)
    rx2 = min(w_orig, rx2 + mx); ry2 = min(h_orig, ry2 + my)
    rx1, ry1, rx2, ry2 = int(rx1), int(ry1), int(rx2), int(ry2)

    # ── 2. Crop + resize ──────────────────────────────────────────
    crop = img_bgr[ry1:ry2, rx1:rx2]
    crop_h, crop_w = crop.shape[:2]
    target = 640
    crop_rs = cv2.resize(crop, (target, target))
    scale_x = crop_w / target
    scale_y = crop_h / target

    # ── 3. Segmentation sur le crop ────────────────────────────────
    img_tensor = torch.from_numpy(
        cv2.cvtColor(crop_rs, cv2.COLOR_BGR2RGB)
    ).permute(2, 0, 1).float() / 255.0
    with torch.no_grad():
        raw_preds = seg_model([img_tensor.to(device)])[0]

    # ── 4. Filtre géométrique calibré ──────────────────────────────
    filtered = filter_predictions_geometric(
        raw_preds,
        score_thresh     = cfg["score_thresh"] if "score_thresh" in cfg else 0.5,
        min_aspect_ratio = cfg["min_aspect_ratio"],
        min_area         = cfg["min_area"] / (scale_x * scale_y),
        max_area         = cfg["max_area"] / (scale_x * scale_y),
        nms_iou_thresh   = 0.4,
    )

    # ── 5. Reprojection dans le repère original ────────────────────
    detections = []
    for i in range(len(filtered["boxes"])):
        bx1, by1, bx2, by2 = filtered["boxes"][i].tolist()
        orig_box = [
            rx1 + bx1 * scale_x, ry1 + by1 * scale_y,
            rx1 + bx2 * scale_x, ry1 + by2 * scale_y,
        ]
        mask_crop = filtered["masks"][i, 0].numpy() > 0.5
        mask_full = np.zeros((h_orig, w_orig), dtype=np.uint8)
        mask_resized_to_crop = cv2.resize(
            mask_crop.astype(np.uint8), (crop_w, crop_h),
            interpolation=cv2.INTER_NEAREST
        )
        mask_full[ry1:ry2, rx1:rx2] = mask_resized_to_crop

        detections.append({
            "box": orig_box,
            "mask": mask_full,
            "score": filtered["scores"][i].item(),
        })

    return {"roi_box": [rx1, ry1, rx2, ry2], "detections": detections, "status": "ok"}


# ============================================================
#  1. GÉOMÉTRIE DE REDRESSEMENT
# ============================================================

def get_straighten_transform(mask_full, box, h_orig, w_orig, padding=8):
    x1, y1, x2, y2 = [int(v) for v in box]
    x1 = max(0, x1 - padding); y1 = max(0, y1 - padding)
    x2 = min(w_orig, x2 + padding); y2 = min(h_orig, y2 + padding)
    if x2 <= x1 or y2 <= y1:
        return None

    local_mask = mask_full[y1:y2, x1:x2]
    mask_u8 = (local_mask > 0).astype(np.uint8)
    contours, _ = cv2.findContours(mask_u8, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if not contours:
        return None
    contour = max(contours, key=cv2.contourArea)
    if cv2.contourArea(contour) < 20:
        return None

    rect = cv2.minAreaRect(contour)
    (cx, cy), (rw, rh), angle = rect
    if rw < rh:
        angle += 90
        rw, rh = rh, rw

    local_h, local_w = local_mask.shape[:2]
    rot_mat = cv2.getRotationMatrix2D((cx, cy), angle, 1.0)
    cos = abs(rot_mat[0, 0]); sin = abs(rot_mat[0, 1])
    new_w = int(local_h * sin + local_w * cos)
    new_h = int(local_h * cos + local_w * sin)
    rot_mat[0, 2] += (new_w / 2) - cx
    rot_mat[1, 2] += (new_h / 2) - cy

    new_cx, new_cy = new_w / 2, new_h / 2
    half_w = rw / 2 + padding
    half_h = rh / 2 + padding
    cx1 = max(0, int(new_cx - half_w)); cy1 = max(0, int(new_cy - half_h))
    cx2 = min(new_w, int(new_cx + half_w)); cy2 = min(new_h, int(new_cy + half_h))
    if cx2 <= cx1 or cy2 <= cy1:
        return None

    return {
        "offset":          (x1, y1),
        "local_size":      (local_w, local_h),
        "rot_mat":         rot_mat,
        "rot_canvas_size": (new_w, new_h),
        "straight_box":    (cx1, cy1, cx2, cy2),
    }


def extract_straightened_local(frame_bgr, mask_full, params):
    x1, y1 = params["offset"]
    local_w, local_h = params["local_size"]
    x2, y2 = x1 + local_w, y1 + local_h

    local_img  = frame_bgr[y1:y2, x1:x2]
    local_mask = mask_full[y1:y2, x1:x2]

    new_w, new_h = params["rot_canvas_size"]
    img_rot  = cv2.warpAffine(local_img, params["rot_mat"],
                               (new_w, new_h), flags=cv2.INTER_LINEAR)
    mask_rot = cv2.warpAffine((local_mask > 0).astype(np.uint8), params["rot_mat"],
                               (new_w, new_h), flags=cv2.INTER_NEAREST)

    cx1, cy1, cx2, cy2 = params["straight_box"]
    crop_img  = img_rot[cy1:cy2, cx1:cx2].copy()
    crop_mask = mask_rot[cy1:cy2, cx1:cx2].copy()
    crop_img[crop_mask == 0] = 0
    return crop_img, crop_mask


def reproject_defect_mask(mask_straight, params, frame_shape):
    cx1, cy1, cx2, cy2 = params["straight_box"]
    new_w, new_h = params["rot_canvas_size"]

    canvas = np.zeros((new_h, new_w), dtype=np.uint8)
    canvas[cy1:cy2, cx1:cx2] = mask_straight

    inv_rot_mat = cv2.invertAffineTransform(params["rot_mat"])
    local_w, local_h = params["local_size"]
    mask_local = cv2.warpAffine(canvas, inv_rot_mat,
                                 (local_w, local_h), flags=cv2.INTER_NEAREST)

    x1, y1 = params["offset"]
    h_frame, w_frame = frame_shape[:2]
    mask_full = np.zeros((h_frame, w_frame), dtype=np.uint8)
    mask_full[y1:y1+local_h, x1:x1+local_w] = mask_local
    return mask_full


def apply_defect_overlay(vis, mask_straight, params, color, alpha):
    mask_frame = reproject_defect_mask(mask_straight, params, vis.shape)
    overlay = np.zeros_like(vis)
    overlay[mask_frame > 0] = color
    return cv2.addWeighted(vis, 1.0, overlay, alpha, 0)


def draw_thickness_lines_mask(shape_2d, sections, min_idx=None,
                               line_thickness=1, highlight_thickness=1,
                               whisker=4, point_radius=1):
    """
    Reprend le dessin des lignes de mesure d'épaisseur (identique à
    draw_thickness_overlay du pipeline vidéo — ligne verticale + moustaches
    + points aux extrémités, section la plus fine plus épaisse) mais au
    lieu de peindre directement sur l'image, dessine sur un masque binaire
    vide de la taille du crop redressé (shape_2d = (h, w)).

    Ce masque peut ensuite être reprojeté avec reproject_defect_mask(),
    exactement comme les masques fissure/écaillage, pour obtenir un
    overlay d'épaisseur (jaune) qui colle à la réalité sur l'image
    d'origine — même concept que le reste des défauts.
    """
    canvas = np.zeros(shape_2d, dtype=np.uint8)
    for i, s in enumerate(sections):
        x = s["x_px"]
        y_top, y_bot = s["y_top"], s["y_bot"]
        th = highlight_thickness if (min_idx is not None and i == min_idx) else line_thickness

        cv2.line(canvas, (x, y_top), (x, y_bot), 255, th)
        cv2.line(canvas, (x - whisker, y_top), (x + whisker, y_top), 255, th)
        cv2.line(canvas, (x - whisker, y_bot), (x + whisker, y_bot), 255, th)
        cv2.circle(canvas, (x, y_top), point_radius, 255, -1)
        cv2.circle(canvas, (x, y_bot), point_radius, 255, -1)

    return canvas


# ============================================================
#  2. INFÉRENCE — deux modèles de défauts
# ============================================================

def predict_defects_on_straightened(crop_bgr, model, transform, device, threshold):
    """
    ThinCrackNet — version robuste au sens du seuil.

    L'ancien seuil fixe ("fissure = proba basse") était calé sur une
    seule image de calibration. Sur d'autres images (éclairage/texture
    différents), la sortie sigmoïde du modèle peut dériver et faire
    classer toute la bande comme fissure. Ici on teste les deux sens
    possibles et on garde celui qui donne la plus PETITE surface —
    une fissure est par nature fine et minoritaire, jamais la majorité
    de la bande.
    """
    h_orig, w_orig = crop_bgr.shape[:2]
    crop_rgb = cv2.cvtColor(crop_bgr, cv2.COLOR_BGR2RGB)
    tensor = transform(image=crop_rgb)["image"].unsqueeze(0).to(device)

    with torch.no_grad():
        output = model(tensor)
        logit  = output[0] if isinstance(output, tuple) else output
        mask_prob = torch.sigmoid(logit).cpu().numpy()[0, 0]

    mask_prob_resized = cv2.resize(mask_prob, (w_orig, h_orig),
                                    interpolation=cv2.INTER_LINEAR)

    pred_proba_basse = (mask_prob_resized < (1.0 - threshold)).astype(np.uint8)
    pred_proba_haute = (mask_prob_resized > threshold).astype(np.uint8)

    n_total = mask_prob_resized.size
    frac_basse = pred_proba_basse.sum() / n_total
    frac_haute = pred_proba_haute.sum() / n_total

    crack_pred = pred_proba_basse if frac_basse <= frac_haute else pred_proba_haute
    return crack_pred  # 1=fissure, 0=fond

def predict_ecaillage(crop_bgr, model, transform, device, threshold):
    h_orig, w_orig = crop_bgr.shape[:2]
    crop_rgb = cv2.cvtColor(crop_bgr, cv2.COLOR_BGR2RGB)
    tensor = transform(image=crop_rgb)["image"].unsqueeze(0).to(device)
    with torch.no_grad():
        output    = model(tensor)
        mask_prob = torch.sigmoid(output).cpu().numpy()[0, 0]
    mask_resized = cv2.resize(mask_prob, (w_orig, h_orig), interpolation=cv2.INTER_LINEAR)
    return (mask_resized > threshold).astype(np.uint8)


# ============================================================
#  3. MESURE D'ÉPAISSEUR — orientation face/profil + 3 sections + échelle
# ============================================================

def estimate_scale_from_known_length(mask_straight, known_length_mm):
    in_band = (mask_straight > 0).astype(np.uint8)
    cols_with_band = np.where(in_band.sum(axis=0) > 0)[0]
    if len(cols_with_band) == 0:
        return None
    length_px = cols_with_band[-1] - cols_with_band[0]
    if length_px <= 0:
        return None
    return length_px / known_length_mm


def get_px_per_mm(mask_straight):
    if PX_PER_MM_DEFAULT is not None:
        return PX_PER_MM_DEFAULT
    if KNOWN_BAND_LENGTH_MM is not None:
        return estimate_scale_from_known_length(mask_straight, KNOWN_BAND_LENGTH_MM)
    return None


def detect_view_orientation(mask_straight, min_band_frac=0.6):
    in_band = (mask_straight > 0).astype(np.uint8)
    h, w = in_band.shape[:2]

    col_heights = []
    for x in range(w):
        col = np.where(in_band[:, x] > 0)[0]
        if len(col) > 0:
            col_heights.append(col[-1] - col[0] + 1)
        else:
            col_heights.append(0)
    col_heights = np.array(col_heights, dtype=np.float32)

    valid = col_heights[col_heights > 0]
    if len(valid) < min_band_frac * w:
        return "incertain", {"reason": "masque trop fragmenté"}

    mean_h = float(np.mean(valid))
    std_h  = float(np.std(valid))
    cv_h   = std_h / mean_h if mean_h > 0 else 999.0
    aspect = w / max(mean_h, 1.0)

    metrics = {
        "mean_height_px": mean_h,
        "std_height_px": std_h,
        "coeff_variation": cv_h,
        "aspect_ratio": aspect,
    }

    if cv_h < 0.15 and aspect < 25:
        return "profil", metrics

    if aspect >= 25 or cv_h >= 0.30:
        return "face", metrics

    return "incertain", metrics


def measure_thickness_sections(mask_straight, positions_frac=(0.25, 0.5, 0.75)):
    in_band = (mask_straight > 0).astype(np.uint8)
    h, w = in_band.shape[:2]

    cols_with_band = np.where(in_band.sum(axis=0) > 0)[0]
    if len(cols_with_band) == 0:
        return []

    x_start, x_end = cols_with_band[0], cols_with_band[-1]
    span = x_end - x_start

    sections = []
    for frac in positions_frac:
        x = int(x_start + frac * span)
        x = min(max(x, x_start), x_end)

        col = np.where(in_band[:, x] > 0)[0]
        if len(col) == 0:
            for dx in range(1, 6):
                col_l = np.where(in_band[:, max(x - dx, 0)] > 0)[0]
                col_r = np.where(in_band[:, min(x + dx, w - 1)] > 0)[0]
                if len(col_l) > 0:
                    col = col_l
                    break
                if len(col_r) > 0:
                    col = col_r
                    break
        if len(col) == 0:
            continue

        y_top, y_bot = int(col[0]), int(col[-1])
        thickness_px = y_bot - y_top + 1

        sections.append({
            "x_px": int(x),
            "thickness_px": thickness_px,
            "y_top": y_top,
            "y_bot": y_bot,
        })

    return sections


def evaluate_defect(sections, px_per_mm, min_thickness_mm_threshold):
    if not sections:
        return {"status": "indetermine", "reason": "aucune section mesurée"}

    thickness_px_list = [s["thickness_px"] for s in sections]
    min_thickness_px = min(thickness_px_list)

    result = {
        "sections_px": thickness_px_list,
        "min_thickness_px": min_thickness_px,
    }

    if px_per_mm is None:
        result["status"] = "non_calibre"
        result["unit"] = "px"
        result["defaut"] = None
        return result

    thickness_mm_list = [t / px_per_mm for t in thickness_px_list]
    min_thickness_mm = min(thickness_mm_list)

    result["sections_mm"] = thickness_mm_list
    result["min_thickness_mm"] = min_thickness_mm
    result["unit"] = "mm"
    result["status"] = "calibre"
    result["defaut"] = min_thickness_mm < min_thickness_mm_threshold

    return result