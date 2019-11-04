#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "prueba.h"


#include "utn_color.h"
#include "utn_marca.h"
#include "utn_auto.h"



/**
 * \brief Inicializa todos los campos de auto en vacio (o)
 * \param list es la lista a inicializar
 * \param tam es el tamaño de la lista
 * \return si todo salio bien 1, si no -1
 */
int inicializarAuto(Auto list[], int tam)
{
int ret = -1;
if(tam > 0)
    {
        for(int i=0; i < tam; i++)
            {
            list[i].id = 0;
            strcpy(list[i].patente, " ");
            list[i].idColor = 0;
            list[i].idMarca = 0;
            list[i].modelo = 0;
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
int buscarLibre(Auto list[], int tam)
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
 * \brief Solicita al usuario dar de alta un auto.
 * \param list es la lista de la estructura Auto
 * \param tam es el tamaño de la lista
 * \param list_M es la lista de la estructura Marca
 * \param tam_M es el tamaño de la lista de marcas
 * \param list_C es la lista de la estructura Color
 * \param tam_C es el tamaño de la lista de Color
 * \param cont es la id del auto(autoincremental)
 * \return si pudo dar de alta al Auto devuelve 1, caso contrario -1
 */
int alta_Auto(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C, int* cont)
{
int index = buscarLibre(list, tam);
int ret = -1;
int id;
if(index != -1 && tam > 0)
    {
    list[index].id = *cont;
    *cont += 1;

    printf("ingrese la patente: ");
    fflush(stdin);
    scanf("%s", list[index].patente);


    do{
    system("cls");
    printf("ingrese la ID de la marca: ");
    mostrarMarcas(list_M, tam_M);
    fflush(stdin);
    scanf("%d", &id);
    if(buscar_ID_marca(list_M, tam_M, id) != -1)
        {
        list[index].idMarca = id;
        }
    else
        {
          printf("\nERROR.\n\n");
          system("pause");
        }

      }while(buscar_ID_marca(list_M, tam_M, id) == -1);


    do{
            system("cls");
    printf("ingrese la ID del color: ");
    mostrarColores(list_C, tam_C);
    fflush(stdin);
    scanf("%d", &id);
    if(buscar_ID_color(list_C, tam_C, id) != -1)
        {
        list[index].idColor = id;
        }
    else
        {
        printf("\nERROR.\n\n");
        system("pause");
        }

    }while(buscar_ID_color(list_C, tam_C, id) == -1);

    printf("ingrese el modelo: ");
    fflush(stdin);
    scanf("%d", &list[index].modelo);


    ret = 1;
    }

return ret;
}


/**
 * \brief Muestra una lista con todos los autos cargados.
 * \param list es la lista a mostrar
 * \param tam es el tamaño de la lista
 * \param list_M es la lista de la estructura Marca
 * \param tam_M es el tamaño de la lista de marcas
 * \param list_C es la lista de la estructura Color
 * \param tam_C es el tamaño de la lista de Color
 * \return si pudo listar algun auto devuelve 1, caso contrario -1
 */
int listar_Autos(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C)
{
char color[21];
char marca[21];
int ret = -1;

if(tam > 0 && tam_C > 0 && tam_M > 0)
    {
        printf("Listado De Autos: \n\n");
        printf("ID    PATENTE     MARCA       COLOR     MODELO \n\n");
    for(int i=0; i<tam; i++)
        {
        Encontrar_Marca(list_M, tam_M, list[i].idMarca, marca);
        Encontrar_Color(list_C, tam_C, list[i].idColor, color);
        if(list[i].id != 0)
            {
            printf("%d     %s      %s      %s      %d\n", list[i].id, list[i].patente, marca, color, list[i].modelo);
            ret = 1;
            }
        }


    }
return ret;
}





/**
 * \brief Muestra lista de autos y realiza una baja logica al auto indicado.
 * \param list es la lista a mostrar
 * \param tam es el tamaño de la lista
 * \param list_M es la lista de la estructura Marca
 * \param tam_M es el tamaño de la lista de marcas
 * \param list_C es la lista de la estructura Color
 * \param tam_C es el tamaño de la lista de Color
 * \return si pudo dar de baja algun auto devuelve la direccion del auto dado de baja, caso contrario -1
 */
int baja_Auto(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C)
{
char patente[7];
char opc;
int index = -1;
printf("Ingrese la Patente del auto a dar de baja: ");
if(listar_Autos(list, tam, list_M, tam_M, list_C, tam_C) != -1)
    {
    fflush(stdin);
scanf("%s", patente);
index = buscar_Patente(list, tam, patente) ;
if(index != -1)
    {
    printf("oprima s si quiere dar de baja.");
    fflush(stdin);
    scanf("%c", &opc);
    if(opc == 's')
        list[index].id = 0;
    }
    }

return index;
}



/**
 * \brief Busca una patente igual a la pasada por parametros.
 * \param list es la lista donde buscar
 * \param tam es el tamaño de la lista
 * \param patente es la patente a comparar con la lista
 * \return si pudo encontrar alguna patente igual devuelve la direccion del auto(direccion de list), caso contrario -1
 */
int buscar_Patente(Auto list[], int tam, char patente[])
{
int ret = -1;
if(tam > 0)
    {
    for(int i=0; i<tam; i++)
        {
        if(strcmp(list[i].patente, patente) == 0)
            {
            ret = i;
            break;
            }
        }

    }
    return ret;
}




/**
 * \brief Muestra un submenu de modificacion
 * \param list es la lista de la estrucura Auto
 * \param tam es el tamaño de la lista
 * \param list_M es la lista de la estructura Marca
 * \param tam_M es el tamaño de la lista de marcas
 * \param list_C es la lista de la estructura Color
 * \param tam_C es el tamaño de la lista de Color
 * \return si pudo modificar algun auto devuelve la id del auto modificado, caso contrario -1
 */
int submenu_mod(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C)
{
int opc;
int id = -1;
int index;
char patente[7];

if(listar_Autos(list, tam, list_M, tam_M, list_C, tam_C) != -1)
    {
    printf("ingrese la patente del auto a modificar: ");
scanf("%s", patente);
index = buscar_Patente(list,tam,patente);
if(index != -1)
    {
    system("cls");
printf("1_Modificar colo.\n");
printf("2_Modiciar marca\n");
scanf("%d", &opc);

switch(opc)
{
case 1:
    do{
            system("cls");
    printf("ingrese la ID del color: ");
    mostrarColores(list_C, tam_C);
    fflush(stdin);
    scanf("%d", &id);
    if(buscar_ID_color(list_C, tam_C, id) != -1)
        {
        list[index].idColor = id;
        }
    else
        {
        printf("\nERROR.\n\n");
        system("pause");
        }

    }while(buscar_ID_color(list_C, tam_C, id) == -1);


    break;
case 2:

    do{
    system("cls");
    printf("ingrese la nueva ID de la marca: ");
    mostrarMarcas(list_M, tam_M);
    fflush(stdin);
    scanf("%d", &id);
    if(buscar_ID_marca(list_M, tam_M, id) != -1)
        {
        list[index].idMarca = id;
        }
    else
        {
          printf("\nERROR.\n\n");
          system("pause");
        }

      }while(buscar_ID_marca(list_M, tam_M, id) == -1);

    break;

default:
    printf("ERROR...");

}
    }
    }



return id;
}




/**
 * \brief Verificar si la lista de autos esta vacia o no
 * \param list es la lista a verificar
 * \param tam es el tamaño de la lista
 * \return si pudo encontrar algun auto devuelve la direccion, caso contrario -1
 */
int verificarListaAutos(Auto list[],int tam)
{
int index = -1;

if(tam > 0)
    {
    for(int i=0; i<tam; i++)
        {
        if(list[i].id != 0)
        index = i;
        }
    }
return index;

}


/**
 * \brief Ordena la lista de autos por marca, en caso de igualdad se ordenara por patente(de menor a mayor)
 * \param list es la lista a ordenar
 * \param tam es el tamaño de la lista
 * \return si pudo ordenar la lista devuelve 1, caso contrario -1
 */
int ordenarAutos(Auto list[], int tam)
{
Auto aux;
int ret = -1;

for(int i=0; i<tam-1; i++)
    {
    for(int j=i+1; j < tam; j++)
        {

        if(list[i].id != 0 && list[i].idMarca > list[j].idMarca)
            {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                    ret = 1;
            }
        if(list[i].id != 0 && list[i].idMarca == list[j].idMarca)
            {

                if(strcmp(list[i].patente, list[j].patente) > 0)
                    {

                            aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                        ret = 1;
                    }

            }


        }
    }
return ret;
}



int encontrar_Patente(Auto list[], int tam, int id,  char patente[])
{
int ret = -1;
if(tam > 0)
    {
    for(int i=0; i<tam; i++)
        {
        if(list[i].id == id)
            {
            strcpy(patente, list[i].patente);
            ret = i;
            break;
            }
        }

    }
    return ret;
}


