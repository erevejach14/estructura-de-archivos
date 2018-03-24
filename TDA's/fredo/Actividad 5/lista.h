#ifndef Lista_H_INCLUDED
#define Lista_H_INCLUDED

#include <exception>
#include <iostream>
#include <fstream>
#include <string>

#include "musica.h"


//Esta clase es del Dr. Alfredo Gutiérrez Hernández.
class listException: std::exception {
    private:
        std::string msg;
    public:
        explicit listException(const char* message):msg(message) {}
        explicit listException(const std::string & message):msg(message) {}
        virtual ~listException() throw() {}
        virtual const char* what() const throw() {
            return msg.c_str();
            }
    };

template <class T>
class Lista {
    private:
        T dato[50];
        int ultimo;
    public:
        Lista();
        bool vacio();
        bool lleno();
        void insertaDato(const int&, const T&);
        void insertaDato(const T&);
        void borrarDato(const int&);

        int getprimero();
        int getUltimo();
        int getPrevio(const int&);
        int getSiguiente(const int&);

        T recupera(const int&);
        void ordenaAutor();
        void ordenaInterprete();
        void ordenaCancion();
        void ordenaRanking();
        void imprimir();
        void borrarTodo();

        void ordenaDato();
        void imprimeDato();

        void escribirEnDisco(std::string);
        void leerEnDisco(std::string);

    };

template <class T>
Lista<T>::Lista() {
    ultimo = -1;
    }
template <class T>
bool Lista<T>::vacio() {
    return ultimo == -1;
    }
template <class T>
bool Lista<T>::lleno() {
    return ultimo ==499;
    }
template <class T>
void Lista<T>::insertaDato(const int& pos, const T& ele) {
    if(pos <-1 or pos > ultimo) {
        throw listException("La posicion para insertar es invalida.");
        return;
        }
    dato[pos] = ele;
    ultimo++;
    }
template <class T>
void Lista<T>::insertaDato(const T& ele) {
    dato[++ultimo] = ele;

    }
template <class T>
void Lista<T>::borrarDato(const int& pos) {
    if(pos<0 or pos> ultimo) {
        throw listException("La posicion para eliminar es invalida");
        return;
        }
    int i=pos;
    while(i<ultimo) {
        dato[i]=dato[i+1];
        i++;
        }
    ultimo--;
    }
template <class T>
int Lista<T>::getprimero() {
    if(vacio()) {
        return -1;
        }
    return 0;
    }
template <class T>
int Lista<T>::getUltimo() {
    return 0;
    }
template <class T>
int Lista<T>::getPrevio(const int& pos) {
    if(vacio() or pos <1 or pos >ultimo) {
        return -1;
        }
    return pos -1;
    }
template <class T>
int Lista<T>::getSiguiente(const int& pos) {
    if(vacio()or pos <0 or pos > ultimo) {
        return -1;
        }
    return pos + 1;
    }
template <class T>
T Lista<T>::recupera(const int& pos) {
    if(vacio()or pos <0 or pos > ultimo) {
        throw listException("Excepcion");
        }
    else {
        return dato[pos];
        }
    }
template <class T>
void Lista<T>::ordenaAutor() {
    for(int i=0; i<ultimo; i++)
        for(int j=0; j<ultimo-i; j++)
            if(dato[j].getAutor()<=dato[j+1].getAutor()) {
                T aux=dato[j];
                dato[j]=dato[j+1];
                dato[j+1]=aux;
                }
    }
template <class T>
void Lista<T>::ordenaInterprete() {
    for(int i=0; i<ultimo; i++)
        for(int j=0; j<ultimo-i; j++)
            if(dato[j].getInterprete()<=dato[j+1].getInterprete()) {
                T aux=dato[j];
                dato[j]=dato[j+1];
                dato[j+1]=aux;
                }
    }
template <class T>
void Lista<T>::ordenaCancion() {
    for(int i=0; i<ultimo; i++)
        for(int j=0; j<ultimo-i; j++)
            if(dato[j].getCancion()<=dato[j+1].getCancion()) {
                T aux=dato[j];
                dato[j]=dato[j+1];
                dato[j+1]=aux;
                }
    }
template <class T>
void Lista<T>::ordenaRanking() {
    for(int i=0; i<ultimo; i++)
        for(int j=0; j<ultimo-i; j++)
            if(dato[j].getRanking()<=dato[j+1].getRanking()) {
                T aux=dato[j];
                dato[j]=dato[j+1];
                dato[j+1]=aux;
                }
    }
template <class T>
void Lista<T>::imprimir() {
    int i=0;
    while(i<=ultimo) {
        std::cout<< dato[i] << std::endl;
        i++;
        }
    }
template <class T>
void Lista<T>::borrarTodo() {
    ultimo=-1;
    }
template <class T>
void Lista<T>::ordenaDato() {

    }
template <class T>
void Lista<T>::imprimeDato() {
    for(int i=0; i<=ultimo; i++) {
        std::cout << dato[i] << std::endl << std::endl;
        }
    }
template <class T>
void Lista<T>::escribirEnDisco(std::string nombreArchivo) {
    std::ofstream miArchivo;

    miArchivo.open(nombreArchivo,miArchivo.trunc);
    if(!miArchivo.is_open()) {
        throw listException("Error de escritura al disco.");
        }

    for(int i=0; i<=ultimo; i++) {
        miArchivo << dato[i] <<std::endl;
        }
    miArchivo.close();
    }

template <class T>
void Lista<T>::leerEnDisco(std::string nombreArchivo) {
    std::ifstream miArchivo;
    T miGrabado;

    miArchivo.open(nombreArchivo);
    if(!miArchivo.is_open()) {
        throw listException("Error de lectura de disco");
        }
    borrarTodo();
    try {
        while(miArchivo >> miGrabado) {
            insertaDato(getUltimo(),miGrabado);
            }
        }
    catch(listException ex) {
        miArchivo.close();

        std::string error;
        error = "Hubo problema al insertar, leyendo desde el disco \n El error reportado es: ";
        error += ex.what();

        throw listException(error);
        }
    miArchivo.close();
    }
#endif // Lista_H_INCLUDED
