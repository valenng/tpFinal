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
stAuto cargarUnAuto(int) ;
void cargarArchivoDeAutos(int) ;
stAuto cargaGenArchivoAutos()  ;

#endif // AUTOS_H_INCLUDED
