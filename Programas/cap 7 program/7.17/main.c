#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Cadena invertida.

El programa obtiene la cadena invertida. */

char * inversor(char *);  //Prototipo de funcion.

void main(void)
{
    char fra[50], aux[50];

    printf("\nIngrese la linea de texto: ");
    gets(fra);
    strcpy(aux, inversor(fra)); //Se copia a aux el resultado de la funcion inversor.

    printf("\nEscribe la linea de texto en forma inversa: ");
    puts(aux);
}

char * inversor(char *cadena)
{
/* La funcion calcula el inverso de una cadena y regresa el resultado al
programa principal. */

int i = 0, j, lon;
char cad;
lon = strlen(cadena);
j = lon - 1;

while(i < ((lon - 1) / 2))
{
    /* Observa que el reemplazo de los caracteres se debe realizar solamente
    hasta la mitad de la cadena. */

    cad = cadena[i];
    cadena[i] = cadena[j];
    cadena[j] = cad;

    i++;
    j++;
}
return (cadena);
}
