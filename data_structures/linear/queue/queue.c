#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue *createQueue() {
    queue *q = (queue*) malloc(sizeof(queue));

    if(!q)
        return NULL;

    q->fisrt = NULL;
    q->last = NULL;
    q->size = 0; 

    return q;
}

node *createNode(int key) {
    node *no = (node*) malloc(sizeof(node));

    if(!no)
        return NULL;

    no->key = key;
    no->next = NULL;

    return no;
}

int enqueue(queue *q, int key) {
    if(!q)
        return 0;
        
    node *newNode = createNode(key);

    if(!newNode)
        return 0;

    if(!q->fisrt) {
        q->fisrt = newNode;
        q->last = newNode;
    } else {
        q->last->next = newNode;
        q->last = newNode;
    }
    
    q->size++;
    return 1;
}

int dequeue(queue *q, int *data) {
    if(!q || !q->fisrt)
        return 0; 

    if (data != NULL)
        *data = q->fisrt->key;

    node *aux = q->fisrt;
    
    q->fisrt = aux->next;

    if(!q->fisrt)
        q->last = NULL;

    free(aux);
    q->size--;
    
    return 1;
}

void destroyQueue(queue *q) {
    if(!q)
        return;

    node *current = q->fisrt;

    while(current) {
        node *aux = current;
        current = current->next;
        free(aux);
    }
    
    free(q);
}

void printQueue(queue *q) {
    if(!q)
        return;

    node *aux = q->fisrt;
    
    printf("Fila: ");
    while(aux) {
        printf("%d ", aux->key);
        aux = aux->next;
    }
    printf("\n");
}