#include <stdio.h>
#include "linear_search.h"

int main() {
    int v[] = {38, 5, 23, 91, 16, 2, 72, 12, 56, 8};
    int size = 10;
    int key = 16;

    printf("Buscando o elemento: %d\n", key);

    //Teste com valor existente
    int result = linear_search(v, size, key);
    if(result != -1) 
        printf("Encontrado no indice %d\n", result);
    else
        printf("Nao encontrado\n");

    return 0;
}