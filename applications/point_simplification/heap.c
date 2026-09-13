#include <stdio.h>
#include "heap.h"

void troca_nos(ponto **min_heap, int i, int j) {
	ponto *aux = min_heap[i];
	min_heap[i] = min_heap[j];
	min_heap[j] = aux;

	min_heap[i]->pos_heap = i;
	min_heap[j]->pos_heap = j;
}

void insere_heap(int *tam, ponto **min_heap, ponto *p_inserido){
	(*tam)++;
	int i = *tam;

	min_heap[i] = p_inserido;
	min_heap[i]->pos_heap = i;

	while (i > 1 && min_heap[i / 2]->erro > min_heap[i]->erro){
		troca_nos(min_heap, i / 2, i);
		i = i / 2;
	}
}


void heapfy(int tam, ponto **min_heap, int i){
	while (2 * i <= tam){
		int filho = 2 * i;

		if (filho < tam && min_heap[filho + 1]->erro < min_heap[filho]->erro)
			filho++;

		if (min_heap[i]->erro <= min_heap[filho]->erro)
			return;

		troca_nos(min_heap, i, filho);
		i = filho;
	}
}

void sobe_heap(ponto **min_heap, int i) {
	while (i > 1 && min_heap[i / 2]->erro > min_heap[i]->erro) {
		troca_nos(min_heap, i / 2, i);
		i = i / 2;
	}
}

void atualiza_heap(ponto **min_heap, int tam, int pos) {
	sobe_heap(min_heap, pos);
	heapfy(tam, min_heap, pos);
}

ponto *remove_heap(int *tam, ponto **min_heap){
	ponto *removido = min_heap[1];
	removido->pos_heap = -1;

	//Elemento da raiz que vamos remover e retornar
	min_heap[1] = min_heap[*tam];
	if (*tam > 1)
		min_heap[1]->pos_heap = 1;
	(*tam)--;

	//Reorganiza a heap
	if (*tam > 0)
		heapfy(*tam, min_heap, 1);

	return(removido);
}