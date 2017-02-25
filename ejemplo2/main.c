#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <fcntl.h>
#include <process.h>

#define SOLOLECT 0
#define DELIM_CAD "|"
#define saca_cad(fd, cad)   write((fd),(cad),strlen(cad));\
                write((fd), DELIM_CAD,1);

int leecampo(int fd, char cad[]);

int main(){

    char cad[30], nomarch[15];
    int fd, n, cont_campos;
    //clrscr();
    printf("\n\t    Con este programa puedes ver los datos de tus amigos favoritos.\n");
    printf("\n\t\tProporcione el nombre del archivo que quiera crear:");
    gets(nomarch);
    if(fd =open(nomarch, SOLOLECT)<0)
    {
        printf("Fin del programa\n");
        exit(1);
    }
    //clrscr();
    cont_campos = 0;

    printf("\n\t    Los amigos que se encuentran en este archivo son:\n");
    while(n = leecampo(fd, cad)>0)
        printf("\t\t    Campo # %3d:  %s\n", ++cont_campos, cad);
    getch();
    close(fd);
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
