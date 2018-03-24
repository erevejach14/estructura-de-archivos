#include <iostream>
#include <cstdlib>
#include "grafo.h"
using namespace std;
int main(){
    setlocale(LC_ALL,"spanish");
    char op;
    string origen, destino,res;
    float peso;
    Grafo grafo;
    grafo.insertaVertice("Francia");
    grafo.insertaVertice("Irlanda");
    grafo.insertaVertice("Alemania");
    grafo.insertaVertice("Espania");
    grafo.insertaArista("Francia","Irlanda",100.0);
    grafo.insertaArista("Irlanda","Francia",100.0);

    grafo.insertaArista("Francia","Espania",120.0);
    grafo.insertaArista("Espania","Francia",120.0);

    grafo.insertaArista("Irlanda","Alemania",100.0);
    grafo.insertaArista("Alemania","Irlanda",100.0);

    grafo.insertaArista("Alemania","Espania",175.0);
    grafo.insertaArista("Espania","Alemania",175.0);
    do{
        system("cls");
        cout<<"MENU"<<endl;
        cout<<"1.-Agregar Destino"<<endl;
        cout<<"2.-Mostrar"<<endl;
        cout<<"3.-Modificar"<<endl;
        cout<<"4.-Buscar"<<endl;
        cout<<"5.-Eliminar"<<endl;
        cout<<"6.-Salir"<<endl;
        cin>>op;
        cin.ignore();
        switch(op){
            case '1':
                cout<<"Nuevo destino: ";
                getline(cin,origen);
                if(grafo.insertaVertice(origen)){
                    for(int i=0;i<10;i++){
                        if(grafo.getVertice(i).existe){
                            cout<<"Incide con "<<grafo.vertice[i].info<<"? ";
                            getline(cin,res);
                            if(res=="s"||res=="Si"||res=="S"||res=="SI"||res=="si"){
                                destino=grafo.getVertice(i).info;
                                cout<<"Cuanto es el peso del arista? ";
                                cin>>peso;
                                cin.ignore();
                                grafo.insertaArista(origen,destino,peso);
                                grafo.insertaArista(destino,origen,peso);
                            }
                        }
                    }
                }
                break;
            case '2':
                cout<<"MOSTRAR"<<endl;
                grafo.imprimir();
                system("pause");
                break;
            case '3':
                cout<<"MODIFICAR"<<endl;
                cout<<"Ciudad a modificar: ";
                getline(cin,origen);
                if(grafo.borraVertice(origen)){
                    cout<<"Nuevo nombre de Ciudad: ";
                    getline(cin,origen);
                    grafo.insertaVertice(origen);
                    for(int i=0;i<10;i++){
                        if(grafo.getVertice(i).existe){
                            cout<<"Incide con "<<grafo.vertice[i].info<<"? ";
                            getline(cin,res);
                            if(res=="s"||res=="Si"||res=="S"||res=="SI"||res=="si"){
                                destino=grafo.getVertice(i).info;
                                cout<<"Cuanto es el peso del arista? ";
                                cin>>peso;
                                cin.ignore();
                                grafo.insertaArista(origen,destino,peso);
                                grafo.insertaArista(destino,origen,peso);
                            }
                        }
                    }
                }
                break;
            case '4':
                cout<<"BUSCAR"<<endl;
                cout<<"Ciudad a buscar: ";
                getline(cin,origen);
                grafo.buscar(origen);
                cout<<"\n";
                system("pause");
                break;
            case '5':
                cout<<"ELIMINAR"<<endl;
                cout<<"Ciudad a eliminar: ";
                getline(cin,origen);
                grafo.borraVertice(origen);
                break;
            case '6':
                cout<<"SALIR\nNos Vemos!!!"<<endl;
                break;
            default:
                cout<<"Opcion no válida"<<endl;
                system("pause");
                break;
        }
    }while(op!='6');
    return 0;
}
