#ifndef ARBOLGENERAL_H_INCLUDED
#define ARBOLGENERAL_H_INCLUDED

#include "Autos.h"
#include "Clientes.h"
#include "menu.h"

typedef struct
{
    stClientes clientes;
    struct nodoArbol* izquierda;
    struct nodoArbol* derecha;
} nodoArbol;


#endif // ARBOLGENERAL_H_INCLUDED
