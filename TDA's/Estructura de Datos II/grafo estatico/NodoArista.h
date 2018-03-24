#ifndef NODOARISTA_H_INCLUDED
#define NODOARISTA_H_INCLUDED

class NodoArista{
    string nombreDestino;
    long peso;
    NodoArista* siguiente;
public:
    NodoArista(){
        nombreDestino="";
        peso=0;
        siguiente=NULL;
    }

    NodoArista(string nombre, long pesox){
        nombreDestino=nombre;
        peso=pesox;
        siguiente=NULL;
    }

    void fijaNombreDestino(string nombreDestinox){
        nombreDestino=nombreDestinox;
    }

    void fijaPeso(long pesox){
        peso=pesox;
    }

    void fijaSiguiente(NodoArista* enlace){
        siguiente=enlace;
    }

    string dameNombreDestino(){
        return nombreDestino;
    }

    long damePeso(){
        return peso;
    }

    NodoArista* dameSiguiente(){
        return siguiente;
    }
};

#endif // NODOARISTA_H_INCLUDED
