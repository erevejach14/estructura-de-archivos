#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <iostream>
#include <string>

class Grafo
{
private:
    struct Vertice
    {
        bool existe;
        std::string info;
    };
    struct Arista
    {
        bool existe;
        float peso;
    };
    bool esDirigido;
    bool esPesado;

public:
    Vertice vertice[10];
    Arista arista[10][10];

    Grafo();

    bool getesDirigido();
    bool getesPesado();

    void setesDirigido(bool);
    void setesPesado(bool);

    bool insertaVertice(std::string);
    bool borraVertice(std::string);

    void insertaArista(std::string, std::string, float);
    void borraArista(std::string, std::string);

    void imprimir();
    bool buscar(std::string);
    Vertice getVertice(int);
};

#endif // GRAFO_H_INCLUDED
