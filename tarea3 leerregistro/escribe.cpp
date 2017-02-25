#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DELIM_CAD "|"
#define DELIM_R "@"
#define PMODE      0755
#define TAM_MAX_REG 512
#define campo_a_buffreg(br,cad) strcat(br,cad); strcat(br,DELIM_CAD);

char buffreg[TAM_MAX_REG+1];
char buffreg2[TAM_MAX_REG+1];
char *solicitud[]=
{
	"\n\n\tdigita los datos que se te piden, o <enter> para salir\n\napellido:",
	"Nombre:",
	"Direccion:",
	"Estado:",
	"cod postal:",
	"" /*cade nula para terminar ciclo de solicitud*/
};
	int main ()
	{
		char respuesta[50];
		char nomarch[15];
		int fd,i;
		int long_reg;
		system("cls");
		printf("\n\nproporcione el nombre del archivo a crear: ");
		gets(nomarch);
		if ((fd=creat(nomarch,PMODE))<0)
		{
			printf("error en apertura del archivo-fin de programa\n");
			exit(1);
		}
		printf("\n\n%s",solicitud[0]);
		gets(respuesta);
		while(strlen(respuesta)>0)
		{
			buffreg[0]='\0';
			campo_a_buffreg(buffreg, respuesta);
			 write(fd,DELIM_R,1);
			for(i=1;*solicitud[i]!='\0';i++)
			{
				printf("\n\n%s",solicitud[i]);
				gets(respuesta);
				campo_a_buffreg(buffreg,respuesta);
			}
			/*escribe la longitud del registro y el contenido del buffer */

			//long_reg = strlen(buffreg);
			//itoa(long_reg,long_reg,10);
			//write(fd,long_reg,2);

            write(fd,&long_reg,2);
			write(fd,buffreg,long_reg);

			/*se prepara para los siguientes datos*/
			printf("%s",solicitud[0]);
			gets(respuesta);
		}
		/*cierra el archivo antes de terminar*/
		close(fd);
	}
