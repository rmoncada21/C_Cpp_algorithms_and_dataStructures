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
        void agregar_nodo(int dato);
        void agregar_final();
        void eliminar_nodo();
        void mostrar_lista();
        
        // Destructor
        // ~Lista();
};

// Funciones de la clase Lista
void Lista::agregar_nodo(int dato){
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

int main(){
    Lista lista; // objeto lista
    lista.agregar_nodo(5);
    lista.agregar_nodo(6);
    lista.mostrar_lista();
    return 0;
}