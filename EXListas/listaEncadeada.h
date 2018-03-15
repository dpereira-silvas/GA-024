#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

typedef struct lista Lista;

Lista*  lista_create(void);
Lista* lista_show(int i);
Lista* insere_ord(Lista* l, char* nome, int matricula,char turma, float p1, float p2, float p3);


#endif // LISTAENCADEADA_H_INCLUDED
