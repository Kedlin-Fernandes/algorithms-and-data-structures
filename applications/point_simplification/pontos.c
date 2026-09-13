#include <stdio.h>
#include <string.h>
#include "pontos.h"

void percorre_e_insere(ponto **heap, arvore *a, no *no_atual, int *tam, const char *opcao){
	if (no_atual) {
		percorre_e_insere(heap, a, no_atual->esq, tam, opcao);
	if (no_atual != minimo(a->raiz) && no_atual != maximo(a->raiz)){
			no_atual->p->erro = calcula_erro(antecessor(no_atual), no_atual, sucessor(no_atual), opcao);
			insere_heap(tam, heap, no_atual->p);
		}
	percorre_e_insere(heap, a, no_atual->dir, tam, opcao);
	}
}

float calcula_erro(no *ant, no *n, no *suc, const char *opcao)
{
	if (!strcmp(opcao,"-a")) return area_triangulo(ant->p->x, ant->p->y, n->p->x, n->p->y, suc->p->x, suc->p->y);
	if (!strcmp(opcao,"-h")) return altura2_triangulo(ant->p->x, ant->p->y, n->p->x, n->p->y, suc->p->x, suc->p->y);
	return 0.0; 
}

// calcula a area do triangulo formado pelos pontos (x1,y1), (x2,y2)
// e (x3,y3), usando o valor absoluto do determinante da matrix com
// os 3 pontos dividido por 2
float area_triangulo(float x1, float y1,
					float x2, float y2,
					float x3, float y3) {
	float area;

	area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
	return (area < 0.0) ? -area : area;
}

// calula a altura do triangulo elevada ao quadrado, sendo a altura
// a distancia entre (x2,y2) e a base do triangulo (x1,y1)~(x3,y3)
// considerando a equacao: area = (base * altura) / 2
// elevando ao quadrado: area^2 = (base^2 * altura^2) / 4
// reorganizando:      altura^2 = 4 * area^2 / base^2
float altura2_triangulo(float x1, float y1,
						float x2, float y2,
						float x3, float y3) {
	float area, dx, dy;

	area = area_triangulo(x1, y1, x2, y2, x3, y3);
	dx = x3 - x1;
	dy = y3 - y1;    
	return 4 * (area * area) / (dx * dx + dy * dy);
}

void imprime_resultado(no *no_atual)
{
	if (no_atual) {
		imprime_resultado(no_atual->esq);
		printf("%.1f %.6g\n", no_atual->p->x, no_atual->p->y);
		imprime_resultado(no_atual->dir);
	}
}