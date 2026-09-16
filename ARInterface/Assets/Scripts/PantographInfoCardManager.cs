using System.Collections.Generic;
using UnityEngine;

public class PantographInfoCardManager : MonoBehaviour
{
    [Header("Prefab de carte")]
    [SerializeField] private CarteBandeInfo prefabCarte;

    [Header("Position au-dessus du pantographe")]
    [SerializeField] private Transform pantographeReference;
    [SerializeField] private Vector3 offsetAuDessus = new Vector3(0f, 1f, 0f);

    [Header("Disposition horizontale")]
    [Tooltip("Espace entre deux cartes le long de l'axe horizontal local")]
    [SerializeField] private float espacementCartes = 0.4f;

    [Header("Billboard")]
    [SerializeField] private Transform cameraSuivie;

    private readonly List<CarteBandeInfo> _cartesActives = new List<CarteBandeInfo>();

    void LateUpdate()
    {
        if (pantographeReference != null)
        {
            transform.position = pantographeReference.position + offsetAuDessus;
        }

        if (cameraSuivie != null)
        {
            Vector3 direction = transform.position - cameraSuivie.position;
            if (direction.sqrMagnitude > 0.0001f)
                transform.rotation = Quaternion.LookRotation(direction);
        }
    }

    public void MettreAJour(AnalyseResult result)
    {
        // Persistance (point 1) : si rien de nouveau n'est detecte cette
        // frame, on garde les cartes deja affichees telles quelles.
        if (result == null || !result.BandeDetectee || result.Bandes == null || result.Bandes.Count == 0)
            return;

        // On reutilise les cartes existantes si possible, sinon on en cree
        // ou on en desactive selon le nombre de bandes detectees (point 2 :
        // 1 ou 2 bandes, jamais fige a 2).
        int nb = result.Bandes.Count;

        while (_cartesActives.Count < nb)
        {
            var nouvelle = Instantiate(prefabCarte, transform);
            _cartesActives.Add(nouvelle);
        }
        while (_cartesActives.Count > nb)
        {
            var derniere = _cartesActives[_cartesActives.Count - 1];
            _cartesActives.RemoveAt(_cartesActives.Count - 1);
            Destroy(derniere.gameObject);
        }

        // Disposition horizontale cote a cote (axe local right), centree,
        // pour eviter que les cartes traversent le modele du pantographe.
        float largeurTotale = (nb - 1) * espacementCartes;
        for (int i = 0; i < nb; i++)
        {
            float x = -largeurTotale / 2f + i * espacementCartes;
            _cartesActives[i].transform.localPosition = new Vector3(x, 0f, 0f);
            _cartesActives[i].transform.localRotation = Quaternion.identity;
            _cartesActives[i].Afficher(result.Bandes[i]);
        }
    }
}