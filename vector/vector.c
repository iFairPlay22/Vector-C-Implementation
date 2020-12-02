#include "vector.h"
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/*
    Ecrit un warning si p_vector est NULL et renvoie FALSE, TRUE sinon
*/
int isNull(s_vector *p_vector)
{
    if (p_vector == NULL)
    {
        printf("\nWarning: can't be NULL\n\n");
        return TRUE;
    }
    return FALSE;
}

/*
    Ecrit un warning si l'index i n'est pas valable et renvoie FALSE, TRUE sinon
*/
int isOutOfBounds(s_vector *p_vector, size_t i)
{
    if (!(0 <= i && i < p_vector->length))
    {
        printf("\nWarning: out of bounds\n\n");
        return TRUE;
    }
    return FALSE;
}

/*
    Alloue et retourne votre structure. 
    Le tableau dynamique contient n double initialisés à 0.0.
*/
s_vector *vector_alloc(size_t n)
{
    if (n < 0)
    {
        printf("Warning: n can't be negative");
        return NULL;
    }

    s_vector *vector = (s_vector *)malloc(sizeof(s_vector));

    vector->tab = (double *)malloc(n * sizeof(double));
    vector->length = n;

    for (int i = 0; i < n; i++)
        vector->tab[i] = 0.0;

    return vector;
}

/*
    Libère votre structure.
*/
void vector_free(s_vector *p_vector)
{
    if (isNull(p_vector) == TRUE)
        return;

    free(p_vector->tab);
    p_vector->tab = NULL;

    free(p_vector);
    p_vector = NULL;
}

/*
    Affecte la donnée v à l’index i de votre tableau dynamique.
*/
void vector_set(s_vector *p_vector, size_t i, double v)
{
    if (isNull(p_vector) == TRUE || isOutOfBounds(p_vector, i) == TRUE)
        return;

    p_vector->tab[i] = v;
}

/*
    Retourne la donnée de l’index i.
*/
double vector_get(s_vector *p_vector, size_t i)
{
    if (isNull(p_vector) == TRUE || isOutOfBounds(p_vector, i) == TRUE)
        return -1;

    return p_vector->tab[i];
}

/*
    Insère une nouvelle donnée à l’index i de votre tableau dynamique.
*/
void vector_insert(s_vector *p_vector, size_t i, double v)
{
    if (isNull(p_vector) == TRUE || (i != 0 && isOutOfBounds(p_vector, i - 1) == TRUE))
        return;

    p_vector->length++;

    double *newTab = (double *)malloc(p_vector->length * sizeof(double));

    for (int index = 0; index < p_vector->length; index++)
    {
        if (index < i)
            newTab[index] = p_vector->tab[index];
        else if (index == i)
            newTab[index] = v;
        else
            newTab[index] = p_vector->tab[index - 1];
    }

    p_vector->tab = newTab;
}

/*
    Supprime la donnée à l’index i de votre tableau dynamique.
*/
void vector_erase(s_vector *p_vector, size_t i)
{
    if (isNull(p_vector) == TRUE || (i != 0 && isOutOfBounds(p_vector, i - 1) == TRUE))
        return;

    p_vector->length--;
    double *newTab = (double *)malloc(p_vector->length * sizeof(double));

    for (int index = 0; index < p_vector->length + 1; index++)
    {
        if (index == i)
            continue;
        else if (index < i)
            newTab[index] = p_vector->tab[index];
        else
            newTab[index - 1] = p_vector->tab[index];
    }

    p_vector->tab = newTab;
}

/*
    Insère une nouvelle donnée à la fin de votre tableau dynamique.
*/
void vector_push_back(s_vector *p_vector, double v)
{
    if (isNull(p_vector) == TRUE)
        return;

    vector_insert(p_vector, p_vector->length, v);
}

/*
    Supprime la dernière donnée de votre tableau dynamique.
*/
void vector_pop_back(s_vector *p_vector)
{
    if (isNull(p_vector) == TRUE)
        return;

    vector_erase(p_vector, p_vector->length);
}

/*
    Supprime toutes les données de votre tableau dynamique.
*/
void vector_clear(s_vector *p_vector)
{
    if (isNull(p_vector) == TRUE)
        return;

    free(p_vector->tab);
    p_vector->tab = NULL;

    p_vector->length = 0;
}

/*
    Retourne un entier non nul si votre tableau dynamique est vide et zéro sinon.
*/
int vector_empty(s_vector *p_vector)
{
    if (isNull(p_vector) == TRUE)
        return -1;

    return p_vector->length == 0 ? TRUE : FALSE;
}

/*
    Retourne le nombre d’élément stocker dans le tableau dynamique.
*/
size_t vector_size(s_vector *p_vector)
{
    if (isNull(p_vector) == TRUE)
        return -1;

    return p_vector->length;
}

/*
    Affiche la structure.
*/
void vector_print(s_vector *p_vector)
{
    if (isNull(p_vector) == TRUE)
        return;

    printf("s_vector(%d) : ", p_vector->length);

    if (p_vector->length == 0)
    {
        printf("[]\n");
        return;
    }

    printf("[%f", p_vector->tab[0]);

    for (int i = 1; i < p_vector->length; i++)
        printf(", %f", p_vector->tab[i]);

    printf("]\n");
}