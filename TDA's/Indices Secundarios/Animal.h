#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <fstream>
#include <string>
#include <string.h>
#include "Otro.h"

class Animal{
public:
    int numeroRegistro;
    char nombre[30], especie[30], nacimiento[30];

    Animal *siguiente;
    Animal *anterior;
    Animal *adyacente;

    void Capturar(int,int);
    void Mostrar();

}anim;

typedef Animal *apAnimal;

#endif
