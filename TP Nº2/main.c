#include <stdio.h>
#include <stdlib.h>
#define TAM 3
#include <string.h>                 // AÑADE LA BIBLIOTECA DE STRINGS
#include "Operaciones.h"
                 // AÑADE LA BIBLIOTECA DE STRINGS

//PROTOTIPO DE UNA FUNCION. FUNCION ALTA 1)



int main()
{
    eEmployee EmployeeLista[TAM];
    char opcion;

    initEmployee(EmployeeLista, TAM);           //LLAMAR A LA FUNCION
        do
    {
        printf("Elija la operacion deseada: \n");
        printf("a) Mostrar datos de los empleados ingresados\n");
        printf("b) Ingrese datos de los empleados\n");
        printf("c) Dar de baja a un empleado\n");
        printf("d) Informar empleados ordenados alfabeticamente por apellido y sector\n");
        printf("e) ------");
        printf("s) SALIR \n");
        fflush(stdin);
        scanf("%c", &opcion);

        //Aqui se arma la estructura de control del menu de opciones

        switch(opcion)
        {

        case 'a' :  printEmployees(EmployeeLista, TAM);


            break;

        case 'b' : addEmployee(EmployeeLista, TAM);


            break;
        case 'c' : removeEmployee(EmployeeLista, TAM);

            break;

        case 'd' :

            break;
        case 'e' :


            break;

        default :

            if(opcion == 's')
            {
                printf("\n Vuelva pronto! \n");
            }
            else
            {
                printf("/n Opcion incorrecta! \n");
            }

        }

        system("pause");
        system("cls");

    }
    while(opcion != 's');


    return 0;
}
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
int sorthEmployeeByName(eEmployee vec[], int size, int order)
{
    int i;
    int j;

    for(i=0; i < size -1; i++)
        {
            for(j=(i+1); j < size; j++)
                {
                    if(order == 1 && vec[i].estado == 1 && vec[j].estado == 1 && vec[i].comparacion)
                        {



                        }

                }


        }



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


