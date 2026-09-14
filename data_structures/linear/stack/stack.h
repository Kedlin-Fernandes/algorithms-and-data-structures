#ifndef STACK_H
#define STACK_H

typedef struct node {
    int key;
    struct node *next;
} node;

typedef struct stack {
    node *top; 
    int size;
} stack;

//Cria uma pilha nova; retorna o ponteiro da pilha
stack *createStack();

//Cria um novo nodo; retorna o ponteiro do nodo
node *createNode(int key);

//Insere sempre no topo da pilha
//Retorna 1 se sucesso, 0 se fracasso
int push(stack *s, int key);

//Remove sempre do topo da pilha
//Retorna 1 se sucesso, 0 se fracasso
int pop(stack *s, int *data);

// Destrói a pilha e limpa a memória alocada
void destroyStack(stack *s);

// Imprime a pilha
void printStack(stack *s);

#endif