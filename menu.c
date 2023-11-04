#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Autos.h"
#include "Clientes.h"
#include "menu.h"
#include "listas2Clientes.h"


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
            printf("\n\n        Inicio de sesion");
            ///sleep(3);
            usuarioSesionIniciada(dni);

        }
        else
        {

            ///sleep(3);
            system("cls");
            printf("el usuario no existe");
            ///sleep(3);

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

        usuario();

        break;

    }

}


void usuarioSesionIniciada(int DNI)
{


    int opcion;

    do
    {
        system("cls");

        printf("Menu de Alquiler de Autos:\n\n");
        printf("1) Ver catalogo de autos disponibles\n");
        printf("2) ver los autos mas populares\n");
        printf("3) Alquilar un auto\n");
        printf("4) Devolver un auto alquilado\n");
        printf("5) Ver historial de alquileres\n");
        printf("6) Información personal\n");
        printf("7) Cerrar sesion\n");
        printf("Ingrese la opción deseada: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
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
            printf("\n\n        Información personal");
            mostrarInformacionDelCliente(DNI);
            fflush(stdin);
            esperarTecla();
            usuarioSesionIniciada(DNI);


        /// falta funcion

        case 7:

            system("cls");
            printf("\n\n        Sesion cerrada. ¡Hasta luego!");
            ///sleep(3);
            menu();
            /// falta funcion
            break;
        default:
            break;
        }

    }
    while (opcion != 7);
}




void administracion()
{

    int opcion;
    system("cls");
    printf("Menu de Alquiler de Autos:\n\n\n1)    Menu autos\n2)    Menu clientes\n3)    Menu alquileres\n4)    volver\n\n     Ingresar opcion:  ");

    scanf("%i", &opcion);
    switch(opcion)
    {

    case 1:

        menuAutos();

        break;
    case 2:

        menuCliente();

        break;

    case 3:

        menuAlquiler();

        break;

    case 4:

        menu();

        break;

    default:

        administracion();

        break;

    }

    system("cls");

}

void menuAutos()
{

    system("cls");
    int opcion;
    printf("1)Lista de autos\n  2)Busqueda De Auto\n    3)Autos disponibles\n   4)Agregar autos\n   5)Modificar auto\n    6)    Eliminar auto\n\n   ingresar opcion: ");
    scanf("%i", &opcion);


}

void menuCliente()
{
    system("cls");
    int opcion, DNI;
    printf("\n\n    1)Info cliente\n    2)Lista de clientes\n    3)Modificar cliente\n    4)Eliminiar cliente\n    5)bloquear\n    6)Volver\n\n    ingresar opcion:");
    scanf("%i", &opcion);

    switch(opcion)
    {

    case 1:

        system("cls");
        printf("\n\nIngresar el DNI buscado:  ");
        scanf("%i", &DNI);
        fflush(stdin);
        if(verificarUsuario(DNI)==1){

            mostrarInformacionDelCliente(DNI);
            esperarTecla();

        }else{
            system("cls");
            printf("\n\n    El DNI no existe");
            ///sleep(3);
        }

        menuCliente();


        break;
    case 2:
        system("cls");
        nodo2Clientes * lista2 = initLista2Cliente();
        lista2 = clientesArchivoCargarLista();
        mostrarlistaClientesLista2(lista2);
        fflush(stdin);
        esperarTecla();
        menuCliente();


        break;
    case 3:

        system("cls");
        printf("\n\n    Ingresar el cliente que queres modificar: \n\n  Ingresar opcion:  ");
        scanf("%i", &DNI);
        if(verificarUsuario(DNI)==1){

            modificarCliente(DNI);
            printf("\n\n    Modificado con exito");
            ///sleep(3);
        }else{
        system("cls");
        printf("\n\n    El DNI no existe");
        ///sleep(3);

        }

        menuCliente();

        break;
    case 4:
        /// verificar que no tenga un auto en alquiler

        system("cls");
        printf("\n\nEliminar cliente: \n\n      Ingresar el DNI q quieres eliminar\n\n      Ingresar opcion:");
        scanf("%i", &DNI);
        if(verificarUsuario(DNI)== 1){
            nodo2Clientes * lista2 = initLista2Cliente();
            lista2 = clientesArchivoCargarLista();
            mostrarlistaClientesLista2(lista2);
            esperarTecla();

            lista2 = eliminarNodoLista2Clientes(lista2, DNI);
            cargarListaDeClientes2EnArchivo(lista2);
            printf("---------------------------\n\n-------------------");
            mostrarlistaClientesLista2(lista2);
            esperarTecla();
        }
        menuCliente();
        break;
    case 5:
        /// falta funcion
        break;
    case 6:
        /// falta funcion
        menu();
        break;

    default:
        menuCliente();
        break;





    }



}

void menuAlquiler()
{

    system("cls");
    int opcion;
    printf("\n\n    1)Promos alquiler\n    2)Alquiler de autos\n    3)Devolver auto\n   4)Mostrar lista de autos disponibles\n   5)buscar auto\n6   )Calcular tarifa\n\n   ingresar opcion:");
    scanf("%i", &opcion);


}


void esperarTecla()
{
    printf("\n\nPresiona una tecla para continuar...");
    getchar();
}

