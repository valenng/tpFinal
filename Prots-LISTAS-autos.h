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

void mostrarNodo(nodo*) ;

nodo* eliminarNodo(nodo*, char[]) ;



#endif // PROTOTIPADOS_LISTAS_H_INCLUDED
