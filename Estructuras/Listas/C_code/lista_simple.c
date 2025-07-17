#include <stdlib.h>
#include <stdio.h>

// Nodo
struct nodo{
    int dato;
    struct nodo* siguiente;
};
typedef struct nodo Nodo;

// Crear nodo
Nodo* crear_nodo(int dato){
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));

    if (nuevo_nodo == NULL){
        printf("No se pudo crear el nodo");
        exit(1);
    }

    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = NULL;

    return nuevo_nodo;
}

// Agregar al inicio
void agregar_inicio(Nodo** lista, int dato){
    Nodo* nodo = crear_nodo(dato);

    nodo->siguiente = *lista;
    *lista = nodo;
}

// TODO: método para recorrer/mostrar lista
/*
Se necesita acceder a todos los nodos, incluyendo el último, que tiene nodo->siguiente == NULL.
De usarse temporal->siguiente != NULL, nunca se imprimiría el último nodo.
*/
void mostrar_lista(Nodo* lista){
    Nodo* temporal = lista;

    while(temporal != NULL){
        printf("dato: %d - ", temporal->dato);
        temporal =  temporal->siguiente; // en cada vuelta temporal = NULL
    }

}

// TODO: método para agregar al final
/*
No se quiere llegar al último nodo nuevo, se quiere llegar al último nodo actual de la lista.
Una vez ahí, se hace: temporal->siguiente = nuevo_nodo;
SE Necesita llegar al penúltimo nodo para cambiar su puntero siguiente.
*/
void agregar_final(Nodo** lista, int dato){
    Nodo* nuevo_nodo = crear_nodo(dato);

    // Asegurarse que la lista no este vacía
    if(*lista==NULL){
        *lista=nuevo_nodo;
        return;
    }

    // Si la lista no esta vacía
    Nodo* temporal = *lista;

    while(temporal->siguiente != NULL){
        temporal = temporal->siguiente;
    }

    temporal->siguiente = nuevo_nodo;
}

// TODO: método para buscar
Nodo* buscar_nodo(Nodo* lista, int dato){
    // int valor = 0;
    // int* puntero = &valor;

    Nodo* temporal = lista;

    while(temporal != NULL){
        
        if(temporal->dato == dato){
            return temporal;    
        }

        temporal = temporal->siguiente;
    }
    
    return NULL;
}

// TODO: método para eliminar nodo
// TODO: método para liberar memoria

int main(){
    Nodo* lista = NULL;

    agregar_inicio(&lista, 0);
    agregar_inicio(&lista, 5);
    agregar_inicio(&lista, 10);
    agregar_inicio(&lista, 15);
    agregar_final(&lista, 20);
    mostrar_lista(lista);
    printf("\n");
    
    Nodo* buscar = buscar_nodo(lista, 2);
    
    if(buscar){
        printf("Encontrado: %d \n", buscar->dato);
    } else {
        printf("NULL");
    }
    
    printf("\n");

    // liberar mempria 
    return 0;
}