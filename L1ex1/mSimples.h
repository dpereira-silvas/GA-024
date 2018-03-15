#ifndef L1EX1_H_INCLUDED
#define L1EX1_H_INCLUDED

typedef struct matrixS MatrixS;


MatrixS* matrixS_create( int m, int n );
void matrixS_print( MatrixS* m );
void matrixS_destroy( MatrixS* m );
void matrixS_setelem( MatrixS* m, int x, int y, int elem );
int* matrixS_getmatrix( MatrixS* m );
int matrixS_getlinecount( MatrixS* m );
int matrixS_getcolumncount( MatrixS* m );
int matrixS_getelem( MatrixS* m, int x, int y );

int matrixS_identidade(int* mat, int n);
int matrixS_triangular_superior(int* mat, int n);
int matrixS_tridiagonal(int* mat, int n);
float matrixS_produto_diagonal(int* mat, int n);
float matrixS_soma_inferior(int* mat, int n);
void matrixS_teste(void);


#endif // L1EX1_H_INCLUDED
