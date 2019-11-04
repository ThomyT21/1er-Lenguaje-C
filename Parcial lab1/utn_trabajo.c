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
 * \brief Inicializa todos los campos del trabajo en vacio (o)
 * \param list es la lista a inicializar
 * \param tam es el tamaño de la lista
 * \return si todo salio bien 1, si no -1
 */
int inicializarTrabajos(Trabajo list[], int tam)
{
int ret = -1;
if(tam > 0)
    {
        for(int i=0; i < tam; i++)
            {
            list[i].id = 0;
            strcpy(list[i].patente, " ");
            list[i].idServicio = 0;
            list[i].fecha.dia = 0;
            list[i].fecha.anio = 0;
            list[i].fecha.mes = 0;
            ret = 1;
            }
    }
return ret;
}





/**
 * \brief Busca un lugar libre dentro de la lista.
 * \param list es la lista donde buscar
 * \param tam es el tamaño de la lista
 * \return si pudo encontrar un lugar libre devuelve la direccion del lugar, si no -1
 */
int buscarTrabajoLibre(Trabajo list[], int tam)
{
int index = -1;
if(tam > 0)
    {
    for(int i=0; i<tam;i++)
        {
        if(list[i].id == 0)
            {
            index = i;
            break;
            }
        }

    }
return index;
}




/**
 * \brief Solicita al usuario dar de alta un trabajo.
 * \param list es la lista de la estructura Trabajo
 * \param tam es el tamaño de la lista
 * \param list_s es la lista de la estructura Servicio
 * \param tam_s es el tamaño de la lista de Servicio
 * \param list_a es la lista de la estructura Auto
 * \param tam_a es el tamaño de la lista de Auto
 * \param list_c es la lista de la estructura Color
 * \param tam_c es el tamaño de la lista de Color
 * \param list_m es la lista de la estructura Marca
 * \param tam_m es el tamaño de la lista de Marca
 * \return si pudo dar de alta al trabajo devuelve la direccion, caso contrario -1
 */
int alta_Trabajo(Trabajo list[], int tam, Servicio list_s[], int tam_s, Auto list_a[], int tam_a, Color list_c[], int tam_c, Marca list_m[], int tam_m)
{
    int index = -1;
    int id;
    char patente[7];
    if(tam > 0 && tam_a > 0 && tam_s > 0)
    {

        if(verificarListaAutos(list_a, tam_a) != -1)
            {
            index = buscarTrabajoLibre(list, tam);

    if(index != -1)
        {
        list[index].id = index + 1;


do{
    system("cls");
    listar_Autos(list_a, tam_a, list_m, tam_m, list_c, tam_c);
    printf("ingrese la patente: ");
    fflush(stdin);
    scanf("%s", patente);
    if(buscar_Patente(list_a, tam_a, patente) != -1)
        {
        strcpy(list[index].patente, patente);
        }
    else
        {
        printf("error...");
        system("pause");
        }

  }while(buscar_Patente(list_a, tam_a, patente) == -1);

do{ system("cls");
    mostrarServicios(list_s, tam_s);

    printf("ingrese la ID del servicio: ");
    fflush(stdin);
    scanf("%d", &id);
    if(buscar_id_servicio(list_s, tam_s, id) != -1)
        {
        list[index].idServicio =  id;
        }
    else
        {
        printf("error...");
        system("pause");
        }
}while(buscar_id_servicio(list_s, tam_s, id) == -1);

  do{
    printf("ingrese dia: ");
    scanf("%d", &list[index].fecha.dia);
    }while(list[index].fecha.dia < 1 && list[index].fecha.dia > 31);


 do{
    printf("ingrese mes: ");
    scanf("%d", &list[index].fecha.mes);
    }while(list[index].fecha.dia < 1 && list[index].fecha.dia > 12);

  do{
    printf("ingrese anio: ");
    scanf("%d", &list[index].fecha.anio);

    }while(list[index].fecha.dia < 2010 && list[index].fecha.dia > 2020);
    }

    }

            }



return index;
}







/**
 * \brief Muestra una lista con todos los trabajos cargados.
 * \param list es la lista de la estructura Trabajo
 * \param tam es el tamaño de la lista
 * \param list_s es la lista de la estructura Servicio
 * \param tam_s es el tamaño de la lista de Servicio
 * \return  si pudo listar algun auto devuelve 1, caso contrario -1
 */
int listar_Trabajos(Trabajo list[], int tam, Servicio list_s[], int tam_s)
{
char servicio[21];
int ret = -1;
if(tam > 0 && tam_s > 0)
    {

        printf("Listado de trabajos: \n\n");
        printf("ID  PATENTE     SERVICIO        FECHA\n\n");
    for(int i=0; i<tam; i++)
        {
        if(list[i].id != 0)
            {
        if(Encontrar_Servicio(list_s, tam_s, list[i].idServicio, servicio)== -1)
            printf("ERROR");
        printf("%d      %s      %s      %d/%d/%d\n", list[i].id, list[i].patente, servicio, list[i].fecha.dia, list[i].fecha.mes, list[i].fecha.anio);
        ret = 1;
            }

        }
    }

return ret;
}

