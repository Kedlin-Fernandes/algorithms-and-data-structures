#include "binary_search.h"

int binary_search_recursive(int *v, int start, int end, int key){
    if(start <= end){
        int m = start + (end - start) / 2;

        if (v[m] == key)
            return m; 

        if (v[m] < key)
            // Busca na metade direita
            return binary_search_recursive(v, m + 1, end, key);

        else // Busca na metade esquerda
            return binary_search_recursive(v, start, m - 1, key);
    }

    return -1; 
}