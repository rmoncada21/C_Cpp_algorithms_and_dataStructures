#include <iostream>

using namespace std;

class Nodo{
    private:
        int dato;
        Nodo* siguiente;
        friend class Cola;
    public:
        // constructor
        Nodo() : siguiente(nullptr) {};
        Nodo(int d) : dato(d), siguiente(nullptr) {};
        int get_dato() {return dato;}
};

class Cola{
    private:
        Nodo* cola;
    public:
        // Constructor
        Cola() : cola(nullptr) {}

        // Métodos
        int vacio();
        void encolar(int dato);
        void mostrar();
        void desencolar();
        Nodo* top();
        void liberar_memoria();

        // Destructor
        // liberar_memoria();
};

int Cola::vacio(){
    if(cola == nullptr){
        return 0;
    }else{
        return 1;
    }
}

void Cola::encolar(int dato){
    Nodo* nodo = new Nodo(dato);
    nodo->siguiente = cola;
    cola = nodo;
    return;
}

void Cola::mostrar(){
    Nodo* temporal = nullptr;
    temporal = cola;
    
    while(temporal != nullptr){
        cout<<" Dato: "<<temporal->dato;
        temporal = temporal->siguiente;
    }

    cout<<endl;
    return;
}

int main(){
    Cola cola; //  objeto

    cola.encolar(10);
    cola.encolar(20);
    cola.mostrar();

    return 0;
}