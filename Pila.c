#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Pila.h"

void initPila(Pila *p)
{

    p->lista = inicLista();

}


void apilarPila(Pila* p, stAuto autito)
{

    nodo * aux = crearNodo(autito);
    p->lista = agregarAlPrincipio(p, aux);


}
/*
void mostrarPila(Pila * p)
{

    printf("\nTope de la pila <|    ");
    recorrerYMostrarLista(p->lista);
    printf("    |> base ");

}
*/

void desapilarPila(Pila* p)
{
    if (p->lista != NULL)
    {
        nodo* nodoAEliminar = p->lista;
        p->lista = p->lista->siguiente;
        free(nodoAEliminar);
    }
}
