#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "vector.h"

/*
    Retourne 1 si vector->tab contient les mêmes valeurs que tab
*/
int checkVector(s_vector *vector, double tab, ...)
{
    va_list l;
    va_start(l, tab);

    size_t size = vector_size(vector);
    double expectedV = tab;

    for (int i = 0; i < size; i++)
    {
        double getV = vector_get(vector, i);

        if (getV != expectedV)
        {
            printf("Warning : Invalid data for vector[%ld]\n", size);
            printf("\t - Expected : %f for index %d\n", expectedV, i);
            printf("\t - Get : %f\n", getV);
            return 0;
        }

        expectedV = va_arg(l, double);
    }

    va_end(l);

    return 1;
}

/*
    Affiche un message d'erreur si un test a échoué
*/
void failed(int testNb)
{
    printf("Test %d failed...\n", testNb);
    exit(testNb);
}

/*
    Lancer le test 1
*/
void test1()
{
    s_vector *vector = vector_alloc(0);

    vector_insert(vector, 0, 400);
    if (checkVector(vector, 400.0, -1) == 0)
        failed(1);

    vector_insert(vector, 0, 500);
    if (checkVector(vector, 500.0, 400.0, -1) == 0)
        failed(2);

    vector_insert(vector, 0, 600);
    if (checkVector(vector, 600.0, 500.0, 400.0, -1) == 0)
        failed(3);

    vector_erase(vector, 0);
    if (checkVector(vector, 500.0, 400.0, -1) == 0)
        failed(4);

    vector_erase(vector, 1);
    if (checkVector(vector, 500.0, -1) == 0)
        failed(5);

    vector_clear(vector);
    if (vector_size(vector) != 0)
        failed(6);

    vector_insert(vector, 0, 600);
    if (checkVector(vector, 600.0, -1) == 0)
        failed(7);

    vector_insert(vector, 1, 700);
    if (checkVector(vector, 600.0, 700.0, -1) == 0)
        failed(8);

    vector_clear(vector);

    vector_insert(vector, 0, 100);
    if (checkVector(vector, 100.0, -1) == 0)
        failed(9);

    for (int i = 0; i < 20; i++)
        vector_insert(vector, 1, 700);

    for (int i = 0; i < 20; i++)
        vector_erase(vector, 1);

    if (checkVector(vector, 100.0, -1) == 0)
        failed(10);

    vector_free(vector);
}

/*
    Lancer le test2
*/
void test2()
{
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
    // Erreurs en rouge
    initStderr();

    // Lancer les tests
    test1();
    test2();

    // Erreurs en noir
    resetStderr();

    // Traitement valide
    printf("Pas d'erreurs !\n");

    return 0;
}
