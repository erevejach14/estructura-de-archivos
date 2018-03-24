#include "grafo.h"

Grafo::Grafo()
{
    for(int i = 0; i < 10; i++){
        vertice[i].existe = false;

        for(int j = 0; j < 10; j++){
            arista[i][j].existe = false;
        }
    }
    esDirigido = true;
    esPesado = true;
}
bool Grafo::getesDirigido(){
    return esDirigido;
}
bool Grafo::getesPesado(){
    return esPesado;
}
void Grafo::setesDirigido(bool d){
    esDirigido = d;
}
void Grafo::setesPesado(bool w){
    esPesado = w;
}
bool Grafo::insertaVertice(std::string e){
    int i = 0;

    while(vertice[i].existe){
        i++;
    }
    if(i<10){
        vertice[i].existe = true;
        vertice[i].info = e;
        return true;
    }
    return false;
}
bool Grafo::borraVertice(std::string e){
    for(int i=0;i<10;i++){
        if(vertice[i].info==e){
            vertice[i].existe = false;
            for(int j = 0; j < 10; j++){
                arista[i][j].existe = false;
                arista[j][i].existe = false;
            }
            return true;
        }
    }
    return false;
}
void Grafo::insertaArista(std::string o, std::string d, float w = 0){
    int oP = 0;
    int dP = 0;
    while(vertice[oP].info != o){
        oP++;
    }
    while(vertice[dP].info != d){
        dP++;
    }
    arista[oP][dP].existe = true;
    arista[oP][dP].peso = w;
    if(!esDirigido){
        arista[dP][oP].existe = true;
        arista[dP][oP].peso = w;
    }
}
void Grafo::borraArista(std::string o, std::string d){
    int oP = 0;
    int dP = 0;
    while(vertice[oP].info != o){
        oP++;
    }
    while(vertice[dP].info != d){
        dP++;
    }
    arista[oP][dP].existe = false;
    if(!esDirigido){
        arista[dP][oP].existe = false;
    }
}
void Grafo::imprimir(){
    for(int i = 0; i < 10; i++){
        if(vertice[i].existe){
            std::cout << vertice[i].info;
            for(int j = 0; j < 10; j++){
                if(arista[i][j].existe){
                    std::cout << " -> " << vertice[j].info;
                    if(esPesado){
                        std::cout << " :" << arista[i][j].peso;
                    }
                }
            }
            std::cout<<std::endl;
        }
    }
}
bool Grafo::buscar(std::string in){
    for(int i=0;i<10;i++){
        if(vertice[i].existe&&vertice[i].info==in){
            std::cout<<vertice[i].info;
            for(int j = 0; j < 10; j++){
                if(arista[i][j].existe){
                    std::cout << " -> " << vertice[j].info;
                    if(esPesado){
                        std::cout << " :" << arista[i][j].peso;
                    }
                }
            }
            return true;
        }
    }
    return false;
}
Grafo::Vertice Grafo::getVertice(int i){
    return vertice[i];
}
