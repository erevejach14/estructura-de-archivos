#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

class Nodo {
private:
    Nodo* siguiente;
    int dato;
public:
    Nodo();
    Nodo(const int&);
    int getDato();
    Nodo* getSiguiente();
    void setSiguiente(Nodo*);
    void setDato(const int&);
};

#endif // NODO_H_INCLUDED
