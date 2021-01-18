#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void test2()
{
    s_vector *vector = vector_alloc(0);

    vector_print(vector); // []

    vector_insert(vector, 0, 400);

    vector_print(vector); // [400.000000]

    vector_insert(vector, 0, 500);

    vector_print(vector); // [500.000000, 400.000000]

    vector_insert(vector, 0, 600);

    vector_print(vector); // [600.000000, 500.000000, 400.000000]

    vector_erase(vector, 0);

    vector_print(vector); // [500.000000, 400.000000]

    vector_erase(vector, 1);

    vector_print(vector); // [500.000000]

    vector_clear(vector);

    vector_print(vector); // []

    vector_insert(vector, 0, 600);

    vector_print(vector); // [600.000000]

    vector_insert(vector, 1, 700);

    vector_print(vector); // [600.000000, 700.000000]

    for (int i = 0; i < 20; i++)
        vector_insert(vector, 1, 800);

    vector_print(vector); // [600.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 800.000000, 700.000000]

    for (int i = 0; i < 20; i++)
        vector_erase(vector, 1);

    vector_print(vector); // [600.000000, 700.000000]

    vector_free(vector);
}

void initStderr()
{
    fprintf(stderr, "\033[1;31m");
}

void resetStderr()
{
    fprintf(stderr, "\033[0m");
}

int main(int argc, char const *argv[])
{
    // test2();
    // return 1;

    initStderr();

    size_t length = 3;

    s_vector *vector = vector_alloc(length);

    for (int i = 0; i < length; i++)
    {
        if (vector_get(vector, i) != 0.0)
        {
            fprintf(stderr, "Erreur 1 : vector_alloc / vector_get\n");
            exit(1);
        }
    }

    int val = 1;

    for (int i = 0; i < length; i++)
    {
        vector_set(vector, i, val);
        if (vector_get(vector, i) != val)
        {
            fprintf(stderr, "Erreur 2 : vector_set\n");
            exit(2);
        }
    }

    int pos = 2;
    vector_insert(vector, pos, val + 3);

    if (vector_get(vector, pos) != val + 3 || vector_size(vector) != length + 1)
    {
        fprintf(stderr, "Erreur 3 : vector_insert / vector_size\n");
        exit(3);
    }
    vector_erase(vector, pos);

    if (vector_size(vector) != length)
    {
        fprintf(stderr, "Erreur 4 : vector_erase\n");
        exit(4);
    }

    for (int i = 0; i < length; i++)
    {
        if (vector_get(vector, i) != val)
        {
            fprintf(stderr, "Erreur 5 : vector_erase\n");
            exit(5);
        }
    }

    vector_push_back(vector, val + 2);
    if (vector_size(vector) != length + 1 || vector_get(vector, length) != val + 2)
    {
        fprintf(stderr, "Erreur 6 : vector_push_back\n");
        exit(6);
    }

    vector_pop_back(vector);
    if (vector_size(vector) != length || vector_get(vector, length - 1) != val)
    {
        fprintf(stderr, "Erreur 7 : vector_pop_back\n");
        exit(7);
    }

    for (int i = 0; i < length; i++)
    {
        if (vector_get(vector, i) != val)
        {
            fprintf(stderr, "Erreur 8 : vector_push_back / vector_pop_back\n");
            exit(8);
        }
    }

    if (vector_empty(vector))
    {
        fprintf(stderr, "Erreur 9 : vector_empty\n");
        exit(9);
    }

    vector_clear(vector);

    if (!vector_empty(vector))
    {
        fprintf(stderr, "Erreur 10 : vector_empty\n");
        exit(10);
    }

    vector_free(vector);

    resetStderr();

    printf("Pas d'erreurs !\n");

    return 0;
}
