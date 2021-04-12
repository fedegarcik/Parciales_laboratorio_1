#include "LinkedList.h"
#include "stdlib.h"
#include "stdio.h"
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED


/** \brief Parsea un archivo csv a una estructura tipo concursante
 *
 * \param pFile: puntero al archivo
 * \param pConcursanteList: linkedlist a agregarse los concursantes
 * \return -1 si da error 1 si ok
 *
 */

int parser_ConcursanteFromText(FILE* pFile, LinkedList* pConcursanteList);
