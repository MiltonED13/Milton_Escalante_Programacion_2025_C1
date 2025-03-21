#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Función para agregar un nodo al final de la lista
void agregarNodo(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        struct Nodo *temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Función para imprimir la lista
void imprimirLista(struct Nodo *cabeza) {
    struct Nodo *temp = cabeza;
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    agregarNodo(&cabeza, 10);
    agregarNodo(&cabeza, 20);
    agregarNodo(&cabeza, 30);

    imprimirLista(cabeza);
    return 0;
}
