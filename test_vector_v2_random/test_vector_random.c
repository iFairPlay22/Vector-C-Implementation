#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../random/random.h"
#include "../vector_v2/vector.h"

// Initialise le vecteur avec des valeurs aléatoires
void init_random(s_vector *vector)
{
    for (int i = 0; i < vector_size(vector); i++)
    {
        vector_set(
            vector,
            i,
            random_double(0, 10) // Valeur : [0, 9]
        );
    }
}

/*
    Répète n fois l’ajout puis la suppression d’un  ́elément à 
    des positions aléatoires.
*/
void insert_erase_random(s_vector *vector, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        size_t index = random_size_t(0, vector_size(vector));

        vector_insert(
            vector,
            index,               // Index : [0, n -1]
            random_double(0, 10) // Valeur : [0, 9]
        );

        vector_erase(vector, index);
    }
}

/*
    Répète n fois l’ajout puis la suppression d’un ́elément en tête.
*/
void insert_erase_head(s_vector *vector, size_t n)
{

    for (int i = 0; i < n; i++)
    {
        vector_insert(
            vector,
            0,                   // Insertion en queue
            random_double(0, 10) // Valeur : [0, 9]
        );

        vector_erase(vector, 0);
    }
}

/*
    Répète n fois l’ajout puis la suppression d’un ́elément en queue.
*/
void insert_erase_tail(s_vector *vector, size_t n)
{

    for (int i = 0; i < n; i++)
    {
        vector_push_back(
            vector,
            random_double(0, 10) // Valeur : [0, 9]
        );

        vector_pop_back(vector);
    }
}

/*
    Répète n fois l’́ecriture puis la lecture d’un elément à  
    des positions aléatoires.
*/
void read_write_random(s_vector *vector, size_t n)
{
    // Répète n fois...
    for (int i = 0; i < n; i++)
    {
        size_t index = random_size_t(0, vector_size(vector));

        // l’́ecriture...
        vector_set(
            vector,
            index,               // Index : [0, n -1]
            random_double(0, 10) // Valeur : [0, 9]
        );

        // puis la lecture d’un elément à des positions aléatoires...
        vector_get(vector, index);
    }
}

/*
    Répète n fois l’écriture de tous les ́eléments du vecteur  
    puis la lecture de tous les ́eléments du vecteur toujours  
    avec un parcours de la tête vers la queue.
*/
void read_write_sequential(s_vector *vector, size_t n)
{
    size_t size = vector_size(vector);

    // Répète n fois...
    for (int i = 0; i < n; i++)
    {
        // l’écriture de tous les ́eléments du vecteur...
        init_random(vector);

        //puis la lecture de tous les ́eléments du vecteur toujours
        //avec un parcours de la tête vers la queue...
        for (int i = 0; i < size; i++)
            vector_get(vector, i);
    }
}

/*
    Répète n fois l’écriture de tous les ́eléments du vecteur avec 
    des valeurs aléatoires puis tri à bulles.
*/
void bubble_sort(s_vector *vector, size_t n)
{
    size_t size = vector_size(vector);

    // On répète n fois
    for (int i = 0; i < n; i++)
    {
        // l’écriture de tous les ́eléments du vecteur avec des valeurs aléatoires ...
        init_random(vector);

        // puis tri à bulles..
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                double t_av = vector_get(vector, j);
                double t_ap = vector_get(vector, j + 1);

                if (t_ap < t_av)
                {
                    vector_set(vector, j, t_ap);
                    vector_set(vector, j + 1, t_av);
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // PARAMETRES
    if (argc != 4)
    {
        printf("Nombre de paramètres invalide...\n");
        return 1;
    }

    size_t init_size, n;
    char const *test_type = argv[1];
    sscanf(argv[2], "%ld", &init_size);
    sscanf(argv[3], "%ld", &n);

    // INIT TIME
    srand(time(NULL));

    // MALLOC
    s_vector *vector = vector_alloc(init_size);
    init_random(vector);

    // TESTS
    if (strcmp(test_type, "insert_erase_random") == 0)
        insert_erase_random(vector, n);

    if (strcmp(test_type, "insert_erase_head") == 0)
        insert_erase_head(vector, n);

    if (strcmp(test_type, "insert_erase_tail") == 0)
        insert_erase_tail(vector, n);

    if (strcmp(test_type, "read_write_random") == 0)
        read_write_random(vector, n);

    if (strcmp(test_type, "read_write_sequential") == 0)
        read_write_sequential(vector, n);

    if (strcmp(test_type, "bubble_sort") == 0)
        bubble_sort(vector, n);

    // vector_print(vector);

    // FREE
    vector_free(vector);

    return 0;
}
