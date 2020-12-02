#include "random.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    double N = 20;

    printf("Double :");
    for (int i = 0; i < N; i++)
        printf(" %f", random_double(0, N));
    printf("\n\n");

    printf("Float :");
    for (int i = 0; i < N; i++)
        printf(" %f", random_float(0, N));
    printf("\n\n");

    printf("Size_t :");
    for (int i = 0; i < N; i++)
        printf(" %ld", random_size_t(0, N));
    printf("\n\n");

    printf("Int :");
    for (int i = 0; i < N; i++)
        printf("%d ", random_int(0, N));
    printf("\n\n");

    printf("Uchar :");
    for (int i = 0; i < N; i++)
        printf(" %d", random_uchar(0, N));
    printf("\n\n");

    char *txt = (char *)malloc(N * sizeof(char));
    random_init_string(txt, N);
    printf("Char* : %s\n\n", txt);
    free(txt);

    return 0;
}
