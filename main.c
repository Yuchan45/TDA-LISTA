#include "lista.h"
#include <stdio.h>
#include "pa2mm.h"

/*
Recibe una lista por parametro y la recorre, devolviendo el puntero de cada posicion.
 */
void recorrer_y_mostrar(lista_t* lista){
    nodo_t* sig;
    size_t posicion = 0;
    sig = lista->nodo_inicio;
    printf("\n-------ELEMENTOS EN LISTA-------\n");
    while(sig != NULL){
        printf("Puntero a elemento: %p, elemento: %i, posicion: %li\n", sig->elemento, *(int*)(sig->elemento), posicion);
        (posicion)++;
        sig = sig->siguiente;
    }

}


void probar_lista_crear(){
    lista_t* una_lista = NULL;

    pa2m_afirmar((una_lista=lista_crear()) != NULL, "Puedo crear una lista.");
    pa2m_afirmar((una_lista->nodo_inicio) == NULL, "Una lista se crea vacia. Con puntero de inicio = NULL.");
    pa2m_afirmar((una_lista->nodo_fin) == NULL, "Una lista se crea vacia. Con puntero de fin = NULL.");
    pa2m_afirmar((una_lista->cantidad) == 0, "Una lista se crea vacia. Con cantidad = 0.\n");

    lista_destruir(una_lista);
}

void probar_lista_insertar(){
    int dato_1 = 12;
    char dato_char = 'A';
    double dato_double = 20.1;

    lista_t* una_lista = lista_crear();

    pa2m_afirmar((lista_insertar(NULL, &dato_1)) != 0, "Insertar devuelve error si recibe una lista invalida (Lista = NULL).\n");

    printf(" - Inserto 1º elemento - \n");
    pa2m_afirmar((lista_insertar(una_lista, &dato_1)) == 0, "Insertar 1º valor (int) en una lista.");
    pa2m_afirmar((*(int*)una_lista->nodo_inicio->elemento) == dato_1, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((una_lista->cantidad) == 1, "Ahora el contador de cantidad es 1.");
    pa2m_afirmar((una_lista->nodo_inicio->elemento) == &dato_1, "El elemento del nodo de inicio ahora apunta al elemento ingresado.");
    pa2m_afirmar((una_lista->nodo_fin->elemento) == &dato_1, "El nodo de fin ahora apunta al elemento ingresado.");
    pa2m_afirmar(una_lista->nodo_inicio->elemento == una_lista->nodo_fin->elemento, "Como es la 1º insercion, el nodo fin y nodo inicio apuntan al mismo elemento.\n");

    printf(" - Inserto 2º elemento - \n");
    pa2m_afirmar((lista_insertar(una_lista, &dato_char)) == 0, "Insertar 2º (char) en una lista.");
    pa2m_afirmar((*(char*)una_lista->nodo_inicio->siguiente->elemento) == dato_char, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((una_lista->cantidad) == 2, "Ahora el contador de cantidad es 2.");
    pa2m_afirmar((una_lista->nodo_inicio->elemento) == &dato_1, "El elemento del nodo de inicio sigue siendo el primer dato ingresado.");
    pa2m_afirmar((una_lista->nodo_fin->elemento) == &dato_char, "El elemento del nodo de fin ahora es el ultimo elemento ingresado.");
    pa2m_afirmar(una_lista->nodo_inicio->elemento != una_lista->nodo_fin->elemento, "Como es la 2º insercion, el nodo inicio y nodo fin apuntan a distintos elementos.\n");

    printf(" - Inserto 3º elemento - \n");
    pa2m_afirmar((lista_insertar(una_lista, &dato_double)) == 0, "Insertar 3º valor (double) en una lista.");
    pa2m_afirmar((*(double*)una_lista->nodo_inicio->siguiente->siguiente->elemento) == dato_double, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((una_lista->cantidad) == 3, "Ahora el contador de cantidad es 2.");
    pa2m_afirmar((una_lista->nodo_inicio->elemento) == &dato_1, "El elemento del nodo de inicio sigue siendo el primer dato ingresado.");
    pa2m_afirmar((una_lista->nodo_fin->elemento) == &dato_double, "El elemento del nodo de fin ahora es el ultimo elemento ingresado.\n");

    lista_destruir(una_lista);

}

void probar_lista_insertar_en_posicion(){
    int dato_1 = 12, dato_2 = 15;
    char dato_char = 'A', dato_char_2 = 'Z';
    double dato_double = 20.1;
    //double dato_double_2 = 2.3;

    lista_t* lista = lista_crear();

    pa2m_afirmar(lista_insertar_en_posicion(NULL, &dato_1, 3) != 0, "La funcion devuelve error si recibe una lista invalida (Lista = NULL).\n");
    
    // Insertar en posicion NULL.
    
    printf(" - Inserto 1º elemento - \n");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &dato_1, 0) == 0, "Puedo insertar un valor (int) por posicion en una lista vacia."); //Funciona con pos = 0 o 1.
    pa2m_afirmar((*(int*)lista->nodo_inicio->elemento) == dato_1, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((lista->cantidad) == 1, "Ahora el contador de cantidad es 1.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &dato_1, "El nodo de inicio ahora contiene al dato ingresado.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &dato_1, "El nodo de fin ahora contiene al dato ingresado.");
    pa2m_afirmar(lista->nodo_inicio->elemento == lista->nodo_fin->elemento, "Como es la 1º insercion, el nodo fin y nodo inicio contienen al mismo elemento.\n");

    printf(" - Inserto 2º elemento - (posicion no valida) - \n");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &dato_2, 48) == 0, "Puedo insertar un valor (int) por posicion (invalida) en una lista.");
    pa2m_afirmar((*(int*)lista->nodo_inicio->siguiente->elemento) == dato_2, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((lista->cantidad) == 2, "Ahora el contador de cantidad es 2.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &dato_1, "El nodo de inicio sigue siendo el primer dato ingresado.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &dato_2, "El nodo de fin ahora contiene al ultimo dato ingresado.");
    pa2m_afirmar(lista->nodo_inicio->elemento != lista->nodo_fin->elemento, "Como es la 2º insercion, el nodo inicio y nodo fin contienen a distintos elementos.\n");

    printf(" - Inserto 3º elemento - (posicion 1, valida) - \n");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &dato_double, 1) == 0, "Puedo insertar un valor (double) en la posicion 1 de la lista.");
    pa2m_afirmar((*(double*)lista->nodo_inicio->siguiente->elemento) == dato_double, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((lista->cantidad) == 3, "Ahora el contador de cantidad es 3.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &dato_1, "El nodo de inicio sigue siendo el primer dato ingresado.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &dato_2, "El nodo de fin no cambia (porque inserte en la primer posicion), sigue conteniendo al nodo de antes.\n");

    printf(" - Inserto 4º elemento - (posicion 0, valida) - \n");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &dato_char, 0) == 0, "Puedo insertar un valor (char) en la posicion 0 de la lista.");
    pa2m_afirmar((*(char*)lista->nodo_inicio->elemento) == dato_char, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((lista->cantidad) == 4, "Ahora el contador de cantidad es 4.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &dato_char, "El nodo de inicio ahora contiene a este nodo.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &dato_2, "El nodo de fin no cambia (porque inserte en la posicion 0), sigue conteniendo al nodo de antes.\n");

    printf(" - Inserto 5º elemento - (posicion 0, valida) - \n");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &dato_char_2, 5) == 0, "Puedo insertar un valor (char) en la posicion maxima de la lista.");
    pa2m_afirmar((*(char*)lista->nodo_fin->elemento) == dato_char_2, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((lista->cantidad) == 5, "Ahora el contador de cantidad es 5.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &dato_char, "El nodo de inicio no cambia, sigue conteniendo al de antes.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &dato_char_2, "El nodo de fin ahora contiene a este nuevo nodo.\n");

    /*
    printf(" - Inserto 6º elemento - (posicion -1, no valida) - \n");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &dato_double_2, -1) == 0, "Puedo insertar un valor en la posicion 0 de la lista.");
    pa2m_afirmar((*(double*)lista->nodo_fin->elemento) == dato_double_2, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((lista->cantidad) == 6, "Ahora el contador de cantidad es 6.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &dato_char, "El nodo de inicio no cambia, sigue apuntando al de antes.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &dato_char_2, "El nodo de fin ahora apunta a este nuevo nodo.\n");
    */

    //free(lista->nodo_inicio->siguiente->siguiente->siguiente->siguiente->siguiente);

    
    lista_destruir(lista);

}

void probar_lista_es_vacia(){
    int dato_1 = 12, dato_2 = 15;
    lista_t* lista = lista_crear();   

    pa2m_afirmar(lista_vacia(NULL) == true, "Si la lista es NULL, la lista esta vacia."); 
    pa2m_afirmar(lista_vacia(lista) == true, "La lista esta vacia.\n"); 

    pa2m_afirmar((lista_insertar(lista, &dato_1)) == 0, "Inserto 1º valor en una lista.");
    pa2m_afirmar(lista_vacia(lista) == false, "La lista no esta vacia.");

    pa2m_afirmar((lista_insertar(lista, &dato_2)) == 0, "Inserto 2º valor en una lista.");
    pa2m_afirmar(lista_vacia(lista) == false, "La lista no esta vacia.\n");

    pa2m_afirmar(lista_borrar(lista) == 0, "Borro el ultimo elemento de la lista.");
    pa2m_afirmar(lista_vacia(lista) == false, "La lista aun no esta vacia.");

    pa2m_afirmar(lista_borrar(lista) == 0, "Borro el ultimo elemento de la lista.");
    pa2m_afirmar(lista_vacia(lista) == true, "La lista esta vacia.");

    lista_destruir(lista);
}

void probar_lista_borrar(){
    int a = 5, b = 1, c = 3;
    lista_t* lista = lista_crear();

    pa2m_afirmar((lista_insertar(lista, &a)) == 0, "Inserto 1º valor en una lista.");
    pa2m_afirmar((lista_insertar(lista, &b)) == 0, "Inserto 2º valor en una lista.");
    pa2m_afirmar((lista_insertar(lista, &c)) == 0, "Inserto 3º valor en una lista.");
    pa2m_afirmar((lista->cantidad) == 3, "El contador de cantidad deberia ser de 3.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &a, "El nodo de inicio contiene al 1º elemento.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &c, "El nodo de fin contiene al 3º elemento.\n");

    pa2m_afirmar(lista_borrar(lista) == 0, "Puedo borrar el ultimo elemento de la lista.");
    pa2m_afirmar((lista->cantidad) == 2, "El contador de cantidad deberia ser de 2.");
    pa2m_afirmar((lista->nodo_fin->siguiente) == NULL, "El ultimo nodo queda apuntando a NULL.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &a, "El nodo de inicio contiene al 1º elemento.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &b, "El nodo de fin ahora contiene al elemento del 2º nodo.\n");

    pa2m_afirmar(lista_borrar(lista) == 0, "Puedo borrar el ultimo elemento de la lista.");
    pa2m_afirmar((lista->cantidad) == 1, "El contador de cantidad deberia ser de 1.");
    pa2m_afirmar((lista->nodo_fin->siguiente) == NULL, "El ultimo nodo queda apuntando a NULL.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &a, "El nodo de inicio contiene al 1º elemento.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &a, "El nodo de fin ahora contiene al elemento del 1º nodo.\n");

    pa2m_afirmar(lista_borrar(lista) == 0, "Puedo borrar el ultimo elemento de la lista. La lista quedo vacia.");
    pa2m_afirmar((lista->cantidad) == 0, "El contador de cantidad deberia ser de 0.");
    pa2m_afirmar((lista->nodo_inicio) == NULL, "El nodo de inicio es NULL.");
    pa2m_afirmar((lista->nodo_fin) == NULL, "El nodo de fin ahora es NULL.\n");

    pa2m_afirmar(lista_borrar(lista) != 0, "Deberia devolver error en caso de querer borrar un elemento en una lista vacia.");

    free(lista);
}

void probar_lista_borrar_de_posicion(){
    //   1º,     2º,    3º,    4º,     5º ->orden de elementos.
    int a = 5, b = 1, c = 3, d = 15, e = 23;
    lista_t* lista = lista_crear();

    pa2m_afirmar((lista_insertar(lista, &a)) == 0, "Inserto 1º elemento en una lista.");
    pa2m_afirmar((lista_insertar(lista, &b)) == 0, "Inserto 2º elemento en una lista.");
    pa2m_afirmar((lista_insertar(lista, &c)) == 0, "Inserto 3º elemento en una lista.");
    pa2m_afirmar((lista_insertar(lista, &d)) == 0, "Inserto 4º elemento en una lista.");
    pa2m_afirmar((lista_insertar(lista, &e)) == 0, "Inserto 5º elemento en una lista.")
    pa2m_afirmar((lista->cantidad) == 5, "Cantidad deberia ser de 5.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &a, "El nodo de inicio contiene al 1º elemento.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &e, "El nodo de fin contiene al 5º elemento.\n");

    pa2m_afirmar(lista_borrar_de_posicion(NULL, 0) != 0, "Borrar por posicion pasando una lista invalida deberia fallar.\n");

    //   1º, 2º, 3º, 4º, 5º ->orden de elementos.
    //  [5, 1, 3, 15, 23]

    pa2m_afirmar(lista_borrar_de_posicion(lista, 0) == 0, "Puedo borrar el 1º elemento, osea posicion = 0, de la lista.");
    pa2m_afirmar((lista->cantidad) == 4, "Cantidad deberia ser de 4.");
    pa2m_afirmar((lista->nodo_fin->siguiente) == NULL, "El ultimo nodo queda apuntando a NULL.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &b, "Ahora el nodo de inicio deberia contener al 2º elemento.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &e, "El nodo de fin deberia seguir conteniendo al 5º elemento.\n");
    //  2º, 3º, 4º, 5º ->orden de elementos.
    // [1, 3, 15, 23]

    pa2m_afirmar(lista_borrar_de_posicion(lista, 3) == 0, "Puedo borrar el ULTIMO elemento pasando la posicion del ultimo elemento (posicion valida), osea posicion = 3");
    pa2m_afirmar((lista->cantidad) == 3, "Cantidad deberia ser de 3.");
    pa2m_afirmar((lista->nodo_fin->siguiente) == NULL, "El ultimo nodo queda apuntando a NULL.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &b, "El nodo de inicio deberia seguir conteniendo al 2º elemento.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &d, "El nodo de fin ahora deberia contener al 4º elemento.\n");
    //  2º, 3º, 4º ->orden de elementos.
    // [1, 3, 15]

    pa2m_afirmar(lista_borrar_de_posicion(lista, 1) == 0, "Puedo borrar el elemento en la posicion 1, osea posicion = 1");
    pa2m_afirmar((lista->cantidad) == 2, "Cantidad deberia ser de 2.");
    pa2m_afirmar((lista->nodo_fin->siguiente) == NULL, "El ultimo nodo queda apuntando a NULL.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &b, "El nodo de inicio deberia seguir conteniendo al 2º elemento.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &d, "El nodo de fin deberia seguir conteniendo al 4º elemento.\n");
    //  2º, 4º ->orden de elementos.
    // [1, 15]

    pa2m_afirmar(lista_borrar_de_posicion(lista, 300) == 0, "Puedo borrar el ULTIMO elemento (pasando una posicion invalida), osea posicion = 300.");
    pa2m_afirmar((lista->cantidad) == 1, "Cantidad deberia ser de 1.");
    pa2m_afirmar((lista->nodo_fin->siguiente) == NULL, "El ultimo nodo queda apuntando a NULL.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &b, "El nodo de inicio deberia seguir conteniendo al 2º elemento.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &b, "El nodo de fin ahora deberia contener al 2º elemento.\n");
    //  2º ->orden de elementos.
    // [1]

    pa2m_afirmar(lista_borrar_de_posicion(lista, 300) == 0, "Puedo borrar el elemento de la posicion 0, el ultimo que queda (pasando posicion = 0)");
    pa2m_afirmar((lista->cantidad) == 0, "Cantidad deberia ser de 0.");
    pa2m_afirmar((lista->nodo_inicio) == NULL, "El nodo de inicio es NULL.");
    pa2m_afirmar((lista->nodo_fin) == NULL, "El nodo de fin ahora es NULL.\n");

    pa2m_afirmar(lista_borrar_de_posicion(lista, 300) != 0, "Deberia devolver error en caso de querer borrar un elemento en una lista vacia.");

    free(lista);

}

void probar_lista_elemento_en_posicion(){
    int dato_int = 15;
    char dato_char = 'A';
    double dato_double = 3.14;
    lista_t* lista = lista_crear();

    pa2m_afirmar((lista_elemento_en_posicion(NULL, 2)) == 0, "Buscar elemento en posicion deberia fallar si paso por parametro NULL.\n");

    pa2m_afirmar((lista_insertar(lista, &dato_int)) == 0, "Inserte un valor (int) en la lista.");
    pa2m_afirmar((lista_insertar(lista, &dato_char)) == 0, "Inserte un valor (char) en la lista.");
    pa2m_afirmar((lista_insertar(lista, &dato_double)) == 0, "Inserte un valor (double) en la lista.\n");

    //pa2m_afirmar((lista_elemento_en_posicion(lista, -1)) == NULL, "Deberia fallar si no existe dicha posicion. (posicion negativa)");
    pa2m_afirmar((lista_elemento_en_posicion(lista, 10)) == NULL, "Deberia fallar si no existe dicha posicion. (posicion supera la cantidad de elementos en la lista).\n");

    pa2m_afirmar(*(int*)lista_elemento_en_posicion(lista, 0) == dato_int, "Devuelve el elemento correcto.");
    pa2m_afirmar(*(char*)lista_elemento_en_posicion(lista, 1) == dato_char, "Devuelve el elemento correcto.");
    pa2m_afirmar(*(double*)lista_elemento_en_posicion(lista, 2) == dato_double, "Devuelve el elemento correcto.");

    
    lista_destruir(lista);
}

void probar_lista_primero(){
    int dato_int = 15;
    char dato_char = 'A';
    lista_t* lista = lista_crear();

    pa2m_afirmar(lista_primero(NULL) == NULL, "La funcion deberia devolver NULL si le paso NULL.");
    pa2m_afirmar(lista_primero(lista) == NULL, "La funcion deberia devolver NULL si le paso una lista vacia o esta no tiene elementos.\n");

    pa2m_afirmar((lista_insertar(lista, &dato_int)) == 0, "Inserté un valor (int) en la lista.");
    pa2m_afirmar(*(int*)lista_primero(lista) == dato_int, "El ultimo valor deberia ser el (int) recientemente ingresado.");

    pa2m_afirmar((lista_insertar(lista, &dato_char)) == 0, "Inserté un valor (char) en la lista.");
    pa2m_afirmar(*(char*)lista_primero(lista) == dato_int, "El primer valor deberia seguir siendo el valor anterior (int).");


    lista_destruir(lista);
}

void probar_lista_ultimo(){
    int dato_int = 15;
    char dato_char = 'A';
    double dato_double = 3.14;
    lista_t* lista = lista_crear();

    pa2m_afirmar(lista_ultimo(NULL) == NULL, "La funcion deberia devolver NULL si le paso NULL.");
    pa2m_afirmar(lista_ultimo(lista) == NULL, "La funcion deberia devolver NULL si le paso una lista vacia o esta no tiene elementos.\n");

    pa2m_afirmar((lista_insertar(lista, &dato_int)) == 0, "Inserte un valor (int) en la lista.");
    pa2m_afirmar(*(int*)lista_ultimo(lista) == dato_int, "El ultimo valor deberia ser el (int) recientemente ingresado.");

    pa2m_afirmar((lista_insertar(lista, &dato_char)) == 0, "Inserte un valor (char) en la lista.");
    pa2m_afirmar(*(char*)lista_ultimo(lista) == dato_char, "El ultimo valor deberia ser el (char) recientemente ingresado.");

    pa2m_afirmar((lista_insertar(lista, &dato_double)) == 0, "Inserte un valor (double) en la lista.");
    pa2m_afirmar(*(double*)lista_ultimo(lista) == dato_double, "El ultimo valor deberia ser el (double) recientemente ingresado.");
    

    lista_destruir(lista);
} 

void probar_lista_elementos(){
    int a = 5, b = 1, c = 3;
    lista_t* lista = lista_crear();

    pa2m_afirmar(lista_elementos(NULL) == 0, "La lista deberia tener 0 elemento/s si le paso NULL.");
    pa2m_afirmar(lista_elementos(lista) == 0, "La lista deberia tener 0 elemento/s si le paso una lista vacia.\n");

    pa2m_afirmar((lista_insertar(lista, &a)) == 0, "Inserto 1º elemento en una lista.");
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista ahora deberia tener 1 elemento/s.");
    pa2m_afirmar((lista_insertar(lista, &b)) == 0, "Inserto 2º elemento en una lista.");
    pa2m_afirmar(lista_elementos(lista) == 2, "La lista ahora deberia tener 2 elemento/s.");
    pa2m_afirmar((lista_insertar(lista, &c)) == 0, "Inserto 3º elemento en una lista.");
    pa2m_afirmar(lista_elementos(lista) == 3, "La lista ahora deberia tener 3 elemento/s.");


    lista_destruir(lista);
}

bool mostrar_elemento(void* elemento, void* contador){
    if(elemento && contador)
        printf("Elemento %i: %c \n", (*(int*)contador)++, *(char*)elemento);
    return true;
}

void probar_operaciones_lista(){
    lista_t* lista = lista_crear();
    char a='a', b='b', c='c', d='d', w='w';
  
    lista_insertar(lista, &a);
    lista_insertar(lista, &c);
    lista_insertar_en_posicion(lista, &d, 100);
    lista_insertar_en_posicion(lista, &b, 1);
    lista_insertar_en_posicion(lista, &w, 3);
  
    lista_borrar_de_posicion(lista, 3);
    
    printf("Elementos en la lista: ");
    for(size_t i=0; i<lista_elementos(lista); i++)
        printf("%c ", *(char*)lista_elemento_en_posicion(lista, i));
    
    printf("\n\n");

    printf("Imprimo la lista usando el iterador externo: \n");
    lista_iterador_t* it = NULL;

    for(it = lista_iterador_crear(lista);
        lista_iterador_tiene_siguiente(it);
        lista_iterador_avanzar(it))
        printf("%c ", *(char*)lista_iterador_elemento_actual(it));
    printf("\n\n");

    lista_iterador_destruir(it);
    
    int contador=0;
    size_t elementos_recorridos = 0;
    printf("Imprimo la lista usando el iterador interno: \n");
    elementos_recorridos = lista_con_cada_elemento(lista, mostrar_elemento, (void*)&contador);

    printf("Recorri %lu elementos con el iterador interno y sume %i elementos\n", elementos_recorridos, contador);
    
    printf("\n");
    lista_destruir(lista);
}


void probar_operaciones_pila(){
    lista_t* pila = lista_crear();
    char* algo="somtirogla";

    for(int i=0; algo[i]!= 0; i++){
        printf("Apilo %c\n", algo[i]);
        lista_apilar(pila, &algo[i]);
    }

    printf("\nDesapilo y muestro los elementos apilados: ");
    while(!lista_vacia(pila)){
        printf("%c", *(char*)lista_tope(pila));
        lista_desapilar(pila);
    }
    printf("\n");
    lista_destruir(pila);
}

void probar_apilar(){
    int a = 1, b = 2, c = 3;
    lista_t* pila = lista_crear();

    pa2m_afirmar((lista_apilar(NULL, &a)) == -1, "Devuelve error si le paso una lista NULL.\n");

    pa2m_afirmar((lista_apilar(pila, &a)) == 0, "Puedo apilar el 1º elemento.");
    pa2m_afirmar(pila->cantidad == 1, "La pila tiene 1 elemento.");  
    pa2m_afirmar(lista_tope(pila) == &a, "El valor se apilo correctamente.\n");

    pa2m_afirmar((lista_apilar(pila, &b)) == 0, "Puedo apilar el 1º elemento.");
    pa2m_afirmar(pila->cantidad == 2, "La pila tiene 2 elementos.");  
    pa2m_afirmar(lista_tope(pila) == &b, "El valor se apilo correctamente.\n");   

    pa2m_afirmar((lista_apilar(pila, &c)) == 0, "Puedo apilar el 1º elemento.");
    pa2m_afirmar(pila->cantidad == 3, "La pila tiene 3 elementos.");  
    pa2m_afirmar(lista_tope(pila) == &c, "El valor se apilo correctamente."); 

    lista_destruir(pila);
}

void probar_desapilar(){
    int a = 1, b = 2;
    lista_t* pila = lista_crear();

    pa2m_afirmar((lista_desapilar(NULL)) == -1, "Devuelve error si intento desapilar en una pila NULL.\n");

    lista_apilar(pila, &a);
    lista_apilar(pila, &b);
    
    pa2m_afirmar(pila->cantidad == 2, "La pila tiene 2 elementos.");  
    pa2m_afirmar((lista_desapilar(pila)) == 0, "Puedo desapilar el 2º elemento.");
    pa2m_afirmar(*(int*)pila->nodo_inicio->elemento == a, "El elemento que queda en la pila es el 1º.");
    pa2m_afirmar(pila->cantidad == 1, "La pila tiene 1 elemento."); 
    pa2m_afirmar((lista_desapilar(pila)) == 0, "Puedo desapilar el 1º elemento.");
    pa2m_afirmar(pila->cantidad == 0, "La pila tiene 0 elementos. Esta vacia."); 
    pa2m_afirmar((lista_desapilar(pila)) == -1, "Desapilar en una pila vacia deberia fallar.");

    lista_destruir(pila);
}

void probar_operaciones_cola(){
    lista_t* cola = lista_crear();

    int numeros[]={1,2,3,4,5,6};

    for(size_t i=0; i<sizeof(numeros)/sizeof(int); i++){
        printf("Encolo %i\n", numeros[i]);
        lista_encolar(cola, &numeros[i]);
    }
  
    printf("\nDesencolo los numeros y los muestro: ");
    while(!lista_vacia(cola)){
        printf("%i ", *(int*)lista_primero(cola));
        lista_desencolar(cola);
    }
    printf("\n");
    lista_destruir(cola);
}

void probar_encolar(){
    int a = 1, b = 2, c = 3;
    lista_t* cola = lista_crear();

    pa2m_afirmar(lista_encolar(NULL, &a) == -1, "Encolar con una lista NULL deberia fallar (devuelve -1)."); 
    pa2m_afirmar(lista_encolar(cola, &a) == 0, "Puedo encolar el 1º elemento."); 
    pa2m_afirmar(cola->cantidad == 1, "La cola tiene 1 elemento/s."); 
    pa2m_afirmar(lista_primero(cola) == &a, "El 1º elemento de la cola es correcto.\n"); 

    pa2m_afirmar(lista_encolar(cola, &b) == 0, "Puedo encolar el 2º elemento."); 
    pa2m_afirmar(cola->cantidad == 2, "La cola tiene 2 elemento/s."); 
    pa2m_afirmar(lista_tope(cola) == &b, "El 2º elemento de la cola es correcto."); 

    pa2m_afirmar(lista_encolar(cola, &c) == 0, "Puedo encolar el 3º elemento."); 
    pa2m_afirmar(cola->cantidad == 3, "La cola tiene 3 elemento/s."); 
    pa2m_afirmar(lista_primero(cola) == &a, "El 1º elemento de la cola es correcto. La cola esta ordenada.\n");
    pa2m_afirmar(lista_tope(cola) == &c, "El 3º elemento de la cola es correcto."); 

    lista_destruir(cola);
}

void probar_desencolar(){
    int a = 1, b = 2;
    lista_t* cola = lista_crear();

    pa2m_afirmar(lista_desencolar(NULL) == -1, "Desncolar con una lista NULL deberia fallar (devuelve -1)."); 

    lista_encolar(cola, &a);
    lista_encolar(cola, &b);
    pa2m_afirmar(cola->cantidad == 2, "La cola tiene 2 elemento/s.\n");

    pa2m_afirmar(lista_desencolar(cola) == 0, "Puedo desencolar el 1º elemento."); 
    pa2m_afirmar(*(int*)cola->nodo_inicio->elemento == b, "El elemento que sale es el 1º. En la cola queda el 2º elemento."); 
    pa2m_afirmar(cola->cantidad == 1, "La cola tiene 1 elemento/s.\n");

    pa2m_afirmar(lista_desencolar(cola) == 0, "Puedo desencolar el 2º elemento.");
    pa2m_afirmar(cola->cantidad == 0, "La cola tiene 0 elemento/s."); 

    pa2m_afirmar(lista_desencolar(cola) == -1, "Desencolar deberia fallar si la cola tiene 0 elementos."); 


    lista_destruir(cola);

}

void probar_iterador_externo(){
    int a = 1, b = 2, c = 3;
    lista_t* lista = lista_crear();
    lista_iterador_t* iterador;
    lista_iterador_t* it;
    pa2m_afirmar((it = lista_iterador_crear(lista)) != NULL, "Puedo crear un iterador pasandole una lista vacia.");
    lista_insertar(lista, &a);
    lista_insertar(lista, &b);
    lista_insertar(lista, &c);

    pa2m_afirmar((iterador = lista_iterador_crear(NULL)) == NULL, "No deberia poder crear un iterador pasandole NULL.");
    pa2m_afirmar((iterador = lista_iterador_crear(lista)) != NULL, "Puedo crear un iterador pasandole una lista con elementos.");
    pa2m_afirmar(iterador->lista == lista, "El puntero lista del iterador se inicia apuntando a la lista pasada por parametro.");
    pa2m_afirmar(iterador->corriente == lista->nodo_inicio, "El puntero corriente se inicia apuntando al nodo_inicio de la lista pasada por parametro.\n");
    printf("Recorro la lista usando el iterador externo: \n");
    while (lista_iterador_tiene_siguiente(iterador)){
        printf("     -Elemento: %i\n", *(int*)(lista_iterador_elemento_actual(iterador)));
        lista_iterador_avanzar(iterador);
    }

    pa2m_afirmar(iterador->corriente == NULL, "Iterador->corriente es NULL cuando ya recorrio toda la lista.");
    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == false, "El iterador devuelve false, ya no tiene siguiente elemento al cual iterar.")

    lista_iterador_destruir(it);
    lista_iterador_destruir(iterador);
    lista_destruir(lista);
}

bool mostrar_hasta_c(void* elemento, void* contador){
    if(elemento && contador)
        printf("    -Elemento %i: %c \n", (*(int*)contador)++, *(char*)elemento);
    if (*(char*)elemento == 'c')
        return false;
    return true;
}

void probar_iterador_interno(){
    lista_t* lista = lista_crear();
    char a = 'a', b = 'b', c = 'c', d = 'd';
    int aux = 1;
    lista_insertar(lista, &a);
    lista_insertar(lista, &b);
    lista_insertar(lista, &c);
    lista_insertar(lista, &d);

    pa2m_afirmar(lista_con_cada_elemento(NULL, mostrar_elemento, (void*)&aux) == 0, "El iterador deberia devolver 0 si le paso una lista NULA.");
    pa2m_afirmar(lista_con_cada_elemento(lista, NULL, (void*)&aux) == 0, "El iterador deberia devolver 0 si le paso un puntero a funcion NULO.\n");
    //pa2m_afirmar(lista_con_cada_elemento(lista, mostrar_elemento, NULL == 0), "El iterador deberia devolver 0 si le paso un contexto (3º parametro) NULO.\n");
    aux = 1;
    printf("Imprimo la lista de inicio a fin pasando la funcion mostrar_elemento().\n");
    size_t elem_recorridos = lista_con_cada_elemento(lista, mostrar_elemento, (void*)&aux);
    pa2m_afirmar(elem_recorridos == 4, "El iterador recorrio toda la lista. Los 4 elementos.\n");

    aux = 1;
    printf("Imprimo la lista pasando la funcion mostrar_hasta_c(). Va a mostrar los elementos hasta encontrar una c.\n");
    elem_recorridos = lista_con_cada_elemento(lista, mostrar_hasta_c, (void*)&aux);
    pa2m_afirmar(aux == 4, "El iterador recorrio la lista. Los 3 elementos hasta c.");
    lista_destruir(lista);
}


int main(){

    /*       PRUEBAS       */

/*          LISTAS           */
    pa2m_nuevo_grupo("PROBAR_LISTA_CREAR");
    probar_lista_crear();

    pa2m_nuevo_grupo("PROBAR_LISTA_INSERTAR");
    probar_lista_insertar();

    pa2m_nuevo_grupo("PROBAR_LISTA_INSERTAR_EN_POSICION");
    probar_lista_insertar_en_posicion();

    pa2m_nuevo_grupo("PROBAR_LISTA_BORRAR");
    probar_lista_borrar();

    pa2m_nuevo_grupo("PROBAR_LISTA_BORRAR_DE_POSICION");
    probar_lista_borrar_de_posicion();

    pa2m_nuevo_grupo("PROBAR_LISTA_ELEMENTO_EN_POSICION");
    probar_lista_elemento_en_posicion();

    pa2m_nuevo_grupo("PROBAR_LISTA_ES_VACIA");
    probar_lista_es_vacia(); 

    pa2m_nuevo_grupo("PROBAR_LISTA_PRIMERO");
    probar_lista_primero();

    pa2m_nuevo_grupo("PROBAR_LISTA_ULTIMO");
    probar_lista_ultimo(); 

    pa2m_nuevo_grupo("PROBAR_LISTA_ELEMENTOS");
    probar_lista_elementos(); 

    pa2m_nuevo_grupo("PROBAR_OPERACIONES_LISTA");
    probar_operaciones_lista();

/*          PILAS           */
    pa2m_nuevo_grupo("PROBAR_APILAR");
    probar_apilar();

    pa2m_nuevo_grupo("PROBAR_DESAPILAR");
    probar_desapilar();

    pa2m_nuevo_grupo("PROBAR_OPERACIONES_DE_PILA");
    probar_operaciones_pila(); 

/*          COLAS           */
    pa2m_nuevo_grupo("PROBAR_ENCOLAR");
    probar_encolar();

    pa2m_nuevo_grupo("PROBAR_DESENCOLAR");
    probar_desencolar();

    pa2m_nuevo_grupo("PROBAR_OPERACIONES_DE_COLA");
    probar_operaciones_cola();

/*          ITERADORES           */
    pa2m_nuevo_grupo("PROBAR_ITERADOR_EXTERNO");
    probar_iterador_externo();

    pa2m_nuevo_grupo("PROBAR_ITERADOR_INTERNO");
    probar_iterador_interno();


    pa2m_mostrar_reporte();
    
/*   MAIN   */
/*
    int a = 1, b = 2, c = 3;

    lista_t* lista = lista_crear();
    lista_insertar(lista, &a);
    lista_insertar(lista, &b);
    lista_insertar(lista, &c);
    //lista_destruir_2(lista);
*/
}