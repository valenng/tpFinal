#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "listas2Clientes.h"

nodo2Clientes * initLista2Cliente()
{

    return NULL;

}

nodo2Clientes * crearNodo2Cliente(stClientes cliente)
{

    nodo2Clientes nuevoCliente = (nodo2Clientes * )malloc(sizeof(nodo2Clientes));
    nuevoCliente->cliente = cliente;
    nuevoCliente->anterior = NULL;
    nuevoCliente->siguiente = NULL;

    return nuevoCliente;

}

nodo2Clientes* buscarDNIlista2Cliente(nodo2Clientes* lista, int DNI)
{
    nodo2Clientes* actual = lista;
    nodo2Clientes* nodoEncontrado = NULL;

    while (actual != NULL)
    {
        if (actual->dni == DNI)
        {
            nodoEncontrado = actual;
        }
        actual = actual->siguiente;
    }

    return nodoEncontrado;
}

