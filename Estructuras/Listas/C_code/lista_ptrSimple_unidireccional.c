#include <stdlib.h>
#include <stdio.h>

struct nodo{
    int dato;
    struct nodo* siguiente;
};
typedef struct nodo Nodo;

struct lista{
    Nodo* raiz;
};
typedef struct lista Lista_t;

Lista_t* crear_lista(){
    Lista_t* lista = (Lista_t*)malloc(sizeof(Lista_t));
    lista->raiz = NULL;

    return lista;
}

Nodo* crear_nodo(int dato){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;    
    return nuevo;
}

void agregarInicio(Lista_t* lista, int dato){
    Nodo* nodo = crear_nodo(dato);

    nodo->siguiente = lista->raiz;
    lista->raiz = nodo;

    return;
}

void mostrar_lista(Lista_t* lista){
    Nodo* temporal = lista->raiz;

    while(temporal != NULL){
        printf("Dato:%d ", temporal->dato);
        
        temporal =  temporal->siguiente;
    }
    
    printf("\n");
    return;
}
// TODO: agregar_final()
void agregar_final(Lista_t* lista, int dato){
    Nodo* nuevo = crear_nodo(dato);

    // Lista vacía
    if(lista->raiz == NULL){
        lista->raiz = nuevo;
        return; 
    }

    // Agregar al final
    Nodo* temporal = lista->raiz; // temporal apunta a nodo
    
    while(temporal != NULL){
        if(temporal->siguiente == NULL){
            temporal->siguiente = nuevo;
            return;
        }

        temporal = temporal->siguiente;
    }

}

// TODO: buscar_nodo()

// TODO: eliminar_nodo()

// TODO: liberar_memoria

int main(){
    Lista_t* lista = crear_lista();
    agregarInicio(lista, 5);
    agregarInicio(lista, 10);
    mostrar_lista(lista);

    agregar_final(lista, 100);
    mostrar_lista(lista);
    
    return 0;
}