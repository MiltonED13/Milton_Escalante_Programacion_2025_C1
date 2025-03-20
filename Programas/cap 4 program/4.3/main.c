#include <stdio.h>
#include <stdlib.h>

/* Conflicto de variables con el mismo nombre. */

void f1(void);  //Prototipo de funcion
int K = 5;      //Variable global

void main (void)
{
    int I;
    for (I = 1; I <= 3; I++)
    {
        f1();
    }
}

void f1(void)
{
    /* La funcion utiliza tanto la variable local I como la
    variable global I. */

    int K = 2; //Variable local

    K += K;

    printf("\n\nEl valor de la variable local es: %d", K);

    K += K; //Uso de ambos variables

    /* Segun el libro para referirse a la variable global se utiliza el simbolo ::
    sin embargo esto solo es posible en el lenguaje C++, en el lenguaje C no es posible
    y por ende da error, para esto se recomienda que las variables local y globales
    tengan nombres distintos. */

    printf("\nEl valor de la variable global es: %d", K);
}
