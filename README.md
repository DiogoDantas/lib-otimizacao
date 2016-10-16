# lib-otimizacao
Uma versão embrionária de uma biblioteca de otimização open source com implementação de 15 problemas conhecidos de programação dinâmica e algoritmos gulosos

##Programação dinâmica
  1. Soma de Subconjuntos [@DiogoDantas](https://github.com/DiogoDantas)
  2. Mochila Binária [@DiogoDantas](https://github.com/DiogoDantas)
  3. Quebra de Palavras [@DiogoDantas](https://github.com/DiogoDantas)
  4. Maior Subsequência Comum [@anjoshigor](https://github.com/anjoshigor)
  5. Multiplicação de Matrizes [@anjoshigor](https://github.com/anjoshigor)
  6. Distância de edição [@anjoshigor](https://github.com/anjoshigor)
  7. Troco em moedas [@alvesmarcos](https://github.com/alvesmarcos)
  8. Triângulo de Pascal [@alvesmarcos](https://github.com/alvesmarcos)
  9. Empilhamento de caixas [@alvesmarcos](https://github.com/alvesmarcos)

##Algoritmos Gulosos
  1. Dijkstra [@DiogoDantas](https://github.com/DiogoDantas)
  3. Mochila Fracionária [@anjoshigor](https://github.com/anjoshigor)
  4. Coloração de Grafos [@anjoshigor](https://github.com/anjoshigor)
  5. Compressão de dados (Código de Huffman) [@alvesmarcos](https://github.com/alvesmarcos)

###Estrutura da biblioteca
`inc/` -- diretório contendo todos os cabeçalhos de cada problema.

`src/` -- diretório contendo a implementação de cada problema.

`tests/` -- diretórico contendo programas que testa a implementação dos problemas.

`inputs/` -- diretório contendo um conjunto de entradas utilizadas pelos programas que testam a implementação dos problemas. As entradas podem ser randômicas, com resultados simples de ser verificado ou que busca atuar sobre os "corner cases" de cada problema.

`doc/` -- diretório contendo a descrição dos problemas

`gerador.py` -- em alguns problemas, é possível utilizar entradas randomicas e verificar o resultado. Este script em python é responsável por gerar essas entradas.

###Makefile
a ser alterado
