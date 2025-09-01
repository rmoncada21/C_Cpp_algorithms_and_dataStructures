#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
void llenar_arreglo(int*, int);
void mostrar_arreglo(int*, int);
void bubble_sort(int*, int);

int main(){
    srand(2); // usar semilla
    int* arreglo = (int*)malloc(sizeof(int)*SIZE);

    llenar_arreglo(arreglo, SIZE);
    mostrar_arreglo(arreglo, SIZE);
    bubble_sort(arreglo, SIZE);
    mostrar_arreglo(arreglo, SIZE);
    return 0;
}

void llenar_arreglo(int* arreglo, int size){
    for(int i=0; i<size; i++){
        *(arreglo+i) = rand()%100;
    }
    return;
}

void mostrar_arreglo(int* arreglo, int size){
    for(int i=0; i<size; i++){
        int elemento = *(arreglo+i);
        printf("%d - ", elemento);
    }

    printf("\n");
    return;
}

// void bubble_sort(int arreglo[], int size){
//     int swap = 1;

//     for(int i=0; i<size; i++){
//         if(swap){
//             swap = 0;
//             for(int j=0; j<(size-1); j++){
//                 int dato_actual = arreglo[j];
//                 int dato_siguiente = arreglo[j+1];

//                 if(dato_actual>dato_siguiente){
//                     swap = 1;
//                     int temporal = dato_actual;
//                     arreglo[j] = arreglo[j+1];
//                     arreglo[j+1] = temporal;
//                     // mostrar_arreglo(arreglo, size); 
//                 }
//                 mostrar_arreglo(arreglo, size);
//             }
//         } else {
//             return;
//         }
//     }
// }


void bubble_sort(int arreglo[], int size){
    int swap_flag = 1;

    while(swap_flag){
        swap_flag = 0;

        for(int i=0; i<(size-1); i++){

            if( arreglo[i]>arreglo[i+1] ){
                int temporal = arreglo[i];
                arreglo[i] = arreglo[i+1];
                arreglo[i+1] = temporal;
                swap_flag = 1;
            }
            mostrar_arreglo(arreglo, size);
        }
    }
    return;
}