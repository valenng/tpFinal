#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define CLIENTE_ARCHIVO "archivoClientes.bin" // const nombre del archivo

#include "Clientes.h" ///-> LIB. CLIENTES C/PROTOTIPADOS Y ESTRUCTURA
#include "listas2Clientes.h"


/*
int verificarUsuario(int DNI){   /// hacer en casa

    FILE *archivo = fopen(NOMBRE_ARCHIVO, "rb");
    int salida = 0;
    nodo2Clientes *  listaClientes = initLista2Cliente();



    if(archivo != NULL)
    {

        if(buscarDNIlista2Cliente(&listaClientes, DNI) != NULL)  /// FALLTA CREAR LA LISTA DE CLIENTES
        {

            salida = 1;

        }
        else
        {

            printf("no se pudo abrir el archivo");

        }


    }

    fclose(archivo);

    return salida;

}

*/

void crearNuevoUsuario()
{

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

    if(buscarDNIlista2Cliente(&listaClientes, nuevoCliente.DNI) == NULL){

        cargarClienteEnLista(nuevoCliente);

    }else{

    printf("El dni ya existe ");
    menu();


    }




}


void cargarClienteEnLista(stClientes nuevoCliente){



        nodo2Clientes * listaCliente = cargarListaClientesArchivo(); /// crear funcion que devuelva una lista cargada segun un archivo


        nodo2Clientes * nodoNuevo = crearNodo2Cliente(nuevoCliente);
        nodo2Clientes * lista = agregarAlPrincipio(listaCliente,nodoNuevo);

        cargarListaDeClientes2EnArchivo(lista);


}


nodo2Clientes* cargarListaClientesArchivo(){

nodo2Clientes* lista2 = initLista2Cliente;
nodo2Clientes* nodoCliente;
FILE* archivo = fopen(CLIENTE_ARCHIVO, "rb");
stClientes cliente;

if(archivo != NULL){

    while(fwrite(&cliente, sizeof(stClientes), 1, archivo)>0){

        nodoCliente = crearNodo2Cliente(cliente);
        lista2 = agregarNodo2EnLaLista2(lista2, nodoCliente);


    }
    fclose(archivo);


}else{

printf("no se pudo abrir el archivo");

}


return lista2;




}



nodo2Clientes* cargarListaDeClientes2EnArchivo(nodo2Clientes lista){ /// terminar en casa

FILE* archivo = fopen(CLIENTE_ARCHIVO, "rb");
stClientes cliente;

if(archivo != NULL){





    }
    fclose(archivo);


}else{

printf("no se pudo abrir el archivo");

}

}





