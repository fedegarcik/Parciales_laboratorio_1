#include "Mascota_raza.h"
#ifndef PAIS_MASCOTA_H_INCLUDED
#define PAIS_MASCOTA_H_INCLUDED



#endif // PAIS_MASCOTA_H_INCLUDED


/** \brief Obtiene cual es el pais con mas mascotas y lo muestra
 *
 * \param eMascota[]: array de mascotas a recorrer
 * \param eRaza[]: array de razas a ser usado
 * \param ePaisAux[]: array de pais a ser procesado
 * \param int: cantidad de mascotas
 * \param int: cantidad de raza
 * \return void
 *
 */


void ObtenerPaisMaximo(eMascota[], eRaza[], ePaisAux[], int, int);

/** \brief Cuenta cuantas veces existe el pais que toma como parametro en el array de paises
 *
 * \param ePaisAux[]: array de paies
 * \param char[]: pais a buscar coincidencia
 * \param int: cantidad de paises
 * \return cantidad de veces que encontro el pais
 *
 */

int ContarCantidadPais(ePaisAux[], char[], int);

/** \brief incializa el array de paises en 0 si no existe el pais y en 1 si existe
 *
 * \param eMascota[]: array de mascotas a recorrer
 * \param eRaza[]: array de razas a ser usado
 * \param ePaisAux[]: array de pais a ser procesado
 * \param int: cantidad de mascotas
 * \param int: cantidad de razas
 * \return void
 *
 */


void InicializarPaises(eMascota[], ePaisAux[], eRaza[], int, int);

void ListarRazaConPais(ePais paises[], eRaza razas[], int cantidadRazas, int cantidadPaises);

int BuscarMascotaPorPais(ePais paises[], eRaza razas[], eMascota mascota, int cantidadMascotas, int cantidadRazas, int cantidadPaises);

void OrdenarPorTel(ePais paises[], eRaza razas[], eMascota mascotas[], int cantidadMascotas, int cantidadRazas, int cantidadPaises);

void MostrarMascotaConArea(ePais paises[], eRaza razas[], eMascota mascotas[], int cantidadMascotas, int cantidadRazas, int cantidadPaises);
