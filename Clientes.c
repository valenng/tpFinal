#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#define NOMBRE_ARCHIVO "archivoClientes.bin" // const nombre del archivo



#include "Clientes.h" ///-> LIB. CLIENTES C/PROTOTIPADOS Y ESTRUCTURA
#include "listas2Clientes.h"



int verificarUsuario(int DNI){   /// consultar

    FILE *archivo = fopen(NOMBRE_ARCHIVO, "rb");
    int salida = 0;
    nodo2Clientes *  listaClientes = initLista2Cliente();



    if(archivo != NULL){

          if(buscarDNIlista2Cliente(&listaClientes, DNI) != NULL){ /// FALLTA CREAR LA LISTA DE CLIENTES

        salida = 1;

    }else{

    printf("no se pudo abrir el archivo");

    }


    }

    fclose(archivo);

    return salida;

}



void crearNuevoUsuario(){

  system("cls");

stClientes nuevoCliente;
fflush(stdin);
printf("  CREAR USUARIO \n\nIngrear el nombre del usuario:  ");
scanf("%s", &nuevoCliente.nombre);
fflush(stdin);
printf("\nIngresar el apellido del cliente:  ");
scanf("%s", &nuevoCliente.apellido);
fflush(stdin);
printf("\nTiene licencia de conducir? \n\n1) SI\n\n2)  NO\n\nIngresar la opcion : ");
scanf("%i", &nuevoCliente.licencia); /// falta cerificacion

printf("\nIngresar el DNI de %s %s\n\nIngresar DNI:  ", nuevoCliente.nombre, nuevoCliente.apellido);
scanf("%i", &nuevoCliente.DNI);

///---------
/// verificar estado de DNI y carga la lista en el arhivo

nodo2Clientes * listaClientes = initLista2Cliente();
FILE * archivo = fopen(NOMBRE_ARCHIVO, "r+b");


if(archivo!=NULL){

    if(buscarDNIlista2Cliente(&listaClientes, nuevoCliente.DNI) == NULL){

        nodo2Clientes* nuevo2NodoCliete = crearNodo2Cliente(nuevoCliente);
        listaClientes = agregarNodo2EnLaLista2(listaClientes, nuevo2NodoCliete);
        fwrite(listaClientes, sizeof(nodo2Clientes), 1, archivo);


    }else{
    system("cls");
    sleep(3);
    printf("EL DNI YA EXISTE. No se puede cargar a la nueva persona");

    }


}else{

printf("No se pudo abrir el archivo");

}

fclose(archivo);




}



void usuarioSesionIniciada(){

}







