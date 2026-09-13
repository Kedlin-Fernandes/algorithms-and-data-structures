#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

// vetor precisa estar ordenado
// Retorna o índice do elemento ou -1 se não encontrar
int binary_search_iterative(int *v, int size, int key);
int binary_search_recursive(int *v, int start, int end, int key);

#endif