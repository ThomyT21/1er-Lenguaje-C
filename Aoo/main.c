#include <stdio.h>
#include <stdlib.h>

 typedef struct
 {
    int marca;
    float precio;



 }eNotebook;                               // char contarCaracteres(char cadena[], char car);

int main()
{
                                //printf("%d\n", contarCaracteres("Obelisco", 'O'));
    return 0;
}
void ordernarNotebook( eNotebook lista [], int tam)
{
    eNotebook aux;
    for(int i=0; i < tam -1; i++)
        {
            for(j = i+1; j < tam; j++)
                {
                    if(strcmp(lista[i].marca, lista[i].precio > lista[j].precio))
                        {
                            aux = lista[i];
                            lista[i] = lista[j];
                            lista[j] = aux;

                        }
            else if(strcmp(lista[i].marca, lista[i].precio < lista[j].precio)
                    {
                            aux = lista[i];
                            lista[i] = lista[j];
                            lista[j] = aux;

                    }
                }


        }



}


/*char contarCaracteres(char cadena[], char car)
{
    int contador = 0;
    for(int i= 0; i < strlen(cadena); i++)
        {
            if(cadena[i]== car)
                {
                    contador++;
                }
        }
return contador;
}
{

int contador = 0;
int i = 0;

while ( cadena [i] != '\0')
    {
        if(cadena[i]== car)
            {
                contador++;

            }
        i++;
    }
return contador;

}
*/
