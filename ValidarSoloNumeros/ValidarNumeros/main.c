#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Strlen() devuelve la longitud de una cadena de texto
//sizeof() devuelve el tamaño en bytes que ocupa un variable o tipo de dato

int main()
{
    int resp;
    char cResp[10];
    int cant;
    int i;

    printf("Ingrese un numero: ");
    //gets(cResp);
    fgets(cResp,sizeof(cResp),stdin);
    cant = strlen(cResp);
    //solo con fgets
    printf("\n1er STRLEN : %d ", cant);
    for (i=0;i<cant;i++)
    {
        printf("\nELemento:: %d : %c ", i, cResp[i]);
    }
    cResp[strlen(cResp)-1]='\0';
    cant = strlen(cResp);
    //fin solo con fgets

    printf("\nSTRLEN : %d ", cant);

    for (i=0;i<cant;i++)
    {
        printf("\nELemento:: %d : %c ", i, cResp[i]);
    }

    resp = atoi(cResp);
    printf("\nVariable numerica resp: %d ", resp );

    return 0;
}
