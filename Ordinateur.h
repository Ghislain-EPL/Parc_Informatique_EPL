#ifndef ORDINATEUR_H
#define ORDINATEUR_H

// Définition de la structure selon les champs de ton sujet
typedef struct {
    int numCarteDetenteur;
    char specialite[50];
    char numSerie[50];
    char marque[30];
    float vitesseCPU;
    int ram;
    int tailleDisque;
    int prixEstime;
} Ordinateur;

// Prototypes des fonctions (Formalisme pointeur imposé)
void ajouterOrdinateur(Ordinateur **parc, int *nbActuel);
void listerParc(Ordinateur **parc, int nbActuel);
void libererToutLeParc(Ordinateur **parc, int nbActuel);

#endif
