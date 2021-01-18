#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../random/random.h"
#include "../vector/vector.h"

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
        int index = random_size_t(0, n);

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

    for (int i = 0; i < n; i++)
    {
        int index = random_size_t(0, n);

        vector_set(
            vector,
            index,               // Index : [0, n -1]
            random_double(0, 10) // Valeur : [0, 9]
        );

        vector_get(vector, index);
    }
}

/*
    Répète n fois l’ ́ecriture de tous les ́eléments du vecteur  
    puis la lecture de tous les ́eléments du vecteur toujours  
    avec un parcours de la tête vers la queue.
*/
void read_write_sequential(s_vector *vector, size_t n)
{
    init_random(vector);

    for (int i = 0; i < n; i++)
    {
        vector_get(vector, i);
    }
}

/*
    Répète n fois l’écriture de tous les ́eléments du vecteur avec 
    des valeurs aléatoires puis tri à bulles.
*/
void bubble_sort(s_vector *vector, size_t n)
{
    init_random(vector);

    // Tri à bulles
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

    // n = init_size < n ? init_size : n;

    char *test_type = "bubble_sort";

    // INIT TIME
    srand(time(NULL));

    // MALLOC
    s_vector *vector = vector_alloc(init_size);
    init_random(vector);

    // TESTS
    if (test_type == "insert_erase_random")
        insert_erase_random(vector, n);

    if (test_type == "insert_erase_head")
        insert_erase_head(vector, n);

    if (test_type == "insert_erase_tail")
        insert_erase_tail(vector, n);

    if (test_type == "read_write_random")
        read_write_random(vector, n);

    if (test_type == "read_write_sequential")
        read_write_sequential(vector, n);

    if (test_type == "bubble_sort")
        bubble_sort(vector, n);

    vector_print(vector);

    // FREE
    vector_free(vector);

    return 0;
}
