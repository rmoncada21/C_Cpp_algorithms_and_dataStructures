#include <iostream>

using namespace std;

class Nodo{
    private:
        int dato;
        Nodo* siguiente;
        friend class Pila;
    public:
    // Constructor
    Nodo() : siguiente(nullptr) {}
    Nodo(int d) : dato(d), siguiente(nullptr) {}
    int get_dato() {return dato;}
};

class Pila{
    private:
        Nodo* pila;

    public:
    // Constructor
    Pila () : pila(nullptr) {}

    // Métodos
    void push(int);
    void pop();
    void mostrar();
    int vacia();
    void top();
    // void isFull();

    // Destructor
    ~Pila();
};

Pila::~Pila(){
    while(pila != nullptr){
        Nodo* actual = pila;
        pila = pila->siguiente;
        delete actual;
    }
    pila = nullptr;
}

int Pila::vacia(){
    if(pila == nullptr){
        return 1;
    } else {
        return 0;
    }
}

// Agregar nodos
void Pila::push(int dato){
    Nodo* temporal = new Nodo(dato);
    temporal->siguiente = pila;
    pila = temporal;
    return;
}

// Mostrar los elementos de la pila
void Pila::mostrar(){
    Nodo* temporal = nullptr;
    temporal = pila;

    while(temporal != nullptr){
        cout<<" Dato: "<<temporal->dato;
        temporal = temporal->siguiente;
    }
    cout<<endl;
    return;
}

// Eliminar el primer nodo. Sacar el primer dato
void Pila::pop(){
    Nodo* temporal = nullptr;
    temporal =pila;

    if(vacia()){
        cout<<" Pila vacía "<<endl;
        return;
    }

    pila = temporal->siguiente;
    delete temporal;
    return;
}

void Pila::top(){
    cout<<" Top: "<<pila->dato<<endl;
    return;
}

int main(){
    Pila pila;
    
    pila.push(10);
    pila.push(15);
    pila.push(20);
    pila.mostrar();
    pila.top();
    pila.push(30);
    pila.push(35);
    pila.push(40);
    pila.mostrar(); 
    pila.top();
    pila.pop();
    pila.mostrar();
    return 0;
}