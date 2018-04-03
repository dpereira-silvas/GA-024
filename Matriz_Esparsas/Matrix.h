#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

typedef struct matrix Matrix;

void lista_create_headers(Matrix **m, int lines, int columms);
int matrix_create( Matrix** m );
struct noM*  lista_createNo(void);
void lista_print(Matrix **m, int lines, int columms);
void lista_destroy(Matrix **m, int lines, int columms);
int matrix_setelem( Matrix** m, int x, int y, float elem );


#endif // MATRIX_H_INCLUDED
