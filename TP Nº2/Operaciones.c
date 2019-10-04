#include <stdio.h>
#include <stdlib.h>
#include <string.h>                 // AÑADE LA BIBLIOTECA DE STRINGS
#include "Operaciones.h"




int addEmployee(eEmployee vec[], int size)
{
    int i;
    for(i=0; i < size; i++)
        {
            printf("Ingrese la id\n");
            fflush(stdin);
            scanf("%d", &vec[i].id);
            fflush(stdin);

            printf("Ingrese nombre\n");
            scanf("%s", vec[i].nombre);
            fflush(stdin);

            printf("Ingrese apellido\n");
            scanf("%s", vec[i].apellido);
            fflush(stdin);

            printf("Ingrese salario\n");
            scanf("%f", &vec[i].salario);
            fflush(stdin);

            printf("Ingrese sector\n");
            scanf("%d", &vec[i].sector);
            fflush(stdin);

            printf("Ingrese el estado\n");
            scanf("%d", &vec[i].estado);
            fflush(stdin);

        }
    return 0;

}
int initEmployee(eEmployee vec[], int size)
{
    int i;
    for(i=0; i < size; i++)
        {
            vec[i].id = 0;
            vec[i].salario = 0;
            vec[i].estado = 0;
            vec[i].sector = 0;

            strcpy(vec[i].nombre, "");
            strcpy(vec[i].apellido, "");
        }

        return 0;
}
int printEmployee(eEmployee empleado)
{
    if(empleado.estado != 0)
    printf("La id: %d nombre: %s Apellido: %s: salario: %.2f estado: %d sector: %d\n", empleado.id, empleado.nombre, empleado.apellido, empleado.salario, empleado.estado, empleado.sector);
    return 0;
}



int printEmployees(eEmployee vec[], int size)
{
    int i;
    for(i=0; i < size; i++)

        {
            printEmployee(vec[i]);

        }

    return 0;

}
int removeEmployee(eEmployee vec[], int size)
{

    int id;
    int direccion;
    printEmployees(vec, size);
    printf("Ingrese la id del empleado a dar de baja\n");
    fflush(stdin);
    scanf("%d",&id);
    direccion = findEmployeeById(vec,size, id);        // CARGAR UNA VARIABLE

        if(direccion != -1)
            {
                vec[direccion].estado = 0;
            }
        else
            {
                printf("id no encontrada\n");
            }

    return 0;

}
int findEmployeeById(eEmployee vec[], int size, int id)
{
    int i;
    int aux = -1;
    for(i=0; i < size; i++)
        {
            if(vec[i].id == id)
            aux = i;
            break;          // BREAK SE USA PARA CORTAR FOR, SWITCH Y TODO LO QUE SEA IGUAL
        }
    return aux;

}

int buscar_Libre(eEmployee vec[], int size)
{
    int i;
    int aux = -1;
    for(i=0; i < size; i++)
        {
            if(vec[i].estado == 0)
                {
                    aux = i;
                    break;
                }


        }


    return aux;
}

int modificar_Empleado(eEmployee vec[], int t,int id)

{
    int estado = -1;
    int index;
    int E_sector;
    char E_nombre[30];
    char E_apellido[30];
    float E_salario;

    index = findEmployeeById(eEmployee,t,id);

   if (index != -1)
   {

        printf("Ingrese un sector: ");
        scanf("%d", &E_sector);
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(E_nombre);
        printf("Ingrese un apellido: ");
        fflush(stdin);
        gets(E_apellido);
        printf("Ingrese un salario: ");
        scanf("%f", &E_salario);

        eEmployee[index].sector = E_sector;
        eEmployee[index].salario = E_salario;
        strcpy(eEmployee[index].nombre,E_nombre);
        strcpy(eEmployee[index].apellido,E_apellido);

        estado = 0;



   }


    return estado;
}

int comparacion(char letra1, char letra2)
{
int retor;
if(letra1 < letra2)
    retor = -1;
if(letra1 > letra2)
    retor = 1;
if(letra1 == letra2)
    retor = 0;

    return retor;
}

int sorthEmployees(eEmployee* list, int len, int order)
{
    int retorno = -1;
    if((list != NULL) && (len > 0))
    {
        if(order==1)
        {
            ordenarArrayAscendiente(list,len);
            retorno=0;
        }
        else if(order==0)
        {
            ordenarArrayDescendiente(list,len);
            retorno=0;
        }
    }
    return retorno;



}
int comparacion(char letra1, char letra2)
{
int retor;
if(letra1 < letra2)
    retor = -1;
if(letra1 > letra2)
    retor = 1;
if(letra1 == letra2)
    retor = 0;

    return retor;
}
float salario_Total(eEmployee vec[], int t)

{

    int i;
    float total=0;

    for (i=0;i<t;i++)
    {

        if (eEmployee[i].estado == 1)
        {
            total += eEmployee[i].salario;


        }
    }
    return total;
}
float promedio(eEmployee vec[], int t)

{
    int i;
    int cont = 0;
    float total;
    float prom;

    total = salario_Total(eEmployee,t);

     for (i=0;i<t;i++)
    {

        if (eEmployee[i].estado == 1)
        {
            cont++;
        }
    }

    prom = total / cont;

    return prom;
}
