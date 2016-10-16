/**
 * @author     Marcos Alves
 * @date       07-10-2016
 */
#ifndef COIN_CHANGE_HPP
#define COIN_CHANGE_HPP

#include <vector> // std::vector

namespace dynamic {
	/**
	 * @brief      Encontrar o número de maneiras possíveis de dar troco.
	 *
	 * @param      s     Vetor com possíveis moedas
	 * @param[in]  n     Valor total a ser subtraído
	 *
	 * @return     Maior número de formas possível para dar o troco.
	 */
	int coin_change(const std::vector<int>& s, int n);
}

#endif //COIN_CHANGE_HPP
