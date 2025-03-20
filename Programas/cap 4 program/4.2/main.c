#include <stdio.h>
#include <stdlib.h>

/* Cubo-2

El programa calcula el cubo de los 10 primeros numeros naturales
con la ayuda de una funcion.*/

int cubo (void); //Prototipo de funcion
int I;           //Variable global


void main(void)
{
    int CUB;
    for (I = 1; I <= 10; I++)
    {
        CUB = cubo();  //Llamada a la funcion cubo.

        //Presentacion del cubo de los primeros 10 numeros naturales
        printf("\nEl cubo de %d es: %d", I, CUB);
    }
}

int cubo(void) //Declaracion de la funcion
{
    int I = 2; //Variable local entera I con el mismo nombre que la variable global.

    /*La variable local I tiene prioridad sobre la variable global
    que tiene el mismo nombre y por esta razon siempre calcula el
    cubo del numero entero 2.*/

    return(I*I*I); //La funcion calcula el cubo de la variable global I.
}
