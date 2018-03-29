#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

struct lista
{
  struct noL* head;
  struct noL* tail;
  int qtd;
};

struct noL
{
    int info;
    struct noL* next;
};

Lista*  lista_create(void)
{
  Lista *l = (Lista*) malloc(sizeof(Lista));
  l->head  = NULL;
  l->tail  = NULL;
  l->qtd   = 0;
  return l;
}

No*  lista_createNo(void)
{
      No *n = (No*) malloc(sizeof(No));
      return n;
}

void lista_destroy(Lista* l)
{
    No* aux;
    int i = 0;
    l->tail->next = NULL;

    if(l->head == NULL)
    {
        printf("Lista sem elementos\n\n");
    }
    else
    {

        aux = l->head;

        while(aux != NULL)
        {

            l->head = l->head->next;
            free(aux);
            aux = l->head;
            printf("limpo %d\n",++i);
        }
    }
}

Lista* lista_insert(Lista* l, int info)
{
      No* n =  lista_createNo();
      if(l->head == NULL)
      {
          n->next = n;
          l->head  = n;
          l->tail  = n;
          n->info = info;
      }
      else
      {
          n->next = l->head;
          l->tail->next = n;
          l->head  = n;
          n->info = info;
      }
      l->qtd++;



    return l;
}

void lista_print(Lista* l)
{

    No* aux = l->head;
    int i ;
    if(l->head == NULL)
    {
        printf("Lista sem elementos\n\n");
    }
    else
    {
        printf("Lista com %d elementos\n",l->qtd);
        for(i = 0; i < l->qtd; i++)
        {
            printf("No %d - info %d\n",i, aux->info);
            aux = aux->next;
        }
    }
}
