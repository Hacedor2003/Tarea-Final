#ifndef DATOS_H
    #define DATOS_H


    #define LIBROS 5
    #define MESES 12


    typedef struct registro {
        long identificador;
        int copias;
        int anno;
        int numero_prestamos[MESES];
        char materia[50];
        char titulo[50];
        char autor[50];
    } Registro;
#endif
