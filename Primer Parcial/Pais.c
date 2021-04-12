
#include "Pais.h"
#include <stdio.h>
#include <string.h>
void HardcodearPais(ePais paises[])
{
    int i;
    char paisAux[CANTIDAD_HARDCODEO_PAIS][30]     = {"argentina","alemania","tailandia","persia","belgica"};
    char contienteAux[CANTIDAD_HARDCODEO_PAIS][30] = {"America","europa","asia","asia","europa"};
    int  CodTelAux[CANTIDAD_HARDCODEO_PAIS]    = {54,49,66,98,32};
    int estadoAux[CANTIDAD_HARDCODEO_PAIS]     = {1,1,1,1,1};
    int idAux[CANTIDAD_HARDCODEO_PAIS]         = {1,2,3,4,5};

    for(i=0;i < CANTIDAD_HARDCODEO_PAIS ;i++)
    {
        paises[i].idpais = idAux[i];
        paises[i].codigoTelefonico = CodTelAux[i];
        strcpy(paises[i].pais, paisAux[i]);
        strcpy(paises[i].continete, contienteAux[i]);
        paises[i].estado = estadoAux[i];
    }
}

void MostrarPais(ePais pais)
{
    printf("%-8d", pais.idpais);
    printf("%-15s", pais.pais);
    printf("%-15s", pais.continete);
    printf("%-8d", pais.codigoTelefonico);

}

void MostrarPaises(ePais paises[], int cantidadPaises)
{
    int i;

    printf("Id      ");
    printf("Pais         ");
    printf("Continente     ");
    printf("Codigo telefonico\n");

    for(i=0;i<cantidadPaises;i++)
    {
        MostrarPais(paises[i]);
        printf("\n");
    }
}

int BuscarPaisPorId(int IdRaza, ePais paises[], int cantidadPaises)
{
     int i;
     int retorno;

     //Establezco el retorno en caso de error en -1
     retorno = -1;

     //For en el cual reccoro el array de paises
     for(i = 0; i< cantidadPaises; i++)
     {
         //Pregunto primero si la raza esta dada de alta y luego si los id coinciden
         if(paises[i].estado == 1 && IdRaza == paises[i].idpais)
         {
             //En caso de coincidir los id y que la raza este dada de alta devuelvo el indice correspondiente
             retorno = i;
             break;
         }
     }

     return retorno;
}
