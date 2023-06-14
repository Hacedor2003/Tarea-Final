#include "Logica/Logica.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


void inicializar(Registro Libros[])
{
    int i;
    int j;


    srand(time(NULL)); /* Inicializa la semilla para generar números aleatorios */


    strcpy(Libros[0].titulo,"La Odisea");
    strcpy(Libros[0].autor,"Homero");
    Libros[0].identificador = 123456789;
    strcpy(Libros[0].materia,"Literatura cl\240sica");
    Libros[0].copias = rand() % 20;
    Libros[0].anno = 1990;

    strcpy(Libros[1].titulo,"Cien a\244os de soledad");
    strcpy(Libros[1].autor,"Gabriel Garc\241a M\240rquez");
    Libros[1].identificador = 987654321;
    strcpy(Libros[1].materia,"Realismo m\240gico");
    Libros[1].copias = rand() % 20;
    Libros[1].anno = 1967;

    strcpy(Libros[2].titulo,"El Quijote");
    strcpy(Libros[2].autor,"Miguel de Cervantes");
    Libros[2].identificador = 246810121;
    strcpy(Libros[2].materia,"Novela espa\244ola");
    Libros[2].copias = rand() % 20;
    Libros[2].anno = 1605;

    strcpy(Libros[3].titulo,"Los juegos del hambre");
    strcpy(Libros[3].autor,"Suzanne Collins");
    Libros[3].identificador = 369121518;
    strcpy(Libros[3].materia,"Ficci\242n de suspense");
    Libros[3].copias = rand() % 20;
    Libros[3].anno = 2008;

    strcpy(Libros[4].titulo,"El c\242digo Da Vinci");
    strcpy(Libros[4].autor,"Dan Brown");
    Libros[4].identificador = 1514131211;
    strcpy(Libros[4].materia,"Ficci\242n de suspense");
    Libros[4].copias = rand() % 20;
    Libros[4].anno = 2003;


    for(i =0; i < LIBROS ;i++)
        for(j =0; j < MESES ; j++)
            /* Genera un número aleatorio entre 0 y el número de copias disponibles */
            Libros[i].numero_prestamos[j] = rand() % (Libros[i].copias + 1);
}


void inicializar_cero(Registro Libros[])
{
    /*Inicializa todos los elementos a 0*/
    memset(Libros, 0, sizeof(Libros[0]) * LIBROS);
}


/*a) Devolver los libros que en algún mes fueron prestados todos sus ejemplares.*/
int calcular_libros_prestados(Registro Libros[],bool *activar_mes,int posicion,int mes)
{
    int i = posicion;
    int j = mes;
    int valor =0;


    if(Libros[i].numero_prestamos[j] == Libros[i].copias && Libros[i].copias != 0)
    {
        *activar_mes =true;
        valor = j;
    }
    return valor;
}


void verificar_nombre_prestado(Registro Libros[],bool activar_nombre[],int *contador, int posicion)
{
    int i = posicion;


    if (Libros[i].copias != 0){
        activar_nombre[0] =true;
    }
    else {
        activar_nombre[1] =true;
        (*contador)++;
    }
}


/*d) Devolver el primer libro que más veces se ha prestado. */
int calcular_libros_mas_prestados(Registro Libros[],int *contador1, int *guardar_libro)
{
    int i;
    int j;
    int guardar[LIBROS] = {0};
    int comparar =0;
    int contador2 =0;


    for(i=0;i < LIBROS;i++)
    {
        contador2 =0;
        for(j=0; j < MESES; j++)
        {
            if(Libros[i].numero_prestamos[j] != 0){
                guardar[i] += Libros[i].numero_prestamos[j];
            }
            else contador2++;
        }
        if(contador2 == MESES){
            (*contador1)++;
        }
    }
        for(i=0;i < LIBROS;i++)
            if(comparar < guardar[i])
            {
                comparar = guardar[i];
                *guardar_libro = i;
            }
    return comparar;
}








