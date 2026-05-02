#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordinateur.h"

void ajouterOrdinateur(Ordinateur **parc, int *nbActuel) {
    if (parc == NULL || *nbActuel >= 300) {
        printf("\nErreur : Parc plein ou inexistant.\n");
        return;
    }

    // Allocation dynamique d'UN ordinateur (Niveau 2)
    Ordinateur *nouvelOrdi = (Ordinateur *)malloc(sizeof(Ordinateur));

    if (nouvelOrdi == NULL) {
        printf("\nErreur : Memoire saturee.\n");
        return;
    }

    printf("\n--- Saisie Ordinateur %d ---\n", *nbActuel + 1);
    printf("Numero carte detenteur : ");
    scanf("%d", &nouvelOrdi->numCarteDetenteur);
    printf("Marque : ");
    scanf(" %[^\n]", nouvelOrdi->marque);
    printf("Vitesse CPU (Ghz) : ");
    scanf("%f", &nouvelOrdi->vitesseCPU);
    printf("RAM (Go) : ");
    scanf("%d", &nouvelOrdi->ram);
    printf("Prix (F CFA) : ");
    scanf("%d", &nouvelOrdi->prixEstime);

    // Rangement avec arithmétique de pointeur
    *(parc + *nbActuel) = nouvelOrdi;
    (*nbActuel)++;
    printf("Succes !\n");
}

void listerParc(Ordinateur **parc, int nbActuel) {
    if (nbActuel == 0) {
        printf("\nLe parc est vide.\n");
        return;
    }
    printf("\n%-5s | %-15s | %-10s | %-10s\n", "ID", "MARQUE", "RAM", "PRIX");
    for (int i = 0; i < nbActuel; i++) {
        Ordinateur *t = *(parc + i);
        if (t != NULL) {
            printf("%-5d | %-15s | %-10d | %-10d\n", i+1, t->marque, t->ram, t->prixEstime);
        }
    }
}

void libererToutLeParc(Ordinateur **parc, int nbActuel) {
    if (parc == NULL) return;
    for (int i = 0; i < nbActuel; i++) {
        if (*(parc + i) != NULL) {
            free(*(parc + i));
            *(parc + i) = NULL;
        }
    }
}
