#include <stdio.h>
#include <stdlib.h>
#define QTY_EDADES 5
#define VALOR_INICIAL 0
int initArrayint(int *pArray, int limite, int valor);

int main()
{
    int edades[QTY_EDADES];
    int minimo, maximo, suma, promedio;
    //inicializar

    initArrayint(edades, QTY_EDADES,VALOR_INICIAL);

    printfArray(edades,QTY_EDADES);

    return 0;

}



int initArrayint(int *pArray, int limite, int valor)
    {
        int retorno = -1;
        int i;
        if(pArray != NULL && limite > 0)
        {
            for(i = 0; i < limite; i++)
            {
                printf("\n\t%i", pArray[i]);
            }
            retorno = 0;
        }
        return retorno;
    }
