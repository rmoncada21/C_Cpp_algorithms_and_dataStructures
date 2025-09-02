#include <stdlib.h>
#include <stdio.h>

#define SIZE 10
#define SALTO putchar('\n');

void mostrar_arreglo(int[], int);
void randomize_arreglo(int[], int);
void selection_sort(int[], int);

int main() {
    int arreglo[SIZE] = {};
    mostrar_arreglo(arreglo, SIZE);
    randomize_arreglo(arreglo, SIZE);
    mostrar_arreglo(arreglo, SIZE);
    selection_sort(arreglo, SIZE);
    mostrar_arreglo(arreglo, SIZE);
    return 0;
}

void mostrar_arreglo(int arreglo[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arreglo[i]);
    }
    SALTO;
    return;
}

void randomize_arreglo(int arreglo[], int size) {
    for (int i = 0; i < size; i++) {
        arreglo[i] = rand()%100;
    }
    SALTO;
    return;
}

void selection_sort(int arreglo[], int size) {
    for (int i = 0; i < size; i++) {
        int indice = i;

        for (int j = i+1; j < size; j++) {
            if (arreglo[j] < arreglo[indice]) {
                indice = j;
            }
        }

        if (indice != i) {
            int temporal = arreglo[i];
            arreglo[i] = arreglo[indice];
            arreglo[indice] = temporal;
        }
    }
}
