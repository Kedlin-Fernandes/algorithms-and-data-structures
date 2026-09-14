#ifndef QUEUE_H
#define QUEUE_H

typedef struct node {
    int key;
    struct node *next;
} node;

typedef struct queue {
    node *fisrt; 
    node *last;  
    int size;
} queue;

//Cria uma fila nova; retorna o ponteiro da fila
queue *createQueue();

//Cria um novo nodo; retorna o ponteiro do nodo
node *createNode(int key);

//Insere sempre no final da fila
//Retorna 1 se sucesso,0 se fracasso
int enqueue(queue *q, int key);

//Remove sempre do inicio da fila
//Retorna 1 se sucesso, 0 se fracasso
int dequeue(queue *q, int *data);

//Destrói a fila e limpa a memória alocada
void destroyQueue(queue *q);

//Imprime a fila
void printQueue(queue *q);

#endif