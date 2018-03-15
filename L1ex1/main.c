#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mSimples.h"
#include "mPont.h"
int main()
{
    
	int op;
    //int mat[16]= {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};  //diagonal
    //int mat[16]= {1,1,1,1,0,1,1,1,0,0,1,1,0,0,0,1}; //triangular superior
    //int mat[16]= {1,1,0,0,1,1,1,0,0,1,1,1,0,0,1,1}; //tridiagonal
    printf("\nVetor Simples - 1, Vetor de Ponteiros 2\n\n ");
    scanf("%d",&op);

    switch(op)
    {
      case 1:
          matrixS_teste();
          break;
      case 2:
          matrixP_teste();
          break;
      default:
        printf("\n\n\Opcao invalida\n");
    }
    return 0;
}
