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

// Método para recorrer/mostrar lista
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

// Método para agregar al final
/*
No se quiere llegar al último nodo nuevo, se quiere llegar al último nodo actual de la lista.
Una vez ahí, se hace: temporal->siguiente = nuevo_nodo;
SE Necesita llegar al penúltimo nodo para cambiar su puntero siguiente.
*/
void agregar_final(Nodo** lista, int dato){
    Nodo* nuevo_nodo = crear_nodo(dato);

    // Asegurarse que la lista no este vacía
    if(*lista==NULL){
        *lista = nuevo_nodo;
        return;
    }

    // Si la lista no esta vacía
    Nodo* temporal = *lista;

    while(temporal->siguiente != NULL){
        temporal = temporal->siguiente;
    }

    temporal->siguiente = nuevo_nodo;
}

// Método para buscar
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

// Método para eliminar nodo
// Escenarios: primer nodo - ultimo nodo - malcomn
void eliminar_nodo(Nodo** lista, int dato){
    Nodo* nodo_actual = *lista;
    Nodo* nodo_anterior = NULL;
    
    
    // while(nodo_actual->siguiente != NULL) <------> No funciona, no entra al utlimo nodo
    while(nodo_actual != NULL){                    // Si entra al ultimo nodo
        if(nodo_actual->dato == dato){
            // Eliminar un nodo al inicio
            if(nodo_anterior == NULL){
                printf("\nEntra - Eliminar primer nodo \n");
                *lista = nodo_actual->siguiente;   
            }
            // nodo malcomn
            // else if (nodo_anterior != NULL && nodo_actual->siguiente != NULL){
            else if (nodo_actual->siguiente != NULL){ // nodo malcomn
                printf("\nEntra - Eliminar malcom \n");
                nodo_anterior->siguiente = nodo_actual->siguiente;
            }
            // ultimo nodo
            // else if(nodo_anterior != NULL && nodo_actual->siguiente == NULL) {
            else if(nodo_actual->siguiente == NULL) { // ultimo nodo
                printf("\nEntra - Eliminar ultimo nodo \n");
                nodo_anterior->siguiente = NULL;
            } 
            free(nodo_actual);
            return;
        }
        nodo_anterior = nodo_actual;
        nodo_actual = nodo_actual->siguiente; // avanzar al siguiente nodo
    }
        
    printf("\nNO SE ENCONTRÓ EL NODO con el dato: %d \n", dato);

}

// TODO: Método para liberar memoria
// Recorrer lista y liberar nodo uno por uno
void liberar_memoria(Nodo** lista){
    Nodo* temporal =  *lista;

    while(temporal != NULL){
        Nodo* actual = temporal;

        temporal =  temporal->siguiente; 
        free(actual);
        // actual = NULL; no es necesario.Deja de existir al salir del bucle
    }

    *lista = NULL;
    return;
}

int main(){
    Nodo* lista = NULL;

    agregar_inicio(&lista, 0);
    agregar_inicio(&lista, 5);
    agregar_inicio(&lista, 10);
    agregar_inicio(&lista, 15);
    agregar_final(&lista, 20);
    mostrar_lista(lista);   
    eliminar_nodo(&lista, 15);
    eliminar_nodo(&lista, 55);
    printf("\n");
    // mostrar_lista(lista);
    liberar_memoria(&lista);
    printf("\n");
    
    Nodo* buscar = buscar_nodo(lista, 2);
    
    if(buscar){
        printf("Encontrado: %d \n", buscar->dato);
    } else {
        printf("NULL: No se encontro");
    }

    // liberar memoria
    // liberar_memoria(&lista);
    return 0;
}