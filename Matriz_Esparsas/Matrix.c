#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

struct noM
{
    struct noM *next;
    struct noM *below;
    int line;
    int column;
    float info;
};

struct matrix{

    struct noM *head;
    struct noM *tail_line;
    struct noM *tail_column;
};

struct matrix_crs{

  float *val;
  int *col_ind;
  int *row_ptr;
  int lines;
  int columns;
};

struct noM*  lista_createNo(void)
{
      struct noM *n = (struct noM*) malloc(sizeof(struct noM));
      return n;
}
/*
void lista_insert(Matrix **m)
{
      NoM* n =  lista_createNo();
      if((*m)->head == NULL)
      {
           n->next           = n;
           n->below          = n;
           n->line           = -1;
           n->column         = -1;
          (*m)->head         = n;
          (*m)->tail_line    = n;
          (*m)->tail_column  = n;

          //n->info  = info;
      }
      else
      {
          n->next       = (*m)->head ;
          l->tail->next = n;
          //l->head  = n; // para inserir no inicio
          l->tail       = n;   // para inserir no fim
          n->info       = info;
      }
      l->qtd++;
    //return l;
}
*/
void lista_create_headers(Matrix **m, int lines, int columms)
{
      int i;
      struct noM* n =  lista_createNo();
      if((*m)->head == NULL)
      {
           n->next           = n;
           n->below          = n;
           n->line           = -1;
           n->column         = -1;
          (*m)->head         = n;
          (*m)->tail_line    = n;
          (*m)->tail_column  = n;
           n->info           = 0.5;
      }

      for(i = 0; i < columms; i++)
      {
           n =  lista_createNo();
           n->next               = (*m)->head;
           (*m)->tail_line->next = n;
           (*m)->tail_line       = n;
           n->below              = n;
           n->line               = 0;
           n->column             = i;
           n->info               = 0.4;

      }
      for(i = 0;i < lines; i++)
      {
           n =  lista_createNo();
           n->below                 = (*m)->head;
           (*m)->tail_column->below = n;
           (*m)->tail_column        = n;
           n->next                  = n;
           n->line                  = i;
           n->column                = 0;
           n->info                  = 0.6;
      }
}


void lista_print(Matrix **m, int lines, int columms)
{
    struct noM* aux = (*m)->head, *head;
    int i,j ;
    printf(" head print %p\n", (*m)->head);
    printf("\n");
    if((*m) == NULL)
    {
        printf("Lista sem elementos\n\n");
    }
    else
    {
       aux  = aux->below;
       head = aux;
       aux  = head->next;
       for(i = 0; i < lines; i++)
       {
           for(j = 0; j < columms; j++)
           {
                printf("x = %d, y = %d, = info %f\n",aux->line,aux->column, aux->info);
                aux = aux->next;
           }
           printf("\n");
           head = head->below;
           aux = head->next;
       }
        printf("\n\n");

      /*
        printf("Lista das Colunas\n");
        for(i = 0; i <= columms; i++)
        {
            printf("No %d - info %f\n",i, aux->info);
            aux = aux->next;
        }
        printf("Lista das Linhas\n");
        aux = (*m)->head;
        for(i = 0; i <= lines; i++)
        {
            printf("No %d - info %f\n",i, aux->info);
            aux = aux->below;
        }
        */
    }
}

int matrix_create( Matrix** m )
{
    //int m = 2, n =2;
    //printf("m = %d",*m);
    //criar matriz
    *m                = (Matrix*) malloc(sizeof(Matrix));
    (*m)->head        = NULL;
    (*m)->tail_line   = NULL;
    (*m)->tail_column = NULL;

    lista_create_headers(m, 2, 2);
    printf("%p %p %p \n",(*m)->head,(*m)->tail_line,(*m)->tail_column);
return 0;
}

void lista_destroy(Matrix **m, int lines, int columms)
{
    struct noM* aux = (*m)->head, *aux2;
    int i ;

    if((*m) == NULL)
    {
        printf("Lista sem elementos\n\n");
    }
    else
    {   aux = aux->next;
        printf("Lista das Colunas\n");
        for(i = 0; i < columms; i++)
        {
            //printf("No %d - info %f\n",i, aux->info);
            aux2 = aux;
            aux  = aux->next;
            free(aux2);
            printf("liberou %p\n",aux2);
        }
        printf("Lista das Linhas\n");
        aux = (*m)->head->below;
        for(i = 0; i < lines; i++)
        {
            //printf("No %d - info %f\n",i, aux->info);
            aux2 = aux;
            aux  = aux->below;
            free(aux2);
            printf("liberou %p\n",aux2);
       }
       free((*m)->head);
       printf("liberou %p\n",(*m)->head);
    }
}


int matrix_setelem( Matrix** m, int x, int y, float elem )
{
    int i;
    struct noM  *aux = (*m)->head, *head, *anter;
    printf(" head des %p\n", (*m)->head);
    struct noM* n =  lista_createNo();
    //inserindo na lista da linha
    for(i = 0; i < x; i++)
    {
        aux = aux->below;
    }
    // guardando cabeçalho da linha
    head = aux;
    // verificando se a lista é vazia
    if(aux->next == head)
    {

        n->next       = aux;
        aux->next     = n;
        n->info       = elem;
        n->line       = x;
        n->column     = y;
    }
    else
    {
        anter = aux;
        aux = aux->next;
        while(aux != head)
        {
            if((aux->column > y) || (aux->column == -1))
            {
                  anter->next   = n;
                  n->next       = aux;
                  n->info       = elem;
                  n->line       = x;
                  n->column     = y;
                  break;
            }
            else
            {
              anter = aux;
              aux   = aux->next;
            }
        }
        anter->next   = n;
        n->next       = head;
        n->info       = elem;
        n->line       = x;
        n->column     = y;
    }
    //inserindo na lista da coluna
    aux = (*m)->head;
    for(i = 0; i < y; i++)
    {
        aux = aux->next;
    }
    // guardando cabeçalho da coluna
    head = aux;
    // verificando se a lista é vazia
    if(aux->below == head)
    {
        n->below       = aux;
        aux->below     = n;
        n->info        = elem;
    }
    else
    {
        anter = aux;
        aux = aux->below;
        while(aux != head)
        {
            if((aux->line > x) || (aux->line == -1))
            {
                  anter->below   = n;
                  n->below       = aux;
                  break;
            }
            else
            {
              anter = aux;
              aux   = aux->below;
            }
        }
        anter->below   = n;
        n->below       = head;
    }

    printf("x = %d, y = %d, Elem = %f\n",n->line,n->column,n->info);

    //lista_print(&m, 2, 2);
    return 0;
}

