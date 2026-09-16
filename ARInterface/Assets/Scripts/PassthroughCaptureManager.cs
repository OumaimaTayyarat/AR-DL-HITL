using UnityEngine;
using Meta.XR;

public class PassthroughCaptureManager : MonoBehaviour
{
    [Header("Camera XR (CenterEyeAnchor)")]
    [SerializeField] private Camera xrCamera;

    [Header("Acces direct a la camera passthrough")]
    [SerializeField] private PassthroughCameraAccess passthroughCameraAccess;

    public struct Capture
    {
        public byte[] jpgBytes;
        public int width;
        public int height;
        public Vector3 cameraPosition;
        public Quaternion cameraRotation;
        public float verticalFovDeg;
        public bool success;
        public float horizontalFovDeg;
    }

    public bool EstPret =>
        xrCamera != null &&
        passthroughCameraAccess != null &&
        passthroughCameraAccess.IsPlaying &&
        passthroughCameraAccess.GetTexture() != null;

    void Start()
    {
        Debug.Log($"[DIAG] IsSupported={PassthroughCameraAccess.IsSupported}");
        if (passthroughCameraAccess == null)
        {
            Debug.LogError("[DIAG] passthroughCameraAccess n'est pas assigné dans l'Inspector !");
        }
    }

    void Update()
    {
        if (Time.frameCount % 90 == 0 && passthroughCameraAccess != null)
        {
            Debug.Log($"[DIAG] IsPlaying={passthroughCameraAccess.IsPlaying}, enabled={passthroughCameraAccess.enabled}, CurrentResolution={passthroughCameraAccess.CurrentResolution}");
        }
    }

    public Capture CapturerFrame(int qualiteJpg = 85)
    {
        Capture capture = default;

        if (!EstPret)
        {
            Debug.LogWarning("[PassthroughCaptureManager] Pas encore pret (camera passthrough non active ou texture indisponible).");
            return capture;
            var resolutions = PassthroughCameraAccess.GetSupportedResolutions(PassthroughCameraAccess.CameraPositionType.Left);
            foreach (var r in resolutions)
                   Debug.Log($"[Resolution disponible] {r.x}x{r.y}");
        }

        Texture source = passthroughCameraAccess.GetTexture();
        int width = passthroughCameraAccess.CurrentResolution.x;
        int height = passthroughCameraAccess.CurrentResolution.y;

        RenderTexture rt = RenderTexture.GetTemporary(width, height, 0, RenderTextureFormat.ARGB32);
        Graphics.Blit(source, rt);

        RenderTexture previous = RenderTexture.active;
        RenderTexture.active = rt;

        Texture2D snapshot = new Texture2D(width, height, TextureFormat.RGB24, false);
        snapshot.ReadPixels(new Rect(0, 0, width, height), 0, 0);
        snapshot.Apply();

        RenderTexture.active = previous;
        RenderTexture.ReleaseTemporary(rt);

        capture.jpgBytes = snapshot.EncodeToJPG(qualiteJpg);
        capture.width = width;
        capture.height = height;

        // ── Pose reelle de la camera passthrough (LensOffset applique) ──
        Pose camPose = passthroughCameraAccess.GetCameraPose();
        capture.cameraPosition = camPose.position;
        capture.cameraRotation = camPose.rotation;

        // ── FOV reel derive des intrinsics, base sur la ZONE RECADREE ──
        // reellement visible dans CurrentResolution, pas le capteur complet.
        // Reproduit la logique interne de CalcSensorCropRegion() du SDK :
        // CurrentResolution est souvent une portion recadree+centree de
        // SensorResolution, donc utiliser SensorResolution tel quel pour
        // calculer le FOV surestime le champ de vision reel -> overlay
        // trop grand a distance egale.
        var intr = passthroughCameraAccess.Intrinsics;
        Vector2 sensorRes = intr.SensorResolution;
        Vector2 curRes = new Vector2(width, height);
        Vector2 scaleFactor = curRes / sensorRes;
        scaleFactor /= Mathf.Max(scaleFactor.x, scaleFactor.y);
        Vector2 cropSize = new Vector2(sensorRes.x * scaleFactor.x, sensorRes.y * scaleFactor.y);

        float fovVerticalRad = 2f * Mathf.Atan((cropSize.y * 0.5f) / intr.FocalLength.y);
        float fovHorizontalRad = 2f * Mathf.Atan((cropSize.x * 0.5f) / intr.FocalLength.x);
        capture.verticalFovDeg = fovVerticalRad * Mathf.Rad2Deg;
        capture.horizontalFovDeg = fovHorizontalRad * Mathf.Rad2Deg;

        float fovVerticalRad_ancien = 2f * Mathf.Atan((sensorRes.y * 0.5f) / intr.FocalLength.y);
        Debug.Log($"[DIAG FOV] SensorRes={intr.SensorResolution}, CurrentRes=({width}x{height}), cropSize={cropSize}, " +
                   $"FOV_v ancien(capteur complet)={fovVerticalRad_ancien * Mathf.Rad2Deg:F1}°, " +
                   $"FOV_v nouveau(crop)={capture.verticalFovDeg:F1}°, FOV_h nouveau={capture.horizontalFovDeg:F1}°");

        capture.success = true;

        Destroy(snapshot);

#if UNITY_EDITOR || DEVELOPMENT_BUILD
        System.IO.File.WriteAllBytes(
            System.IO.Path.Combine(Application.persistentDataPath, "debug_frame.jpg"),
            capture.jpgBytes);
        Debug.Log($"[DEBUG] Frame sauvee dans {Application.persistentDataPath}/debug_frame.jpg");
#endif

        return capture;
    }
}