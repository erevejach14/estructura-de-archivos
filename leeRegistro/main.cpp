#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <conio.h>
#include <fcntl.h>
#include <process.h>


#define DELIM_CAD "|"
#define PMODE 0755
#define TAM_MAX_REG 512
#define SOLOLECT 0
#define saca_cad(fd, cad)   write((fd),(cad),strlen(cad));\
                write((fd), DELIM_CAD,1);
#define campo_a_buffreg(br, cad) strcat(br, cad); strcat(br, DELIM_CAD);

using namespace std;

int leecampo(int fd, char cad[]);

int main()
{
    char nomarch[15];
    int long_reg;
    int fd, i;
    string registro;

    printf("\n\n\tProporcione el nombre del archivo que quieres crear: ");
    gets(nomarch);
    if((fd = creat(nomarch, PMODE)) < 0){
        printf("Error en apertura del archivo, din de programa\n");
        exit(1);
    }



    return 0;
}

int leecampo(int fd, char cad[]){
    int i;
    char c;

    i = 0;
    while(read(fd, &c, 1) > 0 && (c != DELIM_CAD))
        cad[i++] = c;
    cad[i] = '\0';

    return(i);
}
