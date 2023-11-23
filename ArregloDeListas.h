#ifndef ARREGLODELISTAS_H_INCLUDED
#define ARREGLODELISTAS_H_INCLUDED

#define ARCHIVO_AUTO "ArchiAutos.bin"
#define ARCHIVO_ARREGLO_AUTOS "ArchiArregloAutos.bin"
#include "Prots-LISTAS-autos.h"

typedef struct
{
    int marcaDeAuto ;
    nodo* listaAutos ;
}stAutosXMarca;

int cargarArregloDeListasAutos(stAutosXMarca[], int, int) ;
int alta(stAutosXMarca[], nodo*, int, int) ;
int buscarPosMarca(stAutosXMarca[], int, int) ;
void mostrarArregloDeListas(stAutosXMarca[], int) ;
void funcMenuCargaAutos() ;
void funcMenuMostrarListadoGeneral() ;
void funcMenuMostrarDisponibles() ;


#endif // ARREGLODELISTAS_H_INCLUDED
