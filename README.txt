-TDA LISTA-
Hago entrega de la implementacion del TDA Lista (simplemente enlazada), el cual incluye tambien la implementacion de las funciones basicas de los TDAs PILA y COLA.

Para compilar el programa, se debe abrir una consola en la carpeta con los archivos correspondientes y ejecutar la siguiente linea de comando:
    gcc *.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0

Para ejecutarlo:
    ./lista_se
 
Y para ejecutarlo y detectar si hay perdida de memoria:
    valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./lista_se


En la implementacion del TDA entregado, realice todos los metodos necesarios para poder utilizar un TDA lista. La lista consiste en 2 estructuras principales:

-Lista: La cual contiene un puntero nodo_inicio, puntero nodo_fin y la cantidad de elementos (nodos) en la lista. 

-Nodo: El cual guarda un puntero al elemento que el usuario quiera almacenar y un puntero al siguiente nodo. 

Entonces, lo que tenemos es una secuencia de nodos en la cual cada uno apunta al siguiente (menos el ultimo que apunta a NULL). Y una estructura "lista" que sabe la cantidad de nodos en la lista, tiene un puntero al primer nodo y un puntero al ultimo nodo.
La ventaja que brinda el utilizar nodos en vez de arrays es que no hace falta que la memoria utilizada para almacenar los datos sea contigua. Si usasemos arrays en vez de nodos, habria que hacer un realloc por cada vez que insertaramos o borrasemos un elemento. Un problema que puede surgir de esto es que por ejemplo, en caso de que no alcance la memoria previamente reservada para insertar un nuevo elemento, habria que buscar otro bloque de memoria CONTIGUA que si alcance para almacenar todo y ahi copiar todo nuevamente.

Para crear una lista hay que hacer uso de la funcion lista_crear() la cual devolvera una lista. Una vez tengas la lista, ya es posible comenzar a gestionar la lista. Insertar elementos, borrar elementos, insertar elementos en x posicion, borrar elementos en x posicion, etc.
Una vez terminado el uso de la lista, se puede destruir utilizando el metodo lista_destruir() el cual se encarga de liberar todos los nodos y la lista.

En este TDA Lista tambien se incluyen los metodos necesarios para usar la lista como una PILA o como una COLA mediante el uso de los metodos apilar, desapilar, encolar y desencolar, etc.

Se realizo la implementacion del TDA iterador (externo) el le permite al usuario recorrer la lista haciendo uso de los metodos del TDA Iterador, como devolver el elemento o avanzar al sigueinte elemento. 
A su vez, hay un metodo que vendria a ser un "iterador interno", el cual recorre los elementos de la lista y se encarga de ejecutar una funcion (pasada por parametro previamente) en cada elemento de la lista.




 - Conceptos teóricos - 
1) Una lista es una secuencia ordenada de nodos. los nodos son estructuras que almacenan un puntero al elemento que el usuario desee almacenar y todos los nodos cuentan con punteros que los "unen" entre si, formando de esta manera una lista. La diferencia entre una lista simplemente enlazada y una doblemente enlazada es que la simplemente solo cuenta con un puntero que apunta al siguiente nodo, mientras que la doblemente posee dos nodos, uno que apunta al nodo anterior y otro que apunta al nodo siguiente, permitiendole asi recorrer la lista en ambas direcciones (ida y vuelta). Mientras que la simplemete enlazada solo puede recorrer en un solo sentido (ida).

2) Las caracteristicas principales de una Pila es el orden en el que se eliminan los elementos almacenados en esta. En la pila, su orden vendria a ser LIFO (Last in, first out) lo cual significa que, al igual que una pila de platos, el ultimo elemento en insertar en la PILA es el primer elemento a sacar de esta. Por ejemplo, si se tiene una pila [1, 2, 3] en el cual el primer elemento insertado es el "1", y el ultimo elemento insertado es el "3", si yo saco un elemento de la pila, el elementos quitado sera el "3" porque fue el ultimo en agregarse a la pila.
La COLA es lo mismo que la PILA con la diferencia de que es FIFO (First in, first out) y hace referencia a una cola de supermercado, en donde el primer cliente en ponerse en la cola seria el primero en salir de esta. Si la COLA es [1, 2, 3], siendo el "1" el primer elemento encolado y el "3" el ultimo, si yo quito un elemento de la cola (desencolo), el elemento que sale seria el 1 ya que fue el primero en ingresar.

3) Un iterador es un TDA a parte del "TDA Lista" el cual le permite al usuario recorrer una lista. El TDA iterador consiste en crear un puntero que "mira" a los elementos de la lista (inicialmente mira al primer elementos de la lista) y mediante el uso de metodos, el iterador puede devolverle el elemento al cual esta "mirando" al usuario, o avanzar al siguiente elemento de la lista.

4) Un iterador interno se diferencia del TDA Iterador(externo) porque este es mas bien un metodo propio de la lista, no un TDA aparte. A diferencia del TDA iterador(externo) en el cual el usuario se encarga de navegar por la lista haciendo uso de los metodos del TDA Iterador, en el iterador interno el usuario llama a la funcion del iterador interno y este se encarga de recorrer todos los elementos de la lista y mediante el uso de una funcion la cual recibe por parametro, el usuario puede decidir que hacer con cada elemento que el iterador recorre, por ejemplo mostrarlo por pantalla, o mostrar hasta que encuentre una letra 'c' por ejemplo.



