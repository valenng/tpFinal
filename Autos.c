#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define ARCHIVO_AUTO "ArchiAutos.bin" // const nombre del archivo

#include "Autos.h" ///-> LIB. AUTOS C/PROTOTIPADOS Y ESTRUCTURA
#include "Prots-LISTAS-autos.h"
#include "ArregloDeListas.h"



char maxValorMatricula[3] = {25,25,99} ;
char ultimaMatricula[3] = {0,0,0} ;

char marcasDeAuto[10][20] = {"Toyota", "Fiat", "Citroën", "Audi", "Peugeot", "Volkswagen", "Ford", "Chevrolet", "Renault", "Nissan"} ;

/// 1- TOYOTA
char modelosToyota[10][20] = {"Etios Sedán", "Corolla", "Hilux", "SW4", "Etios Aibo", "GR86", "Camry", "RAV4", "C-HR", "Etios Hatchback"};
/// 2- FIAT
char modelosFiat[10][20] = {"Pulse", "Cronos", "Argo", "Toro", "Strada", "Mobi", "Uno", "500", "Tipo", "Fiorino"};
/// 3- CITROEN
char modelosCitroen[10][20] = {"C3", "C3 Aircross", "C4 X", "C4 Cactus", "C4 Lounge", "C5 Aircross", "Jumper", "Jumpy", "Berlingo Furgón", "Berlingo Multispace"};
/// 4- AUDI
char modelosAudi[10][20] = {"A4", "A3", "A6", "Q5", "A5", "A7", "Q3", "Q7", "A1", "Q8"};
/// 5- PEUGEOT
char modelosPeugeot[10][20] = {"208", "308", "408", "Partner Furgón", "Partner Patagónica", "Expert", "5008 SUV", "308S", "2008", "3008"};
/// 6- VOLKSWAGEN
char modelosVolkswagen[10][20] = {"Amarok", "Gol", "Up!", "Saveiro", "T-Cross", "Golf", "Passat", "Suran", "Voyage", "Fox"};
/// 7- FORD
char modelosFord[10][20] = {"Fiesta", "Ranger", "Ranger Raptor", "EcoSport", "Ka", "Focus", "Mustang", "Transit", "F-150 Raptor", "Territory"};
/// 8- CHEVROLET
char modelosChevrolet[10][20] = {"Onix", "S10", "Joy", "Prisma Joy", "Cobalt", "Onix Joy", "Montana", "Trailblazer", "Spin", "Cruze"};
/// 9- RENAULT
char modelosRenault[10][20] = {"Sandero", "Logan", "Kangoo", "KWID", "Captur", "Duster", "Oroch", "Master", "Stepway", "Alaskan"};
/// 10- NISSAN
char modelosNissan[10][20] = {"Versa", "Sentra", "Frontier", "Kicks", "March", "Note", "Murano", "Leaf", "X-Trail", "Versa V-Drive"};

char* modelosPorMarca[10] = {modelosToyota, modelosFiat, modelosCitroen, modelosAudi, modelosPeugeot, modelosVolkswagen, modelosFord, modelosChevrolet, modelosRenault, modelosNissan} ;

char tipoCombustibles[5][20] = {"Infinia", "Súper", "Infinia Diesel", "Ultra Diesel", "Diesel 500"};

char coloresAutos[5][20] = {"Negro", "Blanco", "Rojo", "Gris", "Azul"} ;

///MOSTRAMOS TODAS LAS MARCAS O MODELOS
void mostrarMarcasOModelos(char marcaOModelo[][20])
{
    for (int i = 1; i < 11; i++) ///--> SE PUEDE UTILIZAR PARA AMBOS PORQUE TIENEN LA MISMA CANTIDAD DE ELEMENTOS
    {
        printf("\n\t[ %d ] %s", i, marcaOModelo[i - 1]);
    }
}
/*
///MOSTRAMOS TODOS LAS MODELOS DEPENDIENDO LA MARCA
void mostrarModelos(char* modelos[])
{
    for (int i = 1; i < 11; i++)
    {
        printf("\n\t[ %d ] %s", i, modelos[i - 1]);
    }
}
*/
///MOSTRAMOS TODOS LOS TIPOS DE COMBUSTIBLES O COLORES
void mostrarCombustiblesOColores(char combustiblesOColores[][20])
{
    for(int i=1; i<6; i++)
    {
        printf("\n\t[ %d ] %s", i, combustiblesOColores[i - 1]);
    }
}

///ASIGNACIÓN MATRÍCULA (ASÍ NO SE REPITE)

void asignarMatricula(char matricula[5])
{
    srand(time(NULL)) ;
    matricula[0] = 'A' + rand()%26;
    matricula[1] = 'A' + rand()%26;
    matricula[2] = '0' + rand()%10;
    matricula[3] = '0' + rand()%10;
    matricula[4] = '\0' ;
}

void nuevaMatriculaR(int ultimaMatricula[3], int maxValues[3], int numElements) ///REVISAR
{
    if (ultimaMatricula[numElements-1] < maxValues[numElements-1])
    {
        ultimaMatricula[numElements-1] += 1;
    } else {
        if (numElements-1 > 0)
        {
            ultimaMatricula[numElements-1] = 0;
            nuevaMatriculaR(ultimaMatricula, maxValues, numElements-1);
        }
    }
}

///CARGAR UN AUTO
stAuto cargarUnAuto()
{
    stAuto autito;

    printf("\n|INGRESAR LA MARCA DEL AUTO|\n ") ;
    mostrarMarcasOModelos(marcasDeAuto) ;
    printf("\n\n|OPCIÓN ELEGIDA|: ") ;
    scanf("%i", &autito.marcasDeAuto) ;

    system("cls") ;

    printf("\n|ELEGIR MODELO|(MARCA: %s)\n ", marcasDeAuto[autito.marcasDeAuto-1]) ;
    switch(autito.marcasDeAuto)
    {
    case 1: ///TOYOTA
        mostrarMarcasOModelos(modelosToyota) ;
        break;
    case 2: ///FIAT
        mostrarMarcasOModelos(modelosFiat);
        break;
    case 3: ///CITROEN
        mostrarMarcasOModelos(modelosCitroen);
        break;
    case 4: ///AUDI
        mostrarMarcasOModelos(modelosAudi);
        break;
    case 5: ///PEUGEOT
        mostrarMarcasOModelos(modelosPeugeot);
        break;
    case 6: ///VOLKSWAGEN
        mostrarMarcasOModelos(modelosVolkswagen);
        break;
    case 7: ///FORD
        mostrarMarcasOModelos(modelosFord);
        break;
    case 8: ///CHEVROLET
        mostrarMarcasOModelos(modelosChevrolet);
        break;
    case 9: ///RENAULT
        mostrarMarcasOModelos(modelosRenault);
        break;
    case 10: ///NISSAN
        mostrarMarcasOModelos(modelosNissan);
        break;
    }
    printf("\n\n|OPCIÓN ELEGIDA|: ") ;
    scanf("%i", &autito.modelo) ;

    do
    {
        printf("\n|INGRESAR AÑO DEL AUTO|(MARCA: %s, MODELO: %i): ", marcasDeAuto[autito.marcasDeAuto-1], autito.modelo) ; ///REVISAR CÓMO MOSTRAR EL MODELO
        scanf("%i", &autito.anio) ;
    }
    while(autito.anio < 2020 || autito.anio > 2023) ;

    do
    {
        printf("\n|TIPO DE COMBUSTIBLE|\n") ;
        mostrarCombustiblesOColores(tipoCombustibles) ;
        printf("\n\n|OPCIÓN ELEGIDA|: ") ;
        scanf("%i", &autito.tipoDeCombustible) ;
    }
    while(autito.tipoDeCombustible < 1 || autito.tipoDeCombustible > 5) ;

    asignarMatricula(autito.matricula) ;
    printf("\n|MATRICULA|: %s\n", autito.matricula) ;

    ///system("cls") ;  ///CHEQUEAR CÓMO LIMPIAR DE A PARTES

    do
    {
        printf("\n|COLOR DEL AUTO|\n") ;
        mostrarCombustiblesOColores(coloresAutos) ;
        printf("\n\n|OPCIÓN ELEGIDA|: ") ;
        scanf("%i", &autito.color) ;
    }
    while(autito.color < 1 || autito.color > 5) ;

    do
    {
        printf("\n|INGRESE LA CAPACIDAD DEL AUTO|: ") ;
        scanf("%i", &autito.capacidad) ;
    }
    while(autito.capacidad < 0) ;


    printf("\n|INGRESAR LA CANTIDAD DE KM ACUMULADOS|: ") ;
    scanf("%f", &autito.kilometrosAcumulados) ;

    do
    {
        printf("\n|INGRESAR VALOR INICIAL DEL AUTO|: ") ;
        scanf("%f", &autito.valorInicial) ;
    }
    while(autito.valorInicial < 0) ;

    autito.disponibilidad = 1 ; ///SIEMPRE SE INICIA ESTANDO DISPONIBLE PARA ALQUILAR

    return autito ;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

void mostrarUnAuto(stAuto autito)
{
    printf("\n-----------------------------------------") ;
    printf("\n|MARCA|: %s", marcasDeAuto[autito.marcasDeAuto-1]) ;
    printf("\n|MODELO|: %s", modelosPorMarca[autito.marcasDeAuto-1]+20*(autito.modelo-1)) ;
    printf("\n|AÑO|: %i", autito.anio) ;
    printf("\n|TIPO DE COMBUSTIBLE|: %s", tipoCombustibles[autito.tipoDeCombustible-1]) ;
    printf("\n|MATRICULA|: %s", autito.matricula) ;
    printf("\n|COLOR|: %s", coloresAutos[autito.color-1]) ;
    printf("\n|CAPACIDAD|: %i", autito.capacidad) ;
    printf("\n|KILOMETROS ACUMULADOS|: %.2f", autito.kilometrosAcumulados) ;
    printf("\n|VALOR INICIAL|: %.2f", autito.valorInicial) ;
    printf("\n|DISPONIBILIDAD|: %i", autito.disponibilidad) ;
    printf("\n-----------------------------------------") ;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

void cargarArchivoDeAutos()
{
    FILE *archivo = fopen(ARCHIVO_AUTO, "ab") ;
    if(archivo != NULL)
    {
        stAuto autito = cargarUnAuto() ;
        fwrite(&autito, sizeof(stAuto), 1, archivo) ;
        fclose(archivo) ;
    }
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

nodo* pasarArchivoALista(nodo* listaAutos)
{
    stAuto autito;
    FILE *archivo = fopen(ARCHIVO_AUTO, "rb") ;
    if(archivo != NULL)
    {
        while(fread(&autito, sizeof(stAuto), 1, archivo) > 0)
        {
            nodo* nuevoNodo = crearNodo(autito) ;
            listaAutos = agregarAlPrincipio(listaAutos, nuevoNodo) ;
        }
        fclose(archivo) ;
    }
    return listaAutos ;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

void pasarListaAArchivoWB(nodo* listaAutos)
{
    FILE* archivo = fopen(ARCHIVO_AUTO, "wb") ;
    if(archivo != NULL)
    {
        while(listaAutos != NULL)
        {
            fwrite((&listaAutos->autito), sizeof(stAuto), 1, archivo) ;
            listaAutos = listaAutos->siguiente ;
        }
        fclose(archivo) ;
    }
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

char buscarMatricula(FILE* archivo)
{
    stAuto autito;
    char matricula[5] ;
    int i=0;
    int posicion = -1;

    printf("\n|INGRESE LA MATRICULA BUSCADA|: ") ;
    fflush(stdin) ;
    gets(matricula) ;
    while(fread(&autito, sizeof(stAuto), 1, archivo) > 0)
    {
        printf("\n|INGRESE LA MATRICULA BUSCADA|: ") ;
        fflush(stdin) ;
        gets(matricula) ;

        if(strcmpi(autito.matricula, matricula) == 0)
        {
            posicion = i;
            i++;
        }
    }
    return posicion ;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

void ingresarMatricula(char matricula[5])
{
    printf("\n|INGRESE LA MATRICULA BUSCADA|: ") ;
    fflush(stdin) ;
    gets(matricula) ;
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

void borrarUnAutoDelArchivo()
{
    char matricula[5] ;
    FILE* archivo = fopen(ARCHIVO_AUTO, "rb") ;
    if(archivo != NULL)
    {
        nodo* aux = pasarArchivoALista(archivo) ;
        ingresarMatricula(matricula) ;
        aux = eliminarNodo(aux, matricula) ;
        fclose(archivo) ;
        pasarListaAArchivoWB(aux) ;
    }
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

void buscarAuto(int marcaAuto)
{
    stAutosXMarca* autosXMarca = (stAutosXMarca*) malloc(10*sizeof(stAutosXMarca)) ;
    cargarArregloAutos(autosXMarca) ;

    int flag = 0;

    stAutosXMarca autoDeLaMarca ;

    for(int i=0; i<10 && !flag; i++)
    {
        if(autosXMarca[i].marcaDeAuto == marcaAuto)
        {
            autoDeLaMarca = autosXMarca[i] ;
            flag = 1;
        }
    }
    if(!flag)
    {
        printf("\n|NO SE ENCONTRÓ LA MARCA|.\n") ;
    }
    else
    {
        for(int j=0; j < sizeof(autoDeLaMarca.listaAutos); j++)
        {
            mostrarUnAuto(autoDeLaMarca.listaAutos[j].autito) ;
        }
    }
}

///FUNCIÓN PARA CALCULAR LA TARIFA DE UN AUTO.
