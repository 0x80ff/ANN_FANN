#include "fann.h"

int main()
{
    const unsigned int num_input              = 9;                   // Nombre neurones d'entrée
    const unsigned int num_output             = 1;                   // Nombre neurones sortie
    const unsigned int num_layers             = 3;                   // Nombre de couches
    const unsigned int num_neurons_hidden     = 5;                   // Nombre neurones couche cachée
    const float        desired_error          = (const float) 0.001; // Taux d'erreur désiré
    const unsigned int max_epochs             = 500000;              // Nombre d'itérations
    const unsigned int epochs_between_reports = 1000;                // Itérations entre chaque report de l'état du réseau

    struct fann *ann = fann_create_standard(num_layers, num_input,
        num_neurons_hidden, num_output);

    // Elements de configuration:
    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC); // Définition de la fonction d'activation pour la couche cachée
                                                                      // Utilisation de la fonction sigmoïde, [-1..1] Pas de lisssage ni
                                                                      // D'échelonnage.
    fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC); // Idem couche de sortie

    // Entrainement sur fichier:
    fann_train_on_file(ann, "dat.data", max_epochs,
        epochs_between_reports, desired_error);

    fann_save(ann, "trainet_float.net");

    fann_destroy(ann);

    return 0;
}
