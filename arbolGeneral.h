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


nodoArbol* initArbol();
nodoArbol* crearNodoArbolCliente(stClientes cliente);
nodoArbol* insertarEnArbolNodoCliente(nodoArbol* arbol, nodoArbol* nodoCliente);
void mostrarArbolInOrden(nodoArbol* nodoCliente);
nodoArbol* busquedaDeClienteEnArbol(nodoArbol* arbol, int DNI);
nodoArbol * descargaDeClientesDeArchivoEnArbol();
void cargarArbolDeClientesEnArchivo(nodoArbol* arbol);
void guardarArbolEnArchivoRecursivo(FILE* archivo, nodoArbol* actual);
nodoArbol* encontrarMinimo(nodoArbol* nodo);
nodoArbol* eliminarNodoarbol(nodoArbol* raiz, int dniCliente);
nodoArbol* modificarCliente(int DNI, nodoArbol* arbol);


#endif // ARBOLGENERAL_H_INCLUDED
