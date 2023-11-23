#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "filas.h"


void inicFila(Fila* fila)
{

    fila->primero = inicLista();
    fila->ultimo = inicLista();

}


void agregarFila(Fila* fila, int dato)
{


    nodo2*nuevoNodo = crearNodo2(dato);
    fila->ultimo = agregarAlFinalNodo2ParaFila(fila->ultimo, nuevoNodo);

    if(fila->primero == NULL)
    {

        fila->primero = fila->ultimo;

    }

    fila->ultimo = nuevoNodo;


}

int extrarDeFila(Fila * fila)
{

    int rta;

    if(fila->primero!=NULL)
    {


        rta = verPrimero(fila->primero);
        fila->primero = borrarPrimero(fila->primero);


        if(fila->primero == NULL)
        {

            fila->ultimo = initLista();

        }

    }

    return  rta;


}

int verPrimero(nodo2* lista)
{

    int rta = 0;
    if(lista!=NULL)
    {

        rta = lista->dato;
    }
    return rta;

}

void mostrarFila(Fila * fila)
{

    mostrarLista2(fila->primero);

}

/// listas

nodo2 * borrarPrimero(nodo2* primero)
{

    nodo2* aBorrar = primero;
    if(primero!=NULL)
    {

        primero = primero->ste;
        if(primero!=NULL)
        {

            primero->ante = NULL;
            free(aBorrar);

        }
        return primero;

    }


}

nodo2 * initLista()
{

    return NULL;

}

nodo2* crearNodo2(int dato)
{

    nodo2* nuevoNodo = (nodo2*)malloc(sizeof(nodo2));
    nuevoNodo->dato=dato;
    nuevoNodo->ste = NULL;
    nuevoNodo->ante = NULL;

    return nuevoNodo;


}

nodo2 * agregarAlFinalNodo2ParaFila(nodo2* ultimo, nodo2 *   nuevoNodo)
{

    if(ultimo == NULL)
    {

        ultimo = nuevoNodo;

    }
    else
    {

        ultimo->ste = nuevoNodo;
        nuevoNodo->ante = ultimo;

    }

    return ultimo;

}

void mostrarLista2(nodo2* lista)
{

    nodo2* lista2 = lista;

    while(lista2 != NULL)
    {

        printf(" %i -", lista->dato);
        lista2 = lista2->ste;

    }


}

nodo2* buscaUltimoR(nodo2* lista)
{

    nodo2* rta;
    if (lista == NULL || lista->ste == NULL)
    {
        // Si la lista está vacía o el nodo actual es el último
        rta = lista;
    }
    else
    {

        rta = buscaUltimoR(lista->ste);

    }

    // Llamar recursivamente para el siguiente nodo
    return rta;
}



