#include "Fonction.c"

void RemplirCentre(CENTRE*);
void AllocationAmbulance(AMBULANCE**,int);
void AllocationMission(MISSION**,int);
void AllocationPersonel(PERSONNEL**,int);
void RemplirAmbulance(CENTRE*,int );
void RemplirPersonnel(CENTRE*,int );
void RemplirCentre(CENTRE*);
void RemplireFichierduTableau(CENTRE*);
void RemplireTableauDuFichier(CENTRE*);
void LibereMemoire(CENTRE*);
void RemplireFichierduTableau(CENTRE*centre);
void RemplireTableauDuFichier(CENTRE*centre);

void ModifierAmbulance(CENTRE*centre);
void ModifierMission(CENTRE*centre);
void ModifierPatient(CENTRE*centre);
void ModifierPersonel(CENTRE*centre);
void AjoutAmbulance(CENTRE*centre);
void AjoutMission(CENTRE*centre);
void AjoutPersonel(CENTRE*centre);
void SupprimerMission(CENTRE*centre);
void SupprimerAmbulance(CENTRE*centre);
void SupprimerPersonel(CENTRE*centre);
void AfficherAmbulance(CENTRE*centre);
void AfficherMission(CENTRE*centre);
void AfficherPersonel(CENTRE*centre);
void AfficherPatient(CENTRE*centre);