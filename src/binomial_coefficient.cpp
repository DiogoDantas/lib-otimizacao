/**
 * @author     Marcos Alves
 * @date       07-10-2016
 */
#include "../inc/binomial_coefficient.hpp" //dynamic::binomial_coeff

int dynamic::binomial_coeff(int n, int k){
	// vetor com os coeficientes
	std::vector<int> c(k+1, 0);

	// C0 inicia com 1 * Caso base *
	c[0] = 1;

	for(int i = 1 ; i <= n ; ++i){
		// computando próxima linha em função da anterior
		// considera número k como o máximo de colunas
		for(int j = std::min(i, k) ; j > 0; --j)
			c[j] = c[j] + c[j-1];
	}

	return c[k];
}