#include "lista.h"
#include <stdio.h>
#include "pa2mm.h"

/*
Recibe una lista por parametro y la recorre, devolviendo el puntero de cada posicion.
 */
void recorrer_y_mostrar(lista_t* lista){
    nodo_t* sig;
    size_t posicion = 1;
    sig = lista->nodo_inicio;
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
    pa2m_afirmar((una_lista->nodo_inicio->elemento) == &dato_1, "El nodo de inicio ahora apunta al dato ingresado.");
    pa2m_afirmar((una_lista->nodo_fin->elemento) == &dato_1, "El nodo de fin ahora apunta al dato ingresado.");
    pa2m_afirmar(una_lista->nodo_inicio->elemento == una_lista->nodo_fin->elemento, "Como es la 1º insercion, el nodo fin y nodo inicio apuntan al mismo elemento.\n");

    printf(" - Inserto 2º elemento - \n");
    pa2m_afirmar((lista_insertar(una_lista, &dato_char)) == 0, "Insertar 2º (char) en una lista.");
    pa2m_afirmar((*(char*)una_lista->nodo_inicio->siguiente->elemento) == dato_char, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((una_lista->cantidad) == 2, "Ahora el contador de cantidad es 2.");
    pa2m_afirmar((una_lista->nodo_inicio->elemento) == &dato_1, "El nodo de inicio sigue siendo el primer dato ingresado.");
    pa2m_afirmar((una_lista->nodo_fin->elemento) == &dato_char, "El nodo de fin ahora apunta al ultimo dato ingresado.");
    pa2m_afirmar(una_lista->nodo_inicio->elemento != una_lista->nodo_fin->elemento, "Como es la 2º insercion, el nodo inicio y nodo fin apuntan a distintos elementos.\n");

    printf(" - Inserto 3º elemento - \n");
    pa2m_afirmar((lista_insertar(una_lista, &dato_double)) == 0, "Insertar 3º valor (double) en una lista.");
    pa2m_afirmar((*(double*)una_lista->nodo_inicio->siguiente->siguiente->elemento) == dato_double, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((una_lista->cantidad) == 3, "Ahora el contador de cantidad es 2.");
    pa2m_afirmar((una_lista->nodo_inicio->elemento) == &dato_1, "El nodo de inicio sigue siendo el primer dato ingresado.");
    pa2m_afirmar((una_lista->nodo_fin->elemento) == &dato_double, "El nodo de fin ahora apunta al ultimo dato ingresado.\n");

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
    pa2m_afirmar((lista->nodo_inicio->elemento) == &dato_1, "El nodo de inicio ahora apunta al dato ingresado.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &dato_1, "El nodo de fin ahora apunta al dato ingresado.");
    pa2m_afirmar(lista->nodo_inicio->elemento == lista->nodo_fin->elemento, "Como es la 1º insercion, el nodo fin y nodo inicio apuntan al mismo elemento.\n");

    printf(" - Inserto 2º elemento - (posicion no valida) - \n");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &dato_2, 48) == 0, "Puedo insertar un valor (int) por posicion (invalida) en una lista.");
    pa2m_afirmar((*(int*)lista->nodo_inicio->siguiente->elemento) == dato_2, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((lista->cantidad) == 2, "Ahora el contador de cantidad es 2.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &dato_1, "El nodo de inicio sigue siendo el primer dato ingresado.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &dato_2, "El nodo de fin ahora apunta al ultimo dato ingresado.");
    pa2m_afirmar(lista->nodo_inicio->elemento != lista->nodo_fin->elemento, "Como es la 2º insercion, el nodo inicio y nodo fin apuntan a distintos elementos.\n");

    printf(" - Inserto 3º elemento - (posicion 1, valida) - \n");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &dato_double, 1) == 0, "Puedo insertar un valor (double) en la posicion 1 de la lista.");
    pa2m_afirmar((*(double*)lista->nodo_inicio->siguiente->elemento) == dato_double, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((lista->cantidad) == 3, "Ahora el contador de cantidad es 3.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &dato_1, "El nodo de inicio sigue siendo el primer dato ingresado.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &dato_2, "El nodo de fin no cambia (porque inserte en la primer posicion), sigue apuntando al nodo de antes.\n");

    printf(" - Inserto 4º elemento - (posicion 0, valida) - \n");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &dato_char, 0) == 0, "Puedo insertar un valor (char) en la posicion 0 de la lista.");
    pa2m_afirmar((*(char*)lista->nodo_inicio->elemento) == dato_char, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((lista->cantidad) == 4, "Ahora el contador de cantidad es 4.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &dato_char, "El nodo de inicio ahora apunta a este nodo.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &dato_2, "El nodo de fin no cambia (porque inserte en la posicion 0), sigue apuntando al nodo de antes.\n");

    printf(" - Inserto 5º elemento - (posicion 0, valida) - \n");
    pa2m_afirmar(lista_insertar_en_posicion(lista, &dato_char_2, 5) == 0, "Puedo insertar un valor (char) en la posicion maxima de la lista.");
    pa2m_afirmar((*(char*)lista->nodo_fin->elemento) == dato_char_2, "Valor correcto - El elemento se inserto correctamente.");
    pa2m_afirmar((lista->cantidad) == 5, "Ahora el contador de cantidad es 5.");
    pa2m_afirmar((lista->nodo_inicio->elemento) == &dato_char, "El nodo de inicio no cambia, sigue apuntando al de antes.");
    pa2m_afirmar((lista->nodo_fin->elemento) == &dato_char_2, "El nodo de fin ahora apunta a este nuevo nodo.\n");

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


int main(){

    /*       PRUEBAS       */
    
    pa2m_nuevo_grupo("PRUEBAS DE LISTA");

    printf("\n---------PROBAR_LISTA_INSERTAR---------\n");
    probar_lista_insertar();

    printf("\n---------PROBAR_LISTA_INSERTAR_EN_POSICION---------\n");
    probar_lista_insertar_en_posicion();

/*
    printf("\n---------probar_creacion_lista---------\n");
    probar_creacion_lista();

    pa2m_nuevo_grupo("PRUEBAS DE LISTA - Insertar al final");
    printf("\n---------probar_insertar_en_lista---------\n");
    probar_insertar_en_lista();
    printf("\n---------probar_insertar_distintos_tipos_de_datos---------\n");
    probar_insertar_distintos_tipos_de_datos();
    printf("\n---------probar_valores_insertados_correctamente---------\n");
    probar_correcta_insercion(); 
    printf("\n---------probar_lista_cantidad---------\n");
    probar_lista_cantidad();
    
*/
/*
    pa2m_nuevo_grupo("PRUEBAS DE LISTA - Insertar en posicion");
    printf("\n---------probar_insertar_por_posicion_en_lista_vacia---------\n");
    probar_insertar_por_posicion_en_lista_vacia();
    printf("\n---------probar_insertar_en_posiciones_invalidas---------\n");
    probar_insertar_en_posicion_invalida();
    printf("\n---------probar_insertar_en_posiciones_validas---------\n");
    probar_insertar_en_posicion_valida();
    printf("\n---------probar_lista_cantidad_de_insertar_en_posicion---------\n");
    probar_lista_cantidad_de_insertar_en_posicion();
    printf("\n---------probar_valores_ingresados_por_posicion_correctamente---------\n");
    probar_se_inserta_correctamente();
*/
    pa2m_mostrar_reporte();
    

    /*        MAIN         */
    
    printf("\n-------------------------M.A.I.N--------------------------\n\n");
    int a = 5, b = 1, c = 3, d = 12;
    lista_t* lista = lista_crear();

    /* ANDA - FALTA TESTEAR
    lista_insertar_en_posicion(lista, &b, 100);
    
    
    lista_insertar(lista, &b);
    lista_insertar(lista, &c);
    lista_insertar(lista, &d);

    recorrer_y_mostrar(lista);

    void* elemento = lista_ultimo(lista);
    printf("\n%i\n", *(int*)(elemento));
    */

    /* ANDA - FALTA TESTEAR
    bool es_vacia = lista_vacia(lista);
    printf("%s", es_vacia ? "true" : "false");
    */

    /* ANDA - FALTA TESTEAR
    int cant = lista_elementos(lista);
    printf("%i\n", cant);
    */


}