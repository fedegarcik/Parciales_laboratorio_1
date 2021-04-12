#define CANTIDAD_ARRAY 30
#define CANTIDAD_HARDCODEO_PAIS 5
#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    char pais[CANTIDAD_ARRAY];
    int estado;
}ePaisAux;


typedef struct
{
    char pais[CANTIDAD_ARRAY];
    char continete[CANTIDAD_ARRAY];
    int codigoTelefonico;
    int estado;
    int idpais;
}ePais;


#endif // PAIS_H_INCLUDED

void HardcodearPais(ePais paises[]);

void MostrarPais(ePais pais);

void MostrarPaises(ePais paises[], int cantidadPaises);

int BuscarPaisPorId(int IdRaza, ePais paises[], int cantidadPaises);
