#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Concursante.h"
#include "EntradaySalida.h"

int controller_loadFromText(LinkedList* pArrayConcursantes)
{

    int retorno;
    char path[100];
    FILE* pFile;

    retorno = -1;

    IngresarDatoCadenaCaracteres(path, "ingrese el nombre del archivo incluyendo extension .csv");
    pFile = fopen(path, "r");
    if(pFile != NULL)
    {
        retorno = parser_ConcursanteFromText(pFile, pArrayConcursantes);
    }
    else
    {
        printf("No se encuentra el archivo");
    }

    fclose(pFile);


    return retorno;


}

int controller_ListEmployee(LinkedList* pArrayConcursante)
{
    eConcursante* nuevoConcursante;
    int len;
    int i;
    int retorno;


    len =  ll_len(pArrayConcursante);
    retorno = -1;
    if(pArrayConcursante != NULL)
    {
        for(i=0;i<len;i++)
        {
            nuevoConcursante = ll_get(pArrayConcursante, i);
            mostrarConcursante(nuevoConcursante);





            retorno = 1;
        }

    }

    return retorno;
}

int controller_SaveAsText(char* path, LinkedList* pArrayConcursantes)
{
    int retorno;
    FILE* pFile;
    eConcursante* pConcursante;
    int len;
    int i;
    int numeroConcursante;
    int anioNacimiento;
    char nombre[100];
    char dni[100];
    char fechaPresentacion[100];
    char temaPresentacion[100];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float promedioPuntaje;
    char promedioStr[100];

    retorno = -1;
    len = ll_len(pArrayConcursantes);
    pFile = fopen(path, "w");

    if(pFile != NULL)
    {
        for(i=0; i < len; i++)
        {
            pConcursante = (eConcursante*)ll_get(pArrayConcursantes, i);

            getConcursante(pConcursante ,&numeroConcursante, &anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, &puntajePrimeraRonda, &puntajeSegundaRonda, &promedioPuntaje);
            sprintf(promedioStr, "%f", promedioPuntaje);

            fprintf(pFile, "%d,%d,%s,%s,%s,%s,%d,%d,%s\n", numeroConcursante, anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda, puntajeSegundaRonda, promedioStr);


        }
        retorno = 0;
    }
    fclose(pFile);

    return retorno;
}
/*
int controller_whichToLoad(char* path)
{
    int retorno;
    retorno = -1;

    strlwr(path);
    if(strcmp(path, "buenosaires") == 0)
    {
        retorno = 1;
    }
    else
    {
        printf("El archivo no existe");
    }
    return retorno;
}
*/
int controler_saveAproved(LinkedList* this)
{
    int retorno;
    eConcursante* pConcursante;
    FILE* pFile;
    int numeroConcursante;
    int anioNacimiento;
    char nombre[100];
    char dni[100];
    char fechaPresentacion[100];
    char temaPresentacion[100];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float promedioPuntaje;
    char promedioStr[100];
    char dniPath[100];
    int i;

    retorno = -1;



    if(this != NULL)
    {
        for(i=0; i<ll_len(this); i++)
        {
            pConcursante = (eConcursante*)ll_get(this, i);
            if(verificarAprobado(pConcursante) == 1)
            {


                getConcursante(pConcursante, &numeroConcursante, &anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, &puntajePrimeraRonda, &puntajeSegundaRonda, &promedioPuntaje);

                getDniPath(dniPath, dni);
                pFile = fopen(dniPath, "w");

                sprintf(promedioStr, "%f", promedioPuntaje);


                fprintf(pFile, "%d,%d,%s,%s,%s,%s,%d,%d,%s\n", numeroConcursante, anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda, puntajeSegundaRonda, promedioStr);
                fclose(pFile);
            }
        }
        retorno = 0;

    }
    return retorno;
}

int controller_SaveWinners(LinkedList* pArrayConcursantes)
{
    int retorno;
    FILE* pFile;
    eConcursante* pConcursante;
    int len;
    int i;
    int numeroConcursante;
    int anioNacimiento;
    char nombre[100];
    char dni[100];
    char fechaPresentacion[100];
    char temaPresentacion[100];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float promedioPuntaje;
    char promedioStr[100];
    char dniPath[100];

    retorno = -1;
    len = ll_len(pArrayConcursantes);




        for(i=0; i < len; i++)
        {
            pConcursante = (eConcursante*)ll_get(pArrayConcursantes, i);

            getConcursante(pConcursante, &numeroConcursante, &anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, &puntajePrimeraRonda, &puntajeSegundaRonda, &promedioPuntaje);

            getDniPath(dniPath, dni);
            pFile = fopen(dniPath, "w");

            sprintf(promedioStr, "%f", promedioPuntaje);

            fprintf(pFile, "%d,%d,%s,%s,%s,%s,%d,%d,%s\n", numeroConcursante, anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda, puntajeSegundaRonda, promedioStr);
            fclose(pFile);

        }
        retorno = 0;



    return retorno;
}
