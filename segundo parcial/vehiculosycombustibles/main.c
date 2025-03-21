#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//maximo numero de vehiculos a registrar (3 vehiculos)
#define MAX_VEHICULOS 3

// Estructura para almacenar los datos de un vehiculo
typedef struct {
    char marca[50];   // Marca del vehiculo
    char modelo[50];  // Modelo del vehiculo
    float consumo;    // Consumo de combustible por km (en galones)
} Vehiculo;

// Funcion para ingresar los datos de un vehiculo
void ingresarVehiculo(Vehiculo *v) {
    printf("Ingrese la marca del vehiculo: ");
    getchar();  // Para limpiar el buffer
    fgets(v->marca, 50, stdin); // Leer la marca
    v->marca[strcspn(v->marca, "\n")] = '\0'; // Eliminar el salto de linea

    printf("Ingrese el modelo del vehiculo: ");
    fgets(v->modelo, 50, stdin); // Leer el modelo
    v->modelo[strcspn(v->modelo, "\n")] = '\0'; // Eliminar el salto de linea

    printf("Ingrese el consumo de combustible por km (en galones): ");
    scanf("%f", &v->consumo);  // Leer el consumo por km
}

// Funcion para guardar los datos de los vehículos en un archivo binario
void guardarVehiculos(Vehiculo vehiculos[], int totalVehiculos, float precioCombustible) {
    FILE *archivo = fopen("vehiculos.dat", "wb");  // Abrir el archivo en modo binario para escritura
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar.\n");
        exit(1); // Si hay error al abrir el archivo, salir
    }

    fwrite(&totalVehiculos, sizeof(int), 1, archivo);  // Guardamos la cantidad de vehiculos
    fwrite(vehiculos, sizeof(Vehiculo), totalVehiculos, archivo);  // Guardamos los datos de los vehiculos
    fwrite(&precioCombustible, sizeof(float), 1, archivo);  // Guardamos el precio del combustible

    fclose(archivo);  // Cerrar el archivo
}

// Funcion para leer los datos desde el archivo y mostrar la informacion
void leerVehiculosYMostrar(float precioCombustible) {
    FILE *archivo = fopen("vehiculos.dat", "rb");  // Abrir el archivo en modo binario para lectura
    if (archivo == NULL) {
        printf("Error al abrir el archivo para leer.\n");
        exit(1); // Si hay error al abrir el archivo, salir
    }

    int totalVehiculos;
    fread(&totalVehiculos, sizeof(int), 1, archivo);  // Leer la cantidad de vehiculos

    Vehiculo vehiculo;  // Variable para almacenar los datos de un vehiculo
    printf("\nInformacion de los vehiculos:\n");
    printf("Marca\tModelo\tCosto por galon\tCosto total\n");

    // Leer los datos de cada vehiculo y calcular el costo total
    for (int i = 0; i < totalVehiculos; i++) {
        fread(&vehiculo, sizeof(Vehiculo), 1, archivo);  // Leer un vehiculo
        float costoTotal = vehiculo.consumo * precioCombustible;  // Calcular el costo total
        printf("%s\t%s\t%.2f\t%.2f\n", vehiculo.marca, vehiculo.modelo, vehiculo.consumo, costoTotal);
    }

    fclose(archivo);  // Cerrar el archivo
}

int main() {
    Vehiculo vehiculos[MAX_VEHICULOS];  // Arreglo para almacenar los vehiculos
    int totalVehiculos = 0;
    float precioCombustible;

    // Ingresar el precio del combustible por galon
    printf("Ingrese el precio del combustible por galon: ");
    scanf("%f", &precioCombustible);

    // Validar el numero de vehiculos a registrar
    printf("Cuantos vehiculos desea registrar? (Maximo 3 vehiculos): ");
    scanf("%d", &totalVehiculos);

    if (totalVehiculos > MAX_VEHICULOS) {
        printf("Error: Solo puede registrar un máximo de 3 vehiculos.\n");
        return 1; // Terminar el programa si el número de vehículos es mayor que el maximo permitido
    }

    // Ingresar los datos de los vehiculos
    for (int i = 0; i < totalVehiculos; i++) {
        printf("\nVehiculo %d:\n", i + 1);
        ingresarVehiculo(&vehiculos[i]);
    }

    // Guardar los vehículos en el archivo
    guardarVehiculos(vehiculos, totalVehiculos, precioCombustible);

    // Leer los datos del archivo y mostrar la informacion
    leerVehiculosYMostrar(precioCombustible);

    return 0;
}
