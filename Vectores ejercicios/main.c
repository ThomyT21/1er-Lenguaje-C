#include <stdio.h>
#include <stdlib.h>
#include "UTN_Array.h"
#include "UTN_Inputs.h"

#define CANT_EL 4           //CONTSTANTE DONDE SE REEMPLAZA EL NUMERO 4

int cargarSetDatos(int* aLegajo, char* aSexo, int* aEdad, int* aNota1p, int* aNota2p, float* aPromedio, int limite)
int mostrarEstudiante(int* aLegajo, char* aSexo, int* aEdad, int* aNota1p, int* aNota2p, float* aPromedio, int limite)                 //PROTOTIPOS
int mostrarEstudiantes(int* aLegajo, char* aSexo, int* aEdad, int* aNota1p, int* aNota2p, float* aPromedio, int limite)
int ordenarLegajoEstudiantes(int* aLegajo, char* aSexo, int* aEdad, int* aNota1p, int* aNota2p, float* aPromedio, int limite)

int main()
{
    int legajo[CANT_EL];
    char sexo[CANT_EL];
    int edad[CANT_EL];
    int nota1p[CANT_EL];
    int nota2p[CANT_EL];
    float promedio[CANT_EL];

    //MOSTRAR, ORDENAR Y VOLVER A MOSTRAR
    cargarSetDatos(legajo, sexo, edad, nota1p, nota2p, promedio, CANT_EL);              //
    mostrarEstudiantes(legajo, sexo, edad, nota1p, nota2p, promedio, CANT_EL);
    ordenarLegajoEstudiantes(legajo, sexo, edad, nota1p, nota2p, promedio, CANT_EL);
    mostrarEstudiantes(legajo, sexo, edad, nota1p, nota2p, promedio, CANT_EL);

    return 0;


    int cargarSetDatos(int* aLegajo, char* aSexo, int* aEdad, int* aNota1p, int* aNota2p, float* aPromedio, int limite)
    {
        int i;
        int buffer;
        for (i=0; i< limite; i++)
            {
            if(getInt(&buffer, "+Ingrese el legajo del alumno: ", "Error. ", 1, 100, 2)== 0)    //VALIDAR EL LEGAJO DE LOS ALUMNOS ENTRE 1 Y 100 CON 2 INTENTOS

                {
                    aLegajo[i]=buffer;

                }

                else
                {
                    aLegajo[i]=0;
                }
                printf("Ingrese el sexo del alumno: ");
                fflush(stdin);
                scanf("%c", &aSexo[i]);

                printf("Ingrese la edad del alumno: ");
                scanf("%d", &aEdad[i]);

                printf("Ingrese la nota del 1er parcial del alumno: ");
                scanf("%d", &aNotap1[i]);

                printf("Ingrese la nota del 2do parcial del alumno: ");
                scanf("%d", &aNotap2[i]);

                aPromedio[i] = (((float)aNota1p[i] + aNota2p[i])/2);

            }
            return 0;

    }
    int mostrarEstudiante(int aLegajo, char aSexo, int aEdad, int aNotap1, int aNotap2, float aPromedio)
    {
        printf("\n%d         %c            &d         %d        %d          %.2f", aLegajo,aSexo,aEdad,aNotap1,aNotap2,aPromedio);

        return 0;

    }

    int mostrarEstudiantes(int* aLegajo, char* aSexo, int* aEdad, int* aNotap1, int* aNotap2, float aPromedio)
    {
        int i;
        printf("\nlegajo     sexo   edad    nota1p    nota2p    promedio");
        for (i=0; i<limite; i++)
            {
                mostrarEstudiante(aLegajo[i], aSexo[i], aEdad[i], aNotap1[i], aNotap2[i], aPromedio[i])

            }

     int ordenarLegajoEstudiantes(int* aLegajo, char* aSexo, int* aEdad, int* aNotap1, int* aNotap2, float* aPromedio)
     {
        int i;
        int aux;
        char auxF;
        char auxS;
        int flag =-1;

        while(flag ==-1)
            {
                flag = 0;
                for (i=0; i < limite -1; i++)
                    {
                        if(aLegajo[i]>aLegajo[i+1])
                            {
                                aux= aLegajo[i];
                                aLegajo[i]=aLegajo[i+1];
                                aLegajo[i+1]=aux;

                                aux= aSexo[i];
                                aSexo[i]=aSexo[i+1];
                                aSexo[i+1]=aux;

                                aux= aEdad[i];
                                aEdad[i]=aEdad[i+1];
                                aEdad[i+1]=aux;


                                aux= aNotap1[i];
                                aNotap1[i]=aNotap1[i+1];
                                aNota1[i+1]=aux;

                                aux= aNotap2[i];
                                aNotap2[i]=aNotap2[i+1];
                                aNotap2[i+1]=aux;

                                aux= aPromedio[i];
                                aPromedio[i]=aPromedio[i+1];
                                aPromedio[i+1]=aux;

                                flag=-1;


                            }

                    }

            }


     }


    }





    return 0;
}
