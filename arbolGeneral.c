#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define CLIENTE_ARCHIVO "archivoClientes.bin" // const nombre del archivo


#include "Autos.h"
#include "arbolGeneral.h"

nodoArbol* initArbol()
{
    return NULL;
}

nodoArbol* crearNodoArbolCliente(stClientes cliente)
{
    nodoArbol* nuevoNodoArbol = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevoNodoArbol->clientes = cliente;
    nuevoNodoArbol->izquierda = NULL;
    nuevoNodoArbol->derecha = NULL;

    return nuevoNodoArbol;
}

nodoArbol* insertarEnArbolNodoCliente(nodoArbol* arbol, nodoArbol* nodoCliente)
{
    if(arbol == NULL)
    {
        arbol = nodoCliente;
    }
    else
    {
        if(nodoCliente->clientes.DNI > arbol->clientes.DNI) /// ordenacion por DNI
        {
            arbol->derecha = insertarEnArbolNodoCliente(arbol->derecha, nodoCliente);
        }
        else
        {
            arbol->izquierda = insertarEnArbolNodoCliente(arbol->izquierda, nodoCliente);
        }
    }
    return arbol;
}


void mostrarArbolInOrden(nodoArbol* nodoCliente)/// inorden
{
    if(nodoCliente != NULL)
    {

        mostrarArbolInOrden(nodoCliente->izquierda);
        mostrarCliente(nodoCliente->clientes);
        mostrarArbolInOrden(nodoCliente->derecha);
    }
}

nodoArbol* busquedaDeClienteEnArbol(nodoArbol* arbol, int DNI){


nodoArbol * rta = NULL;
if(arbol->clientes.DNI == DNI){
    rta = arbol;

}else{

if(DNI>arbol->clientes.DNI){

    rta = busquedaDeClienteEnArbol(arbol->derecha, DNI);

}else{

    rta = busquedaDeClienteEnArbol(arbol->izquierda, DNI);

}

}

return rta;

}


nodoArbol * descargaDeClientesDeArchivoEnArbol() /// descargar los datos del archivo(los clientes) y agregar en el arbol
{

    nodoArbol* nodo = initArbol();
    nodoArbol* nodoCliene;

    FILE* archivo = fopen(CLIENTE_ARCHIVO, "rb");
    stClientes cliente;

    if(archivo != NULL)
    {
        while(fread(&cliente, sizeof(stClientes), 1, archivo)>0)
        {
            nodoCliene = crearNodoArbolCliente(cliente);
            nodo = insertarEnArbolNodoCliente(nodo, nodoCliene);
        }
        fclose(archivo);
    }
    else
    {
        printf("no se pudo abrir el archivo");
    }

    return nodo;


}


void cargarArbolDeClientesEnArchivo(nodoArbol* arbol) {
    FILE* archivo = fopen(CLIENTE_ARCHIVO, "wb");

    if (archivo != NULL) {
        guardarArbolEnArchivoRecursivo(archivo, arbol);
        fclose(archivo);
    } else {
        printf("No se pudo abrir el archivo.\n");
    }
}


void guardarArbolEnArchivoRecursivo(FILE* archivo, nodoArbol* actual) { /// guardan en el archivo de forma recursiva
    if (actual != NULL) {
        fwrite(&(actual->clientes), sizeof(stClientes), 1, archivo);


        guardarArbolEnArchivoRecursivo(archivo, actual->izquierda);
        guardarArbolEnArchivoRecursivo(archivo, actual->derecha);
    }
}



/// ---------------

// Función para encontrar el nodo con el valor mínimo en un árbol
nodoArbol* encontrarMinimo(nodoArbol* nodo) {
    while (nodo->izquierda != NULL) {
        nodo = nodo->izquierda;
    }
    return nodo;
}

// Función para eliminar un nodo de un árbol
nodoArbol* eliminarNodoarbol(nodoArbol* raiz, int dniCliente) {
    if (raiz == NULL) {
        return raiz;
    }

    // Buscar el nodo que contiene el cliente a eliminar
    if (dniCliente < raiz->clientes.DNI) {
        raiz->izquierda = eliminarNodoarbol(raiz->izquierda, dniCliente);
    } else if (dniCliente > raiz->clientes.DNI) {
        raiz->derecha = eliminarNodoarbol(raiz->derecha, dniCliente);
    } else {
        // Nodo con un solo hijo o sin hijos
        if (raiz->izquierda == NULL) {
            nodoArbol* temp = raiz->derecha;
            free(raiz);
            return temp;
        } else if (raiz->derecha == NULL) {
            nodoArbol* temp = raiz->izquierda;
            free(raiz);
            return temp;
        }

        // Nodo con dos hijos, encontrar el sucesor inorden (mínimo en el subárbol derecho)
        nodoArbol* temp = encontrarMinimo(raiz->derecha);

        // Copiar el contenido del sucesor inorden al nodo actual
        raiz->clientes = temp->clientes;

        // Eliminar el sucesor inorden
        raiz->derecha = eliminarNodoarbol(raiz->derecha, temp->clientes.DNI);
    }

    return raiz;
}


