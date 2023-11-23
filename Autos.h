#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

#define ARCHIVO_AUTO "ArchiAutos.bin" // const nombre del archivo

typedef struct
{
    int marcasDeAuto;
    int modelo;
    int anio;
    int tipoDeCombustible;
    char matricula[5];
    int color;
    int capacidad;
    float kilometrosAcumulados;
    float valorInicial ;
    int disponibilidad;  ///1- DISPONIBLE / 0- NO DISPONIBLE
    int dniInquilino;
}stAuto ;

void mostrarMarcasOModelos(char[][20]) ;
void mostrarCombustiblesOColores(char[][20]) ;

void asignarMatricula(char[]) ;
int elegirMarca() ;
stAuto cargarUnAuto(int) ;
void mostrarUnAuto(stAuto) ;
void cargarArchivoDeAutos(int) ;

void ingresarMatriculaYCalcularTarifa() ;
int calcularTarifa(char []) ;
void alquilarUnAuto() ;
void modificarEstado() ;
void devolverAuto() ;

#endif // AUTOS_H_INCLUDED
