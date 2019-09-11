#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_Array.h"
#include "UTN_Imputs.h"

#define QTY_CLIENTES 4
#define MSG_INGRESONOM "Ingrese un nombre: "
#define MSG_INGRESOAP "Ingrese un apellido: "

int main()
{
    int i;
    char arrayNombres[QTY_CLIENTES][50];
    char arrayApellidos[QTY_CLIENTES][50];
    char auxNombre[50];
    char auxApellido[50];

    //CARGAR LOS NOMBRES

    for(i=0; i<QTY_CLIENTES; i++)
        {

            getString(MSG_INGRESONOM, auxNombre);
            // arrayNombres[i] = arrayNombre; NOOO
//MATRIZ DE NOMBRES CARGADOS AGARRA TODO LO QUE ENCUENTRA EN ESTE VECTOR Y LO PONE EN OTRO LADO POCISION POR POCISION COPIANDOLO AL 1ER PARAMETRO
            strcpy(arrayNombres[i], auxNombre]);
        }
        printArrayStr(arrayNombres;QTY_CLIENTES);

        for(i=0; i<QTY_CLIENTES;i++)
            {
                getString(MSG_INGRESOAP,auxApellido);
                strcpy(arrayApellidos[i],auxApellido);
            }
        printArrayStr(arrayApellidos;QTY_CLIENTES);

        for(i=0;i<QTY_CLIENTES;i++)
            {
                printf("\n%s - %s - %d", arrayNombres[i], arrayApellidos[i],i);
            }
        Ordenar2ArrayStr


    return 0;
}
