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
 * \brief Busca el servicio por una id, carga al parametro servicio con el servicio encontrado
 * \param list es la lista donde buscar
 * \param tam es el tamaño de la lista
 * \param id es la id a comparar con la lista
 * \param servicio es donde se cargara el servicio buscado
 * \return si pudo cargar el servicio correctamente devolvera la direccion del servicio, caso contrario -1
 */
int Encontrar_Servicio(Servicio list[],int tam,int id, char servicio[])
{
    int index = -1;
if(tam > 0)
    {
    index = buscar_id_servicio(list, tam, id);
    if(index != -1)
        {
        strcpy(servicio, list[index].descripcion);
        }
    }
return index;
}




/**
 * \brief Muestra una lista con todos los servicios cargados.
 * \param list es la lista a mostrar
 * \param tam es el tamaño de la lista
 * \return si pudo mostrar algun servicio devuelve 1, caso contrario -1
 */
int mostrarServicios(Servicio list[], int tam)
{
    int ret = -1;
if(tam > 0)
    {
    printf("ID     DESCRIPCION     PRECIO\n\n");
    for(int i=0; i<tam; i++)
        {
        printf("%d      %s      %.2f\n", list[i].id, list[i].descripcion, list[i].precio);
        ret = 1;
        }
    }
    return ret;
}






/**
 * \brief Busca en la lista de servicios una id igual a la pasada por parametro.
 * \param list es la lista donde buscar
 * \param tam es el tamaño de la lista
 * \param id es la id a comparar con la lista
 * \return si pudo encontrar una id igual devuelve la direccion del servicio, caso contrario -1
 */
int buscar_id_servicio(Servicio list[], int tam,int id)
{
int ret = -1;
if(tam > 0)
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



