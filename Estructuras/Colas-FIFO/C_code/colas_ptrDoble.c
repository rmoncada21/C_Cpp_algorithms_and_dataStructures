/*
Hacer cola con punteros dobles, implementando una lista simple.
struct nodo* cola = entra y puntero nodo->siguiente = NULL sería la salida
*/
#include <stdlib.h>
#include <stdio.h>

#define SALTO putchar('\n')

struct nodo{
    int dato;
    struct nodo* siguiente;
};
typedef struct nodo Nodo;

// vacio(); revisa si la cola tiene o no elementos
int vacio(Nodo* cola) {
    if (cola == NULL) {
        return 1;
    }

    return 0;
}

// encolar(); Inserta un elmemento de la lista al inicio
void encolar(Nodo** cola, int dato) {
    // crear_nodo()
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = dato;  // Inicializar los valores de nodo
    nuevo->siguiente = NULL;  // Inicializar los valores de nodo

    nuevo->siguiente = *cola;
    *cola = nuevo;

    return;
}

// mostrar_cola();
void mostrar_cola(Nodo* pila) {
    Nodo* temporal = NULL;

    temporal = pila;
    while (temporal != NULL) {
        printf("Dato:%d - ", temporal->dato);
        temporal = temporal->siguiente;
    }
    SALTO;
    return;
}

// TODO($user): desencolar(); elimina un elmento de la lista

// TODO($user): top() devuleve el primer elemento de la lista sin eliminar

int main() {
    Nodo* cola = NULL;  // FIFO
    encolar(&cola, 10);
    encolar(&cola, 20);
    encolar(&cola, 30);
    encolar(&cola, 45);
    mostrar_cola(cola);
    return 0;
}
