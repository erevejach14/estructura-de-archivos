#include "interfaz.h"

using namespace std;

void Interfaz::menuPrincipal() {
    Lista<Musica>miLista;
    char opc;
    do {
        cout << "*******Menu Radiodifusora*******" << endl;
        cout << "1.-Ingresar." << endl;
        cout << "2.-Eliminar." << endl;
        cout << "3.-Ordenar." << endl;
        cout << "4.-Guardar datos en archivo." << endl;
        cout << "5.-Leer datos en archivo." << endl;
        cout << "6.-Salir." << endl;
        cout << "-La opcion es: ";
        cin  >>opc;
        switch(opc) {
            case '1':
                menuIngresar();
                break;
            case '2':
                menuEliminar();
                break;
            case '3':
                menuOrdenar();
                break;
            case '4':
                cout << "Escribiendo al disco..." <<endl;
                //miLista.imprimeDato();
                miLista.escribirEnDisco("Musica.txt");
                break;
            case '5':
                cout << "Leyendo de disco..." <<endl;
                //miLista.borrarTodo()
                miLista.leerEnDisco("Musica.txt");
                break;
            case '6':
                cout<<"-Hasta luego"<<endl;
                break;
            default:
                cout <<"-Opcion no valida!"<<endl;
            }
        listaMusica.imprimir();
        enterParaContinuar();
        }
    while (opc!='6');
    }

void Interfaz::menuIngresar() {
    string myString;
    Musica miMusica;

    cout <<"\t*******Ingresar datos*******" << endl;
    cout << "-Nombre del autor: ";
    cin.ignore();
    getline(cin,myString);
    miMusica.setAutor(myString);

    cout << "-Nombre del interprete: ";
    getline(cin,myString);
    miMusica.setInterprete(myString);

    cout << "-Nombre de la cancion: ";
    getline(cin,myString);
    miMusica.setCancion(myString);

    cout << "-Ranking: ";
    getline(cin,myString);
    miMusica.setRanking(atoi(myString.c_str()));
    try {
        ++indice;
        listaMusica.insertaDato(miMusica);
        }
    catch(listException explica) {
        cout <<"-Parece que hubo un problema." << explica.what() << endl;
        }
    }

void Interfaz::menuOrdenar() {
    char opc;
    do {
        cout << "*******Menu Ordenar*******" << endl;
        cout << "1.-Ordenar por Autor."      << endl;
        cout << "2.-Ordenar por Interprete." << endl;
        cout << "3.-Ordenar por Cancion."    << endl;
        cout << "4.-Ordenar por Ranking."    << endl;
        cout << "5.-Regresar." << endl;
        cout << "-La opcion es: ";
        cin.ignore();
        cin  >>opc;
        switch(opc) {
            case '1':
                listaMusica.ordenaAutor();
                break;
            case '2':
                listaMusica.ordenaInterprete();
                break;
            case '3':
                listaMusica.ordenaCancion();
                break;
            case '4':
                listaMusica.ordenaRanking();
                break;
            case '5':
                cout<<"-Regresando..."<<endl;
                break;
            default:
                cout <<"-Opcion no valida!"<<endl;
            }
        listaMusica.imprimir();
        }
    while (opc!='5');

    }


void Interfaz::menuEliminar() {
    string busca;
    cout << "******Eliminar Dato*******" << endl;
    cout << "Ingrese el nombre de la cancion a eliminar: ";
    cin.ignore();
    getline(cin,busca);
    for(int i=0; i<indice; i++) {
        if(listaMusica.recupera(i).getCancion()==busca) {
            listaMusica.borrarDato(i);
            indice--;
            cout <<"Eliminado con exito!"<< endl;
            return;
            }
        }
    cout <<"-No se encontro el elemento a eliminar." << endl;
    }

void Interfaz::enterParaContinuar() {
    cout <<"-Presiona enter para continar..." << endl;
    cin.ignore();
    cin.ignore();
    }

Interfaz::Interfaz() {
    indice = -1;
    menuPrincipal();
    }
