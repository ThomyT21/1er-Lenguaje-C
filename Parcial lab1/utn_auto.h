


///***AUTO****////









typedef struct
{
int id;
char patente[7];
int idMarca;
int idColor;
int modelo;
}Auto;




int inicializarAuto(Auto list[], int tam);
int buscarLibre(Auto list[], int tam);
int alta_Auto(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C, int* cont);
int listar_Autos(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C);
int baja_Auto(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C);
int buscar_Patente(Auto list[], int tam, char patente[]);
int submenu_mod(Auto list[], int tam, Marca list_M[], int tam_M, Color list_C[], int tam_C);
int verificarListaAutos(Auto list[],int tam);
int ordenarAutos(Auto list[], int tam);
int encontrar_Patente(Auto list[], int tam, int id,  char patente[]);
