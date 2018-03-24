#include "Animal.h"

using namespace std;

void Animal::Capturar(int reg, int posicion)
{
    int pos;
    pos = posicion;
    numeroRegistro = reg;
    fflush(stdin);
    cout << "\n Nombre:  ";
    gets(nombre);

    cout<< "\n Especie:  ";
    gets(especie);

    cout<< "\n Nacimiento:  ";
    gets(nacimiento);

    ofstream archivo;
    archivo.open("Indices.txt",ios::app);

    if(archivo.is_open())
    {
        x.numeroRegistro = numeroRegistro;
        x.posicion = pos;

        archivo.write((char*)&x,sizeof(x));
    }

    return;
}


void Animal::Mostrar()
{
    cout << "\n Numero de Registro:  " << numeroRegistro << endl;
    cout << "\n Nombre:      " << nombre << endl;
    cout << "\n Especie:     " << especie << endl;
    cout << "\n Nacimiento:  " << nacimiento << endl;

    return;
}


