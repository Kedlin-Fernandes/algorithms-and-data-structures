#include <stdio.h>
#include <stdlib.h>
#include "pontos.h"

int main (int argc, char *argv[]) {

	if (argc < 3) {
		printf("Uso: %s <-a ou -h> <valor de tolerância>\n", argv[0]);
		return 1;
	}

	const char *opcao = argv[1];
	const float erro_max = atof(argv[2]);

	int n;
	float y;
	arvore *a = malloc(sizeof(arvore));
	a->raiz = NULL;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%f", &y);
		no *novo = malloc(sizeof(no));
		novo->p = malloc(sizeof(ponto));

		novo->p->y = y;
		novo->p->x = i;
		novo->p->erro = 0;
		novo->p->pos_heap = -1;

		novo->altura = 0;
		novo->pai = NULL;
		novo->esq = NULL;
		novo->dir = NULL;
		avl_insere(a, novo);
	}

	int tam = 0;
	ponto **heap = malloc((n + 1) * sizeof(ponto *));

	percorre_e_insere(heap, a, a->raiz, &tam, opcao);
	heapfy(tam, heap, 1);

	while (tam > 0 && heap[1]->erro < erro_max){
		ponto *ponto_removido = remove_heap(&tam, heap);
		no *no_removido = avl_busca(a->raiz, ponto_removido->x);
		
		no *ant = antecessor(no_removido);
		no *suc = sucessor(no_removido);

		avl_deleta(a, no_removido);

		if (ant->p->pos_heap >= 1) {
			heap[ant->p->pos_heap]->erro = calcula_erro(antecessor(ant), ant, sucessor(ant), opcao);
			atualiza_heap(heap, tam, ant->p->pos_heap);
		}	
		if (suc->p->pos_heap >= 1) {
			heap[suc->p->pos_heap]->erro = calcula_erro(antecessor(suc), suc, sucessor(suc), opcao);
			atualiza_heap(heap, tam, suc->p->pos_heap);
		}

		n--;
	}

	printf("%d\n", n);
	imprime_resultado(a->raiz); // como imprimir y? quantas casas depois do . 
}