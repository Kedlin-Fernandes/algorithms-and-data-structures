#include <stdio.h>
#include "quick_sort.h"

//realiza a troca de dois elementos
void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

//separa o vetor no pivô; retorna o indice do meio
int partition (int *v, int left, int right){
    int pivot = v[right];
    int j = left;

    for(int i=left; i<right; i++){
        if(v[i] <= pivot){
            swap(&v[j], &v[i]);
            j++;
        }
    }
    swap(&v[j], &v[right]);
    return j;
}

void quick_sort_recursive(int *v, int left, int right){
    if(left< right){
        int pivot = partition(v, left, right);

        quick_sort_recursive(v, left, pivot-1);
        quick_sort_recursive(v, pivot+1, right);
    }
}

//visivel para o usuário
void quick_sort(int *v, int size){
    quick_sort_recursive(v, 0, size-1);
}

//imprime os elementos de um vetor de inteiros
void print_array(int *v, int size){
    for(int i=0; i<size; i++)
        printf("%d ",v[i]);
    printf("\n");
}