#include "nodo.h"
Nodo::Nodo() : siguiente(nullptr), dato(0){

}

Nodo::Nodo(const int& d) : Nodo(){
    dato = d;
}

int Nodo::getDato() {
    return dato;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}

void Nodo::setSiguiente(Nodo* s) {
    siguiente = s;
}

void Nodo::setDato(const int& d) {
    dato = d;
}
