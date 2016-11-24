#include "../inc/parser.hpp"
#include "../inc/cvrp.hpp"
#include "../inc/grasp.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
  //Parser to get the input and build the problem structure
  CVRP::Parser parser;
  //building the problem structure, basically filling the Instance struct
  CVRP::Instance problem_instance = parser.build_problem();

  CVRP::Grasp grasp(problem_instance);
  CVRP::Solution best_solution = grasp.run();
  std::cout << "Best solution:" <<std::endl;
  grasp.print_solution(best_solution);
  return 0;
}
