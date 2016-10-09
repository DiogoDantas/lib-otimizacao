/**
 * @author     Marcos Alves
 * @date       07-10-2016
 */
#ifndef TROCO_MOEDAS_HPP
#define TROCO_MOEDAS_HPP

#include <vector> //std::vector

/**
 * @brief      Problema do troco moedass utilizando 
 * 			   programação dinâmica.  
 */
namespace dinamica {
	/**
	 * @brief      Encontrar o número de maneiras de fazer trocos
	 *
	 * @param      s     vetor com possíveis moedas
	 * @param[in]  n     valor total a ser subtraído
	 *
	 * @return     Maior número de formas possível para dar o troco
	 */
	int troco_moedas(const std::vector<int>& s, int n);
}

#endif //TROCO_MOEDAS_HPP
