#include "lista.h"
#include <stdio.h>
#include "pa2mm.h"

void probar_creacion_lista(){
    lista_t* una_lista = NULL;

    pa2m_afirmar((una_lista=lista_crear()) != NULL, "Puedo crear una lista.");
    pa2m_afirmar((una_lista->nodo_inicio) == NULL, "La lista se crea vacia. Con puntero de inicio = NULL.");
    pa2m_afirmar((una_lista->nodo_fin) == NULL, "La lista se crea vacia. Con puntero de fin = NULL.");
    pa2m_afirmar((una_lista->cantidad) == 0, "La lista se crea vacia. Con cantidad = 0.");
    //pa2m_afirmar(un_acuario->cantidad_pokemon == 0, "Un acuario se crea vacio");
    //pa2m_afirmar(un_acuario->pokemon == NULL, "Un acuario se crea con un vector nulo");

    lista_destruir(una_lista);
}

void probar_insertar_en_lista(){
    lista_t* una_lista = lista_crear();
    int d = 12;
    int d2 = 33;

    pa2m_afirmar((lista_insertar(una_lista, &d)) != -1, "Puedo insertar el primer valor en la lista.");
    pa2m_afirmar((lista_insertar(una_lista, &d2)) != -1, "Puedo insertar el segundo valor en la lista.");

}

void probar_correcta_insercion(){

}

void probar_insertar_distintos_tipos_de_datos(){
    int dato = 15;
    char dato2 = 'A';
    float dato3 = 23.25;
    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    lista_insertar(lista, &dato2);
    lista_insertar(lista, &dato3);

    pa2m_afirmar((*(int*)lista->nodo_inicio->elemento) == 15, "Puedo insertar el primer valor en la lista.");
    //pa2m_afirmar((lista_insertar(una_lista, &d)) != -1, "Puedo insertar el primer valor en la lista.");
    //pa2m_afirmar((lista_insertar(una_lista, &d)) != -1, "Puedo insertar el primer valor en la lista.");
}

int main(){

    /*       PRUEBAS       */
    pa2m_nuevo_grupo("PRUEBAS DE LISTA");
    probar_creacion_lista();

    probar_insertar_en_lista();
    probar_correcta_insercion();


    pa2m_mostrar_reporte();

    /*        MAIN         */
    printf("\n----------------------------------------\n\n");
    int dato = 15;
    char dato2 = 'A';
    float dato3 = 23.25;
    printf("%c\n", dato2);
    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    lista_insertar(lista, &dato2);
    lista_insertar(lista, &dato3);
    printf("elemento: %i\n", *(int*)lista->nodo_inicio->elemento);
    printf("elemento: %c\n", *(char*)(lista->nodo_inicio + lista->cantidad -1)->elemento);
    printf("elemento: %f\n", *(float*)lista->nodo_fin->elemento);

}