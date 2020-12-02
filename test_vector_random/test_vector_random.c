#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../random/random.h"
#include "../vector/vector.h"

/*
    Répète n fois l’ajout puis la suppression d’un  ́elément à 
    des positions aléatoires.
*/
void insert_erase_random(s_vector p_vector, size_t n) {}

/*
    Répète n fois l’ajout puis la suppression d’un ́elément en tête.
*/
void insert_erase_head(s_vector p_vector, size_t n) {}

/*
    Répète n fois l’ajout puis la suppression d’un ́elément en queue.
*/
void insert_erase_tail(s_vector p_vector, size_t n) {}

/*
    Répète n fois l’́ecriture puis la lecture d’un elément à  
    des positions aléatoires.
*/
void read_write_random(s_vector p_vector, size_t n) {}

/*
    Répète n fois l’ ́ecriture de tous les ́eléments du vecteur  
    puis la lecture de tous les ́eléments du vecteur toujours  
    avec un parcours de la tête vers la queue.
*/
void read_write_sequential(s_vector p_vector, size_t n) {}

/*
    Répète n fois l’écriture de tous les ́eléments du vecteur avec 
    des valeurs aléatoires puis tri à bulles.
*/
void bubble_sort(s_vector p_vector, size_t n) {}

int main(int argc, char const *argv[])
{

    // PARAMETRES
    if (argc != 3)
    {
        printf("Nombre de paramètres invalide...\n");
        return 1;
    }

    size_t init_size, n;
    sscanf(argv[1], "%ld", &init_size);
    sscanf(argv[2], "%ld", &n);

    // INIT RANDOM
    srand(time(NULL));

    // TEST VECTOR
    s_vector *vector = vector_alloc(init_size);
    vector_print(vector);
    vector_free(vector);

    return 0;
}
