/**
 * @author     Marcos Alves
 * @date       Sun, Nov 20 
 */
#ifndef GAs_HPP
#define GAs_HPP

#include <chrono>
#include <limits>
#include <random> // me
#include <iostream> // std::clog
#include <vector> // std::vector
#include <cstdlib> // std::srand, std::rand
#include <algorithm>    // std::sort std::random_shuffle, std::swap, std::find
#include <ctime> // time
#include "parser.hpp" // CVRP::instance, CVRP::build

/**
 * @brief      Namespace for Genetic Algorithms.
 */
namespace GAs {
	/**
	 * @brief      Estrutura do cromossomo armazena um conjunto de rotas.
	 */
	struct individual_t { 
		std::vector<int> routes; 
		double score; 
		// construtor
		individual_t(std::vector<int> rt): routes(rt), score(0.0) {}
		// sobregarga de operador na igualdade
		inline bool operator<(const individual_t& rhs) const {
			return score < rhs.score;
		}
	};

	// Métricas do algoritmo
	extern const int GENERATION; // numero de gerações suportadas
	extern const int POP_SIZE; // tamanho da população
	extern const double PROB_CROSSOVER; // probabilidade de crossover
	extern const double PROB_MUTATE; // probabilidade de mutação
	extern const int VARIABILITY; // variabilidade da população
	/**
	 * @brief      Processo de crossover.
	 *
	 * @param      individuals   Conjunto de indivíduos que será modificado.
	 */
	void crossover(std::vector<individual_t>& individuals);
	/**
	 * @brief      Parte da população para o processo de Crossover e mutação.
	 */
	std::vector<individual_t> copy();
	/**
	 * @brief      Avalia cada indivíduo da população atribuindo um score.
	 */
	void evaluate();
	/**
 	 * @brief      Calcula o melhor indivíduo da população.
 	 *
 	 * @return     Retorna o índice.
 	 */
	int fittest();
	/**
	 * @brief      Inicializa a população.
	 */
	void initialize();
	/**
	 * @brief      Insere novos indivíduos na população.
	 *
	 * @param      individuals  Os indivíduos.
	 */
	void join(std::vector<individual_t>& individuals);
	/**
	 * @brief      Processo de mutação.
	 *
	 * @param      individuals   Conjunto de indivíduos que será modificado.
	 */
	void mutate(std::vector<individual_t>& individuals);	
	/**
	 * @brief      Imprime a população.
	 */
 	void print();
 	/**
 	 * @brief      Refinando a população.
 	 */
 	void refining();
	/**
	 * @brief      Seleciona um elemento pelo metodo da roleta fitness/all_fitness.
	 *
	 * @return     índice do indivíduo escolhido.
	 */
	int roulette_selection();
	/**
	 * @brief      Implementação do algoritmo génetico.
	 */
 	void run();
	/**
	 * @brief      Retira os piores indivíduos da população.
	 */
	void selection();
	/**
	 * @brief      Escolhe aleatoreamente dois indices vê qual melhor score.
	 *
	 * @return     Retorna o índice do indivíduo.
	 */
 	int tournament_selection();
};

#endif // GAs_HPP