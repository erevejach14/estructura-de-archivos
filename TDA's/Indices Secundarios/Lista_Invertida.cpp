#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Lista_Especie.h"
#include "Lista_Invertida.h"
#include "TDA_Secundario.h"

using namespace std;

void Lista_Invertida::Add_Especie(apAnimal anim)
{
    bool existe;
    existe = GetEspecie(anim->especie);

    if( !existe )
    {
        apEspecie nuevo = new Especie();

        if(inicioEspecie != NULL )
        {
            strcpy(nuevo->especie,anim->especie);

            finEspecie->siguienteEspecie = nuevo;
            finEspecie = nuevo;
            nuevo->siguienteEspecie = NULL;

            nuevo->haciaAnimal = secundario.Insertar(anim, NULL, existe);

        }
        else{
            strcpy(nuevo->especie,anim->especie);
            nuevo->siguienteEspecie = NULL;
            inicioEspecie = nuevo;
            finEspecie = nuevo;

            nuevo->haciaAnimal = secundario.Insertar(anim, NULL, existe);

        }
    }
    else{
        apEspecie actual;
        actual = GetNodo(anim->especie);

        secundario.Insertar(anim, actual->haciaAnimal , existe);

    }

}

bool Lista_Invertida::Vacia()
{
    if( inicioEspecie == NULL )
    {
        return true;
    }
    return false;
}

apEspecie Lista_Invertida::GetNodo(char esp[30])
{
    if( Vacia() == false )
    {
        apEspecie actual;
        actual = inicioEspecie;

        while ( strcmp(actual->especie , esp) != 0 )
        {
            actual = actual->siguienteEspecie;
        }

        return actual;
    }

    return NULL;

}

bool Lista_Invertida::GetEspecie(char especie[30])
{
	apEspecie aux;
	aux = inicioEspecie;
	while( aux != NULL)
	{
		if( strcmp(aux->especie,especie) == 0 )
		{
			return true;
		}
		aux = aux->siguienteEspecie;
	}
	return false;

}


void Lista_Invertida::Inicializar()
{
    inicioEspecie = NULL;
    finEspecie = NULL;
}

void Lista_Invertida::Mostrar_Especie(apEspecie especie)
{
    if( !Vacia() )
    {
        cout << "REGISTROS DE ESPECIE: " << especie->especie << endl;
        cout<<"\n____________________________________"<<endl;

        apAnimal actual;
        actual = especie->haciaAnimal;

        secundario.Mostrar(actual);
    }
    else{
        cout << "\n\tLA LISTA INVERTIDA ESTA VACIA " << endl;
    }
}


