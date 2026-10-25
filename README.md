# AR-DL-HITL

## An Intelligent AR-HITL Deep-Learning System for Pantograph Contact-Strip Inspection

This repository contains the implementation, supplementary material, experimental records, model-selection evidence, and reproducibility resources associated with the manuscript:

> **An Intelligent AR-HITL Deep-Learning System for Pantograph Contact-Strip Inspection**

The study investigates an intelligent industrial inspection workflow integrating:

- augmented-reality-guided acquisition;
- edge AI inference;
- coarse-to-fine contact-strip localization;
- defect-specific deep-learning segmentation;
- technician decision support;
- pose-linked human-in-the-loop (HITL) feedback;
- targeted model adaptation.

The contribution is system-level rather than a claim of a new segmentation architecture. Established computer-vision and deep-learning models are integrated into a traceable AR-assisted inspection and learning workflow for railway pantograph contact strips.

---

# Repository Navigation

```text
AR-DL-HITL/
│
├── README.md
├── .gitattributes
│
├── ARInterface/
├── edge-server-inference/
├── training/
├── dataset/
├── architecture-model-selection/
├── literature-review-globalArchitecture/
├── Test_Protocol/
│
├── ablation/
│   ├── configs/
│   ├── results/
│   └── analysis/
│
├── field_evaluation/
├── supplementary/
└── reproducibility/