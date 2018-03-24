#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

#include <cstdlib>
#include <string>

#include "lista.h"
#include "musica.h"

class Interfaz {
    private:
        Lista<Musica> listaMusica;
        int indice;
        void menuPrincipal();
        void menuIngresar();
        void menuEliminar();
        void menuOrdenar();
        void enterParaContinuar();
    public:
        Interfaz();
    };

#endif // INTERFAZ_H_INCLUDED
