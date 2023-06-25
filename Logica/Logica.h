#include <stdbool.h>


#include "Datos.h"



void inicializar(Registro Libros[] );

void inicializar_cero(Registro Libros[] );

int calcular_libros_prestados(Registro Libros[], bool *activar_mes, int posicion, int mes);

void verificar_nombre_prestado(Registro Libros[], bool activar_nombre[], int *contador, int posicion);

int calcular_libros_mas_prestados(Registro Libros[], int *contador1, int *guardar_libro);
