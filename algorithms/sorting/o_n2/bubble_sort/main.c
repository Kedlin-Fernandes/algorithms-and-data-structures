#include <stdio.h>
#include "bubble_sort.h"

int main() {

    int v[] = {15,22,7,0,89,3,55,78,9,17};
    int size = 10;

    printf("Vetor não ordenado: ");
    print_array(v,size);

    bubble_sort(v, size);

    printf("Vetor ordenado: ");
    print_array(v,size);
    return 0;
}