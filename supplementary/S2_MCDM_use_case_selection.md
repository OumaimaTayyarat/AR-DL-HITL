# S2. Detailed MCDM use-case selection

3. Use-Case Selection and Current Inspection Process

The maintenance operation targeted by the proposed AR–ML–HITL architecture was selected using an adapted version of the five-step Multi-Criteria Decision-Making (MCDM) framework developed and validated by the authors in (Tayyarat et al., 2026). The present study retains the framework's decision logic and its AHP-derived criterion weights but adapts the candidate pool and the final expert-validation stage to the rolling-stock current-collection subsystem. This distinction is important: (Tayyarat et al., 2026) applied the framework to twelve railway-maintenance operations and identified OP10, the verification of the Main Transformer insulating-oil level, as its pilot use case; it did not select pantograph contact-strip inspection. In the present study, the same methodological basis is used to evaluate a different subsystem and to select pantograph contact-strip inspection as the target use case.

The selection procedure comprised five sequential steps (Fig. 3): (1) identification of candidate operations, (2) definition of evaluation criteria, (3) weighting of the criteria using the Analytic Hierarchy Process (AHP), (4) scoring of the candidate operations, and (5) expert validation. The procedure was designed to identify an operation for which AR could provide measurable operational value while also supporting subsequent integration with computer-vision models and persistent technician feedback.

For confidentiality reasons, the industrial partner did not authorize disclosure of the names, detailed procedures, or subsystem-specific characteristics of the non-selected operations. Accordingly, the present section reports the aggregate scores of anonymized alternatives only. The anonymization of the alternatives limits external replication of the complete ranking, although the criteria, weights, scoring equation, expert-validation rule, and final selection are reported explicitly.

Fig. 3. Five-step MCDM procedure applied to the selection of pantograph contact-strip inspection. The procedure transfers the criteria and AHP weights established in (Tayyarat et al., 2026) and adapts the candidate pool and expert-validation stage to the rolling-stock current-collection subsystem. Source: authors.

## 3.1 Step 1: Identification of Candidate Operations

The candidate pool was restricted to Level 2 preventive-maintenance operations associated with the rolling-stock current-collection subsystem. This restriction was made before scoring and therefore does not constitute a post hoc exclusion from competing operations. It served two purposes. First, it focused the present study on a subsystem that is operationally relevant to current collection and is distinct from the Main Transformer use case selected in (Tayyarat et al., 2026). Second, it avoided repeating a selection exercise for unrelated operations, including wheelset-related tasks that have already received substantial attention in the AR railway-maintenance literature (Kwon et al., 2021).

The scope was also motivated by the evidence gap identified in Section 2. The reviewed literature contains studies on AR-assisted inspection, computer-vision-based defect detection, and human verification, but no retained study was identified as addressing the visual inspection of pantograph contact strips through a traceable AR–AI–HITL architecture. This observation was used to establish the relevance of the subsystem, not as a substitute for the MCDM selection itself.

The candidate pool comprised 10 Level 2 preventive-maintenance operations documented in the partner facility’s maintenance program. For confidentiality reasons, the operation names and detailed procedures of the non-selected alternatives are not disclosed.

## 3.2 Steps 2 and 3: Evaluation Criteria and AHP Weighting

Each candidate operation was evaluated using the five criteria defined in Table 2. These criteria were transferred without changing their conceptual definitions because they represent general properties of AR suitability in Level 2 maintenance: how often the task is performed, how demanding the procedure is, how consequential an error may be, how strongly the task requires traceability, and whether the resulting system can be extended toward AI-supported maintenance. The weights were not re-estimated in the present study; they were adopted from the AHP procedure reported in (Tayyarat et al., 2026).

Table 2. Evaluation criteria and AHP priority weights adopted from (Tayyarat et al., 2026).

| Code | Criterion | Scoring scale | Weight | Interpretation |
| --- | --- | --- | --- | --- |
| C1 | Operational frequency | Low: 0–1 execution/week; moderate: 2–4; frequent: 5–7 | 0.15 | Frequent tasks create more cumulative opportunities for efficiency and error-reduction gains |
| C2 | Execution complexity | Low, moderate, or high | 0.25 | Complex, multi-step procedures offer greater potential for reducing cognitive load and omission errors |
| C3 | Safety impact | Low, moderate, or high | 0.30 | Higher weight is assigned to tasks for which an undetected error may have serious safety or service consequences |
| C4 | Traceability and documentation requirements | None, partial, or mandatory standardized traceability | 0.15 | Digitally recorded inspection steps and results can improve documentation consistency |
| C5 | Scalability toward AR/AI integration | Low, moderate, or high | 0.15 | Structured, data-rich tasks provide a stronger basis for future computer-vision and decision-support functions |

The AHP comparison reported in (Tayyarat et al., 2026) produced a consistency ratio of CR = 0.004, below the commonly accepted threshold of 0.10. The resulting priority ordering was C3 (safety impact) > C2 (execution complexity) > C1 (frequency) = C4 (traceability) = C5 (scalability). The composite score was calculated as:

S = 0.15C1 + 0.25C2 + 0.30C3 + 0.15C4 + 0.15C5	(1)

where each criterion value lies on a 1–3 scale and the maximum possible composite score is 3.00.

Defect-morphology diversity was not added as a sixth weighted criterion. Adding it would require a new AHP comparison and would prevent a direct methodological comparison with (Tayyarat et al., 2026). Instead, morphology diversity was treated as a qualitative suitability check after the quantitative ranking. This check was necessary because the selected operation also provides the evaluation context for the segmentation models in Section 4.4: the presence of geometrical wear, cracks, and spalling supports evaluation across visually distinct defect morphologies rather than on a single defect class.

## 3.3 Step 4: Composite Scoring of Candidate Operations

All 10 candidate operations were rated by the five-member expert panel using the 1–3 scale defined in Table 2. Table 3 presents the four highest-ranked operations from the complete candidate pool. For these four operations, the displayed panel-aggregated ratings reproduce the reported weighted composite scores directly using Eq. (1). The remaining operation-level ratings are not reported because they are subject to industrial-confidentiality restrictions.

Table 3. Panel-aggregated ratings and weighted composite scores for the four highest-ranked Level 2 candidate operations.

| Operation | C1 | C2 | C3 | C4 | C5 | Composite score (/3.00) |
| --- | --- | --- | --- | --- | --- | --- |
| Pantograph contact-strip inspection | 2.8 | 2.5 | 3.0 | 2.8 | 2.8 | 2.785 |
| Op1 | 2.2 | 2.8 | 2.9 | 3.0 | 2.9 | 2.785 |
| Op2 | 2.5 | 2.2 | 2.6 | 2.3 | 2.4 | 2.410 |
| Op3 | 2.2 | 2.0 | 2.3 | 2.1 | 2.2 | 2.165 |

Pantograph contact-strip inspection and Op1 obtained the same highest composite score, 2.785/3.00. The two alternatives reached this value through different profiles. The pantograph operation received the maximum rating for safety impact, the most heavily weighted criterion, together with a higher rating for operational frequency. Op1 received higher ratings for execution complexity, traceability, and scalability. Since the weighted score did not produce a unique winner, the two highest-ranked alternatives were carried forward to Step 5. This use of expert validation as a tie-breaking stage preserves the sequential logic of the MCDM framework: quantitative scoring narrows the candidate pool, while practitioner judgment determines which of the top-ranked operations offers the stronger operational case for deployment.

The same five field experts provided the criterion ratings used in the weighted scoring stage and subsequently participated in the tie-breaking consultation. This continuity was retained because the panel possessed the subsystem-specific knowledge required to assess both the operational criteria and the practical implications of the tied alternatives. The two stages nevertheless used distinct instruments: numerical criterion ratings in Step 4 and direct comparative questions in Step 5. Because the same panel contributed to both stages, the tie-breaking outcome should be interpreted as an internally consistent expert decision rather than as an independent external validation of the ranking.

## 3.4 Step 5: Targeted Expert Validation

The tie between pantograph contact-strip inspection and Op1 was resolved through a targeted consultation with five field experts. Each expert had between 7 and 10 years of experience in Level 2 maintenance activities within the current-collection subsystem. Unlike the broader, multi-departmental validation used in (Tayyarat et al., 2026), this consultation was deliberately focused on the two highest-ranked candidates and was intended to support a tie-breaking decision rather than estimate population-level consensus. Before the expert responses were collected, the tie-breaking rule specified that the alternative receiving the majority on at least two of the three comparative questions would be selected.

The experts answered three questions addressing the dimensions most relevant to the proposed AR–ML–HITL intervention:

Which operation presents the greater risk of human error under the current manual procedure?

Which operation requires greater technical expertise and traceable documentation to be performed reliably?

Which operation would be easier to integrate into the existing maintenance process with minimal modification?

Because the panel comprised only five experts, the results were summarized as vote counts rather than analyzed using inferential statistical tests.

Table 4. Expert vote distribution for the two highest-ranked candidates (n = 5).

| Question | Decision dimension | Pantograph contact strip | Op1 |
| --- | --- | --- | --- |
| Q1: Risk of human error under the manual procedure | Safety and omission risk | 4/5 | 1/5 |
| Q2: Technical expertise and traceable documentation demand | Complexity and traceability | 3/5 | 2/5 |
| Q3: Ease of integration with minimal process modification | Implementation feasibility | 2/5 | 3/5 |
| Overall majority by question | n/a | 2/3 | 1/3 |

Pantograph contact-strip inspection was selected because it received the majority of expert votes on two of the three comparative questions, thereby satisfying the pre-specified tie-breaking rule. Four of the five experts selected this operation as presenting the greater risk of human error under the manual procedure, and three of the five selected it as requiring greater technical expertise and traceable documentation. Op1 received the majority only for ease of integration with minimal process modification. The selection was subsequently supported by the qualitative morphology-diversity check introduced in Section 3.2, because pantograph contact-strip inspection includes geometrical wear, linear cracking, and diffuse spalling.
