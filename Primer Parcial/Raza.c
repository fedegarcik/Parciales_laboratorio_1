#define CANTIDAD_RAZA_HARDCODEO 6
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Raza.h"
#include "EntradaySalida.h"


void HardcodearRazas(eRaza razas[])
{
    //Cargo los valores que van a ser hardcodeados en array auxiliares
    int i;
    int idRaza[CANTIDAD_RAZA_HARDCODEO]           = {1,2,3,4,5,6};
    int idPais[CANTIDAD_RAZA_HARDCODEO]           = {1,1,2,4,5,1};
    char descripcion[CANTIDAD_RAZA_HARDCODEO][30] = {"siames","doberman","persa","pastor belga","dogo argentino","pastor aleman"};
    char tamanio[CANTIDAD_RAZA_HARDCODEO][30]     = {"chico","grande","mediano","grande","grande","grande"};
    char pais[CANTIDAD_RAZA_HARDCODEO][30]        = {"tailandia","alemania","persia","belgica","argentina","alemania"};
    int estado[CANTIDAD_RAZA_HARDCODEO]           = {1,1,1,1,1,1};

    //Se cargan los valores en el array de razas a travez de un for
    for(i=0;i < CANTIDAD_RAZA_HARDCODEO ;i++)
    {
        razas[i].idRaza = idRaza[i];
        razas[i].idPais = idPais[i];
        strcpy(razas[i].descripcion, descripcion[i]);
        strcpy(razas[i].tamanio, tamanio[i]);
        strcpy(razas[i].origen, pais[i]);
        razas[i].estado = estado[i];
    }
}

void MostrarRazas(eRaza razas[], int cantidad)
{
    int i;

    //Leyendas de los campos de la raza
    printf("id raza ");
    printf("descripcion    ");
    printf("tamanio        ");
    printf("origen\n");

    //For que muestra las razas
    for(i=0; i< cantidad ;i++)
    {
        //Pregunto si la raza esta dada de alta antes de mostrar
        if(razas[i].estado == 1)
        {
            printf("%-8d",  razas[i].idRaza);
            printf("%-15s", razas[i].descripcion);
            printf("%-15s", razas[i].tamanio);
            printf("%-15s\n", razas[i].origen);

        }
    }
}

void MostrarRaza(eRaza raza)
{
    //Pregunto que la raza este dada de alta antes de mostrar
    if(raza.estado == 1)
        {
            //Se muestra una raza
            //printf("%-8d",  razas.idRaza);
            printf("%-15s", raza.descripcion);
            printf("%-15s", raza.tamanio);
            printf("%-15s", raza.origen);
        }
}


 int BuscarRazaPorId(int mascotaIdRaza, eRaza razas[], int cantidadRazas)
 {
     int i;
     int retorno;

     //Establezco el retorno en caso de error en -1
     retorno = -1;

     //For en el cual reccoro el array de razas
     for(i = 0; i< cantidadRazas; i++)
     {
         //Pregunto primero si la raza esta dada de alta y luego si los id coinciden
         if(razas[i].estado == 1 && mascotaIdRaza == razas[i].idRaza)
         {
             //En caso de coincidir los id y que la raza este dada de alta devuelvo el indice correspondiente
             retorno = i;
             break;
         }
     }

     return retorno;
 }

 int inciliazarRazas(eRaza razas[], int cantidadRazas)
 {
      int i;
    int retorno;



    //Se establece el retorno en caso de error en -1
    retorno = -1;

    //Me fijo que la capacidad de array pasada como parametro no sea mayor a la del array
    if(cantidadRazas <= CANTIDAD_RAZAS)
    {

        //Inicializo la variable de estado y los id para no tener valores basuras y que comienzen  todos dados de baja y con su id en 0
        for(i = 0; i < cantidadRazas ; i++)
        {
            razas[i].estado = 0;
            razas[i].idRaza = 0;
        }
        retorno = 0;
    }
    return retorno;
 }

int ObtenerEspacioLibreRaza(eRaza razas[], int cantidadRazas)
{
    int i;
    int banderaEspacioLibre;

    banderaEspacioLibre = 0;

    //Busco en el array cual es el espacio libre
    for(i = 0; i<cantidadRazas; i++)
    {
        if(razas[i].estado == 0)
        {
            banderaEspacioLibre  = 1;

            break;
        }
    }

    //En caso de no encontrar espacio se devuelve -1 como error
    if(banderaEspacioLibre == 0)
    {
        i = -1;
    }
    return i;
}

void CargarRaza(eRaza razas[], int cantidadRazas, int indice, ePais paises[], int cantidadPaises)
{

    int idMaximo;
    int i;

    //Inicializo el id maximo en 0 para evitar errores
    idMaximo = 0;

    //Pregunto si hay espacio libre de no haberlo no se carga la mascota
    if(indice == -1)
    {
        printf("ERROR NO HAY MAS ESPACIO PARA RAZAS NUEVAS\n");
    }
    else
    {
        MostrarPaises(paises, cantidadPaises);
        IngresarDatoCadenaCaracteres(razas[indice].descripcion, "Ingrese el tipo de raza por favor");

        IngresarDatoCadenaCaracteres(razas[indice].tamanio, "Ingrese el tamanio, 'chico', 'mediano' o 'grande'");
        strlwr(razas[indice].tamanio);
        while(strcmp(razas[indice].tamanio, "chico")   != 0 &&
              strcmp(razas[indice].tamanio, "mediano") != 0 &&
              strcmp(razas[indice].tamanio, "grande")  != 0)
        {

            IngresarDatoCadenaCaracteres(razas[indice].tamanio, "Ingrese el tamanio, 'chico', 'mediano' o 'grande'");
            strlwr(razas[indice].tamanio);
        }

        IngresarDatoCadenaCaracteres(razas[indice].origen, "Ingrese el pais de origen de la raza");




        //Recorro el array de razas buscando el id maximo
        for(i = 0; i<cantidadRazas; i++)
        {
            if(razas[i].idRaza > idMaximo)
            {
                idMaximo = razas[i].idRaza;
            }
        }

        //El id de la mascota ingresada va a ser igual al id maximo +1 ej: idMax = 5, nuevoId = 6
        razas[indice].idRaza = idMaximo + 1;

        //Doy de alta logica la mascota
        razas[indice].estado = 1;
    }
}
