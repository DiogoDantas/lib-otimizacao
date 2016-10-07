/**
 * @author     Marcos Alves
 * @date       07-10-2016
 */
#ifndef TRI_PASCAL_HPP
#define TRI_PASCAL_HPP

#include <vector> //std::vector

/**
 * @brief      Problema do triângulo de pascal utilizando 
 * 			   programação dinâmica.  
 */
namespace dinamica {
	/**
	 * @brief      Calcula o coeficiente binomial  
	 *
	 * @param[in]  n     linha
	 * @param[in]  k     coluna
	 *
	 * @return     O coeficiente binomial.
	 */
	int triangulo_pascal(int n, int k);
}

#endif //TRI_PASCAL_HPP