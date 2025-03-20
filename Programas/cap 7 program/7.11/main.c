#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Verifica.
El programa, al recibir como datos un cadena de caracteres y una posicion
especifica en la cadena, determina si el caracter correspondiente es una letra
minuscula. */

void main(void)
{
    char p, cad[50];
    int n;

    printf(("\nIngrese la cadena de caracteres (maximo 50): "));
    gets(cad);

    printf("\nIngrese la posicion en la cadena que desea verificar: ");
    scanf("%d", &n);

    if((n >= 0) && (n < 50))
    {
        p = cad[n - 1];

        if(islower(p))
        {
            printf("\n%c es una letra minuscula", p);
        }
        else
        {
            printf("\n%c no es una letra minuscula", p);
        }
    }
    else
    {
        printf("\nEL valor ingresado de n es incorrecto");
    }
}
