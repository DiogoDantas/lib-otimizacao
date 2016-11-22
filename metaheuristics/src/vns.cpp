#include "../inc/vns.hpp"

CVRP::VNS::VNS(Instance instance){
	instance_ = instance;
}

CVRP::VNS::~VNS(){/* Uniplemented Method*/}

CVRP::Solution CVRP::VNS::generate_initial_solution(){
	// numero de veículos restantes
	int remainder =  instance_.number_of_trucks;
	// quantos nos ja foram visitados
	int counter_node = 0;
	// marcando os nos ja visitados
	std::vector<bool> mark( instance_.number_of_nodes + 1, false);
	mark.at(0) = true;

	//Intâncias da Solução
	Truck truck;
	Solution solution;
	
	while(remainder){
		// indice do mais próximo
		int closer = 0;
		// atual indice
		int index = 0;
		// menor peso inicialmente pro primeiro no
		double weight = 0.0;
		for(int i = 1; i <=  instance_.number_of_nodes ; ++i){
			if(!mark.at(i)){
				weight =  instance_.distance_matrix.at(0).at(i);
				closer = i;
				break;
			}
		}
		// capacidade do atual veiculo
		int capacity = 0;
		// vector indicando por qual nó o veiculo deve passar
		std::vector<int> routes;

		//Inserindo o nó do deposito na rota
		routes.push_back(0);

		// checando se todos os nós foram visitados
		while(counter_node !=  instance_.number_of_nodes){

			for(int i = 1 ; i <=  instance_.number_of_nodes ; ++i){	
				// verifica qual menor peso naquele nó		
				if( instance_.distance_matrix.at(index).at(i) < weight && index != i && !mark.at(i)){
					weight =  instance_.distance_matrix.at(index).at(i);
					closer = i;
				}
			}
			index = closer;
			capacity +=  instance_.nodes.at(index).demand;
			
			if( instance_.capacity >= capacity){
				routes.push_back(index);
				mark.at(index) = true;
				++counter_node;
				// procura o primeiro não marcado
				for(int i = 1; i <=  instance_.number_of_nodes; ++i){
					if(!mark.at(i)){
						weight =  instance_.distance_matrix.at(index).at(i);
						closer = i;
						break;
					}
				}
			} else
			break;
		}

		--remainder;
		
		routes.push_back(0);
		truck.route = routes;
		solution.trucks.push_back(truck);
	}

	return solution;
}

void CVRP::VNS::calc_cost_routes(Solution& solution){
	for(int i = 0; i < solution.trucks.size(); ++i){
		double tmp = 0;
		for(int j = 0; j < solution.trucks[i].route.size() - 1; ++j){
			tmp += instance_.distance_matrix[j][j+1];
		}
		solution.cost += tmp;
	}

}
