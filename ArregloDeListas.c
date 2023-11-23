#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "ArregloDeListas.h"
#define CANT_MAX_AUTO 5

int cargarArregloDeListasAutos(stAutosXMarca arrDeListas[], int validos, int dimension)
{
        system("cls") ;
        printf("\n- Hola! Para ingresar un nuevo auto primero debemos saber su marca para poder ubicarlo..\n") ;

        int marcaDeAuto = elegirMarca() ;

        printf("\n|MARCADEAUTO|: %i", marcaDeAuto) ;

        system("cls") ;

        nodo* listaAutos = cargaGeneralAuto(marcaDeAuto) ;

        validos = alta(arrDeListas, listaAutos, marcaDeAuto, validos) ;
    return validos ;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

int alta(stAutosXMarca arrDeListas[], nodo* listaAutosYaCreada, int marcaDeAuto, int validos)
{
    int posicion = buscarPosMarca(arrDeListas, marcaDeAuto, validos) ;
    ///printf("\nPosición inicial: %d", posicion);
    if(posicion == -1)
    {
        //printf("\n- Marca NO encontrada. Agregando nueva marca..\n");
        arrDeListas[validos].marcaDeAuto = marcaDeAuto ;
        arrDeListas[validos].listaAutos = inicLista() ;
        validos++;
        posicion = validos - 1;
    }
    ///printf("\nPosición final: %d", posicion);
    arrDeListas[posicion].listaAutos = agregarAlPrincipio(arrDeListas[posicion].listaAutos, listaAutosYaCreada) ;

    return validos;
}

int buscarPosMarca(stAutosXMarca arrDeListas[], int marcaDeAuto, int validos)
{
    int posicion = -1;
    int i=0;
    while((i<validos) && (posicion == -1))
    {
        if(arrDeListas[i].marcaDeAuto == marcaDeAuto)
        {
            posicion = i ;
        }
        i++;
    }
    return posicion ;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

void mostrarArregloDeListas(stAutosXMarca arrDeListas[], int validos)
{
    printf("\n|VAL|: %i", validos) ;
    for(int i=0; i<validos; i++)
    {
        mostrarLista(arrDeListas[i].listaAutos) ;
    }
}

///IMPORTANTE
void funcMenuCargaAutos()
{
    int validos = 0;
    int dimension = 5 ;
    stAutosXMarca arrDeListas[dimension] ;

    validos = cargarArregloDeListasAutos(arrDeListas, validos, dimension) ;
}

void funcMenuMostrarListadoGeneral()
{
    stAuto autito ;
    FILE *archivo = fopen(ARCHIVO_AUTO, "rb") ;
    if(archivo != NULL)
    {
        while(fread(&autito, sizeof(stAuto),1,archivo) > 0)
        {
            mostrarUnAuto(autito) ;
        }
        fclose(archivo) ;
    }
}

void funcMenuMostrarDisponibles()
{
    stAuto autito ;
    FILE *archivo = fopen(ARCHIVO_AUTO, "rb") ;
    if(archivo != NULL)
    {
        while(fread(&autito, sizeof(stAuto),1,archivo) > 0)
        {
            if(autito.disponibilidad == 1)
            {
                mostrarUnAuto(autito) ;
            }
        }
        fclose(archivo) ;
    }
}



//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

void pasarArregloAArchivo(stAutosXMarca arrDeListas[], int validos)
{
    FILE* archivo = fopen(ARCHIVO_ARREGLO_AUTOS, "wb");

    if(archivo != NULL)
    {
        fwrite(&validos, sizeof(int), 1, archivo);
        for(int i=0; i<validos; i++)
        {
            printf("\nVALOR de i: %i", i) ;
            fwrite(&(arrDeListas[i].marcaDeAuto), sizeof(int), 1, archivo);
            nodo* seguidora = arrDeListas[i].listaAutos;
            while(seguidora != NULL)
            {
                fwrite(&(seguidora->autito), sizeof(stAuto), 1, archivo);
                seguidora = seguidora->siguiente;
            }
        }
        fclose(archivo);
    }
}

