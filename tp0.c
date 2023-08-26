/*
    Lazo Sebastian Nahuel  
    106213 
    Algoritmos II 95.12
    2do cuatrimestre 2023
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum TIPO { NORMAL, FUEGO, AGUA, PLANTA, ELECTRICO, ROCA };

struct ataque {
    char nombre[20];
    enum TIPO tipo;
    unsigned int poder;
};

struct ataque *parsear_ataque(char *texto, struct ataque *ataque);
enum TIPO asignarTipo(char inicialTipo);

int main()
{
    struct ataque un_ataque;
    int errores = 0;
  
    if (parsear_ataque("", &un_ataque) != NULL) {
        printf("Se espera que no se pueda parsear un string vacío D:\n");
        errores++;
    } else

    if (parsear_ataque("Rayo;E;", &un_ataque) != NULL) {
        printf("Se espera que no se pueda parsear un string incorrecto D:\n");
        errores++;
    } else
  printf("Parseo de un string incorrecto bien ahi\n");


    if (parsear_ataque("Rayo;E;5", &un_ataque) == NULL) {
        printf("Se espera que se pueda parsear un string correcto D:\n");
        errores++;
    } else if (strcmp(un_ataque.nombre, "Rayo") == 0 &&
         un_ataque.tipo == ELECTRICO && un_ataque.poder == 5) {
        printf("Parseo de un string correcto :)\n");
    } else {
        printf("Se parseó el string pero los valores son incorrectos :/\n");
        errores++;
    }

    //imprimo para comprobar que se lleno la estructura
    printf("\nNombre: %s\nTipo:%u\nPoder: %u\n", un_ataque.nombre , un_ataque.tipo , un_ataque.poder );

    return errores;
}



//la funcion en lo posible debe hacer una sola cosa , creo una funcion especifica para asignar el tipo 
struct ataque *parsear_ataque(char *texto, struct ataque *ataque)
{
    //inicializo las variables a las que les voy a asignar los valores 
     char nombre[20] ="";
     char inicialTipo = '\0';
     unsigned int poder = 0;

    //verifico que el String no este vacio 
    if(texto[0] != '\0')
    {
        //sscanf permite separar la cadena segun el formato , le asigno un tipo de dato adecuado
        sscanf( texto,"%[^;];%c;%u", nombre , &inicialTipo ,&poder );

        //printf("\n:|%c|\n",inicialTipo);

        //verifico quetodos los campos tengan información
        if (nombre[0] == '\0' || inicialTipo == '\0' || poder == 0)
        {
            return NULL;
        }

    // printf("\nTexto recibido: %s\n",texto);

     strcpy(ataque->nombre,nombre);

     ataque->poder = poder;
   
     ataque->tipo = asignarTipo(inicialTipo);

     return ataque;
    
    }
        return NULL;
  
}


//esta funcion devuelve el tipo segun la inicial ,siendo Normal el tipo default
enum TIPO asignarTipo( char inicialTipo)
{
    //NORMAL, FUEGO, AGUA, PLANTA, ELECTRICO, ROCA

    switch(inicialTipo)
    {
        case 'N':
            return NORMAL;
            break;

        case 'F':
            return FUEGO;
            break;
        
        case 'A':
            return AGUA;
            break;

         case 'P':
            return PLANTA;
            break;

        case 'E':
            return ELECTRICO;
            break;

        case 'R':
            return ROCA;
            break;
        
        
        
        default : 
            return NORMAL;

    }

}