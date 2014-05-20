#include <stdio.h>
#include <math.h>
#include "floatfann.h"

int main()
{
    fann_type *calc_out;
    fann_type input[9];

    // Fichier de configuration du r�seau apr�s entrainement(poids, fonctions..):
    struct fann *ann = fann_create_from_file("trainet_float.net");

    /* Donn�es de test, le r�seau n'a jamais travailler sur celles-ci, d'ou l'int�r�t pour voir le comportement du r�seau:
    // Le dernier �l�ment correspond au r�sultat des analyses, que le r�seau doit d�duire � partir de sa logique d"apprentissage: 2 pour b�nin, 4 pour malin.
    //
    3,1,1,1,2,1,1,1,1,2
    3,1,1,1,2,1,2,1,2,2
    3,1,1,1,3,2,1,1,1,2
    2,1,1,1,2,1,1,1,1,2
    5,10,10,3,7,3,8,10,2,4
    4,8,6,4,3,4,10,6,1,4
    4,8,8,5,4,5,10,4,1,4
    */

    // Donn�es de la couche d'entr�e:
    input[0] = 4; // Neurone 0
    input[1] = 8; // Neurone 1
    input[2] = 6; // ..
    input[3] = 4;
    input[4] = 3;
    input[5] = 4;
    input[6] = 10;
    input[7] = 6;
    input[8] = 1;

    // calc_out contient le r�sultat renvoy� par le r�seau
    calc_out = fann_run(ann, input); // Le r�seau utilise la fonction d'activation sigmo�de : -1 < calc_out < 1

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
    if(calc_out[0] > 0.98f){ // Je consid�re que seul un r�sultat de 0.99 est acceptable, m�me si une marge plus grande serait envisageable.
                             // Je recherche la pr�cision du r�seau, et seul un r�sultat > 0.98 correspond � mes attentes pour les tests, en
                             // envisageant que ce soit une simulation pour un hopital par exemple ou les r�sultat d'une biopsie serait for-
                             // -mat�s et envoy�s automatiquement au r�seau de neurones. Dans ce cas, seuls les r�sultats s�rs du r�seau sont
                             // gard�s; un r�sultat b�nin s�r ne n�cessitant aucune intervention humaine suppl�mentaire; un r�sultat malin ou
                             // non-s�r n�cessitant alors une intervention humaine pour approfondir les r�sultats.
        float value = (calc_out[0] * 100);
        printf("  Statut : Maligne\n");
        printf("  Pourcentage : %f%%\n", value);
    }else if(calc_out[0] < -0.98f){
        float value = (calc_out[0] * -1) * 100;
        printf("  Statut : Benigne\n");
        printf("  Pourcentage : %f%%\n", value);
    }else{
        printf("R�sultat non s�r\n");
    }
    printf("\n\n\n\n\n\n");
    fann_destroy(ann);
    return 0;
}
