#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "Functions.h"
#include "ArrayEmployees.h"

#define TAM 1000
#define TAMSTRING 50

int main()
{
    sEmployees list [TAM];
    int id = 1;
    char name[51];
    char lastName[51];
    float salary=0;
    int sector=0;
    char close = 'n';
    int flag=0;
    int init;
    int remove;

    init = initEmployees(list,TAM);

    if (init==-1)
    {

        printf("No puede inicializarse el alta de empleados\n");

    }

    else{


        do
        {
            switch(menu())
            {
            case 1:
                if(!addEmployee(list,TAM,id,name,lastName,salary,sector))
                {

                    id++;
                    flag=1;
                } else {

                 printf("No se dio de alta ningun empleado\n\n");

                }

                break;
            case 2:
                if(flag)
                {
                  remove = removeEmployee(list,TAM,id);

                  if(!remove){

                     printf("\n\nEl empleado fue dado de baja\n\n");
                  } else {

                   printf("\n\nNo se dio de baja ningun empleado\n\n");
                  }

                }
                else
                {
                    printf("\nPara usar esta opcion tiene que dar de alta por lo menos un empleado previamente.\n");
                }
                break;

            case 3:
                if(flag)
                {
                    updateEmployee(list,TAM);

                }
                else
                {
                    printf("\nPara usar esta opcion tiene que dar de alta por lo menos un empleado previamente.\n");
                }

                break;
            case 4:

                if(flag)
                {
                    informs(list,TAM);

                }
                else
                {
                    printf("\nPara usar esta opcion tiene que dar de alta por lo menos un empleado previamente.\n");
                }

                break;

            case 5:
                printf("\nCorfirma Salida? s/n \n");
                fflush(stdin);
                close = getchar();
                close= tolower(close);


                while(!(close=='s'||close=='n'))
                {

                    printf("Ingrese opción válida. Confirma salir? s/n:\n");
                    fflush(stdin);

                    close = getchar();
                    close= tolower(close);
                }

                break;

            default:
                printf("Opcion invalida\n");
            }
            system("pause");
        }
        while(close == 'n');
    }
    return 0;
}
