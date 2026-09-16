using UnityEngine;


public class DiagnosticMouvement : MonoBehaviour
{
    private Vector3 _dernierePosition;
    private float _tempsDebut;
    private bool _initialise = false;

    void Start()
    {
        _tempsDebut = Time.time;
        _dernierePosition = transform.position;
        Debug.Log($"[DIAG-MVT] Start() - Position initiale: {transform.position}, " +
                   $"Active: {gameObject.activeSelf}, Time: {Time.time:F3}");
    }

    void Update()
    {
        if (!_initialise)
        {
            _dernierePosition = transform.position;
            _initialise = true;
            return;
        }

        float distance = Vector3.Distance(transform.position, _dernierePosition);

        // Log continu pendant les 3 premieres secondes
        if (Time.time - _tempsDebut < 3f)
        {
            Debug.Log($"[DIAG-MVT] t={Time.time:F3} Position={transform.position} " +
                       $"Delta={distance:F4} Active={gameObject.activeInHierarchy}");
        }

        // Alerte si saut brutal
        if (distance > 0.1f)
        {
            Debug.LogWarning($"[DIAG-MVT] !!! SAUT DETECTE !!! " +
                              $"De {_dernierePosition} vers {transform.position} " +
                              $"(delta={distance:F3}) au temps t={Time.time:F3}");
        }

        _dernierePosition = transform.position;
    }

    void OnDisable()
    {
        Debug.Log($"[DIAG-MVT] OnDisable() appele a t={Time.time:F3}, position={transform.position}");
    }

    void OnEnable()
    {
        Debug.Log($"[DIAG-MVT] OnEnable() appele a t={Time.time:F3}");
    }
}