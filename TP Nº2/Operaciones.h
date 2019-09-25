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
int mostrar_1_Empleado(eEmployee empleado);
int mostrar_Todos_Los_Empleados(eEmployee vec[], int size);
int bAJA(eEmployee vec[], int size);
int buscar_Por_Id(eEmployee vec[], int size, int id);
