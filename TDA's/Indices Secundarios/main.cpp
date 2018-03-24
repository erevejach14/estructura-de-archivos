#include "Animal.cpp"
#include "Indice.cpp"
#include "TDA_Secundario.cpp"
#include "Auxiliar.cpp"
#include "Lista_Especie.cpp"
#include "Lista_Invertida.cpp"
#include "Menu.cpp"

int main()
{
    lista.Inicializar();
    invertida.Inicializar();
    secundario.Inicializa();
    lista.Cargar();
    Menu();
    lista.Almacenar();

    return 0;
}
