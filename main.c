#include "Interfaz\Menus.h"


/* En un centro de investigación se desea llevar un registro de los libros que se
 * prestan. De cada libro se conoce identificador, título, autor, año de
 * publicación, materia a la que pertenece, cantidad de copias y número de
 * préstamos en cada uno de los meses del año. Se desea diseñar una
 * aplicación que permita: */

/* a) Devolver los libros que en algún mes fueron prestados todos sus ejemplares.
 * b) Devolver los datos de los libros que pertenecen a una materia dada.
 * c) Mostrar un reporte por año de publicación con todos los datos de los libros del centro.
 * d) Devolver el primer libro que más veces se ha prestado.
 * e) Dado el identificador de un libro, mostrar toda su información. */


/* Asumo que solo hay espacio para 5 libros en la librería. */

/* El espacio de los libros se puede cambiar en Datos.h pero los datos inicializados de manera
 * automática mostrarán caracteres extraños si son más de 5 libros.*/



int main(void) {
    Registro Libros[LIBROS];


    menu(Libros);


    return 0;
}

/* version 10.0 */
