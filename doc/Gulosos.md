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

  Dado um grafo conexo e unidirecional, uma árvore geradora desse grafo é um subgrafo que é uma árvore e conecta todos os vértices juntos. Um único grafo pode ter muitas árvores. Uma _minimum spanning tree_ (MST) ou árvore geradora de peso mínimo para um grafo ponderado, conectado e não direcionada é uma árvore geradora com peso igual ou inferior ao peso de qualquer outra árvore de expansão. O algoritmo de Prim é utilizado para gerar a MST.

  **Exemplo**

  Considere o seguinte grafo:

  ![Graph](http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/Fig-11.jpg)

  O subgrafo gerado após o processamento do algoritmo de Prim seria o esse:

  ![Graph Dijkstra](http://d1gjlxt8vb0knt.cloudfront.net//wp-content/uploads/MST5.jpg)

  **Complexidade** 

  A complexidade do algoritmo de Prim quando o grafo é representado usando uma matriz de adjacência é *O(V²) 

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

  **Descrição**
  
 Huffman é um algoritmo de compressão de dados sem perdas. A ideia é a de atribuir códigos de comprimento variável de caracteres de entrada, comprimentos dos códigos atribuídos são com base nas frequências de caracteres correspondentes. O caractere mais frequente recebe o menor código e o caractere menos frequente recebe o maior código.
  
  **Exemplo**

Para ilustrar o funcionamento do método, vamos comprimir a sequência de caracteres `AAAAAABBBBBCCCCDDDEEF`. Para usar o código Huffman e comprimir esta sequência precisamos primeiro montar uma árvore de Huffman.

| Caractere  |  A  |  B  |  C  |  D  |  E  |  F  |
|:----------:|:---:|:---:|:---:|:---:|:---:|:---:|
| Frequência |  6  |  5  |  4  |  3  |  2  |  1  |

Gerando nossa árvore de Huffman temos:

![Biynary Tree](https://upload.wikimedia.org/wikipedia/commons/2/20/Huffmanpasso6.png)

  **Complexidade**

A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/huffman.cpp) possui complexidade de tempo *O(nlogn)* em que *n* é o número de caracteres únicos.
  
6) Seleção de Atividades
------

 **Descrição**

Dado N atividades com o seu início e término de tempo. Devemos selecionar o número máximo de atividades que podem ser executadas por uma única pessoa, assumindo que uma pessoa só pode funcionar com uma única atividade de cada vez.

 **Exemplo**
 
 Considere 6 atividades descritas abaixo:
 
| Atividades |  Ínicio  |    Fim   |
|:-------:|:--------:|:--------:|
| 0 | 1 | 2 |
| 1 | 3 | 4 |
| 2 | 0 | 6 |
| 3 | 5 | 7 |
| 4 | 8 | 9 |
| 5 | 5 | 9 |

O conjunto máximo de atividades que podem ser executadas por uma única pessoa é {0, 1, 3, 4}.

 **Complexidade**

A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/activity_selection.cpp) possui complexidade de tempo *O(n)* em que *n* é o número de atividades.
