#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define CLIENTE_ARCHIVO "archivoClientes.bin"
#include "listas2Clientes.h"

nodo2Clientes * initLista2Cliente()
{

    return NULL;

}

nodo2Clientes * crearNodo2Cliente(stClientes cliente)
{

    nodo2Clientes* nuevoCliente = (nodo2Clientes * )malloc(sizeof(nodo2Clientes));
    nuevoCliente->cliente = cliente;
    nuevoCliente->anterior = NULL;
    nuevoCliente->siguiente = NULL;

    return nuevoCliente;

}

nodo2Clientes* buscarDNIlista2Cliente(nodo2Clientes* lista, int DNI) /// funcion que verifica si existe un DNI en la lista
{
    nodo2Clientes* actual = lista;
    nodo2Clientes* nodoEncontrado = NULL; /// si no se encontro devuelve un NULL

    while (actual != NULL)
    {
        if (actual->cliente.DNI == DNI)
        {
            nodoEncontrado = actual;

        }
        actual = actual->siguiente;
    }

    return nodoEncontrado;
}

nodo2Clientes* agregarNodo2EnLaLista2(nodo2Clientes* lista, nodo2Clientes* nuevoNodo)
{

    if(lista == NULL)
    {

        lista = nuevoNodo;

    }
    else
    {

        nuevoNodo->siguiente = lista;
        lista->anterior = nuevoNodo;
        lista = nuevoNodo;

    }

    return lista;


}

nodo2Clientes* eliminarNodoLista2Clientes(nodo2Clientes* lista, int DNI) {
    nodo2Clientes* actual = lista;
    nodo2Clientes* anterior = NULL;

    // Buscar el nodo con el DNI a eliminar
    while (actual != NULL && actual->cliente.DNI != DNI) {
        anterior = actual;
        actual = actual->siguiente;
    }

    // Si el nodo con el DNI es encontrado
    if (actual != NULL) {
        // Si el nodo a eliminar es el primer nodo de la lista
        if (anterior == NULL) {
            lista = actual->siguiente;
        } else {
            anterior->siguiente = actual->siguiente;
        }

        // Liberar la memoria del nodo a eliminar
        free(actual);
        printf("DNI %d eliminado.\n", DNI);
        esperarTecla();
    }

    return lista; // Devolver la lista modificada
}

nodo2Clientes * clientesArchivoCargarLista()
{

    nodo2Clientes* lista2 = initLista2Cliente();
    nodo2Clientes* nodoCliente;
    FILE* archivo = fopen(CLIENTE_ARCHIVO, "rb");
    stClientes cliente;

    if(archivo != NULL)
    {

        while(fread(&cliente, sizeof(stClientes), 1, archivo)>0)
        {

            nodoCliente = crearNodo2Cliente(cliente);
            lista2 = agregarNodo2EnLaLista2(lista2, nodoCliente);


        }
        fclose(archivo);

    }
    else
    {

        printf("no se pudo abrir el archivo");

    }

    return lista2;


}


void cargarListaDeClientes2EnArchivo(nodo2Clientes* lista)
{

    FILE* archivo = fopen(CLIENTE_ARCHIVO, "wb");


    nodo2Clientes * actual = lista;

    if(archivo != NULL)
    {



        while(actual != NULL)
        {

            fwrite(&(actual->cliente), sizeof(stClientes), 1, archivo);
            actual = actual->siguiente;

        }

        fclose(archivo);
    }
    else
    {

        printf("no se pudo abrir el archivo");

    }
}


void mostrarlistaClientesLista2(nodo2Clientes* listaClientes){

nodo2Clientes * listaActual = listaClientes;

    while(listaActual!=NULL){

        mostrarCliente(listaActual->cliente);
        listaActual = listaActual->siguiente;

    }

}


nodo2Clientes * agregarAlFinalLista2(nodo2Clientes * lista, nodo2Clientes * nuevoNodo)
{
    /*
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        nodo2Clientes * ultimo = buscarUltimoR(lista);
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;

    }
    */
    return lista;
}


stClientes * verPrimeroDeLista2 (nodo2Clientes * lista)
{
/*
    stClientes * rta;

    if(lista!=NULL){
       rta=lista->cliente;


    }
    return rta;
*/
}

nodo2Clientes * borrarPrimeroNodoClienteLista2 (nodo2Clientes * lista)
{
    /*
    nodo2Clientes * aux = lista;;
    if (lista)
    {
        lista=lista->ste;
        if(lista)
            lista->ante=NULL;
        free(aux);
    }
    return lista;
    */
}

