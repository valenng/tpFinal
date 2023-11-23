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
*/
void mostrarInformacionAutoLista(nodo* nodo)
{
    stAuto autoInfo = nodo->autito;
    printf("Marcas de Auto: %d\n", autoInfo.marcasDeAuto);
    printf("Modelo: %d\n", autoInfo.modelo);
    printf("Año: %d\n", autoInfo.anio);
    printf("Tipo de Combustible: %d\n", autoInfo.tipoDeCombustible);
    printf("Matrícula: %s\n", autoInfo.matricula);
    printf("Color: %d\n", autoInfo.color);
    printf("Capacidad: %d\n", autoInfo.capacidad);
    printf("Kilómetros Acumulados: %.2f\n", autoInfo.kilometrosAcumulados);
    printf("Valor Inicial: %.2f\n", autoInfo.valorInicial);
    printf("Disponibilidad: %s\n", (autoInfo.disponibilidad == 1) ? "DISPONIBLE" : "NO DISPONIBLE");
}

void recorrerYMostrarLista(nodo* lista)
{
    nodo* seguidora = lista;
    while(seguidora != NULL)
    {
        mostrarInformacionAutoLista(seguidora) ;
        seguidora = seguidora->siguiente ;
    }
}

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




