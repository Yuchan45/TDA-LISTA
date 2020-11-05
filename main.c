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
        printf("Puntero a elemento: %p, elemento: %c, posicion: %li\n", sig->elemento, *(char*)(sig->elemento), posicion);
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

void probar_creacion_lista(){
    //Prueba la correcta creacion de una lista.
    lista_t* una_lista = NULL;

    pa2m_afirmar((una_lista=lista_crear()) != NULL, "Puedo crear una lista.");
    pa2m_afirmar((una_lista->nodo_inicio) == NULL, "La lista se crea vacia. Con puntero de inicio = NULL.");
    pa2m_afirmar((una_lista->nodo_fin) == NULL, "La lista se crea vacia. Con puntero de fin = NULL.");
    pa2m_afirmar((una_lista->cantidad) == 0, "La lista se crea vacia. Con cantidad = 0.");

    lista_destruir(una_lista);
}

void probar_insertar_en_lista(){
    //Prueba que los elementos se pueden insertar, siempre y cuando le mandes una lista valida.
    lista_t* una_lista = lista_crear();
    int d = 12, d2 = 33;

    pa2m_afirmar((lista_insertar(NULL, &d)) != 0, "Puedo insertar un valor en una lista que no existe.");
    pa2m_afirmar((lista_insertar(una_lista, &d)) != -1, "Puedo insertar el primer valor en la lista.");
    pa2m_afirmar((lista_insertar(una_lista, &d2)) != -1, "Puedo insertar el segundo valor en la lista.");

    free(una_lista->nodo_fin);
    free(una_lista->nodo_inicio);
    lista_destruir(una_lista);

}

void probar_insertar_por_posicion_en_lista_vacia(){
    int dato = 10;
    lista_t* lista = lista_crear();

    lista_insertar_en_posicion(lista, &dato, 0);
    pa2m_afirmar(lista->nodo_inicio->elemento != NULL, "Puedo insertar un valor por posicion en una lista vacia.");

    free(lista->nodo_inicio);
    lista_destruir(lista);
}

void probar_correcta_insercion(){
    //Prueba que los elementos que se insertan en la lista corectamente.
    int dato = 1, dato2 = 2;
    char dato3 = 'A';

    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    lista_insertar(lista, &dato2);
    lista_insertar(lista, &dato3);

    pa2m_afirmar(*(int*)(lista->nodo_inicio->elemento) == 1, "Valor correcto. El 1º valor se ingreso correctamente");
    pa2m_afirmar(*(int*)(lista->nodo_inicio->siguiente->elemento) == 2, "Valor correcto. El 2º valor se ingreso correctamente");
    pa2m_afirmar(*(char*)(lista->nodo_fin->elemento) == 'A', "Valor correcto. El ultimo valor se ingreso correctamente");

    free(lista->nodo_fin);
    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio);
    lista_destruir(lista);
    
}

void probar_lista_cantidad(){
    // Prueba que el contador de cantidad sume al realizar cada operacion de "insertar" (al final).
    int dato = 1, dato2 = 2, dato3 = 3;

    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    pa2m_afirmar((int)(lista->cantidad) == 1, "El contador anda bien al agregar el primer elemento.");
    lista_insertar(lista, &dato2);
    pa2m_afirmar((int)(lista->cantidad) == 2, "El contador anda bien al agregar el segundo elemento.");
    lista_insertar(lista, &dato3);
    pa2m_afirmar((int)(lista->cantidad) == 3, "El contador anda bien al agregar el tercer elemento.");


    free(lista->nodo_fin);
    free(lista->nodo_inicio->siguiente);   
    free(lista->nodo_inicio);
    lista_destruir(lista);

}

void probar_insertar_distintos_tipos_de_datos(){
    //En realidad no se si hace falta, porque se supone que guarda punteros void \o/.
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

void probar_lista_cantidad_de_insertar_en_posicion(){
    //Prueba que el contador de cantidad sume correctamente al agregar elementos de diferentes formas y posiciones.
    int dato = 1, dato2 = 2;
    int elemento_insertar_1 = 45, elemento_insertar_2 = 56;

    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    pa2m_afirmar((int)(lista->cantidad) == 1, "El contador anda bien al agregar el primer elemento.");
    lista_insertar(lista, &dato2);
    pa2m_afirmar((int)(lista->cantidad) == 2, "El contador anda bien al agregar el segundo elemento.");
    lista_insertar_en_posicion(lista, &elemento_insertar_1, 3); //La lista tiene cantidad 2. osea 2 elementos, si pongo posicion 3, deberia ponerlo al final.
    pa2m_afirmar((int)(lista->cantidad) == 3, "El contador anda bien al agregar el tercer elemento (con posicion valida).");
    lista_insertar_en_posicion(lista, &elemento_insertar_2, 23); // aca tmb lo pone al final.
    pa2m_afirmar((int)(lista->cantidad) == 4, "El contador anda bien al agregar el cuarto elemento (con posicion invalida).");

    // La lista queda asi: [1, 2, 45, 56]

    free(lista->nodo_fin);
    free(lista->nodo_inicio->siguiente->siguiente);
    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio);
    lista_destruir(lista);
}

void probar_insertar_en_posicion_invalida(){
    int dato = 1, dato2 = 2;
    int elemento_insertar_posicion = 45, elemento_insertar_posicion_2 = 56;
    //int elemento_insertar_posicion_3 = 99;

    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    lista_insertar(lista, &dato2);
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion, 4); //La lista tiene cantidad 2. osea 2 elementos, si pongo posicion 4, deberia ponerlo al final.
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion_2, 108);
    //lista_insertar_en_posicion(lista, &elemento_insertar_posicion_3, -1); //Prueba con usuario usando mal. Lo comento para que no salte warning siempre.

    //printf("%i\n", *(int*)lista->nodo_inicio->siguiente->siguiente->elemento);

    pa2m_afirmar((lista->nodo_inicio->siguiente->siguiente) != NULL, "Puedo insertar 1º elemento por posicion invalida (posicion 4 de una lista con 2 elementos)");
    pa2m_afirmar((lista->nodo_inicio->siguiente->siguiente->siguiente) != NULL, "Puedo insertar 2º elemento por posicion invalida (posicion supera cantidad)");
    //pa2m_afirmar(*(int*)(lista->nodo_fin->elemento) == 99, "Insertar 3º elemento en posicion invalida. (nº negativo)ASDASDAS"); // Lo comento porque sino me salta warning siempre
   
    // La lista queda asi: [1, 2, 3, 45, 56, 99]

    free(lista->nodo_fin);
    //free(lista->nodo_inicio->siguiente->siguiente->siguiente);
    free(lista->nodo_inicio->siguiente->siguiente);
    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio);
    lista_destruir(lista);
}

void probar_insertar_en_posicion_valida(){
    char dato = 'A', dato2 ='B', dato3 ='C';

    char elemento_insertar_posicion = 'X';
    char elemento_insertar_posicion_2 = 'Y';
    char elemento_insertar_posicion_3 = 'J';
    char elemento_insertar_posicion_4 = 'Z';
    char elemento_insertar_posicion_5 = 'K';

    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    lista_insertar(lista, &dato2);
    lista_insertar(lista, &dato3);

    lista_insertar_en_posicion(lista, &elemento_insertar_posicion, 0); //Inserto al inicio.
    pa2m_afirmar((lista->nodo_inicio) != NULL, "Puedo insertar al inicio (posicion 0)");
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion_4, 1); //Inserto en la posicion 1.
    pa2m_afirmar((lista->nodo_inicio->siguiente) != NULL, "Puedo insertar en posicion 1.");
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion_3, 0); //Inserto al inicio DENUEVO.
    pa2m_afirmar((lista->nodo_inicio) != NULL, "Puedo insertar al inicio (posicion 0 denuevo)");
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion_2, 7); //Inserto al final de forma correcta. La lista tiene 6 elementos. Paso la posicion 7.
    pa2m_afirmar((lista->nodo_fin) != NULL, "Puedo insertar al final de forma valida (posicion es el final de la lista).");

    lista_insertar_en_posicion(lista, &elemento_insertar_posicion_5, 3); //Inserto en la posicion 1.
    pa2m_afirmar((lista->nodo_inicio->siguiente) != NULL, "Puedo insertar en posicion 3.");

    //Inserto al final (por ser posicion invalida en el caso de que el usuario ignore el warning).
    /*lista_insertar_en_posicion(lista, &elemento_insertar_posicion_2, -5); */


    // Asi comienza la lista: ['A', 'B', 'C'] y asi termina: ['X', 'Z', 'A', 'B', 'C', 'Y'].

    free(lista->nodo_fin);
    free(lista->nodo_inicio->siguiente->siguiente->siguiente->siguiente->siguiente->siguiente);
    free(lista->nodo_inicio->siguiente->siguiente->siguiente->siguiente->siguiente);
    free(lista->nodo_inicio->siguiente->siguiente->siguiente->siguiente);
    free(lista->nodo_inicio->siguiente->siguiente->siguiente);
    free(lista->nodo_inicio->siguiente->siguiente);
    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio);
    lista_destruir(lista);
    
}
void probar_se_inserta_correctamente(){
    char dato = 'A', dato2 ='B';

    char elemento_insertar_posicion = 'X';
    char elemento_insertar_posicion_2 = 'Y';
    char elemento_insertar_posicion_3 = 'Z';
    char elemento_insertar_posicion_4 = 'J';
    char elemento_insertar_posicion_5 = 'K';

    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    lista_insertar(lista, &dato2);

    lista_insertar_en_posicion(lista, &elemento_insertar_posicion, 0); //Inserto al inicio.
    pa2m_afirmar(*(char*)(lista->nodo_inicio->elemento) == 'X', "Valor correcto. (Insertar al inicio (posicion 0))");
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion_2, 1); //Inserto en la posicion 1.
    pa2m_afirmar(*(char*)(lista->nodo_inicio->siguiente->elemento) == 'Y', "Valor correcto. (Insertar en posicion 1 funciona.)");
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion_3, 5); //Inserto al final de forma correcta. La lista tiene 4 elementos. Paso la posicion 5.
    pa2m_afirmar(*(char*)(lista->nodo_fin->elemento) == 'Z', "Valor correcto. (Inserto al final de forma correcta).");
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion_4, 700); //Insertar elemento al final por posicion invalida (posicion supera cantidad).
    pa2m_afirmar(*(char*)(lista->nodo_fin->elemento) == 'J', "Valor correcto. (Insertar elemento al final por posicion invalida (posicion supera cantidad)).");
    lista_insertar_en_posicion(lista, &elemento_insertar_posicion_5, 3); //Inserto en la posicion 3.
    pa2m_afirmar(*(char*)(lista->nodo_inicio->siguiente->siguiente->siguiente->elemento) == 'K', "Valor correcto. (Insertar en posicion 3 funciona.)");

    free(lista->nodo_fin);
    free(lista->nodo_inicio->siguiente->siguiente->siguiente->siguiente->siguiente);
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

    pa2m_mostrar_reporte();
    

    /*        MAIN         */
    
    printf("\n-------------------------M.A.I.N--------------------------\n\n");
    /*
    char dato = 'A';
    char dato2 = 'B';
    char dato3 = 'C';


    lista_t* lista = lista_crear();

    lista_insertar(lista, &dato);
    lista_insertar(lista, &dato2);
    lista_insertar(lista, &dato3);
    printf("Lista.cantidad = %li\n", lista->cantidad);

    recorrer_y_mostrar(lista);
    //liberar_nodos(lista);

    free(lista->nodo_inicio->siguiente);
    free(lista->nodo_inicio);
    free(lista->nodo_fin);
    lista_destruir(lista);
*/
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