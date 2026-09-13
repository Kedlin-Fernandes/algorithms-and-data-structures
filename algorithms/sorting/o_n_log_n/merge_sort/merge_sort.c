#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

// recebe dois vetores desordenados e retorna um único vetor ordenado 
void merge_sorted(int *v, int left, int m, int right){
    int left_size = m - left + 1; 
    int right_size = right - m;

    int *aux_left = (int*) malloc (sizeof(int) * left_size);
    int *aux_right = (int*) malloc (sizeof(int) * right_size);

    int i, j ;

    if(!aux_left || !aux_right)
        return;
    
    //copia valores da parte left no vetor auxiliar
    for(i=0; i<left_size; i++)
        aux_left[i] = v[left + i];
    
    //copia valores da parte right no vetor auxiliar
    for(i=0; i<right_size; i++)
        aux_right[i] = v[m + 1 + i];
    
    i = 0;  //indice left
    j = 0;  //indifce right
    for(int k=left; k<= right; k++){
        //
        if(i < left_size && (j >= right_size || aux_left[i] <= aux_right[j])){
            v[k] = aux_left[i];
            i++;
        } 
        else {
            v[k] = aux_right[j];
            j++;
        }
    }

    free(aux_left);
    free(aux_right);
    aux_left = NULL;
    aux_right = NULL;
}

//separa um vetor recursivamente no meio até ter um elemento
//retorna um vetor completo ordenado
void merge_sort_recursive (int *v, int left, int right){
    if (left < right) {
        int m = left + (right - left) / 2;

        merge_sort_recursive (v, left, m);
        merge_sort_recursive (v, m+1, right);

        merge_sorted (v, left, m, right);
    }
}

// função visivel para o usuário
void merge_sort (int *v, int size){ 
    merge_sort_recursive (v, 0, size-1);
}

// imprime os elementos de um vetor de inteiros
void print_array(int *v, int size){
    for(int i=0; i<size; i++)
        printf("%d ",v[i]);
    printf("\n");
} 