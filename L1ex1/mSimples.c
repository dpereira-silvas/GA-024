#include <stdio.h>
#include <stdlib.h>
#include "mSimples.h"

struct matrixS
{
  int m, n;
  int *mat;

};

MatrixS* matrixS_create( int m, int n )
{
    MatrixS* ma = (MatrixS*) malloc(sizeof(MatrixS));
    ma->mat = (int*) malloc(m*n*sizeof(int));

    ma->m=m;
    ma->n=n;
    return ma;
}

void matrixS_destroy( MatrixS* m )
{
    free(m);
}

void matrixS_setelem( MatrixS* m, int x, int y, int elem )
{
    m->mat[x*matrixS_getcolumncount( m)+y] = elem;
}

int matrixS_getelem( MatrixS* m, int x, int y )
{
    return m->mat[x*matrixS_getcolumncount( m)+y];
}

int* matrixS_getmatrix( MatrixS* m )
{
    return m->mat;
}

int matrixS_getlinecount( MatrixS* m )
{
    return m->m;
}

int matrixS_getcolumncount( MatrixS* m )
{
    return m->n;
}

void matrixS_print( MatrixS* m )
{
    int i,j, k;
    k=0;
    j=0;
    for(i=0; i<matrixS_getlinecount( m )*matrixS_getcolumncount( m); i++)
    {
        if((i!=0) && (i%matrixS_getcolumncount( m) == 0))
        {
            printf("\n");
            k++;
            j=0;
        }
        printf("%d ",matrixS_getelem( m, k, j ));

        j++;

    }
}

int matrixS_identidade(int* mat, int n)
{
    int i,j;

    //verificando a diagonal
    // os elemento da diagonal são os que i==J
    // para acessar o elemento da diagonal basta ir nos indeces i*n+i para i=0...n-1
    for(i = 0; i < n; i++)
    {
        if(mat[i*n+i]!=1)
        {
            return 0;
        }
    }

    //verificando as outras entradas da matriz

    // indice para as colunas
    j=1;
    for(i = 1; i < ((n*n) - 1); i++)
    {
        //pulando a diagonal
        if(i == j*n+j)
        {
            // se for elemento da diagonal pula o a iteração
            j++;
            continue;
        }
        if(mat[i]!=0)
        {
            return 0;
        }
    }

    return 1;
}

int matrixS_triangular_superior(int* mat, int n)
{
    int i,j,k;

    // indice da coluna
    j=0;
    for(i=1; i<n; i++)
    {
        // Verifica o primeiro elemento de cada linha a partir da segunda
        if(mat[i*n] !=0)
        {
            return 0;
        }
        // para a linha 3 Verifica 2 elementos depois do primeiro
        // para a linha 4 Verifica 3 elementos depois do primeiro
        // e assim sucessivamente
        for(k=1; k<=j; k++)
        {
            if(mat[i*n+k] !=0)
            {
                return 0;
            }
        }
        j++;
    }
    return 1;
}

int matrixS_tridiagonal(int* mat, int n)
{
    int i,j,k;

    // indices para acompanhar em qual linha e coluna esta
    // linha
    k = 0;
    // coluna
    j = 0;
    for(i = 0; i < (n*n); i++)
    {
        // se i for diferente de zero e multiplo de n
        // isso significa que chegamos ao final da linha,
        // portanto incrementamos k (indice da linha) e zeramos o j (indice da coluna)
        if((i!=0) && (i%n == 0))
        {
            k++;
            j=0;
        }
        // condição para a matriz ser tridiagonal
        // k!=j   não está na diagonal principal
        // k!=j-1 não está na diagonal abaixo da principal
        // k!=j+1 não está na diagonal acima da principal
        // mat[k*n+j]!=0  o elemento que atende o 3 requisitos acima é diferente de zero
        if((k!=j) && (k!=j-1) && (k!=j+1) && (mat[k*n+j]!=0))
        {
            return 0;
        }
        // indice da coluna
        j++;

    }
    return 1;
}


float matrixS_produto_diagonal(int* mat, int n)
{
    int i;
    float produto = 1;

    // percorre apenas a diagonal
    for(i = 0; i < n; i++)
    {
        // os elemento da diagonal são os que i==J
        // para acessar o elemento da diagonal basta ir nos indeces i*n+i para i=0...n-1
        produto = produto * mat[i*n+i];

    }
    return produto;
}

float matrixS_soma_inferior(int* mat, int n)
{
    float soma = 0;
    int i,j,k;

    // indice da coluna
    j=0;
    for(i=1; i<n; i++)
    {
        // adiciona o primeiro elemento da segunda linha
        soma = soma + mat[i*n];

        // para a linha 3 adiciona 2 elementos
        // para a linha 4 adiciona 3 elementos
        // e assim sucessivamente
        for(k=1; k<=j; k++)
        {
            soma = soma + mat[i*n+k];
        }
        j++;
    }
    return soma;
}

void matrixS_teste(void)
{
    int i,j,dim,elem;
    //int mat[16]= {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};  //diagonal
    //int mat[16]= {1,1,1,1,0,1,1,1,0,0,1,1,0,0,0,1}; //triangular superior
    //int mat[16]= {1,1,0,0,1,1,1,0,0,1,1,1,0,0,1,1}; //tridiagonal
    srand(time(NULL));

    // Ordem da matriz
    printf("\nVetor Simples\n");
    printf("\nTamanho da Matriz: ");
    scanf("%d",&dim);

    MatrixS* mat = matrixS_create(dim,dim);

    for(i = 0; i <matrixS_getlinecount(mat); i++)
    {
        for(j = 0; j <matrixS_getcolumncount( mat); j++)
        {

            // preenchimento manual
            //printf("Digite um numero: ");
           // scanf("%d",&elem);
           //matrixS_setelem( mat, i, j, elem);
           //matrixP_setelem( mat, i, j, elem);

            // preenchimento aleatorio
            matrixS_setelem( mat, i, j, rand() % 2);
        }
    }

    matrixS_print(mat);

    if(matrixS_triangular_superior(matrixS_getmatrix(mat), matrixS_getcolumncount( mat)) == 1)
        printf("\nE triangular superior\n");
    else
        printf("\nNao e triangular superior\n");


    if(matrixS_identidade(matrixS_getmatrix(mat),matrixS_getcolumncount( mat)) == 1)
        printf("\nE uma Matriz Identidade\n");
    else
        printf("\nNao e uma Matriz Identidade\n");

    printf("\nSoma da diagonal = %f\n",matrixS_produto_diagonal(matrixS_getmatrix(mat), matrixS_getcolumncount( mat)));
    printf("\nSoma Inferior = %f\n",matrixS_soma_inferior(matrixS_getmatrix(mat), matrixS_getcolumncount( mat)));


    if(matrixS_tridiagonal(matrixS_getmatrix(mat), matrixS_getcolumncount( mat)) == 1)
    {
        printf("\nE uma Matriz Tridiagonal\n");
    }
    else
        printf("\nNao e uma Matriz Tridiagonal\n\n");

    matrixS_destroy(mat);
    mat=NULL;
}

