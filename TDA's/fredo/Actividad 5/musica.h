#ifndef MUSICA_H_INCLUDED
#define MUSICA_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

class Musica{
private:
    std::string autor;
    std::string interprete;
    std::string cancion;
    int ranking;
    public:
        Musica();
        Musica(const Musica&);
        std::string getAutor();
        std::string getInterprete();
        std::string getCancion();
        int getRanking();
        void setAutor(std::string);
        void setInterprete(std::string);
        void setCancion(std::string);
        void setRanking(int);

        std::string toString();
        /*
        bool operator == (const Musica&);
        bool operator != (const Musica&);
        bool operator < (const Musica&);
        bool operator > (const Musica&);
        bool operator <= (const Musica&);
        bool operator >= (const Musica&);
        */
        friend std::ostream& operator << (std::ostream& os,Musica&);
        friend std::istream& operator >> (std::istream& is,Musica&);

};

#endif // MUSICA_H_INCLUDED
