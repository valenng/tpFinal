#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Prots-LISTAS-autos.h"
#include "Autos.h"

///1) INCILISTA
///2) CREAR NODO
///3) AGREGAR AL PRINCIPIO
///4) AGREGAR EN ORDEN
///5) MOSTRAR LISTA
///6) ELIMINAR NODO

nodo* inicLista()
{
    return NULL;
}

nodo* crearNodo(stAuto dato)
{
    nodo* nuevoNodo = (nodo*) malloc(sizeof(nodo)) ;
    nuevoNodo->autito = dato;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

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

nodo* agregarAlFinal(nodo* lista, nodo* nuevoNodo)
{
    if(lista == NULL)
    {
        lista = agregarAlPrincipio(lista, nuevoNodo) ;
    }
    else
    {
        nodo* seguidora = lista;
        while(seguidora->siguiente != NULL)
        {
            seguidora = seguidora->siguiente ;
        }
        seguidora->siguiente = nuevoNodo ;
    }
    return lista;
}
/*
nodo* agregarEnOrden(nodo* lista, nodo* nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(nuevoNodo->persona.edad < lista->persona.edad)
        {
            lista = agregarAlPrincipio(lista, nuevoNodo);
        }
        else
        {
            nodo* anterior = lista;
            nodo* seguidora = lista->siguiente;
            while((seguidora != NULL) && (nuevoNodo->persona.edad > seguidora->persona.edad))
            {
                anterior = seguidora;
                seguidora = seguidora->siguiente ;
            }
            anterior->siguiente = nuevoNodo;
            nuevoNodo->siguiente = seguidora ; ///SEGUIDORA = NULL
        }
    return lista;
}

void escribir(nodo* seguidora)
{
    printf("\n-------------------------------------") ;
    printf("\n|NOMBRE|: %s", seguidora->persona.nombre) ;
    printf("\n|EDAD|: %i", seguidora->persona.edad) ;
    printf("\n-------------------------------------\n") ;
}

void recorrerYMostrar(nodo* lista)
{
    nodo* seguidora = lista;
    while(seguidora != NULL)
    {
        escribir(seguidora) ;
        seguidora = seguidora->siguiente ;
    }
}
*/
nodo* eliminarNodo(nodo* lista, char matricula[])
{
    nodo* aux;
    nodo* anterior ;
    if((lista != NULL) && (strcmpi(matricula, lista->autito.matricula) == 0))
    {
        aux = lista;
        lista = lista->siguiente ;
        free(aux) ;
    }
    else
    {
        aux = lista ;
        while((aux != NULL) && (strcmpi(matricula, aux->autito.matricula) != 0))
        {
            anterior = aux ;
            aux = aux->siguiente ;
        }
        if(aux != NULL)
        {
            anterior->siguiente = aux->siguiente;
            free(aux) ;
        }
    }
    return lista;
}




