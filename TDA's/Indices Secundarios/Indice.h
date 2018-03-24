#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include "Animal.h"
#include "Otro.h"

using namespace std;

class Indice{
public:
    apAnimal inicio, fin;

    int tamanio;

    void Inicializar();
    void Cargar();
    int GetPosicion(int);
    bool Vacia();
    void Insertar();
    void Mostrar();
    void Indices();

    void Almacenar();

    void Eliminar(int);
    void Modificar(int);
    void Buscar(int);
    void Indizacion();
    void ImprimirAsc();
    void ImprimirDes();
    void Anular();
    void Mostrar_Animal(int);


}lista;


/*
void Indice::Mostrar_Animal( int nRegistro)
{
    apAnimal actual;
    actual = inicio;

    int posicion;
    posicion = GetPosicion( nRegistro );

    for(int i = 0; i < posicion; i++ )
    {
        actual = actual->siguiente;
    }

    actual->Mostrar();
    cout<<"\n____________________________________"<<endl;

}

void Indice::Almacenar()
{
    if(Vacia() == false )
    {
        apAnimal actual;
        actual = inicio;
        bool existe = false;

        ifstream ayuda;
        ayuda.open("Animales.txt",ios::out|ios::in);

        ofstream zoo;
        zoo.open("Temp_Animales.txt",ios::app);
        int i = 0;
        do
        {
            strcpy(anim.especie, actual->especie);
            strcpy(anim.nacimiento, actual->nacimiento);
            strcpy(anim.nombre, actual->nombre);
            anim.numeroRegistro = actual->numeroRegistro;

            zoo.write((char*)&anim,sizeof(anim));

            actual = actual->siguiente;
            i++;
        }while( i < tamanio );

        zoo.close();

        if(ayuda.good())
        {
            ayuda.close();
            existe = true;
        }

        if( existe == true)
        {
            remove("Animales.txt");
        }
        remove("Indices.txt");
        rename("Temp_Animales.txt","Animales.txt");
    }
    else{
        remove("Animales.txt");
        remove("Indices.txt");

    }
}

void Indice::Cargar()
{
    int i = 0;

    ifstream leer;
    leer.open("Animales.txt",ios::out|ios::in);

    ofstream escribir;
    escribir.open("Indices.txt",ios::app);

    if (leer.is_open() && escribir.is_open())
    {

        while(!leer.eof())
        {
            leer.read((char*)&anim,sizeof(anim));
            if(leer.eof()) break;

            if( i == 0 )
            {
                apAnimal nuevo  = new Animal();

                nuevo->numeroRegistro = anim.numeroRegistro;

                strcpy(nuevo->nombre,anim.nombre);

                strcpy(nuevo->especie,anim.especie);

                strcpy(nuevo->nacimiento,anim.nacimiento);

                nuevo->siguiente = NULL;
                nuevo->anterior = NULL;
                inicio = nuevo;
                fin = nuevo;
                tamanio++;

                invertida.Add_Especie(nuevo);
            }
            else{
                    apAnimal actual, nuevo;
                    actual = fin;
                    nuevo = new Animal();

                    nuevo->numeroRegistro = anim.numeroRegistro;

                    strcpy(nuevo->nombre,anim.nombre);

                    strcpy(nuevo->especie,anim.especie);

                    strcpy(nuevo->nacimiento,anim.nacimiento);

                    actual->siguiente = nuevo;
                    nuevo->anterior = actual;
                    nuevo->siguiente = inicio;
                    inicio->anterior = nuevo;
                    fin = nuevo;
                    tamanio++;

                    invertida.Add_Especie(nuevo);

                }
            x.numeroRegistro = anim.numeroRegistro;
            x.posicion = i;
            escribir.write((char*)&x,sizeof(x));
            i++;
        }

    }

    escribir.close();
    leer.close();
}

int Indice::GetPosicion(int registro)
{
    bool encontrado = false;
    int posicion;

    ifstream lectura;
    lectura.open("Indices.txt",ios::in|ios::out);

    if(lectura.is_open())
    {
        while(!lectura.eof())
        {
            lectura.read((char*)&x,sizeof(x));
            if(lectura.eof()) break;

            if(x.numeroRegistro == registro )
            {
                posicion = x.posicion;
                encontrado = true;
                break;
            }
        }

    }
    lectura.close();

    if( encontrado == true)
    {
        return posicion;
    }
    return -1;
}

void Indice::Inicializar()
{
	inicio = NULL;
	fin = NULL;
	tamanio = 0;
}

bool Indice::Vacia()
{
	if( tamanio == 0 )
	{
		return true;
	}
	else{
		return false;
	}
}

bool ValidCode(int numero)
{
    if( numero < 999)
    {
        return false;
    }
    if( numero > 10000 )
    {
        return false;
    }

    ifstream leer;
    leer.open("Indices.txt",ios::out|ios::in);

    if (leer.is_open() )
    {
        while(!leer.eof())
        {
            leer.read((char*)&x,sizeof(x));
            if (leer.eof()) break;

            if( numero == x.numeroRegistro )
            {
                return false;
            }
        }
    }

    leer.close();

    return true;
}

void Indice::Insertar()
{
    string code;
    int auxiliar;

    cout << "\n\tAGREGAR UN NUEVO REGISTRO" << endl;
    cout << "Numero de Registro (####):  ";
    getline(cin,code);

    auxiliar = atoi(code.c_str());

    if( ValidCode(auxiliar) == false )
    {
        cout << "\n\t!! NUMERO DE REGISTRO INCORRECTO !!\n\n" << endl;
    }else{

        if ( Vacia() )
        {
            apAnimal nuevo = new Animal();
            nuevo->Capturar(auxiliar,tamanio);
            nuevo->anterior = NULL;
            nuevo->siguiente = NULL;
            inicio = nuevo;
            fin = nuevo;

            invertida.Add_Especie(nuevo);
        }else{

            apAnimal actual, nuevo;
            actual = fin;
            nuevo = new Animal();
            nuevo->Capturar(auxiliar,tamanio);
            nuevo->siguiente = inicio;
            nuevo->anterior = actual;
            inicio->anterior = nuevo;
            actual->siguiente = nuevo;
            fin = nuevo;

            invertida.Add_Especie(nuevo);
        }
        tamanio++;
        cout<<"\n\tSE HA INSERTADO CORRECTAMENTE\n"<<endl;

    }
}


void Indice::Mostrar()
{
    if( Vacia() )
	{
		cout<<"\n\tERROR LA LISTA ESTA VACIA\n"<<endl;
	}
	else{
		apAnimal actual;
		actual = inicio;
		int i = 0;

		cout<<"\n\tTODOS LOS ANIMALES"<<endl;
		cout<<"\n____________________________________"<<endl;
		while( i < tamanio)
		{
			actual->Mostrar();
			cout<<"\n____________________________________"<<endl;
			actual = actual->siguiente;
			i++;
		}
	}



}

void Indice::Indices()
{
    if( Vacia() )
    {
        cout <<"\n\tERROR LA LISTA ESTA VACIA\n\n" << endl;
        return;
    }
    ifstream leer;
    leer.open("Indices.txt",ios::out|ios::in);

    cout << "\n\tINDICES" << endl;

    cout << "______________________________________\n" << endl;

    if(leer.is_open())
    {

        while(!leer.eof())
        {
            leer.read((char*)&x, sizeof(x));
            if(leer.eof()) break;
            cout << "\n Numero de Registro:  " << x.numeroRegistro << endl;
            cout << "\n Posicion:            " << x.posicion << endl;
            cout << "______________________________________\n" << endl;

        }
    }
}

void Indice::Buscar(int posicion)
{
    if (posicion != -1)
    {
        apAnimal actual;
        actual = inicio;

        for(int i = 0; i < posicion ; i++)
        {
            actual = actual->siguiente;
        }
        actual->Mostrar();
    }
    else{
        cout <<"\n\t!! NO EXISTE ESE NUMERO DE REGISTRO !! \n\n" << endl;
    }
}

void Indice::Indizacion()
{
     remove("Indices.txt");

    apAnimal actual;
    actual = inicio;
    int i = 0;
    ofstream escribir;
    escribir.open("Indices.txt",ios::app);


    if( escribir.is_open() )
    {
        while( i < tamanio)
        {
            x.numeroRegistro = actual->numeroRegistro;
            x.posicion = i;
            escribir.write((char*)&x,sizeof(x));

            actual = actual->siguiente;
            i++;
        }
    }
    else{
        cout << "\n\t!! ERROR AL ABRIR EL ARCHIVO PARA INDIZACION !!\n\n " << endl;
    }

    escribir.close();
}

void Indice::Eliminar(int posicion)
{
	if( Vacia() || posicion == -1)
	{
		cout<<"\n\tERROR ESA POSICION NO EXISTE\n\n"<<endl;
	}
	else{
        if(posicion == 0 )
        {
            apAnimal suprimir;
            suprimir = inicio;
            if( inicio->siguiente == inicio)
            {
                inicio = NULL;
            }else{
                inicio = inicio->siguiente;
            }
            if( tamanio == 1 )
            {
                fin = NULL;
            }
            else{
                suprimir->siguiente->anterior = fin;
                fin->siguiente = inicio;
            }
            cout<<"\n\tSE ELIMINARA EL ANIMAL:  "<<endl;
            suprimir->Mostrar();

            free(suprimir);
            tamanio--;
            cout<<"\n\t* SE HA ELIMINADO CORRECTAMENTE *\n"<<endl;

        }else{
            if (posicion == tamanio - 1)
            {

                apAnimal suprimir;
                suprimir = fin;
                fin = suprimir->anterior;
                fin->siguiente = inicio;
                inicio->anterior = fin;

                cout<<"\n\tSE ELIMINARA EL ANIMAL:  "<<endl;
                suprimir->Mostrar();

                free(suprimir);
                tamanio--;
                cout<<"\n\t* SE HA ELIMINADO CORRECTAMENTE *\n"<<endl;

            }
            else{
                apAnimal actual, suprimir;
                actual = inicio;

                for(int i = 0 ; i < posicion ; i++)
                {
                    actual = actual->siguiente;
                }
                suprimir = actual;
                actual->siguiente->anterior = actual->anterior;
                actual->anterior->siguiente = actual->siguiente;


                cout<<"\n\tSE ELIMINARA EL ANIMAL:  "<<endl;
                suprimir->Mostrar();

                free(suprimir);
                tamanio--;
                cout<<"\n\t* SE HA ELIMINADO CORRECTAMENTE *\n"<<endl;
            }
        }
        Indizacion();
	}
}

void Indice::Modificar(int posicion)
{
    if( Vacia() || posicion == -1)
	{
		cout<<"\n\tERROR ESA POSICION NO EXISTE\n\n"<<endl;
	}
	else{
           apAnimal actual;
           actual = inicio;

           char auxiliar[30];
           string opc;
           int accion, nReg;
           bool modificado = true;

           for(int i = 0; i < posicion; i++)
           {
               actual = actual->siguiente;
           }

           cout << "\n\tINFORMACION DE REGISTRO" << endl;
           actual->Mostrar();

           cout << "\n INFORMACION A MODIFICAR: " << endl;
           cout << "\n 1) NUMERO DE REGISTRO" << endl;
           cout << "\n 2) NOMBRE" << endl;
           cout << "\n 3) ESPECIE" << endl;
           cout << "\n 4) NACIMIENTO" << endl;
           cout << "\n 5) CANCELAR" << endl;

           cout << "\n Respuesta:  ";
           getline(cin,opc);

           accion = atoi(opc.c_str());
           system("cls");
           switch(accion)
           {
               case 1:
                {
                    cout << "\n\tMODIFICAR NUMERO DE REGISTRO" << endl;
                    cout << "\n ANTERIOR:  " << actual->numeroRegistro;

                    cout << " NUEVO (####):  ";
                    getline(cin,opc);

                    nReg = atoi(opc.c_str());

                    if( ValidCode(nReg) == false )
                    {
                        cout << "\n\t!! NUMERO DE REGISTRO INCORRECTO !!\n\n" << endl;
                        modificado = false;
                    }
                    else{
                        actual->numeroRegistro = nReg;

                        cout << "\n\t* SE HA MODIFICADO CON EXITO *\n" << endl;
                    }

                    break;
                }

               case 2:
                {
                    cout << "\n\tMODIFICAR NOMBRE DE REGISTRO" << endl;
                    cout << "\n ANTERIOR:  " << actual->nombre;

                    do{
                        fflush(stdin);
                        cout << "\n NUEVO:  ";
                        gets(auxiliar);

                    }while( auxiliar[0] == '\0');

                    strcpy(actual->nombre,auxiliar);
                    cout << "\n\t* SE HA MODIFICADO CON EXITO *\n" << endl;

                    break;
                }

               case 3:
                {
                    cout << "\n\tMODIFICAR ESPECIE DE REGISTRO" << endl;
                    cout << "\n ANTERIOR:  " << actual->especie;

                    do{
                        fflush(stdin);
                        cout << "\n NUEVO:  ";
                        gets(auxiliar);

                    }while( auxiliar[0] == '\0');

                    strcpy(actual->especie,auxiliar);
                    cout << "\n\t* SE HA MODIFICADO CON EXITO *\n" << endl;

                    break;
                }

               case 4:
                {
                    cout << "\n\tMODIFICAR REGISTRO DE NACIMIENTO" << endl;
                    cout << "\n ANTERIOR:  " << actual->nacimiento;

                    do{
                        fflush(stdin);
                        cout << "\n NUEVO:  ";
                        gets(auxiliar);

                    }while( auxiliar[0] == '\0');

                    strcpy(actual->nacimiento,auxiliar);
                    cout << "\n\t* SE HA MODIFICADO CON EXITO *\n" << endl;

                    break;
                }

               case 5:
                {
                    cout << "\n\t * NO SE REALIZO NINGUN CAMBIO\n" << endl;
                    break;
                }



           }
        if( modificado )
        {
            Indizacion();
        }

	}

}
*/

#endif // INDICE_H_INCLUDED
