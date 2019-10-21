#include <stdio.h>                                      //Funcion malloc
#include <stdlib.h>                                     // Funcion realloc: reaccion de memoria me duelve una direccion de memoria con puntero void

int main()

int* numeros;
int* aux;

numeros = (int*) malloc(numeros, sizeof(int)* 5);
if(numero == NULL)
    {
        exit(EXIT_FAILURE);
        printf()
    }
    else
        {
            numeros = aux;
        }


    }
for(int i = 0; i<4; i++)
    {
        printf("%d", *(numeros + i));

    }
printf("\n\n");

numeros = (int*) realloc(numeros, sizeof(int)* 4);

aux = (int*) realloc(numeros, sizeof(int)* 10);
if( aux != NULL)
    {
        numeros = aux;
    }
free(numeros);

/*
{
    //int x = 50;
    int* p;

   // p = &x;

   p = (int*) malloc(sizeof(int)* 5);
   for(int i = 0; i < 5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", p+i);
    }
    for(int i = 0 ; i < 5; i++)
        {
            printf("El numero que ingresaste es: %d\n", *(p+i));
        }
    /*
    printf("Ingrese un numero: ");
    scanf("%d", p);
    printf("EL NUMERO QUE INGRESASTE ES: %d\n", *p);
    */
    return 0;
}
