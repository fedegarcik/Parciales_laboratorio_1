#include <stdio.h>
#include <stdlib.h>
#include "Mascota_raza.h"
#include "Pais_mascota.h"
//#define CANTIDAD_PAISES 5
int main()
{

    eMascota mascotas[CANTIDAD_MASCOTAS];
    eRaza razas[CANTIDAD_RAZAS];
    ePaisAux paisesAux[CANTIDAD_MASCOTAS];
    ePais paises[CANTIDAD_HARDCODEO_PAIS];


    Menu(mascotas, razas,paisesAux, paises, CANTIDAD_MASCOTAS, CANTIDAD_RAZAS, CANTIDAD_HARDCODEO_PAIS);

    //HardcodearPais(paises);
    //MostrarPaises(paises, CANTIDAD_PAISES);
    return 0;
}
