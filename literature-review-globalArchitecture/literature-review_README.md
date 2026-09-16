# Literature Review — Screening Protocol (Section 2)

This folder contains the full screening pipeline, search strategy, and corpus-level data extraction underlying Section 2 ("Related Work and Research Gap") of the paper. It is provided to support reproducibility of the gap analysis that motivates the proposed AR–multi-model-segmentation–HITL architecture.

## Contents

| File | Description |
|---|---|
| `PRISMA_screening_pipeline.xlsx` | Full record set with phase-by-phase inclusion/exclusion decisions (Identification → Duplicates removed → Phase 1 → Phase 2 → Phase 3 → Final corpus) |
| `corpus_table.xlsx` | Structured extraction table for the 25 studies in the final corpus  |
| `prisma_flow_diagram.png` | PRISMA 2020 flow diagram  |

## Review protocol summary

The review follows a PRISMA 2020-informed protocol , proportionate to its role as a gap-justification instrument rather than a standalone systematic review.

**Databases:** Scopus, IEEE Xplore, ScienceDirect, Google Scholar (grey-literature/recall backstop).

**Search string:**
```
("Augmented Reality" OR "Mixed Reality" OR AR OR MR)
AND ("Deep Learning" OR AI)
AND ("defect detection" OR segmentation)
AND ("Human-in-the-Loop" OR HITL)
AND (maintenance OR inspection OR infrastructure)
```

**Search date:** 02 July 2026. **Period covered:** 2017–2026.



## Screening phases

| Phase | Applied to | Records in → out |
|---|---|---|
| Identification | Database search | 350 |
| Duplicate removal | — | 350 → 232 |
| Phase 1 (search-tool filters: IC-P1a–d / EC-P1a–b) | Language, document type, period, field | 232 → 212 (20 excluded) |
| Phase 2 (title/abstract: IC1–4 / EC1–3) | Integration relevance, domain, metadata awareness, feedback loop | 212 → 73 (139 excluded) |
| Phase 3 (full-text verification) | Joint, explicit description of AR + AI + HITL | 73 → 25 (48 excluded) |

## Data extraction fields (`corpus_table.xlsx`)

For each of the 25 retained studies: normalized reference, year, venue/publisher/stable identifier, document type, AR/MR/XR device, capture mode, AI model, AI role, HITL presence, human-correction type, persistent retraining status, recorded metadata/pose, reported quantitative results, limitations relative to the proposed architecture, and corpus-inclusion decision.


