#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esNumerica(char* cadena);
static int getSoloNumeros(int* pResultado);

int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = -1;
	int buffer;
	do
	{
		printf("%s",pMensaje);
		//fflush(stdin);
		//fgets(buffer,sizeof(buffer),stdin);
        //gets(buffer);
        if(getSoloNumeros(&buffer)==1)
        {
            if(buffer >= minimo && buffer <= maximo)
            {
                *pResultado = buffer;
                retorno = 0;
                break;
            }
        }
        printf("%s",pMensajeError);
        reintentos--;

	}while(reintentos >= 0);

	return retorno;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    gets(input);
}

static int esNumerica(char* cadena)
{
    int ret=-1;
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
        if(cadena[i]<'0' || cadena[i]>'9')
            break;
        i++;
        }
        if(cadena[i]=='\0')
            ret=1;
    }
    return ret;
}
static int getSoloNumeros(int* pResultado)
{
    int ret=-1;
    //int cant;
    char buffer[8];
        fgets(buffer,sizeof(buffer),stdin);
        //cant = strlen(buffer);
        //printf("1er STRLEN : %d ", cant);
        buffer[strlen(buffer)-1]='\0';
        //cant = strlen(buffer);
        //printf("2do STRLEN : %d ", cant);
        //gets
        //gets(buffer);
        //cant = strlen(buffer);
        //printf("STRLEN : %d ", cant);

        if(esNumerica(buffer)==1)
        {
            *pResultado = atoi(buffer);
            ret=1;
        }
    return ret;
}
