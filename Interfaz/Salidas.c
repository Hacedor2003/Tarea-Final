#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Salidas.h"
#include "validacion.h"

/* Función para recibir los datos de los libros por el usuario */
bool entrada(Registro Libros[], int *cant_libros)
{
    int j;

    int i = 0;
    int respuesta = 0;
    bool guardar = true;

    char condicion[9] = {""};

    char *meses[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
                     "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

    *cant_libros = 0;

    printf("Introduzca los datos de los libros, solo hay espacio para 5 libros.\n");

    do
    {
        system("cls");
        fflush(stdin);

        printf("Libro #%d\n", i + 1);
        printf("Sino posee el dato del libro, introduzca -1\n");
        printf("-------------------------------------------\n");
        printf("Introduzca el t\241tulo del libro:\n");
        printf("Tenga en cuenta que cada libro tiene un t\241tulo particular\n");

        validar_titulo(Libros, i);

        printf("-------------------------------------------\n");
        printf("Introduzca el autor del libro:\n");

        validar_char(Libros[i].autor, sizeof(Libros[i].autor) / sizeof(char));

        printf("-------------------------------------------\n");
        printf("Introduzca el identificador del libro:\n");
        printf("El identificador es num\202rico y \243nico para cada libro\n");

        validar_identificador(Libros, i);

        printf("-------------------------------------------\n");
        printf("Introduzca la materia del libro:\n");

        validar_char(Libros[i].materia, sizeof(Libros[i].materia) / sizeof(char));

        printf("-------------------------------------------\n");
        printf("Introduzca el a\244o donde se public\242 el libro:\n");
        printf("Tenga en cuenta que tiene que ser antes del 2023 que es nuestro a\244o actual.\n");

        validar_anno(&Libros[i].anno);

        printf("-------------------------------------------\n");
        printf("Introduzca la cantidad de copias del libro:\n");

        validar_numero(&Libros[i].copias);

        printf("-------------------------------------------\n");

        if (Libros[i].copias != 0)
        {
            printf("Prestamos por mes:\n");

            for (j = 0; j < MESES; j++)
            {
                printf("Introduzca los pr\202stamos en %s:\n", meses[j]);

                validar_prestamos(&Libros[i].numero_prestamos[j], Libros, i);
            }
        }
        else
        {
            printf("Sino existen copias no pueden haber prestamos.\n");

            system("pause");
        }

        if (i == LIBROS - 1)
        {
            printf("La librer\241a est\240 llena.\n");

            system("pause");

            i = LIBROS;
        }
        else if (i < LIBROS - 1)
        {
            system("cls");

            printf("Desea terminar de a\244adir libros?\n");
            printf("1.Si \n");
            printf("2.No \n");
            printf("3.Usar los libros que ya exist\241an, tenga en cuenta que sobrescribir\240 la informaci\242n introducida.\n");

            respuesta = validar_respuesta(condicion, 9);

            if (respuesta == 1)
            {
                i = LIBROS;

                (*cant_libros)++;

                guardar = true;
            }
            else if (respuesta == 2)
            {
                i++;

                (*cant_libros)++;
            }
            else if (respuesta == 3)
            {
                i = LIBROS;
                (*cant_libros) = LIBROS;
                guardar = false;

                printf("Se han restablecido los datos\n");

                system("pause");
            }
        }
    } while (i < LIBROS);

    return guardar;
}

/* Función para mostrar por consola un arreglo */
void mostrar_char(char arreglo[], int posicion, int *contador)
{
    if (strcmp(arreglo, "") != 0 && strcmp(arreglo, "0") != 0 && strcmp(arreglo, "-1"))
    {
        printf("Libro #%d = %s \n", posicion + 1, arreglo);
    }
    else /* SUGERENCIA: (Sintaxis) Poner siempre las llaves */
        (*contador)++;
}

/* Función para mostrar por consola un entero*/
void mostrar_int(int valor, int posicion, int *contador)
{
    if (valor != 0)
    {
        printf("Libro #%d = %d \n", posicion + 1, valor);
    }
    else /* SUGERENCIA: (Sintaxis) Poner siempre las llaves */
        (*contador)++;
}

/* Función para mostrar por consola que un dato no existe*/
void no_existe(int contador)
{
    if (contador == LIBROS)
    {
        system("cls");

        printf("\n\nNo tengo guardado lo necesario para mostrar esta informaci\242n.\n");
    }
}

/* Función para mostrar los datos de los libros */
void mostrar_datos(Registro Libros[], int posicion)
{
    int k;

    int j = posicion;

    char *meses[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
                     "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

    printf("**************\n");
    printf("Titulo: %s \n", Libros[j].titulo);
    printf("Autor: %s \n", Libros[j].autor);
    printf("Materia: %s \n", Libros[j].materia);
    printf("Identificador: %ld \n", Libros[j].identificador);
    printf("A\244o: %d \n", Libros[j].anno);
    printf("Copias: %d \n", Libros[j].copias);
    printf("Prestamos por mes:\n");

    for (k = 0; k < MESES; k++) /* SUGERENCIA: (Sintaxis) Poner siempre las llaves */
        printf("%s = %d\n", meses[k], Libros[j].numero_prestamos[k]);
}

/* 1. Listado de identificadores */
void mostrar_identificadores(Registro Libros[], int *contador)
{
    int i;
    int j;

    bool comparar[LIBROS] = {false};

    for (i = 0; i < LIBROS; i++)
    {
        if (!comparar[i])
        {
            for (j = i + 1; j < LIBROS; j++)
                if (Libros[i].identificador == Libros[j].identificador)
                {
                    comparar[j] = true;
                }

            if (Libros[i].identificador != 0)
            {
                printf("Libro #%d = %ld \n", i + 1, Libros[i].identificador);
            }
        }

        if (Libros[i].identificador == 0)
        {
            (*contador)++;
        }
    }
}

/* 7.Listado de prestamos */
void mostrar_prestamos(Registro Libros[], int *contador)
{
    int j;
    int k;

    char *meses[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
                     "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

    for (j = 0; j < LIBROS; j++)
    {
        if (Libros[j].copias != 0)
        {
            printf("**************\n");
            printf("Libro #%d\n", j + 1);

            for (k = 0; k < MESES; k++) /* SUGERENCIA: (Sintaxis) Poner siempre las llaves */
                printf("En %s = %d\n", meses[k], Libros[j].numero_prestamos[k]);
        }
        else
        {
            (*contador)++;
        }

        printf("**************\n");
    }
}

/* a) Devolver los libros que en algún mes fueron prestados todos sus ejemplares. */
void mostrar_nombre_libros_prestados(Registro Libros[], bool activar_nombre[], int posicion)
{
    if (activar_nombre[0])
    {
        printf("\n-----------------------------------------------------------------------------------------\n");
        printf("De %s :\n", Libros[posicion].titulo);
    }
    else if (activar_nombre[1])
    {
        if (strcmp(Libros[posicion].titulo, "") != 0 && strcmp(Libros[posicion].titulo, "0") != 0 && strcmp(Libros[posicion].titulo, "-1") != 0)
        {
            printf("\n-----------------------------------------------------------------------------------------\n");
            printf("De %s no fueron prestados todos sus ejemplares\n", Libros[posicion].titulo);
        }
    }
}

void mostrar_libros_prestados(bool *activar_mes, int *contador, int mes)
{
    int i = mes;

    char *meses[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
                     "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};

    if (*activar_mes)
    {
        printf("En %s.\n", meses[i]);
    }

    no_existe(*contador);
}

/* b) Devolver los datos de los libros que pertenecen a una materia dada. */
void libros_materia(Registro Libros[])
{
    int i = 0;
    int materia = 0;
    int contador = 0;

    for (i = 0; i < LIBROS; i++)
    {
        mostrar_char(Libros[i].materia, i, &contador);
    }

    no_existe(contador);

    if (contador != LIBROS)
    {
        do
        {
            fflush(stdin);

            printf("Introduzca la materia:\n");
            scanf("%d", &materia);

            if (materia < 1 || strcmp(Libros[materia - 1].materia, "") == 0)
            {
                printf("Error , tiene que ser de los que estan disponibles \n");
            }
        } while (materia < 1 || strcmp(Libros[materia - 1].materia, "") == 0);

        i = materia - 1;

        mostrar_datos(Libros, i);
    }
}

/* c) Mostrar un reporte por año de publicación con todos los datos de los libros del centro. */
void libros_anno(Registro Libros[])
{
    int j;

    int contador = 0;

    for (j = 0; j < LIBROS; j++)
    {
        if (Libros[j].anno != 0)
        {
            mostrar_datos(Libros, j);
        }
        else /* SUGERENCIA: (Sintaxis) Poner siempre las llaves */
            contador++;
    }

    if (contador == LIBROS) /* SUGERENCIA: (Sintaxis) Poner siempre las llaves */
        printf("No tengo la informaci\242n necesaria (a\244os donde fue publicado)\n");
}

/* d) Devolver el primer libro que más veces se ha prestado. */
void libros_mas_prestados(Registro Libros[], int *guardar_libro, int valor, int *contador1)
{
    printf("Fue prestado m\240s veces : %s con %d prestamos\n", Libros[*guardar_libro].titulo, valor);

    no_existe(*contador1);
}

/* e) Dado el identificador de un libro, mostrar toda su información */
void libros_identificador(Registro Libros[])
{
    int i = 0;
    int contador = 0;
    int identificador = 0;

    mostrar_identificadores(Libros, &contador);
    no_existe(contador);

    if (contador != LIBROS)
    {
        do
        {
            printf("Seleccione el Identificador: \n");
            scanf("%d", &identificador);

            if (identificador < 1 || Libros[identificador - 1].identificador == 0)
            {
                printf("Error , tiene que ser de los que estan disponibles \n");
            }
        } while (identificador < 1 || Libros[identificador - 1].identificador == 0);

        i = identificador - 1;

        mostrar_datos(Libros, i);
    }
}
