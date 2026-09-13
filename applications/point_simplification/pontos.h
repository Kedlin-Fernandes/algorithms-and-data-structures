#ifndef PONTOS_H
#define PONTOS_H

#include "heap.h"
#include "avl.h"

void percorre_e_insere(ponto **heap, arvore *a, no *no, int *tam, const char *opcao);
float calcula_erro(no *ant, no *n, no *suc, const char *opcao);
float area_triangulo(float x1, float y1, float x2, float y2, float x3, float y3);
float altura2_triangulo(float x1, float y1, float x2, float y2, float x3, float y3);
void imprime_resultado(no *n);

#endif