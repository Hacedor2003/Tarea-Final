#include "Logica/Datos.h"


bool entrada(Registro Libros[],int *cant_libros);


void mostrar_identificadores(Registro Libros[],int *contador);

void mostrar_char(char arreglo[],int posicion,int *contador);

void mostrar_int(int valor,int posicion,int *contador);

void no_existe(int contador);

void mostrar_datos(Registro Libros[],int posicion);

void mostrar_prestamos(Registro Libros[],int *contador);


void mostrar_libros_prestados(bool *activar_mes,int *contador,int mes);

void mostrar_nombre_libros_prestados(Registro Libros[],bool activar_nombre[],int posicion);

void libros_materia(Registro Libros[]);

void libros_anno(Registro Libros[]);

void libros_mas_prestados(Registro Libros[],int *guardar_libro,int valor,int *contador1);

void libros_identificador(Registro Libros[]);


