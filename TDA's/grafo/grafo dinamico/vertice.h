#ifndef VERTICES_H_INCLUDE
#define VERTICES_H_INCLUDE

#include "aristas.h"

class Aristas;

template <class V, class A>
class Vertices{
  private:
    V dato;
    Vertices<V>* nodoVertSig;
    Aristas<A>* nodoAriAdya;

  public:
    Vertices();
	  Vertices(const V&);

  	V& getData();
  	Vertices<V>* getNext();
  	Aristas<A>* getArista();

  	void setData(const V&);
  	void setNext(Vertices<V>*);
  	void setArista(Aristas<A>*);
};

template <class V, class A>
Vertices<V>::Vertices(){
  nodoVertSig = nullptr;
  nodoAriAdya = nullptr;
}

template <class V, class A>
Vertices<V>::Vertices(const V& elemento) : Vertices() {
  dato = elemento;
}

template <class V, class A>
V& Vertices<V>::getData() {
	return dato;
}

template <class V, class A>
Vertices<V>* Vertices<V>::getNext() {
	return nodoVertSig;
}

template <class V, class A>
Aristas<A>* Vertices<V>::getArista() {
	return nodoAriAdya;
}

template <class V, class A>
void Vertices<V>::setData(const V& elemento) {
	dato = elemento;
}

template <class V, class A>
void Vertices<V>::setNext(Vertices* ver) {
	nodoVertSig = ver;
}

template <class V, class A>
void Vertices<V>::setArista(Vertices* ar) {
	nodoAriAdya = ar;
}

#endif
