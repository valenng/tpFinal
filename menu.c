#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Autos.h"
#include "Clientes.h"
#include "menu.h"


void menu ()
{

    int opcion;

    system("cls");

    printf("*************************");
    printf("\n**  ALQUILER DE AUTOS  **");
    printf("\n*************************");

    printf("\n\n 1)     USUARIO ");
    printf("\n\n 2)     ADMINISTRACION \n\nIngresar la opcion:  ");
    scanf("%i", &opcion);

    switch(opcion)
    {

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

void usuario()
{

    system("cls");

    int opcion, verificar;
    printf("\n      USUARIO\n\n 1)  Ingresar\n\n 2)  Nuevo usuario\n\n 3)  volver\n\n\ningresar opcio:  ");
    scanf("%i", &opcion);

    switch(opcion)
    {

    case 1:
        system("cls");

        int dni;
        printf("   Ingresar sesion:   \n\nIngresar su DNI:  ");
        scanf("%i", &dni);

        /// verificar usuario
        verificar = verificarUsuario(dni);

        if(verificar != 0)
        {

            system("cls");
            printf("        inicio de sesion");
            sleep(3);
            usuarioSesionIniciada();

        }
        else
        {

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


void usuarioSesionIniciada(){


  int opcion;

    do {
        system("cls");

        printf("Menu de Alquiler de Autos:\n");
        printf("1) Ver catalogo de autos disponibles\n");
        printf("2) ver los autos mas populares\n ");
        printf("3) Alquilar un auto\n");
        printf("4) Devolver un auto alquilado\n");
        printf("5) Ver historial de alquileres\n");
        printf("6) Información personal\n");
        printf("7) Cerrar sesion\n");
        printf("Ingrese la opción deseada: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                /// falta funcion
                break;
            case 2:
                /// falta funcion
                break;
            case 3:
                /// falta funcion
                break;
            case 4:
                /// falta funcion
                break;
            case 5:
                /// falta funcion
                break;
            case 6:

                system("cls");
                printf("\n\n        Sesion cerrada. ¡Hasta luego!");
                sleep(3);
                /// falta funcion
                break;
            default:
                break;
        }

    } while (opcion != 7);
}




void administracion()
{

    system("cls");

}

