#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack *createStack() {
    stack *s = (stack*) malloc(sizeof(stack));

    if(!s)
        return NULL;

    s->top = NULL;
    s->size = 0; 

    return s;
}

node *createNode(int key) {
    node *no = (node*) malloc(sizeof(node));

    if(!no)
        return NULL;

    no->key = key;
    no->next = NULL;

    return no;
}

int push(stack *s, int key) {
    if(!s)
        return 0;
        
    node *newNode = createNode(key);

    if(!newNode)
        return 0;

    newNode->next = s->top;
    s->top = newNode;
    
    s->size++;
    return 1;
}

int pop(stack *s, int *data) {
    if(!s || !s->top)
        return 0; 

    if (data != NULL)
        *data = s->top->key;

    node *aux = s->top;
    
    s->top = aux->next;

    free(aux);
    s->size--;
    
    return 1;
}

void destroyStack(stack *s) {
    if(!s)
        return;

    node *current = s->top;

    while(current) {
        node *aux = current;
        current = current->next;
        free(aux);
    }
    
    free(s);
}

void printStack(stack *s) {
    if(!s)
        return;

    node *aux = s->top;
    
    printf("Pilha: ");
    while(aux) {
        printf("%d ", aux->key);
        aux = aux->next;
    }
    printf("\n"); 
}