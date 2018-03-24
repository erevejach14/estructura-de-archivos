#include "Auxiliar.h"

using namespace std;

void Auxiliar::Mostrar()
{
	apAnimal actual;
	actual = inicio;
	cout<<"____________________" << endl;
    int i = 0;
	while( i < tamanio)
	{
		actual->Mostrar();
		actual = actual->siguiente;
		cout<<"____________________" << endl;
		i++;
	}
}

void Auxiliar::Pasar()
{
    inicio = NULL;
    fin = NULL;
    tamanio = 0;

    apAnimal actual;
    actual = lista.inicio;

    for(int i = 0; i < lista.tamanio ; i++)
    {
        if( i == 0)
        {
            apAnimal nuevo  = new Animal();

            nuevo->numeroRegistro = actual->numeroRegistro;

            strcpy(nuevo->nombre, actual->nombre);

            strcpy(nuevo->especie, actual->especie);

            strcpy(nuevo->nacimiento, actual->nacimiento);

            nuevo->siguiente = NULL;
            nuevo->anterior = NULL;
            inicio = nuevo;
            fin = nuevo;
            tamanio++;
        }
        else{
                apAnimal nuevo, anterior;
                anterior = fin;
                nuevo = new Animal();

                nuevo->numeroRegistro = actual->numeroRegistro;

                strcpy(nuevo->nombre, actual->nombre);

                strcpy(nuevo->especie, actual->especie);

                strcpy(nuevo->nacimiento, actual->nacimiento);

                anterior->siguiente = nuevo;
                nuevo->anterior = anterior;

                nuevo->siguiente = inicio;
                inicio->anterior = nuevo;
                fin = nuevo;
                tamanio++;
            }

            actual = actual->siguiente;
        }
}

void Auxiliar::Quicksort(apAnimal actual, apAnimal siguiente, int extizq, int extder, apAnimal extremo)
{
    if(extizq >=  extder)
	{
		return;
	}
	else
	{
		extremo = inicio;     					// LO QUE HACEMOS AQUI ES MANDAR A EXTREMO EN EL EXTREMO DERECHO
		for(int x = 0; x < extder ; x++)
		{
			extremo = extremo->siguiente;
		}

		actual = inicio;
		siguiente = inicio;


		apAnimal auxiliar = new Animal();     // CREAMOS UN APUNTAODOR AUXILIAR QUE NOS VA A SERVIR PARA HACER LOS INTERCAMBIOS

		int pos;

		pos  = (extizq + extder)/2; // POS TIENE LA POSICION DE EXTIZQ+EXTDER/2

		for(int x = 0; x < pos ; x++)
		{
			actual = actual->siguiente;   	// 	A ACTUAL LO POSICIONAMOS EN LA POSICION DE POS
		}
		// HACEMOS EL PRIMER INTERCAMBIO QUE MARCA EL CODIGO DE QUICKSORT
		// USAMOS EL AUXILIAR PARA ALMACENAR LOS DATOS TEMPORALMENTE
		strcpy(auxiliar->nombre,actual->nombre);
		strcpy(auxiliar->especie,actual->especie);
		strcpy(auxiliar->nacimiento,actual->nacimiento);
		auxiliar->numeroRegistro = actual->numeroRegistro;


		strcpy(actual->nombre , extremo->nombre);
		strcpy(actual->especie , extremo->especie);
		strcpy(actual->nacimiento , extremo->nacimiento);
		actual->numeroRegistro = extremo->numeroRegistro;

		strcpy(extremo->nombre , auxiliar->nombre);
		strcpy(extremo->especie , auxiliar->especie);
		strcpy(extremo->nacimiento , auxiliar->nacimiento);
		extremo->numeroRegistro = auxiliar->numeroRegistro;


		int i, j;

		i = extizq;

		j = extder;

		while(i < j)
		{

			// LO QUE SIGUE ES POSICIONAR A ACTUAL Y SIGUIENTE EN LOS EXTREMOS DE I Y J

			//		NUESTROS APUNTADORES DE I Y J SERAN ACTUAL Y SIGUIENTE

			actual = inicio;    // ACTUAL USARA LA REFERENCIA DE i

			siguiente = inicio;

			for(int x = 0; x < i ; x++)
			{
				actual = actual->siguiente;
			}

			for(int x = 0; x < j ; x++)
			{
				siguiente = siguiente->siguiente;
			}

			/*
					AHORA ENTRAMOS A LOS WHILE QUE NOS MARCA EL CODIGO DEL QUICK

			*/


			while( i < j && ( strcmp(actual->nombre, extremo->nombre) == 0 || strcmp(actual->nombre, extremo->nombre) == 1) )
			{
				i = i + 1;
				// CON CADA AUMENTO DE i, TAMBIEN VAMOS RECORRIENDO ACTUAL

				actual = actual->siguiente;
			}

			while( i < j && ( strcmp(siguiente->nombre, extremo->nombre) == 0 || strcmp(siguiente->nombre, extremo->nombre) == -1))
			{
				j = j - 1;
				// CON CADA DECREMENTO DE J, RECORREMOS SIGUIENTE AL ANTERIOR
				siguiente = siguiente->anterior;
			}

			if( i != j)		// SI I ES DIFERENTE DE J HACEMOS EL INTERCAMBIO UTILIZANDO AUXILIAR
			{

                strcpy(auxiliar->nombre,actual->nombre);
                strcpy(auxiliar->especie,actual->especie);
                strcpy(auxiliar->nacimiento,actual->nacimiento);
                auxiliar->numeroRegistro = actual->numeroRegistro;


                strcpy(actual->nombre , siguiente->nombre);
                strcpy(actual->especie , siguiente->especie);
                strcpy(actual->nacimiento , siguiente->nacimiento);
                actual->numeroRegistro = siguiente->numeroRegistro;

                strcpy(siguiente->nombre , auxiliar->nombre);
                strcpy(siguiente->especie , auxiliar->especie);
                strcpy(siguiente->nacimiento , auxiliar->nacimiento);
                siguiente->numeroRegistro = auxiliar->numeroRegistro;

			}

		}   // 	AQUI TERMINA EL WHILE
		// HACE LA VALIDACION
		if( i != extder)
			{

                strcpy(auxiliar->nombre,actual->nombre);
                strcpy(auxiliar->especie,actual->especie);
                strcpy(auxiliar->nacimiento,actual->nacimiento);
                auxiliar->numeroRegistro = actual->numeroRegistro;


                strcpy(actual->nombre , extremo->nombre);
                strcpy(actual->especie , extremo->especie);
                strcpy(actual->nacimiento , extremo->nacimiento);
                actual->numeroRegistro = extremo->numeroRegistro;

                strcpy(extremo->nombre , auxiliar->nombre);
                strcpy(extremo->especie , auxiliar->especie);
                strcpy(extremo->nacimiento , auxiliar->nacimiento);
                extremo->numeroRegistro = auxiliar->numeroRegistro;

			}

		Quicksort(actual, siguiente, extizq , i - 1, extremo);  // SE VUELVE A LLAMAR
		Quicksort(actual, siguiente, i+1 , extder, extremo );   // SE VUELVE A LLAMAR
	}
}


void Auxiliar::Ordenar_Shell()
{
	apAnimal actual, siguiente;
	actual = inicio;
	siguiente = inicio;
	float fact;
	int dif,tam, in, ide;
	char nom[30], esp[30], nac[30];
	fact = 0.75;
	tam = tamanio;


	dif = ((tam - 1) * (fact));

	while (dif > 0)
	{
		in = 0;

		while (in <= ((tamanio - 1) - dif))
		{
			siguiente = inicio;
			for (int x = 0; x < (in + dif); x++)
			{
				siguiente = siguiente->siguiente;
			}

			if ( strcmp(actual->nombre , siguiente->nombre) == 1 )
			{
				ide = siguiente->numeroRegistro;
				strcpy(nom , siguiente->nombre);
				strcpy(nac , siguiente->nacimiento);
				strcpy(esp , siguiente->especie);

				strcpy(siguiente->nombre , actual->nombre);
				siguiente->numeroRegistro = actual->numeroRegistro;
				strcpy(siguiente->nacimiento , actual->nacimiento);
				strcpy(siguiente->especie , actual->especie);

				strcpy(actual->nombre , nom);
				actual->numeroRegistro = ide;
				strcpy(actual->nacimiento , nac);
				strcpy(actual->especie , esp);

			}
			in = in + 1;
			actual = actual->siguiente;

		}
		dif = (dif * fact);
		actual = inicio;
	}



}
