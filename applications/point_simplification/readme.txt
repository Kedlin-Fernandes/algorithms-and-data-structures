Trabalho de Algoritmos e Estruturas de Dados III
Alunas:
Isabella dos Santos Stuart, 20252459
Isadora Rodrigues Espinha, 20252213
Julia Silveira Acras, 20252105
Kedlin Dalla Vecchia Fernandes, 20250150
Maria Eduarda Prada da Silva, 20252587

Para calcular as margens de erro geradas pelas remoções dos pontos, 
são utilizadas duas estruturas de dados:
- MinHeap
- Árvore AVL

A heap é usada na forma de um vetor alocado dinamicamente, com o objetivo de 
armazenar as margens de erro de cada ponto por ordem de prioridade crescente. 
Ela serve para detectar quais pontos são os melhores canditatos à remoção em 
cada momento. 
Nela, os dados são armazenados por meio de uma 'struct ponto', que contém as 
seguintes informações:
- coordenadas do ponto;
- margem de erro;
- posição atual da struct na heap (utilizada para atualizar os valores de erro).

Já árvore AVL é utilizada para armazenar a ordem relativa entre os pontos na 
imagem. Isso porque, a cada remoção, é necessário recalcular as margens de erro
que seriam geradas no caso da remoção do antecessor e/ou do sucessor do ponto
removido.
Nela, os dados são armazenados por meio de uma 'struct no', que contém as seguintes
informações:
- a struct ponto correspondente ao nó;
- altura do nó na árvore (utilizada para o balanceamento);
- nós pai, filho à esquerda e filho à direita (para funções de antecessor/sucessor).

O algoritmo funciona da seguinte maneira: 

O programa recebe o comando "./programa <flag> <margem de tolerância>". Em seguida,
são construídas as 'structs no' equivalentes e armazenadas na árvore. Uma vez inseridas,
são adicionadas todas as 'structs ponto' de cada nó na heap e é chamada a função 
'Heapfy', que as organiza por ordem de prioridade.

Depois, é verificado se o primeiro elemento da heap possui um erro inferior à margem
de tolerância. 

Caso positivo, ele é removido logicamente da heap (pois a remoção literal teria um 
custo n, que é alto demais) e é feita uma busca pela posição do seu nó na árvore. 
Depois, obtém-se seu antecessor e sucessor por meio da chamada dessas funções na árvore, 
e ele é removido dela. Por fim, as margens de erro do antecessor e do sucessor são 
recalculadas e suas posições no heap são atualizadas individualmente usando a função
de troca de pontos.

Caso negativo, é encerrada a execução do programa e são impressos o número de nós
restantes na árvore e as coordenadas de cada um.

Com isso, o programa possui um custo O(nlogn), com as seguintes operações:
- inserção na heap;
- heapfy;
- inserção e remoção na árvore;
- percorrer e buscar na árvore;
- mínimo e máximo da árvore (para não adicionar extremidades à heap);
- rotações e balanceamento da árvore.
