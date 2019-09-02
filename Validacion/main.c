#include <stdio.h>
#include <stdlib.h>


int main()
{
    char texto [] = "Nona mama";
    char conjuntoCaracteres [] = {'N','o','n','a'};
    char caracteres [] = {'N','o','n','a',' ','m','a','\0'};

    /// Cuenta un caracter de más
    printf("texto:%s Tamanio: %d \n", texto, sizeof(texto));        // 1er CASO
    printf("Longitud de la cadena= %d \n", strlen(texto));

    ///Imprime cualquier cosa, printf no sabe donde termina porque no encuentra el "\0"
    printf("\nConjuntoCaracteres:%s Tamanio: %d \n", conjuntoCaracteres, sizeof(texto));        // 2do CASO
    printf("Longitud de la cadena= %d \n", strlen(conjuntoCaracteres));





    return 0;
}
