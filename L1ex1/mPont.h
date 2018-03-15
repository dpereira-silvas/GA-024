#ifndef MPONT_H_INCLUDED
#define MPONT_H_INCLUDED

typedef struct matrixP MatrixP;

MatrixP* matrixP_create( int m, int n );
void matrixP_print( MatrixP* m );
void matrixP_destroy( MatrixP* m );
void matrixP_setelem( MatrixP* m, int x, int y, int elem );
int** matrixP_getmatrix( MatrixP* m );
int matrixP_getlinecount( MatrixP* m );
int matrixP_getcolumncount( MatrixP* m );
int matrixP_getelem( MatrixP* m, int x, int y );

int matrixP_identidade(int** mat, int n);
int matrixP_triangular_superior(int** mat, int n);
int matrixP_tridiagonal(int** mat, int n);
float matrixP_produto_diagonal(int** mat, int n);
float matrixP_soma_inferior(int** mat, int n);
void matrixP_teste(void);

#endif // MPONT_H_INCLUDED
