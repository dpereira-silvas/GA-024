#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

typedef struct lista Lista;
typedef struct noL No;

Lista*  lista_create(void);
No*  lista_createNo(void);
void lista_destroy(Lista* l);
void lista_print(Lista* l);
void lista_item_print(Lista* l);
int lista_itens_count(Lista* l);
Lista* lista_insert(Lista* l, int info);


#endif // LISTACIRCULAR_H_INCLUDED
