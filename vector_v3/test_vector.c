#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.h"
#include "../random/random.h"
#include "../my_struct/my_struct.h"

// "Cast" functions

void *my_struct_alloc2()
{
    my_struct_alloc();
}

void my_struct_free2(void *myStruct)
{
    my_struct_free((my_struct *)myStruct);
}

void my_struct_copy2(void *dest, void *src)
{
    my_struct_copy((my_struct *)dest, (my_struct *)src);
}

// Test

my_struct *randomStruct()
{
    my_struct *s1 = my_struct_alloc();
    my_struct_randoms_init(s1);
    return s1;
}

void printVectorAt(s_vector *vector, size_t i)
{
    my_struct *s1 = my_struct_alloc();

    vector_get(vector, i, (void *)s1);

    my_struct_print(s1);

    my_struct_free2(s1);
}

void test()
{
    s_vector *vector = vector_alloc(10, my_struct_alloc2, my_struct_free2, my_struct_copy2);

    my_struct *rs = randomStruct();
    // vector_insert(vector, 0, rs);
    my_struct_free(rs);

    // printVectorAt(vector, 0);

    // vector_insert(vector, 0, randomStruct());

    // vector_insert(vector, 0, randomStruct());

    // vector_erase(vector, 0);

    // vector_erase(vector, 1);

    // vector_clear(vector);

    // vector_insert(vector, 0, randomStruct());

    // vector_insert(vector, 1, randomStruct());

    // for (int i = 0; i < 20; i++)
    //     vector_insert(vector, 1, randomStruct());

    // for (int i = 0; i < 20; i++)
    //     vector_erase(vector, 1);

    vector_free(vector);
}

void initStderr()
{
    fprintf(stderr, "\033[1;31m");
}

void resetStderr()
{
    fprintf(stderr, "\033[0m");
}

int main(int argc, char const *argv[])
{
    // INIT TIME
    srand(time(NULL));

    initStderr();

    test();

    resetStderr();

    printf("Pas d'erreurs !\n");

    return 0;
}
