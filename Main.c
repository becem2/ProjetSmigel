#include "Fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(){
    CENTRE centre[1];
    printf("\n------------------------------------");
    if (fopen("centre.bin", "rb") != NULL) {
        printf("\nLe fichier existe deja\nChargement des donnees\n");
        RemplireTableauDuFichier(centre);
    }
    else {
        printf("Le fichier n'existe pas\n");
        printf("On va le remplire \n");
        RemplirCentre(centre);
    }

    int ChoixMenu;
    do {
        printf("\n*-------------- Menu Principal -------------*\n");
        printf("1. Modification du fichier\n");
        printf("2. Traitement\n");
        printf("3. Affichage\n");
        printf("9. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &ChoixMenu);
        
        switch (ChoixMenu) {
        case 1:
            int ChoixModification;
            do {
                printf("\n*-------- Modification du Fichier --------*\n");
                printf("1. Modifier Ambulance\n");
                printf("2. Modifier Mission\n");
                printf("3. Modifier Patient\n");
                printf("4. Modifier Personnel\n");
                printf("9. Retour au menu principal\n");
                printf("Votre choix : ");
                scanf("%d", &ChoixModification);
                switch (ChoixModification) {
                    case 1:
                        int ChoixAmbulance;
                        do {
                            printf("\n*--------Modification du Ambulance-------*\n");
                            printf("1. Modifier un Ambulance\n");
                            printf("2. Ajout un Ambulance\n");
                            printf("3. Supprimer un Ambulance\n");
                            printf("9. Retour au menu modification\n");
                            printf("Votre choix : ");
                            scanf("%d", &ChoixAmbulance);
                            switch (ChoixAmbulance) {
                                case 1:
                                    printf("\n*----------Modifier un Ambulance------*\n");
                                    ModifierAmbulance(centre);
                                    break;
                                case 2:
                                    printf("\n*----------Ajout un Ambulance------*\n");
                                    AjoutAmbulance(centre);
                                    break;
                                case 3:
                                    printf("\n*----------supprimer un Ambulance------*\n");
                                    SupprimerAmbulance(centre);
                                    break;
                                default:
                                    printf("Tapez un Nombre Valide!!");
                                    break;
                            }
                        } while (ChoixAmbulance != 9);
                        break;
                    case 2:
                        int ChoixMission;
                        do {
                            printf("\n*--------Modification du Mission-------*\n");
                            printf("1. Modifier un Mission\n");
                            printf("2. Ajout un Mission\n");
                            printf("3. Supprimer un Mission\n");
                            printf("9. Retour au menu modification\n");
                            printf("Votre choix : ");
                            scanf("%d", &ChoixMission);
                            switch (ChoixMission) {
                                case 1:
                                    printf("\n*----------Modification du Mission------*\n");
                                    ModifierMission(centre);
                                    break;
                                case 2:
                                    printf("\n*----------Ajout un Mission------*\n");
                                    AjoutMission(centre);
                                    break;
                                case 3:
                                    printf("\n*----------Suppression du Mission------*\n");
                                    SupprimerMission(centre);
                                    break;
                                default:
                                    printf("Tapez un Nombre Valide!!");
                                    break;
                            }
                        } while (ChoixMission != 9);
                        break;
                    case 3:
                        int ChoixPatient;
                        do {
                            printf("\n*--------Modification du Patient-------*\n");
                            printf("1. Modifier un Patient\n");
                            printf("2. Ajout un Patient\n");
                            printf("3. Supprimer un Patient\n");
                            printf("9. Retour au menu Patient\n");
                            printf("Votre choix : ");
                            scanf("%d", &ChoixPatient);
                            switch (ChoixPatient) {
                                case 1:
                                    printf("\n*----------Modification du Patient------*\n");
                                    ModifierPatient(centre);
                                    break;
                                default:
                                    printf("Tapez un Nombre Valide!!");
                                    break;
                            }
                        } while (ChoixPatient != 9);
                        break;
                    case 4:
                        int ChoixPersonnel;
                        do {
                            printf("\n*--------Modification du Personnel-------*\n");
                            printf("1. Modifier un Personnel\n");
                            printf("2. Ajout un Personnel\n");
                            printf("3. Supprimer un Personnel\n");
                            printf("9. Retour au menu Personnel\n");
                            printf("Votre choix : ");
                            scanf("%d", &ChoixPersonnel);
                            switch (ChoixPersonnel) {
                                case 1:
                                    printf("\n*----------Modification du Personnel------*\n");
                                    ModifierPersonel(centre);
                                    break;
                                case 2:
                                    printf("\n*----------Ajout du Personnel------*\n");
                                    AjoutPersonel(centre);
                                    break;
                                case 3:
                                    printf("\n*----------Suppression du Personnel------*\n");
                                    SupprimerPersonel(centre);
                                    break;
                                default:
                                    break;
                            }
                        } while (ChoixPersonnel != 9);
                        break;
                    default:
                        printf("Tapez un Nombre Valide!!");
                        break;
                }
            } while (ChoixModification != 9);
            break;
        case 2:
            int ChoixTraitement;
            do {
                printf("\n*---------------Traitement-----------------*\n");
                printf("1. Patient le plus jeune\n");
                printf("2. Mission la plus frequente\n");
                printf("3. Ambulance ayant effectuee plus de mission\n");
                printf("4. Ville plus frequente\n");
                printf("5. Maladie specifier\n");
                printf("Tapez votre choix : ");
                scanf("%d",&ChoixTraitement);
                switch (ChoixTraitement)
                {
                case 1:
                    PatientPlusJeune(centre);
                    break;
                case 2:
                    break;
                case 3:
                    AmbulancePlusDeMissions(centre);
                    break;
                case 4:
                    break;
                case 5:
                    NombrePatientsAvecMaladie(centre);
                    break;
                default:
                    break;
                }
            } while(ChoixTraitement !=9);
            break;
        case 3:
            int ChoixAffichage;
            do {
                printf("\n*--------Affichage-------*\n");
                printf("1. Affichage Ambulance\n");
                printf("2. Affichage Mission\n");
                printf("3. Affichage Personnel\n");
                printf("4. Affichage Paiement\n");
                printf("9. Retour au menu\n");
                printf("Votre choix : ");
                scanf("%d", &ChoixAffichage);
                switch (ChoixAffichage) {
                    case 1:
                        AfficherAmbulance(centre);
                        break;
                    case 2:
                        AfficherMission(centre);
                        break;
                    case 3:
                        AfficherPersonel(centre);
                        break;
                    case 4:
                        AfficherPatient(centre);
                        break;
                    default:
                        printf("Tapez un Nombre Valide!!");
                        break;
                }
            } while (ChoixAffichage != 9);
            break;
        case 4:
            RemplireFichierduTableau(centre);
            LibereMemoire(centre);
            RemplireTableauDuFichier(centre);
            break;
        case 9:
            break;

        default:
            printf("Tapez un Nombre Valide!!");
            break;
        }

    } while (ChoixMenu != 9);
    RemplireFichierduTableau(centre);
    LibereMemoire(centre);
    getch();
    return 0;
}
