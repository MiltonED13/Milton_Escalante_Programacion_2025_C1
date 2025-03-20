#include <stdio.h>

int main() {
    char letra;

    // Pedir al usuario que ingrese una letra
    printf("Ingresa una letra: ");
    scanf("%c", &letra);

    // Verificar si el carácter ingresado es una letra
    if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) {
        // Verificar si la letra es mayúscula o minúscula
        if (letra >= 'A' && letra <= 'Z') {
            // Si es mayúscula, convertir a minúscula
            letra = letra + 32;  // 'A' a 'a' es una diferencia de 32 en la tabla ASCII
            printf("La letra convertida es: %c\n", letra);
        } else {
            // Si es minúscula, convertir a mayúscula
            letra = letra - 32;  // 'a' a 'A' es una diferencia de 32 en la tabla ASCII
            printf("La letra convertida es: %c\n", letra);
        }
    } else {
        // Si el carácter no es una letra
        printf("No ingresaste una letra válida.\n");
    }

    return 0;
}


