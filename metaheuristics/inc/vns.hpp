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


	private:
		Instance instance_;



	};
}