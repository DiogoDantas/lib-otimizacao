/**
 * @author     Diogo Dantas
 * @date       14-10-2016
 */

#ifndef SOMA_SUBCONJUNTO_HPP
#define SOMA_SUBCONJUNTO_HPP

 #include <vector>


 namespace dinamica{
 
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
 	bool soma_subconjunto(std::vector<int> & set, const int set_num_elements, const int sum);

 }



#endif // SOMA_SUBCONJUNTO_HPP
