#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

list *createList() {
    list *l = (list*) malloc(sizeof(list));

    if(!l)
        return NULL;

    l->head = NULL;
    l->size = 0; 

    return l;
}

node *createNode (int key) {
    node *no = (node*) malloc(sizeof(node));

    if(!no)
        return NULL;

    no->key = key;
    no->next = NULL;

    return no;
}

int insertFront (list *l, int key) {
    if(!l)
        return 0;
        
    node *newNode = createNode(key);

    if(!newNode)
        return 0;

    newNode->next = l->head;
    l->head = newNode;

    l->size++;
    return 1;
}

int insertBack (list *l, int key) {
    if(!l)
        return 0;
        
    node *newNode = createNode(key);

    if(!newNode)
        return 0;

    if(!l->head)
        l->head = newNode;
    else {
        node *aux = l->head;

        while (aux->next != NULL) 
            aux = aux->next; 

        aux->next = newNode;
    }
    
    l->size++;
    return 1;
}

int insertSorted (list *l, int key) {
    if(!l)
        return 0;

    node *newNode = createNode(key);
    if(!newNode)
        return 0;

    if(!l->head || l->head->key >= key) {
        newNode->next = l->head;
        l->head = newNode;
    } else {
        node *aux = l->head;

        while (aux->next != NULL && aux->next->key < key)
            aux = aux->next;

        newNode->next = aux->next;
        aux->next = newNode;
    }

    l->size++;
    return 1;
}

int removeKey (list *l, int key) {
    if(!l || !l->head)
        return 0; 

    node *aux = l->head;
    node *prev = NULL;

    while(aux != NULL && aux->key != key) {
        prev = aux;
        aux = aux->next;
    }

    if(!aux)
        return 0;

    if(!prev) {
        l->head = aux->next;
    } else {
        prev->next = aux->next;
    }

    free(aux);
    l->size--;
    return 1;
}

void destroyList(list *l) {
    if(!l)
        return;

    node *current = l->head;

    while(current){
        node *aux = current;
        current = current->next;
        free(aux);
    }
    
    free(l);
}

node *searchKey(list *l, int key) {
    if(!l || !l->head)
        return NULL;

    node *aux = l->head;

    while(aux) {
        if(aux->key == key)
            return aux;
            
        aux = aux->next;
    }

    return NULL;
}

void printList(list *l) {
    if(!l)
        return;

    node *aux = l->head;
    while(aux) {
        printf("%d -> ", aux->key);
        aux = aux->next;
    }
    printf("NULL\n");
}