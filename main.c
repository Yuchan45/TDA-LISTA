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
    free(una_lista->nodo_fin);
    free(una_lista->nodo_inicio);
    lista_destruir(una_lista);

}

void probar_correcta_insercion(){
    int dato = 1;
    int dato2 = 2;
    int dato3 = 3;

    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    lista_insertar(lista, &dato2);
    lista_insertar(lista, &dato3);

    pa2m_afirmar(*(int*)(lista->nodo_inicio->elemento) == 1, "El PRIMER valor se ingreso correctamente");
    pa2m_afirmar(*(int*)(lista->nodo_inicio->siguiente->elemento) == 2, "El SEGUNDO valor se ingreso correctamente");
    pa2m_afirmar(*(int*)(lista->nodo_fin->elemento) == 3, "El ULTIMO valor se ingreso correctamente");

    free(lista->nodo_fin);
    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio);
    lista_destruir(lista);
    
}

void probar_insertar_distintos_tipos_de_datos(){
    int dato = 1;
    char dato2 = 'A';
    //int dato3 = NULL;
    double dato4 = 20.1;

    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    lista_insertar(lista, &dato2);
    //lista_insertar(lista, &dato3);
    lista_insertar(lista, &dato4);

    pa2m_afirmar(*(int*)(lista->nodo_inicio->elemento) == 1, "El PRIMER valor (de tipo int) se ingreso correctamente");
    pa2m_afirmar(*(char*)(lista->nodo_inicio->siguiente->elemento) == 'A', "El SEGUNDO valor (de tipo char) se ingreso correctamente");
    //pa2m_afirmar(*(int*)(lista->nodo_inicio->elemento) == NULL, "El TERCER valor (Un NULL) se ingreso correctamente (se puede ingresar nulls)");
    pa2m_afirmar(*(double*)(lista->nodo_fin->elemento) == 20.1, "El ULTIMO valor (de tipo double) se ingreso correctamente");

    free(lista->nodo_fin);
    //free(lista->nodo_inicio->siguiente->siguiente);
    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio);
    lista_destruir(lista);
}

void probar_insertar_en_posicion_invalida(){
    int dato = 1;
    int dato2 = 2;
    int dato3 = 3;
    int elemento_insertar_posicion = 45;

    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    lista_insertar(lista, &dato2);
    lista_insertar(lista, &dato3);
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion, 5); //La lista tiene cantidad 3. osea 3 elementos, si pongo posicion 5, deberia ponerlo al final.


    pa2m_afirmar(*(int*)(lista->nodo_fin->elemento) == 45, "Insertar en posicion invalida funciona. Lo pone al final :)");

    free(lista->nodo_fin);
    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio->siguiente->siguiente);
    free(lista->nodo_inicio);
    lista_destruir(lista);
}

probar_insertar_en_posicion_valida(){
    int dato = 1;
    int dato2 = 2;
    int dato3 = 3;
    int elemento_insertar_posicion = 45;

    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    lista_insertar(lista, &dato2);
    lista_insertar(lista, &dato3);
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion, 5); //La lista tiene cantidad 3. osea 3 elementos, si pongo posicion 5, deberia ponerlo al final.


    pa2m_afirmar(*(int*)(lista->nodo_fin->elemento) == 45, "Insertar en posicion invalida funciona. Lo pone al final :)");

    free(lista->nodo_fin);
    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio->siguiente->siguiente);
    free(lista->nodo_inicio);
    lista_destruir(lista);
}


/*
Recibe una lista por parametro y la recorre, devolviendo el puntero de cada posicion.
 */
void recorrer_y_mostrar(lista_t* lista){
    nodo_t* sig;
    size_t posicion = 1;
    sig = lista->nodo_inicio;
    while(sig != NULL){
        printf("Puntero a elemento: %p, elemento: %c, posicion: %li\n", sig->elemento, *(char*)(sig->elemento), posicion);
        (posicion)++;
        sig = sig->siguiente;
    }

}

int main(){

    /*       PRUEBAS       */
    
    pa2m_nuevo_grupo("PRUEBAS DE LISTA");
    printf("\n---------probar_creacion_lista---------\n");
    probar_creacion_lista();
    
    printf("\n---------probar_insertar_en_lista---------\n");
    probar_insertar_en_lista();

    printf("\n---------probar_correcta_insercion---------\n");
    probar_correcta_insercion(); 
    
    printf("\n---------probar_insertar_distintos_tipos_de_datos---------\n");
    probar_insertar_distintos_tipos_de_datos();
    
    printf("\n---------probar_insertar_en_posicion_invalida---------\n");
    probar_insertar_en_posicion_invalida();

    printf("\n---------probar_insertar_en_distintas_posiciones---------\n");
    probar_insertar_en_posicion_valida();

    pa2m_mostrar_reporte();
    

    /*        MAIN         */
    
    printf("\n-------------------------M.A.I.N--------------------------\n\n");
    char dato = 'A';
    //char dato2 = 'A';
    //double dato4 = 20.1;
    char dato2 = 'B';
    char dato3 = 'C';
    char elemento_insertar_posicion = 'D';
    char elemento_insertar_posicion_2 = 'E';
    char elemento_insertar_posicion_3 = 'F';


    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    lista_insertar(lista, &dato2);
    lista_insertar(lista, &dato3);

    recorrer_y_mostrar(lista);
    printf("Lista.cantidad = %li\n", lista->cantidad);
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion, 1);
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion_2, 0);
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion_3, 0);
    recorrer_y_mostrar(lista);

    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio);
    free(lista->nodo_fin);
    lista_destruir(lista);

/*
    printf("elemento: %i\n", *(int*)(lista->nodo_inicio->elemento));
    //printf("elemento: %i\n", *(int*)((lista->nodo_inicio + 2)->elemento));
    //printf("elemento: %i\n", *(int*)((lista->nodo_inicio + 4)->elemento));

    printf("elemento: %c\n", *(char*)(lista->nodo_inicio->siguiente->elemento));
    printf("elemento: %d (1 es true)\n", *(bool*)((lista->nodo_inicio + 2)->siguiente->elemento));


    //printf("elemento: %c\n", *(char*)(lista->nodo_inicio + 2)->elemento);
    //printf("elemento: %i\n", *(int*)(lista->nodo_inicio + 3)->elemento);
    //printf("elemento: %f\n", *(float*)(lista->nodo_inicio + lista->cantidad)->elemento);
    printf("elemento: %f\n", *(double*)lista->nodo_fin->elemento);
*/
    
}