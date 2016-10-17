/**
 * @name 	Diogo Dantas
 * date     14-10-2016
 */

#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <vector>

 namespace dynamic {

 	/**
 	 * @brief      { Função que calcula o valor máximo que é possivel colocar na mochila
 	 *             	 de capacidade weight}
 	 *
 	 * @param[in]  weight         Capacidade da mochila
 	 * @param      weight_vector  Vetor que armazena o peso dos itens
 	 * @param      values_vector  Vetor que armazena o valor dos itens
 	 * @param[in]  num_itens      Número de itens
 	 *
 	 */
 	int knapsack(const int weight, std::vector<int> & weight_vector, std::vector<int> & values_vector, const int num_itens);

 }

#endif // KNAPSACK_HPP
