#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED

/** \brief controla la carga de texto desde el archivo
 *
 * \param path: directorio al archivo
 * \param pArrayConcursantes: linkedlist donde se guardaran los concursantes
 * \return -1 si da error 0 si ok
 *
 */


int controller_loadFromText(LinkedList* pArrayConcursantes);


/** \brief lista los empleados
 *
 * \param
 * \param
 * \return
 *
 */

int controller_ListEmployee(LinkedList* pArrayConcursante);

int controller_SaveAsText(char* path, LinkedList* pArrayConcursantes);

//int controller_whichToLoad(char* path);

int controler_saveAproved(LinkedList* this);

int controller_SaveWinners(LinkedList* pArrayConcursantes);

