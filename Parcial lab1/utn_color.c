#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "prueba.h"


#include "utn_color.h"
#include "utn_marca.h"
#include "utn_auto.h"
#include "utn_servicio.h"
#include "utn_trabajo.h"

/**
 * \brief Muestra una lista con todos los colores cargados.
 * \param list es la lista a mostrar
 * \param tam es el tamaño de la lista
 * \return si pudo mostrar algun color devuelve 1, caso contrario -1
 */
int mostrarColores(Color list[], int tam)
{
int ret = -1;
if(tam > 0 && list != NULL)
    {
        printf("\n\nListado De Colores: \n\n");
        printf("ID        Color\n");
    for(int i=0; i < tam;i++)
        {

        printf("%d      %s\n", list[i].id, list[i].nombre);
        ret = 1;
        }

    }
return ret;
}



/**
 * \brief Busca en la lista de colores una id igual a la pasada por parametro.
 * \param list es la lista donde buscar
 * \param tam es el tamaño de la lista
 * \param id es la id a comparar con la lista
 * \return si pudo encontrar una id igual devuelve la direccion del color, caso contrario -1
 */
int buscar_ID_color(Color list[],int tam,int id)
{
int ret = -1;
if(tam > 0 && list != NULL)
    {
    for(int i=0; i<tam; i++)
        {
        if(list[i].id == id)
            {
            ret = i;
            break;
            }
        }

    }
    return ret;
}





/**
 * \brief Busca el color por una id, la coloca el nombre del color en el parametro color.
 * \param list es la lista donde buscar
 * \param tam es el tamaño de la lista
 * \param id es la id a comparar con la lista
 * \param color es donde se cargara el color buscado
 * \return si pudo cargar el color correctamente devolvera la direccion del color, caso contrario -1
 */
int Encontrar_Color(Color list[],int tam,int id, char Color[])
{
    int index = -1;
if(tam > 0 && list != NULL)
    {
    index = buscar_ID_color(list, tam, id);
    if(index != -1)
        {
        strcpy(Color, list[index].nombre);
        }
    }
return index;
}

