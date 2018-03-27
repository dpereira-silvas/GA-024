#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

int main()
{
    Lista* l = lista_create();


    l = lista_insert(l,2);
    l = lista_insert(l,10);
    l = lista_insert(l,50);
    l = lista_insert(l,5);
    l = lista_insert(l,1);

    lista_print(l);
    lista_destroy(l);
    free(l);
    return 0;
}
