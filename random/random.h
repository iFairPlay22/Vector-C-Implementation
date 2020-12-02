#include <stdio.h>

#ifndef __RANDOM__
#define __RANDOM__

/*
    Retourne  un  nombre aleatoire de type double compris entre a et b exclu.
*/
double random_double(double a, double b);

/*
    Retourne un nombre aleatoire de type float compris entre a et b exclu.
*/
float random_float(float a, float b);

/*
    Retourne un nombre aleatoire de type size_t compris entre a et b exclu.
*/
size_t random_size_t(size_t a, size_t b);

/*
    Retourne un nombre aleatoire de type int compris entre a et b exclu.
*/
int random_int(int a, int b);

/*
    Retourne un nombre aleatoire de uchar int compris entre a et b exclu.
*/
unsigned char random_uchar(unsigned char a, unsigned char b);

/*
    Remplit la chaîne de caractère c de lettre majuscule aléatoire,
    n est la taille du tableau point e par le pointeur c.
*/
void random_init_string(unsigned char *c, size_t n);

#endif
