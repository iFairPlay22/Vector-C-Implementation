#include <stdio.h>

#ifndef __VECTOR3__
#define __VECTOR3__
/*
    Règles : 
        1. 16 <= capacity
        2. Lors de l’ajout d’un ́element, si capacity = size alors capacity *= 2
        3. Lors de la suppression d’un  ́element, si size <= capacity / 4, alors capacity /= 2
*/

/*
    Permet d’allouer une donnée
*/
typedef void *(*t_data_alloc)();

/*
    Permet de libérer une donnée
*/
typedef void (*t_data_free)(void *p_data);

/*
    Permet de faire une copie de la donnee p_data_src vers p_data_dst
*/
typedef void (*t_data_cpy)(void *p_data_dst, void *p_data_src);

/*
    Structure s_vector
*/
typedef struct
{
    size_t capacity; // Nombre d’élements réferencés dans la structure (éléments)
    size_t size;     // Nombre d’élements référencables dans la structure (malloc)
    void **tab;

    // Pointeurs de fonction
    t_data_alloc d_alloc;
    t_data_free d_free;
    t_data_cpy d_copy;

} s_vector;

/*
    Alloue et retourne votre structure. 
    Le tableau dynamique contient n void *.
*/
s_vector *vector_alloc(size_t n, t_data_alloc d_alloc, t_data_free d_free, t_data_cpy d_copy);

/*
    Libère votre structure.
*/
void vector_free(s_vector *p_vector);

/*
    Affecte la donnée v à l’index i de votre tableau dynamique.
*/
void vector_set(s_vector *p_vector, size_t i, void *v);

/*
    Retourne la donnée de l’index i.
*/
void *vector_get(s_vector *p_vector, size_t i, void *p_data);

/*
    Insère une nouvelle donnée à l’index i de votre tableau dynamique.
*/
void vector_insert(s_vector *p_vector, size_t i, void *v);

/*
    Supprime la donnée à l’index i de votre tableau dynamique.
*/
void vector_erase(s_vector *p_vector, size_t i);

/*
    Insère une nouvelle donnée à la fin de votre tableau dynamique.
*/
void vector_push_back(s_vector *p_vector, void *v);

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
