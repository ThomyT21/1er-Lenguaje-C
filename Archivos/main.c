#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char auxChar;
    FILE* f = fopen("archivo.txt", "w");            // Se crea un archivo
    char mensaje[30] = "Esto es un mensaje";
    char cadena[30];

    if(f == NULL)
        {
            printf("No se pudo abrir el archivo");
            system("pause");
            exit(EXIT_FAILURE);
        }

// fwrite(mensaje, sizeof(char),strlen(mensaje), f);
// fprintf(f, "Hola World");                                         //fread() es para leer
// fscanf(f,"%s", cadena);

// while(!feof(f))
    {
        // fgets(cadena, 29, f);
        auxChar = fgetc(f);
        puts(cadena);
        // printf("%s", cadena);
        // printf("%c", auxChar);
        fread(cadena, sizeof(char), 29,f);

        printf("%s", cadena);

    }
fclose(f);                                                          //fwrite() es para escribir



return 0;
}
