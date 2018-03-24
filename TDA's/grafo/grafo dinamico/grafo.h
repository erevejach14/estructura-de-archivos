#ifndef _Grafo_H_INCLUDE
#define _Grafo_H_INCLUDE

#include <exception>


#include "aristas.h"
#include "vertice.h"

class GraphException : public std::exception {
private:
	std::string msg;
public:
	explicit GraphException(const char* message):msg(message){}
	explicit GraphException(const std::string message):msg(message){}
	virtual ~GraphException()throw(){}
	virtual const char* what() const throw(){return msg.c_str();}

	};

template <class T>
class Grafo{
  private:
    T pais;
    int ponderacion;

    Aristas ariG;
    Vertices adyG;

  public:
    void insertarNodo();
		void insertarArista();
    void agregaArista(adyG &, adyG &, ariG &);
    void vaciarAristas(adyG &);
    void eliminarNodo();
    void eliminarArista();
    void mostrarGrafo();
    void mostrarAristas();
};


template <class T>
void insertar_nodo(){

}

template <class T>
void insertar_arista(){

}

template <class T>
void agrega_arista(adyG &, adyG &, ariG &){

}

template <class T>
void vaciar_aristas(adyG &){

}

template <class T>
void eliminar_nodo(){

}

template <class T>
void eliminar_arista(){

}

template <class T>
void mostrar_grafo(){

}

template <class T>
void mostrar_aristas(){

}
#endif
