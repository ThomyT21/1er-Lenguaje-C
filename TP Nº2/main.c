#include <stdio.h>
#include <stdlib.h>
#define TAM 1
#include <string.h>                 // AÑADE LA BIBLIOTECA DE STRINGS

typedef struct                      //ESTRUCTURAS
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int estado;


}eEmployee;

int aLTA(eEmployee vec[], int size);    //PROTOTIPO DE UNA FUNCION. FUNCION ALTA 1)
int iNicializar(eEmployee vec[], int size);
int mOSTRAR1Empleado(eEmployee empleado);
int mostrar_Todos_Los_Empleados(eEmployee vec[], int size);




int main()
{
    eEmployee EmployeeLista[TAM];
    char opcion;

iNicializar(EmployeeLista, TAM);           //LLAMAR A LA FUNCION
        do
    {
        printf("Elija la operacion deseada: \n");
        printf("a) Calcular la suma (A+B)\n");
        printf("b) Calcular la resta (A-B)\n");
        printf("c) Calcular la division (A/B)\n");
        printf("d) Calcular la multiplicacion (A*B)\n");
        printf("e) Calcular el factorial (A!)\n");
        printf("s) SALIR \n");
        fflush(stdin);
        scanf("%c", &opcion);

        //Aqui se arma la estructura de control del menu de opciones

        switch(opcion)
        {

        case 'a' : mostrar_Todos_Los_Empleados(EmployeeLista, TAM);


            break;

        case 'b' : aLTA(EmployeeLista, TAM);

            break;
        case 'c' :

            break;

        case 'd' :

            break;
        case 'e' :


            break;

        default :

            if(opcion == 's')
            {
                printf("\n Vuelva pronto! \n");
            }
            else
            {
                printf("/n Opcion incorrecta! \n");
            }

        }

        system("pause");
        system("cls");

    }
    while(opcion != 's');


    return 0;
}
int aLTA(eEmployee vec[], int size)
{
    int i;
    for(i=0; i < size; i++)
        {
            printf("Ingrese la id\n");
            fflush(stdin);
            scanf("%d", &vec[i].id);
            fflush(stdin);

            printf("Ingrese nombre\n");
            scanf("%s", vec[i].nombre);
            fflush(stdin);

            printf("Ingrese apellido\n");
            scanf("%s", vec[i].apellido);
            fflush(stdin);

            printf("Ingrese salario\n");
            scanf("%f", &vec[i].salario);
            fflush(stdin);

            printf("Ingrese sector\n");
            scanf("%d", &vec[i].sector);
            fflush(stdin);

            printf("Ingrese el estado\n");
            scanf("%d", &vec[i].estado);
            fflush(stdin);

        }
    return 0;

}
int iNicializar(eEmployee vec[], int size)
{
    int i;
    for(i=0; i < size; i++)
        {
            vec[i].id = 0;
            vec[i].salario = 0;
            vec[i].estado = 0;
            vec[i].sector = 0;

            strcpy(vec[i].nombre, "");          //INICIALIZA LA VARIABLE DE TIPO STRING
            strcpy(vec[i].apellido, "");
        }

        return 0;
}
int mOSTRAR1Empleado(eEmployee empleado)
{
    printf("La id: %d nombre: %s Apellido: %s: salario: %.2f estado: %d sector: %d\n", empleado.id, empleado.nombre, empleado.apellido, empleado.salario, empleado.estado, empleado.sector);
    return 0;
}



int mostrar_Todos_Los_Empleados(eEmployee vec[], int size)
{
    int i;
    for(i=0; i < size; i++)

        {
            mOSTRAR1Empleado(vec[i]);

        }

    return 0;

}
