#include <stdio.h>
#include <stdlib.h>
#include "mPont.h"

struct matrixP
{
  int m, n;
  int **mat;

};

MatrixP* matrixP_create( int m, int n )
{
    int i,j;

    MatrixP *ma = (MatrixP*) malloc(sizeof(MatrixP));

    //float **mat; /* matriz como um vetor de ponteiros */

    ma->mat = (float**) malloc(m*sizeof(float*));

    for (i=0; i<m; i++)
    {
       ma->mat[i] = (float*) malloc(n*sizeof(float));
    }

    ma->m = m;
    ma->n = n;

return ma;
}



void matrixP_destroy( MatrixP* m )
{   int i;

      for (i=0; i<m->m; i++)
          free(m->mat[i]);
}

void matrixP_print( MatrixP* m )
{
   int i,j;
    for (i=0; i<m->m; i++)
    {
      for (j=0; j<m->n; j++)
      {
         printf("%d ",m->mat[i][j]);
      }
      printf("\n");
    }


}

int** matrixP_getmatrix( MatrixP* m )
{
    return m->mat;
}

matrixP_setelem( MatrixP* m, int x, int y, int elem )
{
  m->mat[x][y] = elem;
}

int matrixP_getelem( MatrixP* m, int x, int y )
{
  return m->mat[x][y];
}

int matrixP_getlinecount( MatrixP* m )
{
  return m->m;
}
int matrixP_getcolumncount( MatrixP* m )
{
  return m->n;
}

int matrixP_identidade(int** mat, int n)
{   int i,j;
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
          if((i==j) && (mat[i][j] != 1))
            return 0;
          if((i!=j) && (mat[i][j] != 0))
            return 0;

      }
    }

return 1;
}
int matrixP_triangular_superior(int** mat, int n)
{
  int i,j;
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
          if((i>j) && (mat[i][j] != 0))
             //printf("%d ",mat[i][j]);
            return 0;
      }
      //printf("\n");
    }

return 1;
}


int matrixP_tridiagonal(int** mat, int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
          if((i!=j) && (i!=j-1) && (i!=j+1) && (mat[i][j]!=0))
            return 0;
      }
    }

  return 1;
}

float matrixP_produto_diagonal(int** mat, int n)
{
    int i,j;
    float produto = 1;
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
          if(i==j)
            produto = produto * mat[i][j];
      }
    }
    return produto;
}


float matrixP_soma_inferior(int** mat, int n)
{
    int i,j;
    float soma = 0;
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
          if(i>j)
            soma = soma + mat[i][j];
      }
    }
    return soma;
}

void matrixP_teste(void)
{
    int i,j,dim,elem;
    //int mat[16]= {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};  //diagonal
    //int mat[16]= {1,1,1,1,0,1,1,1,0,0,1,1,0,0,0,1}; //triangular superior
    //int mat[16]= {1,1,0,0,1,1,1,0,0,1,1,1,0,0,1,1}; //tridiagonal
    srand(time(NULL));

    // Ordem da matriz
    printf("\nVetor de Ponteiros\n");
    printf("\nTamanho da Matriz: ");
    scanf("%d",&dim);

    MatrixP* mat = matrixP_create(dim,dim);

    for (i=0; i<dim; i++)
    {
      for (j=0; j<dim; j++)
      {
          // preenchimento manual
          //printf("Digite um numero: ");
          //scanf("%d",&elem);
          //matrixP_setelem( mat, i, j, elem);
          matrixP_setelem(mat,i,j,rand() % 2);
      }
    }

    matrixP_print(mat);

    if(matrixP_identidade(matrixP_getmatrix(mat),matrixP_getcolumncount( mat)) == 1)
        printf("\nE uma Matriz Identidade\n");
    else
        printf("\nNao e uma Matriz Identidade\n");

    if(matrixP_triangular_superior(matrixP_getmatrix(mat), matrixP_getcolumncount( mat)) == 1)
        printf("\nE triangular superior\n");
    else
        printf("\nNao e triangular superior\n");

    printf("\nProduto da diagonal = %f\n",matrixP_produto_diagonal(matrixP_getmatrix(mat), matrixP_getcolumncount( mat)));
    printf("\nSoma Inferior = %f\n",matrixP_soma_inferior(matrixP_getmatrix(mat), matrixP_getcolumncount( mat)));


    if(matrixP_tridiagonal(matrixP_getmatrix(mat), matrixP_getcolumncount( mat)) == 1)
    {
        printf("\nE uma Matriz Tridiagonal\n");
    }
    else
        printf("\nNao e uma Matriz Tridiagonal\n\n");

    matrixP_destroy( mat);
    mat = NULL;
}

