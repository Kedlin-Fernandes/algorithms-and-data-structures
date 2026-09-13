#include "binary_search.h"

int binary_search_iterative(int *v, int size, int key){
    int start = 0;
    int end = size - 1;

    /* Se o índice do começo for maior que o do final, 
    significa que o algoritmo percorreu todo o vetor e
    não encontrou o elemento */
    while(start <= end){
        int m = start + (end - start) / 2;

        if (v[m] == key) 
            return m; 

        if (v[m] < key)
            start = m + 1; 
        else 
            end = m - 1; 
    }

    return -1; 
}