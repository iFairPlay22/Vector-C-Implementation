#include <stdio.h>

#ifndef __MY_STRUCT__
#define __MY_STRUCT__

typedef struct
{
    char *str;
    double nb;
} my_struct;

/*
    Alloue votre structure vide et la retourne.
*/
my_struct *my_struct_alloc();

/*
    Libère  votre  structure.
*/
void my_struct_free(my_struct *myStruct);

/*
    Initialise de manière aleatoire le contenu de votre structure.
*/
void my_struct_randoms_init(my_struct *myStruct);

/*
    Recopie le contenu de la structure src dans la structure dest.
*/
void my_struct_copy(my_struct *dest, my_struct *src);

/*
    Compare les structures et qui retourne :
    —  0 si s1 est identique à s2 ;
    —  1 si s1 dois être classe après s2 ;
    — -1 si s1 dois être classe avant s2 ;
*/
int my_struct_cmp(my_struct *s1, my_struct *s2);

/*
    Affiche le contenu de la structure dans la console
*/
void my_struct_print(my_struct *myStruct);

#endif
