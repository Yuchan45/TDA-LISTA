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
        //printf("Lista es null.\n");
        return -1;
    }
    //printf("elemento pasado: %i\n", *(int*)elemento);
    nodo_t* p_nodo = malloc(sizeof(nodo_t));
    if (!p_nodo)
        return -1;

    if (lista->cantidad == 0){
        lista->nodo_inicio = p_nodo;
        lista->nodo_fin = p_nodo;
    }else{
        lista->nodo_fin->siguiente = p_nodo; // Primero, antes de cambiar el puntero final, hago que el elemento del puntero final (osea el anterior) apunte al nuevo.
        lista->nodo_fin = p_nodo; // Ahora si actualizo el puntero final.
    }

    lista->nodo_fin->elemento = elemento;
    lista->nodo_fin->siguiente = NULL;
    (lista->cantidad)++;

    return 0;
}

/*
 * Inserta un elemento en la posicion indicada, donde 0 es insertar
 * como primer elemento y 1 es insertar luego del primer elemento.  
 * En caso de no existir la posicion indicada, lo inserta al final.
 * Devuelve 0 si pudo insertar o -1 si no pudo.
 */

/*
Creo el nodo, le cargo el elemento y le pongo el puntero en NUll de base. Dsp recorro los nodos de la lista y utilizando un contador, me fijo cuando el contador
sea igual a la posicion recibida. 
 */
int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){
    if (!lista){
        return -1;
    }
    nodo_t* nodo_nuevo = malloc(sizeof(nodo_t));
    if (!nodo_nuevo)
        return -1;
    nodo_nuevo->elemento = elemento;
    nodo_nuevo->siguiente = NULL;


    if (posicion <= lista->cantidad){
        size_t indice = 0;
        nodo_t* nodo = lista->nodo_inicio;

        if(posicion == 0){ // Caso el nodo a agregar es en la primer posicion.
            nodo_nuevo->siguiente = lista->nodo_inicio;
            lista->nodo_inicio = nodo_nuevo;
            if (lista->cantidad == 0) // Si la lista esta vacia (cantidad = 0) y el usuario te pasa la posicion 0.
                lista->nodo_fin = nodo_nuevo;
            (lista->cantidad)++;
            return 0;
        }
        
        if(posicion == lista->cantidad){ // Caso nodo a agregar es en la ultima posicion.
            lista->nodo_fin->siguiente = nodo_nuevo;
            lista->nodo_fin = nodo_nuevo;
            (lista->cantidad)++;
            return 0;
        }
        
        while(nodo != NULL){ // Caso que el nodo a agregar es uno de los del medio.
            if ((indice + 1) == posicion){
                nodo_nuevo->siguiente = nodo->siguiente;
                nodo->siguiente = nodo_nuevo;
                (lista->cantidad)++;
            }
            //printf("Puntero a elemento: %p, elemento: %c, indice: %li\n", nodo->elemento, *(char*)(nodo->elemento), indice);
            (indice)++;
            nodo = nodo->siguiente;
        }

    }else{ // Si son posiciones invalidas (negativas o exceden las posiciones ya ubicadas.)

        if (lista->cantidad == 0){ // Si la lista esta vacia.
            lista->nodo_inicio = nodo_nuevo;
            lista->nodo_fin = nodo_nuevo;
            (lista->cantidad)++;
        }else{ // Si la lista ya tiene elementos.
            lista->nodo_fin->siguiente = nodo_nuevo; // Primero, antes de cambiar el puntero final, hago que el elemento del puntero final (osea el anterior) apunte al nuevo.
            lista->nodo_fin = nodo_nuevo; // Ahora si actualizo el puntero final.
            lista->nodo_fin->siguiente = NULL;
            (lista->cantidad)++;
        }
    }

    return 0;
}

/* 
 * Devuelve el último elemento de la lista o NULL si la lista se
 * encuentra vacía.
 */
void* lista_ultimo(lista_t* lista){
    if(!lista)
        return NULL;

    nodo_t* nodo = lista->nodo_inicio;

    while(nodo != NULL){
        if(nodo->siguiente == NULL){
            //printf("ULTIMO elemento: %i, posicion: %li\n", *(int*)(nodo->elemento), posicion);
            return nodo->elemento;
        }
        nodo = nodo->siguiente;
    }

}


void lista_destruir(lista_t* lista){
    free(lista);
}