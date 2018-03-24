#ifndef PROYECTO_H_INCLUDED
#define PROYECTO_H_INCLUDED
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class archivo{
public:
    char nombre[60];
    char responsable[60];
    char fecha[20];

    void capturar(){
        cout<<"Nombre del Archivo: ";
        fflush(stdin);
        cin.getline(nombre,60);

        cout<<endl<<"Responsable: ";
        cin.getline(responsable,60);

        cout<<endl<<"Fecha de ejecucion: ";
        cin.getline(fecha,60);

        ofstream archivo("Proyectos.txt",ios::app);
    archivo<<nombre<<"|"<<responsable<<"|"<<fecha<<"|";
    archivo.close();
    }

void mostrar(){

    ifstream leer("Proyectos.txt");
    if(!leer.good())
        cout<<"Error FALTA DE DATOS"<<endl;
    else{
             while(!leer.eof()){

    char nombre[60];
    char responsable[60];
    char fecha[20];


    leer.getline(nombre,60,'|');
    leer.getline(responsable,60,'|');
    leer.getline(fecha,60,'|');

    if(leer.eof())
        break;

        cout<<endl<<"Nombre del archivo: "<<nombre<<endl;
        cout<<"Responsable: "<<responsable<<endl;
        cout<<"Fecha de ejecucion: "<<fecha<<endl<<endl;
                }}leer.close();
    }

void Buscar(){
    char buscado[60];
    cout<<endl<<"Ingresa el nombre del archivo que buscas: ";
    fflush(stdin);
    cin.getline(buscado,60);
     ifstream leer("Proyectos.txt");
    if(!leer.good())
        cout<<"Error";
    else{
             while(!leer.eof()){

    char nombre[60];
    char responsable[60];
    char fecha[20];


    leer.getline(nombre,60,'|');
    leer.getline(responsable,60,'|');
    leer.getline(fecha,60,'|');

    if(leer.eof())
        break;
         if(strcmp(buscado,nombre)==0){
        cout<<endl<<"Nombre del archivo: "<<nombre<<endl;
        cout<<"Responsable: "<<responsable<<endl;
        cout<<"Fecha de ejecucion: "<<fecha<<endl<<endl;
         }

                }}leer.close();
    }

void Eliminar(){
    char buscado[60];
    cout<<endl<<"Ingresa el nombre del archivo que Eliminaras: ";
    fflush(stdin);
    cin.getline(buscado,60);
     ofstream archivo("Temporal.txt",ios::app);
     ifstream leer("Proyectos.txt");
    if(!leer.good())
        cout<<"Error";
    else{
             while(!leer.eof()){

    char nombre[60];
    char responsable[60];
    char fecha[20];


    leer.getline(nombre,60,'|');
    leer.getline(responsable,60,'|');
    leer.getline(fecha,60,'|');

    if(leer.eof())
        break;
         if(strcmp(buscado,nombre)!=0){
        cout<<"Datos Guardados "<<endl;
        cout<<endl<<"Nombre del archivo: "<<nombre<<endl;
        cout<<"Responsable: "<<responsable<<endl;
        cout<<"Fecha de ejecucion: "<<fecha<<endl<<endl;

    archivo<<nombre<<"|"<<responsable<<"|"<<fecha<<"|";


         }

        }
    }leer.close();archivo.close();
    system("del Proyectos.txt");
    system("ren Temporal.txt Proyectos.txt");
    }

void Modificar(){
    char buscado[60];
    cout<<endl<<"Ingresa el nombre del archivo que Eliminaras: ";
    fflush(stdin);
    cin.getline(buscado,60);
     ofstream archivo("Temporal.txt",ios::app);
     ifstream leer("Proyectos.txt");
    if(!leer.good())
        cout<<"Error";
    else{
             while(!leer.eof()){

    char nombre[60];
    char responsable[60];
    char fecha[20];


    leer.getline(nombre,60,'|');
    leer.getline(responsable,60,'|');
    leer.getline(fecha,60,'|');

    if(leer.eof())
        break;
          if(strcmp(buscado,nombre)==0){
            capturar();
            cout<<endl;
          }
         if(strcmp(buscado,nombre)!=0){
        cout<<"DATOS GUARDADOS "<<endl;
        cout<<endl<<"Nombre del archivo: "<<nombre<<endl;
        cout<<"Responsable: "<<responsable<<endl;
        cout<<"Fecha de ejecucion: "<<fecha<<endl<<endl;

    archivo<<nombre<<"|"<<responsable<<"|"<<fecha<<"|";


         }

        }
    }leer.close();archivo.close();
    system("del Proyectos.txt");
    system("ren Temporal.txt Proyectos.txt");
    }

};

#endif // PROYECTO_H_INCLUDED
