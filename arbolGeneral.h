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
nodoArbol* crearNodoArbol(stAuto) ;
nodoArbol* insertarEnArbolAutos(nodoArbol*, stAuto) ;
void mostrarArbolPreOrden(nodoArbol*) ;

#endif // ARBOLGENERAL_H_INCLUDED
