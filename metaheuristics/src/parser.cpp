#include "../inc/parser.hpp"
#include <string>
#include <iostream>
#include <math.h>

CVRP::Parser::Parser(){
  std::clog << "LOG:  Creating Parser.." << std::endl;
}

CVRP::Parser::~Parser(){}


double CVRP::Parser::calc_distance(CVRP::Node node1, CVRP::Node node2)
{
  int a = (node2.x - node1.x);
  int b = (node2.y - node1.y);

  return sqrt(a * a + b * b);
}

void  CVRP::Parser::print_nodes(Instance problem_instance)
{
  int i =0;
  for (auto &node : problem_instance.nodes)
  {
    std::clog << "Node: " << i << std::endl;
    std::clog << "Postion: " << node.x <<", "<< node.y << std::endl;
    std::clog << "Demand: " << node.demand << std::endl;
    i++;
  }
}

void  CVRP::Parser::print_matrix(Instance problem_instance)
{
  for (auto &row : problem_instance.distance_matrix)
  {
    for (auto cell : row)
    {
      std::clog << cell <<" ";
    }

    std::clog << std::endl;
  }

}

CVRP::Instance CVRP::Parser::build_problem()
  {

    std::clog << "LOG:  Creating a temporary instance problem.." << std::endl;
    Instance problem_instance;
    std::string word;
    int i = 0;

    std::clog << "LOG:  Receiving input.." << std::endl;
    while(i<=28){
      std::cin >> word;

      if(i==12)
      {
        word.pop_back();
        std::clog << "LOG:  Number of trucks: "<<word << std::endl;
        problem_instance.number_of_trucks = std::stoi(word);
      }

      if(i==21){
        std::clog << "LOG:  Number of nodes: "<<word << std::endl;
        problem_instance.number_of_nodes = std::stoi(word);
      }

      if(i==27){
        problem_instance.capacity = std::stoi(word);
        std::clog << "LOG:  Capacity of each truck: "<<problem_instance.capacity << std::endl;
      }

      i++;
    }


    std::clog << "LOG:  Getting the nodes.." << std::endl;
    Node deposit;
    deposit.x = 1;
    deposit.y = -1;
    deposit.demand = 0;

    problem_instance.nodes.push_back(deposit);

    for (int i = 1; i <= problem_instance.number_of_nodes; i++) {
      Node node;
      std::cin >> word; //index
      std::cin >> node.x;
      std::cin >> node.y;
      problem_instance.nodes.push_back(node);
    }

    std::cin >> word; //Demand title

    std::clog << "LOG:  Getting the demand of each node.." << std::endl;
    for (int i = 1; i <= problem_instance.number_of_nodes; i++) {
      std::cin >> word; //index
      Node* node = &(problem_instance.nodes.at(i));
      int demand;
      std::cin >> demand;
      node->demand = demand;
    }

    std::clog << "LOG:  Calculating the distance between nodes.." << std::endl;
    std::vector<double> row(problem_instance.number_of_nodes);
    std::clog << "LOG:  Creating a new temp vector for rows.." << std::endl;
    for (int i = 0; i <= problem_instance.number_of_nodes; i++)
    {
      row.clear();
      for (int j = 0; j <= problem_instance.number_of_nodes; j++)
      {
        row.push_back(calc_distance(problem_instance.nodes.at(i), problem_instance.nodes.at(j)));
      }
      problem_instance.distance_matrix.push_back(row);
    }


    std::clog << "LOG:  Returning the temporary instance.." << std::endl;
    std::clog << "LOG:  Instance generated.." << std::endl;
    std::clog << "LOG:  Nodes:" << std::endl;
    print_nodes(problem_instance);
    std::clog << "LOG:  Distance matrix:" << std::endl;
    print_matrix(problem_instance);

    return problem_instance;
  }
