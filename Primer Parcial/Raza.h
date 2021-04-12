#define CANTIDAD_ARRAY 30
#define CANTIDAD_RAZAS 10
#include "Pais.h"
#ifndef RAZA_H_INCLUDED
#define RAZA_H_INCLUDED

typedef struct
{
    int idRaza;
    char descripcion[CANTIDAD_ARRAY];
    char tamanio[CANTIDAD_ARRAY];
    char origen[CANTIDAD_ARRAY];
    int idPais;
    int estado;
}eRaza;

#endif // RAZA_H_INCLUDED

/** \brief Se hardcodean los valores de las razas
 *
 * \param eRaza[]: array de razas a ser hardcodeado
 * \return void
 *
 */


void HardcodearRazas(eRaza[]);

/** \brief Se muestran todas las razas
 *
 * \param eRaza[]: array de razas a ser mostrado
 * \param int: cantidad de elementos del array de razas
 * \return void
 *
 */


void MostrarRazas(eRaza[], int);

/** \brief Se muestra una raza
 *
 * \param eRaza: raza a ser mostrada
 * \return void
 *
 */

void MostrarRaza(eRaza);

/** \brief Busca una raza por el id de raza y devuelve el indice donde se ubica
 *
 * \param int: id de raza a ser buscado
 * \param eRaza[]: array de raza donde se buscara la coincidencia de id
 * \param int: cantidad de elementos de array de razas
 * \return devuelve -1 en caso de no encontrar el id y el indice de la raza en caso de coincidencia
 *
 */


int BuscarRazaPorId(int, eRaza[], int);


int inciliazarRazas(eRaza razas[], int cantidadRazas);

int ObtenerEspacioLibreRaza(eRaza razas[], int cantidadRazas);

void CargarRaza(eRaza razas[], int cantidadRazas, int indice, ePais[], int);

