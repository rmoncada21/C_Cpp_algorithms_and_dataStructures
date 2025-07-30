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

// TODO: mostrar_lista()

// TODO: agregar_final()

// TODO: buscar_nodo()

// TODO: eliminar_nodo()

// TODO: liberar_memoria

int main(){
    Lista_t* lista = crear_lista();
    agregarInicio(lista, 5);
    agregarInicio(lista, 10);
    
    return 0;
}