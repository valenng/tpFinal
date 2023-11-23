#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Prots-LISTAS-autos.h"

nodo* inicLista()
{
    return NULL;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

nodo* crearNodo(stAuto dato)
{
    nodo* nuevoNodo = (nodo*) malloc(sizeof(nodo)) ;
    nuevoNodo->autito = dato;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista ;
        lista = nuevoNodo;
    }
    return lista;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo)
{
    if(lista == NULL)
    {
        lista = agregarAlPrincipio(lista, nuevoNodo) ;
    }
    else
    {
        nodo* seguidora = lista;
        nodo* anterior;
        while(seguidora != NULL)
        {
            anterior = seguidora ;
            seguidora = seguidora->siguiente ;
        }
        nuevoNodo->siguiente = seguidora ;
        anterior->siguiente = nuevoNodo ;
    }
    return lista;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

nodo* pasarArchivoALista()
{
    nodo* listaAutos = inicLista() ;
    stAuto autito ;

    FILE *archivo = fopen(ARCHIVO_AUTO, "rb") ;
    if(archivo != NULL)
    {
        while(fread(&autito, sizeof(stAuto), 1, archivo) > 0)
        {
            nodo* nuevoNodo = crearNodo(autito) ;
            listaAutos = agregarAlFinal(listaAutos, nuevoNodo) ;
        }
        fclose(archivo) ;
    }
    return listaAutos ;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

nodo* cargaGeneralAuto(int marcaDeAuto) ///CARGO EL ARCHIVO Y LO PASO A LA LISTA
{
    cargarArchivoDeAutos(marcaDeAuto) ;
    nodo* listaAutos = pasarArchivoALista() ;
    return listaAutos ;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

void mostrarLista(nodo* listaAMostrar)
{
    while(listaAMostrar!=NULL)
    {
        mostrarUnAuto(listaAMostrar->autito);
        listaAMostrar = listaAMostrar->siguiente;
    }
}

void mostrarDisponibles(nodo* listaAMostrar)
{
    while(listaAMostrar != NULL)
    {
        if(listaAMostrar->autito.disponibilidad == 1)
        {
            mostrarUnAuto(listaAMostrar->autito);

        }
        listaAMostrar = listaAMostrar->siguiente;
    }
}

