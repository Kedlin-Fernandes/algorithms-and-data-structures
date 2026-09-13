#include <stdio.h>
#include "binary_search.h"

int main(){
    int v[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = 10;
    int key1 = 23;
    int key2 = 100;

    // Teste com valor existente
    printf("Buscando o elemento: %d\n", key1);

    // Teste Iterativo
    int result_ite = binary_search_iterative(v, size, key1);

    if(result_ite != -1)
        printf("Iterative: Encontrado no indice %d\n", result_ite);
    else
        printf("Iterative: Nao encontrado\n");

    // Teste Recursivo
    int result_rec = binary_search_recursive(v, 0, size - 1, key1);
    
    if(result_rec != -1)
        printf("Recursive: Encontrado no indice %d\n", result_rec);
    else 
        printf("Recursive: Nao encontrado\n");

    // Teste com valor inexistente
    printf("Buscando o elemento: %d\n", key2);

    // Teste Iterativo
    result_ite = binary_search_iterative(v, size, key2);

    if(result_ite != -1)
        printf("Iterative: Encontrado no indice %d\n", result_ite);
    else
        printf("Iterative: Nao encontrado\n");

    // Teste Recursivo
    result_rec = binary_search_recursive(v, 0, size - 1, key2);
    
    if(result_rec != -1)
        printf("Recursive: Encontrado no indice %d\n", result_rec);
    else 
        printf("Recursive: Nao encontrado\n");

    return 0;
}