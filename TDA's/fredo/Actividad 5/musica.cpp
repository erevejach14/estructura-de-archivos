#include "musica.h"

Musica::Musica() {
    ranking=0;
    }

Musica::Musica(const Musica& mus): Musica() {
    autor = mus.autor;
    interprete = mus.interprete;
    cancion = mus.cancion;
    ranking = mus.ranking;
    }

std::string Musica::getAutor() {
    return autor;
    }

std::string Musica::getInterprete() {
    return interprete;
    }

std::string Musica::getCancion() {
    return cancion;
    }

int Musica::getRanking() {
    return ranking;
    }

void Musica::setAutor(std::string au) {
    autor = au;
    }

void Musica::setInterprete(std::string in) {
    interprete = in;
    }

void Musica::setCancion(std::string ca) {
    cancion = ca;
    }

void Musica::setRanking(int ra) {
    ranking = ra;
    }
/*
bool Musica::operator==(const Musica&r) {
    ranking == r.ranking;
    }

bool Musica::operator!=(const Musica&r) {
    ranking != r.ranking;
    }

bool Musica::operator<(const Musica&r) {
    ranking < r.ranking;
    }

bool Musica::operator>(const Musica&r) {
    ranking > r.ranking;
    }

bool Musica::operator<=(const Musica&r) {
    ranking <= r.ranking;
    }

bool Musica::operator>=(const Musica&r) {
    ranking >= r.ranking;
    }
*/
std::string Musica::toString() {
    char r[10];
    sprintf(r,"%i",ranking);
    return autor + "\n" +
           interprete + "\n" +
           cancion + "\n" +
           r;
    }
std::ostream& operator << (std::ostream& os, Musica& mus) {
    os <<"-Nombre del Autor: "  << mus.autor << std::endl
       <<"-Nombre del Interprete: " << mus.interprete <<std::endl
       <<"-Nombre de la cancion: " << mus.cancion << std::endl
       <<"-Ranking: " << mus.ranking << std::endl;

    return os;
    }
std::istream& operator >> (std::istream& is, Musica& mus) {
    std::string myString;

    std::getline(is, mus.autor);
    std::getline(is, mus.interprete);
    std::getline(is, mus.cancion);
    std::getline(is, myString);
    mus.ranking = atoi(myString.c_str());

    return is;
    }
