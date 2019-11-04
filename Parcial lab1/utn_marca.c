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
 * \brief Muestra una lista con todas las marcas cargadas.
 * \param list es la lista a mostrar
 * \param tam es el tamaño de la lista
 * \return si pudo mostrar alguna marca devuelve 1, caso contrario -1
 */
int mostrarMarcas(Marca list[], int tam)
{
int ret = -1;
if(tam > 0)
    {
        printf("\n\nListado De Marcas: \n\n");
        printf("ID        Marca\n\n");
    for(int i=0; i < tam;i++)
        {
        printf("%d      %s\n", list[i].id, list[i].descripcion);
        ret = 1;
        }

    }
return ret;
}





/**
 * \brief Busca en la lista de marcas una id igual a la pasada por parametro.
 * \param list es la lista donde buscar
 * \param tam es el tamaño de la lista
 * \param id es la id a comparar con la lista
 * \return si pudo encontrar una id igual devuelve la direccion del color, caso contrario -1
 */
int buscar_ID_marca(Marca list[],int tam,int id)
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




/**
 * \brief Busca la marca por una id, carga al parametro Marca con la marca encontrada
 * \param list es la lista donde buscar
 * \param tam es el tamaño de la lista
 * \param id es la id a comparar con la lista
 * \param Marca es donde se cargara la marca buscada
 * \return si pudo cargar la marca correctamente devolvera la direccion de la marca, caso contrario -1
 */
int Encontrar_Marca(Marca list[],int tam,int id, char Marca[])
{
    int index = -1;
if(tam > 0)
    {
    index = buscar_ID_marca(list, tam, id);
    if(index != -1)
        {
        strcpy(Marca, list[index].descripcion);
        }
    }
return index;
}

