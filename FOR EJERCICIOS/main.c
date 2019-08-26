#include <stdio.h>
#include <stdlib.h>

int main()   //Solicito el primer numero el cual por ser el primero sera tanto el maximo como el minimo y el 1er nº
{
    int maximo;
    int minimo;
    int acumulador;
    int auxiliarInt;
    int i;


    for(int i = 0; <4; i++)
    {
      printf("Ingrese un numero: ");
      scanf("%d", &auxiliarInt);
      acumulador = acumulador  auxiliarInt;

      if (auxiliarInt > maximo)
        {
            maximo = auxiliarInt;
        }

      if ( auxiliarInt < minimo)
        {
        minimo = auxiliarInt
        }


    }



    return 0;
}
