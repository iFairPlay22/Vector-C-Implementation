#include <stdlib.h>
#include "my_struct.h"
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    // MALLOC
    my_struct *s1 = my_struct_alloc();
    my_struct_randoms_init(s1);

    my_struct *s2 = my_struct_alloc();
    my_struct_randoms_init(s2);

    my_struct *s3 = my_struct_alloc();

    // COPY
    my_struct_copy(s3, s2);

    // PRINT
    printf("s1 : ");
    my_struct_print(s1);

    printf("s2 : ");
    my_struct_print(s2);

    // printf("s3 : ");
    my_struct_print(s3);

    // CMP
    printf("my_struct_cmp(s1, s2) = %d\n", my_struct_cmp(s1, s2));
    printf("my_struct_cmp(s2, s3) = %d\n", my_struct_cmp(s2, s3));

    // FREE
    my_struct_free(s1);
    my_struct_free(s2);
    my_struct_free(s3);

    return 0;
}
