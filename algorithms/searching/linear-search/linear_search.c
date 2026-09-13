#include "linear_search.h"

int linear_search(int *v, int size, int key){
    for (int i = 0; i < size; i++) 
        if (v[i] == key)
            return i; 
    return -1; 
}