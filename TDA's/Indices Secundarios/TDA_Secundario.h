#ifndef TDA_SECUNDARIO_H_INCLUDED
#define TDA_SECUNDARIO_H_INCLUDED

#include "Animal.h"

class TDA_Secundario{
public:
    int tamano;
    apAnimal inicio, fin;

    void Inicializa();
    apAnimal Insertar(apAnimal, apAnimal, bool);
    void Mostrar(apAnimal);

}secundario;

typedef TDA_Secundario *apSecundario;


#endif
