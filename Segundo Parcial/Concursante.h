#define CAPACIDAD_ARRAY 100
#define DIGITOS_DNI 30
#include "LinkedList.h"
#ifndef CONCURSANTE_H_INCLUDED
#define CONCURSANTE_H_INCLUDED
typedef struct
{
    int numeroConcursante;
    int anioNacimiento;
    char nombre[CAPACIDAD_ARRAY];
    char dni[DIGITOS_DNI];
    char fechaPresentacion[100];
    char temaPresentacion[CAPACIDAD_ARRAY];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    int puntajeTerceraRonda;
    float promedioPuntaje;


}eConcursante;

#endif // CONCURSANTE_H_INCLUDED


eConcursante* newConcursante();

eConcursante* newConcursanteParametros(char* numeroConcursante, char* anioNacimiento, char* nombre, char* dni, char* fechaPresentacion, char* temaPresentacion, char* puntajePrimeraRonda);

int setNumeroConcursante(eConcursante* this, int numeroConcursante);

int setAnioNacimiento(eConcursante* this, int anioNacimiento);

int setNombre(eConcursante* this, char nombre[]);

int setDni(eConcursante* this, char dni[]);

int setFechaPresentacion(eConcursante* this, char fechaPresentacion[]);

int setTemaPresentacion(eConcursante* this, char temaPresentacion[]);

int setPuntajePrimeraRonda(eConcursante* this, int puntajePrimeraRonda);

int getNumeroConcursante(eConcursante* this, int* numeroConcursante);

int getAnioNacimiento(eConcursante* this, int* anioNacimento);

int getNombre(eConcursante* this, char* nombre);

int getDni(eConcursante* this, char* dni);

int getFechaPresentacion(eConcursante* this, char* fechaPresentacion);

int getTemaPresentacion(eConcursante* this, char* temaPresentacion);

int getPuntajePrimeraRonda(eConcursante* this, int* puntajePrimeraRonda);

void mostrarConcursante(eConcursante* concursante);

int numeroRandom();

int calcularSegundaRonda(void* this);

int setPuntajeSegundaRonda(eConcursante* this, int puntajeSegundaRonda);

int setPromedioPuntaje(eConcursante* this, float promedioPuntaje);

int getPuntajeSegundaRonda(eConcursante* this, int *puntajeSegundaRonda);

int getPromedio(eConcursante* this, float *promedio);

int verificarAprobado(eConcursante* this);

int getDniPath(char* dniPath, char* dniAux);

int sacarGanadorPrimeraRonda(void* pConcursante, int criterio);

int calcularTerceraRonda(void* this);

int setPuntajeTerceraRonda(eConcursante* pConcursante, int puntajeTerceraRonda);

int getPuntajeTerceraRonda(eConcursante* this, int* puntajeTerceraRonda);

int sacarGanadorTerceraRonda(void* pConcursante, int criterio);

int getConcursante(eConcursante* pConcursante, int* numeroConcursante, int* anioNacimiento, char* nombre, char* dni, char* fechaPresentacion, char* temaPresentacion, int* puntajePrimeraRonda, int* puntajeSegundaRonda, float* promedio);

int sacarFinalistasPrimeraRonda(void* pArrayConcursantes);

int sacarFinalistasTerceraRonda(void* pArrayConcursantes);
