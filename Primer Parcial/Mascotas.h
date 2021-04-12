#define CANTIDAD_ARRAY 30
#define CANTIDAD_MASCOTAS 10
#include "Raza.h"
#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{
    char nombre[CANTIDAD_ARRAY];
    int idMascota;
    int idRaza;
    int edad;
    int peso;
    char sexo;
    char tipo[CANTIDAD_ARRAY];
    int estado;
    int idPais;
}eMascota;


#endif // MASCOTAS_H_INCLUDED

/** \brief hardcode los datos en el array de mascotas
 *
 * \param eMascota[]: array de mascotas donde se van a hardcodear los datos
 * \return void
 *
 */

void HardcodearMascotas(eMascota[]);

/** \brief Muestra una mascota
 *
 * \param eMascota: mascota a mostrar
 * \return void
 *
 */


void MostrarMascota(eMascota);

/** \brief Muestra todas las mascotas del array de mascotas
 *
 * \param eMascota[]: array de mascotas a mostrarse
 * \param int: longitud del array de mascotas
 * \return void
 *
 */


void MostrarMascotas(eMascota[], int);


/** \brief Carga una mascota al array de mascotas
 *
 * \param eMascota[]: array de mascotas donde se cargara la mascota
 * \param eRaza[]: array de razas donde se validara el id raza
 * \param int: cantidad de elementos del array de mascotas
 * \param int: cantidad de elementos del array de razas
 * \param int: indice donde se cargara la mascota
 * \return void
 *
 */

void CargarMascota(eMascota[], eRaza[], int, int, int);

/** \brief Busca por id una mascota
 *
 * \param eMascota[]: el array de mascotas donde se buscara
 * \param int: cantidad de elementos del array de mascotas
 * \return devuelve -1 en caso de no poder encontrarse el id y el indice de elemento en caso de coincidencia
 *
 */

int BuscarPorId(eMascota[], int);

/** \brief Remueve una mascota del listado
 *
 * \param eMascota[]: array de mascota de donde se eliminara la mascota
 * \param int: cantidad de elementos del array de mascotas
 * \param int: indice del elemento a ser eliminado
 * \return devuelve 0 en caso de que no se elemine la mascota y 1 en caso de que se elimine
 *
 */


int RemoverMascota(eMascota[], int, int);

/** \brief incializa el estado de las mascotas y los id en 0
 *
 * \param eMascota[]: array de mascotas a ser inicializado
 * \param int: cantidad de elementos del array de mascotas
 * \return devuelve -1 en caso de no poder incializar y si pudo devuelve 0
 *
 */


int inicializarMascotas(eMascota[], int);

/** \brief ordena las mascotas por peso de mayor a menor
 *
 * \param eMascota[]: array de mascotas a ser ordenado
 * \param int: cantidad de elementos del array de mascotas
 * \return devuelve 0 si no se pudo ordenar 1 si pudo
 *
 */


int OrdenarPorPeso(eMascota[],int);

/** \brief busca un espacio libre en el array de mascotas
 *
 * \param eMascota[]: array de mascotas a buscarse el espacio libre
 * \param int: cantidad de elementos del array de mascotas
 * \return -1 en caso de error y si no el indice del espacio libre
 *
 */


int ObtenerEspacioLibreMascota(eMascota[], int);

/** \brief Se busca la mascota con el mismo id que la raza y lo muestra
 *
 * \param int: id de la raza a buscar
 * \param eMascota[]: array de mascota a recorrer
 * \param int: cantidad de elementos del array de mascotas
 * \return devuelve -1 en caso de error o 0 en caso de haber encontrado coincidencia
 *
 */


int MostarMascotasPorId(int, eMascota[], int);

/** \brief Modifica una mascota con el indice que se le pase
 *
 * \param eMascota[]: array de mascotas donde se modificara la mascota
 * \param eRaza[]: array de raza usado para validaciones
 * \param int: cantidad de elementos del array de razas
 * \param int: indice de la mascota a modificar
 * \return void
 *
 */


void ModificarMascota(eMascota[], eRaza[], int, int);
