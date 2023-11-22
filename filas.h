#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED



typedef struct{

struct nodo2* primero;
struct nodo2* ultimo;


}Fila;

typedef struct{

int dato;
struct nodo * ste;
struct nodo * ante;

}nodo2;

void inicFila(Fila* fila);
void agregarFila(Fila* fila, int dato);
int extrarDeFila(Fila * fila);
int verPrimero(nodo2* lista);
void mostrarFila(Fila * fila);
nodo2 * borrarPrimero(nodo2* primero);
nodo2 * initLista();
nodo2* crearNodo2(int dato);
nodo2 * agregarAlFinalNodo2ParaFila(nodo2* ultimo, nodo2 *   nuevoNodo);
void mostrarLista2(nodo2* lista);
nodo2* buscaUltimoR(nodo2* lista);




#endif // FILAS_H_INCLUDED
