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

void Cola::desencolar(){
    Nodo* actual = nullptr;
    actual = cola;

    while(actual != nullptr){
        Nodo* anterior = nullptr;
        anterior = actual;
        actual = actual->siguiente;
        if (actual->siguiente == nullptr){
            // cout<<" Ultimo nodo dato: "<<actual->dato<< endl;
            // return;
            anterior->siguiente = nullptr;
            delete actual;
            return;
        }
    }

}

Nodo* Cola::top(){
    Nodo* temporal = nullptr;
    temporal = cola;

    while(temporal != nullptr){
        if(temporal->siguiente == nullptr){
            return temporal;
        }
        temporal = temporal->siguiente;
    }
    return temporal;
}

void Cola::liberar_memoria(){
    while(cola != nullptr){
        Nodo* temporal = nullptr;
        temporal = cola;
        delete temporal;
        cola = cola->siguiente;
        return;
    }
}

int main(){
    Cola cola; //  objeto

    cola.encolar(10);
    cola.encolar(20);
    cola.encolar(30);
    cola.encolar(40);
    cola.encolar(50);
    cola.mostrar();
    cola.desencolar();
    cola.mostrar();
    cola.encolar(100);
    cola.encolar(150);
    cola.encolar(200);
    cola.mostrar();
    cola.desencolar();
    cola.mostrar();
    Nodo* top = cola.top();
    cout<<" Dato Top: "<<top->get_dato()<<endl;
    cola.liberar_memoria();
    if(cola.vacio()){
        cout<<" Vacío "<<endl;
    }
    return 0;
}