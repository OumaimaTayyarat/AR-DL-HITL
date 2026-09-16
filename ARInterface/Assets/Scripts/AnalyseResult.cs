using System.Collections.Generic;
using Newtonsoft.Json;


[System.Serializable]
public class AnalyseResult
{
    [JsonProperty("bande_detectee")]
    public bool BandeDetectee;

    [JsonProperty("bandes")]
    public List<BandeResultat> Bandes = new List<BandeResultat>();

    [JsonProperty("image_annotee")]
    public string ImageAnneteeBase64;
}

[System.Serializable]
public class BandeResultat
{

    [JsonProperty("id")]
    public string Id;   // "gauche" / "droite" — doit matcher le champ "id" ajoute cote serveur
    [JsonProperty("box")]
    public float[] Box; // [x1, y1, x2, y2]

    [JsonProperty("score")]
    public float Score;

    [JsonProperty("orientation")]
    public string Orientation;

    [JsonProperty("fissure_pct")]
    public float FissurePct;

    [JsonProperty("fissure_defaut")]
    public bool FissureDefaut;

    // AJOUTS pour le point 3 (mm au lieu de %)
    [JsonProperty("fissure_longueur_mm")]
    public float FissureLongueurMm;

    [JsonProperty("fissure_largeur_mm")]
    public float FissureLargeurMm;

    [JsonProperty("ecaillage_pct")]
    public float EcaillagePct;

    [JsonProperty("ecaillage_defaut")]
    public bool EcaillageDefaut;

    [JsonProperty("sections")]
    public List<Section> Sections = new List<Section>();

    [JsonProperty("min_thickness_mm")]
    public float MinThicknessMm;

    [JsonProperty("epaisseur_defaut")]
    public bool EpaisseurDefaut;
    

    public bool AuMoinsUnDefaut => FissureDefaut || EcaillageDefaut || EpaisseurDefaut;
}

[System.Serializable]
public class Section
{
    [JsonProperty("id")]
    public string Id;

    [JsonProperty("thickness_mm")]
    public float ThicknessMm;

    [JsonProperty("defaut")]
    public bool Defaut;
}