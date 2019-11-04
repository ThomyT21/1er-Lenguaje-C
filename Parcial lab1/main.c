#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


#include "utn_color.h"
#include "utn_marca.h"
#include "utn_auto.h"
#include "utn_servicio.h"
#include "utn_trabajo.h"


#define TAM_AUTOS 10
#define TAM_TRAB 100
#define ENCERADO 20002
#define BLANCO 5001






void menu();
int mostrarAutosXcolor(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C, int idcolor);
int mostrarAutosXmarca(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C, int idmarca);
int listar_TrabajosXauto(Trabajo list[], int tam, Servicio list_s[], int tam_s, char patente[]);
int mostrarAutos_SinTrabajo(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C, Trabajo list_T[], int tam_T);
int buscar_Patente_Trabajo(Trabajo list[], int tam, char patente[]);
int pedir_marca(Marca list_M[], int tam_M);
int informe_importeTotalXauto(Trabajo list[], int tam, Servicio list_s[], int tam_s, char patente[]);
int pedir_auto(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C);
int serviciosMasPedidos(Trabajo list[],int tam);
int mostrarServicios_MasPedido(Servicio list[], int tam, Trabajo list_T[], int tam_T);
void submenu_informes(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C, Servicio list_S[], int tam_S, Trabajo list_T[], int tam_T);
int mostrarEnceradoFecha(Auto list[], int tam, Servicio list_S[], int tam_S, Trabajo list_T[], int tam_T, Marca list_M[], int tam_M, Color list_C[], int tam_C);
int listar_Trabajos_Autos_Blancos(Trabajo list[], int tam, Servicio list_s[], int tam_s, Auto list_a[], int tam_a);
int main()
{
    char opc;
    int id = 1001;

     Marca lista_Marcas[5] = { {1000, "Renault"},{1001,"Fiat"},{1002, "Ford"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};
    Color lista_Colores[5] = { {5000, "Negro"},{5001,"Blanco"},{5002, "Gris"}, {5003, "Rojo"}, {5004, "Azul"}};
    Servicio lista_Servicios[4] = { {20000, "Lavado", 250},{20001,"Pulido", 300},{20002, "Encerado", 400}, {20003, "Completo", 600}};
    Auto lista_autos[TAM_AUTOS];
    Trabajo lista_trabajos[TAM_TRAB];
    inicializarTrabajos(lista_trabajos, TAM_TRAB);
    inicializarAuto(lista_autos, TAM_AUTOS);


  do{
    menu();
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &opc);
    opc =tolower(opc);

    switch(opc)
    {
        case 'a':
            if(alta_Auto(lista_autos, TAM_AUTOS, lista_Marcas, 5, lista_Colores, 5, &id) == -1)
                printf("no hay mas lugar...\n");
            break;
        case 'b':
            if(submenu_mod(lista_autos, TAM_AUTOS, lista_Marcas, 5, lista_Colores, 5) == -1)
                printf("modificacion cancelada...\nASEGURESE DE CARGAR MINIMO UN AUTO ANTES DE MODIFICAR.\n\n");
            break;
        case 'c':
            if(baja_Auto(lista_autos, TAM_AUTOS, lista_Marcas, 5, lista_Colores, 5)== -1)
                printf("baja cancelada...\nASEGURESE DE CARGAR MINIMO UN AUTO ANTES DE MODIFICAR.\n\n");
            break;
        case 'd':
            ordenarAutos(lista_autos, TAM_AUTOS);
            if(listar_Autos(lista_autos, TAM_AUTOS, lista_Marcas, 5, lista_Colores, 5)== -1)
                printf("no hay autos cargados...\n");

            break;
        case 'e':
            if(mostrarMarcas(lista_Marcas, 5) == -1)
                printf("no hay marcas cargados...\n");
            break;
        case 'f':
            if(mostrarColores(lista_Colores, 5)== -1)
                printf("no hay colores cargados...\n");
            break;
        case 'g':
            mostrarServicios(lista_Servicios, 4);
            break;
        case 'h':
            if(alta_Trabajo(lista_trabajos, TAM_TRAB, lista_Servicios, 4, lista_autos, TAM_AUTOS, lista_Colores, 5,lista_Marcas, 5) == -1)
                printf("\nNO HAY trabajos CARGADOS\n\n");
            break;
        case 'i':
            if(listar_Trabajos(lista_trabajos, TAM_TRAB, lista_Servicios, 4) == -1)
                printf("\nNO HAY TRABAJOS QUE MOSTRAR\n\n");
            break;

        case 'j':
            submenu_informes(lista_autos, TAM_AUTOS, lista_Marcas, 5, lista_Colores, 5, lista_Servicios, 4, lista_trabajos, TAM_TRAB);
            break;

        case 's':
            printf("vuelva a oprimir S para salir: ");
            fflush(stdin);
            scanf("%c", &opc);
            opc =tolower(opc);
            break;
        default:
            printf("opcion no valida...\n\n");



    }
    system("pause");
    system("cls");
    }while(opc != 's');

    return 0;
}


void menu()
{
printf("     *** ABM ***    \n");
printf("A_Alta auto.\n");
printf("B_Modificar Auto.\n");
printf("C_Baja Auto.\n");
printf("D_Listar Autos.\n");
printf("E_Listar Marcas.\n");
printf("F_Listar Colores.\n");
printf("G_Listar Servicios.\n");
printf("H_Alta Trabajo.\n");
printf("I_Listar Trabajos.\n");
printf("J_INFORMES.\n");
printf("oprima s para salir\n");
}


void sub_menu()
{
printf("     *** INFORMES ***    \n");
printf("A_Mostrar autos de color negro.\n");
printf("B_Mostrar autos de una marca seleccionada.\n");
printf("C_Mostrar todos los trabajos efectuados al auto seleccionado.\n");
printf("D_Listar los autos que no tuvieron trabajos.\n");
printf("E_Informar importe total de los trabajos realizados a un auto seleccionado.\n");
printf("F_Mostrar el servicio mas pedido.\n");
printf("G_Mostrar todos los autos que realizaron un encerado y la fecha.\n");
printf("k_Trabajos realizados a autos blancos.\n");
printf("oprima s para salir\n");
}



void submenu_informes(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C, Servicio list_S[], int tam_S, Trabajo list_T[], int tam_T)
{
char opc;
int index_auto = -1;
int idmarca;
char patente[7];





    system("cls");
    sub_menu();
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &opc);
    opc =tolower(opc);

    switch(opc)
    {
        case 'a':
            if(mostrarAutosXcolor(list, tam, list_M, tam_M, list_C, tam_C, 5000) == -1)
                printf("NO HAY AUTOS DE COLOR NEGRO.\n\n");
            break;
        case 'b':
            idmarca = pedir_marca(list_M, tam_M);
            if(idmarca != -1)
            if(mostrarAutosXmarca(list, tam, list_M, tam_M, list_C, tam_C, idmarca) == -1 )
                printf("NO AUTOS DE LA MARCA ELEGIDA.\n\n");
            break;
        case 'c':
            index_auto = pedir_auto(list, tam, list_M, tam_M, list_C, tam_C);
            if(index_auto != -1)
            encontrar_Patente(list, tam, list[index_auto].id, patente);
            if(listar_TrabajosXauto(list_T, tam_T, list_S, tam_S, patente) == -1)
                printf("NO HAY TRABAJOS DEL AUTO ELEGIDO.\n\n");

            break;
        case 'd':
            if(mostrarAutos_SinTrabajo(list, tam, list_M, tam_M, list_C, tam_C, list_T, tam_T ) == -1)
                printf("NO HAY AUTOS SIN TRABAJOS.\n\n");
            break;
        case 'e':
            index_auto = pedir_auto(list, tam, list_M, tam_M, list_C, tam_C);
            if(index_auto != -1){
            encontrar_Patente(list, tam, list[index_auto].id, patente);
            informe_importeTotalXauto(list_T, tam_T, list_S, tam_S, patente);
                }printf("NO HAY AUTOS PARA HACER EL INFORME.\n\n");
            break;
        case 'f':
            if(mostrarServicios_MasPedido(list_S, tam_S, list_T, tam_T) == -1)
                printf("NO HAY TRABAJOS CARGADOS.\n\n");
            break;
        case 'g':
            if(mostrarEnceradoFecha(list, tam, list_S, tam_S, list_T, tam_T, list_M, tam_M, list_C, tam_C) == -1)
                printf("NO HAY AUTOS.\n\n");
            break;
        case 'k':
            if(listar_Trabajos_Autos_Blancos(list_T, tam_T, list_S, tam_S, list, tam) == -1)
                printf("NO HAY AUTOS.\n\n");
            break;
        default:
            printf("opcion no valida...\n\n");



    }




}








/**
 * \brief Muestra una lista con todos los autos del color pasado por parametro.
 * \param list es la lista a mostrar
 * \param tam es el tamaño de la lista
 * \param list_M es la lista de la estructura Marca
 * \param tam_M es el tamaño de la lista de marcas
 * \param list_C es la lista de la estructura Color
 * \param tam_C es el tamaño de la lista de Color
 * \return si pudo listar algun auto devuelve 1, caso contrario -1
 */
int mostrarAutosXcolor(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C, int idcolor)
{

char color[21];
char marca[21];
int ret = -1;

if(tam > 0 && tam_C > 0 && tam_M > 0)
    {
        printf("Listado De Autos por color: \n\n");
        printf("ID    PATENTE     MARCA       COLOR     MODELO \n\n");
    for(int i=0; i<tam; i++)
        {
        Encontrar_Marca(list_M, tam_M, list[i].idMarca, marca);
        Encontrar_Color(list_C, tam_C, list[i].idColor, color);
        if(list[i].id != 0 && list[i].idColor == idcolor)
            {
            printf("%d     %s      %s      %s      %d\n", list[i].id, list[i].patente, marca, color, list[i].modelo);
            ret = 1;
            }
        }


    }
return ret;
}




/**
 * \brief Muestra una lista con todos los autos de la marca pasada por parametro.
 * \param list es la lista a mostrar
 * \param tam es el tamaño de la lista
 * \param list_M es la lista de la estructura Marca
 * \param tam_M es el tamaño de la lista de marcas
 * \param list_C es la lista de la estructura Color
 * \param tam_C es el tamaño de la lista de Color
 * \return si pudo listar algun auto devuelve 1, caso contrario -1
 */
int mostrarAutosXmarca(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C, int idmarca)
{
char color[21];
char marca[21];
int ret = -1;

if(tam > 0 && tam_C > 0 && tam_M > 0)
    {
        printf("Listado De Autos por marca: \n\n");
        printf("ID    PATENTE     MARCA       COLOR     MODELO \n\n");
    for(int i=0; i<tam; i++)
        {
        Encontrar_Marca(list_M, tam_M, list[i].idMarca, marca);
        Encontrar_Color(list_C, tam_C, list[i].idColor, color);
        if(list[i].id != 0 && list[i].idMarca == idmarca)
            {
            printf("%d     %s      %s      %s      %d\n", list[i].id, list[i].patente, marca, color, list[i].modelo);
            ret = 1;
            }
        }


    }
return ret;
}






/**
 * \brief Muestra una lista con todos los trabajos de un auto.
 * \param list es la lista de la estructura Trabajo
 * \param tam es el tamaño de la lista
 * \param list_s es la lista de la estructura Servicio
 * \param tam_s es el tamaño de la lista de Servicio
 * \return  si pudo listar algun auto devuelve 1, caso contrario -1
 */
int listar_TrabajosXauto(Trabajo list[], int tam, Servicio list_s[], int tam_s, char patente[])
{
char servicio[21];
int ret = -1;
if(tam > 0 && tam_s > 0)
    {

        printf("Listado de todos los trabajos de un auto: \n\n");
        printf("ID  PATENTE     SERVICIO        FECHA\n\n");
    for(int i=0; i<tam; i++)
        {
        if(list[i].id != 0 && strcmp(list[i].patente, patente) == 0)
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






/**
 * \brief Busca una patente igual a la pasada por parametros.
 * \param list es la lista donde buscar
 * \param tam es el tamaño de la lista
 * \param patente es la patente a comparar con la lista
 * \return si pudo encontrar alguna patente igual devuelve la direccion del auto(direccion de list), caso contrario -1
 */
int buscar_Patente_Trabajo(Trabajo list[], int tam, char patente[])
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
 * \brief Muestra una lista con todos los autos de la marca pasada por parametro.
 * \param list es la lista a mostrar
 * \param tam es el tamaño de la lista
 * \param list_M es la lista de la estructura Marca
 * \param tam_M es el tamaño de la lista de marcas
 * \param list_C es la lista de la estructura Color
 * \param tam_C es el tamaño de la lista de Color
 * \return si pudo listar algun auto devuelve 1, caso contrario -1
 */
int mostrarAutos_SinTrabajo(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C, Trabajo list_T[], int tam_T)
{
char color[21];
char marca[21];
int ret = -1;

if(tam > 0 && tam_C > 0 && tam_M > 0)
    {
        printf("Listado De Autos sin trabajo: \n\n");
        printf("ID    PATENTE     MARCA       COLOR     MODELO \n\n");
    for(int i=0; i<tam; i++)
        {
        Encontrar_Marca(list_M, tam_M, list[i].idMarca, marca);
        Encontrar_Color(list_C, tam_C, list[i].idColor, color);
        if(list[i].id != 0 && buscar_Patente_Trabajo(list_T, tam_T, list[i].patente) == -1)
            {
            printf("%d     %s      %s      %s      %d\n", list[i].id, list[i].patente, marca, color, list[i].modelo);
            ret = 1;
            }
        }


    }
return ret;
}



/**
 * \brief Muestra una lista con todos los trabajos de un auto y su importe total.
 * \param list es la lista de la estructura Trabajo
 * \param tam es el tamaño de la lista
 * \param list_s es la lista de la estructura Servicio
 * \param tam_s es el tamaño de la lista de Servicio
 * \param patente es la patente a comparar con la lista
 * \return  si pudo listar algun auto devuelve 1, caso contrario -1
 */
int informe_importeTotalXauto(Trabajo list[], int tam, Servicio list_s[], int tam_s, char patente[])
{
char servicio[21];
int idServicio;
int ret = -1;
float precio = 0;
if(tam > 0 && tam_s > 0)
    {

        printf("Informe del importe total de los trabajos del auto: \n\n");
        printf("ID  PATENTE     SERVICIO        FECHA\n\n");
    for(int i=0; i<tam; i++)
        {
        if(list[i].id != 0 && strcmp(list[i].patente, patente) == 0)
            {
                idServicio = buscar_id_servicio(list_s, tam_s, list[i].idServicio);
                precio += list_s[idServicio].precio;
        if(Encontrar_Servicio(list_s, tam_s, list[i].idServicio, servicio)== -1)
            printf("ERROR");
        printf("%d      %s      %s      %d/%d/%d\n", list[i].id, list[i].patente, servicio, list[i].fecha.dia, list[i].fecha.mes, list[i].fecha.anio);
        ret = 1;
            }

        }
        printf("\n\nIMPORTE TOTAL: %.2f\n\n", precio);
    }

return ret;
}





/**
 * \brief busca el servicio mas pedido y devuelve id
 * \param list es la lista a verificar
 * \param tam es el tamaño de la lista
 * \return si pudo encontrar algun auto devuelve la direccion del servicio, caso contrario -1
 */
int serviciosMasPedidos(Trabajo list[],int tam)
{
int index = -1;
int Lavado = 0;
int Pulido = 0;
int Encerado = 0;
int Completo = 0;


if(tam > 0)
    {
    for(int i=0; i<tam; i++)
        {
    if(list[i].id != 0)
        {
        if(list[i].idServicio == 20000)
        Lavado ++;
        if(list[i].idServicio == 20001)
        Pulido ++;
        if(list[i].idServicio == 20002)
        Encerado ++;
        if(list[i].idServicio == 20003)
        Completo ++;
        }

        }

if(Lavado != 0 || Pulido != 0 || Encerado != 0 ||Completo != 0)
        {
        if(Lavado >= Pulido && Lavado >= Encerado && Lavado >= Completo)
        index = 20000;
        if(Pulido >= Lavado && Pulido >= Encerado && Pulido >= Completo)
        index = 20001;
        if(Encerado >= Lavado && Encerado >= Pulido && Encerado >= Completo)
        index = 20002;
        if(Completo >= Lavado && Completo >= Pulido && Completo >= Encerado)
        index = 20003;

        }
    else{
        index = -1;
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
int mostrarServicios_MasPedido(Servicio list[], int tam, Trabajo list_T[], int tam_T)
{
    int ret = -1;
    int idservicio;
    idservicio = serviciosMasPedidos(list_T,tam_T);
if(tam > 0 && idservicio != -1)
    {
    printf("EL SERVICIO MAS PEDIDO ES: \n\n");
    printf("ID     DESCRIPCION     PRECIO\n\n");
    for(int i=0; i<tam; i++)
        {
        if(list[i].id == idservicio)
            {
            printf("%d      %s      %.2f\n", list[i].id, list[i].descripcion, list[i].precio);
            ret = 1;
            }
        }
    }
    return ret;
}



int pedir_marca(Marca list_M[], int tam_M)
{
    int id = -1;
do{
    system("cls");
    printf("ingrese la ID de la marca: ");
    mostrarMarcas(list_M, tam_M);
    fflush(stdin);
    scanf("%d", &id);

      }while(buscar_ID_marca(list_M, tam_M, id) == -1);
      return id;
}


int pedir_auto(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C)
{

int index = -1;
char patente[7];

if(listar_Autos(list, tam, list_M, tam_M, list_C, tam_C) != -1)
    {


            printf("ingrese la patente del auto: ");
            scanf("%s", patente);
            index = buscar_Patente(list,tam,patente);

    }
return index;
}




int mostrarEnceradoFecha(Auto list[], int tam, Servicio list_S[], int tam_S, Trabajo list_T[], int tam_T, Marca list_M[], int tam_M, Color list_C[], int tam_C)
{
char color[21];
char marca[21];
int index;
int ret = -1;

if(tam > 0 && tam_S > 0 && tam_T > 0 && tam_C > 0 && tam_M > 0)
    {
    printf("Listado De Autos que realizaron un encerado: \n\n");
    printf("ID    PATENTE     MARCA       COLOR     MODELO     SERVICIO    FECHA \n\n");

    for(int i=0; i<tam; i++)
        {

        index = buscar_Patente_Trabajo(list_T, tam_T, list[i].patente);
        Encontrar_Marca(list_M, tam_M, list[i].idMarca, marca);
        Encontrar_Color(list_C, tam_C, list[i].idColor, color);

        if(list[i].id != 0 && list_T[index].idServicio == ENCERADO)
            {
                printf("%d     %s      %s      %s      %d       Encerado      %d/%d/%d\n", list[i].id, list[i].patente, marca, color, list[i].modelo, list_T[index].fecha.dia, list_T[index].fecha.mes, list_T[index].fecha.anio);
                ret = 1;
            }
        }


    }
return ret;


}



int listar_Trabajos_Autos_Blancos(Trabajo list[], int tam, Servicio list_s[], int tam_s, Auto list_a[], int tam_a)
{
char servicio[21];
int index;
int ret = -1;
if(tam > 0 && tam_s > 0)
    {

    printf("Listado de trabajos a autos blancos: \n\n");
    printf("ID  PATENTE     SERVICIO        FECHA\n\n");
    for(int i=0; i<tam; i++)
        {
        if(list[i].id != 0 )
            {
                index = buscar_Patente(list_a, tam_a, list[i].patente);
                Encontrar_Servicio(list_s, tam_s, list[i].idServicio, servicio);

                if(list_a[index].idColor == BLANCO)
                printf("%d      %s      %s      %d/%d/%d\n", list[i].id, list[i].patente, servicio, list[i].fecha.dia, list[i].fecha.mes, list[i].fecha.anio);
                ret = 1;
            }

        }
    }

return ret;
}






