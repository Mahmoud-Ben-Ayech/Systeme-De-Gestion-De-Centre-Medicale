struct DATE
{
int jour ;                       //structure date classique
int mois;
int annee;
};
typedef struct DATE DATE;
struct patient                        //structure patient qui contient les informations des patients
{
char nom_patient[20];
long numero_telephone;
DATE datenaiss;
char maladie[20];
int nbre_medicament;
char* nom_medicaments[20];
DATE jour_visite;
char nom_docteur[20];
char prenom_docteur[20];
long numcin;
};
typedef struct patient PATIENT;
struct medicament                                  //strucutre medicament qui contient les informations d'un medicament
{
float prix;
char nom_medicament[20];
DATE date_validite;
DATE date_livraison;
char ordonnance[20];
float TVA;
float masse;
};
typedef struct medicament MEDICAMENT;

struct sotckage                                    //structure sotkcage qui contient les informations d'un medicament en stock
{
 char nom_medicament[20];
 int numero_exsiste;
 char type_medicament[20];
char pays_d_importation[20];
 int code_importation;
 float prix;
 float TVA ;
};
typedef struct sotckage STOKAGE;
struct docteur                                       //structure docteur contient les info de l'ordonnance donné par le patient
{
    char nom[20];
    char prenom[20];
    DATE date_visite;
    char specialite[20];
    char nom_labo[20];
};
typedef struct docteur DOCTEUR;
struct semaine                                 //structure utilisé pour fixé un jour de la semaine
{
    char jour[10];
};
typedef struct semaine SEMAINE;
struct gestion_pharmacien                          //strucutre utilisé pour l'horraire et le nombre d'heures par jour d'un pharmacien
{
    int nombre_heures;
    SEMAINE* horraire_travail;
    char nom[10];
};
typedef struct gestion_pharmacien GESTIONPHARMACIEN;
struct pharmacien                                   //structure contenant les info d'un pharmacien
{ int age;
  char nom [20];
  char diplome[20];
  int annee_exepriences;
  char sexe[20];
  char nationalite[20];
};
typedef struct pharmacien PHARMACIEN;
struct vaccination_coronavirus                    //structure conenant les info d'une vaccination faite au pharmacie
{
    char Pharmacien[20];
    char nom_vaccin[20];
    char client[20];
    int num_dose;
    long num_inscription;
};
typedef struct vaccination_coronavirus VACCINATION;

PATIENT ajout_patient();
void affiche(PATIENT);
PATIENT* remplir(int );
void affichetab(PATIENT*,int );
void supprimer (PATIENT* ,int* ,PATIENT);
MEDICAMENT saisir_medicament();
STOKAGE remplir_stokage_un_medicament();
void affiche_stockage_un_medicament(STOKAGE );
STOKAGE* remplir_medicaments();
void  remplir_stokage(STOKAGE*, int ) ;
void affiche_stokagetotale(STOKAGE*,int );
DOCTEUR remplir_docteur();
void affiche_docteur(DOCTEUR );
DOCTEUR* remplir_tab_docteur(int );
void affiche_tab_docteur(DOCTEUR* ,int );
GESTIONPHARMACIEN remplir_calenderier(float*);
void affiche_calenderier(GESTIONPHARMACIEN,float);
PHARMACIEN remplir_pharmacien();
void affiche_pharmacien(PHARAMCIEN );
PHARMACIEN* remplir_tab_pharmacien(int);
void affiche_tab_pharmacien(PHARMACIEN*,int);
VACCINATION remplir_un_vaccin();
void affiche_vaccin(VACCINATION);
VACCINATION* gestion_vaccin(int);
void supprimer_vaccin(VACCINATION*,int);
void supprimer_visite_docteur(DOCTEUR*, int);
void afficher_fichier(FILE*);
void ouverture(FILE*);
void remplir_fichier(FILE*);
void enregistrement_archive(PATIENT*,int);
void affichage_patients_datedonnee(PATIENT*,int,DATE);
float calcul_tva_total(STOKAGE*,int );
float calcul_prix_totale(STOKAGE*,int );
float calcul_prix_brut_medicaments(STOKAGE*,int);
void affichage_patients_docteurdonnee(PATIENT*,int,DOCTEUR*,int);
void stockage_des_pharmaciens(int);
GESTIONPHARMACIEN* remplissage_horraire(PHARMACIEN*);
void affichegestion(PHARMACIEN*,GESTIONPHARMACIEN*,int);
void date_donnee(GESTIONPHARMACIEN*,int,SEMAINE);
PHARMACIEN* stockage_pharmaciens_jour(PHARMACIEN*,GESTIONPHARMACIEN*, int, SEMAINE);
void enregistrement_stockage(STOKAGE*);
GESTIONPHARMACIEN* remplissage_horraire(PHARMACIEN*);


