/**
 * @author     Diogo Dantas
 * @date       14-10-2016
 */

#ifndef SUBSET_SUM_HPP
#define SUBSET_SUM_HPP

 #include <vector>


 namespace dynamic{

 	/**
 	 * @brief      { Problema classico de programação dinâmica. Dado um subconjunto a função retorna um
 	 *             	 boolean que diz se existe algum subconjunto onde a soma dos elementos desse subconjunto
 	 *             	 é igual ao parâmetro sum }
 	 *
 	 * @param      set               Conjunto de entrada
 	 * @param[in]  set_num_elements  A cardinalinade do conjunto
 	 * @param[in]  sum               O valor númerico alvo
 	 *
 	 * @return     { Caso a função retorne True existe um subconjunto tal que a soma dos elementos desse
 	 *               subconjunto é igual ao valor do pamâmetro sum, caso não exista esse subconjunto a função
 	 *               vai retornar False }
 	 */
 	bool subset_sum(std::vector<int> & set, const int set_num_elements, const int sum);

 }



#endif // SUBSET_SUM_HPP
