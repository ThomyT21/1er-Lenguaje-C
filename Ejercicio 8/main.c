#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    int numero;
    int contPares = 0;
    int contImpares = 0;
    int ContCeros = 0
    int acumPositivos = 0;
    float promPositivos;
    int acumNegativos = 0;
    int numMax;
    int numMin;
    char letraMax;
    char letraMin;
    int flag = 0;
    int contPositivos = 0;
    char seguir;


    do{
       printf("ingrese un numero: ");
        scanf("d%", &numero);
        fflush(stdin);

        printf("ingrese una letra: ");
        scanf("c%", &letra);
        fflush(stdin);

        while(!(numero >= -100 && numero <= 100))
        {
            printf("Error. Reingrese un numero: ");
        }



        if( numero % 2 == 0)        // 1) CONTADOR DE PARES
        {
          contPares++;
        }

        else
        {
          contImpares++;           // 2) CONTADOR DE IMPARES
        }

        if( numero == 0)
        {
          ContCeros++;             // 3) CONTADOR DE CEROS
        }

        else if( numero > 0)
        {
            acumPositivos += numero;    // 4) ACUMULADOR O CONTADOR DE POSITIVOS
            contPositivos++;
        }

        else
        {
            acumNegativos += numero;    // 5) ACUMULADOR O CONTADOR DE NEGATIVOS
        }

        if ( numero > numMax || flag == 0)  // 6) NUMERO Y LETRA MAXIMO
        {
            numMax = numero;
            letraMax = letra;
        }

        if ( numero < numMin || flag == 0)  // 6) NUMERO Y LETRA MINIMO
        {
            numMin = numero;
            letraMin = letra;
            flag = 1;
        }

        printf = ("Quiere seguir ingresando numeros y letras?");
        fflush(stdin);
        scanf("&c", &seguir);



    }while (seguir == 's');

    promPositivos = (float)acumPositivos / contPositivos;          // 4) PROMEDIO TOTAL DE LOS POSITIVOS

        printf("la cantidad de pares es %d", contPares);            // 1)
        printf("La cantidad de impares es %d", contImpares);        // 2)
        printf("La cantidad de ceros es %d ", ContCeros);           // 3)
        printf("El promedio de los positivos es %.2f", promPositivos);  // 4)
        printf("La suma de los negativos es %d", acumNegativos);        // 5)
        printf("El numero maximo es %d y su letra es %c", numMax, letraMax);    // 6)
        printf("El numero minimo es &d y su letra es %c", numMin, letraMin);    // 6)

        // %d int

        // %c char

        // %.2f float

        //%s string
}
