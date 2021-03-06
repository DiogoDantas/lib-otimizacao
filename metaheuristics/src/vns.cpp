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
	mark.at(1) = true;

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
		for(int i = 2; i <=  instance_.number_of_nodes ; ++i){
			if(!mark.at(i)){
				weight =  instance_.distance_matrix.at(1).at(i);
				closer = i;
				break;
			}
		}
		// capacidade do atual veiculo
		int capacity = 0;
		// vector indicando por qual nó o veiculo deve passar
		std::vector<int> routes;

		//Inserindo o nó do deposito na rota
		routes.push_back(1);

		// checando se todos os nós foram visitados
		while(counter_node !=  instance_.number_of_nodes){

			for(int i = 2 ; i <=  instance_.number_of_nodes ; ++i){	
				// verifica qual menor peso naquele nó		
				if( instance_.distance_matrix.at(index).at(i) < weight && index != i && !mark.at(i)){
					weight =  instance_.distance_matrix.at(index).at(i);
					closer = i;
				}
			}

			index = closer;
			capacity +=  instance_.nodes.at(index).demand;
			
			if(instance_.capacity >= capacity){
				truck.capacity = capacity;
				routes.push_back(index);
				mark.at(index) = true;
				++counter_node;
				// procura o primeiro não marcado
				for(int i = 2; i <=  instance_.number_of_nodes; ++i){
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
		
		routes.push_back(1);
		truck.route = routes;
		solution.trucks.push_back(truck);
	}

	return solution;
}

double CVRP::VNS::calc_cost_routes(Solution& solution){
	double cost = 0;
	for(auto & truck : solution.trucks){
		cost += calc_cost_route(truck);
	}

	solution.solution_cost = cost;

	return cost;

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

	new_truck.route.reserve(start.size() + middle.size() + end.size());
	new_truck.route.insert(new_truck.route.end(), start.begin(), start.end());
	new_truck.route.insert(new_truck.route.end(), middle.begin(), middle.end());
	new_truck.route.insert(new_truck.route.end(), end.begin(), end.end());

	new_truck.route_cost = calc_cost_route(new_truck);

	return new_truck;
}

CVRP::Solution CVRP::VNS::local_search(Solution &current_solution)
{
	for (auto &truck : current_solution.trucks)
	{
		two_opt(truck);
	}

	calc_cost_routes(current_solution);
	calc_capacity(current_solution);

	return current_solution;

}

CVRP::Solution CVRP::VNS::vnd(Solution current_solution){
	bool improve = true;
	while(improve){
		improve = false;
		int k = 0;
		while(k < 5){
			Solution new_solution = local_search(current_solution);

			if(calc_cost_routes(new_solution) < calc_cost_routes(current_solution)){
				improve = true;
				current_solution = new_solution;
			}

			k++;
		}
	}

	return current_solution;
}

void CVRP::VNS::calc_capacity(Solution& solution){
	int capacity = 0;
	for(auto & truck : solution.trucks){
		for(int i = 0; i < truck.route.size(); ++i){
			capacity += instance_.nodes.at(truck.route.at(i)).demand;
		}

		truck.capacity = capacity;
		capacity = 0;
	}
}

CVRP::Solution CVRP::VNS::perturbation(Solution current_solution){

		int route_1 = 0, route_2 = 0;
		int i_route_1 = 0, k_route_1 = 0;
		int i_route_2 = 0, k_route_2 = 0;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, current_solution.trucks.size()-1);

		do
		{
		//Escolhendo a primeira rota que sera pertubada
			route_1 = dist(gen);

		//Escolhendo a segunda rota que sera pertubada
			route_2 = dist(gen);

		}while(route_1 == route_2);

		std::uniform_int_distribution<> dist2(1, current_solution.trucks.at(route_1).route.size()-2);
		std::uniform_int_distribution<> dist3(1, current_solution.trucks.at(route_2).route.size()-2);

		do{
			i_route_1 = dist2(gen);
			k_route_1 = dist2(gen);
		}while(i_route_1 > k_route_1);

		do{
			i_route_2 = dist3(gen);
			k_route_2 = dist3(gen);
		}while(i_route_2 > k_route_2);

		current_solution.trucks.at(route_1) =  two_opt_swap(current_solution.trucks.at(route_1), i_route_1, k_route_1);
		current_solution.trucks.at(route_2) =  two_opt_swap(current_solution.trucks.at(route_2), i_route_2, k_route_2);


	return current_solution;
}

CVRP::Solution CVRP::VNS::run(){

	double limit = 60.0;
	int MAX_ITERATIONS = std::numeric_limits<int>::max();
	int count = 0;

	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	CVRP::Solution initial_solution = generate_initial_solution();
	CVRP::Solution improve_solution = vnd(initial_solution);

	CVRP::Solution best_solution = improve_solution;

	while(count < MAX_ITERATIONS){
		improve_solution = perturbation(improve_solution);
		improve_solution = vnd(improve_solution);

		if(calc_cost_routes(improve_solution) < calc_cost_routes(best_solution)){
			best_solution = improve_solution;
		}

		count++;
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		if((std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count()) > limit)
			break;
	}

	return best_solution;

}