#include "amigo.hpp"
#include <iostream>

Amigo::Amigo()
{

}

Amigo::Amigo(std::string nombre, std::string direccion, std::string ciudad, std::string estado, std::string codPostal, std::string tel, std::string cumpleanio)
{
    this->nombre = nombre;
    this->direccion = direccion;
    this->ciudad = ciudad;
    this->estado = estado;
    this->codPostal = codPostal;
    this->tel = tel;
    this->cumpleanio = cumpleanio;
}

std::string Amigo::getNombre()
{
    return nombre;
}

std::string Amigo::getDirec()
{
    return direccion;
}

std::string Amigo::getCiudad()
{
    return ciudad;
}

std::string Amigo::getEstado()
{
    return estado;
}

std::string Amigo::getCod()
{
    return codPostal;
}

std::string Amigo::getTel()
{
    return tel;
}

std::string Amigo::getCumple()
{
    return cumpleanio;
}

void Amigo::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

void Amigo::setDirec(std::string direccion)
{
    this->direccion = direccion;
}

void Amigo::setCiudad(std::string ciudad)
{
    this->ciudad = ciudad;
}

void Amigo::setEstado(std::string estado)
{
    this->estado = estado;
}

void Amigo::setCod(std::string codPostal)
{
    this->codPostal = codPostal;
}

void Amigo::setTel(std::string tel)
{
    this->tel = tel;
}

void Amigo::setCumple(std::string cumpleanio)
{
    this->cumpleanio = cumpleanio;
}
