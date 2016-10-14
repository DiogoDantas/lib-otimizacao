/**
 * @author     Diogo Dantas
 * @date       14-10-2016
 */

 #include "../inc/soma_subconjunto.hpp"


 bool dinamica::soma_subconjunto(std::vector<int> & set, const int set_num_elements, const int sum){

 	bool subset[sum+1][set_num_elements+1];


 	/**
 	 * Base da recursão:
 	 * Se a soma for zero sempre é possivel encontrar um subconjunto cujo a soma dos elementos seja zero 
 	 */
 	for (int i = 0; i <= set_num_elements; ++i)
 	{
 		subset[0][i] = true;
 	}

 	/**
 	 * Se a soma não for zero e o número de elementos no subconjunto for zero então não é possivel 
 	 * encontrar um subconjunto cuja a soma dos elementos seja igual ao valor do parâmetro sum 
 	 */
 	for (int i = 1; i <= sum; ++i)
 	{
 		subset[i][0] = false;
 	}

 	/*
 		 Conjunto de instruções resposavel por preencher a tabela da forma botton up 
 	 */
 	for (int i = 1; i <= sum; ++i)
 	{
 		for (int j = 1; j <= set_num_elements; ++j)
 		{
 			/**
 			 * Recuperando o valor da celula acima
 			 */
 			subset[i][j] = subset[i][j-1];
 			
 			/*
 			* Caso o elemento do conjunto seja maior que o valor da soma, recuperamos o valor da celula da linha acima
 			* deslocado para esquerda um número de colunas de acordo com o indice da linha atual 
 			*/
 			if (i >= set[j-1])
           		subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
 		}
 	}

 	/**
 	 * Caso exista um subconjunto onde a soma dos elementos é igual ao valor passado para a função, o ultimo elemento
     * da tabela tera o valor verdadeiro.
 	 */	
 	 return subset[sum][set_num_elements];
 }
