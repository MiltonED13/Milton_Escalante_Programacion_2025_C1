#include <stdio.h>
#include <stdlib.h>

/* Incorpora caracteres.

El programa agrega caracteres el archivo libro.txt. */

void main(void)
{
    char p1;
    FILE *ar;

    ar = fopen("C:\\Archivos de Codeblock\\libro.txt", "a");
    // Se abre el archivo con la opcion para incorporar caracteres.

    if(ar != NULL)
    {
        while((p1 = getchar()) != '\n')
        {
            fputc(p1, ar);
        }
        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }
}
