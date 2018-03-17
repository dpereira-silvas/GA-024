#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

typedef struct lista Lista;

Lista*  lista_create(void);
Lista*  lista_createNo(Lista* l, char* nome, int matricula,char turma, float p1, float p2, float p3);
void lista_destroy(Lista* l);
void lista_print(Lista* l);
void lista_item_print(Lista* l);
int lista_itens_count(Lista* l);

Lista* lista_insere_ord(Lista* l, char* nome, int matricula,char turma, float p1, float p2, float p3);
Lista* lista_retira(Lista* l, int matricula);
Lista* lista_copia(Lista* l);


#endif // LISTAENCADEADA_H_INCLUDED
