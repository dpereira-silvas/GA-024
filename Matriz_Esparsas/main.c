#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main()
{
    Matrix *A;

    //printf("A = %d\n",A);
    int i = matrix_create( &A );

//    printf("%d %d %d \n",A->head,A->tail_line,A->tail_column);

    matrix_setelem( &A, 1, 2, 2);
    matrix_setelem( &A, 1, 1, 1);
    matrix_setelem( &A, 1, 3, 3);

    matrix_setelem( &A, 2, 3, 6);
    matrix_setelem( &A, 2, 1, 4);
    matrix_setelem( &A, 2, 2, 5);

    matrix_setelem( &A, 3, 1, 7);
    matrix_setelem( &A, 3, 2, 8);
    matrix_setelem( &A, 3, 3, 9);

    lista_print(&A, 3, 3);
    lista_destroy(&A, 3, 3);
    free(A);
    return 0;
}
