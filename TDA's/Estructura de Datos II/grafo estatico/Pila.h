#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include "Nodo.h"
class Pila{
    Nodo* siguiente;
    Nodo* cima;
public:
    Pila(){
        siguiente=NULL;
        cima=NULL;
    }

    bool esPilaVacia(){
        return cima==NULL;
    }

    void insertar(string nombreNodo){
        Nodo* nuevo;
        nuevo=new Nodo(nombreNodo);
        nuevo->fijaSiguiente(cima);
        cima=nuevo;
    }

    string sacarDato(){
        string nombre;
        Nodo* auxiliar;

        if (esPilaVacia()){
            return NULL;
        }
        auxiliar=cima;
        nombre=cima->dameNombreVertice();
        cima=cima->dameSiguiente();
        auxiliar->fijaSiguiente(NULL);
        delete auxiliar;
        return nombre;
    }

    string mostrarCima(){
        return cima->dameNombreVertice();
    }
};

#endif // PILA_H_INCLUDED
