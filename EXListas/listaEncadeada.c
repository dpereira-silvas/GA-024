#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaEncadeada.h"

struct lista
{
    char nome[81];
    int matricula;
    char turma;
    float p1;
    float p2;
    float p3;
    struct lista* prox;
};


Lista* lista_createNo(Lista* l, char* nome, int matricula,char turma, float p1, float p2, float p3)
{
    l            = (Lista*) malloc(sizeof(Lista));
    if(l == NULL)
    {
        printf("Espaco Insuficiente\n");
        return NULL;
    }
    else
    {
        strcpy(l->nome,nome);
        l->matricula = matricula;
        l->turma     = turma;
        l->p1        = p1;
        l->p2        = p2;
        l->p3        = p3;
        l->prox      = NULL;
    }
    return l;
}

Lista*  lista_create()
{
    return NULL;
}

void lista_destroy(Lista* l)
{
    Lista* ult, *anter;
    if(l == NULL)
    {
        printf("Lista sem elementos\n\n");
    }
    else
    {

        ult = l;
        while(ult != NULL)
        {
            anter = ult;
            ult   = ult->prox;
            free(anter);
        }
    }
}

Lista* lista_insere_ord(Lista* l, char* nome, int matricula,char turma, float p1, float p2, float p3)
{
    Lista* atual, *novo, *anter;
    int count = 0;

    if(l == NULL)
    {
        l = lista_createNo(l, nome, matricula,turma, p1, p2, p3);
    }
    else
    {
        anter = l;
        atual = l;
        while((atual != NULL) && (((atual->p1 + atual->p2 + atual->p3)/3) < ((p1 + p2 + p3)/3)))
        {
            anter  = atual;
            atual  = atual->prox;
            count++;
        }
        if(count == 0)
        {
            novo       = lista_createNo(l, nome, matricula,turma, p1, p2, p3);
            novo->prox = atual;
            l          = novo;
        }
        else
        {
            novo        = lista_createNo(l, nome, matricula,turma, p1, p2, p3);
            novo->prox  = atual;
            anter->prox = novo;
        }
    }

    return l;
}

Lista* lista_retira(Lista* l, int matricula)
{
    Lista* atual, *novo, *anter;
    int count = 0;

    if(l == NULL)
    {
        printf("Lista Vazia\n");
    }
    else
    {
        anter = l;
        atual = l;
        while((atual != NULL) && atual->matricula != matricula)
        {
            anter  = atual;
            atual  = atual->prox;
            count++;
        }
        if(atual == NULL)
        {
            printf("Aluno Nao Encontrado\n\n");
        }
        else
        {
            if(count == 0)
            {
                l = l->prox;
                free(atual);
            }
            else
            {
                anter->prox = atual->prox;
                free(atual);
            }
        }


    }
    return l;
}

void lista_item_print(Lista* l)
{
    printf("Nome - %s\nMatricula - %d\nTurma - %c\nNota1 - %f\nNota2 - %f\nNota2 - %f\n\n",l->nome,l->matricula,l->turma,l->p1,l->p2,l->p3);

}


void lista_print(Lista* l)
{
    Lista* ult;

    if(l == NULL)
    {
        printf("Lista sem elementos\n\n");

    }
    else
    {
        ult = l;
        while(ult != NULL)
        {
            printf("Nome - %s\nMatricula - %d\nTurma - %c\nNota1 - %f\nNota2 - %f\nNota2 - %f\n\n",ult->nome,ult->matricula,ult->turma,ult->p1,ult->p2,ult->p3);
            ult = ult->prox;
        }
    }


}

int lista_itens_count(Lista* l)
{
    Lista* ult;
    int qtd = 0;

    if(l == NULL)
    {
        printf("Lista sem elementos\n\n");
    }
    else
    {
        ult = l;
        while(ult != NULL)
        {
            ult = ult->prox;
            qtd++;
        }
    }

    return qtd;
}

Lista* lista_copia(Lista* l)
{
    Lista *c, *noC, *noL;

    c = lista_create();

    if(l == NULL)
    {
        printf("Lista sem elementos\n\n");
    }
    else
    {
        c   = lista_createNo(c, l->nome, l->matricula, l->turma, l->p1, l->p2, l->p3);
        noC = c;
        noL = l->prox;
        while(noL != NULL)
        {
            noC->prox = lista_createNo(noC, noL->nome, noL->matricula, noL->turma, noL->p1, noL->p2, noL->p3);
            noL       = noL->prox;
            noC       = noC->prox;
        }
    }
    return c;
}

