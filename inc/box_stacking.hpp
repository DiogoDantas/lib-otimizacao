/**
 * @author     Marcos Alves
 * @date       14-10-2016
 */ 
#ifndef BOX_STACKING_HPP
#define BOX_STACKING_HPP

#include <algorithm> // std::begin, std::end, std::max_element, std::sort
#include <vector> // std::vector

namespace dynamic {
	/**
	 * @brief      Estrutura com as especificações da caixa.
	 */
	struct box { int height, width, depth; };
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  boxes  The boxes
	 *
	 * @return     { description_of_the_return_value }
	 */
	int box_stacking(const std::vector<box>& boxes);
}

#endif //BOX_STACKING_HPP