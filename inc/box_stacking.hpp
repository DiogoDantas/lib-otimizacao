/**
 * @author     Marcos Alves
 * @date       14-10-2016
 */ 
#ifndef BOX_STACKING_HPP
#define BOX_STACKING_HPP

#include <algorithm> // std::begin, std::end, std::max_element, std::sort
#include <functional> // std::greater
#include <vector> // std::vector

namespace dynamic {
	/**
	 * @brief      Estrutura com as especificações da caixa.
	 */
	struct box_t {
		int height, width, depth; 
		// sobrecarga do operador de comparação
		inline bool operator<(const box_t& rhs) const {
			return rhs.depth * rhs.width < depth * width;
		}
	};
	/**
	 * @brief      Calcular a maior altura formada pelo empilhamento de caixas.
	 *
	 * @param[in]  boxes  As caixas com suas especificações
	 *
	 * @return     Altura máxima.
	 */
	int box_stacking(const std::vector<box_t>& boxes);
}

#endif //BOX_STACKING_HPP