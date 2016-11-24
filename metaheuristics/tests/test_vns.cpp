#include "../inc/parser.hpp"
#include "../inc/cvrp.hpp"
#include "../inc/grasp.hpp"
#include "../inc/vns.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
	
	//Parser to get the input and build the problem structure
	CVRP::Parser parser;
    //building the problem structure, basically filling the Instance struct
	CVRP::Instance problem_instance = parser.build_problem();

	CVRP::VNS vns(problem_instance);
	CVRP::Solution solution = vns.run();
	                  
	std::cout << "Best cost: " << solution.solution_cost << std::endl;                 
	for(auto& truck : solution.trucks){
		for(auto route : truck.route){
			std::cout << route << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}
