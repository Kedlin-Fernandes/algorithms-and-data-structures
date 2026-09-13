#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ALT(a) ((a == NULL)?(-1):(a->altura))

no* arvore_insere (arvore *t, no *z) {
	no *x, *y;

	x = t->raiz;
	y = NULL;
	while(x != NULL) {
		y = x;
		if(z->p->x < x->p->x)
			x = x->esq;
		else
			x = x->dir;
	}
	z->pai = y;
	if(y == NULL)
		t->raiz = z;
	else if(z->p->x < y->p->x) 
		y->esq = z;
	else
		y->dir = z;
	return y;
}


void transplante (arvore *t, no *u, no *v) {
	if(u->pai == NULL)
		t->raiz = v;
	else if(u == u->pai->esq)
		u->pai->esq = v;
	else
		u->pai->dir = v;
	if(v != NULL)
		v->pai = u->pai;
}


no* minimo (no *x) {
	while(x->esq != NULL)
		x = x->esq;
	return x;
}

no* maximo (no *x) {
	while(x->dir != NULL)
		x = x->dir;
	return x;
}


no* arvore_deleta (arvore *t, no *z) {
	no *x, *y;

	x = z->pai;
	if(z->esq == NULL)
		transplante(t, z, z->dir);
	else if(z->dir == NULL)
		transplante(t, z, z->esq);
	else {
		y = minimo(z->dir);
		x = y->pai;
		if(y != z->dir) {
			transplante(t, y, y->dir);
			y->dir = z->dir;
			y->dir->pai = y;
		}
		else x = y;
		transplante(t, z, y);
		y->esq = z->esq;
		y->esq->pai = y;
	}
	return x;
}


no* rot_esq (no *p) {
	no *q;

	q = p->dir;
	p->dir = q->esq;
	if(p->dir)
		p->dir->pai = p;
	q->esq = p;
	q->pai = p->pai;
	p->pai = q;    
	p->altura = 1 + MAX(ALT(p->esq), ALT(p->dir));
	q->altura = 1 + MAX(ALT(q->esq), ALT(q->dir));
	return q;
}


no* rot_dir (no *p) {
	no *q;

	q = p->esq;
	p->esq = q->dir;
	if(p->esq)
		p->esq->pai = p;
	q->dir = p;
	q->pai = p->pai;
	p->pai = q;    
	p->altura = 1 + MAX(ALT(p->esq), ALT(p->dir));
	q->altura = 1 + MAX(ALT(q->esq), ALT(q->dir));
	return q;
}


no* rot_esqdir (no *p) {
	p->esq = rot_esq(p->esq);
	p->esq->pai = p;
	return rot_dir(p);
}


no* rot_diresq (no *p) {
	p->dir = rot_dir(p->dir);
	p->dir->pai = p;
	return rot_esq(p);
}


no* avl_balanceamento (no *x) {
	int fb;
	no *y;

	y = x;
	fb = ALT(x->dir) - ALT(x->esq);
	if(fb < -1) {
		if(ALT(x->esq->esq) < ALT(x->esq->dir))
			y = rot_esqdir(x);
		else
			y = rot_dir(x);
	}
	else if(fb > 1) {
		if(ALT(x->dir->dir) < ALT(x->dir->esq))
			y = rot_diresq(x);
		else
			y = rot_esq(x);
	}
	return y;
}

// ajustes feitos na confusão do professor entre u e v
void troca_filho (arvore *t, no *u, no *v) {
	if(v->pai == NULL)
		t->raiz = v;
	else if(u == v->pai->esq)
		v->pai->esq = v;
	else
		v->pai->dir = v;
}

void avl_insere (arvore *t, no *z) {
	int a;
	no *x, *y;

	z->altura = 0;
	x = arvore_insere(t, z);
	while(x != NULL) {
		a = 1 + MAX(ALT(x->esq), ALT(x->dir));
		y = avl_balanceamento(x);
		if(y != x) {
			troca_filho(t, x, y);
			break;
		}
		if(x->altura == a)
			break;
		x->altura = a;
		x = x->pai;
	}        
}

// acho que precisa de alteração: na teoria aprendemos que devia subir ate raiz
void avl_deleta (arvore *t, no *z) {
	int a;
	no *x, *y;
	
	x = arvore_deleta(t, z);
	while(x != NULL) {
		a = 1 + MAX(ALT(x->esq), ALT(x->dir));
		y = avl_balanceamento(x);
		if(y != x) {
			troca_filho(t, x, y);
			x = y;
		}
		if(x->altura == a)
			break;
		x->altura = a;
		x = x->pai;
	}
}

no* antecessor(no *x) {
	no *y;

	if (x->esq != NULL)
		return maximo(x->esq);
	y = x->pai;
	while (y != NULL && x == y->esq) {
		x = y;
		y = y->pai;
	}
	return y;
}

no* sucessor(no *x) {
	no *y;

	if (x->dir != NULL)
		return minimo(x->dir);
	y = x->pai;
	while (y != NULL && x == y->dir) {
		x = y;
		y = y->pai;
	}
	return y;
}

no* avl_busca(no *raiz, float x) {
	while (raiz != NULL) {
		if (x < raiz->p->x)
			raiz = raiz->esq;
		else if (x > raiz->p->x)
			raiz = raiz->dir;
		else
			return raiz;
	}

	return NULL;
}