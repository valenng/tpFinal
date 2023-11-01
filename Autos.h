#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

typedef struct
{
    int marcasDeAuto;
    int modelo;
    int ano;
    int tipoDeCombustible;
    char matricula[5];
    int color;
    int capacidad;
    float kilometrosAcumulados;
    float valorInicial ;
    int disponibilidad;  ///1- DISPONIBLE / 0- NO DISPONIBLE

}stAuto ;

<<<<<<< HEAD
void mostrarMarcasOModelos(char marcaOModelo[][15])
void mostrarCombustiblesOColores(char*[]) ;
=======
void mostrarMarcasOModelos(char[][15]) ;
void mostrarCombustiblesOColores(char[][15]) ;
>>>>>>> aad0f982f16ad157d2c45ce42446145a8c3c2604

void asignarMatricula(char* []) ;
stAuto cargarUnAuto() ;

#endif // AUTOS_H_INCLUDED
