#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int vec[4];

    num1 = vec[1];
    vec[2] = num1;

    for(int i = 0; i < 5; i++)
        {
            printf("Ingrese un numero: \n ");
            scanf("%d", &num1);
            vec[i] = num1;

        }

    for(int i = 0; i < 5; i++)
        {
            printf("El 1er numero ingresado es %d \n",vec[i]);

        }
    return 0;
}
