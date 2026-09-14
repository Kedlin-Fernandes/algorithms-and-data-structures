#include <stdio.h>
#include "insertion_sort.h"

int main (){
    int v[]={1,15,22,38,6,56,99,154,8,48};
    int size = 10;

    printf("Vetor não ordenado: ");
    print_array(v,size);

    insertion_sort(v,size);

    printf("Vetor ordenado: ");
    print_array(v, size);
    return 0;
}