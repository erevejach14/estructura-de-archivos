#include "pila.h"
#include "pila.cpp"
#include <cstdlib>

/*********************************************************
*               Autor: Angel Rengifo Cancino             *
*               e-mail: durazno@ayudairc.org             *
**********************************************************
* He procurado que este código  se ajuste lo más posible *
* al estándar  ANSI C/C++ para que pueda  ser fácilmente *
* transportable  a cualquier  compilador sobre cualquier *
* plataforma. Compilé sin problemas este código sobre el *
* GCC y el DJGPP  de GNU.  No habría problema alguno con *
* cualquier otro compilador.                             *
**********************************************************
* Este código puede ser libremente copiado y distribuido *
* siempre y cuando se mantenga intacta esta nota.  Úsese *
* para aprender de él y  ompartamos el conocimiento con  *
* todos para hacer cada día un mejor software.           *
*********************************************************/

void menu();
int main()
{
    pila <int> P;
    /* Aqui se crea un objeto de la clase 'pila'. Se especifica el tipo de datos de los que estará formada la 
    pila '<int>'. Es decir, será una pila de números enteros. Puede especificarse en su lugar otro tipo de datos 
    como por ejemplo: <int>,<char>,<alumno> ('alumno' seria un tipo de dato definido por el usuario) */
    char c[20];
    int N;
    while (1)
    {
	    printf("\nComando (m para obtener ayuda): ");
	    scanf("%19s",c);
    	if (*c == 'e')
	    {
		    printf("Ingrese un valor a empilar: ");
		    scanf("%d",&N);
		    if (!P.empilar(N))
			    printf("Memoria insuficiente para trabajar con la pila");
	    }
	    else if (*c == 'd')
	    {
		    if (P.vacio())
			    printf("No hay elementos en la pila");
		    else
			    printf("%d",P.desempilar());
	    }
	    else if (*c == 'v')
	        P.destruir();
	    else if (*c == 'm')
		    menu();
	    else if (*c == 'c')
		    system("clear");//'system("clear")' es para sistemas Unix. Usar 'system("cls")' para MS-DOS
	    else if (*c == 's')
	    {
		    printf("\n");
		    exit(0);
	    }
	    else
		    printf("%s: comando desconocido",c);
    }
    return EXIT_SUCCESS;
}
void menu()
{
	printf("Accion del comando\n");
	printf("  e  Empilar un valor a la pila\n");
	printf("  d  Desempilar el valor de la cima\n");
	printf("  v  Vaciar o destruir la pila\n");	
	printf("  m  Imprime este menu\n");
	printf("  c  Limpia la pantalla\n");
	printf("  s  Salir del programa\n");
}
