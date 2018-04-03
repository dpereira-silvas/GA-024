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

    matrix_setelem( &A, 2, 1, 3);
    matrix_setelem( &A, 2, 2, 4);

    lista_print(&A, 2, 2);
    lista_destroy(&A, 2, 2);
    free(A);
    return 0;
}
