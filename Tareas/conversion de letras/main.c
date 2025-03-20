#include <stdio.h>

int main() {
    char letra;

    // Pedir al usuario que ingrese una letra
    printf("Ingresa una letra: ");
    scanf("%c", &letra);

    // Verificar si el car�cter ingresado es una letra
    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) {
        // Verificar si la letra es may�scula o min�scula
        if (letra >= 'A' && letra <= 'Z') {
            // Si es may�scula, convertir a min�scula
            letra = letra + 32;  // 'A' a 'a' es una diferencia de 32 en la tabla ASCII
            printf("La letra convertida es: %c\n", letra);
        } else {
            // Si es min�scula, convertir a may�scula
            letra = letra - 32;  // 'a' a 'A' es una diferencia de 32 en la tabla ASCII
            printf("La letra convertida es: %c\n", letra);
        }
    } else {
        // Si el car�cter no es una letra
        printf("No ingresaste una letra v�lida.\n");
    }

    return 0;
}


