typedef struct                      //ESTRUCTURAS
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int estado;


}eEmployee;

int addEmployee(eEmployee vec[], int size);    //PROTOTIPO DE UNA FUNCION. FUNCION ALTA 1)
int initEmployee(eEmployee vec[], int size);
int printEmployee(eEmployee empleado);
int printEmployees(eEmployee vec[], int size);
int removeEmployee(eEmployee vec[], int size);
int findEmployeeById(eEmployee vec[], int size, int id);
int buscar_Libre(eEmployee vec [], int size);
int comparacion(char letra1, char letra2);
