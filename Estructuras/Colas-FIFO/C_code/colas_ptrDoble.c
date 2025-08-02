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
    printf("Enqueue: %d \n", dato);
    nuevo->dato = dato;  // Inicializar los valores de nodo
    nuevo->siguiente = NULL;  // Inicializar los valores de nodo

    nuevo->siguiente = *cola;
    *cola = nuevo;

    return;
}

// mostrar_cola();
void mostrar_cola(Nodo* cola) {
    Nodo* temporal = NULL;

    if (vacio(cola)) printf(" Cola vacía \n");

    temporal = cola;
    while (temporal != NULL) {
        printf("Dato:%d - ", temporal->dato);
        temporal = temporal->siguiente;
    }
    SALTO;
    return;
}

// desencolar(); elimina el primer elemento ingresado
void desencolar(Nodo** cola) {
    Nodo* temporal = *cola;
    Nodo* anterior =  NULL;

    while (temporal != NULL) {

        if (temporal->siguiente == NULL) {
            anterior->siguiente = NULL;
            free(temporal);
            temporal = NULL;
            return;
        }
        anterior = temporal;
        temporal = temporal->siguiente;
    }
    // return;
}

// liberar_memoria(); elimina un elmento de la lista
void liberar_memoria(Nodo** cola) {
    while (*cola != NULL) {
        Nodo* temp = NULL;
        temp = *cola;
        *cola = (*cola)->siguiente;
        free(temp);
    }
    return;
}

// TODO($user): top() devuleve el primer elemento de la lista sin eliminar
Nodo* top(Nodo* cola){
    Nodo* temporal = cola;
    Nodo* actual = temporal;

    while (temporal!=NULL) {
        if (temporal->siguiente==NULL) {
            actual = temporal;
        }
        temporal = temporal->siguiente;
    }
    return actual;
}

int main() {
    Nodo* cola = NULL;  // FIFO
    encolar(&cola, 10);
    encolar(&cola, 20);
    encolar(&cola, 30);
    encolar(&cola, 45);
    mostrar_cola(cola);
    desencolar(&cola);
    mostrar_cola(cola);
    desencolar(&cola);
    mostrar_cola(cola);
    desencolar(&cola);
    mostrar_cola(cola);
    encolar(&cola, 50);
    encolar(&cola, 100);
    encolar(&cola, 200);
    mostrar_cola(cola);
    desencolar(&cola);
    
    Nodo* nodo_top = top(cola);
    printf("dato top: %d \n", nodo_top->dato);

    liberar_memoria(&cola);
    return 0;
}
