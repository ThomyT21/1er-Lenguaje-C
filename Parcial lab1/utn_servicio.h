#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
///****SERVICIO****////


typedef struct{
int id;
char descripcion[26];
float precio;
}Servicio;


int mostrarServicios(Servicio list[], int tam);
int Encontrar_Servicio(Servicio list[],int tam,int id, char Sericio[]);
int buscar_id_servicio(Servicio list[], int tam, int id);
