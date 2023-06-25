#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "../Interfaz/Menus.h"
#include "../Interfaz/Salidas.h"
#include "../Interfaz/validacion.h"

#include "Datos.h"
#include "Logica.h"


/* Menu Principal */
void menu(Registro Libros[] ) {
    int resp = 0;
    int cant_libros = LIBROS;
    bool guardar = true;

    char respuesta[9] = {""};


    do {
        system("cls");

        printf("*******Bienvenido al centro de investigaci\242n*******\n");
        printf("         .:Ya cuento con datos de %d libros:. \n", cant_libros);
        printf("Pero desea crear nuevos datos?Escriba o seleccione la opci\242n deseada\n");
        printf("1.Si \n");
        printf("2.No \n");
        printf("3.Terminar \n");

        resp = validar_respuesta(respuesta, 9);

        resp = validar_respuesta(respuesta, 9);


        switch (resp) {
            case 1:
                inicializar_cero(Libros);


                guardar = entrada(Libros, &cant_libros);


                if (!guardar) {
                    inicializar(Libros);
                }


                elegir_menu(Libros);


                break;
            case 2:
                guardar = false;


                if (!guardar) {
                    inicializar(Libros);
                }


                elegir_menu(Libros);


                break;
            case 3:         /* CORRECCIÓN: (Lógica) Tener un case vacío no tiene mucho sentido.
                             *                      Hay mejores maneras de modelar la salida del menú */
                break;

            default:
                printf("Opci\242n inv\240lida. Por favor, seleccione una de las 3 opciones.\n");

                system("pause");


                break;
        }
    } while (resp != 3);
}

/* Menu para escojer reportes o listados */
void elegir_menu(Registro Libros[] ) {
    int resp = 0;

    char respuesta[9] = {""};


    do
    {
        system("cls");

        printf("Que informaci\242n desea visualizar?\n");
        printf("1.Menu Listados \n");
        printf("2.Menu Reportes \n");
        printf("3.Terminar \n");


        resp = validar_respuesta(respuesta, 9);


        switch (resp) {
            case 1:
                menu_listados(Libros);


                break;
            case 2:
                menu_reportes(Libros);


                break;
            case 3:         /* CORRECCIÓN: (Lógica) Tener un case vacío no tiene mucho sentido.
                             *                      Hay mejores maneras de modelar la salida del menú */
                break;

            default:
                printf("Opci\242n inv\240lida. Por favor, seleccione una de las 3 opciones.\n");

                system("pause");


                break;
        }
    } while (resp != 3);
}

/* Menu para mostrar los datos de los libros*/
void menu_listados(Registro Libros[] ) {
    int i;
    int contador;

    int resp = 0;


    system("cls");


    do
    {
        printf("   Listados \n");
        printf("1. Listado de identificadores. \n");
        printf("2. Listado de los titulos. \n");
        printf("3. Listado de los autores \n");
        printf("4. Listado de los a\244os de publicaci\242n.\n");
        printf("5. Listado de las materias. \n");
        printf("6. Listado de las copias. \n");
        printf("7. Listado de los prestamos por mes. \n");
        printf("8. Terminar Listados.\n");

        do
        {
            fflush(stdin);

            printf("Introduzca (1-8) acorde a las necesidades:\n");
            scanf("%d", &resp);


            if (isalpha(resp) ) {
                printf("Error, por favor, ingrese un valor num\202rico.\n");
            }
        } while (isalpha(resp) );


        switch (resp) {
            case 1:
                contador = 0;


                mostrar_identificadores(Libros, &contador);
                no_existe(contador);

                system("pause");


                break;
            case 2:
                contador = 0;


                for (i = 0; i < LIBROS; i++) {
                    mostrar_char(Libros[i].titulo, i, &contador);
                }


                no_existe(contador);

                system("pause");


                break;
            case 3:
                contador = 0;


                for (i = 0; i < LIBROS; i++) {
                    mostrar_char(Libros[i].autor, i, &contador);
                }


                no_existe(contador);

                system("pause");


                break;
            case 4:
                contador = 0;


                for (i = 0; i < LIBROS; i++) {
                    mostrar_int(Libros[i].anno, i, &contador);
                }


                no_existe(contador);

                system("pause");


                break;
            case 5:
                contador = 0;


                for (i = 0; i < LIBROS; i++) {
                    mostrar_char(Libros[i].materia, i, &contador);
                }


                no_existe(contador);

                system("pause");


                break;
            case 6:
                contador = 0;


                for (i = 0; i < LIBROS; i++) {
                    mostrar_int(Libros[i].copias, i, &contador);
                }


                no_existe(contador);

                system("pause");


                break;
            case 7:
                contador = 0;


                mostrar_prestamos(Libros, &contador);
                no_existe(contador);

                system("pause");


                break;
            case 8:         /* CORRECCIÓN: (Lógica) Tener un case vacío no tiene mucho sentido.
                             *                      Hay mejores maneras de modelar la salida del menú */
                break;

            default:
                printf("Opci\242n inv\240lida. Por favor, seleccione un n\243mero del 1 al 8.\n");

                system("pause");


                break;
        }
        system("cls");
    } while (resp != 8);
}

/*Menu para mostrar los reportes*/
void menu_reportes(Registro Libros[] ) {
    int contador;

    int resp = 0;


    system("cls");


    do
    {
        printf("   Reportes \n");
        printf("1. Devolver los libros que en alg\243n mes fueron prestados todos sus ejemplares.\n");
        printf("2. Devolver los datos de los libros que pertenecen a una materia dada.\n");
        printf("3. Mostrar un reporte por a\244o de publicaci\242n con todos los datos de los libros del centro.\n");
        printf("4. Devolver el primer libro que m\240s veces se ha prestado.\n");
        printf("5. Dado el identificador de un libro, mostrar toda su informaci\242n.\n");
        printf("6. Terminar reportes.\n");


        do
        {
            fflush(stdin);

            printf("Introduzca (1-6) acorde a las necesidades:\n");
            scanf("%d", &resp);


            if (isalpha(resp) ) {
                printf("Error, por favor, ingrese un valor num\202rico.\n");
            }
        } while (isalpha(resp) );


        switch (resp) {
            case 1: {
                int mes;
                int fin;
                int valor;
                int posicion;

                contador = 0;


                system("cls");

                printf("1. Devolver los libros que en alg\243n mes fueron prestados todos sus ejemplares.\n\n");


                for (posicion = 0; posicion < LIBROS; posicion++) {
                    bool activar_nombre[2] = {false, false};

                    fin = 12;
                    valor = 0;


                    verificar_nombre_prestado(Libros, activar_nombre, &contador, posicion);
                    mostrar_nombre_libros_prestados(Libros, activar_nombre, posicion);


                    if (activar_nombre[0]) {
                        for (mes = 0; mes < MESES; mes++) {
                            bool activar_mes = false;

                            valor = calcular_libros_prestados(Libros, &activar_mes, posicion, mes);


                            if (activar_mes) {
                                mostrar_libros_prestados(&activar_mes, &contador, valor);
                            } else {
                                fin--;
                            }

                            if (fin == 0) {
                                printf("No fueron prestados todos sus ejemplares\n");
                            }
                        }
                    }
                }


                system("pause");


                break;
            }
            case 2:
                system("cls");

                printf("2. Devolver los datos de los libros que pertenecen a una materia dada.\n\n");

                libros_materia(Libros);

                system("pause");

            int mayor_valor = 0;
            int contador = 0;
            int guardar_libro = 0;

                break;
            case 3:
                system("cls");

                printf("3. Mostrar un reporte por a\244o de publicaci\242n con todos los datos de los libros del centro.\n\n");

                libros_anno(Libros);

                system("pause");


                break;
            case 4: {
                int contador = 0;
                int mayor_valor = 0;
                int guardar_libro = 0;


                system("cls");

                printf("4. Devolver el primer libro que m\240s veces se ha prestado.\n\n");


                mayor_valor = calcular_libros_mas_prestados(Libros, &contador, &guardar_libro);


                libros_mas_prestados(Libros, &guardar_libro, mayor_valor, &contador);

                system("pause");


                break;
            }
            case 5:
                system("cls");

                printf("5. Dado el identificador de un libro, mostrar toda su informaci\242n.\n\n");

                libros_identificador(Libros);

                system("pause");


                break;
            case 6:         /* CORRECCIÓN: (Lógica) Tener un case vacío no tiene mucho sentido.
                             *                      Hay mejores maneras de modelar la salida del menú */
                break;

            default:
                printf("Opci\242n inv\240lida. Por favor, seleccione un n\243mero del 1 al 6.\n");

                system("pause");


                break;
        }


        system("cls");
    } while (resp != 6);
}
