#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Grafo.h"

using namespace std;

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

enum menuDestinos {AGREGAR_VERTICE=1,AGREGAR_ARISTA,MOSTRAR_GRAFO,MOSTRAR_MATRIZ_ADYACENCIA,
BUSCAR_VERTICE,BUSCAR_ARISTA,MODIFICAR_VERTICE,MODIFICAR_ARISTA, ELIMINAR_VERTICE,
ELIMINAR_ARISTA,RECORRER_PROFUNDIDAD, MOSTRAR_RUTAS,SALIR };

void agregarVertice();
void agregarArista();
void mostrarGrafo();
void buscarVertice();
void buscarArista();
void modificarVertice();
void modificarArista();
void eliminarVertice();
void eliminarArista();
void recorridoProfundidad();
void mostrarRutas();
void cargarDatos();

Grafo grafoPrincipal;

int main(){
    ofstream archivo;
    bool continuarBucle;
    int opcion;
    grafoPrincipal.cargarDatos();
    do{
        cout << "Menu: "<<endl;
        cout << "1) Agregar Nodo."<<endl;
        cout << "2) Agregar Arista."<<endl;
        cout << "3) Mostrar Grafo."<<endl;
        cout << "4) Mostrar Matriz Adyacencia." <<endl;
        cout << "5) Buscar Nodo."<<endl;
        cout << "6) Buscar Arista."<<endl;
        cout << "7) Modificar Nodo."<<endl;
        cout << "8) Modificar Arista."<<endl;
        cout << "9) Eliminar Nodo."<<endl;
        cout << "10) Eliminar Arista."<<endl;
        cout << "11) Recorrer Grafo por Profundidad."<<endl;
        cout << "12) Mostrar Rutas."<<endl;
        cout << "13) Salir."<<endl;
        cout << "Que desea hacer? ";
        cin >> opcion;
        cin.get();
        switch(opcion){
        case AGREGAR_VERTICE:
            agregarVertice();
            break;
        case AGREGAR_ARISTA:
            agregarArista();
            break;
        case MOSTRAR_GRAFO:
            grafoPrincipal.mostrarGrafo();
            break;
        case MOSTRAR_MATRIZ_ADYACENCIA:
            grafoPrincipal.mostrarMatrizAdyacencia();
            break;
        case BUSCAR_VERTICE:
            buscarVertice();
            break;
        case BUSCAR_ARISTA:
            buscarArista();
            break;
        case MODIFICAR_VERTICE:
            modificarVertice();
            break;
        case MODIFICAR_ARISTA:
            modificarArista();
            break;
        case ELIMINAR_VERTICE:
            eliminarVertice();
            break;
        case ELIMINAR_ARISTA:
            eliminarArista();
            break;
        case RECORRER_PROFUNDIDAD:
            recorridoProfundidad();
            break;
        case MOSTRAR_RUTAS:
            mostrarRutas();
            break;
        case SALIR:
            break;
        default:
            cout << "Opcion no encontrado."<<endl;
        }
        continuarBucle=opcion!=SALIR;
        if(continuarBucle){
            cout << "Presione enter para continuar..."<<endl;
            cin.get();
            system(CLEAR);
        }
    }
    while(continuarBucle);
    grafoPrincipal.guardarDatos();
    return 0;
}

void agregarVertice()
{
    string nombreVertice;
    cout << "Introduce el nombre del Nuevo Vertice: ";
    getline(cin,nombreVertice);
    grafoPrincipal.agregarVertice(nombreVertice);
}

void agregarArista()
{
    string nombreVerticeInicial,nombreVerticeDestino;
    long peso;
    cout << "Introduce el nombre del Vertice: ";
    getline(cin,nombreVerticeInicial);
    cout << "Introduce el nombre del Vertice Destino: ";
    getline(cin,nombreVerticeDestino);
    cout << "Introduzca el peso: ";
    cin >> peso;
    cin.get();
    grafoPrincipal.agregarArista(nombreVerticeInicial,nombreVerticeDestino,peso);
}

void buscarVertice(){
    string nombreVerticeBuscar;
    cout << "Introduce el nombre del Vertice a Buscar: "<<endl;
    getline(cin,nombreVerticeBuscar);
    grafoPrincipal.buscarVertice(nombreVerticeBuscar);
}

void buscarArista(){
    string nombreVerticeInicial, nombreVerticeDestino;
    cout << "Introduce el vertice de Inicio: ";
    getline(cin,nombreVerticeInicial);
    cout << "Introduce el Vertice Destino: ";
    getline(cin,nombreVerticeDestino);
    grafoPrincipal.buscarArista(nombreVerticeInicial,nombreVerticeDestino);
}

void modificarVertice(){
    string nombreVerticeModificar, nuevoNombreVertice;
    cout << "Introduce el nombre del vertice a modifiar: ";
    getline(cin,nombreVerticeModificar);
    cout << "Introduce el nuevo nombre del Vertice: ";
    getline(cin,nuevoNombreVertice);
    grafoPrincipal.modificarVertice(nombreVerticeModificar,nuevoNombreVertice);
}

void modificarArista(){
    string nombreVerticeInicial, nombreVerticeDestino, nuevoNombreVerticeDestino;
    long nuevoPeso;
    cout << "Introduce el nombre del Vertice: ";
    getline(cin,nombreVerticeInicial);
    cout << "Introduce el nombre del Destino: ";
    getline(cin,nombreVerticeDestino);
    cout << "Introduce el nuevo Destino: ";
    getline(cin,nuevoNombreVerticeDestino);
    cout << "Introduce el nuevo peso: ";
    cin >> nuevoPeso;
    cin.get();
    grafoPrincipal.modificarArista(nombreVerticeInicial,nombreVerticeDestino,nuevoNombreVerticeDestino,nuevoPeso);
}

void eliminarVertice(){
    string nombreVerticeEliminar;
    cout << "Introduce el nombre del Vertice a eliminar: ";
    getline(cin,nombreVerticeEliminar);
    grafoPrincipal.eliminarVertice(nombreVerticeEliminar);
}

void eliminarArista(){
    string nombreVerticeInicial, nombreVerticeDestino;
    cout << "Introduce el Vertice inicial: ";
    getline(cin,nombreVerticeInicial);
    cout << "Introduce el Vertice Destino: ";
    getline(cin,nombreVerticeDestino);
    grafoPrincipal.eliminarArista(nombreVerticeInicial,nombreVerticeDestino);
}

void recorridoProfundidad(){
    string nombreVerticeInicial;
    cout << "Introduce el Vertice de origen: ";
    getline(cin,nombreVerticeInicial);
    grafoPrincipal.recorrerProfundidad(nombreVerticeInicial);
}

void mostrarRutas(){
    string nombreVerticeInicial, nombreVerticeDestino;
    cout << "Introduce el nombre del Vertice Origen: ";
    getline(cin,nombreVerticeInicial);
    cout << "Introduce el nombre del Vertice Destino: ";
    getline(cin,nombreVerticeDestino);
    cout << "Ruta por Profundidad: "<<endl;
    grafoPrincipal.rutaProfundidad(nombreVerticeInicial,nombreVerticeDestino);
    cout << "Ruta Primero El Mejor  ---->" <<endl;
    //text_color(2);
    grafoPrincipal.primeroElMejor(nombreVerticeInicial,nombreVerticeDestino);
    //text_color(7);
}
