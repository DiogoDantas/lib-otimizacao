/**
 * @author     Marcos Alves
 * @date       Sun, Nov 20 
 */
#include "../inc/GAs.hpp"

namespace GAs {
	// definição das constantes
	const int GENERATION = 100000000;
	const int POP_SIZE = 150;
	// condição ao definir constantes PROB_CROSSOVER >= PROB_MUTATE
	const double PROB_CROSSOVER = 0.5;
	const double PROB_MUTATE = 0.8;
	// significa que a cada 100 iterações o melhor não for modificado
	// gere uma nova população
	const int VARIABILITY = 300;

	// população do algoritmo
	std::vector<individual_t> population;
	// dados da instancia
	CVRP::Instance instance;	

	std::vector<individual_t> copy(){
		int len = PROB_CROSSOVER * POP_SIZE, index = 0;
		std::vector<individual_t> result;
		std::vector<individual_t> copy_population(population);

		for(int i = 0 ; i < len ; ++i){
			// seleciona um índice
			do {
				index = roulette_selection();
			} while(index >= copy_population.size());
			
			// insere o elemento que será modificado no crossover/mutate
			result.push_back(copy_population.at(index).routes);

			copy_population.erase(copy_population.begin() + index);
		}

		return result;
	}

	void crossover(std::vector<individual_t>& individuals){
		int parent1 = 0, parent2 = 0, delimiter = 0, it = 0;
		std::vector<int> routes; 
		int size_routes = population.at(0).routes.size();
		
		for(int i = 0 ; i < individuals.size() ; ++i){
			std::vector<bool> mark(population.size(), false); 
			
			parent1 = roulette_selection();
			do{
				parent2 = roulette_selection();
			} while(parent1==parent2 || (mark.at(parent1) && mark.at(parent2)));

			mark.at(parent1) = true;
			mark.at(parent2) = true;

			delimiter = std::rand() % size_routes;
			// [5, 6, 1, 8]
			// 	   ^  
			// [1, 2, 3, 9]
			// 		  ^	
			// [5, 6, 3, 9]
			for(int j = 0 ; j <= delimiter ; ++j)
				routes.push_back(population.at(parent1).routes.at(j));

			// segunda parte precisa verificar se não existe elementos
			// repetidos, caso tiver pego próximo
			for(int j = delimiter + 1 ; j < size_routes ; ++j){
				it = j;
				while(std::find(routes.begin(), routes.end(), population.at(parent2).routes.at(it))
					  != routes.end()) {
					it++;
					if(it == size_routes) it = 0;
				}
				routes.push_back(population.at(parent2).routes.at(it)); 
			}
			individuals.at(i).routes = routes;

			routes.clear();
		}
	}

	void evaluate(){
		int demand = 0;
		int size_routes = population.at(0).routes.size();
		double score = 0;
		
		for(int i = 0 ; i < population.size() ; ++i){
			// saida do deposito
			score += instance.distance_matrix.at(1).at(population.at(i).routes.at(0));
	
			for(int j = 0 ; j < size_routes - 1; ++j){
				demand += instance.nodes.at(population.at(i).routes.at(j)).demand +
						  instance.nodes.at(population.at(i).routes.at(j+1)).demand;
 				
				if(demand > instance.capacity) {
					score += instance.distance_matrix.at(1).at(population.at(i).routes.at(j));
					// novo veículo sai do deposito
					score += instance.distance_matrix.at(1).at(population.at(i).routes.at(j+1));			
					demand = 0;
				} else
					score += instance.distance_matrix.at(population.at(i).routes.at(j))
													 .at(population.at(i).routes.at(j+1));
			}
			// volta para o deposito
			score += instance.distance_matrix.at(1).at(population.at(i).routes.at(size_routes - 1));

			population.at(i).score = score;	
			demand = 0;
			score = 0;
		}	
	}

	int fittest(){
		int index = 0;

		for(int i = 0 ; i < POP_SIZE ; ++i){
			if(population.at(index).score > population.at(i).score)
				index = i;	
		}
		return index;
	}

	void initialize(){
		CVRP::Parser parser;
		// todos os dados necessários para inicializar a população.
		instance = parser.build_problem();
		std::vector<int> list_of_nodes;
		int demand;

		// gerar lista de nos 1..number_of_nodes	
		for(int i = 2 ; i <= instance.number_of_nodes; ++i)
			list_of_nodes.push_back(i);


		for(int i = 0 ; i < POP_SIZE ; ++i){
			demand = 0;
			// gerando rota aleatória levando em considerações as duas principais restrições
			// A - cada nó só recebe uma unica visita 
			// B - capacidade
			individual_t individual(list_of_nodes);
			// embaralho a lista de nós gerando uma rota
			std::random_shuffle(individual.routes.begin(), individual.routes.end());

			population.push_back(individual);
		}
	}

	void join(std::vector<individual_t>& individuals){

		for(int i = 0 ; i < individuals.size() ; ++i){
			for(int j = 0 ; j < population.size(); ++j){
				if(individuals.at(i).routes == population.at(j).routes)
					std::random_shuffle(individuals.at(i).routes.begin(), individuals.at(i).routes.end());
			}
		}
		population.insert(population.end(), individuals.begin(), individuals.end());
	}

	void mutate(std::vector<individual_t>& individuals){
		int len = PROB_MUTATE * POP_SIZE, index1 = 0, index2 = 0;
		int counter = 0;

		for(int i = 0 ; i < individuals.size() ; ++i){
			std::vector<bool> mark(individuals.at(0).routes.size(), false); 

			do {
				index1 = std::rand() % individuals.at(i).routes.size();
				do {
					index2 = std::rand() % individuals.at(i).routes.size();
				} while(index1==index2);

			    std::swap(individuals.at(i).routes.at(index1), individuals.at(i).routes.at(index2));				
				++counter;
			// numero de trocas
			} while(counter != len);
			counter = 0;
		}
	}

	void print(){
		std::clog << "# Current population" << " " << population.size() << std::endl;

		for(int i = 0 ; i < population.size() ; ++i){
			std::clog << i + 1 << " - Routes: ";
			for(int j = 0 ; j < population.at(0).routes.size() ; ++j)
				std::clog << population.at(i).routes.at(j) << " ";
			std::clog << "Score: " << population.at(i).score << std::endl;
		}
	}
	// bastante inifeciente para entradas muito grandes
	// verifica se algum elemento igual, verifica qual nó está mais próximo do deposito.
	void refining(){
		for(int i = 0; i < POP_SIZE ; ++i){
			for(int j = 0 ; j < population.at(0).routes.size() - 1; ++j){
				if(instance.distance_matrix.at(1).at(population.at(i).routes.at(j)) > 
					instance.distance_matrix.at(1).at(population.at(i).routes.at(j+1)))
						std::swap(population.at(i).routes.at(j), population.at(i).routes.at(j+1));
			}	
		}
		for(int i = 0 ; i < population.size() ; ++i){
			for(int j = 0 ; j < population.size(); ++j){
					if(i != j && population.at(i).routes == population.at(j).routes)
						std::random_shuffle(population.at(i).routes.begin(), population.at(i).routes.end());
			}
		}
	}
	//   	fitness(i)
	// --------------------
	// SOMATORIO(j) fitness(j)
	// 
	int roulette_selection(){
		double total_score = 0.0, total_tmp = 0.0;
		double randomic = (double) std::rand() / RAND_MAX;

		for(individual_t individual : population)
			total_score += individual.score;
		
		for(int i = 0 ; i < POP_SIZE ; ++i){
			total_tmp += population.at(i).score/total_score;

			if(randomic < total_tmp)
				return i;
		}
	}

	void run(){
		std::srand(std::time(NULL));
		int counter = 0, optimal = 0, index = 0;
		// numero de gerações sem melhorias
		int ns = 0;
		// numero de gerações
		int ng = 0;
		// inicializo geração 0
		double limit = 60.0;
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		
		initialize();
		// calculo o fitness de cada índividuo
		evaluate();
		// melhor indíviduo da população
		individual_t elitism(population.at(fittest()));
	
		while(ng < GENERATION){
			// índividuos a serem modificados
			std::vector<individual_t> elements = copy();
			// processo de crossover
			crossover(elements);	
			// processo de mutação
			mutate(elements);
			// junto os novos elementos a minha população
			join(elements);
			// uma nova avaliação do índividuos
			evaluate();
			// seleção natural
			selection();
			// busco o índice melhor fitness
			index = fittest();
			
			// vejo se é melhor do que a solução que já tenho
			if(elitism.score > population.at(index).score)
				elitism = population.at(index);
			else
				++ns;
			if(ns == VARIABILITY){ 
				refining(); 
				population.at(0) = elitism;
				ns = 0; 
			}
			std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    		if((std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count()) > limit) break;
			++ng;
		}
		std::cout << elitism.score << std::endl;
	}

	void selection(){
		// ordeno a lista de acordo com score descrecente
		std::sort(population.begin(), population.end());
		
		int size = population.size() - POP_SIZE;
		// retiro os piores indíviduos
		for(int i = 0 ; i < size ; ++i)
			population.pop_back();
	}

	int tournament_selection(){
		int index1 = std::rand() % POP_SIZE; 
		int index2 = 0;
		do {
			index2 = std::rand() % POP_SIZE;
		} while(index1==index2);
		
		if(population.at(index1).score > population.at(index1).score)
			return index1;
		else
			return index2;
	}
}
