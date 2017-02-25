#ifndef AMIGO_HPP_INCLUDED
#define AMIGO_HPP_INCLUDED
#include <iostream>

class Amigo{
private:
    std::string nombre;
    std::string direccion;
    std::string ciudad;
    std::string estado;
    std::string codPostal;
    std::string tel;
    std::string cumpleanio;
public:
    Amigo();
    Amigo(std::string, std::string, std::string, std::string, std::string, std::string, std::string);
    std::string getNombre();
    std::string getDirec();
    std::string getCiudad();
    std::string getEstado();
    std::string getCod();
    std::string getTel();
    std::string getCumple();

    void setNombre(std::string);
    void setDirec(std::string);
    void setCiudad(std::string);
    void setEstado(std::string);
    void setCod(std::string);
    void setTel(std::string);
    void setCumple(std::string);
};

#endif // AMIGO_HPP_INCLUDED
