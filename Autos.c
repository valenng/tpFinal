#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

///#include "Autos.h" ///-> LIB. AUTOS C/PROTOTIPADOS Y ESTRUCTURA
///#include "Prots-LISTAS-autos.h"
#include "ArregloDeListas.h"
#define VALOR_ALQUILER 500

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

int capacidadMaximaUnAuto = 6 ;

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

int elegirMarca()
{
    int eleccion = 0;

    do
    {
        mostrarMarcasOModelos(marcasDeAuto) ;

        printf("\n\n|OPCIÓN ELEGIDA|: ") ;
        scanf("%i", &eleccion) ;

        if(eleccion < 1 || eleccion > 10)
        {
            system("cls") ;
            printf("\n- Opción incorrecta! Ingresa nuevamente la marca.\n") ;
        }
    }
    while(eleccion < 1 || eleccion > 10) ;

    return eleccion ;
}



///CARGAR UN AUTO
stAuto cargarUnAuto(int marcaDeAuto)
{
    stAuto autito;
/*
    printf("\n|INGRESAR LA MARCA DEL AUTO|\n ") ;
    mostrarMarcasOModelos(marcasDeAuto) ;
    printf("\n\n|OPCIÓN ELEGIDA|: ") ;
    scanf("%i", &autito.marcasDeAuto) ;
*/
    ///printf("\n- Volvamos a la carga general, ingrese nuevamente su marca..") ;
    autito.marcasDeAuto = marcaDeAuto ;
    system("cls") ;

    printf("\n- Excelente! Empecemos a cargar los datos del auto..\n") ;

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

    printf("\n- ¡Aclaración!: Nuestros modelos de auto corresponden desde el 2020 al 2023, por favor verificar bien al momento de ingresar su año.\n") ;
    do
    {
        printf("\n|INGRESAR AÑO DEL AUTO|(MARCA: %s, MODELO: %i): ", marcasDeAuto[autito.marcasDeAuto-1], autito.modelo) ;
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

    printf("\n- ¡Importante! El límite de capacidad es %i.\n", capacidadMaximaUnAuto) ;
    do
    {
        printf("\n|INGRESE LA CAPACIDAD DEL AUTO|: ") ;
        scanf("%i", &autito.capacidad) ;
    }
    while(autito.capacidad < 0 || autito.capacidad > 6) ;


    do
    {
        printf("\n|INGRESAR LA CANTIDAD DE KM ACUMULADOS|: ") ;
        scanf("%f", &autito.kilometrosAcumulados) ;
    }
    while(autito.kilometrosAcumulados < 0) ;

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

void cargarArchivoDeAutos(int marcaDeAuto)
{
    stAuto autito ;
    FILE *archivo = fopen(ARCHIVO_AUTO, "ab") ;
    if(archivo != NULL)
    {
        autito = cargarUnAuto(marcaDeAuto) ;
        fwrite(&autito, sizeof(stAuto), 1, archivo) ;
        fclose(archivo) ;
    }
}

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

///FUNCIONES PARA CALCULAR LA TARIFA DE UN AUTO.

void ingresarMatriculaYCalcularTarifa()
{
    char matricula[5] ;
    printf("\n- Ingrese la matrícula buscada: ") ;
    fflush(stdin) ;
    gets(matricula) ;

    int tarifa = calcularTarifa(matricula) ;
    printf("\n- Su tarifa final es: $%i", tarifa) ;
}

int calcularTarifa(char matriculaSeleccionada[])
{
    int cantidadDias, tarifa = 0;
    stAuto autito ;

    FILE* archivo = fopen(ARCHIVO_AUTO, "rb") ;
    if(archivo != NULL)
    {
        printf("\n\t\t|CÁLCULO DE TARIFAS|\n") ;
        printf("\t# Valor del alquiler: $500 por día.\n") ;
        printf("\n- Ingrese cuántos días quiere alquilar el auto: ") ;
        scanf("%i", &cantidadDias) ;

        while(fread(&autito, sizeof(stAuto), 1, archivo) > 0)
        {
            if(strcmpi(autito.matricula, matriculaSeleccionada) == 0)
            {
                tarifa = (cantidadDias * VALOR_ALQUILER) + autito.valorInicial;
                break;
            }
        }
        if(strcmpi(autito.matricula, matriculaSeleccionada) != 0)
        {
            printf("\n\t\t# Matrícula NO encontrada.\n") ;
            system("pause") ;
        }
        fclose(archivo) ;
    }
    return tarifa;
}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

void alquilarUnAuto()
{
    stAuto autito;
    FILE* archivo = fopen(ARCHIVO_AUTO, "r+b") ;
    if(archivo != NULL)
    {
        char matriculaSeleccionada[5] ;
        printf("\n- Ingrese la matrícula del auto para modificar su estado: ") ;
        fflush(stdin) ;
        gets(matriculaSeleccionada) ;

        while(fread(&autito, sizeof(stAuto), 1, archivo) > 0)
        {
            if(strcmpi(autito.matricula, matriculaSeleccionada) == 0) //SON IGUALES
            {
                int dniCliente = 0;
                printf("\n- Ingrese su DNI para confirmar el alquiler: ") ;
                scanf("%i", &dniCliente) ;

                autito.dniInquilino = dniCliente ;
                autito.disponibilidad = 0; //PASA A NO ESTAR DISPONIBLE
                fseek(archivo, (-1)*sizeof(stAuto), SEEK_CUR);
                fwrite(&autito, sizeof(stAuto), 1, archivo);

                printf("\n- Excelente! DNI cargado a la estructura del auto.\n") ;
                break;
            }
        }
        if(strcmpi(autito.matricula, matriculaSeleccionada) != 0)
        {
            printf("\n\t\t# Matrícula NO encontrada.\n") ;
            system("pause") ;
        }
        rewind(archivo) ; ///Reposicionar el indicador de posición al principio
        fclose(archivo) ;
    }
}


void modificarEstado()
{
    stAuto autito;
    FILE* archivo = fopen(ARCHIVO_AUTO, "r+b") ;
    if(archivo != NULL)
    {
        char matriculaSeleccionada[5] ;
        printf("\n- Ingrese la matrícula del auto que quiere alquilar: ") ;
        fflush(stdin) ;
        gets(matriculaSeleccionada) ;

        while(fread(&autito, sizeof(stAuto), 1, archivo) > 0)
        {
            if(strcmpi(autito.matricula, matriculaSeleccionada) == 0) //SON IGUALES
            {
                autito.disponibilidad = 0; //PASA A NO ESTAR DISPONIBLE
                fseek(archivo, (-1)*sizeof(stAuto), SEEK_CUR);
                fwrite(&autito, sizeof(stAuto), 1, archivo);
                break;
            }
        }
        rewind(archivo) ; ///Reposicionar el indicador de posición al principio
        fclose(archivo) ;
    }
}


void devolverAuto()
{
    char matriculaSeleccionada[5] ;
    printf("\n- Ingrese la matrícula del auto que quiere devolver: ") ;
    fflush(stdin) ;
    gets(matriculaSeleccionada) ;

    float cantKilometros = 0;
    printf("\n- Ingrese la cantidad de kilometros que recorrió: ") ;
    scanf("%f", &cantKilometros) ;

    stAuto autito;
    FILE* archivo = fopen(ARCHIVO_AUTO, "r+b") ;
    if(archivo != NULL)
    {
        while(fread(&autito, sizeof(stAuto), 1, archivo) > 0)
        {
            if(strcmpi(autito.matricula, matriculaSeleccionada) == 0)
            {
                autito.disponibilidad = 1; ///NUEVAMENTE DISPONIBLE
                autito.kilometrosAcumulados = autito.kilometrosAcumulados + cantKilometros ; ///NUEVA CANT. DE KM ACUMULADOS
                fseek(archivo, (-1)*sizeof(stAuto), SEEK_CUR);
                fwrite(&autito, sizeof(stAuto), 1, archivo);
                break;
            }
        }
        rewind(archivo) ; ///Reposicionar el indicador de posición al principio
        fclose(archivo) ;
    }
}

