#include "parser.hpp"
#include "cvrp.hpp"
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>


namespace CVRP{
	class VNS{

	public:
		VNS(Instance);
		~VNS();
		Solution run();
		Solution generate_initial_solution();
		void calc_cost_routes(Solution& solution);
		double calc_cost_route(Truck & truck);
		void two_opt(Truck &truck);
		Truck two_opt_swap(Truck truck, int i, int k);
		void local_search(Solution &current_solution);


	private:
		Instance instance_;



	};
}