#include <stdio.h>
#include <stdlib.h>

int main()
{   //CONVERSION DE CHAR (LETRAS) A ENTERO, LONG Y FLOAT
    char letras [] = "123";
    int numeroentero;
    numeroentero = atoi(letras);
    printf("texto convertido en numeroentero %d \n", numeroentero);

    long numerolong;
    numerolong = atoi(letras);
    printf("Texto convertido en numerolong %ld \n", numerolong);

    float numerodecimal;
    numerodecimal = atoi(letras);
    printf("Texto convertido en numerodecimal %.2f \n", numerodecimal);

}
