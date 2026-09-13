#include <stdio.h>
#include "quick_sort.h"

int main() {
    int v[] = {0, 45, 44, 13, 4, 88, 7, 9, 3, 4};
    int size = 10;

    printf("Vetor não ordenado: ");
    print_array(v, size);

    quick_sort(v, size);

    printf("Vetor ordenado: ");
    print_array(v, size);

    return 0;
}