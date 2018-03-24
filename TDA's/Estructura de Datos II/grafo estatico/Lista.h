#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "NodoArista.h"
class Lista{
    NodoArista* primero;
public:
    Lista(){
        primero=NULL;
    }

    void insertar(string destino, int peso){
        NodoArista* nueva;
        nueva=new NodoArista(destino,peso);
        if(primero==NULL){
            primero=nueva;
        }
        else{
            NodoArista* auxiliar;
            auxiliar=primero;
            while(auxiliar->dameSiguiente()!=NULL){
                auxiliar=auxiliar->dameSiguiente();
            }
            auxiliar->fijaSiguiente(nueva);
        }
    }

    bool esVerticeEncontrado(string nombreVertice){
        NodoArista* auxiliar;
        auxiliar=primero;
        while(auxiliar!=NULL){
            if(auxiliar->dameNombreDestino()==nombreVertice){
                return true;
            }
            auxiliar=auxiliar->dameSiguiente();
        }
        return false;
    }

    NodoArista* buscarDato(string nombreVertice){
        NodoArista* auxiliar;
        auxiliar=primero;
        while(auxiliar!=NULL){
            if(auxiliar->dameNombreDestino()==nombreVertice){
                return auxiliar;
            }
            auxiliar=auxiliar->dameSiguiente();
        }
        return NULL;
    }

    void modificarPrimerDato(long peso){
        primero->fijaPeso(peso);
    }

    void modificarDato(string nombreDato, long peso){
        NodoArista* auxiliar;
        auxiliar=primero;
        while(auxiliar!=NULL){
            if(auxiliar->dameNombreDestino()==nombreDato){
                break;
            }
            auxiliar=auxiliar->dameSiguiente();
        }
        if(auxiliar!=NULL){
            auxiliar->fijaPeso(peso);
        }
    }

    bool estaVacia(){
        return primero==NULL;
    }

    void insertarOrdenadamente(string destino, int peso){
        NodoArista* nueva;
        nueva=new NodoArista(destino,peso);
        if(primero==NULL){
            primero=nueva;
        }
        else if(peso<primero->damePeso()){
            nueva->fijaSiguiente(primero);
            primero=nueva;
        }
        else{
            NodoArista *anterior, *p;
            anterior=p=primero;
            while((p->dameSiguiente()!=NULL) && (peso>p->damePeso())){
                anterior=p;
                p=p->dameSiguiente();
            }
            if (peso>p->damePeso()) // se inserta después del último
                anterior=p;
            // se procede al enlace del nuevo nodo
            nueva->fijaSiguiente(anterior->dameSiguiente());
            anterior->fijaSiguiente(nueva);
        }
    }

    NodoArista* sacarDato(){
        NodoArista* auxiliar;
        auxiliar=primero;
        primero=primero->dameSiguiente();
        auxiliar->fijaSiguiente(NULL);
        return auxiliar;
    }

    NodoArista* mostrarPrimerDato(){
        return primero;
    }

    void mostrarDatos(){
        NodoArista* auxiliar;
        auxiliar=primero;
        while(auxiliar!=NULL){
            cout << auxiliar->dameNombreDestino() << " Tiene un peso de: " << auxiliar->damePeso() << endl;
            auxiliar=auxiliar->dameSiguiente();
        }
    }
};

#endif // LISTA_H_INCLUDED
