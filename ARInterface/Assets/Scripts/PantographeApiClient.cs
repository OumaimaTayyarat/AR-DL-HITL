using System.Collections;
using UnityEngine;
using UnityEngine.Networking;
using Newtonsoft.Json;
using Meta.XR;

/// <summary>
/// Boucle principale : capture une frame à intervalle regulier, l'envoie
/// au serveur FastAPI (/analyse), parse la reponse et transmet le resultat
/// + la pose camera au placeur AR (AROverlayPlacer).
/// </summary>
public class PantographeApiClient : MonoBehaviour
{
    [Header("Config serveur")]
    [SerializeField] private string serverUrl = "http://192.168.137.1:8000/analyse";
    [Header("Raycast pour distance reelle (conversion mm/px)")]
    [SerializeField] private EnvironmentRaycastManager raycastManager;
    [SerializeField] private float distanceParDefautM = 0.5f;

    [SerializeField] private PantographInfoCardManager infoCard;
    [Tooltip("Intervalle entre deux analyses (secondes). L'inference PC + reseau limite la frequence realiste.")]
    [SerializeField] private float intervalSeconds = 0.1f;

    [Tooltip("Timeout d'une requete avant abandon (secondes).")]
    [SerializeField] private int timeoutSeconds = 8;

    [Header("References")]
    [SerializeField] private PassthroughCaptureManager captureManager;
    [SerializeField] private AROverlayPlacer overlayPlacer;
    [SerializeField] private PantographDefectMarkers defectMarkers;

    private bool _requeteEnCours;
    void Start()
    {
        Debug.Log("[DIAG] PantographApiClient.Start() appele !");
        StartCoroutine(BoucleAnalyse());
    }
private IEnumerator BoucleAnalyse()
{
    var attente = new WaitForSecondsRealtime(intervalSeconds);

    while (true)
    {
        yield return attente;

        if (_requeteEnCours)
        {
            Debug.Log("[DIAG] Requete deja en cours, skip");
            continue;
        }
        if (captureManager == null)
        {
            Debug.LogError("[DIAG] captureManager est NULL - a assigner dans l'Inspector !");
            continue;
        }
        if (!captureManager.EstPret)
        {
            Debug.LogWarning("[DIAG] captureManager.EstPret = false, skip ce tour");
            continue;
        }

        Debug.Log("[DIAG] Envoi requete vers " + serverUrl);
        yield return EnvoyerEtTraiter();
    }
}

    private IEnumerator EnvoyerEtTraiter()
    {
        _requeteEnCours = true;

        var capture = captureManager.CapturerFrame();
        if (!capture.success)
        {
            _requeteEnCours = false;
            yield break;
        }

        float pxPerMm = CalculerPxParMm(capture);

        WWWForm form = new WWWForm();
        form.AddBinaryData("file", capture.jpgBytes, "frame.jpg", "image/jpeg");
        form.AddField("px_per_mm", pxPerMm.ToString(System.Globalization.CultureInfo.InvariantCulture));

        using (UnityWebRequest req = UnityWebRequest.Post(serverUrl, form))
        {
            req.timeout = timeoutSeconds;
            yield return req.SendWebRequest();

            if (req.result != UnityWebRequest.Result.Success)
            {
                // Requete echouee : on ne touche pas a l'overlay, l'ancien
                // resultat reste affiche (voir point "pas de coupure" plus bas).
                Debug.LogWarning($"[PantographeApiClient] ERREUR reseau: {req.error}");
                _requeteEnCours = false;
                yield break;
            }

            AnalyseResult result = null;
            try
            {
                result = JsonConvert.DeserializeObject<AnalyseResult>(req.downloadHandler.text);
            }
            catch (System.Exception e)
            {
                Debug.LogError($"[PantographeApiClient] Erreur parsing JSON: {e.Message}");
            }

        if (result != null)

{
        Debug.Log($"[DIAG] Reponse recue ! bande_detectee={result.BandeDetectee}, nb_bandes={result.Bandes?.Count}");
        if (infoCard != null)
        infoCard.MettreAJour(result);

    if (overlayPlacer != null)
    {
        overlayPlacer.AfficherResultat(
            result,
            capture.cameraPosition,
            capture.cameraRotation,
            capture.verticalFovDeg,
            capture.horizontalFovDeg,
            capture.width,
            capture.height
        );
    }

    if (defectMarkers != null)
        defectMarkers.MettreAJour(result);
}
        }

        _requeteEnCours = false;
    }
    private float CalculerPxParMm(PassthroughCaptureManager.Capture capture)
{
    Vector3 direction = capture.cameraRotation * Vector3.forward;
    float distanceM = distanceParDefautM;

    if (raycastManager != null)
    {
        Ray ray = new Ray(capture.cameraPosition, direction);
        if (raycastManager.Raycast(ray, out var hitInfo))
        {
            distanceM = Vector3.Distance(capture.cameraPosition, hitInfo.point);
        }
    }

    float focalLengthPx = (capture.height / 2f) / Mathf.Tan(capture.verticalFovDeg * Mathf.Deg2Rad * 0.5f);
    float pxPerMm = focalLengthPx / (distanceM * 1000f);

    Debug.Log($"[PX_PER_MM] distance={distanceM:F3}m focal_px={focalLengthPx:F1} -> px_per_mm={pxPerMm:F3}");
    return pxPerMm;
}
}