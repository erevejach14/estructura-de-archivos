#include "menu.hpp"
#include "amigo.hpp"

#include <iostream>

static char *menu[]={
    "\n\tSeleccione una opcion\n\t1)AGREGAR UN NUEVO AMIGO",
    "\n\t2)EXTRAER UN AMIGO PARA ACTUALIZAR SUS DATOS",
    "\n\t3)BORRAR UN AMIGO LOGICAMENTE",
    "\n\t4)BORRAR UN AMIGO FISICAMENTE",
    "\n\t0)SALIR DEL PROGRAMA",
    "\n\n\tDIGITE EL NUMERO DE TU ELECCION: ",
    ""
};

static char *solicitud[]={"\n\nAPELLIDO: ",
"NOMBRE: ",
"DIRECCION: ",
"CIUDAD: ",
"ESTADO: ",
"COD. POSTAL: ",
"TELEFONO: ",
"CUMPLEAÑOS: ",
""};

static std::string respuesta[]={apellido,
nimbre,
direccion,
ciudad,
estado,
codPostal,
tel,
cumpleanios,
};

Menu::Menu(){
    menuMost();
}

void Menu::menuMost(){
    char opc;
    for(int i = 0; *menu[i] != '\0'; i++){
        std::cout << menu[i];
    }
    std::cin >> opc;

    switch(opc){
    case '1' :
        agregar();
        break;
    case '2':
        extraer();
        break;
    case '3':
        borrarLog();
        break;
    case '4':
        borrarFis();
        break;
    case '0':
        salir();
        break;
    default:
        std::cout << "\n\nError opcion incorrecta\n\n";
    }
}

void Menu::agregar()
{
    Amigo ami;

    std::cout << solicitud[0] << std::endl;
    std::cin >> respuesta[0];

    while(strlen(respuesta) > 0){
        for(i = 1; *solicitud[i] != '\0'; i++){
            std::cout << solicitud[i] << std::endl;
            std::cin >> respuesta[i];
            ;
        }
        /*Escribe la longitud del registro y el contenido del buffer */
        long_reg = strlen(buffreg);
        write(fd, &long_reg, 2);
        write(fd, buffreg, long_reg);

        /*Se prepara para los siguientes datos */
        printf("\n\n%s", solicitud[0]);
        gets(respuesta);
    }
}

void Menu::extraer()
{

}

void Menu::borrarLog()
{

}

void Menu::borrarFis()
{

}

void Menu::salir()
{

}
