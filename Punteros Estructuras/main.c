#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int id;
    char nombre;
    char apellido;
    float altura;
    int fechaNacimiento;
    int dia;
    int mes;
    int anio;

}ePersona;


int main()
{
    ePersona per1;
    ePersona* p;

    p = &per1;

    strcpy(per1.nombre, "Juan");

    per1.fechaNacimiento.dia = 10;
    per1.fechaNacimiento.mes = 5;
    per1.fechaNacimiento.anio = 2000;

    printf("%S\n", per1.nombre);
    printf("%s\n", p->nombre);
    printf("%s\n", (*p).nombre);
    printf("%s\n", p->fechaNacimiento.mes);
    printf("Ingrese altura: ");
    scanf("%f", &p->altura);
    printf("La altura de la persona es %.2f\n", p->altura);

    return 0;
}
