#ifndef DEQUE_H
#define DEQUE_H

typedef struct node {
    int data;
    node *next;
    node *prev;
} node;

typedef struct deque {
    node *front;
    node *back;
    int size;
} deque;

//Cria um novo deque; 
//Retorna endereço do deque
deque *createDeque();

//Cria um novo nodo; 
//Retorna endereço do nodo
node *createNode(int data);

//Insere no inicio; retorna 1 se sucesso e 0 se fracasso
int insertFront(deque *dq, int data);

//Insere no final; retorna 1 se sucesso e 0 se fracasso
int insertBack(deque *dq, int data);

//Destrói o deque e limpa a memória alocada
void destroyDeque(deque *dq);

//Remove do inicio; retorna 1 se sucesso e 0 se fracasso
//Endereço do nodo removido retorna pelo ponteiro data 
int removeFront(deque *dq, int *data);

//Remove do final; retorna 1 se sucesso e 0 se fracasso
//Endereço do nodo removido retorna pelo ponteiro data 
int removeBack(deque *dq, int *data);

//Procura e retorna um nodo
//Endereço do nodo procurado retorna pelo ponteiro data 
int search(deque *dq, int key, node *data);

#endif