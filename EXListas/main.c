#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main()
{

    Lista *lista  = lista_create();
    Lista *listaC = lista_create();
    //lista_print(lista);

    lista = lista_insere_ord(lista, "Diogo Pereira", 11311144,'A', 7.0, 6.5, 8);
    lista = lista_insere_ord(lista, "Diogo Pereira da silva", 11111111,'B', 6, 6,6);
    lista = lista_insere_ord(lista, "Diogo Pereira da silva Santos", 33333333,'C', 9, 9, 9);
    lista = lista_insere_ord(lista, "Diogo Pereira da silva Santos", 44444444,'C', 5, 5, 5);
    lista = lista_insere_ord(lista, "Diogo Pereira da silva Santos", 55555555,'C', 10, 10, 10);
    lista = lista_insere_ord(lista, "Diogo Pereira da silva Santos", 66666666,'C', 8.5, 8.5, 8.5);
    lista = lista_insere_ord(lista, "Diogo Pereira da silva Santos", 77777777,'C', 6, 6, 6);

    //lista_print(lista);
    printf("Quantidade de elementos - %d\n",lista_itens_count(lista));
    //getchar();

    lista = lista_retira(lista, 44444444);
    lista = lista_retira(lista, 55555555);
    lista = lista_retira(lista, 11311144);

    lista_print(lista);

    printf("Quantidade de elementos - %d\n",lista_itens_count(lista));

    listaC =  lista_copia(lista);

    printf("LIsta CC\n\n");

    lista_print(listaC );

    printf("Quantidade de elementos - %d\n",lista_itens_count(listaC));

    lista_destroy(lista);
    lista_destroy(listaC);
    listaC = NULL;
    lista  = NULL;

    return 0;
}
