#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

deque *createDeque() {
    deque *dq = malloc(sizeof(deque));

    if(!dq)
        return NULL;

    dq->front = NULL;
    dq->back = NULL;
    dq->size = 0;

    return dq;
}

node *createNode(int data) {
    node *item = malloc(sizeof(node));

    if(!item)
        return NULL;

    item->data = data;
    item->next = NULL;
    item->prev = NULL;

    return item;
}

int insertFront(deque *dq, int data) {
    if(!dq)
        return 0;

    node *newNode = createNode(data);

    if(!newNode)
        return 0;

    if(dq->size == 0) {
        dq->front = newNode;
        dq->back = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }

    dq->size++;
    return 1;
}

int insertBack(deque *dq, int data) {
    if(!dq)
        return 0;

    node *newNode = createNode(data);
    
    if(!newNode)
        return 0;

    if(dq->size == 0) {
        dq->front = newNode;
        dq->back = newNode;
    } else {
        newNode->prev = dq->back;
        dq->back->next = newNode;
        dq->back = newNode;
    }

    dq->size++;
    return 1;
}

void destroyDeque(deque *dq) {
    if(!dq)
        return;

    node *current = dq->front;

    while(current) {
        node *aux = current;
        current = current->next;
        free(aux);
    }
    
    free(dq);
}

int removeFront(deque *dq, int *data) {
    if(!dq || dq->size == 0)
        return 0; 

    if (data != NULL)
        *data = dq->front->data;

    node *aux = dq->front;

    if(dq->size == 1) {
        dq->front = NULL;
        dq->back = NULL;
    } else {
        dq->front = aux->next;
        dq->front->prev = NULL;
    }

    free(aux);
    dq->size--;
    
    return 1; 
}

int removeBack(deque *dq, int *data) {
    if(!dq || dq->size == 0)
        return 0; 

    if (data != NULL) 
        *data = dq->back->data;

    node *aux = dq->back;

    if(dq->size == 1) {
        dq->front = NULL;
        dq->back = NULL;
    } else {
        dq->back = aux->prev;
        dq->back->next = NULL;
    }

    free(aux);
    dq->size--;
    
    return 1; 
}