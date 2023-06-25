#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<Interfaz/validacion.h>


/* valida que el identificador no se repita y no sea menor ni igual que 0*/
void validar_identificador(Registro Libros[],int posicion)
{
    int i;
    int condicion;
    do {
        do{
            fflush(stdin);
            if(scanf("%ld", &Libros[posicion].identificador)!= 1)
            {
                printf("Error, no pueden ser letras\n");
                condicion = 0;
            }
            else if(Libros[posicion].identificador <= 0 && Libros[posicion].identificador != -1 )
            {
                printf("Error no puede ni menor ni igual a 0, introduzca otro\n");
                condicion = 0;
            }
            else if(Libros[posicion].identificador == -1){
                Libros[posicion].identificador =0;
                condicion =1;
            }
            else condicion =1;
        } while (!condicion);
        for(i = 0;i < LIBROS;i++)
            if(Libros[posicion].identificador == Libros[i].identificador && i != posicion && Libros[posicion].identificador != 0)
            {
                printf("Ya existe, introduzca otro\n");
                condicion = 0;
            }
    } while (!condicion);
}


/*Valida que el año sea menor que 2023*/
void validar_anno(int *anno)
{
    int condicion;
    do{
        fflush(stdin);
        validar_numero(anno);
        if(*anno > 2023) {
            printf("Error, por favor ingrese un a\244o menor que 2023.\n");
            condicion = 0;
        }
        else if(*anno == -1){
            *anno =0;
            condicion =1;
        }
        else condicion =1;
    }while (!condicion);
}


/*Validacion para que sean numeros y mayores que 0*/
void validar_numero(int *numero)
{
    int condicion;
    do {
        fflush(stdin);
        if(scanf("%d", numero) != 1 )
        {
            printf("Error, no pueden ser letras.\n");
            condicion = 0;
        }
        else if(*numero <= 0 && *numero < -1)
        {
            printf("Error no puede ser ni menor ni igual a 0, introduzca otro.\n");
            condicion = 0;
        }
        else if(*numero == -1){
            *numero =0;
            condicion =1;
        }
        else condicion = 1;
    } while (!condicion);
}


/*validacion para que solo exista un titulo*/
void validar_titulo(Registro Libros[], int posicion)
{
    int i;
    int condicion;


    do{
        validar_char(Libros[posicion].titulo,sizeof(Libros[i].autor)/sizeof(char));
        for (i = 0; i < LIBROS; i++)
        {
            if (i != posicion && strcmp(Libros[i].titulo, Libros[posicion].titulo) == 0)
            {
                printf("Ya existe, introduzca otro.\n");
                i = LIBROS;
                condicion = 0;
            }
            else if(strcmp(Libros[i].titulo, "-1")== 0){
                strcpy(Libros[i].titulo ,"0");
                condicion =1;
            }
            else condicion =1;
        }
    } while (!condicion);
}


/*Validar que no se use el caracter de fin de linea*/
void validar_char(char arreglo[],int tamano)
{
    do {
        fflush(stdin);
        fgets(arreglo, tamano, stdin);
        if (arreglo[0] != '\n')
        {
            size_t pos = strcspn(arreglo, "\n");
            arreglo[pos] = '\0';
        }
        else if(strcmp(arreglo, "-1")== 0){
            strcpy(arreglo ,"0");
        }
        else {
            printf("Error: se debe ingresar un valor.\n");
        }
    } while (arreglo[0] == '\n');
}


/*validar que los prestamos no sean mayores que las copias existentes*/
void validar_prestamos(int *numero, Registro Libros[], int posicion)
{
    int condicion;
    do {
        validar_numero(numero);
        if(*numero > Libros[posicion].copias)
        {
            printf("Error, solo hay %d copias disponibles\n", Libros[posicion].copias);
            condicion = 0;
        }
        else if(Libros[posicion].copias == -1){
            Libros[posicion].copias =0;
            condicion =1;
        }
        else condicion =1;
    } while (!condicion);
}


/* Funcion para validar la respuesta del usuario funciona con 1, 2, 3 ,y si, no y terminar*/
int validar_respuesta(char arreglo[],int cantidad)
{
    int i;
    int respuesta =0;
    int tamano;
    char *si[] = {"si","1"};
    char *no[] = {"no","2"};
    char *terminar[] = {"terminar","3"};
    char comparar1[9] = {""};
    do{
        fflush(stdin);
        tamano = cantidad;
        fgets(arreglo, tamano, stdin);
        tamano = strlen(arreglo);
        for(i=0 ; i < tamano ;i++)
        {
            if (arreglo[0] != '\n')
            {
                comparar1[i]=tolower(arreglo[i]);
                comparar1[strlen(arreglo)-1] = '\0';
            } else {
                printf("Error: se debe ingresar un valor.\n");
                i =tamano;
            }
        }
    }while (arreglo[0] == '\n');
    for(i=0; i < 2; i++)
    {
        if(strcmp(comparar1,si[i])==0){
            respuesta = 1;
        }
        else if (strcmp(comparar1,no[i])==0){
            respuesta = 2;
        }
        else if(strcmp(comparar1,terminar[i])==0){
            respuesta = 3;
        }
    }
    return respuesta;
}
