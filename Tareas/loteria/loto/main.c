#include <stdio.h>
#include <stdlib.h>

#define MAX_CLIENTES 99          // Maximo numero de clientes permitidos
#define ARCHIVO_PREMIOS "premios.txt" // Nombre del archivo para almacenar los numeros jugados

// Estructura para representar un cliente con su numero de loteria
typedef struct {
    int numero;  // Numero elegido por el cliente
} Cliente;

Cliente *clientes[MAX_CLIENTES];  // Arreglo de punteros a Cliente
int totalClientes = 0;            // Contador de clientes registrados
int historialNumeros[100] = {0};  // Historial de numeros sorteados

// Funcion para cargar el historial de numeros sorteados desde un archivo
void cargarHistorial() {
    FILE *archivo = fopen(ARCHIVO_PREMIOS, "r");
    if (archivo) {
        int numero;
        // Lee todos los numeros sorteados en el archivo y actualiza el historial
        while (fscanf(archivo, "%d", &numero) != EOF) {
            if (numero >= 1 && numero <= 99) {
                historialNumeros[numero]++;
            }
        }
        fclose(archivo);
    }
}

// Funcion para guardar un numero sorteado en el archivo
void guardarNumero(int numero) {
    FILE *archivo = fopen(ARCHIVO_PREMIOS, "a");
    if (archivo) {
        fprintf(archivo, "%d\n", numero);
        fclose(archivo);
    }
    historialNumeros[numero]++;
}

// Funcion para registrar un nuevo cliente con su numero de loteria
void jugar() {
    if (totalClientes < MAX_CLIENTES) {
        clientes[totalClientes] = (Cliente *)malloc(sizeof(Cliente));  // Asigna memoria para un nuevo cliente
        if (!clientes[totalClientes]) {
            printf("Error: No se pudo asignar memoria.\n");
            return;
        }

        int num;
        do {
            printf("Ingrese su numero para jugar (1-99): ");  // Solicita el numero del cliente
            if (scanf("%d", &num) != 1) {  // Verifica si la entrada es un numero valido
                printf("Entrada invalida. Intente de nuevo.\n");
                while (getchar() != '\n');  // Limpia el buffer de entrada
                continue;
            }
            if (num < 1 || num > 99) {  // Verifica si el numero esta en el rango permitido
                printf("Numero fuera de rango. Debe estar entre 1 y 99.\n");
            }
        } while (num < 1 || num > 99);  // Repite la solicitud hasta obtener un numero valido

        clientes[totalClientes]->numero = num;  // Asigna el numero al cliente
        totalClientes++;  // Incrementa el contador de clientes registrados
        printf("Numero registrado con exito.\n");
    } else {
        printf("No se pueden registrar mas clientes.\n");
    }
}

// Funcion para listar los numeros que han salido en los sorteos anteriores
void listarNumerosSalidos() {
    printf("\nHistorial de numeros sorteados:\n");
    for (int i = 1; i < 100; i++) {
        if (historialNumeros[i] > 0) {
            printf("Numero %d ha salido %d veces.\n", i, historialNumeros[i]);  // Muestra cuantas veces han salido los numeros
        }
    }
}

// Funcion para realizar un sorteo y asignar premios a los clientes
void tirarNumeros() {
    int oro, plata, bronce;
    FILE *archivoResultados = fopen("resultados_loteria.txt", "a");  // Abre el archivo de resultados en modo append

    if (!archivoResultados) {
        printf("Error al abrir el archivo de resultados.\n");
        return;
    }

    // Genera tres numeros aleatorios diferentes entre 1 y 99 para los premios
    do {
        oro = (rand() % 99) + 1;
        plata = (rand() % 99) + 1;
        bronce = (rand() % 99) + 1;
    } while (oro == plata || oro == bronce || plata == bronce);  // Asegura que los tres numeros sean distintos

    printf("\nNumeros sorteados: ORO(%d) PLATA(%d) BRONCE(%d)\n", oro, plata, bronce);  // Muestra los numeros sorteados

    // Guarda los numeros sorteados en el archivo
    guardarNumero(oro);
    guardarNumero(plata);
    guardarNumero(bronce);

    int Ganador = 0;
    // Verifica si algun cliente ha acertado alguno de los numeros sorteados
    for (int i = 0; i < totalClientes; i++) {
        int aciertos = 0;
        if (clientes[i]->numero == oro) aciertos++;
        if (clientes[i]->numero == plata) aciertos++;
        if (clientes[i]->numero == bronce) aciertos++;

        // Asigna premios segun el numero de aciertos
        if (aciertos == 3) {
            fprintf(archivoResultados, "Cliente con numero %d gana $1,000,000 de pesos.\n", clientes[i]->numero);
            printf("\nCliente con numero %d gana $1,000,000 de pesos.\n", clientes[i]->numero);
            Ganador = 1;
        } else if (aciertos == 2) {
            fprintf(archivoResultados, "Cliente con numero %d gana $500,000.00 pesos.\n", clientes[i]->numero);
            printf("\nCliente con numero %d gana $500,000.00 pesos.\n", clientes[i]->numero);
            Ganador = 1;
        } else if (aciertos == 1) {
            if (clientes[i]->numero == oro) {
                fprintf(archivoResultados, "Cliente con numero %d gana $100,000 pesos por Oro.\n", clientes[i]->numero);
                printf("\nCliente con numero %d gana $100,000 pesos por Oro.\n", clientes[i]->numero);
            } else if (clientes[i]->numero == plata) {
                fprintf(archivoResultados, "Cliente con numero %d gana $75000 pesos por Plata.\n", clientes[i]->numero);
                printf("\nCliente con numero %d gana $75000 pesos por Plata.\n", clientes[i]->numero);
            } else if (clientes[i]->numero == bronce) {
                fprintf(archivoResultados, "Cliente con numero %d gana $50000 pesos por Bronce.\n", clientes[i]->numero);
                printf("\nCliente con numero %d gana $50000 pesos por Bronce.\n", clientes[i]->numero);
            }
            Ganador = 1;
        }
    }


    if (!Ganador) {
        fprintf(archivoResultados, "No hubo ganadores en este sorteo.\n");
        printf("\nNo hubo ganadores en este sorteo.\n");
    }

    fclose(archivoResultados);  // Cierra el archivo de resultados
}

// Funcion para liberar la memoria reservada para los clientes
void liberarMemoria() {
    for (int i = 0; i < totalClientes; i++) {
        free(clientes[i]);
    }
    totalClientes = 0;
}

// Funcion principal
int main() {
    int seed_variable;
    srand((unsigned int)&seed_variable);  // Usa la direccion de memoria como semilla para rand()

    int opcion;
    cargarHistorial();  // Carga el historial de numeros sorteados desde el archivo

    do {
        printf("\n===== Loteka no te toca =====");
        printf("\n MENU \n");
        printf("1. Jugar (Registrar Cliente)\n");
        printf("2. Lista de Numeros Salidos\n");
        printf("3. Tirar Numeros\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {  // Verifica que la entrada sea valida
            printf("Entrada invalida. Intente de nuevo.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcion) {
            case 1: jugar(); break;  // Registra un nuevo cliente
            case 2: listarNumerosSalidos(); break;  // Muestra los numeros sorteados
            case 3: tirarNumeros(); break;  // Realiza el sorteo
            case 4: printf("Gracias por su confianza...\n"); break;  // Sale del programa
            default: printf("Opcion no valida.\n");
        }
    } while (opcion != 4);  // Repite el menu hasta que el usuario elija salir

    liberarMemoria();  // Libera la memoria antes de terminar el programa
    return 0;
}
