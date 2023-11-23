#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "Prots-LISTAS-autos.h"

typedef struct{

nodo * lista;

}Pila;

void initPila(Pila *p);
void apilarPila(Pila* p, stAuto autito);
void mostrarPila(Pila * p);
void desapilarPila(Pila* p);


#endif // PILA_H_INCLUDED
