#include <stdio.h>
#include "selection_sort.h"

// troca dois elementos
void swap (int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

//ordena vetor com ordem crescente
void selection_sort (int *v, int size){
    for(int i=0; i<size-1; i++){
        int min = i;
        for(int j=i+1; j<size; j++)
            if(v[j]<v[min])
                min = j;

        if(min != i)
            swap(&v[i],&v[min]);
    }
}

//imprime um vetor de inteiros
void print_array (int *v, int size){
    for(int i=0; i<size; i++)
        printf("%d ", v[i]);
    printf("\n");
}