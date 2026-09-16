# ============================================================
#  SERVEUR D'INFÉRENCE — expose le pipeline pantographe en API
#  À lancer sur le PC. Le Quest 3 / téléphone enverra ses images ici.
# ============================================================
#
# Ce fichier suppose que tout ton code de chargement de modèles
# et tes fonctions (full_pipeline_inference, get_straighten_transform,
# extract_straightened_local, predict_defects_on_straightened,
# predict_ecaillage, detect_view_orientation, measure_thickness_sections,
# get_px_per_mm, evaluate_defect, etc.) sont dans "pipeline_core.py".
#
# VERSION COMPATIBLE UNITY : l'endpoint /analyse renvoie un SEUL JSON
# qui contient à la fois les métriques ET l'image annotée en base64
# (clé "image_annotee"), exactement ce qu'attend AnalyseResult.cs /
# AnalyseImageDisplay.cs côté Unity. Pas besoin de parser un header
# HTTP séparé.
#
# ============================================================

import json
import base64
import os
from datetime import datetime
from pydantic import BaseModel
import numpy as np
import cv2
from fastapi import FastAPI, File, UploadFile, Form
from fastapi.responses import JSONResponse, HTMLResponse
import uvicorn

# ── Import de TON pipeline existant (à adapter selon le nom réel) ────
from pipeline_core import (
    yolo_inf, seg_inf, crack_model, crack_transform,
    ecaille_model, ecaille_transform, device, CFG,
    full_pipeline_inference,
    get_straighten_transform,
    extract_straightened_local,
    predict_defects_on_straightened,
    predict_ecaillage,
    detect_view_orientation,
    measure_thickness_sections,
    get_px_per_mm,
    evaluate_defect,
    reproject_defect_mask,      # ← reprojette un masque "straightened" vers le repère de l'image d'origine
    draw_thickness_lines_mask,  # ← même dessin que draw_thickness_overlay du pipeline vidéo, en version masque
    THICKNESS_COLOR,
    CRACK_THRESHOLD,
    ECAILLE_THRESHOLD,
    DEFECT_PCT_ALERT,
    ECAILLE_PCT_ALERT,
    MIN_THICKNESS_MM_THRESHOLD,
)

app = FastAPI(title="Pipeline Pantographe API")

# Couleurs BGR pour l'overlay
COULEUR_FISSURE = (0, 0, 255)          # rouge : zones fissurées
COULEUR_ECAILLAGE = (0, 140, 255)      # orange : zones écaillées
COULEUR_OK = (0, 255, 0)               # vert : pas de défaut
COULEUR_DEFAUT = (0, 0, 255)           # rouge : défaut détecté
COULEUR_TEXTE_BG = (0, 0, 0)
COULEUR_BANDE_GRISE = (190, 190, 190)  # gris fané : simple confirmation visuelle
                                        # que la bande est segmentée (pas un contour,
                                        # pas de couleur vive — juste un léger voile gris)
ALPHA_BANDE_GRISE = 200              # opacité faible (0-255) pour rester "fané"

# ── Seuils d'alerte (identiques au pipeline vidéo d'origine) ──────────
# Pas de filtre de "nettoyage" ou de "plausibilité" ici : ton modèle
# ThinCrackNet est déjà entraîné et fiable sur la tâche de segmentation
# de fissure. On affiche simplement le résultat du modèle, comme dans
# le pipeline vidéo qui fonctionne.


def _dessiner_texte(img, texte, x, y, couleur=(255, 255, 255), scale=0.55, epaisseur=1):
    """Petit texte avec fond noir pour rester lisible sur toutes les images."""
    (w, h), _ = cv2.getTextSize(texte, cv2.FONT_HERSHEY_SIMPLEX, scale, epaisseur)
    cv2.rectangle(img, (x - 2, y - h - 4), (x + w + 2, y + 4), COULEUR_TEXTE_BG, -1)
    cv2.putText(img, texte, (x, y), cv2.FONT_HERSHEY_SIMPLEX, scale, couleur, epaisseur, cv2.LINE_AA)


def encoder_png_base64(image_bgra: np.ndarray) -> str:
    """Encode une image RGBA (avec canal alpha, donc PNG obligatoire —
    le JPEG ne supporte pas la transparence) en base64, prête à être
    décodée avec Texture2D.LoadImage côté Unity et affichée en overlay
    par-dessus le flux caméra en direct."""
    ok, buf = cv2.imencode(".png", image_bgra)
    if not ok:
        return ""
    return base64.b64encode(buf.tobytes()).decode("utf-8")


def _peindre_masque(overlay_bgr, alpha, mask_bool, couleur, alpha_val=255):
    """Peint uniquement les pixels où mask_bool est vrai, avec transparence
    ailleurs inchangée. alpha_val contrôle l'opacité (255=opaque, ~150=semi-transparent)."""
    overlay_bgr[mask_bool] = couleur
    alpha[mask_bool] = alpha_val


def _peindre_contours(overlay_bgr, alpha, contours, couleur, epaisseur=2, alpha_val=255):
    """Dessine uniquement le contour (pas le remplissage) — utile pour les
    contours de défauts, qui doivent rester fins et nets dans l'overlay."""
    h, w = alpha.shape[:2]
    canvas_contour = np.zeros((h, w), dtype=np.uint8)
    cv2.drawContours(canvas_contour, contours, -1, 255, epaisseur)
    mask_bool = canvas_contour > 0
    overlay_bgr[mask_bool] = couleur
    alpha[mask_bool] = alpha_val


def _peindre_texte(overlay_bgr, alpha, texte, x, y, couleur, scale=0.5, epaisseur=1):
    """Dessine du texte SANS fond opaque derrière (contrairement à
    _dessiner_texte) — seuls les pixels du texte lui-même deviennent
    visibles dans l'overlay transparent."""
    h, w = alpha.shape[:2]
    canvas_texte = np.zeros((h, w), dtype=np.uint8)
    cv2.putText(canvas_texte, texte, (x, y), cv2.FONT_HERSHEY_SIMPLEX, scale, 255, epaisseur, cv2.LINE_AA)
    mask_bool = canvas_texte > 0
    overlay_bgr[mask_bool] = couleur
    alpha[mask_bool] = 255





def analyser_une_image(frame_bgr: np.ndarray, px_per_mm_client: float = None):
    """
    Reprend la logique de la boucle vidéo, mais pour UNE seule image.
    Retourne (result_json, overlay_bgra).

    overlay_bgra est un canvas RGBA à la MÊME résolution que frame_bgr :
    - alpha=0 (totalement transparent) partout où il n'y a rien à montrer
    - alpha>0 uniquement sur : le voile gris de la bande segmentée, les
      pixels de fissure/écaillage CONFIRMÉS (reprojetés depuis le repère
      "redressé" vers le repère de l'image d'origine), et les petites
      étiquettes de texte.

    RÈGLE D'AFFICHAGE (important) :
    - La bande segmentée est TOUJOURS peinte en gris fané, quel que soit
      le résultat des modèles de défaut.
    - Le rouge (fissure) et l'orange (écaillage) ne sont peints QUE sur
      les pixels que le modèle a réellement segmentés comme défaut, et
      SEULEMENT si le pourcentage dépasse le seuil d'alerte
      (DEFECT_PCT_ALERT / ECAILLE_PCT_ALERT) — résultat brut du modèle,
      sans post-traitement qui pourrait effacer une vraie détection.
    Cet overlay est fait pour être superposé par-dessus le flux caméra en
    direct côté Unity (pas pour remplacer l'image affichée).
    """
    h_frame, w_frame = frame_bgr.shape[:2]
    overlay_bgr = np.zeros((h_frame, w_frame, 3), dtype=np.uint8)
    alpha = np.zeros((h_frame, w_frame), dtype=np.uint8)

    result = full_pipeline_inference(
        frame_bgr, yolo_inf, seg_inf, device, CFG,
        margin_pct=CFG["roi_margin_pct"]
    )

    if not result["roi_box"]:
        _peindre_texte(overlay_bgr, alpha, "Aucune bande detectee", 20, 30, (0, 0, 255))
        overlay_bgra = np.dstack([overlay_bgr, alpha])
        return {"bande_detectee": False, "bandes": []}, overlay_bgra

    bandes_resultats = []

    for i, det in enumerate(result["detections"]):
        band_mask_full = det["mask"]
        x1, y1, x2, y2 = [int(v) for v in det["box"]]

        # ── Voile gris fané sur toute la bande segmentée ──────────────
        # (confirmation visuelle que la segmentation a eu lieu — pas un
        # contour, pas de couleur vive, juste un léger gris semi-
        # transparent sur les pixels réellement segmentés par Mask R-CNN)
        # → TOUJOURS peint, indépendamment du résultat des modèles de défaut.
        _peindre_masque(overlay_bgr, alpha, band_mask_full > 0,
                         COULEUR_BANDE_GRISE, alpha_val=ALPHA_BANDE_GRISE)

        params = get_straighten_transform(
            band_mask_full, det["box"], frame_bgr.shape[0], frame_bgr.shape[1]
        )
        if params is None:
            _peindre_texte(overlay_bgr, alpha, "Redressement impossible", x1, max(y1 - 10, 20), (0, 0, 255))
            continue

        straightened, straight_mask = extract_straightened_local(
            frame_bgr, band_mask_full, params
        )
        if straightened.size == 0:
            continue

        gray = cv2.cvtColor(straightened, cv2.COLOR_BGR2GRAY)
        in_band = (gray > 5).astype(np.uint8)
        n_band = max(int(in_band.sum()), 1)

        # ════════════════════════════════════════════════════════════
        #  FISSURES — prédiction directe du modèle (pas de post-traitement)
        # ════════════════════════════════════════════════════════════
        crack_pred = predict_defects_on_straightened(
            straightened, crack_model, crack_transform, device, CRACK_THRESHOLD
        )
        crack_mask = crack_pred * in_band
        crack_pct = float(crack_mask.sum() / n_band * 100)
        fissure_defaut = crack_pct > DEFECT_PCT_ALERT
        fissure_dims = mesurer_dimensions_fissure(crack_mask, px_per_mm_client) if fissure_defaut else None

        # ════════════════════════════════════════════════════════════
        #  ÉCAILLAGE — prédiction directe du modèle (pas de post-traitement)
        # ════════════════════════════════════════════════════════════
        ecaille_pred = predict_ecaillage(
            straightened, ecaille_model, ecaille_transform, device, ECAILLE_THRESHOLD
        )
        ecaille_mask = ecaille_pred * in_band
        ecaille_pct = float(ecaille_mask.sum() / n_band * 100)
        ecaillage_defaut = ecaille_pct > ECAILLE_PCT_ALERT

        # ── Reprojection des masques défauts vers le repère original ──
        crack_mask_frame = reproject_defect_mask(crack_mask, params, frame_bgr.shape) > 0
        ecaille_mask_frame = reproject_defect_mask(ecaille_mask, params, frame_bgr.shape) > 0

        # ── Rouge fissure UNIQUEMENT si défaut confirmé et fiable ──────
        if fissure_defaut:
            _peindre_masque(overlay_bgr, alpha, crack_mask_frame, COULEUR_FISSURE, alpha_val=180)
            crack_u8 = (crack_mask_frame.astype(np.uint8)) * 255
            cnts_crack, _ = cv2.findContours(crack_u8, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            _peindre_contours(overlay_bgr, alpha, cnts_crack, COULEUR_FISSURE, epaisseur=1)

        # ── Orange écaillage UNIQUEMENT si défaut confirmé et fiable ───
        if ecaillage_defaut:
            _peindre_masque(overlay_bgr, alpha, ecaille_mask_frame, COULEUR_ECAILLAGE, alpha_val=180)
            ecaille_u8 = (ecaille_mask_frame.astype(np.uint8)) * 255
            cnts_ecaille, _ = cv2.findContours(ecaille_u8, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            _peindre_contours(overlay_bgr, alpha, cnts_ecaille, COULEUR_ECAILLAGE, epaisseur=1)

        # ── Orientation + épaisseur ──────────────────────────────
        orientation, orient_metrics = detect_view_orientation(straight_mask)

        thickness_result = None
        if orientation == "profil":
            sections = measure_thickness_sections(straight_mask)
            px_per_mm = px_per_mm_client if px_per_mm_client else get_px_per_mm(straight_mask)
            print(f"px_per_mm_client={px_per_mm_client}")
            thickness_result = evaluate_defect(
                sections, px_per_mm, MIN_THICKNESS_MM_THRESHOLD
            )

            # ── Overlay épaisseur (jaune), reprojeté — même concept que
            #    fissure/écaillage : uniquement les lignes de mesure,
            #    jamais toute la bande. (aligné sur le pipeline vidéo)
            if sections:
                unit = thickness_result.get("unit", "px")
                values = thickness_result.get("sections_mm") if unit == "mm" \
                    else thickness_result.get("sections_px")
                min_idx = int(np.argmin(values)) if values else None

                thickness_mask_straight = draw_thickness_lines_mask(
                    straight_mask.shape[:2], sections, min_idx=min_idx
                )
                thickness_mask_frame = reproject_defect_mask(
                    thickness_mask_straight, params, frame_bgr.shape
                ) > 0
                _peindre_masque(overlay_bgr, alpha, thickness_mask_frame,
                                 THICKNESS_COLOR, alpha_val=220)

        # ── Étiquette texte flottante au-dessus de la bbox ───────

        cx = (det["box"][0] + det["box"][2]) / 2.0
        bande_id = "gauche" if cx < w_frame / 2 else "droite"

        bande_json = {
            "id": bande_id,              # <-- identifiant stable
            "box": [float(v) for v in det["box"]],
            "score": float(det["score"]),
            "orientation": orientation,
            "fissure_pct": round(crack_pct, 3),
            "fissure_defaut": fissure_defaut,
            "ecaillage_pct": round(ecaille_pct, 3),
            "ecaillage_defaut": ecaillage_defaut,
        }

        # IMPORTANT : on met des valeurs par défaut (pas de null) car
        # JsonUtility côté Unity gère mal les null sur des types valeur
        # (bool / float). Si pas d'épaisseur calculée -> 0.0 / false.
        if thickness_result and thickness_result.get("status") == "calibre":
            labels = ["S1", "S2", "S3"]
            sections_json = []
            for j, val_mm in enumerate(thickness_result["sections_mm"]):
                defaut_epaisseur = bool(val_mm < MIN_THICKNESS_MM_THRESHOLD)
                sections_json.append({
                    "id": labels[j] if j < len(labels) else f"S{j+1}",
                    "thickness_mm": round(float(val_mm), 2),
                    "defaut": defaut_epaisseur,
                })
            bande_json["sections"] = sections_json
            bande_json["min_thickness_mm"] = round(thickness_result["min_thickness_mm"], 2)
            bande_json["epaisseur_defaut"] = bool(thickness_result["defaut"])
        else:
            bande_json["sections"] = []
            bande_json["min_thickness_mm"] = 0.0
            bande_json["epaisseur_defaut"] = False
        bande_json["fissure_longueur_mm"] = fissure_dims["longueur_mm"] if fissure_dims else 0.0
        bande_json["fissure_largeur_mm"] = fissure_dims["largeur_mm"] if fissure_dims else 0.0




        bandes_resultats.append(bande_json)

    overlay_bgra = np.dstack([overlay_bgr, alpha])
    return {
        "bande_detectee": len(bandes_resultats) > 0,
        "bandes": bandes_resultats,
    }, overlay_bgra


def _lire_image_upload(contents: bytes):
    np_arr = np.frombuffer(contents, np.uint8)
    return cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
def mesurer_dimensions_fissure(crack_mask, px_per_mm):
    """
    Mesure la longueur et la largeur (epaisseur) de la fissure en mm.
    Le redressement ne fait que tourner l'image (pas de resize), donc
    l'echelle px/mm calculee sur l'image d'origine reste valide ici.
    """
    mask_u8 = (crack_mask > 0).astype(np.uint8)
    contours, _ = cv2.findContours(mask_u8, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if not contours:
        return None
    contour = max(contours, key=cv2.contourArea)
    if cv2.contourArea(contour) < 5:
        return None
    (cx, cy), (w, h), angle = cv2.minAreaRect(contour)
    longueur_px = max(w, h)
    largeur_px = min(w, h)
    if px_per_mm and px_per_mm > 0:
        return {
            "longueur_mm": round(longueur_px / px_per_mm, 2),
            "largeur_mm": round(largeur_px / px_per_mm, 2),
        }
  
    return {"longueur_mm": 0.0, "largeur_mm": 0.0}

@app.post("/analyse")
async def analyse(file: UploadFile = File(...), px_per_mm: float = Form(None)):
    contents = await file.read()
    frame_bgr = _lire_image_upload(contents)

    if frame_bgr is None:
        return JSONResponse(status_code=400, content={"error": "image illisible"})

    result, overlay_bgra = analyser_une_image(frame_bgr, px_per_mm_client=px_per_mm)
    result["image_annotee"] = encoder_png_base64(overlay_bgra)

    return JSONResponse(content=result)


@app.get("/health")
async def health():
    """Petit endpoint pour vérifier que le serveur tourne, sans rien analyser."""
    return {"status": "ok"}


# ============================================================
#  INTERFACE DE TEST — page web simple pour envoyer une image
#  et voir le résultat (overlay + JSON) sans passer par Unity.
#  Accessible depuis n'importe quel navigateur sur le réseau :
#      http://<ip-du-pc>:8000/
# ============================================================

_PAGE_TEST_HTML = """
<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="UTF-8">
<title>Test Pipeline Pantographe</title>
<style>
  body { font-family: system-ui, sans-serif; background:#111; color:#eee; margin:0; padding:20px; }
  h1 { font-size: 1.3rem; }
  .zone { border:2px dashed #555; border-radius:10px; padding:20px; text-align:center; margin-bottom:20px; }
  .zone.dragover { border-color:#4caf50; background:#1a2a1a; }
  input[type=file] { color:#eee; }
  button { background:#2d6cdf; color:white; border:none; padding:10px 18px; border-radius:6px; cursor:pointer; font-size:1rem; }
  button:disabled { background:#555; cursor:not-allowed; }
  .canvas-wrap { position:relative; display:inline-block; max-width:100%; }
  canvas { max-width:100%; border-radius:8px; border:1px solid #333; display:block; }
  #status { margin:10px 0; color:#9cf; }
  pre { background:#000; color:#8f8; padding:12px; border-radius:8px; overflow:auto; max-height:300px; }
  .legende { display:flex; gap:16px; margin:10px 0; font-size:0.9rem; }
  .legende span { display:inline-flex; align-items:center; gap:6px; }
  .swatch { width:14px; height:14px; border-radius:3px; display:inline-block; }
  .cols { display:flex; gap:24px; flex-wrap:wrap; align-items:flex-start; }
  .col { flex:1; min-width:320px; }
</style>
</head>
<body>
  <h1>🔍 Test du pipeline pantographe (fissure / écaillage / épaisseur)</h1>

  <div class="zone" id="dropzone">
    <p>Glisse une image ici, ou choisis un fichier :</p>
    <input type="file" id="fileInput" accept="image/*">
    <br><br>
    <button id="btnAnalyser" disabled>Analyser</button>
  </div>

  <div id="status"></div>

  <div class="legende">
    <span><span class="swatch" style="background:#bebebe"></span> Bande segmentée</span>
    <span><span class="swatch" style="background:red"></span> Fissure</span>
    <span><span class="swatch" style="background:orange"></span> Écaillage</span>
    <span><span class="swatch" style="background:yellow"></span> Épaisseur</span>
  </div>
 

  <h3>Résultat — image segmentée</h3>
  <div class="canvas-wrap">
    <canvas id="canvasBase"></canvas>
    <canvas id="canvasOverlay" style="position:absolute; top:0; left:0;"></canvas>
  </div>

  <details style="margin-top:16px;">
    <summary style="cursor:pointer; color:#9cf;">Voir le JSON brut</summary>
    <pre id="jsonOut">—</pre>
  </details>
  <div class="cols">
    <div class="col">
      <div class="canvas-wrap">
        <canvas id="canvasBase"></canvas>
        <canvas id="canvasOverlay" style="position:absolute; top:0; left:0;"></canvas>
      </div>
    </div>
    <div class="col">
      <h3>Résultat JSON</h3>
      <pre id="jsonOut">—</pre>
    </div>
  </div>

<script>
const fileInput   = document.getElementById('fileInput');
const btnAnalyser = document.getElementById('btnAnalyser');
const dropzone    = document.getElementById('dropzone');
const statusEl    = document.getElementById('status');
const canvasBase    = document.getElementById('canvasBase');
const canvasOverlay = document.getElementById('canvasOverlay');
const jsonOut      = document.getElementById('jsonOut');

let currentFile = null;

function setFile(file) {
  currentFile = file;
  btnAnalyser.disabled = !file;
  if (!file) return;
  const img = new Image();
  img.onload = () => {
    canvasBase.width = canvasOverlay.width = img.width;
    canvasBase.height = canvasOverlay.height = img.height;
    const ctx = canvasBase.getContext('2d');
    ctx.clearRect(0,0,canvasBase.width, canvasBase.height);
    ctx.drawImage(img, 0, 0);
    canvasOverlay.getContext('2d').clearRect(0,0,canvasOverlay.width, canvasOverlay.height);
    jsonOut.textContent = '—';
  };
  img.src = URL.createObjectURL(file);
}

fileInput.addEventListener('change', e => setFile(e.target.files[0]));

['dragover','dragenter'].forEach(ev => dropzone.addEventListener(ev, e => {
  e.preventDefault(); dropzone.classList.add('dragover');
}));
['dragleave','drop'].forEach(ev => dropzone.addEventListener(ev, e => {
  e.preventDefault(); dropzone.classList.remove('dragover');
}));
dropzone.addEventListener('drop', e => {
  const file = e.dataTransfer.files[0];
  if (file) setFile(file);
});

btnAnalyser.addEventListener('click', async () => {
  if (!currentFile) return;
  btnAnalyser.disabled = true;
  statusEl.textContent = 'Analyse en cours...';

  const form = new FormData();
  form.append('file', currentFile);

  try {
    const resp = await fetch('/analyse', { method: 'POST', body: form });
    const data = await resp.json();

    if (data.error) {
      statusEl.textContent = 'Erreur : ' + data.error;
      btnAnalyser.disabled = false;
      return;
    }

    // Affiche l'overlay PNG transparent par-dessus l'image de base
    if (data.image_annotee) {
      const overlayImg = new Image();
      overlayImg.onload = () => {
        const ctx = canvasOverlay.getContext('2d');
        ctx.clearRect(0,0,canvasOverlay.width, canvasOverlay.height);
        ctx.drawImage(overlayImg, 0, 0, canvasOverlay.width, canvasOverlay.height);
      };
      overlayImg.src = 'data:image/png;base64,' + data.image_annotee;
    }

    const dataSansImage = { ...data };
    delete dataSansImage.image_annotee;
    jsonOut.textContent = JSON.stringify(dataSansImage, null, 2);

    statusEl.textContent = data.bande_detectee
      ? '✅ Analyse terminée — ' + data.bandes.length + ' bande(s) détectée(s)'
      : '⚠️ Aucune bande détectée';
  } catch (err) {
    statusEl.textContent = 'Erreur réseau : ' + err;
  } finally {
    btnAnalyser.disabled = false;
  }
});
</script>
</body>
</html>
"""
FEEDBACK_FILE = "feedback_log.json"

class FeedbackIn(BaseModel):
    bande_id: str
    valide: bool
    commentaire: str = ""
    fissure_pct: float = 0.0
    fissure_defaut: bool = False
    fissure_longueur_mm: float = 0.0
    fissure_largeur_mm: float = 0.0
    ecaillage_pct: float = 0.0
    ecaillage_defaut: bool = False
    min_thickness_mm: float = 0.0
    epaisseur_defaut: bool = False
    orientation: str = ""
    score: float = 0.0

@app.post("/feedback")
async def feedback(entree: FeedbackIn):
    """Enregistre une validation/commentaire utilisateur avec toutes les
    infos de detection, dans un fichier JSON local (append)."""
    enregistrement = entree.dict()
    enregistrement["horodatage"] = datetime.now().isoformat()

    donnees = []
    if os.path.exists(FEEDBACK_FILE):
        try:
            with open(FEEDBACK_FILE, "r", encoding="utf-8") as f:
                donnees = json.load(f)
        except (json.JSONDecodeError, IOError):
            donnees = []

    donnees.append(enregistrement)

    with open(FEEDBACK_FILE, "w", encoding="utf-8") as f:
        json.dump(donnees, f, ensure_ascii=False, indent=2)

    return {"status": "ok", "total_enregistrements": len(donnees)}

@app.get("/", response_class=HTMLResponse)
async def page_test():
    """Interface web simple pour tester une image sans passer par Unity.
    Ouvre http://<ip-du-pc>:8000/ dans un navigateur (PC, téléphone, casque
    — tant qu'il est sur le même réseau que le serveur)."""
    return HTMLResponse(content=_PAGE_TEST_HTML)


if __name__ == "__main__":
    # host="0.0.0.0" est OBLIGATOIRE pour que le Quest 3 / téléphone
    # (autre appareil sur le réseau) puisse atteindre ce serveur.
    # "127.0.0.1" ne fonctionnerait que depuis le PC lui-même.
    uvicorn.run(app, host="0.0.0.0", port=8000)