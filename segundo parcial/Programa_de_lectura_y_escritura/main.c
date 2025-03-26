#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos la estructura para almacenar información de carros
typedef struct {
    char marca[50];
    char modelo[50];
    int ano;
    char tipo_motor[50];
    float precio;
} Carro;

// Funcion para escribir datos en el archivo
void escritura(Carro *carros, int cantidad, const char *narchivo) {
    FILE *archivo = fopen(narchivo, "wb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para escritura");
        return;
    }
    fwrite(carros, sizeof(Carro), cantidad, archivo);
    fclose(archivo);
    printf("\nDatos guardados exitosamente en el archivo.\n");
}

// Funcion para leer datos desde el archivo
void lectura(Carro **carros, int *cantidad, const char *narchivo) {
    FILE *archivo = fopen(narchivo, "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo para lectura");
        return;
    }

    fseek(archivo, 0, SEEK_END);
    long size = ftell(archivo);
    rewind(archivo);

    *cantidad = size / sizeof(Carro);
    Carro *temp = (Carro *)realloc(*carros, size);
    if (temp == NULL) {
        perror("Error al asignar memoria");
        fclose(archivo);
        return;
    }
    *carros = temp;

    fread(*carros, sizeof(Carro), *cantidad, archivo);
    fclose(archivo);
    printf("\nDatos cargados exitosamente.\n");

    Estadisticas(*carros, *cantidad);
}

// Función para mostrar estadísticas de los carros almacenados
typedef struct {
    char marca[50];
    int cantidad;
} MarcaConteo;

void Estadisticas(Carro *carros, int cantidad) {
    if (cantidad == 0) {
        printf("\nNo hay carros registrados.\n");
        return;
    }

    float precioMin = carros[0].precio;
    float precioMax = carros[0].precio;
    MarcaConteo marcas[100];
    int numMarcas = 0;

    for (int i = 0; i < cantidad; i++) {
        if (carros[i].precio < precioMin) precioMin = carros[i].precio;
        if (carros[i].precio > precioMax) precioMax = carros[i].precio;

        int nuevaMarca = 1;
        for (int j = 0; j < numMarcas; j++) {
            if (strcmp(marcas[j].marca, carros[i].marca) == 0) {
                marcas[j].cantidad++;
                nuevaMarca = 0;
                break;
            }
        }
        if (nuevaMarca) {
            strcpy(marcas[numMarcas].marca, carros[i].marca);
            marcas[numMarcas].cantidad = 1;
            numMarcas++;
        }
    }

    printf("\n----- Estadisticas de Carros -----\n");
    printf("- Total de carros: %d\n", cantidad);
    printf("- Precio minimo: $%.2f\n", precioMin);
    printf("- Precio maximo: $%.2f\n", precioMax);
    printf("- Marcas registradas: %d\n", numMarcas);
    for (int i = 0; i < numMarcas; i++) {
        printf("  - %s: %d unidades\n", marcas[i].marca, marcas[i].cantidad);
    }
}

// Función para listar los carros almacenados
target_listar(Carro *carros, int cantidad) {
    printf("\nListado de carros:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("\nCarro %d:\n", i + 1);
        printf(" Marca: %s\n", carros[i].marca);
        printf(" Modelo: %s\n", carros[i].modelo);
        printf(" Ano: %d\n", carros[i].ano);
        printf(" Tipo de motor: %s\n", carros[i].tipo_motor);
        printf(" Precio: $%.2f\n", carros[i].precio);
    }
}

// Función principal del programa
int main() {
    Carro *carros = NULL;
    int cantidad = 0;
    int opcion;
    const char *narchivo = "carros.dat";

    do {
        printf("\n===== Milton Auto Dealer =====\n");
        printf("\nMenu:\n");
        printf("1. Registrar nuevos carros\n");
        printf("2. Cargar carros desde el archivo\n");
        printf("3. Listar carros registrados\n");
        printf("4. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                printf("\nCantidad de carros a registrar: ");
                scanf("%d", &cantidad);
                getchar();

                carros = (Carro *)realloc(carros, cantidad * sizeof(Carro));
                for (int i = 0; i < cantidad; i++) {
                    printf("\nCarro %d:\n", i + 1);
                    printf("Marca: "); fgets(carros[i].marca, 50, stdin); strtok(carros[i].marca, "\n");
                    printf("Modelo: "); fgets(carros[i].modelo, 50, stdin); strtok(carros[i].modelo, "\n");
                    printf("Ano: "); scanf("%d", &carros[i].ano); getchar();
                    printf("Tipo de motor: "); fgets(carros[i].tipo_motor, 50, stdin); strtok(carros[i].tipo_motor, "\n");
                    printf("Precio: "); scanf("%f", &carros[i].precio); getchar();
                }
                escritura(carros, cantidad, narchivo);
                break;
            case 2:
                lectura(&carros, &cantidad, narchivo);
                break;
            case 3:
                target_listar(carros, cantidad);
                break;
            case 4:
                printf("\nGracias, le contactamos luego\n");
                break;
            default:
                printf("\nOpción inválida, intenta de nuevo.\n");
        }
    } while (opcion != 4);

    free(carros);
    return 0;
}
