#include "../inc/grasp.hpp"
#include "../inc/quicksort.cpp"
#include <utility>
#include <vector>
#include <random>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <algorithm>

CVRP::Grasp::Grasp(Instance instance)
{
  std::clog << "LOG:  Creating Grasp.." << std::endl;
  instance_ = instance;

}

CVRP::Grasp::~Grasp(){}

CVRP::Solution CVRP::Grasp::run()
{
  int MAX = 10;
  Solution best_solution;
  best_solution.cost = std::numeric_limits<double>::max();
  Solution found_solution;

  std::clog << "LOG:  Running Grasp "<<MAX<<" times .." << std::endl;
  for (int i = 0; i < MAX; i++) {
    std::clog << "LOG:  Iteration "<<i<<"\n ----------------" << std::endl;
    found_solution = construct_greedy_solution();
    //found_solution = check_and_repair_solution(found_solution);
    //found_solution = local_search(found_solution);
    compare_solutions(found_solution, best_solution);
    print_solution(best_solution);
  }

  return best_solution;
}

void CVRP::Grasp::compare_solutions(Solution found_solution, Solution &best_solution)
{
  // std::clog << "LOG: comparing solutions.."<<std::endl;
  // std::clog << "LOG: found:"<<std::endl;
  // print_solution(found_solution);
  // std::clog << "LOG: best:"<<std::endl;
  // print_solution(*(best_solution));

  if (best_solution.cost > found_solution.cost)
  {
    best_solution.cost = found_solution.cost;
    best_solution.trucks = found_solution.trucks;
  }

}


void CVRP::Grasp::print_solution(Solution current_solution)
{
  std::cout << "Cost:" << current_solution.cost << std::endl;
  std::cout << "Routes:" << std::endl;
  for (auto &truck : current_solution.trucks)
  {
    for (auto node : truck.route)
    {
      std::cout << node <<" ";
    }

    std::cout << std::endl;
  }

}

CVRP::Solution CVRP::Grasp::construct_greedy_solution()
{
  const int DEPOT = 0;
  Solution found_solution;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::vector<Truck> trucks(instance_.number_of_trucks);
  std::uniform_int_distribution<> dist(1, instance_.nodes.size()-1);

  //filling all trucks capacity
  for (auto &truck : trucks)
  {
    truck.capacity = instance_.capacity;
    truck.route.push_back(DEPOT);
  }

  for (auto &node : instance_.nodes)
  {
    node.marked = false;
  }

  int number_of_marked = 0;

  while(number_of_marked != instance_.nodes.size()-1)
  {
    //randomic
    int random_node = dist(gen);
    if(!instance_.nodes.at(random_node).marked)
    {
      //sort by smallest distance
      //greedy
      // sorting::quickSort(trucks, 0, trucks.size()-1, instance_, random_node);

      //inserting if capacity is available
      for (auto &truck : trucks)
      {
        if((truck.capacity - instance_.nodes.at(random_node).demand) >= 0)
        {
          found_solution.cost += instance_.distance_matrix[truck.route.back()][random_node];
          truck.route.push_back(random_node);
          truck.capacity -= instance_.nodes.at(random_node).demand;
          instance_.nodes.at(random_node).marked = true;
          break;
        }
      }

      number_of_marked++;
    }

  }
  //
  // for (int i = 1; i <= this->instance_.number_of_nodes; i++)
  // {
  //   bool inserted = false;
  //   while (!inserted)
  //   {
  //     int random = dist(gen);
  //     std::clog << "random: "<< random << std::endl;
  //     if((trucks.at(random).capacity - instance_.nodes.at(i).demand) >= 0)
  //     {
  //       trucks.at(random).route.push_back(i);
  //       trucks.at(random).capacity -= instance_.nodes.at(i).demand;
  //       inserted = true;
  //     }
  //   }
  // }




  for (auto &truck : trucks)
  {
    found_solution.cost += instance_.distance_matrix[truck.route.back()][DEPOT];
    truck.route.push_back(DEPOT);
  }

  found_solution.trucks = trucks;

  int i =0;
  for (auto &truck : trucks)
  {
    std::clog << "Truck "<<i<< std::endl;
    std::clog << "Capacity "<<truck.capacity<< std::endl;
    std::clog << "Route "<<std::endl;
    for (auto route : truck.route)
      std::clog << route << std::endl;
    i++;
  }
  return found_solution;
}
