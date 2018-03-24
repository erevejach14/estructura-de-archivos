#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

class Cola{
    Nodo* inicio;
    Nodo* fin;
public:
    Cola(){
        inicio=NULL;
        fin=NULL;
    }

    bool esColaVacia(){
        return inicio==NULL;
    }

    void insertar(string nombreNodo){
        if(esColaVacia()){
            Nodo* nuevoVertice=new Nodo(nombreNodo);
            inicio=nuevoVertice;
            fin=inicio;
        }
        else{
            fin->fijaSiguiente(new Nodo(nombreNodo));
            fin=fin->dameSiguiente();
        }
    }

    string sacarDato(){
        string nombre;
        Nodo* auxiliar;
        auxiliar=inicio;
        if(esColaVacia()){
            //cout<<"cola vacia"<<endl;
        }
        else{
            inicio=auxiliar->dameSiguiente();
            if(esColaVacia()){
                fin=NULL;
            }
        }
        nombre=auxiliar->dameNombreVertice();
        delete auxiliar;
        return nombre;
    }
};

#endif // COLA_H_INCLUDED
