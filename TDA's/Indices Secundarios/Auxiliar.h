#ifndef AUXILIAR_H_INCLUDED
#define AUXILIAR_H_INCLUDED

#include <iostream>
#include <string.h>
#include "Indice.h"
#include "Animal.h"

class Auxiliar{
public:
    apAnimal inicio, fin;

    int tamanio;

    void Pasar();
    void Ordenar_Shell();
    void Quicksort(apAnimal, apAnimal, int, int, apAnimal);
    void Mostrar();


}orden;

#endif
