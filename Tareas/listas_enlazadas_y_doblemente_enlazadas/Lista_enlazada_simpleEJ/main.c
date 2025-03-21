#include <stdio.h>
#include <stdlib.h>

// Definicion de la estructura de un nodo
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Funcion para agregar un nodo al final de la lista
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

// Funcion para imprimir la lista
void imprimirLista(struct Nodo *cabeza) {
    struct Nodo *temp = cabeza;
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

// Funcion para invertir la lista enlazada
void invertirLista(struct Nodo **cabeza) {
    struct Nodo *prev = NULL;
    struct Nodo *current = *cabeza;
    struct Nodo *next = NULL;

    while (current != NULL) {
        next = current->siguiente;  // Guardar el siguiente nodo
        current->siguiente = prev;  // Invertir el enlace
        prev = current;             // Mover el puntero prev al nodo actual
        current = next;             // Mover el puntero current al siguiente nodo
    }
    *cabeza = prev;  // El ultimo nodo procesado se convierte en el nuevo cabeza
}

int main() {
    struct Nodo *cabeza = NULL;

    // Agregar nodos a la lista
    agregarNodo(&cabeza, 10);
    agregarNodo(&cabeza, 20);
    agregarNodo(&cabeza, 30);
    agregarNodo(&cabeza, 40);

    printf("Lista original:\n");
    imprimirLista(cabeza);

    // Invertir la lista
    invertirLista(&cabeza);

    printf("Lista despues de invertir:\n");
    imprimirLista(cabeza);

    return 0;
}
