#include <stdio.h>
#include "merge_sort.h"

int main() {

    int v[] = {45, 33, 0, 6, 88, 39, 72, 3, 14, 122};
    int size = 10;

    printf("Vetor não ordenado: ");
    print_array(v, size); 

    merge_sort(v,size);

    printf("Vetor ordenado: ");
    print_array(v, size); 

    return 0;
}