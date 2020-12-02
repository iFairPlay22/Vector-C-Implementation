#include <stdio.h>

#ifndef __VECTOR__
#define __VECTOR__

typedef struct
{
    size_t length;
    double *tab;
} s_vector;

/*
    Alloue et retourne votre structure. 
    Le tableau dynamique contient n double initialisés à 0.0.
*/
s_vector *vector_alloc(size_t n);

/*
    Libère votre structure.
*/
void vector_free(s_vector *p_vector);

/*
    Affecte la donnée v à l’index i de votre tableau dynamique.
*/
void vector_set(s_vector *p_vector, size_t i, double v);

/*
    Retourne la donnée de l’index i.
*/
double vector_get(s_vector *p_vector, size_t i);

/*
    Insère une nouvelle donnée à l’index i de votre tableau dynamique.
*/
void vector_insert(s_vector *p_vector, size_t i, double v);

/*
    Supprime la donnée à l’index i de votre tableau dynamique.
*/
void vector_erase(s_vector *p_vector, size_t i);

/*
    Insère une nouvelle donnée à la fin de votre tableau dynamique.
*/
void vector_push_back(s_vector *p_vector, double v);

/*
    Supprime la dernière donnée de votre tableau dynamique.
*/
void vector_pop_back(s_vector *p_vector);

/*
    Supprime toutes les données de votre tableau dynamique.
*/
void vector_clear(s_vector *p_vector);

/*
    Retourne un entier non nul si votre tableau dynamique est vide et zéro sinon.
*/
int vector_empty(s_vector *p_vector);

/*
    Retourne le nombre d’élément stocker dans le tableau dynamique.
*/
size_t vector_size(s_vector *p_vector);

/*
    Affiche la structure.
*/
void vector_print(s_vector *p_vector);

#endif
