#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include "nodo.h"

class Lista {
private:
    Nodo* ancla;
    bool posicionValida(Nodo*);
public:
    Lista();
    ~Lista();
    bool estaVacia();
    void insertar(Nodo*, const int&);
    void borrar(Nodo*);
    void mostrar();
    int recuperar(Nodo*);
    Nodo* primero();
    Nodo* ultimo();
    Nodo* siguiente(Nodo*);
    Nodo* previo(Nodo*);
    Nodo* buscar(const int&);
    void borrarTodo();
    Nodo* mayor();
};


#endif // LISTA_H_INCLUDED
