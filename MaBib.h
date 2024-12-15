struct date
{
    int jour;
    int mois;
    int annee;
};
typedef struct date DATE;

struct patient
 {
    char Nom[20];
    DATE Age;
    char Maladie[15];
} ;
 typedef struct patient PATIENT;



 struct personnel
 {
    char Nom[10];
    char Role[15];
    int Telephone;
} ;
typedef struct personnel PERSONNEL;



 struct mission {
    DATE Date;
    char Localisation[20];
    int IdMission;
    PATIENT Patient;
} ;
typedef struct mission MISSION;



 struct ambulance
 {
    char Imatriculation[10];
    char Conducteur[15];
    int NbMissions;
    MISSION* mission;     
} ;
typedef struct ambulance AMBULANCE;



 struct centre
 {
    int NbAmbulances;
    AMBULANCE* ambulances;
    int NbPersonel;
    PERSONNEL* personnel;
} ;

typedef struct centre CENTRE;

struct resultat {
char immatriculation[10];
int nbMission;
};
typedef struct resultat RESULTAT;