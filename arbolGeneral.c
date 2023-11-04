#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "Autos.h"
#include "arbolGeneral.h"

nodoArbol* inicArbol()
{
    return NULL;
}

nodoArbol* crearNodoArbol(stAuto dato)
{
    nodoArbol* nuevoNodoArbol = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevoNodoArbol->autito = dato;
    nuevoNodoArbol->izquierda = NULL;
    nuevoNodoArbol->derecha = NULL;

    return nuevoNodoArbol;
}

nodoArbol* insertarEnArbolAutos(nodoArbol* arbolAutos, stAuto autito)
{
    if(arbolAutos == NULL)
    {
        arbolAutos = crearNodoArbol(autito);
    }
    else
    {
        if(autito.marcasDeAuto > arbolAutos->autito.marcasDeAuto) ///marcasDeAuto es de tipo int, por lo que más fácil de acomodar en un árbol
        {
            arbolAutos->derecha = insertarEnArbolAutos(arbolAutos->derecha, autito);
        }
        else
        {
            arbolAutos->izquierda = insertarEnArbolAutos(arbolAutos->izquierda, autito);
        }
    }
    return arbolAutos;
}


void mostrarArbolPreOrden(nodoArbol* arbolAutos) ///RAÍZ, IZQ, DER.
{
    if(arbolAutos != NULL)
    {
        printf("%d", arbolAutos->autito);
        mostrarArbolPreOrden(arbolAutos->izquierda);
        mostrarArbolPreOrden(arbolAutos->derecha);
    }
}

/*
nodoArbol* busquedaArbolGeneral(nodoArbol* arbol, char buscarMaticula)
{

    nodoArbol* rta = NULL;

    if(arbol!=NULL)
    {

        if(buscarMaticula==arbol->automovil.matricula)
        {

            rta = arbol;

        }
        else
        {

            if(buscarMaticula == arbol->automovil.matricula)
            {

                rta = busquedaArbolGeneral(arbol->dere, buscarMaticula);

            }
            else
            {

                rta = busquedaArbolGeneral(arbol->izq, buscarMaticula);

            }
        }
    }

    return rta;

}
*/
