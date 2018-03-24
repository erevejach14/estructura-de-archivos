#include "lista.h"

bool Lista::posicionValida(Nodo* p) {
    Nodo* aux = ancla;
    while(aux != nullptr) {
        if(aux == p) {
            return true;
        }
        aux = aux->getSiguiente();
    }
    return false;
}

Lista::Lista() : ancla(nullptr) {

}

void Lista::insertar(Nodo* p, const int& d) {
    if(!posicionValida(p) and p != nullptr) {
        std::cout << "Error, posicion invalida para insertar" << std::endl;
        return;
    }
    Nodo* aux = new Nodo(d);
    if(aux == nullptr) {
        std::cout << "Error, no hay espacio para insertar" << std::endl;
        return;
    }
    if(p == nullptr) {
        aux->setSiguiente(ancla);
        ancla = aux;
    }
    else {
		aux->setSiguiente(p->getSiguiente());
		p->setSiguiente(aux);
	}
}
void Lista::borrar(Nodo* p) {
    Nodo* aux = ancla;
    if(p == ancla){
        ancla = ancla->getSiguiente();
    }
    else {
        aux->setSiguiente(p->getSiguiente());
    }
    delete p;
}

void Lista::mostrar() {
    Nodo* aux = ancla;
    while (aux != nullptr) {
        std::cout << aux->getDato() << "\n";
        aux = aux->getSiguiente();
    }
}

int Lista::recuperar(Nodo* p) {
    if (!posicionValida(p)) {
        std::cout << "Posición invalida para recuperar" << "\n";
        return 0;
    }
    return p->getDato();
}

Nodo* Lista::primero() {
    return ancla;
}

Nodo* Lista::ultimo() {
    Nodo* aux = ancla;
    while (aux->getSiguiente() != nullptr) {
        aux = aux->getSiguiente();
    }
    return aux;
}

Nodo* Lista::siguiente(Nodo* p) {
    if (!posicionValida(p)) {
        std::cout << "posicion invalida para obtener su siguiente" << "\n";
        return nullptr;
    }
    return p->getSiguiente();
}

Nodo* Lista::previo(Nodo* p) {
    if (!posicionValida(p)) {
        std::cout << "posicion invalida para su anterior" << "\n";
        return nullptr;
    }
    Nodo* aux = ancla;
    while (aux != nullptr and aux->getSiguiente() != p) {
        aux = aux->getSiguiente();
    }
    return aux;
}

Nodo* Lista::buscar(const int& d) {
    Nodo* aux = ancla;
    while (aux != nullptr and aux->getDato() != d) {
        aux = aux->getSiguiente();
    }
    return aux;
}

void Lista::borrarTodo() {
    Nodo *aux;
    while (ancla != nullptr) {
        aux = ancla;
        ancla = ancla->getSiguiente();
        delete aux;
    }
}

Lista::~Lista() {
    borrarTodo();
}

Nodo* Lista::mayor() {
    Nodo* aux = ancla;
    Nodo* mayor = aux;
    while (aux->getSiguiente() != nullptr) {
        if (aux->getDato() >= mayor->getDato()) {
            mayor = aux;
        }
        aux = aux->getSiguiente();
    }
    return mayor;
}

bool Lista::estaVacia() {
    return ancla == nullptr;
}
