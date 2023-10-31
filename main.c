#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Autos.h"
#include "Clientes.h"

int main()
{
    menu();
    return 0;
}


void menu (){

int opcion;

system("cls");

printf("*************************");
printf("\n**  ALQUILER DE AUTOS  **");
printf("\n*************************");

printf("\n\n 1)     USUARIO ");
printf("\n\n 2)     ADMINISTRACION \n\nIngresar la opcion:  ");
scanf("%i", &opcion);

switch(opcion){

case 1:

    usuario();

    break;
case 2:

    administracion();
    break;

    default:
        menu();
    break;
}

}

void usuario(){

system("cls");

int opcion, verificar;
printf("\n      USUARIO\n\n 1)  Ingresar\n\n 2)  Nuevo usuario\n\n 3)  volver\n\n\ningresar opcio:  ");
scanf("%i", &opcion);

switch(opcion){

case 1:
    system("cls");

    int dni;
    printf("   Ingresar sesion:   \n\nIngresar su DNI:  ");
    scanf("%i", &dni);

    verificar = verificarUsuario(dni);

    if(verificar != 0){

        usuarioSesionIniciada();

    }else{

        sleep(3);
        system("cls");
        printf("el usuario no existe");
        sleep(3);

    usuario();

    }

    break;

case 2:

    crearNuevoUsuario();
    menu();

    break;

case 3:

    menu();

    break;

default:

    menu();

        break;

}

}


void administracion(){

    system("cls");

}

