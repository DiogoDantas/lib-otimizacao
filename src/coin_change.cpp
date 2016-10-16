/**
 * @author     Marcos Alves
 * @date       07-10-2016
 */
#include "../inc/coin_change.hpp" // dynamic::coin_change

int dynamic::coin_change(const std::vector<int>& s, int n){
	// tamanho do array de moedas
	int len = s.size();

	// vetor iniciando 0 até o troco máximo
	std::vector<int> table{n+1, 0};
	
	// caso base
	table[0] = 1;

	// complexidade espaço O(n)
	// imaginando a matriz moedas x troco fica mais fácil de compreender
	// a redução para um único vetor
	for(int i = 0 ; i < len ; ++i)
		for(int j = s[i] ; j <= n ; ++j)
			table[j] += table[j-s[i]];

	return table[n];
}
