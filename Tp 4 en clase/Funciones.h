#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmployees.h"

#define TAM 1000
#define TAMSTRING 50

/** \brief Obtiene y valida un array de caracteres;
 * \param sEmployees list[] (array de estructura de employees)
 * \param int length  (tama�o del array)
 * \param char message []  (mensaje con el que se le indica al ususario que informaci�n debe introducir)
 */
void getString(char string [], int length, char message[]);


/** \brief Convierte en may�sculas las primeras letras de cada palabra
 * \param char string[] (cadena de caracteres que contiene las palabras)
 */
void convertToProperNoun(char string[]);


/** \brief Obtiene y valida un array de caracteres;
 * \param sEmployees list[] (array de estructura de employees)
 * \param int length  (tama�o del array)
 * \param char message []  (mensaje con el que se le indica al ususario que informaci�n debe introducir)
 */
void applyFormatToName(char fullName[], int length, char name[], char lastName[]);


/** \brief Muestra las opciones disponibles del menu principal y obtiene la opci�n elegida por el usuario
 * \return Retorna la opci�n elegida
 */
int menu();


/** \brief Muestra las opciones disponibles del submenu Informes y obtiene la opci�n elegida por el usuario
 * \return Retorna la opci�n elegida
 */
int menuInformation();

/** \brief Muestra las opciones disponibles de la secci�n de ordenamiento en el submenu Informes y obtiene la opci�n elegida por el usuario
 * \return Retorna la opci�n elegida
 */
int getOptionOrder();

