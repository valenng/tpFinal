#ifndef ARBOLGENERAL_H_INCLUDED
#define ARBOLGENERAL_H_INCLUDED

#include "Autos.h"
#include "Clientes.h"
#include "menu.h"

typedef struct
{
    stAuto autito;
    struct nodoArbol* izquierda;
    struct nodoArbol* derecha;
} nodoArbol;

nodoArbol* inicArbol() ;
nodoArbol* insertarEnArbol(nodoArbol* arbolAutos, stAuto);

#endif // ARBOLGENERAL_H_INCLUDED
