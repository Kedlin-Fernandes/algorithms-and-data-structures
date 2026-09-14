#include <stdio.h>
#include "insertion_sort.h"

void insertion_sort (int *v, int size){
    for(int i=1; i<size; i++){
        int key = v[i];
        int j = i - 1;

        //enquanto os elementos forem maior que key
        while(j>=0 && v[j]>key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

void print_array (int *v, int size){
    for(int i=0; i<size; i++)
        printf("%d ",v[i]);
    printf("\n");
}