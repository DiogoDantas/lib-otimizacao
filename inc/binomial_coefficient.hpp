/**
 * @author     Marcos Alves
 * @date       07-10-2016
 */
#ifndef BINOMIAL_COEFFICIENT_HPP
#define BINOMIAL_COEFFICIENT_HPP

#include <vector> // std::vector

namespace dynamic {
	/**
	 * @brief      Calcula o coeficiente binomial  
	 *
	 * @param[in]  n     linha
	 * @param[in]  k     coluna
	 *
	 * @return     O coeficiente binomial.
	 */
	int binomial_coeff(int n, int k);
}

#endif //BINOMIAL_COEFFICIENT_HPP