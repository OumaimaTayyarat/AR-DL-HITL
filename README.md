# AR-DL-HITL

## Pose-Aware Augmented Reality and Human-in-the-Loop Deep Learning for Pantograph Contact-Strip Inspection

This repository contains the supplementary material, experimental artefacts, model-selection evidence, datasets documentation, and implementation resources associated with the manuscript:

> "Pose-Aware Augmented Reality and Human-in-the-Loop Deep Learning for Pantograph Contact-Strip Inspection"

The proposed framework integrates:

- Augmented Reality (AR)
- Edge AI inference
- Multi-model defect segmentation
- Human-in-the-Loop (HITL) learning
- Pose-aware feedback traceability

for railway pantograph contact-strip inspection.

---

# Repository Structure

```text
AR-DL-HITL
│
├── architecture-model-selection
│   ├── contact-strip-localization-architecture-matrix.xlsx
│   ├── defect-segmentation-modelArchitecture-matrix.xlsx
│   └── README.md
│
├── ARInterface
│   ├── Assets/
│   ├── Packages/
│   ├── ProjectSettings/
│   └── ...
│
├── dataset
│   ├── contact-strip-localization-datasetSelection.xlsx
│   ├── defect-strip-localization-datasetSelection.xlsx
│   └── README.md
│
├── edge-server-inference
│   ├── pipeline_core.py
│   └── serveur_api.py
│
├── literature-review-globalArchitecture
│   ├── corpus_table.xlsx
│   ├── prisma_flow_diagram.png
│   ├── PRISMA_screening_pipeline.xlsx
│   └── literature-review_README.md
│
├── Test_Protocol
│   ├── 120_operations_full_log.xlsx
│   └── Thickness-test.xlsx
│
├── training
│   ├── LocalisationBande
│   ├── SegmentationDefects
│   └── README.md
│
└── Hitl-Architecture.zip
```

---

# Research Objective

The objective of this work is to demonstrate how augmented reality, computer vision, and technician feedback can be integrated into a closed-loop inspection architecture capable of:

- reducing missed defects;
- improving inspection efficiency;
- improving segmentation precision through periodic HITL retraining;
- maintaining full traceability between acquisition conditions and corrections.

---

# Architecture Overview

The proposed system consists of four interconnected layers:

1. AR acquisition layer
2. Edge inference layer
3. AR visualization and interaction layer
4. Pose-linked HITL feedback layer

The inference pipeline combines:

- YOLO region proposal
- Mask R-CNN contact-strip localization
- DeepLabV3+ crack segmentation
- U-Net spalling segmentation

---

# Repository Content

## Architecture Selection

Folder:

```text
architecture-model-selection/
```

Contains:

- literature-driven model screening;
- architecture scoring matrices;
- benchmarking results;
- final model-selection rationale.

The selected architectures are:

| Task | Selected Model |
|--------|--------|
| Contact-strip localization | Mask R-CNN |
| Crack segmentation | DeepLabV3+ |
| Spalling segmentation | U-Net |

---

## Dataset Documentation

Folder:

```text
dataset/
```

Contains:

- dataset landscape review;
- dataset selection rationale;
- dataset construction summary.

### Important

The complete industrial image dataset is **not publicly released** because of operational and confidentiality constraints.

Only dataset metadata, screening information, and supplementary documentation are provided.

---

## Literature Review

Folder:

```text
literature-review-globalArchitecture/
```

Contains:

- PRISMA workflow;
- article-classification tables;
- screening decisions;
- corpus statistics supporting the literature review.

---

## Edge Inference Server

Folder:

```text
edge-server-inference/
```

Contains:

- inference server implementation;
- segmentation orchestration logic;
- server API.

This layer executes the complete inference workflow remotely from the headset.

---

## AR Interface

Folder:

```text
ARInterface/
```

Contains:

- Unity-based AR application;
- headset-side visualization;
- passthrough rendering;
- interaction workflow.

The implementation targets Meta Quest devices.

---

## Training Resources

Folder:

```text
training/
```

Contains:

- localization experiments;
- defect segmentation experiments;
- model fine-tuning workflows.

---

## Experimental Protocol

Folder:

```text
Test_Protocol/
```

Contains:

- anonymized experimental logs;
- thickness-evaluation records;
- statistical-analysis inputs.

No technician identifiers or confidential operational identifiers are disclosed.

---

# Data Availability

The repository provides:

- architecture screening matrices;
- literature-review artefacts;
- experimental summaries;
- anonymized evaluation records;
- code components required to understand the architecture.

The complete industrial image dataset remains unavailable due to industrial confidentiality restrictions.

---

# Citation

If you use this repository, please cite the associated publication.

Citation details will be updated upon publication.

---

