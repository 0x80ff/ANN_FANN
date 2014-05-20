#include <stdio.h>
#include <math.h>
#include "floatfann.h"

int main()
{
    fann_type *calc_out;
    fann_type input[9];

    // Fichier de configuration du réseau après entrainement(poids, fonctions..):
    struct fann *ann = fann_create_from_file("trainet_float.net");

    /* Données de test, le réseau n'a jamais travailler sur celles-ci, d'ou l'intérêt pour voir le comportement du réseau:
    // Le dernier élément correspond au résultat des analyses, que le réseau doit déduire à partir de sa logique d"apprentissage: 2 pour bénin, 4 pour malin.
    //
    3,1,1,1,2,1,1,1,1,2
    3,1,1,1,2,1,2,1,2,2
    3,1,1,1,3,2,1,1,1,2
    2,1,1,1,2,1,1,1,1,2
    5,10,10,3,7,3,8,10,2,4
    4,8,6,4,3,4,10,6,1,4
    4,8,8,5,4,5,10,4,1,4
    */

    // Données de la couche d'entrée:
    input[0] = 4; // Neurone 0
    input[1] = 8; // Neurone 1
    input[2] = 6; // ..
    input[3] = 4;
    input[4] = 3;
    input[5] = 4;
    input[6] = 10;
    input[7] = 6;
    input[8] = 1;

    // calc_out contient le résultat renvoyé par le réseau
    calc_out = fann_run(ann, input); // Le réseau utilise la fonction d'activation sigmoïde : -1 < calc_out < 1

    // Affichage en speed..
    printf("Groupement des Couches        : %.0f\n",  input[0]);
    printf("Uniformite Taille Cellule     : %.0f\n",  input[1]);
    printf("Uniformite Forme Cellule      : %.0f\n",  input[2]);
    printf("Adhesion Cellulaire           : %.0f\n",  input[3]);
    printf("Taille Cellules Epithelialles : %.0f\n",  input[4]);
    printf("Noyau isole                   : %.0f\n",  input[5]);
    printf("Uniformite Texture Chromatine : %.0f\n",  input[6]);
    printf("Nucleoles                     : %.0f\n",  input[7]);
    printf("Mitoses                       : %.0f\n\n",input[8]);

    printf("Valeur de sortie:  -> %f\n\n", calc_out[0]);

    printf("Resultat :\n");
    if(calc_out[0] > 0.98f){ // Je considère que seul un résultat de 0.99 est acceptable, même si une marge plus grande serait envisageable.
                             // Je recherche la précision du réseau, et seul un résultat > 0.98 correspond à mes attentes pour les tests, en
                             // envisageant que ce soit une simulation pour un hopital par exemple ou les résultat d'une biopsie serait for-
                             // -matés et envoyés automatiquement au réseau de neurones. Dans ce cas, seuls les résultats sûrs du réseau sont
                             // gardés; un résultat bénin sûr ne nécessitant aucune intervention humaine supplémentaire; un résultat malin ou
                             // non-sûr nécessitant alors une intervention humaine pour approfondir les résultats.
        float value = (calc_out[0] * 100);
        printf("  Statut : Maligne\n");
        printf("  Pourcentage : %f%%\n", value);
    }else if(calc_out[0] < -0.98f){
        float value = (calc_out[0] * -1) * 100;
        printf("  Statut : Benigne\n");
        printf("  Pourcentage : %f%%\n", value);
    }else{
        printf("Résultat non sûr\n");
    }
    printf("\n\n\n\n\n\n");
    fann_destroy(ann);
    return 0;
}
