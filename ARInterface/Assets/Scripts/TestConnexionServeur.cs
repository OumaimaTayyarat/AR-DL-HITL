using System.Collections;
using UnityEngine;
using UnityEngine.Networking;

public class TestConnexionServeur : MonoBehaviour
{
    [SerializeField] private string healthUrl = "http://192.168.137.1:8000/health";

    void Start()
    {
        StartCoroutine(TesterConnexion());
    }

    private IEnumerator TesterConnexion()
    {
        DebugHud.SetStatus($"Test connexion vers {healthUrl}...");

        using (UnityWebRequest req = UnityWebRequest.Get(healthUrl))
        {
            req.timeout = 5;
            yield return req.SendWebRequest();

            if (req.result == UnityWebRequest.Result.Success)
            {
                DebugHud.SetStatus($"CONNEXION OK: {req.downloadHandler.text}");
            }
            else
            {
                DebugHud.SetStatus($"ECHEC: {req.error} (code {req.responseCode})");
            }
        }
    }
}