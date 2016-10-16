/**
 * @author     Marcos Alves
 * @date       15-10-2016
 */
#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <iostream> // std::string, std::cout
#include <queue> // std::priority_queue
#include <vector> // std::vector

namespace greedy {
	/**
	 * @brief      Estrutura Nó da heap que será gerada.
	 */
	struct node_t {
		// conteúdo (CARACTER) 
		char content;
		// frequência do conteúdo
		unsigned frequency;
		// apontadores para o filho
		node_t *left, *right; 
		// construtor 1
		node_t(char c, unsigned f) {
			content = c;
			frequency = f;
			left = right = nullptr;
		}
		// construtor 2
		node_t(char c, unsigned f, node_t* l, node_t* r) {
			content = c;
			frequency = f;
			left = l;
			right = r;
		}
	};
	/**
	 * @brief      Imprimi o conteúdo e o mesmo codificado.
	 *
	 * @param[in]  root  Referência para raíz da árvore
	 * @param[in]  code  String com a código dos elementos.
	 */
	void code_puts(node_t* root, std::string code = "");
	/**
	 * @brief      Responsável por gerar árvore.
	 *
	 * @param[in]  ch    vetor com caracters.
	 * @param[in]  freq  frequência dos caracters.
	 *
	 * @return     Retorna a raíz da árvore de huffman.
	 */
	node_t* huff_encode(const std::vector<char>& ch, const std::vector<unsigned>& freq);
}

#endif //HUFFMAN_HPP