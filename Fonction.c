#include "MaBib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AllocationAmbulance(AMBULANCE** ambulance, int n) {
    *ambulance = (AMBULANCE*)malloc(n * sizeof(AMBULANCE));
    if (!*ambulance) {
        printf("Erreur d'allocation memoire pour les ambulances.");
        exit(-1);
    }
    else{
        printf("Allocation ambulance succes\n");
    }
}
void AllocationMission(MISSION** mission, int n) {
    *mission = (MISSION*)malloc(n * sizeof(MISSION));
    if (!*mission) {
        printf("Erreur d'allocation memoire pour les missions.");
        exit(-2);
    }else{
        printf("Allocation mission succes\n");
    }
}
void AllocationPersonel(PERSONNEL**personnel,int n){
    *personnel = (PERSONNEL*)malloc(n * sizeof(PERSONNEL));
    if (!*personnel) {
        printf("Erreur d'allocation memoire pour les personnels.");
        exit(-4);
    }
    else{
        printf("Allocation personnel succes\n");
    }

}

void RemplirPersonnel(CENTRE*centre,int i){
    printf("Saisire le nom du personnel : ");
    scanf("%10s",centre->personnel[i].Nom);
    printf("Saisire le role du personnel : ");
    scanf("%15s",centre->personnel[i].Role);
    printf("Saisire le numero du telephone du personnel : ");
    scanf("%d",&centre->personnel[i].Telephone);
}

void RemplirAmbulance(CENTRE*centre,int i){
    printf("Saisire immatriculation : ");
    scanf("%10s",centre->ambulances[i].Imatriculation);
    printf("Saisire le conducteur : ");
    scanf("%15s",centre->ambulances[i].Conducteur);
    printf("Saisire le nombre des missions : ");
    scanf("%d",&centre->ambulances[i].NbMissions);
    AllocationMission(&centre->ambulances[i].mission,centre->ambulances[i].NbMissions);
    for (int j = 0;j<centre->ambulances[i].NbMissions;j++){
        printf("Saisire la date du mission  : \n");
        printf("Jour : ");
        scanf("%d",&centre->ambulances[i].mission[j].Date.jour);
        printf("Mois : ");
        scanf("%d",&centre->ambulances[i].mission[j].Date.mois);
        printf("Annee : ");
        scanf("%d",&centre->ambulances[i].mission[j].Date.annee);
        printf("Saisire la localisation : ");
        scanf("%20s",centre->ambulances[i].mission[j].Localisation);
        printf("Saisire Id mission : ");
        scanf("%d",&centre->ambulances[i].mission[j].IdMission);
        printf("Saisire le nom du patient : ");
        scanf("%20s",centre->ambulances[i].mission[j].Patient.Nom);
        printf("Saisire l'age du patient : ");
        printf("Jour : ");
        scanf("%d",&centre->ambulances[i].mission[j].Patient.Age.jour);
        printf("Mois : ");
        scanf("%d",&centre->ambulances[i].mission[j].Patient.Age.mois);
        printf("Annee : ");
        scanf("%d",&centre->ambulances[i].mission[j].Patient.Age.annee);
        printf("Saisire la maladie du patient : ");
        scanf("%15s",centre->ambulances[i].mission[j].Patient.Maladie);
    }
}

void RemplirCentre(CENTRE*centre){
    printf("Saisire nombre des ambulances : ");
    scanf("%d",&centre->NbAmbulances);
    printf("Saisire nombre des Personnel : ");
    scanf("%d",&centre->NbPersonel);
    AllocationAmbulance(&centre->ambulances,centre->NbAmbulances);
    AllocationPersonel(&centre->personnel,centre->NbPersonel);
    for (int i =0;i<centre->NbAmbulances;i++){
        RemplirAmbulance(centre,i);
    }
    for (int i =0;i<centre->NbPersonel;i++){
        RemplirPersonnel(centre,i);
    }
}

void RemplireFichierduTableau(CENTRE*centre){
    FILE* f = fopen("centre.bin","wb+");
    fwrite(&centre->NbAmbulances,sizeof(int),1,f);
    fwrite(&centre->NbPersonel,sizeof(int),1,f);
    for (int i = 0 ;i<centre->NbAmbulances;i++){
        fwrite(centre->ambulances[i].Imatriculation,sizeof(char),10,f);
        fwrite(centre->ambulances[i].Conducteur,sizeof(char),10,f);
        fwrite(&centre->ambulances[i].NbMissions,sizeof(int),1,f);
        for (int j =0;j<centre->ambulances[i].NbMissions;j++){
            fwrite(&centre->ambulances[i].mission[j].Date.jour,sizeof(int),1,f);
            fwrite(&centre->ambulances[i].mission[j].Date.mois,sizeof(int),1,f);
            fwrite(&centre->ambulances[i].mission[j].Date.annee,sizeof(int),1,f);
            fwrite(centre->ambulances[i].mission[j].Localisation,sizeof(char),20,f);
            fwrite(&centre->ambulances[i].mission[j].IdMission,sizeof(int),1,f);
            fwrite(&centre->ambulances[i].mission[j].Patient.Age.jour,sizeof(int),1,f);
            fwrite(&centre->ambulances[i].mission[j].Patient.Age.mois,sizeof(int),1,f);
            fwrite(&centre->ambulances[i].mission[j].Patient.Age.annee,sizeof(int),1,f);
            fwrite(centre->ambulances[i].mission[j].Patient.Nom,sizeof(char),20,f);
            fwrite(centre->ambulances[i].mission[j].Patient.Maladie,sizeof(char),15,f);
        }    
    }
    for (int i = 0;i<centre->NbPersonel;i++){
        fwrite(centre->personnel[i].Nom,sizeof(char),10,f);
        fwrite(centre->personnel[i].Role,sizeof(char),15,f);
        fwrite(&centre->personnel[i].Telephone,sizeof(int),1,f);
    }
    fclose(f);
    }


void RemplireTableauDuFichier(CENTRE*centre){
    FILE* f = fopen("centre.bin","rb");
    fread(&centre->NbAmbulances,sizeof(int),1,f);
    fread(&centre->NbPersonel,sizeof(int),1,f);
    AllocationAmbulance(&centre->ambulances,centre->NbAmbulances);
    AllocationPersonel(&centre->personnel,centre->NbPersonel);
    for (int i = 0 ;i<centre->NbAmbulances;i++){
        fread(centre->ambulances[i].Imatriculation,sizeof(char),10,f);
        fread(centre->ambulances[i].Conducteur,sizeof(char),10,f);
        fread(&centre->ambulances[i].NbMissions,sizeof(int),1,f);
        AllocationMission(&centre->ambulances[i].mission,centre->ambulances[i].NbMissions);
        for (int j =0;j<centre->ambulances[i].NbMissions;j++){
            fread(&centre->ambulances[i].mission[j].Date.jour,sizeof(int),1,f);
            fread(&centre->ambulances[i].mission[j].Date.mois,sizeof(int),1,f);
            fread(&centre->ambulances[i].mission[j].Date.annee,sizeof(int),1,f);
            fread(centre->ambulances[i].mission[j].Localisation,sizeof(char),20,f);
            fread(&centre->ambulances[i].mission[j].IdMission,sizeof(int),1,f);
            fread(&centre->ambulances[i].mission[j].Patient.Age.jour,sizeof(int),1,f);
            fread(&centre->ambulances[i].mission[j].Patient.Age.mois,sizeof(int),1,f);
            fread(&centre->ambulances[i].mission[j].Patient.Age.annee,sizeof(int),1,f);
            fread(centre->ambulances[i].mission[j].Patient.Nom,sizeof(char),20,f);
            fread(centre->ambulances[i].mission[j].Patient.Maladie,sizeof(char),15,f);
        }    
    }
    for (int i = 0;i<centre->NbPersonel;i++){
        fread(centre->personnel[i].Nom,sizeof(char),10,f);
        fread(centre->personnel[i].Role,sizeof(char),15,f);
        fread(&centre->personnel[i].Telephone,sizeof(int),1,f);
    }
    fclose(f);
    }



void LibereMemoire(CENTRE*centre){
    for (int i = 0;i<centre->NbAmbulances;i++){
        free(centre->ambulances[i].mission);
    }    
    free(centre->ambulances);
    free(centre->personnel);
    free(centre);
}

void ModifierAmbulance(CENTRE*centre){
    int ind;
    printf("Saisire le code ambulance : ");
    scanf("%d",&ind);
    ind-=1;
    if (ind < 0 || ind >= centre->NbAmbulances) {
        printf("Code ambulance invalide!\n");
        return;
    }
    printf("Saisire la nouvelle immatriculation (ancienne est : %d) : ",centre->ambulances[ind].Imatriculation);
    scanf("%d",&centre->ambulances[ind].Imatriculation);
    printf("Saisire le nouveau conducteur (ancien est : %s) : ",centre->ambulances[ind].Conducteur);
    scanf("%14s",centre->ambulances[ind].Imatriculation);
    printf("Saisire la nouveau nombre de missions (ancienne est : %d) : ",centre->ambulances[ind].NbMissions);
    scanf("%d",&centre->ambulances[ind].NbMissions);
    centre->ambulances[ind].mission = (MISSION*)realloc(centre->ambulances[ind].mission,centre->ambulances[ind].NbMissions*sizeof(MISSION));
    for (int i = 0;i<centre->ambulances[ind].NbMissions;i++){
        printf("Saisire la nouvelle date (ancienne est : %2d/%2d/%4d ) : \n",centre->ambulances[ind].mission[i].Date.jour,
        centre->ambulances[ind].mission[i].Date.mois,centre->ambulances[ind].mission[i].Date.annee);
        printf("Jour : ");
        scanf("%d",&centre->ambulances[ind].mission[i].Date.jour);
        printf("Mois : ");
        scanf("%d",&centre->ambulances[ind].mission[i].Date.mois);
        printf("Annee : ");
        scanf("%d",&centre->ambulances[ind].mission[i].Date.annee);
        printf("Saisire la nouvelle localisation (ancienne est : %s ) : ",centre->ambulances[ind].mission[i].Localisation);
        scanf("%14s",centre->ambulances[ind].mission[i].Localisation);
        printf("Saisire le nouvelle Idmission (ancienne est :  %d) :  ",centre->ambulances[ind].mission[i].IdMission);
        scanf("%d",&centre->ambulances[ind].mission[i].IdMission);
        printf("Saisire le nouveau nom du patient (ancien est : %s) : ",centre->ambulances[ind].mission[i].Patient.Nom);
        scanf("%19s",centre->ambulances[ind].mission[i].Patient.Nom);
        printf("Saisire le nouveau age du patient (ancien est : %2d/%2d/%4d) : ",centre->ambulances[ind].mission[i].Patient.Age.jour,
        centre->ambulances[ind].mission[i].Patient.Age.mois,centre->ambulances[ind].mission[i].Patient.Age.annee);
        printf("Saisire la nouvelle maladie du patient (ancienne est : %s) : ",centre->ambulances[ind].mission[i].Patient.Maladie);
        scanf("%14s",centre->ambulances[ind].mission[i].Patient.Maladie);
    }
}


void ModifierMission(CENTRE*centre){
    int indC,indM;
    printf("Saisir le code d'ambulance a modifier : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= centre->NbAmbulances) {
        printf("Code ambulance invalide!\n");
        return;
    }
    printf("Saisir le code du mission a modifier : ");
    scanf("%d", &indM);
    indM -= 1;
    if (indM < 0 || indM >= centre->ambulances[indC].NbMissions) {
        printf("Code mission invalide!\n");
        return;
    }
        printf("Saisire la nouvelle date (ancienne est : %2d/%2d/%4d ) : \n",centre->ambulances[indC].mission[indM].Date.jour,
        centre->ambulances[indC].mission[indM].Date.mois,centre->ambulances[indC].mission[indM].Date.annee);
        printf("Jour : ");
        scanf("%d",&centre->ambulances[indC].mission[indM].Date.jour);
        printf("Mois : ");
        scanf("%d",&centre->ambulances[indC].mission[indM].Date.mois);
        printf("Annee : ");
        scanf("%d",&centre->ambulances[indC].mission[indM].Date.annee);
        printf("Saisire la nouvelle localisation (ancienne est : %s ) : ",centre->ambulances[indC].mission[indM].Localisation);
        scanf("%14s",centre->ambulances[indC].mission[indM].Localisation);
        printf("Saisire le nouvelle Idmission (ancienne est :  %d) :  ",centre->ambulances[indC].mission[indM].IdMission);
        scanf("%d",&centre->ambulances[indC].mission[indM].IdMission);
        printf("Saisire le nouveau nom du patient (ancien est : %s) : ",centre->ambulances[indC].mission[indM].Patient.Nom);
        scanf("%19s",centre->ambulances[indC].mission[indM].Patient.Nom);
        printf("Saisire le nouveau age du patient (ancien est : %2d/%2d/%4d) : ",centre->ambulances[indC].mission[indM].Patient.Age.jour,
        centre->ambulances[indC].mission[indM].Patient.Age.mois,centre->ambulances[indC].mission[indM].Patient.Age.annee);
        printf("Saisire la nouvelle maladie du patient (ancienne est : %s) : ",centre->ambulances[indC].mission[indM].Patient.Maladie);
        scanf("%14s",centre->ambulances[indC].mission[indM].Patient.Maladie);
}

void ModifierPatient(CENTRE*centre){
    int indC,indM;
    printf("Saisir le code d'ambulance a modifier : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= centre->NbAmbulances) {
        printf("Code ambulance invalide!\n");
        return;
    }
    printf("Saisir le code du mission a modifier : ");
    scanf("%d", &indM);
    indM -= 1;
    if (indM < 0 || indM >= centre->ambulances[indC].NbMissions) {
        printf("Code mission invalide!\n");
        return;
    }
    printf("Saisire le nouveau nom du patient (ancien est : %s) : ",centre->ambulances[indC].mission[indM].Patient.Nom);
    scanf("%19s",centre->ambulances[indC].mission[indM].Patient.Nom);
    printf("Saisire le nouveau age du patient (ancien est : %2d/%2d/%4d) : ",centre->ambulances[indC].mission[indM].Patient.Age.jour,
    centre->ambulances[indC].mission[indM].Patient.Age.mois,centre->ambulances[indC].mission[indM].Patient.Age.annee);
    printf("Saisire la nouvelle maladie du patient (ancienne est : %s) : ",centre->ambulances[indC].mission[indM].Patient.Maladie);
    scanf("%14s",centre->ambulances[indC].mission[indM].Patient.Maladie);
}


void ModifierPersonel(CENTRE*centre){
    int indP;
    printf("Saisir le code du personnel a modifier : ");
    scanf("%d", &indP);
    indP -= 1;
    if (indP < 0 || indP >= centre->NbPersonel) {
        printf("Code personnel invalide!\n");
        return;
    }
    printf("Saisire le nouveau nom du personnel (ancien est : %s) : ",centre->personnel->Nom);
    scanf("%9s",centre->personnel->Nom);
    printf("Saisire la nouvelle role du personnel (ancienne est : %s) : ",centre->personnel->Role);
    scanf("%14s",centre->personnel->Role);
    printf("Saisire le nouveau numero du telephone du personnel (ancien est : %d) : ",centre->personnel->Telephone);
    scanf("%d",&centre->personnel->Telephone);
}

void AjoutAmbulance(CENTRE*centre){
    centre->ambulances = (AMBULANCE*)realloc(centre->ambulances,((centre->NbAmbulances)+1)*sizeof(AMBULANCE));
    RemplirAmbulance(centre,centre->NbAmbulances);
    centre->NbAmbulances +=1;
}
void AjoutMission(CENTRE*centre){
    int ind;
    printf("Saisire le code ambulance : ");
    scanf("%d",&ind);
    ind-=1;
    if (ind < 0 || ind >= centre->NbAmbulances) {
        printf("Code ambulance invalide!\n");
        return;
    }
    centre->ambulances[ind].mission = (MISSION*)realloc(centre->ambulances[ind].mission,((centre->ambulances[ind].NbMissions)+1)*sizeof(MISSION));
    int n = centre->ambulances[ind].NbMissions;
    printf("Saisire la date du mission  : \n");
    printf("Jour : ");
    scanf("%d",&centre->ambulances[ind].mission[n].Date.jour);
    printf("Mois : ");
    scanf("%d",&centre->ambulances[ind].mission[n].Date.mois);
    printf("Annee : ");
    scanf("%d",&centre->ambulances[ind].mission[n].Date.annee);
    printf("Saisire la localisation : ");
    scanf("%19s",centre->ambulances[ind].mission[n].Localisation);
    printf("Saisire Id mission : ");
    scanf("%d",&centre->ambulances[ind].mission[n].IdMission);
    printf("Saisire le nom du patient : ");
    scanf("%19s",centre->ambulances[ind].mission[n].Patient.Nom);
    printf("Saisire l'age du patient : ");
    printf("Jour : ");
    scanf("%d",&centre->ambulances[ind].mission[n].Patient.Age.jour);
    printf("Mois : ");
    scanf("%d",&centre->ambulances[ind].mission[n].Patient.Age.mois);
    printf("Annee : ");
    scanf("%d",&centre->ambulances[ind].mission[n].Patient.Age.annee);
    printf("Saisire la maladie du patient : ");
    scanf("%14s",centre->ambulances->mission->Patient.Maladie);

}
void AjoutPersonel(CENTRE*centre){
    int indP;
    printf("Saisir le code du personnel a modifier : ");
    scanf("%d", &indP);
    indP -= 1;
    if (indP < 0 || indP >= centre->NbPersonel) {
        printf("Code personnel invalide!\n");
        return;
    }
    centre->personnel = (PERSONNEL*)realloc(centre->personnel,((centre->NbPersonel)+1)*sizeof(PERSONNEL));
    int n = centre->NbPersonel;
    RemplirPersonnel(centre,n);
}

void SupprimerMission(CENTRE*centre){
    int indC,indM;
    printf("Saisir le code d'ambulance a modifier : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= centre->NbAmbulances) {
        printf("Code ambulance invalide!\n");
        return;
    }
    printf("Saisir le code du mission a modifier : ");
    scanf("%d", &indM);
    indM -= 1;
    if (indM < 0 || indM >= centre->ambulances[indC].NbMissions) {
        printf("Code mission invalide!\n");
        return;
    }
    for (int i = indM;i <centre->ambulances[indC].NbMissions -1;i++) {
        centre->ambulances[indC].mission[i]=centre->ambulances[indC].mission[i+1];
    }
    centre->ambulances[indC].mission = (MISSION*)realloc(centre->ambulances[indC].mission,(centre->ambulances[indC].NbMissions-1)*sizeof(MISSION));
    centre->ambulances[indC].NbMissions -= 1;
    printf("Mission supprime avec succes\n");
}
void SupprimerAmbulance(CENTRE*centre){
    int ind;
    printf("Saisire le code ambulance : ");
    scanf("%d",&ind);
    ind-=1;
    if (ind < 0 || ind >= centre->NbAmbulances) {
        printf("Code ambulance invalide!\n");
        return;
    }
    for (int i =ind;i<centre->NbAmbulances-1;i++){
        centre->ambulances[i] = centre->ambulances[i+1];
    }
    centre->ambulances = (AMBULANCE*)realloc(centre->ambulances,(centre->NbAmbulances-1)*sizeof(AMBULANCE));
    centre->NbAmbulances = centre->NbAmbulances-1;
    printf("Ambulance supprime avec succes\n");

}
void SupprimerPersonel(CENTRE*centre){
    int ind;
    printf("Saisire le code personnel : ");
    scanf("%d",&ind);
    ind-=1;
    if (ind < 0 || ind >= centre->NbPersonel) {
        printf("Code personnel invalide!\n");
        return;
    }
    centre->personnel = (PERSONNEL*)realloc(centre->personnel,(centre->NbPersonel-1)*sizeof(PERSONNEL));
    centre->NbPersonel = centre->NbPersonel-1;
    printf("Personnel supprime avec succes\n");
}

void AfficherAmbulance(CENTRE*centre){
    int ind;
    printf("Saisire le code ambulance : ");
    scanf("%d",&ind);
    ind-=1;
    if (ind < 0 || ind >= centre->NbAmbulances) {
        printf("Code ambulance invalide!\n");
        return;
    }
    printf("Immatricule : %s\n",centre->ambulances[ind].Imatriculation);
    printf("Conducteur : %s\n",centre->ambulances[ind].Conducteur);
    for (int i = 0;i<centre->ambulances[ind].NbMissions;i++){
        printf("Date : %2d/%2d/%4d\n",centre->ambulances[ind].mission[i].Date.jour
        ,centre->ambulances[ind].mission[i].Date.mois
        ,centre->ambulances[ind].mission[i].Date.annee);
        printf("IdMission  : %d \n",centre->ambulances[ind].mission[i].IdMission);
        printf("Nom du patient : %s \n",centre->ambulances[ind].mission[i].Patient.Nom);
        printf("Age du patient : %2d/%2d/%4d \n",centre->ambulances[ind].mission[i].Patient.Age.jour
        ,centre->ambulances[ind].mission[i].Patient.Age.mois
        ,centre->ambulances[ind].mission[i].Patient.Age.annee);
        printf("Maladie du patient : %s \n",centre->ambulances[ind].mission[i].Patient.Maladie);

    }
    
}
void AfficherMission(CENTRE*centre){
    int indC,indM;
    printf("Saisir le code d'ambulance  : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= centre->NbAmbulances) {
        printf("Code ambulance invalide!\n");
        return;
    }
    printf("Saisir le code du mission  : ");
    scanf("%d", &indM);
    indM -= 1;
    if (indM < 0 || indM >= centre->ambulances[indC].NbMissions) {
        printf("Code mission invalide!\n");
        return;
    }
    printf("Date : %2d/%2d/%4d\n",centre->ambulances[indC].mission[indM].Date.jour
    ,centre->ambulances[indC].mission[indM].Date.mois
    ,centre->ambulances[indC].mission[indM].Date.annee);
    printf("IdMission  : %d \n",centre->ambulances[indC].mission[indM].IdMission);
    printf("Nom du patient : %s \n",centre->ambulances[indC].mission[indM].Patient.Nom);
    printf("Age du patient : %2d/%2d/%4d \n",centre->ambulances[indC].mission[indM].Patient.Age.jour
    ,centre->ambulances[indC].mission[indM].Patient.Age.mois
    ,centre->ambulances[indC].mission[indM].Patient.Age.annee);
    printf("Maladie du patient : %s \n",centre->ambulances[indC].mission[indM].Patient.Maladie);

}
void AfficherPersonel(CENTRE*centre){
    int ind;
    printf("Saisire le code personnel : ");
    scanf("%d",&ind);
    ind-=1;
    if (ind < 0 || ind >= centre->NbPersonel) {
        printf("Code personnel invalide!\n");
        return;
    }
    printf("Nom du personnel : %s\n",centre->personnel[ind].Nom);
    printf("Role du personnel : %s\n",centre->personnel[ind].Role);
    printf("Numero du telephone du personnel : %d\n",centre->personnel[ind].Telephone);
}
void AfficherPatient(CENTRE*centre){
    int indC,indM;
    printf("Saisir le code d'ambulance  : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= centre->NbAmbulances) {
        printf("Code ambulance invalide!\n");
        return;
    }
    printf("Saisir le code du mission  : ");
    scanf("%d", &indM);
    indM -= 1;
    if (indM < 0 || indM >= centre->ambulances[indC].NbMissions) {
        printf("Code mission invalide!\n");
        return;
    }
    printf("Nom du patient : %s\n",centre->ambulances[indC].mission[indM].Patient.Nom);
    printf("Age du patient : %2d/%2d/%4d\n",centre->ambulances[indC].mission[indM].Patient.Age.jour
    ,centre->ambulances[indC].mission[indM].Patient.Age.mois
    ,centre->ambulances[indC].mission[indM].Patient.Age.annee);
    printf("Maladie du patient : %s\n",centre->ambulances[indC].mission[indM].Patient.Maladie);
}
void PatientPlusJeune(CENTRE *centre) {
    int minAgeTotal = INT_MAX;
    PATIENT patientMin;

    int agePatientEnJours;
    int ageReference;
    for (int i = 0; i < centre->NbAmbulances; i++) {
        for (int j = 0; j < centre->ambulances[i].NbMissions; j++) {
            ageReference = 2024 * 365;
            agePatientEnJours = ageReference -
                                (centre->ambulances[i].mission[j].Patient.Age.annee * 365 +
                                 centre->ambulances[i].mission[j].Patient.Age.mois * 30 +
                                 centre->ambulances[i].mission[j].Patient.Age.jour);

            if (agePatientEnJours < minAgeTotal) {
                minAgeTotal = agePatientEnJours;
                patientMin = centre->ambulances[i].mission[j].Patient;
            }
        }
    }

    if (minAgeTotal == INT_MAX) {
        printf("Aucun patient enregistré.\n");
        return;
    }
    printf("Le patient le plus jeune est :\n");
    printf("Nom : %s\n", patientMin.Nom);
    printf("Date de naissance : %02d/%02d/%04d\n",
           patientMin.Age.jour,
           patientMin.Age.mois,
           patientMin.Age.annee);
    printf("Maladie : %s\n", patientMin.Maladie);
}

void AmbulancePlusDeMissions(CENTRE *centre) {
    int maxMissions = 0; 
    int indexAmbulanceMax = -1; 

    for (int i = 0; i < centre->NbAmbulances; i++) {
        int nbMissions = centre->ambulances[i].NbMissions;
        if (nbMissions > maxMissions) {
            maxMissions = nbMissions;
            indexAmbulanceMax = i;
        }
    }
    if (indexAmbulanceMax != -1) {
        printf("L'ambulance ayant effectué le plus de missions est l'ambulance #%d.\n", indexAmbulanceMax + 1);
        printf("Nombre de missions : %d\n", maxMissions);
    } else {
        printf("Aucune mission n'a été effectuée par les ambulances.\n");
    }
}

void NombrePatientsAvecMaladie(CENTRE *centre) {
    int compteur = 0;
    char Maladie[50];
    printf("Donner une maladie : ");
    scanf("%49s",Maladie);
    for (int i = 0; i < centre->ambulances->NbMissions; i++) {
        for (int j = 0;j<centre->ambulances[i].NbMissions;j++){
            if (strcmp(centre->ambulances[i].mission[j].Patient.Maladie, Maladie) == 0) {
            compteur++;
            }
        }
    }
    printf("Il y a %d patient qui ont %s\n",compteur,Maladie);
}



