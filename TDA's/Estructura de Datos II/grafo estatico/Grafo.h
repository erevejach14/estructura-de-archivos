#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <iostream>
#include <fstream>
#include "Pila.h"
#include "Cola.h"
#include "Lista.h"
#include "NodoArista.h"
#define MAX_TAM 10
using namespace std;

#define NOMBRE_ARCHIVO "graph.txt"
#define SEPARADOR '|'

class Grafo
{
    bool matrizAdyacencia[MAX_TAM][MAX_TAM];
    int matrizPesos[MAX_TAM][MAX_TAM];
    string nombresVertices[MAX_TAM];
    string verticesVisitados[MAX_TAM];
    long numeroVertices;
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
    
    void recorrerProfundidad(string nombreVerticeInicial);
    
    void rutaProfundidad(string nombreInicial,string nombreDestino);

    void primeroElMejor(string nombreInicial,string nombreDestino);

    bool esVerticeVisitado(int i, string nombreVisitado);
    
    void desplegarRuta(Pila lista, string destino);
    
    string buscarAristaImprimir(string nombreVerticeInicial,string nombreVerticeDestino);
    
    bool aristaExistente(string nombreVerticeInicial,string nombreVerticeDestino);
    bool verticeExistente(string nombreVertice);
    
    void guardarDatos();
    void cargarDatos();
};

Grafo::Grafo()
{
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

void Grafo::agregarVertice(string nombreVertice)
{
    if(!verticeExistente(nombreVertice))
    {
        nombresVertices[numeroVertices]=nombreVertice;
        numeroVertices++;
    }
    else
    {
        cout << "Ya existe el vertice"<<endl;
    }
}

void Grafo::agregarArista(string nombreVerticeInicial,string nombreVerticeDestino,int peso)
{
    int fila, columna;
    bool filaEncontrada=false;
    bool columnaEncontrada=false;
    for(int i=0; i<numeroVertices; i++)
    {
        if(nombreVerticeInicial==nombresVertices[i])
        {
            fila=i;
            filaEncontrada=true;
            break;
        }
    }

    for(int i=0; i<numeroVertices; i++)
    {
        if(nombreVerticeDestino==nombresVertices[i])
        {
            columna=i;
            columnaEncontrada=true;
            break;
        }
    }

    if(filaEncontrada && columnaEncontrada)
    {
        if(!matrizAdyacencia[fila][columna])
        {
            matrizPesos[fila][columna]=peso;
            matrizAdyacencia[fila][columna]=true;
        }
        else
        {
            cout << "Arista ya existence."<<endl;
        }
    }
}

void Grafo::mostrarGrafo()
{
    string nombre;
    for(int i=0; i<15; i++)
    {
        cout <<" ";
    }

    for(int i=0; i<numeroVertices; i++)
    {
        nombre=nombresVertices[i];
        cout << nombre[0] << "\t";
    }
    cout <<endl;

    for(int i=0; i<numeroVertices; i++)
    {
        cout << nombresVertices[i];
        for(int k=nombresVertices[i].length(); k<14; k++)
        {
            cout <<" ";
        }
        cout << "|";

        for(int j=0; j<numeroVertices; j++)
        {
            if(matrizAdyacencia[i][j])
            {
                cout << matrizPesos[i][j]<<"\t";
            }
            else
            {
                cout << " - " <<"\t";
            }
        }
        cout <<endl;
    }
}

void Grafo::mostrarMatrizAdyacencia(){
    string nombre;
    for(int i=0; i<15; i++)
    {
        cout <<" ";
    }

    for(int i=0; i<numeroVertices; i++)
    {
        nombre=nombresVertices[i];
        cout << nombre[0] << "\t";
    }
    cout <<endl;

    for(int i=0; i<numeroVertices; i++)
    {
        cout << nombresVertices[i];
        for(int k=nombresVertices[i].length(); k<14; k++)
        {
            cout <<" ";
        }
        cout << "|";

        for(int j=0; j<numeroVertices; j++)
        {
            if(matrizAdyacencia[i][j])
            {
                cout << "1" <<"\t";
            }
            else
            {
                cout << "0" <<"\t";
            }
        }
        cout <<endl;
    }
}

void Grafo::buscarVertice(string nombreVertice)
{
    int indice;
    bool verticeEncontrado=false;
    for(int i=0; i<numeroVertices; i++)
    {
        if(nombreVertice==nombresVertices[i])
        {
            indice=i;
            verticeEncontrado=true;
            break;
        }
    }

    if(verticeEncontrado)
    {
        cout << "\t";
        for(int i=0; i<numeroVertices; i++)
        {
            cout << nombresVertices[i] <<"\t";
        }
        cout <<endl;

        cout << nombresVertices[indice]<< "\t";
        for(int i=0; i<numeroVertices; i++)
        {
            if(matrizAdyacencia[indice][i])
            {
                cout << matrizPesos[indice][i] << "\t";
            }
            else
            {
                cout << "--" << "\t";
            }
        }
        cout <<endl;
    }
    else{
        cout << "Vertice No encontrado, por que no existe."<<endl;
    }
}

void Grafo::buscarArista(string nombreVerticeInicial,string nombreVerticeDestino)
{
    int fila, columna;
    bool filaEncontrada=false;
    bool columnaEncontrada=false;

    for(int i=0; i<numeroVertices; i++)
    {
        if(nombresVertices[i]==nombreVerticeInicial)
        {
            fila=i;
            filaEncontrada=true;
            break;
        }
    }

    for(int i=0; i<numeroVertices; i++)
    {
        if(nombresVertices[i]==nombreVerticeDestino)
        {
            columna=i;
            columnaEncontrada=true;
            break;
        }
    }

    if(columnaEncontrada && filaEncontrada)
    {
        cout << "Vertice encontrado de:  " << nombresVertices[fila] << " a " << nombresVertices[columna]<<endl;
        cout << "Peso: " << matrizPesos[fila][columna]<<endl;
    }
    else{
        cout << "Arista No encontrada, por que No existe."<<endl;
    }
}

void Grafo::modificarVertice(string nombreVertice,string nuevoNombreVertice)
{
    bool verticeEncontrado=false;
    int indice;
    for(int i=0; i<numeroVertices; i++)
    {
        if(nombreVertice==nombresVertices[i])
        {
            indice=i;
            verticeEncontrado=true;
            break;
        }
    }

    if(verticeEncontrado)
    {
        if(!verticeExistente(nuevoNombreVertice))
        {
            nombresVertices[indice]=nuevoNombreVertice;
        }
        else
        {
            cout << "Ya existe el vertice"<<endl;
        }
    }
    else
    {
        cout << "Vertice No existente."<<endl;
    }
}

void Grafo::modificarArista(string nombreVerticeInicial,string nombreVerticeDestino,string nuevoNombreDestino,long nuevoPeso)
{
    bool filaEncontrada=false;
    bool columnaEncontrada=false;
    bool nuevaColumnaEncontrada=false;
    int columna, fila, nuevaColumna;

    for (int i=0; i<numeroVertices; i++)
    {
        if(nombreVerticeInicial==nombresVertices[i])
        {
            fila=i;
            filaEncontrada=true;
            break;
        }
    }

    for(int i=0; i<numeroVertices; i++)
    {
        if(nombreVerticeDestino==nombresVertices[i])
        {
            columna=i;
            columnaEncontrada=true;
            break;
        }
    }

    for (int i=0; i<numeroVertices; i++)
    {
        if(nuevoNombreDestino==nombresVertices[i])
        {
            nuevaColumna=i;
            nuevaColumnaEncontrada=true;
            break;
        }
    }

    if(filaEncontrada && columnaEncontrada && nuevaColumnaEncontrada)
    {
        if(!matrizAdyacencia[fila][nuevaColumna])
        {
            if(matrizAdyacencia[fila][columna]){
            matrizPesos[fila][nuevaColumna]=nuevoPeso;
            matrizAdyacencia[fila][columna]=false;
            matrizAdyacencia[fila][nuevaColumna]=true;
            }
            else{
                cout << "No existe un Vertice en esa direccion."<<endl;
            }
        }
        else
        {
            cout << "Ya existe una arista, intente con otro destino."<<endl;
        }
    }
}

void Grafo::eliminarVertice(string nombreVertice)
{
    bool verticeEncontrado;
    int indice;

    for(int i=0; i<numeroVertices; i++)
    {
        if(nombreVertice==nombresVertices[i])
        {
            indice=i;
            verticeEncontrado=true;
            break;
        }
    }

    if(verticeEncontrado)
    {

        for(int i=indice; i<numeroVertices-1; i++)
        {
            nombresVertices[i]=nombresVertices[i+1];
        }

        for(int i=indice; i<numeroVertices-1; i++)
        {
            for(int j=0; j<numeroVertices; j++)
            {
                matrizPesos[i][j]=matrizPesos[i+1][j];
                matrizAdyacencia[i][j]=matrizAdyacencia[i+1][j];
            }
        }

        for(int i=0; i<numeroVertices-1; i++)
        {
            for(int j=indice; j<numeroVertices-1; j++)
            {
                matrizPesos[i][j]=matrizPesos[i][j+1];
                matrizAdyacencia[i][j]=matrizAdyacencia[i][j+1];
            }
        }
        numeroVertices--;
    }
    else{
        cout << "Imposible Eliminar un vertice, no Existente."<<endl;
    }
}

void Grafo::eliminarArista(string nombreVerticeInicial,string nombreVerticeDestino)
{
    bool filaEncontrada=false;
    bool columnaEncontrada=false;
    int fila,columna;

    for(int i=0; i<numeroVertices; i++)
    {
        if(nombreVerticeInicial==nombresVertices[i])
        {
            fila=i;
            filaEncontrada=true;
            break;
        }
    }

    for(int i=0; i<numeroVertices; i++)
    {
        if(nombreVerticeDestino==nombresVertices[i])
        {
            columna=i;
            columnaEncontrada=true;
            break;
        }
    }

    if(columnaEncontrada && filaEncontrada)
    {
        matrizAdyacencia[fila][columna]=false;
    }
    else{
        cout << "Imposible Eliminar una Arista inexistente."<<endl;
    }
}

void Grafo::recorrerProfundidad(string nombreVerticeInicial)
{
    string nombre;
    Pila lista;
    lista.insertar(nombreVerticeInicial);
    int i=0;
    int indice;
    bool indiceEncontrado=false;
    if(verticeExistente(nombreVerticeInicial))
    {
        cout << "Ruta: ";
        while(!lista.esPilaVacia())
        {
            nombre=lista.sacarDato();

            if(!esVerticeVisitado(i,nombre))
            {
                cout << " -> " << nombre;

                verticesVisitados[i++]=nombre;

                for(int j=0; j<numeroVertices; j++)
                {
                    if(nombre==nombresVertices[j])
                    {
                        indice=j;
                        indiceEncontrado=true;
                        break;
                    }
                }

                if(indiceEncontrado)
                {
                    for(int k=0; k<numeroVertices; k++)
                    {
                        if(matrizAdyacencia[indice][k])
                        {
                            if(!esVerticeVisitado(i,nombresVertices[k]))
                            {
                                lista.insertar(nombresVertices[k]);
                            }
                        }
                    }
                }
            }
        }
        cout <<endl;
    }
    else
    {
        cout << "No Existente, el vertice ingresado"<<endl;
    }
}

void Grafo::rutaProfundidad(string nombreInicial,string nombreDestino)
{
    string nombre;
    int indiceOrigen;
    bool verticeEncontrado=false;
    Pila lista;
    lista.insertar(nombreInicial);
    Pila listado;
    listado.insertar(nombreInicial);
    int i=0;
    if(verticeExistente(nombreDestino) && verticeExistente(nombreInicial))
    {
        while(!lista.esPilaVacia())
        {
            nombre=lista.sacarDato();

            if(!esVerticeVisitado(i,nombre))
            {
                if(nombre==nombreDestino)
                {
                    //mostrarRuta encontrada
                    desplegarRuta(listado,nombreDestino);
                    return;
                }
                verticesVisitados[i++]=nombre;

                verticeEncontrado=false;
                for(int j=0; j<numeroVertices; j++)
                {
                    if(nombresVertices[j]==nombre)
                    {
                        indiceOrigen=j;
                        verticeEncontrado=true;
                        break;
                    }
                }

                if(verticeEncontrado)
                {
                    for(int j=0; j<numeroVertices; j++)
                    {
                        if(matrizAdyacencia[indiceOrigen][j])
                        {
                            if(!esVerticeVisitado(i,nombresVertices[j]))
                            {
                                lista.insertar(nombresVertices[j]);
                                listado.insertar(nombresVertices[indiceOrigen]);
                                listado.insertar(nombresVertices[j]);
                            }
                        }
                    }
                }
            }
        }
        cout << "No existe una ruta entre esos vertices."<<endl;
    }
    else
    {
        cout << "No existe ese vertice de origen."<<endl;
    }
}

void Grafo::primeroElMejor(string nombreInicial,string nombreDestino)
{
    NodoArista* auxiliarArista;
    int indiceVertice=0;
    Lista costos, listaOrdenada;

    if(verticeExistente(nombreInicial) && verticeExistente(nombreDestino))
    {
        costos.insertar(nombreInicial,0);
        listaOrdenada.insertarOrdenadamente(nombreInicial,0);
        Pila ruta;
        ruta.insertar(nombreInicial);

        string verticeActual;
        long costoActual=0;

        while(!listaOrdenada.estaVacia())
        {
            auxiliarArista=listaOrdenada.sacarDato();
            //costos.sacarDato();
            verticeActual=auxiliarArista->dameNombreDestino();
            costoActual=auxiliarArista->damePeso();

            if(verticeActual==nombreDestino)
            {
                desplegarRuta(ruta,nombreDestino);
                return;
            }

            for(int i=0; i<numeroVertices; i++)
            {
                if(nombresVertices[i]==verticeActual)
                {
                    indiceVertice=i;
                    break;
                }
            }

            for(int i=0; i<numeroVertices; i++)
            {
                if(matrizAdyacencia[indiceVertice][i])
                {
                    costoActual=costoActual+ matrizPesos[indiceVertice][i];
                    if(!costos.esVerticeEncontrado(nombresVertices[i]))
                    {
                        costos.insertar(nombresVertices[i],costoActual);
                        listaOrdenada.insertarOrdenadamente(nombresVertices[i],costoActual);
                        ruta.insertar(nombresVertices[indiceVertice]);
                        // probar esto, creo que era mas simple ruta.insertar(verticeActual);
                        ruta.insertar(nombresVertices[i]);
                        costoActual=costoActual-matrizPesos[indiceVertice][i];
                    }
                    else
                    {
                        if(costoActual<costos.buscarDato(nombresVertices[i])->damePeso())
                        {
                            costos.modificarDato(nombresVertices[i],costoActual);
                            listaOrdenada.modificarDato(nombresVertices[i],costoActual);
                            ruta.insertar(verticeActual);
                            // asi lo tenia antes ruta.insertar(nombresVertices[indiceVertice]);
                            ruta.insertar(nombresVertices[i]);
                        }
                        costoActual=costoActual-matrizPesos[indiceVertice][i];
                    }
                }
            }
        }
        cout << "No existe una ruta entre esos vertices."<<endl;
    }
    else
    {
        cout << "Error, Alguno de los dos Vertices, No Existe.";
    }
}

void Grafo::desplegarRuta(Pila lista, string destino)
{
    string destinoActual;
    destinoActual=destino;

    while(!lista.esPilaVacia())
    {
        cout <<destinoActual;

        while(!lista.esPilaVacia() && lista.sacarDato()!=destinoActual)
        {
            lista.sacarDato();
        }

        if(!lista.esPilaVacia())
        {
            destinoActual=lista.sacarDato();
        }

        if(!lista.esPilaVacia()){
            cout << "<-";
        }
    }
    cout <<endl;
}

bool Grafo::esVerticeVisitado(int i, string nombreVisitado)
{
    for(int j=0; j<i; j++)
    {
        if(nombreVisitado==verticesVisitados[j])
        {
            return true;
        }
    }
    return false;
}

bool Grafo::verticeExistente(string nombreVertice)
{
    for(int i=0; i<numeroVertices; i++)
    {
        if(nombreVertice==nombresVertices[i])
        {
            return true;
        }
    }
    return false;
}

void Grafo::guardarDatos()
{
    ofstream archivo;
    archivo.open(NOMBRE_ARCHIVO,ios::out);
    if(archivo.is_open())
    {

        for(int i=0; i<numeroVertices; i++)
        {
            archivo << nombresVertices[i] << SEPARADOR;
        }
        archivo <<endl;

        for(int i=0; i<numeroVertices; i++)
        {
            for(int j=0; j<numeroVertices; j++)
            {
                if(matrizAdyacencia[i][j])
                {
                    archivo << matrizPesos[i][j] << SEPARADOR;
                }
                else
                {
                    archivo << "--" << SEPARADOR;
                }
            }
            archivo <<endl;
        }
    }
    archivo.close();
}

void Grafo::cargarDatos()
{
    ifstream archivoEncontrado;
    archivoEncontrado.open(NOMBRE_ARCHIVO,ios::in);

    string cadenaLugares;
    string nuevoTipo;
    int maxTam;
    if(archivoEncontrado.is_open())
    {
        int posicion;
        int posicionAux=-1;

        getline(archivoEncontrado,cadenaLugares);

        maxTam=cadenaLugares.length();
        while(posicionAux<maxTam-2)
        {


            posicion=cadenaLugares.find_first_of(SEPARADOR,posicionAux+1);


            nuevoTipo=cadenaLugares.substr(posicionAux+1,posicion-(posicionAux+1));


            posicionAux=posicion;


            agregarVertice(nuevoTipo);
        }

        int peso;
        for(int i=0; i<numeroVertices; i++)
        {
            posicionAux=-1;
            getline(archivoEncontrado,cadenaLugares);
            maxTam=cadenaLugares.length();
            for(int j=0; j<numeroVertices && posicionAux<maxTam-1; j++)
            {
                posicion=cadenaLugares.find_first_of(SEPARADOR,posicionAux+1);

                nuevoTipo=cadenaLugares.substr(posicionAux+1,posicion-(posicionAux+1));

                posicionAux=posicion;
                if(nuevoTipo[0]!='-')
                {
                    peso=atoi(nuevoTipo.c_str());
                    agregarArista(nombresVertices[i],nombresVertices[j],peso);
                }
            }
        }
    }
    archivoEncontrado.close();
}

#endif // GRAFO_H_INCLUDED
