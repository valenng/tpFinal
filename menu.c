#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Autos.h"
#include "Clientes.h"
#include "menu.h"
#include "listas2Clientes.h"
#include "arbolGeneral.h"
#include "filas.h"



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

    int opcion;
    nodoArbol * nodoCliente;
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
        nodoArbol* arbol = descargaDeClientesDeArchivoEnArbol();
        mostrarArbolInOrden(arbol);
        nodoCliente = busquedaDeClienteEnArbol(arbol, dni);


        if(nodoCliente != NULL)
        {

            system("cls");
            printf("\n\n        Inicio de sesion");
            sleep(3);
            usuarioSesionIniciada(dni);

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
        printf("2) Alquilar un auto\n");
        printf("3) Devolver un auto alquilado\n");
        printf("4) Información personal\n");
        printf("5) Cerrar sesion\n");
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
            system("cls");
            printf("\n\n        Información personal");
            mostrarInformacionDelCliente(DNI);
            fflush(stdin);
            esperarTecla();
            usuarioSesionIniciada(DNI);

            break;
        case 5:
            system("cls");
            printf("\n\n        Sesion cerrada. ¡Hasta luego!");
            sleep(3);
            menu();

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

    printf("\nMenu autos\n\n\n") ; ///

    printf("    1)Lista de autos\n    2)Busqueda De Auto\n    3)Autos disponibles\n    4)Agregar autos\n    5)Modificar auto\n    6)Eliminar auto\n    7)Volver al menu\n\n   ingresar opcion: ");
    scanf("%i", &opcion);

    switch(opcion)
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
        /// falta funcion

        break;
    case 7:

        menu();

        break;

    default:

        break;


    }



}

void menuCliente()
{
    nodoArbol* arbol = descargaDeClientesDeArchivoEnArbol();
    system("cls");
    int opcion, DNI;
    int limite;
    char salida = 's';
    printf("\n\n    1)Info cliente\n    2)Lista de clientes\n    3)Modificar cliente\n    4)Eliminiar cliente\n    5)Eliminar mas de un cliente\n    6)Volver\n\n    ingresar opcion:    ");
    scanf("%i", &opcion);

    switch(opcion)
    {

    case 1:

        system("cls");
        printf("\n\nIngresar el DNI buscado:  ");
        scanf("%i", &DNI);
        fflush(stdin);
        if(busquedaDeClienteEnArbol(arbol, DNI)== NULL)
        {

             mostrarInformacionDelCliente(DNI);
            esperarTecla();

        }
        else
        {
            system("cls");
            printf("\n\n    El DNI no existe");
            sleep(3);
        }

        menuCliente();


        break;
    case 2:
        system("cls");

        mostrarArbolInOrden(arbol);
        fflush(stdin);
        esperarTecla();
        menuCliente();


        break;
    case 3:

        system("cls");
        printf("\n\n    Ingresar el cliente que queres modificar: \n\n  Ingresar opcion:  ");
        scanf("%i", &DNI);
        if(busquedaDeClienteEnArbol(arbol, DNI) != NULL)
        {

            arbol = modificarCliente(DNI, arbol);
            printf("\n\n    Modificado con exito");
            cargarArbolDeClientesEnArchivo(arbol);
            sleep(3);
        }
        else
        {
            system("cls");
            printf("\n\n    El DNI no existe");
            sleep(3);

        }

        menuCliente();

        break;
    case 4:

        system("cls");
        printf("\n\nEliminar cliente: \n\n      Ingresar el DNI q quieres eliminar\n\n      Ingresar opcion:");
        scanf("%i", &DNI);
        nodoArbol* dato = busquedaDeClienteEnArbol(arbol, DNI);
        if(dato != NULL && dato->clientes.estadoDeAlquiler == 0)
        {

            arbol = eliminarNodoarbol(arbol, DNI);
            cargarArbolDeClientesEnArchivo(arbol);
            esperarTecla();


        }
        menuCliente();
        break;

    case 5:
        fflush(stdin);
        limite = 1;
        Fila nuevaFila;
        inicFila(&nuevaFila);
        while(salida=='s'){
             system("cls");
            limite++;
            printf("ingresar el DNI a eliminar:\n\n Ingresar DNI: ");
            scanf("%i", &DNI);
            nodoArbol* dato = busquedaDeClienteEnArbol(arbol, DNI);


            if(dato->clientes.estadoDeAlquiler == 0 && busquedaDeClienteEnArbol(arbol, DNI) != NULL){

                agregarFila(&nuevaFila, DNI);


            }else{

            printf("El usuario no se pude eliminar ya que en este momento tiene un auto alquilado O NO EXISTE\n");

            }
            printf("\n\nIngresar una s para carga otro DNI\n\n  Ingresar opcion: ");
            fflush(stdin);
            scanf("%s", &salida);
            fflush(stdin);

        }

        int aEliminar;
        for(int i = 0 ; i<limite ; i++){
            aEliminar = extrarDeFila(&nuevaFila);
            arbol = eliminarNodoarbol(arbol, aEliminar);

        }


            cargarArbolDeClientesEnArchivo(arbol);
        printf("\n\nClientes eliminados con exito");
        esperarTecla();
        administracion();



        break;

    case 6:
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
    printf("\n\n    1)Promos alquiler\n    2)Alquiler de autos\n    3)Devolver auto\n    4)Mostrar lista de autos disponibles\n    5)Buscar auto\n    6)Calcular tarifa    7)Volver al menu\n\n   ingresar opcion:");
    scanf("%i", &opcion);

    switch(opcion)
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

        /// falta funcion
    case 4:

        /// falta funcion
        break;
    case 5:


        break;
    case 6:

        /// falta funcion
        break;
    case 7:

        administracion();
        break;
    default:


        break;



    }


}


void esperarTecla()
{
    printf("\n\nPresiona una tecla para continuar...");
    getchar();
}

