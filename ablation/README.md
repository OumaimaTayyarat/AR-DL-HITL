# Annotation-budget-matched HITL ablation

This directory contains the data manifests, model configurations, image-level evaluation results, and statistical analysis used for the annotation-budget-matched HITL ablation reported in the manuscript.

## Variants
- M0: pre-HITL model
- M1: validated technician corrections only
- M2: corrections + randomly selected acquisitions
- M3: corrections + pose-guided acquisitions

## Matched budgets
### Cracking
- M2: 22 corrections + 20 random acquisitions + 84 resampled original images = 126
- M3: 22 corrections + 20 pose-guided acquisitions + 84 resampled original images = 126

### Spalling
- M2: 23 corrections + 23 random acquisitions + 112 resampled original images = 158
- M3: 23 corrections + 23 pose-guided acquisitions + 112 resampled original images = 158

## Reproduction
Run `python analysis/clustered_bootstrap_ablation.py`. The script reads the two prediction CSV files and reports mean Dice for the random-control and pose-guided variants, the paired mean difference, the 95% strip-cluster bootstrap confidence interval, and the number of images and strips. Bootstrap seed = 7; resamples = 10,000.

## Manifest note
The actual training image IDs for the 22/23 corrections, 20/23 random acquisitions, 20/23 pose-guided acquisitions, and 84/112 resampled original images were not supplied in the available analysis records. To avoid fabricating provenance, the manifest CSVs included here contain the verified category counts and explicit placeholder IDs. Replace the placeholder IDs with the real training image IDs from the training logs before public release.
