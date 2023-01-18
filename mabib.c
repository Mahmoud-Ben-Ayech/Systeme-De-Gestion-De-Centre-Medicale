
#include<stdio.h>
#include"mabib.h"

PATIENT ajout_patient()    //fonction remplissage patient
{
    PATIENT p;
    printf("\n donner le numr tlf ,  maladie , nbre de medicament : \n");
    scanf("%d%s%d",&p.numero_telephone,&p.maladie,&p.nbre_medicament);
    printf("donner la date de naissance  'JJ MM AAAA' :  ")   ;
    scanf("%d%d%d",&p.datenaiss.jour,&p.datenaiss.mois,&p.datenaiss.annee);
     printf("donner la date de visite  'JJ MM AAAA' : ")   ;
    scanf("%d%d%d",&p.jour_visite.jour,&p.jour_visite.mois,&p.jour_visite.annee);
   printf("\n donner le numr cin : ");
    scanf("%d",&p.numcin);
    *(p.nom_medicaments)=(char*)malloc(p.nbre_medicament*sizeof(char));
    if(!p.nom_medicaments) exit(-1);
    for(int i=0;i<p.nbre_medicament;i++)
    {
        printf(" donner la %d eme medicament : ",i+1);
        scanf("%s",p.nom_medicaments+i);
    }
    return(p);
}

void affiche(PATIENT p)    //fonction affichage d'un patient deja rempli
{
    printf("\n le numr tlf : %d , date naiss : %d/%d/%d , maladie : %s   , nbre de medicament : %d  , date visite : %d/%d/%d , num cin : %d   \n ",p.numero_telephone,p.datenaiss.jour,p.datenaiss.mois,p.datenaiss.annee,p.maladie,p.nbre_medicament,p.jour_visite.jour,p.jour_visite.mois,p.jour_visite.annee,p.numcin);
    printf("\n les medicaments sont : ");
    for(int i=0;i<p.nbre_medicament;i++){
            printf("\n %c",*(p.nom_medicaments+i));
    }
}

PATIENT* remplir(int n)              //fonction remplissage d'un tableau de patients
{
    int i;
    PATIENT p;
    PATIENT* t;
    t=(PATIENT*)malloc(n*sizeof(PATIENT));
    if (!t) exit(-1);
    for (i=0;i<n;i++)
    {
        printf("\n donner les informations de %d eme patient : ",i+1 );
        p=ajout_patient();                                     //bien evidament on fait appel au remplissage d'un seul patient
        *(t+i)=p;
    }
    return(t);
}

void affichetab(PATIENT* t,int n)                      //fonction affichage du tableau des patients
{
    for (int j=0;j<n;j++)
        {
            affiche(*(t+j));
            printf("\n ******* \n ");
        }
}


void supprimer (PATIENT*  t,int* n,PATIENT p)            //fonction du suppression d'un patient du tableau remplie
{
    for (int i=0;i<*n;i++)
    {
        if ((t+i)->numcin==p.numcin)
        {
            int j=i;
            while (j<*n-1)
            {
                *(t+j)=(*(t+j+1));
                j++;
            }
        }
    }
    *n--;
}


MEDICAMENT saisir_medicament()            //fonction remplissage d'un medicament en utilisant sa strucutre
{
   MEDICAMENT med;
   printf("donner le prix,le nom , l' ordonnance de medicament , tva , la masse   \n ");
   scanf("%f%s%s%f%f",&med.prix,&med.nom_medicament,&med.ordonnance,&med.TVA,&med.masse);
   printf("donner la date de validite sous forme 'JJ MM AAAA' ");
   scanf("%d%d%d",&med.date_validite.jour,&med.date_validite.mois,&med.date_validite.annee);
   printf("donner la date de livraison  sous forme 'JJ MM AAAA' ");
   scanf("%d%d%d", &med.date_livraison.jour,&med.date_livraison.mois,&med.date_livraison.annee);

         return(med);
}


STOKAGE remplir_stokage_un_medicament( )            //fonction qui rempli  le stockage d'un medicaments
{
    STOKAGE s;
    printf("donner nom de medicament  ,numero existe   ,son type   ,pays d importation et le code d importation  \n  ");
    scanf("%s%d%s%s%d",&(s.nom_medicament),&(s.numero_exsiste),&(s.type_medicament),&(s.pays_d_importation),&(s.code_importation));
    return(s);
}


STOKAGE* remplir_medicaments(int n)    //fonction qui remplie de  les medicaments dans un tableau
{
    STOKAGE* p;
    p=(STOKAGE*)malloc(n*sizeof(STOKAGE));
    if (!p) exit(-1);
    for(int i=0;i<n;i++)
      *(p+i)= remplir_stokage_un_medicament();
    return(p);
}

void affiche_stokage_un_medicament(STOKAGE s)   //fonction affichage du  stockage d un medicament
{
    printf(" nom de medicament : %s ,numero existe : %d, son type : %s, pays d importation : %s et le code d importation  : %d    ",
           s.nom_medicament,s.numero_exsiste,s.type_medicament,s.pays_d_importation,s.code_importation);
}

void  remplir_stokage(STOKAGE* tab, int nb )    //fonction remplissage du stockage de tous les medicaments
{
    tab=(STOKAGE*)malloc(nb*sizeof(STOKAGE));

    for(int i=0;i<nb;i++)
    {
        printf("\n les informations de %d eme stockage : ",i+1);
        *(tab+i)=remplir_stokage_un_medicament();
    }
}

void affiche_stokagetotale(STOKAGE* tab,int nb )    //fonction affichage de tous les medicaments en stock
{
    for(int i=0;i<nb ;i++)
    {
        printf("\n affichage de %d eme stockage : ",i+1);
        affiche_stokage_un_medicament(*(tab+i));
    }
}

DOCTEUR remplir_docteur()                     //fonction de remplissage des information du carte visite de la docteur donné par le client au pharmacien
{
    DOCTEUR d;
    printf("\n donner le nom , le prenom , specialitee , nom laboo  : ");
    scanf("%s%s%s%s",&d.nom,d.prenom,&d.specialite,&d.nom_labo);
    printf("\n donner la date de visite  sous forme  'JJ MM AAAA' ");
    scanf("%d%d%d",&d.date_visite.jour,&d.date_visite.mois,&d.date_visite.annee);
    return(d);
}

void affiche_docteur(DOCTEUR d)      //fonction affichage des information de la visite du docteur
{
    printf("\n le nom : %s , le prenom :%s , date visite : %d/%d/%d , specialitee :%s,nom laboo : %s   ",d.nom,d.prenom,d.date_visite.jour,d.date_visite.mois,d.date_visite.annee,d.specialite,d.nom_labo);
}

DOCTEUR* remplir_tab_docteur(int nd)     //fonction remplissage de tous les  visites des docteurs
{
    DOCTEUR* t;
    t=(DOCTEUR*)malloc(nd*sizeof(DOCTEUR));
    if(!t) exit(-1);
    for(int i=0;i<nd ;i++)
    {
          printf("\n les coordonnee de %d eme docteur :  ",i+1);
          *(t+i)=remplir_docteur();
    }
    return(t);
}
void affiche_tab_docteur(DOCTEUR* t,int nd)   //fonction affichage de tous les visites docteurs
{
  for (int i=0;i<nd;i++)
  {
      printf("\n les inf de %d eme docteur : ",i+1);
      affiche_docteur(*(t+i));
  }
}

GESTIONPHARMACIEN remplir_calenderier(float* h)     //rempilssage du calendrier du travail du pharmacien
{
    GESTIONPHARMACIEN g;
    printf ("\n donner le nbre des heures :  ");
    scanf("%f",h);
    g.horraire_travail=(char*)malloc(7*sizeof(char));
    if(!g.horraire_travail) exit(-1);
    for(int i=0;i<7;i++)
    {
        printf("\n donner l'intervalle d'heures de travail pour la %d eme jour : ",i+1);
        scanf("%s",g.horraire_travail+i);
    }
    return g;
}

void affiche_calenderier(GESTIONPHARMACIEN g,float h)   //fonction affichage du calendrier du travail du pharmacien donné par semaine
{
    printf ("\n le nbre des heures :",h);
    g.horraire_travail=(SEMAINE*)malloc(7*sizeof(SEMAINE));
    for(int i=0;i<7;i++)
    {
        printf("\n l'intervalle d'heures de travail pour la %d eme jour : ",i+1);
        printf("%s",*(g.horraire_travail+i));
    }

}

PHARMACIEN remplir_pharmacien()   //fonction remplissage d'un pharmacien
{
   PHARMACIEN ph;
   printf("\n donner l'age , le diplome , le nbre d'anne  experience , le sexe , la nationnalite : ");
   scanf("%d%s%d%s%s",&ph.age,&ph.diplome,&ph.annee_exepriences,&ph.sexe,&ph.nationalite);
   return ph;
}

void affiche_pharmacien(PHARMACIEN ph)
{
    printf("\n l'age : %d , le diplome : %s ,le nbre d'anne  experience : %d , le sexe : %s , la nationnalite : %s  ",ph.age,ph.diplome,ph.annee_exepriences,ph.sexe,ph.nationalite);
}


PHARMACIEN* remplir_tab_pharmacien(int nf )  //remplissage d'un tableau de pharmaciens
{
  PHARMACIEN* t;
  t=(PHARMACIEN*)malloc(nf*sizeof(PHARMACIEN));
  for (int i=0;i<nf;i++)
  {
      printf("\n remplissage des coordonnee de %d eme pharmacien :  ",i+1);
      *(t+i)=remplir_pharmacien();
  }
  return t ;
}


void affiche_tab_pharmacien(PHARMACIEN* t,int nf )  //fonction affichage des pharmaciens
{
    for (int i=0;i<nf;i++)
  {
      printf("\n les coordonnee de %d eme pharmacien : ",i+1);
      affiche_pharmacien(*(t+i));
  }
}


VACCINATION remplir_un_vaccin()  //fonction remplissage du vaccin faite dans le pharmacie
{
    VACCINATION v;
    printf("\n donner le pharmacien , le nom de vaccin , le client , num dose , num inscription : \n ");
    scanf(" %s%s%s%d%d",&v.Pharmacien,&v.nom_vaccin,&v.client,&v.num_dose,&v.num_inscription);
    return v;
}


void affiche_vaccin(VACCINATION v) //fonction affichage du vaccin faite dans le pharmacie
{
    printf("\n le pharmacien  : %s , le nom de vaccin : %s , le client : %s , num dose : %d , num inscription : %d " ,v.Pharmacien,v.nom_vaccin,v.client,v.num_dose,v.num_inscription);
}

VACCINATION* gestion_vaccin(int nv) //fonction du tableau des vaccins faites
{
   VACCINATION* t;
   t=(VACCINATION *)malloc(nv*sizeof(VACCINATION));
   printf("\n *************remplissage **************\n ");
   for(int i=0;i<nv;i++)
   {
       printf("\n donner les inf de %d eme vaccin :  ",i+1);
       *(t+i)=remplir_un_vaccin();
   }
   printf("\n ******************************affichage *******************************\n ");
   for(int i=0;i<nv;i++)
   {
       printf("\n les inf de %d eme vaccin : ",i+1);
       affiche_vaccin(*(t+i));
   }
}

void supprimer_vaccin(VACCINATION* a,int n)   //fonction du suppression dans le tableau  d'un vaccin   faite
{
    VACCINATION* v;
    printf("\n \n saisir les information de vaccin a supprimer : \n ");
     *v=remplir_un_vaccin();
     for (int i=0;i<n;i++)
    {
        if (v->num_inscription==a->num_inscription)
        {   ((a+i)->num_inscription=(v->num_inscription));
            int j=i;
            while (j<n-1)
            {
                *(a+j)=(*(a+j+1));
                j++;
            }
        }
    }
    n--;
}

void supprimer_visite_docteur(DOCTEUR* a,int n)  //fonction suppression d'une visite du docteur
{ DOCTEUR* b;
  printf("|n donner le nom , prenom du docteur ainsi que la date de visite : \n ");
  scanf("%s%s%d%d%d",&(b->nom),&(b->prenom),&(b->date_visite.jour),&(b->date_visite.mois),&(b->date_visite.annee));
  for (int i=0;i<n;i++)
    {
        if (((a+i)->nom==b->nom)&&((a+i)->prenom)==(b->prenom)&&(((a+i)->date_visite.jour)==(b->date_visite.jour))&&(((a+i)->date_visite.mois)==(b->date_visite.mois))&&((a+i)->date_visite.annee)==(b->date_visite.annee))
        { for (int c = i-1; c <n -1; c++)
         *(a+c) = *(a+c+1);
        }
    }
}

void afficher_fichier(FILE* fp)  //fonction d'utulisation d'un fichier sera appellé aprés
{ char x;
  rewind(fp);
  while(1)
  {  if(x!=('/0'))
      fread(&x,sizeof(char),1,fp);
     else
        printf("/t");
     if (feof(fp)) break;
     printf("%c",x);
  }
}
void ouverture(FILE* fp)  //une fonction classique d'ouverture d'un fichier
{
    char nom[20];
    printf("\n saisir le nom du fichier : ");
    scanf("%s",nom);
    fp=open(nom,"w+");
    if (!fp) exit(-1);
}
void remplir_fichier(FILE* fp)  //fonction remplissage d'un fichier
{
    char x;
    do
     {
        scanf("%c",&x);
        fwrite(&x,sizeof(char),1,fp);
     }
    while (x!='/0');
}
void enregistrement_archive(PATIENT* p,int n)  //fonction stockage des patients dans un fichier
{ int i;
  FILE* fp;
  ouverture(fp);
  for(i=0;i<n;i++)
   {
    char x;
    do
     {
        scanf("%c",&x);
        fwrite(&x,sizeof(char),1,fp);
     }
    while (x!='/0');
   }
}
void affichage_patients_datedonnee(PATIENT* t,int n,DATE da)  //fonction affichage du patient pour une date du visite docteur donné
{
    int k=0;
  for(int i=0;i<n;i++)
  {
      if (((t+i)->jour_visite.jour==da.jour)&&((t+i)->jour_visite.mois==da.mois)&&((t+i)->jour_visite.annee==da.annee)){
        affiche(*(t+i));
        k++;
      }
  }
  if (k==0)  printf("pas de patient dans cette date !!");
}

float calcul_tva_total(STOKAGE* t,int n) //fonction qui calcul TVA total dans le stockage
{
   float s ;
   s=0;
   for(int i=0;i<n;i++)
   {
       s+=(t+i)->TVA;
   }
   return(s);
}

float calcul_prix_totale(STOKAGE* t,int n ) //fonction calcul du prix total des medicaments dans le stockage
{
    float s ;
   for(int i=0;i<n;i++)
   {
       s+=(t+i)->prix;
   }
   return(s);
}
float calcul_prix_brut_medicaments(STOKAGE* t, int n) //fonction calcul du prix initial du medicaments -sans TVA- dans le stock
{
    return(calcul_prix_totale(t,n)-calcul_tva_total( t, n));
}

void affichage_patients_docteurdonnee(PATIENT* t,int n,DOCTEUR* tab1,int nd)  //fonction affichage des patients du meme docteur
{
    for(int i=0;i<nd;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(((tab1+i)->nom==(t+j)->nom_docteur)&&((tab1+i)->prenom==(t+j)->prenom_docteur))
                printf("\n %s est un patient de %s  ",(t+j)->nom_patient,(tab1+i)->nom);
        }
    }
}
void stockage_des_pharmaciens(int n)      //stockage des pharmaciens dans un fichier
{ FILE* fp;
  PHARMACIEN* p;
  ouverture(fp);
  p=remplir_tab_pharmacien(n);
  for (int i=0;i<n;i++)
    remplir_fichier(fp);
}
GESTIONPHARMACIEN* remplissage_horraire(PHARMACIEN* p) //remplissage du tableau du gestion pharmaciens selon nombres d'heures
{   GESTIONPHARMACIEN* g;
    int i,j;
    for(i=0;i<(sizeof(p)/sizeof(PHARMACIEN));i++)
      printf("\n donner les horraires du travail totales et les heures chaque jours du pharmacien ' %s '  ", (p+i)->nom);
      scanf("%d",& (g+i)->nombre_heures);
      for(j=0;j<7;j++)
        scanf("%d",&(((g+i)+j)->horraire_travail));
    return(g);
}
void affichegestion(PHARMACIEN* p,GESTIONPHARMACIEN* g,int n)      //affichage de tableau des gestion des pharmaciens : horraire chaque jour et horraire totale
{
    int i;
    for(int j=0;j<n;j++)
    {
        printf("\n %s %d \t ",(p+j)->nom,(g+j)->nombre_heures);
        for(i=0;i<7;i++)
        {
            printf("  %d   ",((g+j)+i)->horraire_travail);
        }
    }
}
void date_donnee(GESTIONPHARMACIEN* s,int n,SEMAINE t)    //fonction qui affiche les noms du pharmaciens qui travaillent le jour J donné
{
    int i;
    for(i=0;i<n;i++)
        if ((t.jour)=="lundi")
         if ((s->horraire_travail)!=0)
            printf("%s",(s+i)->nom);

        else if((t.jour)=="mardi")
         if ((s+1)->horraire_travail!=0)
          printf("%s",(s+i)->nom);

        else if ((t.jour)=="mercredi")
          if ((s+2)->horraire_travail!=0)
          printf("%s",(s+2)->nom);
        else if ((t.jour)==("jeudi"))
         if ((s+3)->horraire_travail!=0)
         printf("%s",(s+3)->nom);
        else if ((t.jour)==("vendredi"))
        if ((s+4)->horraire_travail!=0)
          printf("%s",(s+i)->nom);
        else if ((t.jour)==("samedi"))
         if ((s+5)->horraire_travail!=0)
           printf("%s",(s+5)->nom);
        else if ((t.jour)==("dimanche"))
         if ((s+6)->horraire_travail!=0)
            printf("%s",(s+i)->nom);
}
PHARMACIEN* stockage_pharmaciens_jour(PHARMACIEN* p,GESTIONPHARMACIEN* g, int n, SEMAINE t) //fonction stockage des informations du pharmacien qui travaille un jour donné
{
    int i=0;
    int c=0;
    int j=0;
    _Bool a;
    PHARMACIEN* tab;
    for(i=0;i<n;i++)
         if((g+i)->nom==t.jour)
         {    c++;
              a=(((p+i)->nom)!=(p+c)->nom);
              while((c<n)&&a)
                j++;
                  *(tab+j)=*(p+i);
         }

    return(tab);
}

