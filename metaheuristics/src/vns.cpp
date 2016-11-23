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
	double cost = 0;
	for(auto & truck : solution.trucks){
		cost += calc_cost_route(truck);
	}

	solution.solution_cost = cost;

}

double CVRP::VNS::calc_cost_route(Truck & truck){
	
	double cost = 0;

	for(int i = 0; i < truck.route.size() - 1; ++i){
		cost += instance_.distance_matrix[truck.route.at(i)][truck.route.at(i+1)];
	}

	return cost;
}

void CVRP::VNS::two_opt(Truck &truck){
	int size = truck.route.size();
	if (size<4)
		return;

	double best_cost = truck.route_cost;

  //iterate over route nodes
	for (int node = 0; node < truck.route.size(); node++)
	{
		int i = node + 1;
		int k = i + 1;
		while (k < truck.route.size())
		{
			Truck new_truck = two_opt_swap(truck, i, k);

			if(calc_cost_route(new_truck) < calc_cost_route(truck))
			{
				std::clog << "AQUI" << std::endl;
				truck = new_truck;
			}
			k++;
		}
	}
}

CVRP::Truck CVRP::VNS::two_opt_swap(Truck truck, int i, int k){
	Truck new_truck;

	std::vector<int> start (truck.route.begin(), truck.route.begin()+i);
	std::vector<int> middle (truck.route.begin()+i, truck.route.begin()+k);
	std::reverse(middle.begin(), middle.end());

	std::vector<int> end (truck.route.begin()+k, truck.route.end());

	std::move(start.begin(), start.end(),std::back_inserter(new_truck.route));
	std::move(middle.begin(), middle.end(),std::back_inserter(new_truck.route));
	std::move(end.begin(), end.end(),std::back_inserter(new_truck.route));

	new_truck.route_cost = calc_cost_route(new_truck);

	return new_truck;
}

void CVRP::VNS::local_search(Solution &current_solution)
{
  for (auto &truck : current_solution.trucks)
  {
    two_opt(truck);
  }

  calc_cost_routes(current_solution);

}