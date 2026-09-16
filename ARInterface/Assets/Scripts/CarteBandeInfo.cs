using System.Text;
using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Networking;
using TMPro;
using Newtonsoft.Json;

public class CarteBandeInfo : MonoBehaviour
{
    [Header("UI")]
    [SerializeField] private TextMeshProUGUI texteInfo;
    [SerializeField] private Button boutonOk;
    [SerializeField] private Button boutonPasBon;
    [SerializeField] private GameObject panelCommentaire;
    [SerializeField] private TMP_InputField champCommentaire;
    [SerializeField] private Button boutonValiderCommentaire;
    [SerializeField] private TextMeshProUGUI texteStatutEnvoi;

    [Header("Couleurs")]
    [SerializeField] private Color couleurOk = new Color(0.3f, 1f, 0.3f);
    [SerializeField] private Color couleurDefaut = new Color(1f, 0.3f, 0.3f);

    [Header("Serveur")]
    [SerializeField] private string urlServeurFeedback = "http://<ton-ip>:8000/feedback";

    private BandeResultat _bandeCourante;
    private readonly StringBuilder _sb = new StringBuilder();

    void Awake()
    {
        if (boutonOk != null) boutonOk.onClick.AddListener(() => EnvoyerFeedback(true, ""));
        if (boutonPasBon != null) boutonPasBon.onClick.AddListener(() => panelCommentaire?.SetActive(true));
        if (boutonValiderCommentaire != null)
            boutonValiderCommentaire.onClick.AddListener(() =>
            {
                string commentaire = champCommentaire != null ? champCommentaire.text : "";
                EnvoyerFeedback(false, commentaire);
            });

        panelCommentaire?.SetActive(false);
    }

    public void Afficher(BandeResultat bande)
    {
        _bandeCourante = bande;
        _sb.Clear();

        string nomBande = bande.Id == "gauche" ? "Bande Gauche" : "Bande Droite";
        _sb.AppendLine($"<b>{nomBande}</b>");

        string couleurFissureHex = ColorToHex(bande.FissureDefaut ? couleurDefaut : couleurOk);
        _sb.AppendLine($"Fissure : <color=#{couleurFissureHex}>" +
                        $"L={bande.FissureLongueurMm:F1}mm  E={bande.FissureLargeurMm:F2}mm" +
                        $"{(bande.FissureDefaut ? " - DEFAUT" : " - OK")}</color>");

        string couleurEcaillageHex = ColorToHex(bande.EcaillageDefaut ? couleurDefaut : couleurOk);
        _sb.AppendLine($"Ecaillage : <color=#{couleurEcaillageHex}>{bande.EcaillagePct:F1}%" +
                        $"{(bande.EcaillageDefaut ? " - DEFAUT" : " - OK")}</color>");

        if (bande.Sections != null && bande.Sections.Count > 0)
        {
            string couleurEpaisseurHex = ColorToHex(bande.EpaisseurDefaut ? couleurDefaut : couleurOk);
            _sb.AppendLine($"Epaisseur min : <color=#{couleurEpaisseurHex}>{bande.MinThicknessMm:F2} mm" +
                            $"{(bande.EpaisseurDefaut ? " - DEFAUT" : " - OK")}</color>");
        }
        else
        {
            _sb.AppendLine("Epaisseur : non mesuree (vue face)");
        }

        if (texteInfo != null) texteInfo.text = _sb.ToString();

        panelCommentaire?.SetActive(false);
        if (champCommentaire != null) champCommentaire.text = "";
        if (texteStatutEnvoi != null) texteStatutEnvoi.text = "";
    }

    private void EnvoyerFeedback(bool valide, string commentaire)
    {
        if (_bandeCourante == null) return;

        var data = new FeedbackData
        {
            bande_id = _bandeCourante.Id,
            valide = valide,
            commentaire = commentaire,
            fissure_pct = _bandeCourante.FissurePct,
            fissure_defaut = _bandeCourante.FissureDefaut,
            fissure_longueur_mm = _bandeCourante.FissureLongueurMm,
            fissure_largeur_mm = _bandeCourante.FissureLargeurMm,
            ecaillage_pct = _bandeCourante.EcaillagePct,
            ecaillage_defaut = _bandeCourante.EcaillageDefaut,
            min_thickness_mm = _bandeCourante.MinThicknessMm,
            epaisseur_defaut = _bandeCourante.EpaisseurDefaut,
            orientation = _bandeCourante.Id
        };

        StartCoroutine(PostFeedback(data));
        panelCommentaire?.SetActive(false);
    }

    private IEnumerator PostFeedback(FeedbackData data)
    {
        string json = JsonConvert.SerializeObject(data);
        var req = new UnityWebRequest(urlServeurFeedback, "POST");
        byte[] bodyRaw = Encoding.UTF8.GetBytes(json);
        req.uploadHandler = new UploadHandlerRaw(bodyRaw);
        req.downloadHandler = new DownloadHandlerBuffer();
        req.SetRequestHeader("Content-Type", "application/json");

        if (texteStatutEnvoi != null) texteStatutEnvoi.text = "Envoi...";
        yield return req.SendWebRequest();

        if (texteStatutEnvoi != null)
        {
            texteStatutEnvoi.text = req.result == UnityWebRequest.Result.Success
                ? "Feedback envoye"
                : $"Erreur envoi: {req.error}";
        }
    }

    private static string ColorToHex(Color c) => ColorUtility.ToHtmlStringRGB(c);
}

[System.Serializable]
public class FeedbackData
{
    public string bande_id;
    public bool valide;
    public string commentaire;
    public float fissure_pct;
    public bool fissure_defaut;
    public float fissure_longueur_mm;
    public float fissure_largeur_mm;
    public float ecaillage_pct;
    public bool ecaillage_defaut;
    public float min_thickness_mm;
    public bool epaisseur_defaut;
    public string orientation;
}