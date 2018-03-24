#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lista.h"

using namespace std;

int main(int argc, char* argv[]) {
    srand(time(NULL));
    Lista lista;
    int dato;
    for (int i = 0; i < 10; ++i) {
        dato = rand()%100;
        lista.insertar(nullptr, dato);
    }
    lista.mostrar();
    cin.ignore();
    for (int i = 0; i < 10 and !lista.estaVacia(); ++i) {
        std::cout << "borrando el mayor a menor" << "\n";
        lista.borrar(lista.mayor());
        lista.mostrar();
    }
    return 0;
}
