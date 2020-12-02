#include "random.h"
#include <stdlib.h>

/*
    Retourne  un  nombre aleatoire de type double compris entre a et b exclu.
*/
double random_double(double a, double b)
{
    double c = b - a;
    return a + (rand() / (RAND_MAX / (b - a)));
}

/*
    Retourne un nombre aleatoire de type float compris entre a et b exclu.
*/
float random_float(float a, float b)
{
    return (float)random_double(a, b);
}

/*
    Retourne un nombre aleatoire de type size_t compris entre a et b exclu.
*/
size_t random_size_t(size_t a, size_t b)
{
    return (size_t)random_double(a, b);
}

/*
    Retourne un nombre aleatoire de type int compris entre a et b exclu.
*/
int random_int(int a, int b)
{
    return (int)random_double(a, b);
}

/*
    Retourne un nombre aleatoire de unsigned char compris entre a et b exclu.
*/
unsigned char random_uchar(unsigned char a, unsigned char b)
{
    return (unsigned char)random_double(a, b);
}

/*
    Remplit la chaîne de caractère c de lettre majuscule aléatoire,
    n est la taille du tableau pointé par le pointeur c.
*/
void random_init_string(unsigned char *c, size_t n)
{
    for (int i = 0; i < n; i++)
        c[i] = random_int('A', 'Z');
}