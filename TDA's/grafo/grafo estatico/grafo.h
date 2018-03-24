#ifndef _Grafo_H_INCLUDE
#define _Grafo_H_INCLUDE

#include <exception>

#include <iostream>
#include <fstream>
#include "pila.h"
#include "cola.h"
#include "lista.h"
#include "aristas.h"

#define MAX_TAM 20

#define NOMBRE_ARCHIVO "graph.txt"
#define SEPARADOR '|'

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
		bool adyacencias[MAX_TAM][MAX_TAM];
		int pesos[MAX_TAM][MAX_TAM];
    T verticeNombre[MAX_TAM];
		T verticeVisitado[MAX_TAM];
    int ponderacion;

    Aristas ariG;
    Vertices adyG;

  public:
		Grafo();
		void agregarVertice(string nombreVertice);
		void agregarArista(string nombreVerticeInicial,string nombreVerticeDestino,int peso);

		void mostrarGrafo();
		void mostrarMatrizAdyacencia();

		void buscarVertice(string nombreVertice);
		void buscarArista(string nombreVerticeInicial,string nombreVerticeDestino);

		void modificarVertice(string nombreVertice,string nuevoNombreVertice);
		void modificarArista(string nombreVerticeInicial,string nombreVerticeDestino,string nuevoNombreDestino,long nuevoPeso);

		void eliminarVertice(string nombreVertice);
		void eliminarArista(string nombreVerticeInicial,string nombreVerticeDestino);


		void recorrerAnchura(string nombreVerticeInicial);
		void recorrerProfundidad(string nombreVerticeInicial);

		void rutaAnchura(string nombreInicial,string nombreDestino);
		void rutaProfundidad(string nombreInicial,string nombreDestino);
		void primeroElMejor(string nombreInicial,string nombreDestino);

		bool esVerticeVisitado(int i, string nombreVisitado);

		void desplegarRuta(Pila lista, string destino);

		string buscarAristaImprimir(string nombreVerticeInicial,string nombreVerticeDestino);


		bool aristaExistente(string nombreVerticeInicial,string nombreVerticeDestino);
		bool verticeExistente(string nombreVertice);


		void guardarDatos();
		void cargarDatos();

    //void vaciar_aristas(adyG &);
};

template <class T>
Grafo::Grafo(){
	for(int i=0; i<MAX_TAM; i++)
    {
        for(int j=0; j<MAX_TAM; j++)
        {
            matrizAdyacencia[i][j]=false;
            matrizPesos[i][j]=0;
        }
        nombresVertices[i]="";
    }
    numeroVertices=0;
}

template <class T>
void Grafo::agregarVertice(string nombreVertice){

}

template <class T>
void Grafo::agregarArista(string nombreVerticeInicial,string nombreVerticeDestino,int peso){

}

template <class T>
void Grafo::mostrarGrafo(){

}

template <class T>
void Grafo::mostrarMatrizAdyacencia(){

}

template <class T>
void Grafo::buscarVertice(string nombreVertice){

}

template <class T>
void Grafo::buscarArista(string nombreVerticeInicial,string nombreVerticeDestino){

}

template <class T>
void Grafo::modificarVertice(string nombreVertice,string nuevoNombreVertice){

}

template <class T>
void Grafo::modificarArista(string nombreVerticeInicial,string nombreVerticeDestino,string nuevoNombreDestino,long nuevoPeso){

}

template <class T>
void Grafo::eliminarVertice(string nombreVertice){

}

template <class T>
void Grafo::eliminarArista(string nombreVerticeInicial,string nombreVerticeDestino){

}

template <class T>
void Grafo::recorrerAnchura(string nombreVerticeInicial){

}

template <class T>
void Grafo::recorrerProfundidad(string nombreVerticeInicial){

}

template <class T>
void Grafo::rutaAnchura(string nombreInicial,string nombreDestino){

}

template <class T>
void Grafo::rutaProfundidad(string nombreInicial,string nombreDestino){

}

template <class T>
void Grafo::primeroElMejor(string nombreInicial,string nombreDestino){

}

template <class T>
bool Grafo::esVerticeVisitado(int i, string nombreVisitado){

}

template <class T>
void Grafo::desplegarRuta(Pila lista, string destino){

}

template <class T>
string buscarAristaImprimir(string nombreVerticeInicial,string nombreVerticeDestino){

}

template <class T>
bool Grafo::aristaExistente(string nombreVerticeInicial,string nombreVerticeDestino){

}

template <class T>
bool Grafo::verticeExistente(string nombreVertice){

}

template <class T>
void Grafo::guardarDatos(){

}

template <class T>
void Grafo::cargarDatos(){

}
#endif
