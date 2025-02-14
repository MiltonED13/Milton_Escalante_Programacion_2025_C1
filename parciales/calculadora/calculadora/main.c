#include <stdio.h>
#include <stdlib.h>

#define SUMA 1
#define RESTA 2
#define MULTIPLICACION 3
#define DIVISION 4
#define RAIZ_CUADRADA 5
#define POTENCIA_CUADRADO 6



int main() {
    float numero1 = 0.0;
    float numero2 = 0.0;
    float result = 0.0;
    int menu = 0;

    do {
        // Menú de opciones
        printf("\n0-Salir\n1-Suma\n2-Resta\n3-Multiplicacion\n4-Division\n5-Raiz cuadrada\n6-Potencia al cuadrado\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &menu);

        // Funciones matematicas
float suma(float a, float b) {
    return a + b;
}

float resta(float a, float b) {
    return a - b;
}

float multiplicacion(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    if (b == 0) {
        printf("\nError: División por cero no permitida.\n");
        return 0;
    }
    return a / b;
}

float raiz_cuadrada(float a) {
    if (a < 0) {
        printf("\nError: No se puede calcular la raíz cuadrada de un número negativo.\n");
        return 0;
    }
    float resultado = a;
    float diferencia;
    do {
        diferencia = resultado - (a / resultado);
        if (diferencia < 0) diferencia = -diferencia;
        resultado = (resultado + a / resultado) / 2;
    } while (diferencia > 0.01);
    return resultado;
}

float potencia_cuadrado(float a) {
    return a * a;
}

        switch(menu) {
            case SUMA:
                printf("\nIngresa el primer número: ");
                scanf("%f", &numero1);
                printf("\nIngresa el segundo número: ");
                scanf("%f", &numero2);
                result = suma(numero1, numero2);
                printf("\nEl resultado de la suma es: %f\n", result);
                break;

            case RESTA:
                printf("\nIngresa el primer número: ");
                scanf("%f", &numero1);
                printf("\nIngresa el segundo número: ");
                scanf("%f", &numero2);
                result = resta(numero1, numero2);
                printf("\nEl resultado de la resta es: %f\n", result);
                break;

            case MULTIPLICACION:
                printf("\nIngresa el primer número: ");
                scanf("%f", &numero1);
                printf("\nIngresa el segundo número: ");
                scanf("%f", &numero2);
                result = multiplicacion(numero1, numero2);
                printf("\nEl resultado de la multiplicación es: %f\n", result);
                break;

            case DIVISION:
                printf("\nIngresa el primer número: ");
                scanf("%f", &numero1);
                printf("\nIngresa el segundo número: ");
                scanf("%f", &numero2);
                result = division(numero1, numero2);
                if (numero2 != 0) {
                    printf("\nEl resultado de la división es: %f\n", result);
                }
                break;

            case RAIZ_CUADRADA:
                printf("\nIngresa un número: ");
                scanf("%f", &numero1);
                result = raiz_cuadrada(numero1);
                if (numero1 >= 0) {
                    printf("\nEl resultado de la raíz cuadrada es: %f\n", result);
                }
                break;

            case POTENCIA_CUADRADO:
                printf("\nIngresa un número: ");
                scanf("%f", &numero1);
                result = potencia_cuadrado(numero1);
                printf("\nEl resultado de la potencia al cuadrado es: %f\n", result);
                break;

            case 0:
                printf("\nFin de programa\n");
                break;

            default:
                printf("\nOpción no válida. Por favor, seleccione una opción válida.\n");
        }
    } while (menu != 0);

    return 0;
}
