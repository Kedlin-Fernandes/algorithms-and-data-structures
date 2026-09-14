#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct node{
    int key;
    struct node *next;

} node;

typedef struct list{
    node *head;
    int size;

} list;

//Cria uma lista nova; 
//Retorna endereço da lista
list *createList ();

//Cria um novo nodo;
//Retorna endereço do nodo
node *createNode(int key);

//Insere um elemento no começo da lista
//Retorna 1 sucesso, 0 se fracasso
int insertFront(list *l, int key);

// Insere um elemento no final da lista
//Retorna 1 sucesso, 0 se fracasso
int insertBack(list *l, int key);

//Insere ordenado um elemento na lista
//Retorna 1 sucesso, 0 se fracasso
int insertSorted(list *l, int key);

//Remove um elemento da lista
//Retorna 1 sucesso, 0 se fracasso
int removeKey (list *l, int key);

//destrói a lista e limpa memória alocada
int destroy (list *l);

//procura um elemento na lista e retorna o ponteiro
node serachKey (list *l, int key);

//imprime uma lista
void printList(list *l);

#endif