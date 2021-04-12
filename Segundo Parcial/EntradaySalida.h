/*
 * EntradaySalida.h
 *
 *  Created on: 5 sep. 2020
 *      Author: Federico
 */

#ifndef ENTRADAYSALIDA_H_
#define ENTRADAYSALIDA_H_



#endif /* ENTRADAYSALIDA_H_ */

/**brief: ingresa una cadena de caracteres por teclado
 *
 * @param input: array de caracteres donde se ingresara la cadena
 * @param mensaje: array de caracteres que contiene mensaje a mostrar
 */


int ValidarNumeroEntero(char numero[]);

/** \brief Valida que el numero ingresado se un entero
 *
 * \param char cadena de caracteres a validar
 * \return numero entero validado
 *
 */


void IngresarDatoCadenaCaracteres(char input[], char mensaje[]);

/**brief valida que una cadena sea un numero y  la devuelve cuando sea un numero
 *
 * @param numero: cadena de caracteres con el numero a validar
 * @return numero: validado
 */

float ValidarNumeroFlotante(char numero[]);

/**
 * @fn  ValidarFlotante(float)
 * @brief Valida que el numero sea flotante
 * @param numero: numero a validar
 * @return El numero como flotante
 */
int ValidarFlotante(char numero[]);


/**brief muestra un numero entero por pantalla
 *
 * @param numero numero a mostrase por pantalla
 * @param mensaje mensaje a mostrarse por pantalla
 */
void MostrarNumeroEntero(int numero, char mensaje[]);

/** \brief Pide apretar enter para continuar despues de un mensaje
 *
 * \param
 * \param
 * \return void
 *
 */

 /** \brief muestra un numero de tipo long long int junto a un mensaje personalizado
  *
  * \param numero: numero de tipo long long int
  * \param mensaje: mensaje a mostrar
  * \return
  *
  */


void MostrarNumeroLongLong(unsigned long long int numero, char mensaje[]);

void AprieteEnter();

/** \brief Muestra un numero flotante
 *
 * \param numero: numero a mostrar
 * \param mensaje: mensaje a mostrar junto al numero
 * \return void
 *
 */

void MostrarNumeroFlotante(float numero, char mensaje[]);

/** \brief
 *
 * \param suma: resultado de la suma
 * \param resta: resultado de la resta a mostrarse
 * \param multiplicacion: resultado de la multiplicacion a mostrarse
 * \param division: resultado de la division a mostrarse
 * \param factorialPrimero: resultado del factorial del primer operando a mostrarse
 * \param factorialSegundo: resultado del factorial del segundo operando a mostrarse
 * \param denominador: el denominador de la division
 * \return void
 *
 */

void MostrarResultados(float suma, float resta, float multiplicacion, float division, unsigned long long int factorialPrimero, unsigned long long int factorialSegundo, int denominador);


/** \brief Muestra un mensaje personalizado y pide un numero
 *
 * \param char[]: mensaje personalizado a mostrarse
 * \return devuelve el numero el cual se ingreso
 *
 */


int IngresarNumeroEntero(char[]);
