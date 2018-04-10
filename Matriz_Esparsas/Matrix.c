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

struct matrix
{
    int lines;
    int columns;
    struct noM *head;
    struct noM *tail_line;
    struct noM *tail_column;
};

struct noM*  matrix_createNo(void)
{
    struct noM *n = (struct noM*) malloc(sizeof(struct noM));
    return n;
}

int matrix_create_headers(Matrix **m, int lines, int columns)
{
    if((lines <= 0) || (columns <= 0))
    {
        return 1;
    }

    int i;
    struct noM* n;// =  matrix_createNo();
    // cria a cabeça das cabeças
    if((*m)->head == NULL)
    {
        n =  matrix_createNo();
        if(n == NULL)
        {
            return 1;
        }
        n->next           = n;
        n->below          = n;
        n->line           = -1;
        n->column         = -1;
        (*m)->head         = n;
        (*m)->tail_line    = n;
        (*m)->tail_column  = n;
        (*m)->lines        = lines;
        (*m)->columns      = columns;
        n->info           = 0;
    }
    // cria as cabeças das colunas
    for(i = 0; i < columns; i++)
    {
        n =  matrix_createNo();
        if(n == NULL)
        {
            return 1;
        }
        n->next               = (*m)->head;
        (*m)->tail_line->next = n;
        (*m)->tail_line       = n;
        n->below              = n;
        n->line               = -1;
        n->column             = i+1;
        n->info               = 0;

    }
    //cria a cabeça das linhas
    for(i = 0; i < lines; i++)
    {
        n =  matrix_createNo();
        if(n == NULL)
        {
            return 1;
        }
        n->below                 = (*m)->head;
        (*m)->tail_column->below = n;
        (*m)->tail_column        = n;
        n->next                  = n;
        n->line                  = i+1;
        n->column                = -1;
        n->info                  = 0;
    }
    return 0;
}

int matrix_print(Matrix *m)
{
    int i,j;
    float elem;
    if(m == NULL)
    {
        //printf("Lista sem elementos\n\n");
        return 1;
    }
    else
    {
        printf("%d %d\n",m->lines, m->columns);
        //fprintf( stderr, "%d %d\n",m->lines, m->columns);
        for(i = 1; i <= m->lines; i++)
        {
            for(j = 1; j <= m->columns; j++)
            {
                matrix_getelem(m, i,j, &elem );
                if(elem == 0)
                {
                    continue;
                }
                printf("%d %d %f\n",i,j, elem);
                //fprintf(stderr,"%d %d %f\n",i,j, elem);
            }
        }
        //fprintf(stderr,"%d\n",0);
        printf("%d\n",0);
    }
    return 0;
}

int matrix_create( Matrix** m )
{
    int   lines,columns,j,k;
    float v;
    //criar matriz
    *m                = (Matrix*) malloc(sizeof(Matrix));
    if((*m) == NULL)
    {
        return 1;
    }

    (*m)->head        = NULL;

    scanf("%d %d",&lines,&columns);
    if(!matrix_create_headers(m, lines, columns))
    {
        do
        {
            scanf("%d",&j);
            if(!(j == 0))
            {
                scanf(" %d %f",&k,&v);
                matrix_setelem( (*m), j, k, v);
            }
            else
                break;
        }
        while(1);
    }
    else
    {
        return 1;
    }
    return 0;
}

int matrix_destroy(Matrix *m)
{
    if(m == NULL)
    {
        //printf("Lista sem elementos\n\n");
        return 1;
    }
    else
    {
        struct noM* aux = m->head,*aux2, *head;
        int i,columms;
        head  = aux->below;
        //head = aux;

        do
        {
            //printf("%d Elementos na Linha\n",(int) aux->info);
            columms = (int) aux->info;
            for(i = 0; i <= columms; i++)
            {
                aux2 = aux;
                aux  = aux->next;
                free(aux2);
            }
            aux = head;
            head = head->below;
        }
        while(aux != m->head);
        free(m);

    }
    return 0;
}

int matrix_setelem( Matrix* m, int x, int y, float elem )
{
    if((m == NULL) || (x <= 0) || (y <= 0) || (x > m->lines) || (y > m->columns))
    {
        return 1;
    }

    int i;
    struct noM  *aux = m->head, *head, *anter;
    struct noM* n =  matrix_createNo();

    if(n == NULL)
    {
        return 1;
    }
    else
    {
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
            head->info   += 1;
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
                    head->info   += 1 ;
                    break;
                }
                anter = aux;
                aux   = aux->next;
            }
            if(aux == head)
            {
                anter->next   = n;
                n->next       = head;
                n->info       = elem;
                n->line       = x;
                n->column     = y;
                head->info   += 1 ;
            }
        }
        //inserindo na lista da coluna
        aux = m->head;
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
            head->info    += 1;
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
                    head->info    +=1;
                    break;
                }
                anter = aux;
                aux   = aux->below;
            }
            if(aux == head)
            {
                anter->below   = n;
                n->below       = head;
                head->info    +=1;
            }
        }
    }
    return 0;
}

int matrix_getelem( const Matrix* m, int x, int y, float *elem )
{
    if((m == NULL) ||(x <= 0) || (y <= 0) || (x > m->lines) || (y > m->columns))
    {
        return 1;
    }

    int i;
    struct noM  *aux = m->head, *head;
    for(i = 0; i < x; i++)
    {
        aux = aux->below;
    }
    // guardando cabeçalho da linha
    head = aux;
    aux = aux->next;
    // printf("linha %d\n",head->line);
    while(aux != head)
    {
        if(aux->column == y)
        {
            *elem = aux->info;
            return 0;
        }
        aux = aux->next;
    }
    *elem = 0;

    return 0;
}

int matrix_add( const Matrix* m, const Matrix* n, Matrix** r )
{
    if((m == NULL) || (n == NULL )|| (m->lines != n->lines) || (m->columns != n->columns))
    {
        *r = NULL;
        return 1;
    }
    int i,j;
    float elem1,elem2;
    *r                = (Matrix*) malloc(sizeof(Matrix));
    if((*r)== NULL)
    {
        (*r) = NULL;
        return 1;
    }
    else
    {
        (*r)->head         = NULL;

        if(!matrix_create_headers(r, m->lines, m->columns))
        {
            for(i = 1; i <= m->lines; i++)
            {
                for(j = 1; j <= m->columns; j++)
                {
                    matrix_getelem(m,i,j,&elem1);
                    matrix_getelem(n,i,j,&elem2);
                    if((elem1+elem2) != 0)
                    {
                        matrix_setelem( (*r), i, j, elem1+elem2);
                    }
                }
            }
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int matrix_multiply( const Matrix* m, const Matrix* n, Matrix** r )
{
    if(m == NULL || n == NULL)
    {
        return 1;
    }

    if(m->columns != n->lines)
    {
        (*r) = NULL;
        return 1;
    }

    int i,j,k;
    float elem1,elem2,soma;

    *r                = (Matrix*) malloc(sizeof(Matrix));
    if((*r)== NULL)
    {
        (*r) = NULL;
        return 1;
    }
    else
    {
        (*r)->head         = NULL;

        if(!matrix_create_headers(r, m->lines, n->columns))
        {
            for (i = 1; i <=  m->lines; i++)
            {
                for (j = 1; j <= n->columns; j++)
                {
                    soma = 0;
                    for (k = 1; k <= m->columns; k++)
                    {
                        matrix_getelem(m,i,k,&elem1);
                        matrix_getelem(n,k,j,&elem2);
                        soma += elem1 * elem2;
                    }
                    if(soma != 0)
                        matrix_setelem( (*r), i, j, soma);
                }
            }
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int matrix_transpose( const Matrix* m, Matrix** r )
{
    if(m == NULL)
    {
        (*r) = NULL;
        return 1;
    }

    int i,j;
    float elem;

    *r                = (Matrix*) malloc(sizeof(Matrix));
    if((*r)== NULL)
    {
        (*r) = NULL;
        return 1;
    }
    else
    {
        (*r)->head         = NULL;

        if(!matrix_create_headers(r, m->columns, m->lines))
        {

            for(i = 1; i <= m->lines; i++)
            {
                for(j = 1; j <= m->columns; j++)
                {
                    matrix_getelem(m,i,j,&elem);
                    matrix_setelem( (*r), j, i, elem);
                }
            }
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
