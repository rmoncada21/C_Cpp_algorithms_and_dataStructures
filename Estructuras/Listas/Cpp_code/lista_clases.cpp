/*
Lista en enlazada simple usando objetos y punteros
*/
#include <iostream>

using namespace std;

// class Lista;

class Nodo{
    friend class Lista;
    private:
        int dato;
        Nodo* siguiente;
    public:
        // Constructot
        Nodo(int d, Nodo* s) : dato(d), siguiente(s) {}
        Nodo(int d) : dato(d), siguiente(nullptr) {}
};

class Lista{
    private:
        // raíz de la lista    
        Nodo* lista;
    public:
        // Constructor
        Lista() : lista(nullptr) {}
        
        // Métodos
        void crear_nodo();
        void agregar_inicio(int dato);
        void agregar_final(int dato);
        void eliminar_nodo(int dato);
        void mostrar_lista();
        
        // Destructor
        // ~Lista();
};

// Funciones de la clase Lista
void Lista::agregar_inicio(int dato){
    Nodo* nodo = new Nodo(dato);

    nodo->siguiente = lista;
    lista = nodo;
    return;
}

void Lista::mostrar_lista(){
    Nodo* temporal = nullptr;
    temporal = lista;
    
    while ( temporal!=nullptr ){
        cout<<"Dato: "<<temporal->dato<<" - ";
        temporal = temporal->siguiente;
    }

    cout<<endl;
    return;
}

void Lista::agregar_final(int dato){
    Nodo* nodo = new Nodo(dato);
    Nodo* temporal = nullptr;
    temporal = lista;
    
    // Lista vacía
    if (temporal == nullptr){
        agregar_inicio(dato);
    } else {
        while( temporal != nullptr){
            if(temporal->siguiente == nullptr){
                temporal->siguiente = nodo;
                return;
            }
            temporal = temporal->siguiente;
        }
    }
}

// TODO($user): eliminar nodo
void Lista::eliminar_nodo(int dato){
    return;
}

int main(){
    Lista lista; // objeto lista
    lista.agregar_inicio(5);
    lista.agregar_inicio(6);
    lista.mostrar_lista();
    lista.agregar_final(10);

    Lista* lista_ptr = nullptr;
    lista_ptr = &lista;
    lista_ptr->agregar_inicio(7);
    lista_ptr->mostrar_lista();

    Lista* lista_heap = new Lista();
    lista_heap->agregar_inicio(100);
    lista_heap->mostrar_lista();    

    return 0;
}