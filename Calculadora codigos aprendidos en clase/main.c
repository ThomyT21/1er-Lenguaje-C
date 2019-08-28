#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
int sumar(int num1, int num2);          // PARAMETROS FORMALES // PROTOTIPO
int resta(int num1, int num2);
int multiplicacion(int num1, int num2);
float division(int num1, int num2);
int factorial(int num1);


int main()
{
    int valor1;
    int valor2;
    int total;
    float total2;
    int resultado;

        printf("Ingrese el 1er valor: ");
        scanf("%d", &valor1);
        printf("Ingrese el 2do valor: ");
        scanf("%d", &valor2);
        total = sumar(valor1, valor2);      // LLAMADA // ASIGNACION DE VALOR A UNA VARIABLE // PARAMETRO REALES
        printf("El total de la suma es: %d\n", total);      //SUMA

        total = resta(valor1, valor2);
        printf("El total de la resta es: %d\n", total);     // RESTA

        total = multiplicacion(valor1, valor2);
        printf("El total de la multiplicacion es: %d\n", total);        //MULTIPLICACIÓN

        total2 = division(valor1, valor2);
        printf("El total de la division es: %f\n", total2);          //DIVISIÓN


        resultado = factorial(valor1);
        printf("El factorial de %d es %d", valor1, resultado);       // FACTORIAL

        return 0;
}

    int sumar(int num1, int num2)               // 1) SUMA
    {
        int respuesta;
        respuesta = num1 + num2;
        return respuesta;

    }

    int resta(int num1, int num2)               // 2) RESTA
    {
        int respuesta;
        respuesta = num1 - num2;
        return respuesta;

    }

    int multiplicacion(int num1, int num2)      // 3) MULTIPLICACION
    {
        int respuesta;
        respuesta = num1 * num2;
        return respuesta;
    }

    float division(int num1, int num2)            // 4) DIVISION
    {
        float respuesta;
        respuesta =(float)num1 / num2;
        return respuesta;
    }


    int factorial(int num1)                        // 5) FACTORIAL
    {
        int respuesta;
        if(num1 ==1)
            return 1;
        respuesta = num1 * factorial(num1 - 1);
        return (respuesta);


    }






