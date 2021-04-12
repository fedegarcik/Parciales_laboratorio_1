#include <stdio.h>
#include <stdlib.h>
#include "Pais.h"
#include "Pais_mascota.h"
#include "Mascotas.h"
#include "Raza.h"
#include <string.h>


void ObtenerPaisMaximo(eMascota mascotas[], eRaza razas[], ePaisAux paises[], int cantidadMascotas, int cantidadRazas)
{
    int i;
    char paisMax[CANTIDAD_ARRAY];
    int cantMax;
    int cantPaisActual;

    cantPaisActual = 0;
    cantMax = 0;

    InicializarPaises(mascotas, paises, razas, cantidadMascotas, cantidadRazas);

    for(i=0; i< cantidadMascotas; i++)
    {
        if(paises[i].estado == 1)
        {
            cantPaisActual = ContarCantidadPais(paises, paises[i].pais, cantidadMascotas);

            if(cantPaisActual> cantMax)
            {
                cantMax = cantPaisActual;
                strcpy(paisMax, paises[i].pais);
            }
        }
    }

    printf("El pais con mas mascotas es: %s \n", paisMax);



}

int ContarCantidadPais(ePaisAux paises[], char nombrePais[],  int cantidadPaises)
{
    int contadorAux;
    int i;

    contadorAux = 0;

    for(i=0; i< cantidadPaises; i++)
    {
        if(strcmp(paises[i].pais, nombrePais) == 0)
        {
            contadorAux++;
            paises[i].estado = 0;
        }
    }

    return contadorAux;
}

void InicializarPaises(eMascota mascotas[], ePaisAux paises[], eRaza razas[], int cantidadMascotas, int cantidadRazas)
{
    int i;
    int j;

    for(i = 0; i<cantidadMascotas; i++)
    {
        if(mascotas[i].estado == 1)
        {
            j = BuscarRazaPorId(mascotas[i].idRaza, razas, cantidadRazas);
            strcpy(paises[i].pais, razas[j].origen);
            paises[i].estado = 1;
        }
        else
        {
            paises[i].estado = 0;
        }

    }
}

void ListarRazaConPais(ePais paises[], eRaza razas[], int cantidadRazas, int cantidadPaises)
{
    int i;
    int j;

    printf("descripcion    ");
    printf("tamanio        ");
    printf("origen            ");
    printf("Pais         ");
    printf("Codigo telefonico\n");

    for(i=0; i<cantidadPaises; i++)
    {

        MostrarRaza(razas[i]);

        j = BuscarPaisPorId(razas[i].idPais ,paises, cantidadPaises);
        if(j != -1)
        {
            printf("%-15s      ", paises[j].pais);
            printf("%-8d\n", paises[j].codigoTelefonico);

        }

    }
}

int BuscarMascotaPorPais(ePais paises[], eRaza razas[], eMascota mascota, int cantidadMascotas, int cantidadRazas, int cantidadPaises)
{
    int j;
    int l;
    int retorno;

    retorno = -1;

            for(j=0;j<cantidadRazas;j++)
            {
                if(razas[j].estado == 1 && mascota.idRaza == razas[j].idRaza)
                {
                    for(l=0;l<cantidadPaises;l++)
                    {
                        if(razas[j].idPais == paises[l].idpais)
                        {
                            retorno = l;
                            break;
                        }
                    }
                }
            }
    return retorno;
}

void OrdenarPorTel(ePais paises[], eRaza razas[], eMascota mascotas[], int cantidadMascotas, int cantidadRazas, int cantidadPaises)
{
    int i;
    int j;
    int indiceUno;
    int indiceDos;
    eMascota mascotaAux;

    for(i=0; i<cantidadMascotas; i++)
    {
        indiceUno = BuscarMascotaPorPais(paises, razas, mascotas[i], cantidadMascotas, cantidadRazas, cantidadPaises);

        for(j=i+ 1; j< cantidadMascotas; j++)
        {

            indiceDos = BuscarMascotaPorPais(paises, razas, mascotas[j], cantidadMascotas, cantidadRazas, cantidadPaises);

            if(paises[indiceUno].codigoTelefonico < paises[indiceDos].codigoTelefonico)
            {
                mascotaAux  = mascotas[i];
                mascotas[i] = mascotas[j];
                mascotas[j] = mascotaAux;

            }
        }
    }
    MostrarMascotaConArea(paises, razas, mascotas, cantidadMascotas, cantidadRazas, cantidadPaises);

}

void MostrarMascotaConArea(ePais paises[], eRaza razas[], eMascota mascotas[], int cantidadMascotas, int cantidadRazas, int cantidadPaises)
{
    int i;
    int indice;


    printf("id     ");
    //printf("id raza   ");
    printf("nombre        ");
    printf("sexo      ");
    printf("edad    ");
    printf("peso      ");
    printf("tipo       ");
    printf("Codigo telefonico\n");

    //Recorro todo el array de las mascotas mostrandolas
    for(i= 0; i < cantidadMascotas; i ++)
    {
        //Pregunto si esta dada de alta la mascota antes de mostrar
        if(mascotas[i].estado == 1)
        {
            indice = BuscarMascotaPorPais(paises, razas, mascotas[i], cantidadMascotas, cantidadRazas, cantidadPaises);
            MostrarMascota(mascotas[i]);
            printf("%-8d", paises[indice].codigoTelefonico);
            printf("\n");
        }
    }
}
