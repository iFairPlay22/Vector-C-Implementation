#include "my_struct.h"
#include "../random/random.h"
#include <stdlib.h>
#include <string.h>

/*
    Alloue votre structure vide et la retourne.
*/
my_struct *my_struct_alloc()
{
    my_struct *myStruct = (my_struct *)malloc(sizeof(my_struct));

    myStruct->str = NULL;
    myStruct->nb = 0;

    return myStruct;
}

/*
    Libère  votre  structure.
*/
void my_struct_free(my_struct *myStruct)
{
    if (myStruct == NULL)
        return;

    if (myStruct->str != NULL)
        free(myStruct->str);

    free(myStruct);
}

/*
    Initialise de manière aleatoire le contenu de votre structure.
*/
void my_struct_randoms_init(my_struct *myStruct)
{
    if (myStruct == NULL)
        return;

    myStruct->nb = random_int(0, 100);

    int randomSize = random_int(5, 10);
    myStruct->str = (char *)malloc(randomSize * sizeof(char));
    random_init_string(myStruct->str, randomSize);
}

/*
    Recopie le contenu de la structure src dans la structure dest.
*/
void my_struct_copy(my_struct *dest, my_struct *src)
{
    if (src == NULL)
    {
        dest = NULL;
        return;
    }

    dest->nb = src->nb;

    if (dest->str != NULL)
    {
        free(dest->str);
    }

    if (src->str == NULL)
    {
        dest->str = NULL;
    }
    else
    {
        dest->str = (char *)malloc((strlen(src->str) + 1) * sizeof(char));
        strcpy(dest->str, src->str);
    }
}

/*
    Convertit un char masjuscule en minuscule
*/
char _toLowerCase(char c)
{
    return 'A' <= c && c <= 'Z' ? c - 'A' + 'a' : c;
}

/*
    Compare deux chaines de carctères par ordre lexicographique
*/
int _str_cmp(char *s1, char *s2)
{

    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0')
    {

        char c1 = _toLowerCase(s1[i]);
        char c2 = _toLowerCase(s2[i]);

        if (c1 < c2)
            return 1;

        if (c2 < c1)
            return 0;

        i++;
    }

    if (s1[i] == '\0' && s2[i] != '\0')
    {
        return 1;
    }

    return 0;
}

/*
    Compare les structures et retourne :
    —  0 si vectorA est identique à vectorB ;
    —  1 si vectorA dois être classe après vectorB ;
    — -1 si vectorA dois être classe avant vectorB ;
*/
int my_struct_cmp(my_struct *s1, my_struct *s2)
{
    if (s1 == NULL || s2 == NULL)
    {
        printf("NullPointerException...\n");
        exit(1);
    }

    // Comparaison par rapport au nombre
    if (s1->nb < s2->nb)
        return -1;
    else if (s2->nb < s1->nb)
        return 1;

    // Comparaison par rapport au str
    return _str_cmp(s1->str, s2->str);
}

/*
    Affiche le contenu de la structure dans la console
*/
void my_struct_print(my_struct *myStruct)
{
    if (myStruct == NULL)
        return;

    printf("my_struct(\"%s\", %f)\n", myStruct->str, myStruct->nb);
}