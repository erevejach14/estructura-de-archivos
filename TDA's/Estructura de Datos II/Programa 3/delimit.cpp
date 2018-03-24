#include "delimit.h"


using namespace std;

Delimit::Delimit(){

}

Delimit::~Delimit(){

}	

void Delimit::addMedia(){
	char* name;
	char* URL;
	char* date;

	cin.getline(name,60);
	
	cin.getline(URL,60);
	me.setURL(URL);
	cin.getline(date,60);

	ofstream archivo("lala.txt",ios::app);
    archivo<<name<<"|"<<URL<<"|"<<date<<"|";
    archivo.close();


}

void Delimit::modifyMedia(){
	char buscado[60];
    cout<<endl<<"Ingresa el nombre del archivo que Eliminaras: ";
    fflush(stdin);
    cin.getline(buscado,60);
     ofstream archivo("Temporal.txt",ios::app);
     ifstream leer("lala.txt");
    if(!leer.good())
        cout<<"Error";
    else{
             while(!leer.eof()){

    char nombre[60];
    char URL[60];
    char date[20];


    leer.getline(nombre,60,'|');
    leer.getline(URL,60,'|');
    leer.getline(date,60,'|');

    if(leer.eof())
        break;
          if(strcmp(buscado,nombre)==0){
            addMedia();
            cout<<endl;
          }
         if(strcmp(buscado,nombre)!=0){
        cout<<"DATOS GUARDADOS "<<endl;
        cout<<endl<<"Nombre del archivo: "<<nombre<<endl;
        cout<<"URL: "<<URL<<endl;
        cout<<"Fecha de ejecucion: "<<date<<endl<<endl;

    archivo<<nombre<<"|"<<URL<<"|"<<date<<"|";


         }

        }
    }leer.close();archivo.close();
    system("del lala.txt");
    system("ren Temporal.txt lala.txt");
}

void Delimit::deleteMedia(){
	char buscado[60];
    cout<<endl<<"Ingresa el nombre del archivo que Eliminaras: ";
    fflush(stdin);
    cin.getline(buscado,60);
     ofstream archivo("Temporal.txt",ios::app);
     ifstream leer("lala.txt");
    if(!leer.good())
        cout<<"Error";
    else{
             while(!leer.eof()){

    char nombre[60];
    char URL[60];
    char date[20];


    leer.getline(nombre,60,'|');
    leer.getline(URL,60,'|');
    leer.getline(date,60,'|');

    if(leer.eof())
        break;
         if(strcmp(buscado,nombre)!=0){
        cout<<"Datos Guardados "<<endl;
        cout<<endl<<"Nombre del archivo: "<<nombre<<endl;
        cout<<"URL: "<<URL<<endl;
        cout<<"Fecha de ejecucion: "<<date<<endl<<endl;

    archivo<<nombre<<"|"<<URL<<"|"<<date<<"|";


         }

        }
    }leer.close();archivo.close();
    system("del Proyectos.txt");
    system("ren Temporal.txt Proyectos.txt");
}
void Delimit::showMedia(){
	 ifstream leer("Proyectos.txt");
    if(!leer.good())
        cout<<"Error FALTA DE DATOS"<<endl;
    else{
             while(!leer.eof()){

    char nombre[60];
    char URL[60];
    char date[20];


    leer.getline(nombre,60,'|');
    leer.getline(URL,60,'|');
    leer.getline(date,60,'|');

    if(leer.eof())
        break;

        cout<<endl<<"Nombre del archivo: "<<nombre<<endl;
        cout<<"URL: "<<URL<<endl;
        cout<<"Fecha de ejecucion: "<<date<<endl<<endl;
                }}leer.close();
}

void Delimit::searchMedia(){
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
    char URL[60];
    char date[20];


    leer.getline(nombre,60,'|');
    leer.getline(URL,60,'|');
    leer.getline(date,60,'|');

    if(leer.eof())
        break;
         if(strcmp(buscado,nombre)==0){
        cout<<endl<<"Nombre del archivo: "<<nombre<<endl;
        cout<<"URL: "<<URL<<endl;
        cout<<"Fecha de ejecucion: "<<date<<endl<<endl;
         }

                }}leer.close();
}


void Delimit::menu(){
	int opc;
	 do{
    system("cls");
    cout<<"Administracion de Archivos"<<endl<<endl;
    cout<<" \nMenu "<<endl<<endl;
    cout<<"1) Agregar\n2) Mostrar\n3) Buscar\n4) modificar\n5) Eliminar\n6) Salir\nOpcion: ";
   cin>>opc;

    switch(opc){
    case 1:
        system("cls");
        addMedia();
        break;
    case 2:
        system("cls");
        showMedia();
        system("pause");
        break;
    case 3:
        system("cls");
        searchMedia();
        system("pause");
        break;
    case 4:
        system("cls");
        modifyMedia();
        system("pause");
        break;
    case 5:
        system("cls");
        deleteMedia();
        system("pause");
        break;
        }

}while(opc<6);
}