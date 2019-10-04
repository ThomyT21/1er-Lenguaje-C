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
        printf("d) Informar empleados ordenados alfabeticamente por apellido, sector y salario\n");
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

        case 'd' : sortEmployees(EmployeeLista, TAM);
                   printEmployees(EmployeeLista, TAM);
                   salario_Total(EmployeeLista, TAM);

            break;
        case 'e' : printf("Usted ha salido");


            break;

        default : printf("Opcion incorrecta");

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
