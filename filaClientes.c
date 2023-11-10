#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "filaClientes.h"
#include "listas2Clientes.h"
#include "Clientes.h"

// init fila

void initFila(filaClienteCompra* fila)
{

    fila->inicio = inicLista();
    fila->fin = inicLista();

}

// mostrar fila

void mostrarFila(filaClienteCompra* fila)
{


    printf("\nINICIO ->  \n ");
    mostrarlistaClientesLista2(fila->inicio);
    printf("\n<-Fin");


}

// agregar a la fila
/*
void agregarALaFilaDeCliente(filaClienteCompra* fila, stClientes cliente)
{

    nodo2Clientes * nuevo = crearNodo2Cliente(cliente);

    fila->fin=agregarALaFilaDeCliente(fila->fin, nuevo);

    if(fila->inicio==NULL)
    {
        fila->inicio=fila->fin;
    }
    fila->fin=nuevo;
}



stClientes extraeDeLfILA(filaClienteCompra* fila){

stClientes resp;

if(fila->inicio != NULL){

    resp = verPrimeroDeLista2(fila->inicio);

    fila->inicio = borrarPrimeroNodoClienteLista2(fila->inicio);
    if(fila->inicio==NULL)
            fila->fin=inicLista();
    }
    return resp;

}


*/






