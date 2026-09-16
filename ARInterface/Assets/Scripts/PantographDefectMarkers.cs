using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Affiche des icones flottantes (marqueurs) directement ancrees sur des
/// points precis du mesh 3D du pantographe (et non pas en overlay camera).
/// Comme les marqueurs sont enfants de l'ancre, ils suivent automatiquement
/// le modele quand l'utilisateur le tourne/zoome/deplace (grab).
/// </summary>
public class PantographDefectMarkers : MonoBehaviour
{
    [System.Serializable]
    public class BandeAnchor
    {
        [Tooltip("Doit correspondre exactement au champ 'id' renvoye par le serveur (ex: gauche / droite)")]
        public string bandeId;

        [Tooltip("Transform vide (empty) place a l'endroit precis du mesh ou afficher le marqueur")]
        public Transform anchor;
    }

    [Header("Association bande <-> position sur le modele 3D")]
    [SerializeField] private List<BandeAnchor> anchors;

    [Header("Prefab marqueur (icone/billboard flottant)")]
    [SerializeField] private GameObject markerPrefab;

    [Header("Decalage local au-dessus de l'ancre (metres)")]
    [SerializeField] private Vector3 offsetLocal = new Vector3(0f, 0.03f, 0f);

    [Header("Couleurs")]
    [SerializeField] private Color couleurFissure = Color.red;
    [SerializeField] private Color couleurEcaillage = new Color(1f, 0.55f, 0f); // orange
    [SerializeField] private Color couleurEpaisseur = Color.yellow;

    [Header("Taille reelle voulue du marqueur (metres, dans le MONDE)")]
    [SerializeField] private float tailleMondeMarqueur = 0.04f;

    private readonly Dictionary<string, GameObject> _markersInstancies = new();

    /// <summary>
    /// Appele apres chaque reponse du serveur (/analyse), en plus ou a la
    /// place de l'overlay camera classique (AROverlayPlacer).
    /// </summary>
    public void MettreAJour(AnalyseResult result)
    {
        Debug.Log($"[MARKERS] MettreAJour appele. result null? {result == null}");

        // IMPORTANT : on ne cache plus tout par defaut ici. Si le serveur ne
        // detecte rien cette frame (bande hors champ, echec ponctuel), on
        // garde le dernier marqueur affiche tel quel (reste "superpose").
        // Un marqueur n'est cache QUE si sa bande precise revient avec
        // explicitement aucun defaut (fissure/ecaillage/epaisseur tous false).

        if (result == null || !result.BandeDetectee || result.Bandes == null)
        {
            Debug.Log("[MARKERS] Rien de nouveau detecte cette frame -> on garde l'affichage precedent");
            return;
        }

        Debug.Log($"[MARKERS] Nombre de bandes recues: {result.Bandes.Count}");

        foreach (var bande in result.Bandes)
        {
            bool fissure = bande.FissureDefaut;
            bool ecaillage = bande.EcaillageDefaut;
            bool epaisseur = bande.EpaisseurDefaut;

            Debug.Log($"[MARKERS] Bande id='{bande.Id}' fissure={fissure} ecaillage={ecaillage} epaisseur={epaisseur}");

            var anchorInfo = anchors.Find(a => a.bandeId == bande.Id);
            if (anchorInfo == null || anchorInfo.anchor == null)
            {
                Debug.LogWarning($"[PantographDefectMarkers] Aucune ancre configuree pour bandeId='{bande.Id}' (anchors configures: {string.Join(",", anchors.ConvertAll(a => a.bandeId))})");
                continue;
            }

            if (!fissure && !ecaillage && !epaisseur)
            {
                // Cette bande precise confirme explicitement l'absence de
                // defaut -> on cache SEULEMENT son marqueur a elle.
                if (_markersInstancies.TryGetValue(bande.Id, out var m) && m != null)
                {
                    m.SetActive(false);
                    Debug.Log($"[MARKERS] Bande '{bande.Id}' : defaut disparu -> marqueur cache");
                }
                continue;
            }

            if (!_markersInstancies.TryGetValue(bande.Id, out var marker) || marker == null)
            {
                marker = Instantiate(markerPrefab, anchorInfo.anchor);
                marker.transform.localPosition = offsetLocal;
                marker.transform.localRotation = Quaternion.identity;

                // ── Compensation d'echelle : force une taille MONDE fixe,
                // peu importe combien de parents scales imbriques il y a
                // au-dessus de l'ancre (Strip_TGV, pantogra57_1, etc.)
                Vector3 parentLossyScale = anchorInfo.anchor.lossyScale;
                marker.transform.localScale = new Vector3(
                    tailleMondeMarqueur / Mathf.Max(parentLossyScale.x, 0.0001f),
                    tailleMondeMarqueur / Mathf.Max(parentLossyScale.y, 0.0001f),
                    tailleMondeMarqueur / Mathf.Max(parentLossyScale.z, 0.0001f)
                );

                _markersInstancies[bande.Id] = marker;
            }

            marker.SetActive(true);

            Debug.Log($"[MARKERS] Marker '{bande.Id}' -> WorldPos={marker.transform.position} " +
                      $"WorldScale={marker.transform.lossyScale} Active={marker.activeInHierarchy} " +
                      $"AnchorWorldPos={anchorInfo.anchor.position}");

            var renderer = marker.GetComponentInChildren<Renderer>();
            if (renderer == null)
            {
                Debug.LogWarning($"[MARKERS] Aucun Renderer trouve sur le marker '{bande.Id}' !");
            }
            else
            {
                Debug.Log($"[MARKERS] Renderer trouve: enabled={renderer.enabled}, " +
                          $"bounds={renderer.bounds}, material={renderer.material?.name}");

                // Priorite d'affichage couleur : fissure > ecaillage > epaisseur
                Color couleur = fissure ? couleurFissure : (ecaillage ? couleurEcaillage : couleurEpaisseur);
                renderer.material.color = couleur;
            }
        }
    }
}