#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fcntl.h>
#include <process.h>
#define SOLOLECT 0
#define DELIM_CAR '|'

int leecampo(int fd,char cad[], int longi);
char *solicitud[]=
{
	"Apellido:",
	"Nombre:",
	"Direccion:",
	"Estado:",
	"cod postal:"
	//"" /*cade nula para terminar ciclo de solicitud*/
};

int main()
{

	int fd,n;
	char cad[30],c;
	char nomarch[15];
	int cont_campos;
	int longi;
	system ("cls");
	printf("\n\t con este programa puedes ver los datos de tus amigos\n");
	printf("\t que ya han sido guardados en un archivo.\n");
	printf("\t digita el nombre del archivo que quieres ver: ");
	gets(nomarch);
	if ((fd=open(nomarch,SOLOLECT))<0)
	{
		printf("Error en la apertura del archivo\n");
		exit(1);
	}
	cont_campos=0;
	printf("\n\t los amigos que se encuentren en este archivo son:\n");
    read(fd, &longi, 2);
	while((n=leecampo(fd,cad, longi))>0){
        printf("\t %s: %s\n", solicitud[cont_campos++],cad);
        if(cont_campos == 5)
            cont_campos = 0;
	}
	getch();
	close(fd);

}

int leecampo (int fd, char cad[], int longi)
{
	int i;
	char c;
	i=0;
	while(read(fd,&c,1)>0 && (c != DELIM_CAR) && i<longi)
	cad[i++]=c;
	cad[i]='\0';
	return(i);
}
