#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <conio.h>


#define DELIM_CAD "|"
#define PMODE 0755
#define TAM_MAX_REG 512
#define campo_a_buffreg(br, cad) strcat(br, cad); strcat(br, DELIM_CAD);

char buffreg[TAM_MAX_REG + 1];
char *solicitud[]={
    "\n\tDigita los datos que se te piden, o <ENTER> para salir\nApellido: ",
    "Nombre: ",
    "Direccion: ",
    "Ciudad: ",
    "Estado: ",
    "Cod. Post.: ",
    /** char placa[9];
    char nombre[30];
    int modelo;
    char marca[10];
     */

    "" /* Cadena nula para terminar el ciclo de solicitud */
};

int main(){
    char respuesta[50];
    char nomarch[15];
    int long_reg;
    int fd, i;
    char lon_reg[3];

    printf("\n\n\tProporcione el nombre del archivo que quieres crear: ");
    gets(nomarch);
    if((fd = creat(nomarch, PMODE)) < 0){
        printf("Error en apertura del archivo, din de programa\n");
        exit(1);
    }
    printf("\n\n%s",solicitud[0]);
    gets(respuesta);
    while(strlen(respuesta) > 0){
        buffreg[0] = '\0';
        campo_a_buffreg(buffreg, respuesta);
        camp
        for(i = 1; *solicitud[i] != '\0'; i++){
            printf("%s", solicitud[i]);
            gets(respuesta);
            campo_a_buffreg(buffreg, respuesta);
        }
        /*Escribe la longitud del registro y el contenido del buffer */
        long_reg = strlen(buffreg);
        itoa(long_reg,lon_reg,10);
        write(fd, &lon_reg, 2);
        write(fd, buffreg, long_reg);

        /*Se prepara para los siguientes datos */
        printf("\n\n%s", solicitud[0]);
        gets(respuesta);
    }
    /*Cierra el archivo antes de terminar */
    close(fd);
    return 0;
}
