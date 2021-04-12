#include "Mascotas.h"
#include "Raza.h"
#include "Pais.h"


/** \brief Muestra cada raza con sus respectivas mascotas
 *
 * \param eRaza[]: array de razas
 * \param eMascota[]: array de mascotas
 * \param int: cantidad de elementos del array de mascotas
 * \param int: cantidad de elementos del array de razas
 * \return void
 *
 */


void MostrarRazaConMascotas(eRaza[], eMascota[], int, int);

/** \brief Muestra la mascotas con su raza y pais de origen
 *
 * \param eRaza[]: array de razas
 * \param eMascota[]: array de mascotas
 * \param int: cantidad de elementos del array de mascotas
 * \param int: cantidad de elementos del array de razas
 * \return void
 *
 */


void MostrarMascotaConRaza(eRaza[], eMascota[], int, int);

/** \brief Menu de opciones interactivo
 *
 * \param eMascota[]: array de mascotas que se le pasara a las distintas funciones
 * \param eRaza[]: array de razas que se les pasa a las distintas funciones
 * \param ePaisp[]: array de paises que se le pasa a las distintas funciones
 * \param int: cantidad de elementos del array de mascotas
 * \param int: cantidad de elementos del array de razas
 * \return
 *
 */


void Menu(eMascota[], eRaza[], ePaisAux[], ePais[], int, int, int);


