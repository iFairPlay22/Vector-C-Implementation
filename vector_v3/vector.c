#include "vector.h"
#include <stdlib.h>

#define MIN_MALLOC 16
#define TRUE 1
#define FALSE 0

/*
    Retourne le maximum de a, b
*/
size_t max_size_t(size_t a, size_t b)
{
    return a < b ? b : a;
}

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
    if (!(0 <= i && i < p_vector->size))
    {
        printf("\nWarning: out of bounds\n\n");
        return TRUE;
    }

    return FALSE;
}

/*
    Alloue et retourne votre structure. 
    Le tableau dynamique contient n void *.
*/
s_vector *vector_alloc(size_t n, t_data_alloc d_alloc, t_data_free d_free, t_data_cpy d_copy, t_data_print d_print)
{
    // Vérifier que les valeurs passées en paramètre soient valides
    if (n < 0)
    {
        printf("Warning: n can't be negative");
        return NULL;
    }

    s_vector *vector = (s_vector *)malloc(sizeof(s_vector));

    // Initialisation des valeurs de vector
    vector->size = n;
    vector->capacity = max_size_t(MIN_MALLOC, n); // Règle 1
    vector->tab = (void **)malloc(vector->capacity * sizeof(void *));

    // Initialiser les pointeurs de fonction
    vector->d_alloc = d_alloc;
    vector->d_free = d_free;
    vector->d_copy = d_copy;
    vector->d_print = d_print;

    // Initialiser le tableau de void*
    for (int i = 0; i < n; i++)
        vector->tab[i] = vector->d_alloc();

    return vector;
}

/*
    Libère votre structure.
*/
void vector_free(s_vector *p_vector)
{
    // Vérifier que les valeurs passées en paramètre soient valides
    if (isNull(p_vector) == TRUE)
        return;

    if (p_vector->tab != NULL)
    {
        // Libérer en mémoire le contenu tu tableau de void*
        for (int i = 0; i < p_vector->size; i++)
            p_vector->d_free(p_vector->tab[i]);

        // Libérer en mémoire le tableau
        free(p_vector->tab);
        p_vector->tab = NULL;
    }

    // Libérer en mémoire la structure
    free(p_vector);
    p_vector = NULL;
}

/*
    Affecte la donnée v à l’index i de votre tableau dynamique.
*/
void vector_set(s_vector *p_vector, size_t i, void *v)
{
    // Vérifier que les valeurs passées en paramètre soient valides
    if (isNull(p_vector) == TRUE || isOutOfBounds(p_vector, i) == TRUE)
        return;

    // Faire une copie de l'objet v en position i
    p_vector->d_copy(p_vector->tab[i], v);
}

/*
    Retourne la donnée de l’index i.
*/
void vector_get(s_vector *p_vector, size_t i, void *p_data)
{
    // Vérifier que les valeurs passées en paramètre soient valides
    if (isNull(p_vector) == TRUE || isOutOfBounds(p_vector, i) == TRUE)
        return;

    // Mettre dans p_data une copie de l'objet stocké en position i
    p_vector->d_copy(p_data, p_vector->tab[i]);
}

/*
    Insère une nouvelle donnée à l’index i de votre tableau dynamique.
*/
void vector_insert(s_vector *p_vector, size_t i, void *v)
{
    // Vérifier que les valeurs passées en paramètre soient valides
    if (isNull(p_vector) == TRUE || (i != 0 && isOutOfBounds(p_vector, i - 1) == TRUE))
        return;

    void **tab;
    int mustFree = 0;

    if (p_vector->capacity <= p_vector->size)
    {
        // Malloc un nouveau tableau 2 fois plus grand
        p_vector->capacity *= 2; // Règle 2
        tab = (void **)malloc(p_vector->capacity * sizeof(void *));

        // Malloc les nouveaux éléments du tableau
        for (int i = p_vector->size; i < p_vector->capacity; i++)
            p_vector->tab[i] = p_vector->d_alloc();

        mustFree = 1;
    }
    else
    {
        // Pas de nécessité de faire un malloc
        tab = p_vector->tab;
    }

    p_vector->size++;

    // Récupérer les valeur du tableau d'index < i
    for (int index = 0; index < i; index++)
        tab[index] = p_vector->tab[index];

    // Décaler d'une position à droite les valeurs du tableau d'index i < index.
    for (int index = p_vector->size - 1; i < index; index--)
        tab[index] = p_vector->tab[index - 1];

    // Faire une copie de l'élément v en position i
    p_vector->tab[i] = p_vector->d_alloc();
    p_vector->d_copy(p_vector->tab[i], v);

    // Libérer en mémoire l'ancien tableau si besoin
    if (mustFree == 1)
        free(p_vector->tab);

    // Mettre à jour le tableau
    p_vector->tab = tab;
}

/*
    Supprime la donnée à l’index i de votre tableau dynamique.
*/
void vector_erase(s_vector *p_vector, size_t i)
{
    // Vérifier que les valeurs passées en paramètre soient valides
    if (isNull(p_vector) == TRUE || (i != 0 && isOutOfBounds(p_vector, i - 1) == TRUE))
        return;

    void **tab;
    int mustFree = 0;

    if (MIN_MALLOC < p_vector->capacity && p_vector->size <= p_vector->capacity / 4) // Règle 1
    {
        // Malloc un nouveau tableau 2 fois plus petit
        p_vector->capacity /= 2; // Règle 3
        tab = (void **)malloc(p_vector->capacity * sizeof(void *));
        mustFree = 1;
    }
    else
    {

        // Pas la nécessité de faire un malloc
        tab = p_vector->tab;
    }

    // On libère en mémoire l'élément i
    p_vector->d_free(p_vector->tab[i]);

    // On récupère les valeurs de position != i et on les décale à gauche si leur
    // position est telle que i < position
    for (int index = 0; index < p_vector->size; index++)
    {
        if (index == i)
            continue;
        else if (index < i)
            tab[index] = p_vector->tab[index];
        else
            tab[index - 1] = p_vector->tab[index];
    }

    // Libérer en mémoire l'ancien tableau si nécessaire
    if (mustFree == 1)
        free(p_vector->tab);

    // Mettre à jour le tableau
    p_vector->tab = tab;
    p_vector->size--;
}

/*
    Insère une nouvelle donnée à la fin de votre tableau dynamique.
*/
void vector_push_back(s_vector *p_vector, void *v)
{
    // Vérifier que les valeurs passées en paramètre soient valides
    if (isNull(p_vector) == TRUE)
        return;

    vector_insert(p_vector, p_vector->size, v);
}

/*
    Supprime la dernière donnée de votre tableau dynamique.
*/
void vector_pop_back(s_vector *p_vector)
{
    // Vérifier que les valeurs passées en paramètre soient valides
    if (isNull(p_vector) == TRUE)
        return;

    vector_erase(p_vector, p_vector->size - 1);
}

/*
    Supprime toutes les données de votre tableau dynamique.
*/
void vector_clear(s_vector *p_vector)
{
    // Vérifier que les valeurs passées en paramètre soient valides
    if (isNull(p_vector) == TRUE)
        return;

    if (p_vector->tab != NULL)
    {
        // Libérer en mémoire l'ensemble des éléments du tableau
        for (int i = 0; i < p_vector->size; i++)
            p_vector->d_free(p_vector->tab[i]);

        // Libérer en mémoire le tableau
        free(p_vector->tab);
    }

    p_vector->size = 0;
    p_vector->capacity = MIN_MALLOC; // Règle 1

    // Malloc le tableau avec le nombre minimum d'éléments
    p_vector->tab = (void **)malloc(p_vector->capacity * sizeof(void *));
}

/*
    Retourne un entier non nul si votre tableau dynamique est vide et zéro sinon.
*/
int vector_empty(s_vector *p_vector)
{
    // Vérifier que les valeurs passées en paramètre soient valides
    if (isNull(p_vector) == TRUE)
        return -1;

    return p_vector->size == 0 ? TRUE : FALSE;
}

/*
    Retourne le nombre d’élément stocker dans le tableau dynamique.
*/
size_t vector_size(s_vector *p_vector)
{
    // Vérifier que les valeurs passées en paramètre soient valides
    if (isNull(p_vector) == TRUE)
        return -1;

    return p_vector->size;
}

/*
    Affiche la structure.
*/
void vector_print(s_vector *p_vector)
{
    // Vérifier que les valeurs passées en paramètre soient valides
    if (isNull(p_vector) == TRUE)
        return;

    printf("s_vector(%ld) : ", p_vector->size);

    // Afficher un tableau vide
    if (p_vector->size == 0)
    {
        printf("[]\n");
        return;
    }

    // Afficher un tableau de taille non vide
    printf("[\n");

    for (int i = 0; i < p_vector->size; i++)
    {
        printf("\t");
        p_vector->d_print(p_vector->tab[i]);
    }

    printf("]\n");
}