#ifndef ARISTAS_H_INCLUDE
#define ARISTAS_H_INCLUDE

#include "vertice.h"

class Vertices;

template <class A, class V>
class Aristas{
  private:
    A dato;
    Vertices<V> *nodoVertDest;
    Aristas<A> *nodoAriSig;
  public:
    Aristas();
	  Aristas(const A&);

  	A getData();
  	Aristas<A>* getNext();
  	Vertices<V>* getVertice();

  	void setData(const A&);
  	void setNext(Aristas<A>*);
  	void setVertice(Vertices<V>*);
};

template <class A, class V>
Aristas<A>::Aristas(){
  nodoVertDest = nullptr;
  nodoAriSig = nullptr;
}

template <class A, class V>
Aristas<A>::Aristas(const A& elemento) : Aristas() {
  dato = elemento;
}

template <class A, class V>
A Aristas<A>::getData() {
	return dato;
}

template <class A, class V>
Aristas<A>* Aristas<A>::getNext() {
	return nodoAriSig;
}

template <class A, class V>
Vertices<V>* Aristas<A>::getVertice() {
	return nodoVertDest;
}

template <class A, class V>
void Aristas<A>::setData(const A& elemento) {
	dato = elemento;
}

template <class A, class V>
void Aristas<A>::setNext(Aristas<A>* ar) {
	nodoAriSig = ar;
}

template <class A, class V>
void Aristas<A>::setVertice(Vertices<V>* ver) {
	nodoVertDest = ver;
}

#endif
