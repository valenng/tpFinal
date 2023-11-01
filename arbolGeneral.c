#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "arbolGeneral.h"

nodoArbol * initNarbol()
{

    return NULL;

}


nodoArbol * crearNodoArbol(stAuto automovil)
{


    nodoArbol * nuevoNodoArbol = (nodoArbol *) malloc (sizeof(nodoArbol));

    nuevoNodoArbol->automovil = automovil;
    nuevoNodoArbol->izq = NULL;
    nuevoNodoArbol->dere = NULL;
    return nuevoNodoArbol;

}


nodoArbol * busquedaArbolGeneral(nodoArbol* arbol, char buscarMaticula)
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

