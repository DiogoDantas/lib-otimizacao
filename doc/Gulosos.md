#Descrição dos problemas resolvidos com **Algoritmos Gulosos**

1) Dijkstra
------

  **Descrição**
  
  Esse problema é semelhante ao problema de Prim que está descrito logo abaixo. Considerando um grafo e um nó desse grafo,
  o problema consiste em encontrar o caminho com menor custo a partir desse nó para todos os outros nós do grafo.

  **Exemplo**
  
  Considere o seguinte grafo:

  ![Graph](http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/Fig-11.jpg)

  Considerando o nó *0* como nó inicial, o grafo resultante após o processamento do algoritmo de Dijkstra seria o esse:

  ![Graph Dijkstra](http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/DIJ5.jpg)

  Percebam o grafo resultante possui os caminhos com menor custo partindo do nó *0* para todos os outros nós
  
  **Complexidade**

  O algoritmo de Dijkstra possui complexidade _O(|E| + |V| * |log V|) onde |E| é número de arestas e |V| o número de vértices



2) Prim
------

  **Descrição**

  **Exemplo**

  **Complexidade** 

3) Mochila Fracionária
------

  **Descrição**
  
  Esse problema é semelhante ao problema da mochila binária que foi resolvido com programação dinâmica. O problema diz que dado pesos e valores
  de *n* itens, é necessário colocá-los em uma mochila de capacidade *W* de forma a conseguir o maior valor total. A diferença para este problema
  é que agora é possível colocar apenas uma **fração** do item na mochila.
  
  **Exemplo**
  
| Item  | Valor | Peso  |
| ----- |:-----:| -----:|
| A     | 60    | 10    |
| B     | 100   | 20    |
| C     | 120   | 30    |

**Capacidade = 50**

`O valor máximo obtido é 240, pegando o item A, B e 20kg do C`

  **Complexidade**
  
  Como a operação mais custosa e dependente do algoritmo implementado [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/fractional_knapsack.cpp)
  é a ordenação, a complexidade está ligada a ele, que nesse caso é *O(nlogn)*, pois a complexidade
  do método de ordenação da biblioteca padrão de C++ é esse.

4) Coloração de Grafos
------
  
  **Descrição**
  
  O problema consiste em atribuir cores aos vértices de uma forma que vértices adjacentes não possuam a mesma cor e que se utilize o 
  número mínimo de cores. Porém, esse problema é considerado um *problema NP Completo* então a solução apresentada aqui é uma aproximação
  que não utiliza a quantidade mínima de cores, mas utiliza no máximo *d+1* cores onde *d* é o grau máximo de um vértice no grafo. O grau
  é a quantidade de conexões do vértice.
  
  **Exemplo**

Dado o seguinte grafo com as seguintes ligações, é possível atribuir as seguintes cores sem que haja cores iguais entre vértices adjacentes

![Graph Coloring](http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/graph_coloring11-300x130.png)

  **Complexidade**

A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/graph_coloring.cpp) possui complexidade de tempo *O(V²+E)* onde V é o número de
vértices e E o número de arestas do grafo.


5) Compressão de Dados (Huffman)
------
  
6) Seleção de Atividades
------

