CFLAGS=-g -O0

correr: pruebas
	./pruebas

pruebas: lista.c main.c
	gcc $(CFLAGS) lista.c main.c -o pruebas

valgrind: pruebas
	valgrind ./pruebas
