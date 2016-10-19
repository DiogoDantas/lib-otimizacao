#Descrição dos problemas de **Programação Dinâmica**

1) Soma de Subconjuntos
------

  **Descrição**

  Dado um conjunto composto por números inteiros, não negativos, e um valor soma. A função deve verificar a existencia de algum subconjunto em que a soma dos elementos seja igual ao valor soma recebido.

  **Exemplo**
  
  Dado o seguinte conjunto {3, 34, 4, 12, 5, 2} e o valor de soma {9} existe o subconjunto {5, 4} que a soma dos seus elementos
  5 + 4 é igual ao valor de soma {9} 

  **Complexidade**

  A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/subset_sum.cpp) possui complexidade _O(sum * N)_

2) Mochila Binária
------

  **Descrição**

  Esse é um problema muito conhecido de programação dinâmica. Considere a seguinte analogia, você é um ladrão que invadiu uma
  casa e dentro dela existem *n* itens e cada um desses itens possui um peso *w*. Seu problema é que a mochila que você levou 
  para armazenar os itens só consegue carregar um certo peso *W* e seu objetivo é selecionar os itens que irão garantir o maior
  lucro possivel, levando em consiração que o itens não podem ser quebrados, ou você vai levá-los, ou não. 

  **Exemplo**
  
| Item  | Valor | Peso  |
| ----- |:-----:| -----:|
| A     | 60    | 10    |
| B     | 100   | 20    |
| C     | 120   | 30    |

**Capacidade = 50**

`O valor máximo obtido é 220, pegando o item B e o item C`

  **Complexidade**

  A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/knapsack.cpp) possui complexidade *O(nW)* onde *n* é o número de itens e *W* é a capacidade da mochila

3) Quebra de Palavras
------

  **Descrição**

  Dado um string de entrada e um dicionário de palavras. Esse problema tenta decidir se a string de entrada pode ser dividida
  em um sequência de palavras do dicionário.

  **Exemplo**

  >Considerando o seguinte dicionário:  
  *{ i, like, sam, sung, samsung, mobile, ice, cream, icecream, man, go, mango }*

  >Entrada:  ilike
  >
  >Saída: Yes 
  >
  >A string pode ser dividida como "i like".

  **Complexidade**

  A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/word_break.cpp) possui complexidade *O(n³)*  devido a função que retorna uma substring sozinha possuir uma complexidade *O(n)*

4) Maior Subsequência Comum
------
  
  **Descrição**
  
  Dada duas palavras, encontrar o comprimento da maior subsequência presente em ambos. Uma subsequência é uma sequência que aparece na mesma ordem **relativa**, mas não necessariamente contígua. Por exemplo, *"abc"*, *“abc”*, *“abg”*, *“bdf”*, *“aeg”* e *”acefg”* são subsequências de *“abcdefg”*. Então uma string de tamanho n tem no máximo *2^n* possibilidades de subsequências diferentes.
  
  **Exemplo**

Tamanho da Maior Subsequência Comum entre  *"ABCDGH"* e *"AEDFHR"* é **3**. `"ADH"`

Tamanho da Maior Subsequência Comum entre  *"AGGTAB"* e *"GXTXAYB"* é **4**. `"GTAB"`.

  **Complexidade**

A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/lcs.cpp) possui complexidade *O(mn)* onde *m* é o tamanho da primeira string e *n* da segunda.


5) Multiplicação de Matrizes
------
  
  **Descrição**
  
  Dada uma sequência de matrizes, encontrar a forma mais eficiente de multiplicar essas matrizes. O problema não é executar essas multiplicações, mas simplesmente decidir em que ordem multiplicá-las.
  
  **Exemplo**
  
  Dada as 4 matrizes seguintes A=*40x20*, B=*20x30*, C=*30x10* e D=*10x30*.
  
  O menor número de multiplicações são obtidas quando multiplicadas da forma a seguir:
  
  `(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30`
  
  Totalizando **2600** multiplicações
  
  **Complexidade**
  
A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/matrix_chain_mult.cpp) possui complexidade cúbica *O(n³)* de tempo e quadrática *O(n²)* de espaço.
  
  
6) Distância de edição
------

  **Descrição**
  Dada duas strings A e B e as operações de adição, remoção e substituição que podem ser realizadas sobre a string A. Encontrar o número mínimo de operações necessárias para converter A em B.
  
  **Exemplo**
  
  Dadas as strings A = *"github"* e B = *"git"*

  A distância de edição é **3**, pois podemos remover o *"hub"* de A.
  
  **Complexidade**
  
  A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/edit_distance.cpp) possui complexidade *O(mn)* de tempo e espaço. Onde m e n são os tamanhos das duas strings.

7) Troco em moedas
------

  **Descrição**
  
  Dado um troco (N) e um conjunto de moedas (S), encontrar quantas possibilidades existem de se formar o troco, com as moedas contidas no conjunto. A ordem das moedas não importa.

  
  **Exemplo**
  
  Dado N = 4 e S = {1,2,3}
  
  O maior conjunto de possibilidades que podemos conseguir é **4**, são elas:  

  `{1,1,1,1},{1,1,2},{2,2},{1,3}`
    
  **Complexidade**
  
A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/coin_change.cpp) possui complexidade *O(mn)* de tempo, onde m é o tamanho conjunto de moedas e n do troco, e linear *O(n)* de espaço.

8) Triângulo de Pascal
------

  **Descrição**
  
  Dado n e k encontrar o valor do coeficiente binomial utilizado no triângulo de Pascal. Mais informações sobre coeficiente binomial pode ser encontrada [aqui](https://pt.wikipedia.org/wiki/Coeficiente_binomial).
  
  **Exemplo**
  
  Dado N = 4 e K = 2
  
  O valor coeficiente binomial  C (4, 2) é **6**.
    
  **Complexidade**
  
A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/binomial_coefficient.cpp) possui complexidade *O(nk)* de tempo e linear *O(n)* de espaço.  

9) Empilhamento de caixas
------
 **Descrição**
 
 Suponha que sejam dadas **N** caixas. Cada caixa tem uma altura h, uma largura w e uma profundidade d. Deseja-se saber qual é a altura máxima formada pelo empilhamento de caixas, de forma que só é permitido empilhar uma caixa sobre outra, se as dimensões da base da caixa inferior forem estritamente maiores do que as respectivas dimensões da base da caixa superior.  Lembrando que você pode rotacionar uma caixa para que qualquer uma de suas faces faça o papel da base.
![Box Stacking](http://algorithms.tutorialhorizon.com/files/2016/04/Box-Stacking-Rotations.png)
 
  **Exemplo**
  
  Dado um conjunto de caixas `B = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} }`
  
  Rotações produzidas:

    10 x 12 x 32
  
    12 x 10 x 32
  
    32 x 10 x 12
   
    4 x 6 x 7
   
    4 x 5 x 6
   
    6 x 4 x 7
   
    5 x 4 x 6
   
    7 x 4 x 6
   
    6 x 4 x 5
   
    1 x 2 x 3
   
    2 x 1 x 3
   
    3 x 1 x 2 

`A altura máxima é 60`

Obtido pelas caixas {{**3**, 1, 2}, {**1**, 2, 3}, {**6**, 4, 5}, {**4**, 5, 6}, {**4**, 6, 7}, {**32** , 10, 12}, {**10**, 12, 32}}
  
    
  **Complexidade**
  
A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/box_stacking.cpp) possui complexidade quadrática *O(n²)* de tempo e linear *O(n)* de espaço.
