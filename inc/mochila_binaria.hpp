/**
 * @name 	Diogo Dantas
 * date     14-10-2016
 */

#ifndef MOCHILA_BINARIA_HPP
#define MOCHILA_BINARIA_HPP

#include <vector>

 namespace dinamica {

 	/**
 	 * @brief      { Função que calcula o valor máximo que é possivel colocar na mochila 
 	 *             	 de capacidade weight}
 	 *
 	 * @param[in]  weight         Capacidade da mochila
 	 * @param      weight_vector  Vetor que armazena o peso dos itens
 	 * @param      values_vector  The que armazena o valor dos itens
 	 * @param[in]  num_itens      Número de itens
 	 *
 	 */
 	int mochila_binaria(const int weight, std::vector<int> & weight_vector, std::vector<int> & values_vector, const int num_itens);

 } 

#endif // MOCHILA_BINARIA_HPP
