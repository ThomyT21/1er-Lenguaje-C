#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "Functions.h"


void getString(char string [], int length, char message[])
{

    char auxString[100];



    printf("%s", message);
    fflush(stdin);
    gets(auxString);



    while(strlen(auxString)>length)
    {

        printf("\nError, demasiado largo. La cantidad permitida es de %d caracteres. Reingrese: ", length-1);
        fflush(stdin);
        gets(auxString);
    }

    strcpy(string, auxString);


}


void convertToProperNoun(char string[])
{

    char aux[100];
    int i=0;

    strcpy(aux,string);

    strlwr(aux);

    aux[0]=toupper(aux[0]);

    while(aux[i] != '\0')
    {

        if(aux[i]== ' ')
        {
            aux[i+1]= toupper(aux[i+1]);
        }
        i++;
    }

    strcpy(string, aux);
}

void applyFormatToName(char fullName[], int length, char name[], char lastName[])
{


    convertToProperNoun(name);
    convertToProperNoun(lastName);

    strcpy(fullName,lastName);
    strcat(fullName, ", ");
    strcat(fullName,name);

}

int menu()
{

    int option;
    system("cls");
    printf("************Menu de Opciones************\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificar Empleado\n");
    printf("4- Informes\n");
    printf("5- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &option);

    return option;
}




int menuInformation()
{



    int option;

    system("cls");
    printf("****** Informes *******\n\n");
    printf(" 1-Listar empleados por sector.\n");
    printf(" 2-Total y promedio de salarios. Empleados que superan el salario promedio.\n");
    printf(" 3-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &option);

    return option;
}


int getOptionOrder()
{

    int order;

    system("cls");

    printf("***Criterios de ordenamiento***\n\n");
    printf("1.Ordenamiento ascendente.\n");
    printf("2.Ordenamiento descendente.\n");
    printf("Elija  1 o 2: ");

    scanf("%d",&order);

    while(!(order==1||order==2))
    {
        printf("Opcion invalida. Elija 1 0 2\n");

        scanf("%d",&order);
    }
    return order;
}

