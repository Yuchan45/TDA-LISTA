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

void liberar_nodos(lista_t* lista){
    size_t numero_de_nodos= lista->cantidad;

    for (int i = (int)numero_de_nodos - 1; i >= 0; i--){
        printf("%i", i);
    }

}

void probar_lista_insertar(){
    int dato_1 = 12;
    char dato_char = 'A';
    double dato_double = 20.1;

    lista_t* una_lista = NULL;

    pa2m_afirmar((una_lista=lista_crear()) != NULL, "Puedo crear una lista.");
    pa2m_afirmar((una_lista->nodo_inicio) == NULL, "Una lista se crea vacia. Con puntero de inicio = NULL.");
    pa2m_afirmar((una_lista->nodo_fin) == NULL, "Una lista se crea vacia. Con puntero de fin = NULL.");
    pa2m_afirmar((una_lista->cantidad) == 0, "Una lista se crea vacia. Con cantidad = 0.\n");

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

    free(una_lista->nodo_fin);
    free(una_lista->nodo_inicio->siguiente);
    free(una_lista->nodo_inicio);
    lista_destruir(una_lista);

}

void probar_lista_insertar_en_posicion(){
    int dato_1 = 12, dato_2 = 15;
    char dato_char = 'A', dato_char_2 = 'Z';
    double dato_double = 20.1;
    //double dato_double_2 = 2.3;

    lista_t* lista = lista_crear();

    pa2m_afirmar(lista_insertar_en_posicion(NULL, &dato_1, 3) != 0, "La funcion devuelve error si recibe una lista invalida (Lista = NULL).\n");
    
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

    free(lista->nodo_inicio->siguiente->siguiente->siguiente->siguiente);
    free(lista->nodo_inicio->siguiente->siguiente->siguiente);
    free(lista->nodo_inicio->siguiente->siguiente);
    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio);
    lista_destruir(lista);

}

void probar_lista_es_vacia(){
    //1 = true, 0 = false.
    int dato_1 = 12, dato_2 = 15;
    lista_t* lista = lista_crear();   

    pa2m_afirmar(lista_vacia(NULL) == 1, "Si la lista es NULL, la lista esta vacia."); 
    pa2m_afirmar(lista_vacia(lista) == 1, "La lista esta vacia.\n"); 

    pa2m_afirmar((lista_insertar(lista, &dato_1)) == 0, "Inserto 1º valor en una lista.");
    pa2m_afirmar(lista_vacia(lista) != 1, "La lista no esta vacia.");

    pa2m_afirmar((lista_insertar(lista, &dato_2)) == 0, "Inserto 2º valor en una lista.");
    pa2m_afirmar(lista_vacia(lista) != 1, "La lista no esta vacia.\n");

    pa2m_afirmar(lista_borrar(lista) == 0, "Borro el ultimo elemento de la lista.");
    pa2m_afirmar(lista_vacia(lista) != 1, "La lista aun no esta vacia.");

    pa2m_afirmar(lista_borrar(lista) == 0, "Borro el ultimo elemento de la lista.");
    pa2m_afirmar(lista_vacia(lista) == 1, "La lista esta vacia.");

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

    pa2m_afirmar((lista_elemento_en_posicion(NULL, 2)) == 0, "Buscar elemento en posicion deberia fallar si la lista es NULL.\n");

    pa2m_afirmar((lista_insertar(lista, &dato_int)) == 0, "Inserte un valor (int) en la lista.");
    pa2m_afirmar((lista_insertar(lista, &dato_char)) == 0, "Inserte un valor (char) en la lista.");
    pa2m_afirmar((lista_insertar(lista, &dato_double)) == 0, "Inserte un valor (double) en la lista.\n");

    //pa2m_afirmar((lista_elemento_en_posicion(lista, -1)) == NULL, "Deberia fallar si no existe dicha posicion. (posicion negativa)");
    pa2m_afirmar((lista_elemento_en_posicion(lista, 10)) == NULL, "Deberia fallar si no existe dicha posicion. (posicion supera la cantidad de elementos en la lista).\n");

    pa2m_afirmar(*(int*)lista_elemento_en_posicion(lista, 0) == dato_int, "Devuelve el elemento correcto.");
    pa2m_afirmar(*(char*)lista_elemento_en_posicion(lista, 1) == dato_char, "Devuelve el elemento correcto.");
    pa2m_afirmar(*(double*)lista_elemento_en_posicion(lista, 2) == dato_double, "Devuelve el elemento correcto.");

    
    free(lista->nodo_fin);
    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio);
    free(lista);
}

void probar_lista_ultimo(){
    int dato_int = 15;
    char dato_char = 'A';
    double dato_double = 3.14;
    lista_t* lista = lista_crear();

    pa2m_afirmar(lista_ultimo(NULL) == NULL, "La funcion deberia devolver NULL si le paso una lista vacia o esta no tiene elementos.");

    pa2m_afirmar((lista_insertar(lista, &dato_int)) == 0, "Inserte un valor (int) en la lista.");
    pa2m_afirmar(*(int*)lista_ultimo(lista) == dato_int, "El ultimo valor deberia ser el (int) recientemente ingresado.");

    pa2m_afirmar((lista_insertar(lista, &dato_char)) == 0, "Inserte un valor (char) en la lista.");
    pa2m_afirmar(*(char*)lista_ultimo(lista) == dato_char, "El ultimo valor deberia ser el (char) recientemente ingresado.");

    pa2m_afirmar((lista_insertar(lista, &dato_double)) == 0, "Inserte un valor (double) en la lista.");
    pa2m_afirmar(*(double*)lista_ultimo(lista) == dato_double, "El ultimo valor deberia ser el (double) recientemente ingresado.");
    

    free(lista->nodo_fin);
    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio);
    free(lista);
} 

void probar_lista_elementos(){
    int a = 5, b = 1, c = 3;
    lista_t* lista = lista_crear();

    pa2m_afirmar((lista_insertar(lista, &a)) == 0, "Inserto 1º elemento en una lista.");
    pa2m_afirmar(lista_elementos(lista) == 1, "La lista ahora deberia tener 1 elemento/s.");
    pa2m_afirmar((lista_insertar(lista, &b)) == 0, "Inserto 2º elemento en una lista.");
    pa2m_afirmar(lista_elementos(lista) == 2, "La lista ahora deberia tener 2 elemento/s.");
    pa2m_afirmar((lista_insertar(lista, &c)) == 0, "Inserto 3º elemento en una lista.");
    pa2m_afirmar(lista_elementos(lista) == 3, "La lista ahora deberia tener 3 elemento/s.");

    free(lista->nodo_fin);
    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio);
    free(lista);
}

int main(){

    /*       PRUEBAS       */
    
    pa2m_nuevo_grupo("PRUEBAS DE LISTA");

    printf("\n---------PROBAR_LISTA_INSERTAR---------\n");
    probar_lista_insertar();

    printf("\n---------PROBAR_LISTA_INSERTAR_EN_POSICION---------\n");
    probar_lista_insertar_en_posicion();

    printf("\n---------PROBAR_LISTA_BORRAR---------\n");
    probar_lista_borrar();

    printf("\n---------PROBAR_LISTA_BORRAR_DE_POSICION---------\n");
    probar_lista_borrar_de_posicion();

    printf("\n---------PROBAR_LISTA_ELEMENTO_EN_POSICION---------\n");
    probar_lista_elemento_en_posicion();

    printf("\n---------PROBAR_LISTA_ES_VACIA---------\n");
    probar_lista_es_vacia(); 

    printf("\n---------PROBAR_LISTA_ULTIMO---------\n");
    probar_lista_ultimo(); 

    printf("\n---------PROBAR_LISTA_ELEMENTOS--------\n");
    probar_lista_elementos(); 

    pa2m_mostrar_reporte();
    

    /*        MAIN         */
    
    printf("\n-------------------------M.A.I.N--------------------------\n\n");
    /*
    int a = 5, b = 1, c = 3, d = 12;
    lista_t* lista = lista_crear();

    lista_insertar(lista, &a);
    lista_insertar(lista, &b);
    lista_insertar(lista, &c);
    recorrer_y_mostrar(lista);
    lista_borrar_de_posicion(lista, 1);
    lista_borrar_de_posicion(lista, 1);
    lista_borrar_de_posicion(lista, 0);

    recorrer_y_mostrar(lista);

    free(lista);
    */
    /* ANDA - FALTA TESTEAR
    int cant = lista_elementos(lista);
    printf("%i\n", cant);
    */


}