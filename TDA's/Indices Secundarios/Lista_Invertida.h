#ifndef LISTA_INVERTIDA_H_INCLUDED
#define LISTA_INVERTIDA_H_INCLUDED

class Lista_Invertida{
public:
    apEspecie inicioEspecie;
    apEspecie finEspecie;

    bool GetEspecie(char*);
    apEspecie GetNodo(char*);
    void Inicializar();
    void Add_Especie(apAnimal);
    bool Vacia();

    void Mostrar_Especie(apEspecie);


}invertida;


#endif // LISTA_INVERTIDA_H_INCLUDED
