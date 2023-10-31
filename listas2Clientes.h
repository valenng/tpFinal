#ifndef LISTAS2CLIENTES_H_INCLUDED
#define LISTAS2CLIENTES_H_INCLUDED
#include "Clientes.h"

typedef struct
{

    stClientes cliente;

    struct nodo2Clientes * siguiente;
    struct nodo2Clientes * anterior;

} nodo2Clientes;

#endif // LISTAS2CLIENTES_H_INCLUDED
