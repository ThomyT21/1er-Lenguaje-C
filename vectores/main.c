#include <stdio.h>
#include <stdlib.h>

int main()
{            ///( 0 , 1 , 2, 3)
    int vec[] = {23,123,12,242};  ///TAMAÑO = 4

    int minimo, maximo, suma = 0, promedio, cantidad; /// VAR NO GLOBALS
    int flag =1 ;

   for(int i=0; i < 4; i++){   /// FOR PARA RECORRER EL VECTOR DEL INDICE 0 AL 3

    printf("%d\n", vec[i]);       ///MUESTRO LOS NUMEROS DEL VECTOR Y AGREGO UN SALTO DE LINEA


    if(flag || minimo > vec[i])   ///SACAR EL MAXIMO
        minimo = vec[i];

     if(flag || maximo < vec[i])    ///SACAR EL MINIMO
        maximo = vec[i];

    flag = 0;                       ///FLAG = 0 PARA INDICAR Q NO ES PRIMERA ENTRADA

    suma += vec[i];                 /// CALCULO LA SUMA, POR CADA PASADA SE SUMA UN NUMERO

    cantidad = i + 1;                   /// CALCULO LA CANTIDAD DE NUMEROS QUE HAY



   }


   promedio = suma / cant;          /// SACO PROMEDIO, SIEMPRE FUERA DEL FOR, O EL WHILE


    ///******MUESTRO TODO*****
    printf("\nmaximo: %d\n", maximo);
    printf("minimo: %d\n", minimo);
    printf("suma: %d\n", suma);
    printf("promedio: %d\n", promedio);
    printf("cantidad: %d\n", cant);

    return 0;
}
