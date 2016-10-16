/**
 * @author     Marcos Alves
 * @date       16-10-2016
 */
#include "../inc/activity_selection.hpp" // std::max_activities

std::string greedy::max_activities(const std::vector<int>& start, const std::vector<int>& finish){
	// string será o resultado final de todas as atividades
	// por default o primeiro processo já será executado
	std::string index_activities{"0 "};
	int len = start.size();
	int index = 0;

	// percorre do segundo em diante
	for(int u = 1 ; u < len ; ++u){
		// comparado se o inicio do processo corrente é maior do que o fim do anterior
		// s = 3 e f = 2
		// significa que passaram 2s e a outra atividade tem inicio só em 3s (são compatíveis)
		if(start[u] >= finish[index]){
			// concatenando o valor das atividades
			index_activities += std::to_string(u) + " ";
			index = u;
		}
	}
	return index_activities;
}
