#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "TDA_Secundario.h"
#include "Indice.h"

void TDA_Secundario::Inicializa()
{
    tamano = 0;
    inicio = NULL;
    fin = NULL;
}

apAnimal TDA_Secundario::Insertar(apAnimal nodo, apAnimal actual, bool existe)
{
    apAnimal nuevo = new Animal();
    if ( !existe )
    {
        if (tamano == 0)
        {
            nuevo->numeroRegistro = nodo->numeroRegistro;
            nuevo->adyacente = NULL;
            nuevo->siguiente = NULL;
            nuevo->anterior = NULL;

            inicio = nuevo;
            fin = nuevo;
        }
        else{
            nuevo->numeroRegistro = nodo->numeroRegistro;
            nuevo->adyacente = NULL;
            nuevo->siguiente = NULL;
            nuevo->anterior = fin;
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }
    else{
        while(actual->adyacente != NULL )
        {
            actual = actual->adyacente;
        }

        nuevo->numeroRegistro = nodo->numeroRegistro;
        nuevo->siguiente = NULL;
        nuevo->adyacente = NULL;

        actual->adyacente = nuevo;

        fin->siguiente = nuevo;
        nuevo->anterior = fin;
        fin = nuevo;

    }

    tamano ++;

    return nuevo;
}


void TDA_Secundario::Mostrar(apAnimal actual)
{
    while(actual != NULL )
    {
        lista.Mostrar_Animal( actual->numeroRegistro );
        actual = actual->adyacente;
    }

}


