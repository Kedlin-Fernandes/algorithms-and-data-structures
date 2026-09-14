#include <stdio.h>
#include "selection_sort.h"

int main (){
    int v[]={8, 10, 55, 48, 7, 0, 12, 89, 3, 5};
    int size = 10;

    printf("Vetor não ordenado: ");
    print_array(v,size);

    selection_sort(v,size);

    printf("Vetor ordenado: ");
    print_array(v, size);
    return 0;
}