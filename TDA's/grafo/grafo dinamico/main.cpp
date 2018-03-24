#include <iostream>
#include "grafo.h"

using namespace std;

int main(int argc, char const *argv[]) {
  Grafo gra;

  int op;
  do{
      menu();
      cin>>op;

      switch(op)
      {
          case 1:
                  insertar_nodo();
                  break;
          case 2: insertar_arista();
                  break;
          case 3: eliminar_nodo();
                  break;
          case 4: eliminar_arista();
                  break;
          case 5: mostrar_grafo();
                  break;
          case 6: mostrar_aristas();
                  break;
          default: cout<<"OPCION NO VALIDA...!!!";
                   break;
        }
        cout<<endl<<endl;
    }while(op!=7);
    getch();
    return 0;
}
void menu()
{
    cout<<"\n\tREPRESENTACION DE GRAFOS DIRIGIDOS\n\n";
    cout<<" 1. INSERTAR UN NODO                 "<<endl;
    cout<<" 2. INSERTAR UNA ARISTA              "<<endl;
    cout<<" 3. ELIMINAR UN NODO                 "<<endl;
    cout<<" 4. ELIMINAR UNA ARISTA              "<<endl;
    cout<<" 5. MOSTRAR  GRAFO                   "<<endl;
    cout<<" 6. MOSTRAR ARISTAS DE UN NODO       "<<endl;
    cout<<" 7. SALIR                            "<<endl;

    cout<<"\n INGRESE OPCION: ";
}
