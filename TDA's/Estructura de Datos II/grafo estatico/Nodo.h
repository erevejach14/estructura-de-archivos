#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>
using namespace std;
class Nodo{
    string nombre;
    Nodo* siguiente;
public:
    Nodo(){
        siguiente=NULL;
    }

    Nodo(string nombreVertice){
        siguiente=NULL;
        nombre=nombreVertice;
    }

    void fijaSiguiente(Nodo* enlace){
        siguiente=enlace;
    }

    void fijaNombreVertice(string nombreVertice){
        nombre=nombreVertice;
    }

    Nodo* dameSiguiente(){
        return siguiente;
    }

    string dameNombreVertice(){
        return nombre;
    }
};


#endif // NODO_H_INCLUDED
