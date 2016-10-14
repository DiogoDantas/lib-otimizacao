/**
 * @author     Marcos Alves
 * @date       07-10-2016
 */
#include "../inc/troco_moedas.hpp" //dinamica::troco_moedas

int dinamica::troco_moedas(const std::vector<int>& s, int n){
	// tamanho do array de moedas
	int len = s.size();
	// vetor iniciando 0 até o troco
	std::vector<int> table(n+1, 0);

	table[0] = 1; // caso base

	// complexidade espaço O(n)
	// imaginando a matriz moedas x troco fica mais fácil de compreender
	// a redução para um único vetor
	for(int i = 0 ; i < len ; ++i){
		for(int j = s[i] ; j <= n ; ++j)
			table[j] += table[j-s[i]];
	}

	return table[n];
}
