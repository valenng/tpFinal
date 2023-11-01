#ifndef ARBOLGENERAL_H_INCLUDED
#define ARBOLGENERAL_H_INCLUDED

#include "Autos.h"
#include "Clientes.h"
#include "menu.h"

typedef struct
{
    stAuto automovil;
    struct nodoArbol * izq;
    struct nodoArbol * dere;
} nodoArbol;


#endif // ARBOLGENERAL_H_INCLUDED
