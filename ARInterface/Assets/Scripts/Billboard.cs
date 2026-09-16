using UnityEngine;

public class Billboard : MonoBehaviour
{
    private Transform _camTransform;

    void Start()
    {
        if (Camera.main != null)
            _camTransform = Camera.main.transform;
    }

    void Update()
    {
        if (_camTransform == null)
        {
            if (Camera.main == null) return;
            _camTransform = Camera.main.transform;
        }

        transform.LookAt(transform.position + (transform.position - _camTransform.position));
    }
}