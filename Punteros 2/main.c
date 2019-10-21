#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y);

int main()
{
    int x = 10;
    int y = 7;

    printf(" En Main x: %d     y: %d \n\n", x, y);

    swap(&x, &y);
    printf(" En Main x: %d     y: %d \n\n", x, y);

    return 0;
}
void swap(int* x, int* y)
{
    int aux = *x;
    aux = x*;
    *x = *y;
    *y = aux;

    printf(" En Swap x: %d     y: %d \n\n", *x, *y);
}
