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

int lista_borrar(lista_t* lista){
    if (!lista)
        return -1;

    if (lista->cantidad == 0)
        return -1;

    if (lista->cantidad == 1){
        free(lista->nodo_fin);
        lista->nodo_inicio = NULL;
        lista->nodo_fin = NULL;
        (lista->cantidad)--;
    }else{
        nodo_t* nodo = lista->nodo_inicio;
        size_t posicion = 0;

        (lista->cantidad)--;
        free(lista->nodo_fin);
        while(nodo != NULL){
            if ((posicion + 1) == lista->cantidad){
                //printf("Ante-ultimo elemento: %i, posicion: %li\n", *(int*)(nodo->elemento), posicion);
                lista->nodo_fin = nodo;
                lista->nodo_fin->siguiente = NULL;
                return 0;
            }
            (posicion)++;
            nodo = nodo->siguiente;
        }
    }

    return 0;
}

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){
    if (!lista)
        return -1;

    if (lista->cantidad == 0)   
        return -1;

    if ( (posicion > 0) && (posicion < (lista->cantidad-1)) ){ // Si no es ni el ultimo nodo ni el primero.
        nodo_t* nodo_auxiliar;
        nodo_t* nodo = lista->nodo_inicio;
        size_t indice = 0;

        while(nodo != NULL){
            if ((indice + 1) == posicion){
                //printf("Ante-ultimo elemento: %i, posicion: %li\n", *(int*)(nodo->elemento), posicion);
                nodo_auxiliar = nodo->siguiente;
                nodo->siguiente = nodo_auxiliar->siguiente;
                free(nodo_auxiliar);
                (lista->cantidad)--;

            }
            (indice)++;
            nodo = nodo->siguiente;
        }
    }else{
        // Si la posicion es 0 o la ultima. Hay que reasignar punteros de la lista.
        if (posicion == 0 && (lista->cantidad > 1)){ // Si la lista tuviese 1 elemento solo, directamente habria que borrar el ultimo elemento.
            //printf("entro aca\n");
            nodo_t* nodo_auxiliar;
            (lista->cantidad)--;
            nodo_auxiliar = lista->nodo_inicio;
            lista->nodo_inicio = lista->nodo_inicio->siguiente;
            free(nodo_auxiliar);

        }else{ // Aca deberia entrar si tiene mas de 1 elemento.
            lista_borrar(lista);
        }
    }
    //printf("paso por aca\n\n\n");
    return 0;
}


void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){
    if (!lista || posicion > lista->cantidad-1)
        return NULL;

    if (posicion == 0)
        return lista->nodo_inicio->elemento; 

    nodo_t* nodo_buscado;
    nodo_t* nodo = lista->nodo_inicio;
    size_t indice = 0;

    while(nodo != NULL){
        if ((indice + 1) == posicion){
            nodo_buscado = nodo->siguiente->elemento;
        }
        (indice)++;
        nodo = nodo->siguiente;
    }

    return nodo_buscado;
}

void* lista_ultimo(lista_t* lista){
    if(!lista || lista->cantidad == 0)
        return NULL;
    return lista->nodo_fin->elemento;
}

void* lista_primero(lista_t* lista){
    if(!lista || lista->cantidad == 0)
        return NULL;
    return lista->nodo_inicio->elemento;
}

bool lista_vacia(lista_t* lista){
    // printf("%s", es_vacia ? "true" : "false");
    if(lista == NULL || lista->cantidad == 0)
        return true;
    return false;
}

size_t lista_elementos(lista_t* lista){
    return lista->cantidad;
}


void liberar_nodos(nodo_t* nodo){
    if (!nodo) 
        return;
    if(nodo->siguiente)
        liberar_nodos(nodo->siguiente);

    free(nodo);
}

void lista_destruir(lista_t* lista){
    liberar_nodos(lista->nodo_inicio);
    free(lista);
}

/*----------PILAS-----------*/

int lista_apilar(lista_t* lista, void* elemento){
    return lista_insertar(lista, elemento);
}


int lista_desapilar(lista_t* lista){
    return lista_borrar(lista);
}

void* lista_tope(lista_t* lista){
    return lista_ultimo(lista);
}

/*----------COLAS-----------*/

int lista_encolar(lista_t* lista, void* elemento){
    return lista_insertar(lista, elemento);
}

int lista_desencolar(lista_t* lista){
    return lista_borrar_de_posicion(lista, 0);
}

/*--------ITERADORES---------*/

/*
 * Crea un iterador para una lista. El iterador creado es válido desde
 * el momento de su creación hasta que no haya mas elementos por
 * recorrer o se modifique la lista iterada (agregando o quitando
 * elementos de la lista). 
 *
 * Al momento de la creación, el iterador queda listo para devolver el
 * primer elemento utilizando lista_iterador_elemento_actual.
 *
 * Devuelve el puntero al iterador creado o NULL en caso de error.
 */
lista_iterador_t* lista_iterador_crear(lista_t* lista){
    if (!lista)
        return NULL;
    
    lista_iterador_t* iterador = malloc(sizeof(lista_iterador_t));
    if (!iterador)
        return NULL;
    iterador->lista = lista;
    iterador->corriente = lista->nodo_inicio;
    return iterador;

}

/*
 * Devuelve true si hay mas elementos sobre los cuales iterar o false
 * si no hay mas.
 */
bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){
    if (!iterador)
        return false;
    return iterador->corriente;
}

/*
 * Avanza el iterador al siguiente elemento.
 * Devuelve true si pudo avanzar el iterador o false en caso de
 * que no queden elementos o en caso de error.
 *
 * Una vez llegado al último elemento, si se invoca a
 * lista_iterador_elemento_actual, el resultado siempre será NULL.
 */
bool lista_iterador_avanzar(lista_iterador_t* iterador){
    if (!iterador || !(iterador->corriente))
        return false;
    
    iterador->corriente = iterador->corriente->siguiente;
    return iterador->corriente;
}

/*
 * Devuelve el elemento actual del iterador o NULL en caso de que no
 * exista dicho elemento o en caso de error.
 */
void* lista_iterador_elemento_actual(lista_iterador_t* iterador){

}

/*
 * Libera la memoria reservada por el iterador.
 */
void lista_iterador_destruir(lista_iterador_t* iterador){
    free(iterador);
}