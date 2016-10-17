#Descrição dos problemas de **Programação Dinâmica**

1) Soma de Subconjuntos
------

2) Mochila Binária
------

3) Quebra de Palavras
------

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
  
  **Exemplo**
  
    
  **Complexidade**
  
A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/box_staking.cpp) possui complexidade quadrática *O(n²)* de tempo e linear *O(n²)* de espaço.
