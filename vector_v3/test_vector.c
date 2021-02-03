#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"
#include "../random/random.h"
#include "../my_struct/my_struct.h"

/*
    Retourne une my_struct* initialisée de manière aléatoire
*/
my_struct *randomStruct()
{
    my_struct *s1 = my_struct_alloc();
    my_struct_randoms_init(s1);
    return s1;
}

/*
    Positionne une my_struct* initialisée de manière aléatoire
    à la position i du vector passé en paramètre.
*/
void secureSet(s_vector *vector, size_t i)
{
    my_struct *expected = randomStruct();
    my_struct *get = my_struct_alloc();

    // Set
    size_t beforeSize = vector_size(vector);
    vector_set(vector, i, expected);
    size_t afterSize = vector_size(vector);
    vector_get(vector, i, get);

    // Test quality
    if (!(beforeSize == afterSize && my_struct_cmp(expected, get) == 0))
    {
        printf("Error when set my_struct[%ld -> %ld]\n", beforeSize, afterSize);
        printf("Expected : ");
        my_struct_print(expected);
        printf("Get : ");
        my_struct_print(get);
        exit(1); // NB : Ignorer les erreurs de free de valgrind
    }

    // Test quality
    my_struct_free(expected);
    my_struct_free(get);
}

/*
    Insère une my_struct* initialisée de manière aléatoire
    à la position i du vector passé en paramètre.
*/
void secureInsert(s_vector *vector, size_t i)
{
    my_struct *expected = randomStruct();
    my_struct *get = my_struct_alloc();

    // Insert
    size_t beforeSize = vector_size(vector);
    vector_insert(vector, i, expected);
    size_t afterSize = vector_size(vector);
    vector_get(vector, i, get);

    // Test quality
    if (!(beforeSize + 1 == afterSize && my_struct_cmp(expected, get) == 0))
    {
        printf("Error when insert my_struct[%ld -> %ld]\n", beforeSize, afterSize);
        printf("Expected : ");
        my_struct_print(expected);
        printf("Get : ");
        my_struct_print(get);
        exit(2); // NB : Ignorer les erreurs de free de valgrind
    }

    // Free copy
    my_struct_free(expected);
    my_struct_free(get);
}

/*
    Supprime la position i du vector passé en paramètre.
*/
void secureErase(s_vector *vector, size_t i)
{
    my_struct *expected = randomStruct();
    my_struct *get = my_struct_alloc();

    // Erase
    size_t beforeSize = vector_size(vector);
    vector_erase(vector, 0);
    size_t afterSize = vector_size(vector);

    // Test quality
    if (beforeSize != afterSize + 1)
    {
        printf("Error when erase my_struct[%ld -> %ld]\n", beforeSize, afterSize);
        exit(3); // NB : Ignorer les erreurs de free de valgrind
    }

    // Free copy
    my_struct_free(expected);
    my_struct_free(get);
}

/*
    Teste l'implémentation des vecteurs génériques avec des my_struct*
*/
void test()
{
    // Malloc
    s_vector *vector = vector_alloc(
        10,
        (t_data_alloc)my_struct_alloc,
        (t_data_free)my_struct_free,
        (t_data_cpy)my_struct_copy,
        (t_data_print)my_struct_print);

    // [ 0 => #1, ... ]
    secureSet(vector, 0);

    // [ 0 => #2, ... ]
    secureSet(vector, 0);

    // [ ... ]
    secureErase(vector, 0);

    // [ 0 => #3, ... ]
    secureInsert(vector, 0);

    // [ 0 => #3, 1 => #4, ... ]
    secureInsert(vector, 1);

    // vector_print(vector);

    for (int i = 0; i < 20; i++)
    {
        secureInsert(vector, 1);
        secureErase(vector, 1);
    }

    // [  ]
    vector_clear(vector);

    // [ 0 => #5, ... ]
    secureInsert(vector, 0);

    // vector_print(vector);

    // Free
    vector_free(vector);
}

/*
    Ecrire sur le terminal les erreurs en rouge
*/
void initStderr()
{
    fprintf(stderr, "\033[1;31m");
}

/*
    Ecrire sur le terminal les erreurs en noir
*/
void resetStderr()
{
    fprintf(stderr, "\033[0m");
}

int main(int argc, char const *argv[])
{
    // INIT TIME
    srand(time(NULL));

    // Erreurs en rouge
    initStderr();

    // Lancer des tests
    test();

    // Message ok en noir
    resetStderr();

    // Traitement valide
    printf("Pas d'erreurs !\n");

    return 0;
}
