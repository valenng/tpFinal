#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{

    char nombre[20];
    char apellido[20];
    int DNI;
    int licencia; // 1 si -  2 no


}stClientes;

void crearNuevoUsuario();
void mostrarInformacionDelCliente(int DNI);
void mostrarCliente(stClientes cliente);


#endif // CLIENTES_H_INCLUDED
