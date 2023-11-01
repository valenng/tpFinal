#include <stdlib.h>
#include <string.h>
#include <locale.h>

<<<<<<< HEAD
#include "Clientes.h"
#include "menu.h"
#include "arbolGeneral.h"

=======
#include "arbolGeneral.h"
>>>>>>> aad0f982f16ad157d2c45ce42446145a8c3c2604

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
<<<<<<< HEAD

=======
>>>>>>> aad0f982f16ad157d2c45ce42446145a8c3c2604
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

