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

    printf("\n\t�BIENVENIDO! ") ;
    printf("\n\n- Nos alegra que nos hayas elegido para tu pr�ximo alquiler de auto! A continuaci�n ingresar�s al men� para comenzar..\n\n") ;

    system("pause") ;
    system("cls") ;

    printf("\n\t\t|ALQUILER DE AUTOS|");
    printf("\n\t\t*******************");

    printf("\n\n\t[ 1 ] USUARIO ");
    printf("\n\t[ 2 ] ADMINISTRACION");
    printf("\n\n|OPCI�N ELEGIDA|: ") ;
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
    printf("\n\t\t|USUARIO|") ;
    printf("\n\t\t---------");

    printf("\n\t[ 1 ] Iniciar sesi�n..") ;
    printf("\n\t[ 2 ] Nuevo usuario..") ;
    printf("\n\t[ 3 ] Volver..") ;

    printf("\n\n|OPCI�N ELEGIDA|: ") ;
    scanf("%i", &opcion);

    switch(opcion)
    {

    case 1:
        system("cls");
        int dni;
        printf("\n\t\t|INICIAR SESI�N|") ;
        printf("\n\t\t----------------");
        printf("\n- Ingrese su DNI: ") ;
        scanf("%i", &dni);

        /// verificar usuario
        nodoArbol* arbol = descargaDeClientesDeArchivoEnArbol();
        ///mostrarArbolInOrden(arbol);
        nodoCliente = busquedaDeClienteEnArbol(arbol, dni);

        if(nodoCliente != NULL)
        {
            system("cls");
            printf("\n- Se inici� sesi�n correctamente.\n");
            usuarioSesionIniciada(dni);
        }
        else
        {
            printf("\n\t # El usuario ingresado NO existe. Debe crear una cuenta nueva.. \n\n");
            system("pause") ;
            system("cls");
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
    while(opcion != 5)
    {
        system("cls");
        printf("\n\t\t|MEN� DE ALQUILER DE AUTOS|") ;
        printf("\n\t\t---------------------------\n") ;

        printf("\n[ 1 ] Ver cat�logo de autos disponibles..") ;
        printf("\n[ 2 ] Alquilar un auto..") ;
        printf("\n[ 3 ] Devolver un auto alquilado..") ;
        printf("\n[ 4 ] Informaci�n personal..") ;
        printf("\n[ 5 ] Cerrar sesi�n..") ;

        printf("\n\n|OPCI�N ELEGIDA|: ") ;
        scanf("%i", &opcion);

        switch (opcion)
        {
            case 1:
                funcMenuMostrarDisponibles() ;
                printf("\n") ;
                system("pause") ;
                system("cls") ;
            break;
            case 2:
                printf("\n\t\t|AUTOS DISPONIBLES PARA ALQUILAR|") ;
                funcMenuMostrarDisponibles() ;
                alquilarUnAuto(DNI) ;
                printf("\n") ;
                system("pause") ;
                system("cls") ;
            break;
            case 3:
                devolverAuto() ;
                printf("\n") ;
                system("pause") ;
                system("cls") ;
            break;
            case 4:
                system("cls");
                printf("\n\t|INFORMACI�N PERSONAL|") ;
                printf("\n\t---------------------") ;
                mostrarInformacionDelCliente(DNI);
                fflush(stdin);
                esperarTecla();
                usuarioSesionIniciada(DNI);
            break;
            case 5:
                printf("\n\t\t�Sesi�n cerrada! Hasta luego.. ");
                printf("\n") ;
                system("pause") ;
                system("cls") ;
                ///sleep(3);
                menu();
            break;
            default:

            break;
        }

    }
}

void administracion()
{
    int opcion;
    system("cls");
    printf("\n\t|MEN� DE ALQUILER DE AUTOS|") ;
    printf("\n\t---------------------------\n") ;
    printf("\n - Elija a qu� men� desea ingresar..\n") ;

    printf("\n\t[ 1 ] Men� autos..") ;
    printf("\n\t[ 2 ] Men� clientes..") ;
    printf("\n\t[ 3 ] Volver al men� anterior..") ;

    printf("\n\n|OPCI�N ELEGIDA|: ") ;
    scanf("%i", &opcion);

    switch(opcion)
    {

        case 1:
            menuAutos();
            printf("\n") ;
            system("pause") ;
            system("cls") ;
        break;
        case 2:
            menuCliente();
            printf("\n") ;
            system("pause") ;
            system("cls") ;
        break;

        case 3:
            menu();
            printf("\n") ;
            system("pause") ;
            system("cls") ;
        break;

        default:
            administracion();
            printf("\n") ;
            system("pause") ;
            system("cls") ;
        break;
    }
    system("cls");
}

void menuAutos()
{
    system("cls");
    int opcion;

    while(opcion != 6)
    {
        printf("\n\t\t|MEN� AUTOS|") ;
        printf("\n\t\t------------\n") ;
        printf("\n- Ingrese qu� desea realizar..\n") ;

        printf("\n\t[ 1 ] Agregar autos..") ;
        printf("\n\t[ 2 ] Autos disponibles..") ;
        printf("\n\t[ 3 ] Calcular tarifa (por matr�cula)..") ;
        printf("\n\t[ 4 ] Dar de baja un auto..") ;
        printf("\n\t[ 5 ] Mostrar listado de autos..") ;
        printf("\n\t[ 6 ] Volver..") ;

        printf("\n\n|OPCI�N ELEGIDA|: ") ;
        scanf("%i", &opcion);

        system("cls") ;
        switch(opcion)
        {
        case 1: ///AGREGAR AUTOS
            funcMenuCargaAutos();
            printf("\n") ;
            system("pause") ;
            system("cls") ;
            break;

        case 2: ///AUTOS DISPONIBLES
            funcMenuMostrarDisponibles() ;
            printf("\n") ;
            system("pause") ;
            system("cls") ;
            break;

        case 3: ///B�SQUEDA DE UN AUTO
            ingresarMatriculaYCalcularTarifa() ;
            printf("\n") ;
            system("pause") ;
            system("cls") ;
            break;

        case 4: ///MODIFICAR ESTADO
            modificarEstado() ;
            printf("\n") ;
            system("pause") ;
            system("cls") ;
            break;

        case 5: ///LISTA DE AUTOS
            funcMenuMostrarListadoGeneral() ;
            printf("\n") ;
            system("pause") ;
            system("cls") ;
            break;

        case 6:
            administracion() ;
            break;
        }
    }

}


void menuCliente()
{
    nodoArbol* arbol = descargaDeClientesDeArchivoEnArbol();
    system("cls");
    int opcion, DNI;
    int limite;
    char salida = 's';

    printf("\n\t|MEN� CLIENTES|") ;
    printf("\n\t---------------\n") ;
    printf("\n- Ingrese qu� desea realizar..\n") ;

    printf("\n\t[ 1 ] Informaci�n cliente..") ;
    printf("\n\t[ 2 ] Lista de clientes..") ;
    printf("\n\t[ 3 ] Modificar un cliente..") ;
    printf("\n\t[ 4 ] Eliminar un cliente..") ;
    printf("\n\t[ 5 ] Eliminar m�s de un cliente..") ;
    printf("\n\t[ 6 ] Volver..") ;

    printf("\n\n|OPCI�N ELEGIDA|: ") ;
    scanf("%i", &opcion);

    switch(opcion)
    {

    case 1:

        system("cls");
        printf("\n - Ingresa el DNI buscado: ");
        scanf("%i", &DNI);
        fflush(stdin);
        if(busquedaDeClienteEnArbol(arbol, DNI)== NULL)
        {
            mostrarInformacionDelCliente(DNI);
            system("pause") ;
        }
        else
        {
            system("cls");
            printf("\n\n\t- El DNI NO existe..");
        }
        menuCliente();
        break;

    case 2:
        mostrarArbolInOrden(arbol);
        fflush(stdin);
        printf("\n") ;
        system("pause") ;
        system("cls");
        menuCliente();
        break;

    case 3:
        system("cls");
        printf("\n - Ingresa el DNI del cliente que queres modificar: ");
        scanf("%i", &DNI);
        if(busquedaDeClienteEnArbol(arbol, DNI) != NULL)
        {

            arbol = modificarCliente(DNI, arbol);
            printf("\n\t\t # Modificado con �xito..\n");
            cargarArbolDeClientesEnArchivo(arbol);
        }
        else
        {
            system("cls");
            printf("\n\t\t # El DNI no existe..\n");
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


void esperarTecla()
{
    printf("\n\nPresiona una tecla para continuar...");
    getchar();
}

