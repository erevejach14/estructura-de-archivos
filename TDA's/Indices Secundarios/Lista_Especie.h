#ifndef LISTA_ESPECIE_H_INCLUDED
#define LISTA_ESPECIE_H_INCLUDED

#include "Animal.h"

class Especie{
public:
    char especie[30];
    Especie *siguienteEspecie;
    apAnimal haciaAnimal;

    void Hola();

};
typedef Especie *apEspecie;




#endif
