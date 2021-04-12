#include "Concursante.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "EntradaySalida.h"
#include <time.h>

eConcursante* newConcursante()
{
    eConcursante* nuevoConcursante;

    nuevoConcursante = (eConcursante*) malloc(sizeof(eConcursante));

    return nuevoConcursante;
}

int setNumeroConcursante(eConcursante* this, int numeroConcursante)
{
    int retorno;

    retorno = -1;

    if(this != NULL && numeroConcursante > 0)
    {
        this->numeroConcursante = numeroConcursante;
        retorno = 1;
    }

    return retorno;
}

int setAnioNacimiento(eConcursante* this, int anioNacimiento)
{
    int retorno;

    retorno = -1;

    if(this != NULL && anioNacimiento > 1940)
    {
        this->anioNacimiento = anioNacimiento;
        retorno = 1;
    }

    return retorno;
}

int setNombre(eConcursante* this, char nombre[])
{
    int retorno;

    retorno = -1;

    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }

    return retorno;
}

int setDni(eConcursante* this, char dni[])
{
    int retorno;

    retorno = -1;

    if(this != NULL)
    {
        strcpy(this->dni, dni);
        retorno = 1;
    }

    return retorno;
}

int setFechaPresentacion(eConcursante* this, char fechaPresentacion[])
{
    int retorno;

    retorno = -1;

    if(this != NULL)
    {
        strcpy(this->fechaPresentacion, fechaPresentacion);
        retorno = 1;
    }


    return retorno;
}


int setTemaPresentacion(eConcursante* this, char temaPresentacion[])
{
    int retorno;

    retorno = -1;

    if(this != NULL)
    {
        strcpy(this->temaPresentacion, temaPresentacion);
        retorno = 1;
    }

    return retorno;
}

int setPuntajePrimeraRonda(eConcursante* this, int puntajePrimeraRonda)
{
    int retorno;

    retorno = -1;

    if(this != NULL && puntajePrimeraRonda > -1 && puntajePrimeraRonda < 100)
    {
        this->puntajePrimeraRonda = puntajePrimeraRonda;
        retorno = 1;
    }

    return retorno;
}

eConcursante* newConcursanteParametros(char* numeroConcursante, char* anioNacimiento, char* nombre, char* dni, char* fechaPresentacion, char* temaPresentacion, char* puntajePrimeraRonda)
{
    eConcursante* nuevoConcursante;

    nuevoConcursante = newConcursante();

    if(nuevoConcursante != NULL)
    {
        if(setNumeroConcursante(nuevoConcursante, atoi(numeroConcursante))    == 1 &&
           setAnioNacimiento(nuevoConcursante, atoi(anioNacimiento))          == 1 &&
           setNombre(nuevoConcursante, nombre)                                == 1 &&
           setDni(nuevoConcursante, dni)                                      == 1 &&
           setFechaPresentacion(nuevoConcursante, fechaPresentacion)          == 1 &&
           setTemaPresentacion(nuevoConcursante, temaPresentacion)            == 1 &&
           setPuntajePrimeraRonda(nuevoConcursante,atoi(puntajePrimeraRonda)) == 1)
        {

        }
        else
        {
            printf("ERROR AL CARGAR LOS DATOS");
            nuevoConcursante = NULL;
        }
    }
    else
    {
        printf("NO HAY ESPACIO EN MEMORIA");
    }

    return nuevoConcursante;
}


int getNumeroConcursante(eConcursante* this, int* numeroConcursante)
{
    int retorno;

    retorno = -1;


    if(this != NULL && numeroConcursante != NULL)
    {
        *numeroConcursante = this->numeroConcursante;
        retorno = 0;
    }

    return retorno;
}

int  getAnioNacimiento(eConcursante* this, int* anioNacimento)
{
    int retorno;

    retorno = -1;

    if(this != NULL && anioNacimento != NULL)
    {
        *anioNacimento = this->anioNacimiento;
        retorno = 0;
    }

    return retorno;
}

int getNombre(eConcursante* this, char* nombre)
{
    int retorno;

    retorno = -1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }

    return retorno;
}

int getDni(eConcursante* this, char* dni)
{
    int retorno;

    retorno = -1;

    if(this != NULL && dni != NULL)
    {
        strcpy(dni, this->dni);
        retorno = 0;
    }

    return retorno;
}

int getFechaPresentacion(eConcursante* this, char* fechaPresentacion)
{
    int retorno;

    retorno = -1;

    if(this != NULL && fechaPresentacion != NULL)
    {
        strcpy(fechaPresentacion, this->fechaPresentacion);
        retorno = 0;
    }

    return retorno;
}

int getTemaPresentacion(eConcursante* this, char* temaPresentacion)
{
    int retorno;

    retorno = -1;

    if(this != NULL && temaPresentacion != NULL)
    {
        strcpy(temaPresentacion, this->temaPresentacion);
        retorno = 0;
    }

    return retorno;
}

int getPuntajePrimeraRonda(eConcursante* this, int* puntajePrimeraRonda)
{
    int retorno;

    retorno = -1;

    if(this != NULL && puntajePrimeraRonda != NULL)
    {
        *puntajePrimeraRonda = this->puntajePrimeraRonda;
        retorno = 0;
    }

    return retorno;
}


void mostrarConcursante(eConcursante* concursante)
{
    int numeroConcursante;
    int anioNacimiento;
    char nombre[100];
    char dni[100];
    char fechaPresentacion[100];
    char temaPresentacion[100];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float promedio;
    int puntajeTerceraRonda;

    getNumeroConcursante(concursante, &numeroConcursante);
    getAnioNacimiento(concursante, &anioNacimiento);
    getNombre(concursante, nombre);
    getDni(concursante, dni);
    getFechaPresentacion(concursante, fechaPresentacion);
    getTemaPresentacion(concursante, temaPresentacion);
    getPuntajePrimeraRonda(concursante, &puntajePrimeraRonda);
    getPuntajeSegundaRonda(concursante, &puntajeSegundaRonda);
    getPromedio(concursante, &promedio);
    getPuntajeTerceraRonda(concursante, &puntajeTerceraRonda);

    printf("%-15d %-15d %-30s %-30s %-30s %-50s %-25d %-15d %-15.2f %-15d \n", numeroConcursante, anioNacimiento, nombre, dni, fechaPresentacion, temaPresentacion, puntajePrimeraRonda, puntajeSegundaRonda, promedio, puntajeTerceraRonda);
}


int numeroRandom()
{

    int retorno;
    //srand((unsigned)time(&t));
    retorno =  rand() % 100 + 1;


    return retorno;
}

int setPuntajeSegundaRonda(eConcursante* this, int puntajeSegundaRonda)
{
    int retorno;
    retorno = -1;

    if(this != NULL)
    {
        this->puntajeSegundaRonda = puntajeSegundaRonda;
        retorno = 0;
    }

    return retorno;


}

int setPromedioPuntaje(eConcursante* this, float promedioPuntaje)
{
    int retorno;
    retorno = -1;

    if(this != NULL)
    {
        this->promedioPuntaje = promedioPuntaje;
        retorno = 0;
    }

    return retorno;


}

int calcularSegundaRonda(void* this)
{
    int retorno;
    int puntajeSegundaRonda;
    int puntajePrimeraRonda;
    float promedio;

    retorno = -1;

    if(this != NULL)
    {
        puntajeSegundaRonda = numeroRandom();
        getPuntajePrimeraRonda(this, &puntajePrimeraRonda);

        promedio = (float)(puntajePrimeraRonda + puntajeSegundaRonda) / 2;

        setPuntajeSegundaRonda(this, puntajeSegundaRonda);
        setPromedioPuntaje(this, promedio);

        retorno = 0;
    }


    return retorno;

}

int getPuntajeSegundaRonda(eConcursante* this, int *puntajeSegundaRonda)
{
    int retorno;
    retorno = -1;

    if(this != NULL && puntajeSegundaRonda != NULL)
    {
        *puntajeSegundaRonda = this->puntajeSegundaRonda;
        retorno = 0;
    }

    return retorno;
}


int getPromedio(eConcursante* this, float *promedio)
{
    int retorno;
    retorno = -1;

    if(this != NULL && promedio != NULL)
    {
        *promedio = this->promedioPuntaje;
        retorno = 0;
    }

    return retorno;
}

int verificarAprobado(eConcursante* this)
{
    int retorno;

    retorno = -1;

    if(this->puntajePrimeraRonda > 70)
    {
        retorno = 1;
    }

    return retorno;
}

int getDniPath(char* dniPath, char* dniAux)
{
    int retorno;
    retorno = -1;
    if(dniAux != NULL && dniPath != NULL)
    {
        strcpy(dniPath, dniAux);
        strcat(dniPath, ".csv");
        retorno = 0;
    }

    return retorno;
}

int sacarGanadorPrimeraRonda(void* pConcursante, int criterio)
{
    int retorno;
    int puntajePrimeraRondaConcursante;



    getPuntajePrimeraRonda(pConcursante, &puntajePrimeraRondaConcursante);
    retorno = 0;


    if(puntajePrimeraRondaConcursante >= criterio)
    {
        retorno = 1;
    }
    return retorno;
}

int calcularTerceraRonda(void* this)
{
    int retorno;
    int puntajeTerceraRonda;


    retorno = -1;

    if(this != NULL)
    {
        puntajeTerceraRonda = numeroRandom();

        setPuntajeTerceraRonda(this, puntajeTerceraRonda);


        retorno = 0;
    }


    return retorno;

}

int setPuntajeTerceraRonda(eConcursante* pConcursante, int puntajeTerceraRonda)
{
    int retorno;

    retorno = -1;

    if(pConcursante != NULL)
    {
        pConcursante->puntajeTerceraRonda = puntajeTerceraRonda;
        retorno = 0;
    }

    return retorno;
}

int getPuntajeTerceraRonda(eConcursante* this, int* puntajeTerceraRonda)
{
    int retorno;
    retorno = -1;

    if(this != NULL)
    {
        *puntajeTerceraRonda = this->puntajeTerceraRonda;
        retorno = 0;
    }

    return retorno;
}

int sacarGanadorTerceraRonda(void* pConcursante, int criterio)
{
    int retorno;
    int puntajeTerceraRonda;



    getPuntajeTerceraRonda(pConcursante, &puntajeTerceraRonda);
    retorno = 0;


    if(puntajeTerceraRonda >= criterio)
    {
        retorno = 1;
    }
    return retorno;
}

int getConcursante(eConcursante* pConcursante ,int* numeroConcursante, int* anioNacimiento, char* nombre, char* dni, char* fechaPresentacion, char* temaPresentacion, int* puntajePrimeraRonda, int* puntajeSegundaRonda, float* promedioPuntaje)
{
    int retorno;

    retorno = -1;

    if(
    getNumeroConcursante(pConcursante, numeroConcursante)     == 0 &&
    getAnioNacimiento(pConcursante, anioNacimiento)           == 0 &&
    getNombre(pConcursante, nombre)                           == 0 &&
    getDni(pConcursante, dni)                                 == 0 &&
    getFechaPresentacion(pConcursante, fechaPresentacion)     == 0 &&
    getTemaPresentacion(pConcursante, temaPresentacion)       == 0 &&
    getPuntajePrimeraRonda(pConcursante, puntajePrimeraRonda) == 0 &&
    getPuntajeSegundaRonda(pConcursante, puntajeSegundaRonda) == 0 &&
    getPromedio(pConcursante, promedioPuntaje)                == 0
    )
    {
        retorno = 0;
    }
    else
    {
        printf("ERROR AL OBTENER ALGUNO DE LOS DATOS");
    }

    return retorno;

}

int sacarFinalistasPrimeraRonda(void* pArrayConcursantes)
{
    int retorno;
    int primerGanador;
    int segundoGanador;
    int tercerGanador;
    int i;
    eConcursante* pConcursante;


    retorno        = -1;

    if(pArrayConcursantes != NULL)
    {


        pConcursante   = (eConcursante*)ll_get(pArrayConcursantes, 0);
        primerGanador  = pConcursante->puntajePrimeraRonda;
        segundoGanador = pConcursante->puntajePrimeraRonda;
        tercerGanador  = pConcursante->puntajePrimeraRonda;


        for(i=0; i < ll_len(pArrayConcursantes); i++)
        {
            pConcursante = (eConcursante*)ll_get(pArrayConcursantes, i);
            if(pConcursante->puntajePrimeraRonda > primerGanador)
            {
                tercerGanador = segundoGanador;
                segundoGanador = primerGanador;
                primerGanador = pConcursante->puntajePrimeraRonda;

            }
            else
            {
                if(pConcursante->puntajePrimeraRonda > segundoGanador)
                {
                    tercerGanador = segundoGanador;
                    segundoGanador = pConcursante->puntajePrimeraRonda;

                }
                else
                {
                    if(pConcursante->puntajePrimeraRonda > tercerGanador)
                    {
                    tercerGanador = pConcursante->puntajePrimeraRonda;
                    }
                }
            }
        }

        retorno = tercerGanador;
    }

    return retorno;
}

int sacarFinalistasTerceraRonda(void* pArrayConcursantes)
{
    int retorno;
    int primerGanador;
    int segundoGanador;
    int tercerGanador;
    int i;
    eConcursante* pConcursante;


    retorno        = -1;

    if(pArrayConcursantes != NULL)
    {


        pConcursante   = (eConcursante*)ll_get(pArrayConcursantes, 0);
        primerGanador  = pConcursante->puntajeTerceraRonda;
        segundoGanador = pConcursante->puntajeTerceraRonda;
        tercerGanador  = pConcursante->puntajeTerceraRonda;


        for(i=0; i < ll_len(pArrayConcursantes); i++)
        {
            pConcursante = (eConcursante*)ll_get(pArrayConcursantes, i);
            if(pConcursante->puntajeTerceraRonda > primerGanador)
            {
                tercerGanador = segundoGanador;
                segundoGanador = primerGanador;
                primerGanador = pConcursante->puntajeTerceraRonda;

            }
            else
            {
                if(pConcursante->puntajeTerceraRonda > segundoGanador)
                {
                    tercerGanador = segundoGanador;
                    segundoGanador = pConcursante->puntajeTerceraRonda;

                }
                else
                {
                    if(pConcursante->puntajeTerceraRonda > tercerGanador)
                    {
                    tercerGanador = pConcursante->puntajeTerceraRonda;
                    }
                }
            }
        }

        retorno = tercerGanador;
    }

    return retorno;
}

