using UnityEngine;
using Meta.XR;


public class AROverlayPlacer : MonoBehaviour
{
    [Header("References scene")]
    [SerializeField] private EnvironmentRaycastManager raycastManager;
    [SerializeField] private Transform overlayQuad;
    [SerializeField] private MeshRenderer overlayRenderer;

    [SerializeField] private float distanceParDefaut = 0.5f;

    [Header("Tolerance aux echecs ponctuels")]
    [Tooltip("Nombre d'echecs consecutifs avant de masquer l'overlay")]
    [SerializeField] private int echecsAvantMasquage = 3;

    private Texture2D _texture;
    private int _echecsConsecutifs = 0;

public void AfficherResultat(
    AnalyseResult result,
    Vector3 posCameraCapture,
    Quaternion rotCameraCapture,
    float fovVerticalDeg,
    float fovHorizontalDeg,
    int largeurImage,
    int hauteurImage)
{
    bool echec = result == null || !result.BandeDetectee || string.IsNullOrEmpty(result.ImageAnneteeBase64);

    if (echec)
    {
        _echecsConsecutifs++;
        if (_echecsConsecutifs >= echecsAvantMasquage && overlayQuad != null)
        {
            overlayQuad.gameObject.SetActive(false);
        }
        // sinon : on garde le dernier overlay affiche tel quel, pas de coupure
        return;
    }

    _echecsConsecutifs = 0;

    byte[] pngBytes = System.Convert.FromBase64String(result.ImageAnneteeBase64);
        if (_texture == null)
            _texture = new Texture2D(2, 2, TextureFormat.RGBA32, false);
        _texture.LoadImage(pngBytes);

        Vector3 direction = rotCameraCapture * Vector3.forward;
        float distance = distanceParDefaut;

        if (raycastManager != null)
        {
            Ray ray = new Ray(posCameraCapture, direction);
            if (raycastManager.Raycast(ray, out var hitInfo))
            {
                distance = Vector3.Distance(posCameraCapture, hitInfo.point);
                Debug.Log($"[AROverlayPlacer] Raycast OK, distance={distance:F3}m, hitPoint={hitInfo.point}");
            }
            else
            {
                Debug.LogWarning($"[AROverlayPlacer] Raycast SANS resultat, distance par defaut utilisee ({distanceParDefaut}m).");
            }
        }

        float hauteurQuad = 2f * distance * Mathf.Tan(fovVerticalDeg * Mathf.Deg2Rad * 0.5f);
        float largeurQuad = 2f * distance * Mathf.Tan(fovHorizontalDeg * Mathf.Deg2Rad * 0.5f);

        Vector3 position = posCameraCapture + direction * distance;
        Quaternion rotation = Quaternion.LookRotation(direction, rotCameraCapture * Vector3.up);

        overlayQuad.gameObject.SetActive(true);
        overlayQuad.SetPositionAndRotation(position, rotation);
        overlayQuad.localScale = new Vector3(largeurQuad, hauteurQuad, 1f);

        if (overlayRenderer != null && overlayRenderer.material.mainTexture != _texture)
        {
            overlayRenderer.material.mainTexture = _texture;
        }
    }
}