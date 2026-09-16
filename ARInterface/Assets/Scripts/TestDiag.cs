using UnityEngine;

public class TestDiag : MonoBehaviour
{
    void Awake()
    {
        Debug.LogError("ZZZ_AWAKE_TESTDIAG");
    }

    void Start()
    {
        Debug.LogError("ZZZ_START_TESTDIAG");
    }

    void Update()
    {
        if (Time.frameCount % 60 == 0)
        {
            Debug.LogError("ZZZ_UPDATE_TESTDIAG_frame" + Time.frameCount);
        }
    }
}