#include <stdio.h>
#include <stdlib.h>

/* Archivos con variables enteras y reales.

El programa lee datos de alumnos almacenados en un archivo y escribe la
matricula y el promedio de cada alumno. */

void main(void)
{
    int i, j, n, mat;
    float cal, pro;
    FILE *ar;

    if((ar = fopen("C:\\Archivos de Codeblock\\arc8.txt", "r")) != NULL)
    {
        fscanf(ar, "%d", &n); // Se lee el valor de n.

        for(i = 0; i < n; i++)
        {
            fscanf(ar, "%d", &mat); // Se lee la matricula de cada alumno.
            printf("%d\t", mat);
            pro = 0;

            for(j = 0; j < 5; j++)
            {
                fscanf(ar, "%f", &cal); // Se leen las cinco calificaciones del alumno.
                pro += cal;
            }
            printf("\t %.2f  ", pro / 5); // Se escribe el promedio de cada alumno.

            printf("\n");
        }
        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo");
    }
}
