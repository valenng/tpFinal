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
nodo* agregarAlFinal(nodo*, nodo*);

nodo* pasarArchivoALista() ;
nodo* cargaGeneralAuto(int) ;

void mostrarLista(nodo*) ;
void mostrarDisponibles(nodo*) ;



#endif // PROTOTIPADOS_LISTAS_H_INCLUDED
