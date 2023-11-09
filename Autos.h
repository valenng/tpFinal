#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

char archivoAutos[] = "ArchiAutos" ;

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
}stAuto ;

void mostrarMarcasOModelos(char[][20]) ;
void mostrarCombustiblesOColores(char[][20]) ;

void asignarMatricula(char[]) ;
stAuto cargarUnAuto() ;
void cargarArchivoDeAutos() ;




#endif // AUTOS_H_INCLUDED
