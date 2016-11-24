#include "parser.hpp"
#include "cvrp.hpp"
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <ctime>
#include <chrono>
#include <limits>
#include <utility>
#include <cstdlib>


namespace CVRP{
	class VNS{

	public:
		VNS(Instance);
		~VNS();
		Solution run();
		Solution vnd(Solution current_solution);
		Solution generate_initial_solution();
		double calc_cost_routes(Solution& solution);
		double calc_cost_route(Truck & truck);
		void calc_capacity(Solution& solution);
		void two_opt(Truck &truck);
		Truck two_opt_swap(Truck truck, int i, int k);
		Solution local_search(Solution &current_solution);
		Solution perturbation(Solution current_solution);


	private:
		Instance instance_;



	};
}