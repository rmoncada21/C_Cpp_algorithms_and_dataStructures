#include <stdlib.h>
#include <stdio.h>

#define SIZE 10
#define SALTO putchar('\n')

void mostrar_arreglo(int[], int size);
void randomize_arreglo(int[], int size);
void insertion_sort(int[], int size);

int main() {
    int arreglo[SIZE] = {};
    srand(1);
    mostrar_arreglo(arreglo, SIZE);
    randomize_arreglo(arreglo, SIZE);
    mostrar_arreglo(arreglo, SIZE);
    insertion_sort(arreglo, SIZE);
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
        // arreglo[i] = rand()%100;
        *(arreglo+i) = rand()%100;
    }
    return;
}

void insertion_sort(int arreglo[], int size) {
    for (int i = 0; i < size-1; i++) {
        int key = arreglo[i+1];
        printf("key: %d \n", key);

        for (int j = i+1; j >= 0; j--) {
            int indice = j;
            if (key < arreglo[j]) {
                int temporal = arreglo[j+1];
                arreglo[j+1] = arreglo[j];
                arreglo[j] = temporal;
                mostrar_arreglo(arreglo, size);
            }
        }
    SALTO;
    }
    return;
}
