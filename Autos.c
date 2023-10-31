#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "Autos.h" ///-> LIB. AUTOS C/PROTOTIPADOS Y ESTRUCTURA

char *marcasDeAuto[10] = {"Toyota", "Fiat", "Citroën", "Audi", "Peugeot", "Volkswagen", "Ford", "Chevrolet", "Renault", "Nissan"} ;

/// 1- TOYOTA
char* modelosToyota[10] = {"Etios Hatchback", "Etios Sedán", "Corolla", "Hilux", "SW4", "Etios Aibo", "GR86", "Camry", "RAV4", "C-HR"};
/// 2- FIAT
char* modelosFiat[10] = {"Pulse", "Cronos", "Argo", "Toro", "Strada", "Mobi", "Uno", "500", "Tipo", "Fiorino"};
/// 3- CITROEN
char* modelosCitroen[10] = {"C3", "C3 Aircross", "C4 X", "C4 Cactus", "C4 Lounge", "C5 Aircross", "Berlingo Furgón", "Berlingo Multispace", "Jumper", "Jumpy",};
/// 4- AUDI
char* modelosAudi[10] = {"A4", "A3", "A6", "Q5", "A5", "A7", "Q3", "Q7", "A1", "Q8"};
/// 5- PEUGEOT
char* modelosPeugeot[10] = {"208", "308", "408", "Partner Furgón", "Partner Patagónica", "Expert", "5008 SUV", "308S", "2008", "3008"};
/// 6- VOLKSWAGEN
char* modelosVolkswagen[10] = {"Amarok", "Gol", "Up!", "Saveiro", "T-Cross", "Golf", "Passat", "Suran", "Voyage", "Fox"};
/// 7- FORD
char* modelosFord[10] = {"Fiesta", "Ranger", "Ranger Raptor", "EcoSport", "Ka", "Focus", "Mustang", "Transit", "F-150 Raptor", "Territory"};
/// 8- CHEVROLET
char* modelosChevrolet[10] = {"Onix", "S10", "Joy", "Prisma Joy", "Cobalt", "Onix Joy", "Montana", "Trailblazer", "Spin", "Cruze"};
/// 9- RENAULT
char* modelosRenault[10] = {"Sandero", "Logan", "Kangoo", "KWID", "Captur", "Duster", "Oroch", "Master", "Stepway", "Alaskan"};
/// 10- NISSAN
char* modelosNissan[10] = {"Versa", "Sentra", "Frontier", "Kicks", "March", "Note", "Murano", "Leaf", "X-Trail", "Versa V-Drive"};

char* tipoCombustibles[5] = {"Infinia", "Súper", "Infinia Diesel", "Ultra Diesel", "Diesel 500"};

char* coloresAutos[5] = {"Negro", "Blanco", "Rojo", "Gris", "Azul"} ;

///MOSTRAMOS TODAS LAS MARCAS O MODELOS
void mostrarMarcasOModelos(char* marcaOModelo[])
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
void mostrarCombustiblesOColores(char* combustiblesOColores[])
{
    for(int i=1; i<6; i++)
    {
        printf("\n\t[ %d ] %s", i, combustiblesOColores[i - 1]);
    }
}



stAuto cargarUnAuto()
{
    stAuto autito;
    char control = ' ' ;

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
        scanf("%i", &autito.ano) ;
    }
    while(autito.ano < 2020 || autito.ano > 2023) ;

    do
    {
        printf("\n|TIPO DE COMBUSTIBLE|\n") ;
        mostrarCombustiblesOColores(tipoCombustibles) ;
        printf("\n\n|OPCIÓN ELEGIDA|: ") ;
        scanf("%i", &autito.tipoDeCombustible) ;
    }
    while(autito.tipoDeCombustible < 1 || autito.tipoDeCombustible > 5) ;

    do
    {
        printf("\n|INGRESAR LA MATRÍCULA DEL AUTO|: ") ;
        fflush(stdin) ;
        gets(autito.matricula) ;

        printf("\n\t\t¿NECESITA VOLVER A INGRESAR LA MATRÍCULA?(S/N)|: ") ;
        fflush(stdin) ;
        scanf("%s", &control) ;
    }
    while(tolower(control) == 's') ;

    ///system("cls") ;  ///CHEQUEAR CÓMO LIMPIAR DE A PARTES

    do
    {
        printf("\n|COLOR DEL AUTO|\n") ;
        mostrarCombustiblesOColores(coloresAutos) ;
        printf("\n\n|OPCIÓN ELEGIDA|: ") ;
        scanf("%i", &autito.color) ;
    }
    while(autito.color < 1 || autito.color > 5) ;

    printf("\n|INGRESAR LA CANTIDAD DE KM ACUMULADOS|: ") ;
    scanf("%f", &autito.kilometrosAcumulados) ;

    autito.disponibilidad = 1 ; ///SIEMPRE SE INICIA ESTANDO DISPONIBLE PARA ALQUILAR

    return autito ;
}

