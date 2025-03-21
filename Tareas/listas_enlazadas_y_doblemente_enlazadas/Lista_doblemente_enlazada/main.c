#include <stdio.h>
#include <stdlib.h>

// Definicion de la estructura de un nodo
struct NodoDoble {
    int dato;
    struct NodoDoble *siguiente;
    struct NodoDoble *anterior;
};

// Funcion para agregar un nodo al final de la lista
void agregarNodoDoble(struct NodoDoble **cabeza, int valor) {
    struct NodoDoble *nuevoNodo = (struct NodoDoble *)malloc(sizeof(struct NodoDoble));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        struct NodoDoble *temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->anterior = temp;
    }
}

// Funcion para imprimir la lista de adelante hacia atras
void imprimirListaAdelante(struct NodoDoble *cabeza) {
    struct NodoDoble *temp = cabeza;
    while (temp != NULL) {
        printf("%d <-> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

// Funcion para imprimir la lista de atras hacia adelante
void imprimirListaAtras(struct NodoDoble *cabeza) {
    struct NodoDoble *temp = cabeza;
    while (temp != NULL && temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->dato);
        temp = temp->anterior;
    }
    printf("NULL\n");
}

int main() {
    struct NodoDoble *cabeza = NULL;
    agregarNodoDoble(&cabeza, 10);
    agregarNodoDoble(&cabeza, 20);
    agregarNodoDoble(&cabeza, 30);

    printf("Lista de adelante hacia atras:\n");
    imprimirListaAdelante(cabeza);

    printf("Lista de atras hacia adelante:\n");
    imprimirListaAtras(cabeza);

    return 0;
}
