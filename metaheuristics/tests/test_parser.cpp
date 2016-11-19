#include "../inc/parser.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
  //Parser to get the input and build the problem structure
  CVRP::Parser parser;
  //building the problem structure, basically filling the Instance struct
  CVRP::Instance problem_instance = parser.build_problem();

  std::cout << "Number of nodes: ";
  std::cout << problem_instance.number_of_trucks << std::endl;

  std::cout << "Number of nodes: ";
  std::cout << problem_instance.number_of_nodes << std::endl;

  std::cout << "Distance between node 1 and 2:\n";
  std::cout << "Node 1: "<<problem_instance.nodes.at(0).x<<", "<<problem_instance.nodes.at(0).y << std::endl;
  std::cout << "Node 2: "<<problem_instance.nodes.at(1).x<<", "<<problem_instance.nodes.at(1).y << std::endl;
  std::cout << "Distance: "<<problem_instance.distance_matrix.at(0).at(1)<< std::endl;

  return 0;
}
