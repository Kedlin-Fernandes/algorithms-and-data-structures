#ifndef AVL_H
#define AVL_H
#include "heap.h"

typedef struct no {
	ponto *p;
	int altura;
	struct no *pai;
	struct no *esq;
	struct no *dir;
} no;

typedef struct {
	no *raiz;
} arvore;


no* arvore_insere (arvore *t, no *z) ;
void transplante (arvore *t, no *u, no *v) ;
no* minimo (no *x) ;
no* maximo (no *x) ;
no* arvore_deleta (arvore *t, no *z) ;
no* rot_esq (no *p) ;
no* rot_dir (no *p) ;
no* rot_esqdir (no *p) ;
no* rot_diresq (no *p);
no* avl_balanceamento (no *x) ;
void troca_filho (arvore *t, no *u, no *v) ;
void avl_insere(arvore *t, no *z);
void avl_deleta (arvore *t, no *z) ;
no* antecessor(no *x);
no* sucessor(no *x);
no *avl_busca(no *raiz, float x);

#endif