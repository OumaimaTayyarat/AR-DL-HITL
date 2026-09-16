using UnityEngine;
using TMPro;


public class DebugHud : MonoBehaviour
{
    [SerializeField] private TMP_Text statusText;

    public static DebugHud Instance { get; private set; }

    private void Awake()
    {
        Instance = this;
        if (statusText == null)
        {
            statusText = GetComponent<TMP_Text>();
        }
    }

    public static void SetStatus(string message)
    {
        if (Instance == null || Instance.statusText == null)
        {
            Debug.Log($"[DebugHud] {message}");
            return;
        }
        Instance.statusText.text = message;
        Debug.Log($"[DebugHud] {message}");
    }
}