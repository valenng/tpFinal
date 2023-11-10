#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define CLIENTE_ARCHIVO "archivoClientes.bin" // const nombre del archivo

#include "Clientes.h"
#include "arbolGeneral.h"


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
    scanf("%i", &nuevoCliente.licencia); /// falta validar 1 o 2

    printf("\nIngresar el DNI de %s %s\n\nIngresar DNI:  ", nuevoCliente.nombre, nuevoCliente.apellido);
    scanf("%i", &nuevoCliente.DNI);

///---------
/// verificar estado de DNI y carga EN EL ARBOL en el arhivo

    nodoArbol* arbolCliente = descargaDeClientesDeArchivoEnArbol();
    nodoArbol* nodoCliente = busquedaDeClienteEnArbol(arbolCliente, nuevoCliente.DNI);



    if(nodoCliente == NULL)
    {
        nodoArbol* nodoNuevoCliente = crearNodoArbolCliente(nuevoCliente);
        arbolCliente = insertarEnArbolNodoCliente(arbolCliente,nodoNuevoCliente );
        cargarArbolDeClientesEnArchivo(arbolCliente);
        system("cls");
        printf("\n\n    USUARIO CREADO CON EXITO !!!");
        sleep(5);
        menu();

    }
    else // si el DNI ya existe NO se carga el nuevo cliente;
    {

        printf("\n\n    EL DNI YA EXISTE !!!");
        sleep(5);
        menu();


    }

    menu();

}

/*
void cargarClienteEnLista(stClientes nuevoCliente)
{



    nodo2Clientes * listaCliente = clientesArchivoCargarLista(); /// teniendo en cuenta los datos del archivo. se cargan estos datos el la lista. (se crea una nueva lista con los clientes)

    nodo2Clientes * nodoNuevo = crearNodo2Cliente(nuevoCliente); /// se crea un nuevo nodo cliente para agregar en la lista 2
    nodo2Clientes * lista = agregarNodo2EnLaLista2(listaCliente,nodoNuevo); /// se agrega al cliente en la lista 2

    cargarListaDeClientes2EnArchivo(lista);


}
*/

void mostrarInformacionDelCliente(int DNI)
{



    stClientes cliente;
    nodoArbol* arbol = descargaDeClientesDeArchivoEnArbol();
    nodoArbol* clienteNodo = busquedaDeClienteEnArbol(arbol, DNI);


    mostrarCliente(clienteNodo->clientes);



}



/*
stClientes buscarStClientePorDNI(int DNI)
{

    stClientes clienteEncontrado;
    nodo2Clientes * nodo = clientesArchivoCargarLista();

    while(lista!=NULL)
    {

        if(lista->cliente.DNI ==  DNI)
        {

            clienteEncontrado = lista->cliente;
            break;

        }
        else
        {

            lista = lista->siguiente;

        }


    }

    return clienteEncontrado;



}
*/

void mostrarCliente(stClientes cliente)
{

    printf("\n\nNombre: %s\nApellido: %s\nDNI: %i\nLicencia: ",cliente.nombre,cliente.apellido, cliente.DNI);
    if(cliente.licencia == 1)
    {

        printf("SI");

    }
    else
    {

        printf("NO");

    }

}






