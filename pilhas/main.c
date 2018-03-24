#include <stdio.h>
#include <stdlib.h>

void concatena_pilhas (Pilha* p1, Pilha* p2);

int main()
{
    printf("Hello world!\n");
    return 0;
}


void concatena_pilhas (Pilha* p1, Pilha* p2)
{
   float a;

    a = pop(p2);
    concatena_pilhas (p1,p2);
    push(p1,a);

   /*
    Pilha* aux = cria(void);
    while(vazia (p2) !=1)
    {
        push(aux,pop(p2));
    }
    while(vazia (aux) !=1)
    {
        push(p1,pop(aux));
    }
  */
}
