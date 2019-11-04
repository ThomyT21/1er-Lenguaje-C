
///****MARCAS****////

typedef struct
{
int id;
char descripcion[21];
}Marca;



int mostrarMarcas(Marca list[], int tam);
int buscar_ID_marca(Marca list[],int tam,int id);
int Encontrar_Marca(Marca list[],int tam,int id, char Marca[]);
