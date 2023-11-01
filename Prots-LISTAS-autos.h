#ifndef PROTOTIPADOS_LISTAS_H_INCLUDED
#define PROTOTIPADOS_LISTAS_H_INCLUDED

#include "Autos.h"

typedef struct
{
    stAuto autito;
    struct nodo* siguiente;
}nodo;

nodo* inicLista() ;
nodo* crearNodo(stAuto) ;
nodo* agregarAlPrincipio(nodo*, nodo*) ;
nodo* agregarEnOrden(nodo*, nodo*) ;
void escribir(nodo*) ;
void recorrerYMostrar(nodo*) ;
nodo* eliminarNodo(char[30], nodo*) ;

#endif // PROTOTIPADOS_LISTAS_H_INCLUDED
