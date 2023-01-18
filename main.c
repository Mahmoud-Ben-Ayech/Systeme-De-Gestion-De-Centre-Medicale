#include<stdio.h>
#include<conio.h>
#include<string.h>
#include"mabib.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{   //definition des variables du programme principale
    char log[]={'m','o','h','a','m','e','d','\0'};
    char  mdp[]={'m','o','h','a','m','e','d','\0'};
    char validation [10],ch1[20],ch2[20],ch3[20],ch4[20],ch5[20],ch6[20];
    float* reel;
    DATE da;
    PHARMACIEN ph;
    PHARMACIEN* sp,p;
    SEMAINE semaine;
    GESTIONPHARMACIEN gestion;
    DOCTEUR* tab1;
    DOCTEUR d;
    STOKAGE* tab;
    STOKAGE s;
    MEDICAMENT med;
    int n,nb,nd,nf,nv,ch,xy;
    float h,x,y;
    PATIENT* t;
    PATIENT pa;
    PHARMACIEN* tab2;
    VACCINATION v;
    GESTIONPHARMACIEN* g;
    VACCINATION* tab3;
    FILE* fp;
    int test=0;

    printf("Veuiller choisir  : \n 1/si vous avez un compte \n 2/creer un compte  \n ");
    scanf("%d",&xy);
    switch(xy){
        case 1 :
                    while (1){
                    printf ("\n ***** connexion **** \n NB: dans notre cas le mot 'mohamed' est a la fois login et mot de passe  \n   ");
                    printf("donner votre login  \n ");
                    scanf("%s",&ch5);
                   printf("donner votre mot de passe   \n ");
                   scanf("%s",&ch6);
                   if ( (strcmp(log,ch5)==0) && (strcmp(mdp,ch6)==0 )) { printf (" \n Felicitations vous avez connecter  avec succes \n ");
                                                                         break;}
                   else printf (" \n verifier votre informations saisie !! \n ");
                   }
                  break ;

        case 2 :

                printf("donner votre nom \n");
                scanf("%s",&ch1);
                printf("donner votre prenom \n ");
                scanf("%s",&ch2);
                printf("saisir votre login  \n ");
                scanf("%s",&ch3);
                printf("saisir votre mot de passe   \n ");
                scanf("%s",&ch4);
            while (1){
                printf ("\n ***** connexion **** \n ");
                printf("donner votre login  \n ");
                scanf("%s",&ch5);
                printf("donner votre mot de passe   \n ");
                scanf("%s",&ch6);
                if ( (strcmp(ch3,ch5)==0) && (strcmp(ch4,ch6)==0 )) { printf (" \n Felicitations vous avez connecter  avec succes \n ");
                                                                       break;}
                else printf (" \n verifier votre informations saisie !! \n ");

            }
                break;
         default : printf("\n choix invalide !!");
    }

    while(1){
            system("cls");
    if (test==6) break;
    printf("\n ******* Application de Gestion du Cabinet Medical ****** \n \n  ");
    printf("veuiller choisir une choix a faire  \n ");
    printf("\n 1/ Gestion des patients  \n 2/Gestion des Medicaments \n 3/Gestion des Docteurs \n 4/Gesion des pharmaciens \n 5/Gestion des Vaccins \n 6/Quitter \n ");
    scanf("%d",&ch);
    switch(ch){
    case 1 : pa=ajout_patient();                 //appel au fonction d'ajout d'un patient
                 affiche(pa);                        //appel au ft d'affichage d'un patient

                 printf("\n  *** remplissage de tableaux des Patients *** \n ");
                 printf(" donner le nbre des patients   ");
                 scanf("%d",&n);
                 t=remplir(n);                             //remplissage du tableau des patients
                 affichetab(t,n);                         //affichage des patients
                 printf("\n  *** suppression  de tableaux des Patients *** \n ");

                 printf("donner les informations de patient a supprimer : ");
                 pa=ajout_patient();
                 supprimer(t,&n,pa);      //appel au fonction du suppression d'un patient
                 printf("\n ***********************");
                 printf("\n donner une date sous forme 'JJ MM AAAA' pour avoir les patients dans cette date  :  ");
                 scanf("%d%d%d",&da.jour,&da.mois,&da.annee);
                 affichage_patients_datedonnee(t,n,da);                 //affichage des patients d'une date donnée d'ordonnance
                          break;

        case 2 :
                  printf("\n Remplissage d'un medicament \n");
                  med=saisir_medicament();                                           //remplissage d'un medicament
                  printf("**********************remplissez les medicaments en stock******************\n");
                  s=remplir_stokage_un_medicament();                                //remplisssage du stock d'un medicament
                  printf("\n le medicament en stock est :");
                  affiche_stokage_un_medicament(s);
                  printf("\n donner la taille de stockage \n");                        //taille du tableau  du stockage medicaments = nombre du medicaments
                  scanf("%d",&nb);
                  remplir_stokage(tab,nb);                                            //remplissage du tableau stockage
                  affiche_stokagetotale(tab,nb);                                    //affichage
                  printf("****************************************\n");
                  x=calcul_tva_total(tab,nb);                                           //calcul du TVA des medicaments dans le stock
                  y=calcul_prix_totale(tab,nb);                                         //calcul du prix  des medicaments dans le stock
                  printf(" \n  tva sur la totalite de stocke est :%f, et le prix de tous les medicaments est : %f  ",x,y);

                  printf("\n le prix brut des medicaments est : %f ",reel);
                           break;

        case 3 :
             printf("\n veuillez saisir  les informations de l'ordonnance du docteur \n");
             d=remplir_docteur();                                               //remplissage des informations  visite_docteur
             affiche_docteur(d);                                               //affichage du visite docteur(ordonnance)

             printf("\n donner le nbre de docteurs  ");
             scanf("%d",&nd);                                                     //nombre d'elements du tableau d'ordonnances
             tab1= remplir_tab_docteur( nd);                                     //remplissage
             affiche_tab_docteur(tab1,nd);                                     //affichage
                 break;

        case 4 :
             printf("\n Veuiller saisir  les informations  d'un pharmacien   ");
             ph=remplir_pharmacien();                                            //remplissage des informations d'un pharmacien
             affiche_pharmacien(ph);                                             //affichage des info d'un pharmacien

             printf("\n donner le nbre de pharmacien   ");
             scanf("%d",&nf);
             tab2=remplir_tab_pharmacien(nf);                                      //remplissage de tableaux des  pharmaciens
             affiche_tab_pharmacien(tab2,nf );                                       //affichage
             printf("\n *******************************\n");
             stockage_des_pharmaciens(n);                                          //stocker les pharmaciens dans un fichier
             printf("\n voulez vous changer l'horraire d un pharmacien \n Oui/Non   ");
             scanf("%s",&validation);
             if (validation=="Oui")
             g=remplissage_horraire(sp);                                 //remplissage du tableau des horraires de pharmaciens

             printf("\n donner une  date sous la forme 'JJ MM AAAA' pour avoir les patients dans cette date  :    ");
             scanf("%d%d%d",&da.jour,&da.mois,&da.annee);                       //donner les info des patients ayant une ordonnance du date donné
             affichage_patients_datedonnee(t,n,da);                            //affichage de ces patients
                printf("**************************\n");
               printf("\n voulez vous afficher le stockage du gestion des pharmaciens: Oui\Non  ");
               scanf("%s",&validation);
              if (validation=="Oui")
                        affichegestion(sp,g,n);                             //  affichage de stockage du gestion des pharmaciens
              printf("\n donner une date précis  : \n ");
              scanf("%s",&semaine);
              printf("\n affichage du gestion des pharmaciens trvaillent le jour donné   ");
              date_donnee(g,n,semaine);
              printf("\n voulez vous les pharmaciens qui trvaillent le jour donnée ? Oui\Non   ");
              scanf("%s",&validation);
              if (validation=="Oui")
              printf("\n donner une date : \n");
              scanf("%s",&semaine);
              tab2=stockage_pharmaciens_jour(sp,g,n,semaine);
                break;

        case 5:
             printf("\n donner l'information d'une vaccination faite au pharmacie \n");
             v=remplir_un_vaccin();                                                    //remplissage des info d'une vaccination faite
             affiche_vaccin(v);                                                        //affichage des vaccinations
             printf("\n donner le nbre de personne vaccinee \n");
             scanf("%d",&nv);
             printf("\n tableau des vaccins deja faites \n  ");
             tab3=gestion_vaccin(nv);
             supprimer_vaccin(tab3,nv);                                         //suppression d'un vaccin donné

                  break;

         case 6 :  test=ch; break;
         default : printf ("choix invalide !!");break;
    }
    }

    return(0);

}

