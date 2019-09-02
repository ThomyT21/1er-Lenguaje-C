#include <stdio.h>
#include <stdlib.h>
int calcularMinMax(int cantidadPedidos, int* min,int* max);

int main()
{
    int minimo;
    int maximo;
    int pedidos;
    int res;

    printf("\nCantidad de numeros a pedir");
    scanf("%s", &pedidos);
    if((res = calcularMinMax(pedidos, &minimo, &maximo))== 0)
        {
           printf("minimo = %d ", minimo);
           printf("maximo = %d", maximo)


        }


}
