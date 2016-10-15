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

A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/maior_subs_comum.cpp) possui complexidade *O(mn)* onde *m* é o tamanho da primeira string e *n* da segunda.


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
  
A solução implementada [aqui](https://github.com/anjoshigor/lib-otimizacao/blob/master/src/multiplicacao_matrizes.cpp) possui complexidade cúbica *O(n³)* de tempo e quadrática *O(n²)* de espaço.
  
  
6) Distância de edição
------
  
7) Troco em moedas
------
  
8) Triângulo de Pascal
------
  
9) Empilhamento de caixas
------
