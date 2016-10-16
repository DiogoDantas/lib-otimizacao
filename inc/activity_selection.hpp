/**
 * @author     Marcos Alves
 * @date       16-10-2016
 */
#ifndef ACTIVITY_SELECTION_HPP
#define ACTIVITY_SELECTION_HPP

#include <string> // std::string
#include <vector> // std::vector

namespace greedy {
	/**
	 * @brief      Seleciona o subconjunto de tamanho máximo de atividades mutuamente compatíveis. 
	 *
	 * @param[in]  start   Inicio dos processos
	 * @param[in]  finish  Fim dos processos
	 *
	 * @return     Os índice das atividades do subconjunto.
	 */
	std::string max_activities(const std::vector<int>& start, const std::vector<int>& finish);
}

#endif // ACTIVITY_SELECTION_HPP