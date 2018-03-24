#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Auxiliar.h"
#include "Indice.h"
#include "Lista_Especie.h"
#include "Lista_Invertida.h"

using namespace std;

void Ordenado()
{
    orden.Pasar();
    int control, accion;
    string aux;

    do{
        control = 1;
        cout << "\n\tSECCION DE MOSTRAR\n" << endl;

        cout << "\n 1) ORDENADO ITERATIVO ASCENDENTE" << endl;
        cout << "\n 2) ORDENADO RECURSIVO DESCENDENTE" << endl;
        cout << "\n 3) * MOSTRAR POR ESPECIE " << endl;
        cout << "\n 4) REGRESAR" << endl;
        cout << "\n Respuesta:  ";
        getline(cin,aux);

        accion = atoi(aux.c_str());

        system("cls");

        switch(accion)
        {
            case 1:{
                orden.Ordenar_Shell();

                cout<<"\nDATOS ORDENADOS CON SHELL"<<endl;
                orden.Mostrar();


                system("pause");
                system("cls");
                break;
            }

            case 2:{
                apAnimal actual = lista.inicio;
                apAnimal extremo = lista.fin;
                int extder = lista.tamanio;

                orden.Quicksort(actual, actual->siguiente, 0 , extder-1, extremo);
                cout<<"\nDATOS ORDENADOS CON QUICKSORT"<<endl;
                orden.Mostrar();

                system("pause");
                system("cls");
                break;
            }

            case 3:{
                char temporal[30];
                cout << "\n\tMOSTRAR MASCOTAS POR ESPECIE " << endl;
                fflush(stdin);
                cout << "\n ESPECIE:  ";
                gets(temporal);

                if( temporal[0] == '\0')
                {
                    cout << "\n\t!! DEBE DE INGRESAR UNA ESPECIE\n\n " << endl;
                }
                else{
                    apEspecie actual;

                    actual = invertida.GetNodo(temporal);
                    if( actual == NULL )
                    {
                        cout << "\n\t!! ESA ESPECIE NO EXISTE !!\n\n" << endl;

                    }
                    else
                    {
                        invertida.Mostrar_Especie(actual);
                    }
                }


                break;
            }

            case 4:{
                control = 2;
                break;
            }


        }


    }while(control == 1);
}


void Menu()
{
    int control, accion;
    string resp;

    do{
        control = 0;

        cout << "\n\t ZOOLOGICO " << endl;

        cout << "\n 1) AGREGAR" << endl;
        cout << "\n 2) MOSTRAR ANIMALES" << endl;
        cout << "\n 3) MOSTRAR INDICES" << endl;
        cout << "\n 4) LOCALIZAR" << endl;
        cout << "\n 5) BUSCAR" << endl;
        cout << "\n 6) MODIFICAR" << endl;
        cout << "\n 7) ELIMINAR" << endl;
        cout << "\n 8) MOSTRAR" << endl;
        cout << "\n 9) SALIR " << endl;


        cout << "\n Respuesa:  ";
        getline(cin,resp);

        accion = atoi(resp.c_str());
        system("cls");
        switch(accion)
        {
            case 1:{
                lista.Insertar();
                system("pause");
                system("cls");
            break;
            }

            case 2:{
                lista.Mostrar();
                system("pause");
                system("cls");
            break;
            }

            case 3:
                {
                    lista.Indices();
                    system("pause");
                    system("cls");
                    break;
                }

            case 4:{
                string no;
                int aux;

                cout << "\n\tLOCALIZAR UN REGISTRO" << endl;

                cout << " No DE REGISTRO:  ";
                getline(cin,no);

                aux = atoi(no.c_str());

                aux = lista.GetPosicion(aux);

                if( aux < 0)
                {
                    cout << "\n\tNO EXISTE ESE REGISTRO\n\n" << endl;
                }
                else{
                    cout << "\nEL REGISTRO SE ENCUENTRA EN LA POSICION:  " << aux << endl;
                    cout << endl;
                }

                system("pause");
                system("cls");
                break;
            }

            case 5:{
                string no;
                int aux;

                cout << "\n\tBUSCAR UN REGISTRO" << endl;

                cout << " No DE REGISTRO:  ";
                getline(cin,no);

                aux = atoi(no.c_str());

                lista.Buscar(lista.GetPosicion(aux));

                system("pause");
                system("cls");
                break;
            }

            case 6:{
                string no;
                int aux;

                cout << "\n\tMODIFICAR UN REGISTRO" << endl;

                cout << " No DE REGISTRO:  ";
                getline(cin,no);

                aux = atoi(no.c_str());

                lista.Modificar(lista.GetPosicion(aux));
                system("pause");
                system("cls");
                break;
            }

            case 7:{
                string no;
                int aux;

                cout << "\n\tELIMINAR UN REGISTRO" << endl;

                cout << " No DE REGISTRO:  ";
                getline(cin,no);

                aux = atoi(no.c_str());

                lista.Eliminar(lista.GetPosicion(aux));
                system("pause");
                system("cls");
                break;
            }

            case 8:{
                Ordenado();
                system("cls");
                break;
            }

            case 9:
                {
                    control = 1;
                    break;
                }
        }



    }while(control == 0);
}

