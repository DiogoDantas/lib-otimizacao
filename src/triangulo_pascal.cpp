/**
 * @author     Marcos Alves
 * @date       07-10-2016
 */
#include "../inc/triangulo_pascal.hpp" //dinamica::triangulo_pascal

int dinamica::triangulo_pascal(int n, int k){
	// inicializando e preenchendo vetor
	std::vector<int> coeff(k+1, 0);
	// C0 inicia com 1 
	coeff[0] = 1;

	for(int i = 1 ; i <= n ; ++i){
		// computando próxima linha em função da anterior
		for(int j = std::min(i, k) ; j > 0; --j)
			coeff[j] = coeff[j] + coeff[j-1];
	}
	return coeff[k];
}