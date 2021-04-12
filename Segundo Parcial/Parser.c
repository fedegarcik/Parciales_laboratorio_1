#include "Parser.h"
#include "Concursante.h"
#include <string.h>
int parser_ConcursanteFromText(FILE* pFile, LinkedList* pConcursanteList)
{
    int retorno;
    int banderaCarga;
    char numeroConcursante[100];
    char anioNacimiento[100];
    char nombre[100];
    char dni[30];
    char fechaPresentacion[100];
    char temaPresentacion[100];
    //char temaPresentacion2[100];
    char puntajePrimeraRonda[100];
    eConcursante* pNuevoConcursante;

    banderaCarga = 0;

    //Pongo el retorno en -1 en caso de error
    retorno = 1;

    //Leo un empleado en este caso la cabecera para evitar cargarlas en el array
    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", numeroConcursante, anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda);

    //Recorro el archivo hasta el final de este
    if(pConcursanteList != NULL && pFile !=NULL)
    {
        while(!feof(pFile))
        {

            //Leo un empleado
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", numeroConcursante, anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda) ==  7 )
            {
                /*
                if(atoi(puntajePrimeraRonda) == 0)
                {
                    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", numeroConcursante, anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, temaPresentacion2, puntajePrimeraRonda);
                    strcat(temaPresentacion, temaPresentacion2);
                    pNuevoConcursante = newConcursanteParametros(numeroConcursante, anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda);



                    ll_add(pConcursanteList, pNuevoConcursante);
                    banderaCarga = 1;
                    continue;
                }
                */
                //Reservo espacio en memoria para el empleado y cargo los datos
                pNuevoConcursante = newConcursanteParametros(numeroConcursante, anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda);


                //Agrego mi empleado a mi lista enlazada
                ll_add(pConcursanteList, pNuevoConcursante);
                banderaCarga = 1;
            }
            else
            {
                banderaCarga = 0;
            }



            //Compruebo que se hallan cargado correctamente los datos
            if(banderaCarga == 0)
            {
                //Pongo el retorno en -1 en caso de error y salgo del bucle
                retorno = -1;
                break;
            }
        }
    }

    return retorno;
}
