#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Clientes.h" ///-> LIB. CLIENTES C/PROTOTIPADOS Y ESTRUCTURA
#include "listas2Clientes.h"



int verificarUsuario(int DNI){

    FILE archivo;
    int salida = 0;

    if(archivo != NULL){

          if(buscarDNIlista2Cliente(listaClientes, DNI) != NULL){ /// FALLTA CREAR LA LISTA DE CLIENTES

        salida = 1;

    }else{

    printf("no se pudo abrir el archivo");

    }


    }

    return salida;

}



void crearNuevoUsuario(){
stClientes nuevoCliente;

printf("ingreas")



}



void usuarioSesionIniciada(){

}







