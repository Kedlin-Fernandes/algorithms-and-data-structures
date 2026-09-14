#include <stdio.h>
#include "bubble_sort.h"

// troca dois elementos
void swap (int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

//troca o maior com o menor elemento 
//até ordenar o vetor
void bubble_sort (int *v, int size){
    for(int i=0; i<size; i++)
        for(int j=0; j<size-1; j++)
            if(v[j] > v[j+1])
                swap(&v[j], &v[j+1]);
}

//imprime um vetor de inteiros
void print_array (int *v, int size){
    for(int i=0; i<size; i++)
        printf("%d ",v[i]);
    printf("\n");
}