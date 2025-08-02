#include <stdlib.h>
#include <stdio.h>

#define SALTO putchar('\n')

struct _nodo{
    int dato;
    struct _nodo* siguiente;
};
typedef struct _nodo Nodo_t;

Nodo_t* crear_nodo(int dato){
    Nodo_t* nuevo_nodo = (Nodo_t*)malloc(sizeof(Nodo_t));
    
    nuevo_nodo->dato =  dato;
    nuevo_nodo->siguiente = NULL;

    return nuevo_nodo;
}

void mostrar_pila(Nodo_t* pila){
    Nodo_t* temporal = pila;
    
    // Pila vacía
    if (temporal == NULL){
        printf("Pila vacía \n");
    }

    while(temporal != NULL){
        printf("Dato: %d\n", temporal->dato);
        temporal =  temporal->siguiente;
    }

    return;
}

void push(Nodo_t** pila, int dato){
    Nodo_t* nodo = crear_nodo(dato);

    nodo->siguiente = *pila;
    *pila = nodo;

    return;
}

// Eliminar primer nodo - devolver el dato eliminado
int pop(Nodo_t** pila){

    // Pila vacía
    if(*pila == NULL){
        printf("Pila vacía \n");
        return -1;
    }

    Nodo_t* primer_nodo = *pila;
    int valor_eliminado = primer_nodo->dato;
    *pila = primer_nodo->siguiente;
    free(primer_nodo);

    return valor_eliminado;
}

// Liberar PILA
void liberar_pila(Nodo_t** pila){
    
    while(*pila != NULL){
        pop(pila);
    }

    return;
}

int main(){
    // Pila = LIFO: Last in First out
    Nodo_t* pila = NULL;
    push(&pila, 10);
    push(&pila, 15);
    push(&pila, 20);
    push(&pila, 25);
    
    // Mostrar
    mostrar_pila(pila);
    int eliminado = pop(&pila);
    SALTO;
    
    // Mostrar después de eliminar
    mostrar_pila(pila);
    SALTO;
    printf("Nodo eliminado: %d \n", eliminado);

    eliminado = pop(&pila);
    SALTO;
    
    // Mostrar después de eliminar
    mostrar_pila(pila);
    SALTO;
    printf("Nodo eliminado: %d \n", eliminado);

    // Liberar lista
    liberar_pila(&pila);
    mostrar_pila(pila);

    return 0;
}