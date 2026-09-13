#ifndef HEAP_H
#define HEAP_H

typedef struct {
	float x;
	float y;
	float erro;
	int pos_heap;
} ponto;

//Troca dois nós da heap
void troca_nos(ponto **min_heap, int i, int j);

//Insere um novo ponto na min-heap
void insere_heap(int *tam, ponto **min_heap, ponto *p_inserido);

//Reorganiza a estrutura 
void heapfy(int tam, ponto **min_heap, int i);

void sobe_heap(ponto **min_heap, int i);

void atualiza_heap(ponto **min_heap, int tam, int pos);

//Remove elemento da heap e retorna ele
ponto *remove_heap(int *tam, ponto **min_heap);

#endif