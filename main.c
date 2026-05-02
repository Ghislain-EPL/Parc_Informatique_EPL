#include <stdio.h>
#include <stdlib.h>
#include "ordinateur.h"

int main() {
    // Allocation du tableau de 300 pointeurs (Niveau 1)
    Ordinateur **monParc = (Ordinateur **)malloc(300 * sizeof(Ordinateur *));

    if (monParc == NULL) return 1;

    // Initialisation sécurisée
    for (int i = 0; i < 300; i++) *(monParc + i) = NULL;

    int nbOrdis = 0;
    int choix;

    do {
        printf("\n--- GESTION PARC EPL ---\n");
        printf("1. Ajouter\n2. Lister\n0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1: ajouterOrdinateur(monParc, &nbOrdis); break;
            case 2: listerParc(monParc, nbOrdis); break;
            case 0: libererToutLeParc(monParc, nbOrdis); break;
        }
    } while (choix != 0);

    free(monParc); // Libération finale du tableau
    printf("Fin du programme.\n");
    return 0;
}
