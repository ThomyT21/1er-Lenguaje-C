#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


#include "ArrayEmployees.h"
#include "Functions.h"




int initEmployees (sEmployees list[], int length)
{
    int itIsOk = -1;
    for(int i = 0; i < length; i++)
    {
        list[i].isEmpty = 1;
        itIsOk=0;
    }

    return itIsOk;
}



int findEmptyPosition(sEmployees list[], int length)
{
    int index = -1;

    for(int i=0; i < length; i++)
    {
        if( list[i].isEmpty == 1 )
        {
            index = i;
            break;
        }
    }
    return index;
}

sEmployees newEmployee(
    int id,
    char name[],
    char lastName[],
    float salary,
    int sector
)
{

    sEmployees employee;

    employee.id = id;
    strcpy (employee.name,name);
    strcpy(employee.lastName, lastName);
    employee.salary=salary;
    employee.sector=sector;
    employee.isEmpty=0;

    return employee;
}


int addEmployee(sEmployees list[], int length, int id, char name[], char lastName[],float salary,int sector)
{
    int itIsOk = -1;
    int index;
    char fullName[101];

    system("cls");

    printf("*****************Alta Empleado******************\n\n");

    index =findEmptyPosition(list,length);

    if( index == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {


        getString(name,TAMSTRING,"Ingrese nombre: ");
        convertToProperNoun(name);
        getString(lastName,TAMSTRING,"Ingrese apellido: ");
        convertToProperNoun(lastName);

        printf("Ingrese salario: ");
        scanf("%f", &salary);

        printf("Ingrese sector: ");
        scanf("%d", &sector);


        list[index] = newEmployee(id, name,lastName, salary,sector);
        itIsOk = 0;

        applyFormatToName(fullName,101, name, lastName);

        printf("El empleado %s fue dado de alta\n\n", fullName);

        itIsOk=0;
    }

    return itIsOk;
}


int findEmployeeById(sEmployees list[], int length, int id)
{

    int index = -1;

    for(int i=0; i < length; i++)
    {
        if( list[i].isEmpty==0 && list[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}




int removeEmployee(sEmployees list[], int length, int id)
{
    int itIsOk = -1;

    int index;
    char confirm;
    system("cls");
    printf("************Baja Empleado*************\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    index = findEmployeeById(list, length,id);

    if( index == -1)
    {
        printf("No existe un empleado con ese ID\n\n");

    }
    else
    {
        showEmployee(list[index]);

        printf("\n¿Confirma dar de baja?:");
        fflush(stdin);
        scanf("%c", &confirm);

        if( confirm == 's')
        {
            list[index].isEmpty = 1;
            itIsOk = 0;

        }

    }

    return itIsOk;
}






void showEmployee(sEmployees employee)
{

    printf("  %d  %3d      %10s   %10s      %.2f\n\n",employee.id,employee.sector, employee.lastName,employee.name,employee.salary);

}

int printEmployees(sEmployees list[], int length)
{

    int flag = 0;
    system("cls");

    printf(" ID  Sector     Apellido      Nombre        Salario\n\n");

    for(int i=0; i < length; i++)
    {
        if( list[i].isEmpty == 0)
        {
            showEmployee(list[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        return -1;
    }

    printf("\n\n");

    return 0;
}

int sortEmployees(sEmployees list[], int length, int order)
{

    system("cls");

    int itIsOk=-1;




    sEmployees auxEmployee;



    for(int i= 0; i < length-1 ; i++)
    {
        for(int j= i+1; j <length; j++)
        {

            if(order==1)
            {

                if(!list[i].isEmpty&&list[i].sector > list[j].sector)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;

                }
                else if (!list[i].isEmpty&&list[i].sector == list[j].sector&&strcmp(list[i].lastName,list[j].lastName)>0)
                {

                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;


                }

            }
            else
            {


                if( !list[i].isEmpty&&list[i].sector < list[j].sector)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;

                }
                else if (!list[i].isEmpty&&list[i].sector == list[j].sector&&strcmp(list[i].lastName,list[j].lastName)>0)
                {

                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;


                }

            }


        }

    }

    if (printEmployees(list,length)==-1)
    {

        printf("\n\nNo hay empleados para mostrar\n\n");
    }
    else
    {

        if(order==1)
        {
            printf("\n\nOrden por sector ascendente \n\n");
            itIsOk=0;

        }
        else if(order==2)
        {


            printf("\n\nOrden por sector descendente \n\n");
            itIsOk=0;
        }
    }


    return itIsOk;

}




int updateEmployee(sEmployees list[], int length)
{
sEmployees aux[length];

    int itIsOk = -1;
    int id;
    int index;
    system("cls");
    printf("***** Modificar Empleado *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);
    int option;


    index = findEmployeeById(list,length,id);

    if( index == -1)
    {
        printf("\n\nNo existe un empleado con ese id\n\n");


    }
    else
    {

        printf("\n");

        showEmployee(list[index]);

        printf("\n\n1- Modificar Nombre\n");
        printf("\n\n2- Modificar Apellido\n");
        printf("\n\n3- Modificar Salario\n");
        printf("\n\n4- Modificar Sector\n");
        printf("\n\n5- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &option);


        switch(option)
        {
        case 1:


            getString(aux[index].name,TAMSTRING,"\n\nIngrese nuevo nombre: ");

            convertToProperNoun(aux[index].name);

            if(!strcmp(list[index].name,aux[index].name)){


                printf("\n\nHa ingresado el mismo nombre\n\n");
                 printf("\n\nNombre no modificado\n ");


            }else{


            printf("\n\nNombre modificado\n ");

            strcpy(list[index].name, aux[index].name);
            }
            break;

        case 2:


            getString(list[index].lastName,TAMSTRING,"\n\nIngrese nuevo apellido: ");

            convertToProperNoun(list[index].lastName);
              if(!strcmp(list[index].name,aux[index].name)){


                printf("\n\nHa ingresado el mismo apellido\n\n");
                 printf("\n\nApellido no modificado\n ");


            }else{


            printf("\n\nApellido modificado\n ");
            strcpy(list[index].lastName, aux[index].lastName);
            }
            break;

        case 3:
            printf("\n\nIngrese nuevo sueldo: ");
            scanf("%f", &aux[index].salary);

            if(aux[index].salary==list[index].salary){

                printf("\n\nHa ingresado el mismo sueldo\n\n");
                 printf("\n\nSueldo no modificado\n ");

            } else{

            printf("\n\nSueldo modificado. \n");
            list[index].salary=aux[index].salary;
            }
            break;

        case 4:
            printf("\n\nIngrese nuevo sector: ");
            scanf("%d", &aux[index].sector);

             if(aux[index].sector==list[index].sector){

                printf("\n\nHa ingresado el mismo sector\n\n");
                 printf("\n\nSector no modificado\n ");

            } else{

            printf("\n\nSector modificado. \n");
            list[index].sector=aux[index].sector;
            }

            break;

        case 5:
            printf("\n\nSe ha cancelado la modificacion\n");
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        itIsOk=0;
    }


    return itIsOk;
}


void informTotalAverageQuantity(sEmployees list[], int length)
{
    system("cls");

    float acumulator=0;
    float average=0;
    int counter=0;
    int divider=0;

    for(int i=0; i<length; i++)
    {

        if(!list[i].isEmpty)
        {

            acumulator= acumulator + list[i].salary;

            divider++;
        }

    }


    if(divider!=0)
    {

        average=acumulator/divider;
    }


    for(int i=0; i<length; i++)
    {

        if(!list[i].isEmpty&&list[i].salary>average)
        {

            counter++;
        }


    }



    printf("\n\nEl total de sueldos es %2.f, el promedio %2.f y la cantidad de empleados que superan el salario promedio %d.\n\n", acumulator, average,counter);





}


void showSalary(sEmployees employee)
{

    printf("%f", employee.salary);

}

void showSalaries(sEmployees list[], int length)
{

    printf("Salarios: ");

    for(int i=0; i < length; i++)
    {

        showSalary(list[i]);
    }

}

void informs(sEmployees list[], int length)
{
    char close = 'n';
    int order;
    system("cls");
    printf("******Informes******\n\n");

    do
    {
        switch( menuInformation())
        {
        case 1:

            order=getOptionOrder();

            if(!sortEmployees(list,length,order))
            {

                printf("\n\nEmpleados ordenados exitosamente\n\n");
            }
            else
            {
                printf("\nLos empleados no fueron ordenados\n\n");
            }

            break;

        case 2:
            informTotalAverageQuantity(list,length);
            break;



        case 3:
            printf("Confirma salir?:s/n \n");
            fflush(stdin);

            close = getchar();
            close= tolower(close);

            while(!(close=='s'||close=='n'))
            {

                printf("Ingrese opción válida. Confirma salir?: s/n \n");
                fflush(stdin);

                close = getchar();
                close= tolower(close);
            }


            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(close == 'n');
}
