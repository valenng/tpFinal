#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "ArregloDeListas.h"

const char archivoAutos[] = "ArchiAutos" ;

stAutosXMarca buscarAutosXMarca(int marcaActual, stAutosXMarca arregloXMarca[], int cantidad)
{
    stAutosXMarca autosXMarcaActual ;
    int flag = 0;

    for(int i=0; i<cantidad && !flag; i++)
    {
        if(arregloXMarca[i].marcaDeAuto == marcaActual)
        {
            autosXMarcaActual = arregloXMarca[i] ;
            flag = 1;
        }
    }
    if(!flag)
    {
        arregloXMarca[cantidad].listaAutos = inicLista() ;
        arregloXMarca[cantidad].marcaDeAuto = marcaActual ;
        cantidad++;
    }
    return autosXMarcaActual ; ///RETORNA EL ELEMENTO GUARDADO EN EL ARREGLO -> el cual contiene la marca que se busca
}


void cargarArregloAutos(stAutosXMarca arregloXMarca[])
{
    FILE* archivo = fopen(archivoAutos, "rb") ;
    if(archivo != NULL)
    {
        int cantidad = 0;
        stAuto autitoAux;
        nodo* nodoAux;
        fseek(archivo, 0, SEEK_END) ; ///LLEGO AL FINAL DEL ARCHIVO
        int cantidadAutos = ftell(archivo) / sizeof(stAuto) ;

        if(cantidadAutos > 0)
        {
            fseek(archivo, 0,SEEK_SET) ; ///POSICIONADO AL INICIO DEL ARCHIVO
            while(fread(&autitoAux, sizeof(stAuto), 1, archivo)>0) ///LEO EL REGISTRO
            {
                int marcaActual = autitoAux.marcasDeAuto;
                stAutosXMarca autosXMarcaActual = buscarAutosXMarca(marcaActual, arregloXMarca, cantidad) ;
                nodoAux = crearNodo(autitoAux) ;
                autosXMarcaActual.listaAutos = agregarAlFinal(autosXMarcaActual.listaAutos, nodoAux) ;
            }
        }
        fclose(archivo) ;
    }
}















