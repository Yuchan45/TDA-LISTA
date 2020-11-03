#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

lista_t* lista_crear(){
    lista_t* lista = malloc(sizeof(lista_t));
    if (!lista){
        return NULL;
    }
    lista->nodo_inicio = NULL;
    lista->nodo_fin = NULL;
    lista->cantidad = 0;
    return lista;

}

/*
 * Inserta un elemento al final de la lista.
 * Devuelve 0 si pudo insertar o -1 si no pudo.
 */
int lista_insertar(lista_t* lista, void* elemento){
    if (!lista){
        printf("Lista es null.\n");
        return -1;
    }
    //printf("elemento pasado: %i\n", *(int*)elemento);
    nodo_t* p_nodo = malloc(sizeof(nodo_t));
    if (!p_nodo)
        return -1;

    if (lista->cantidad == 0){
        lista->nodo_inicio = p_nodo;
        lista->nodo_fin = p_nodo;

        lista->nodo_fin->elemento = elemento;
        lista->nodo_fin->siguiente = NULL;

    }else{
        lista->nodo_fin->siguiente = p_nodo; // Primero, antes de cambiar el puntero final, hago que el elemento del puntero final (osea el anterior) apunte al nuevo.
        lista->nodo_fin = p_nodo; // Ahora si actualizo el puntero final.

        lista->nodo_fin->elemento = elemento;
        lista->nodo_fin->siguiente = NULL;

    }

    (lista->cantidad)++;

    return 0;
}


void lista_destruir(lista_t* lista){
    free(lista);
}