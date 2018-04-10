#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef struct matrix Matrix;

struct noM*  matrix_createNo(void);
int matrix_create_headers(Matrix **m, int lines, int columms);
int matrix_create(Matrix** m );
int matrix_destroy(Matrix *m);
int matrix_transpose( const Matrix* m, Matrix** r );
int matrix_print(Matrix *m);
int matrix_multiply( const Matrix* m, const Matrix* n, Matrix** r );
int matrix_add( const Matrix* m, const Matrix* n, Matrix** r );
int matrix_setelem(Matrix* m, int x, int y, float elem );
int matrix_getelem( const Matrix* m, int x, int y, float *elem );


#endif // MATRIX_H_INCLUDED
