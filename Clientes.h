#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{

    char nombre[20];
    char apellido[20];
    int DNI;
    int licencia; // 1 si -  2 no


}stClientes;

void cargarClienteEnLista(stClientes nuevoCliente);
void crearNuevoUsuario();



#endif // CLIENTES_H_INCLUDED
