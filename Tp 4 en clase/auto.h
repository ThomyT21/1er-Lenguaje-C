#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


#define TAM 1000
#define TAMSTRING 50


#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} sEmployees;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief Asigna valor 1 al entero isEmpty, indicando que esa posici�n en el array de estructuras est� vac�a, y puede as� carg�rsele datos
 * \param sEmployees list[] (array de estructura de employees)
 * \param int length  (tama�o del array)
 * \return int -1 si no se pudo ejecutar exitosamente, int 0 si se le pudo asignar 1 a los campos isEmpty
 */
 int initEmployees (sEmployees list[], int length);


/** \brief indica cu�l es la primer posici�n vac�a del array,bas�ndose en que el campo isEmpty sea verdadero o falso (en caso de quedicho campo tenga asignado el valor 1,
 *se reconocer� como vac�o.
 * \param sEmployees list[] (array d eestructuras de employees)
 * \param int length (tama�o del array)
 * \return int index= -1 si no hay una posico�n vac�a, int index con index igual al �ndice del vector cuya posici�n est� vac�a
 */
int findEmptyPosition(sEmployees list[], int length);


/** \brief Solicita los datos para dar de alta un nuevo empleado, y genera el alta
 * \param sEmployees list[] (array de estructura de employees)
 * \param int length  (tama�o del array)
 * \return int -1 si no se pudo dar de alta, int 0 si el alta fue exitosa
 */
int addEmployee(sEmployees list[], int length, int id, char name[], char lastName[],float salary,int sector);


/** \brief Encuentra un empleado dentro de un array de employees, locliz�ndolo a trav�s del ID del mismo
 * \param sEmployees list[] (array de estructura de employees)
 * \param int length  (tama�o del array)
 * \param int id (id del empleado que se desea localizar)
 * \return int -1 si no existe un empleado con ese id, int index con index igual al �ndice del vector en el que se encuentra ese empleado
 */
int findEmployeeById(sEmployees list[], int length, int id);

/** \brief Genera la baja l�gica de un empleado dentro de un array de employees(asign�ndole 1 a la posici�n isEmpty)
 * \param sEmployees list[] (array de estructura de employees)
 * \param int length  (tama�o del array)
 * \param int id (id del empleado que se desea remover)
 * \return int -1 si no existe un empleado con ese id, int index con index igual al �ndice del vector en el que se encuentra ese empleado
 */
int removeEmployee(sEmployees list[], int length, int id);

/** \brief Muestra los datos asignados a una posici�n determinada de un array de employees (id, nombre, apellido, salario, sector)
 * \param sEmployees list[] (array de estructura de employees)
 */
void showEmployee(sEmployees employee);


/** \brief Muestra los datos (id, nombre, apellido, salario, sector) de todo empleado activo dentro de un array employees
 * \param sEmployees list[] (array de estructura de employees)
 * \param int length  (tama�o del array)
 * \return int -1 si no hay empleados para mostrar, int 0 si los hay
 */
int printEmployees(sEmployees list[], int length);


/** \brief Ordena por sector de manera ascendente o descendente a los empleados activos de un array employees. Adem�s los ordena alfab�ticamente dentro de cada sector
 * \param sEmployees list[] (array de estructura de employees)
 * \param int length  (tama�o del array)
 * \param int order 1, si el orden es ascendente, 2 si es descendente
 * \return int -1 si el orden no pudo concretarse, int 0 si fue exitoso
 */
int sortEmployees(sEmployees list[], int length, int order);



/** \brief Permite actualizar nombre, apellido sector y salario de un empleado activo
 * \param sEmployees list[] (array de estructura de employees)
 * \param int length  (tama�o del array)
 * \return int -1 si no se actualiz� ning�n dato, int 0 si fue actualizado con �xito.
 */
int updateEmployee(sEmployees list[], int length);


/** \brief Obtiene y muestra la suma de todos los sueldos, el promedio, y la cantidad d eempleados de un array employee que superan ese promedio
 * \param sEmployees list[] (array de estructura de employees)
 * \param int length  (tama�o del array)
 */
void informTotalAverageQuantity(sEmployees list[], int length);



/** \brief Obtiene los datos para operar con el men� de informes
 * \param sEmployees list[] (array de estructura de employees)
 * \param int length  (tama�o del array)
 */
void informs(sEmployees list[], int length);


/** \brief Muestra el salario de un empleado
 * \param sEmployees employee (empleado)
 */
void showSalary(sEmployees employee);


/** \brief Muestra los salarios de los empleados de un array de employees
 * \param sEmployees list[] (array de estructura de employees)
 * \param int length  (tama�o del array)
 */
void showSalaries(sEmployees list[], int length);
