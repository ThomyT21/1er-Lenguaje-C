
///****TRABAJO****///
typedef struct
{
int dia;
int mes;
int anio;
}Fecha;


typedef struct
{
int id;
char patente[6];
int idServicio;
Fecha fecha;
}Trabajo;



int inicializarTrabajos(Trabajo list[], int tam);
int buscarTrabajoLibre(Trabajo list[], int tam);
int alta_Trabajo(Trabajo list[], int tam, Servicio list_s[], int tam_s, Auto list_a[], int tam_a, Color list_c[], int tam_c, Marca list_m[], int tam_m);
int listar_Trabajos(Trabajo list[], int tam, Servicio list_s[], int tam_s);
