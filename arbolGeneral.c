#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Clientes.h"
#include "menu.h"
#include "arbolGeneral.h"

nodoArbol* inicArbol()
{
    return NULL;
}

nodoArbol* crearNodoArbol(stAuto autoNuevo)
{
    nodoArbol* nuevoNodoArbol = (nodoArbol*) malloc (sizeof(nodoArbol));
    nuevoNodoArbol->autito = autoNuevo;
    nuevoNodoArbol->izquierda = NULL;
    nuevoNodoArbol->derecha = NULL;

    return nuevoNodoArbol;
}

nodoArbol* insertarEnArbol(nodoArbol* arbolAutos, stAuto autito)
{
    if(arbolAutos == NULL)
    {
        arbolAutos = crearNodoArbol(autito) ;
    }
    else
    {
        if(autito.marcasDeAuto > arbolAutos->autito.marcasDeAuto)
        {
            arbolAutos->derecha = insertarEnArbol(arbolAutos->derecha, autito.marcasDeAuto) ;
        }
        else
        {
            arbolAutos->izquierda = insertarEnArbol(arbolAutos->izquierda, autito.marcasDeAuto) ;
        }
    }
    return arbolAutos ;
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


nodoArbol * insertarEnArbolGeneral(nodoArbol* arbolGeneral, stAuto automovil){

if(arbolGeneral != NULL){

    arbolGeneral = crearNodoArbol(automovil);

}else{

    if(automovil.matricula > arbolGeneral->automovil.matricula){

        arbolGeneral->dere = insertarEnArbolGeneral(arbolGeneral->dere, automovil);

    }else{

        arbolGeneral->izq = insertarEnArbolGeneral(arbolGeneral->izq, automovil);


    }

}

return arbolGeneral;


}


void mostrarArbolPreorden(nodoArbol* arbol)
{
    if(arbol != NULL){

        printf("%d", arbol->automovil);
        mostrarArbolPreorden(arbol->izq);
        mostrarArbolPreorden(arbol->izq);

    }

}

*/
