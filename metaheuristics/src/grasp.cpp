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
  int MAX = 200;
  Solution best_solution;
  best_solution.solution_cost = std::numeric_limits<double>::max();
  Solution found_solution;

  std::clog << "LOG:  Running Grasp "<<MAX<<" times .." << std::endl;
  for (int i = 0; i < MAX; i++) {
    std::clog << "LOG:  Iteration "<<i<<"\n ----------------" << std::endl;
    found_solution = construct_greedy_solution();
    local_search(found_solution);
    compare_solutions(found_solution, best_solution);
    print_solution(found_solution);
  }
  print_solution(found_solution);
  return best_solution;
}

void CVRP::Grasp::local_search(Solution &current_solution)
{
  for (auto &truck : current_solution.trucks)
  {
    current_solution.solution_cost -= truck.route_cost;
    two_opt(truck);//this could change the route
    current_solution.solution_cost += truck.route_cost;
  }

}

// repeat until no improvement is made {
//     start_again:
//     best_distance = calculateTotalDistance(existing_route)
//     for (i = 0; i < number of nodes eligible to be swapped - 1; i++) {
//         for (k = i + 1; k < number of nodes eligible to be swapped; k++) {
//             new_route = 2optSwap(existing_route, i, k)
//             new_distance = calculateTotalDistance(new_route)
//             if (new_distance < best_distance) {
//                 existing_route = new_route
//                 goto start_again
//             }
//         }
//     }
// }
void CVRP::Grasp::two_opt(Truck &truck)
{
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
      if(new_truck.route_cost < truck.route_cost)
      {
        truck = new_truck;
      }
      k++;
    }
  }
}

  //
  // 2optSwap(route, i, k) {
  //     1. take route[1] to route[i-1] and add them in order to new_route
  //     2. take route[i] to route[k] and add them in reverse order to new_route
  //     3. take route[k+1] to end and add them in order to new_route
  //     return new_route;
  // }

CVRP::Truck CVRP::Grasp::two_opt_swap(Truck truck, int i, int k){
  Truck new_truck;

  std::vector<int> start (truck.route.begin(), truck.route.begin()+i);
  std::vector<int> middle (truck.route.begin()+i, truck.route.begin()+k);
  std::reverse(middle.begin(), middle.end());

  std::vector<int> end (truck.route.begin()+k, truck.route.end());

  std::move(start.begin(), start.end(),std::back_inserter(new_truck.route));
  std::move(middle.begin(), middle.end(),std::back_inserter(new_truck.route));
  std::move(end.begin(), end.end(),std::back_inserter(new_truck.route));

  new_truck.route_cost = calculate_cost(new_truck);

  return new_truck;
}

CVRP::Truck& CVRP::Grasp::get_closest_truck(std::vector<Truck> &trucks, Instance instance, int random_node)
{
    double best_distance;
    /**getting the first allowed distance**/
    int i = 0;
    for (i = 0; i < trucks.size(); i++)
    {
      if((trucks.at(i).capacity - instance.nodes.at(random_node).demand) >= 0)
      {
        best_distance = instance.distance_matrix[trucks.at(i).route.back()][random_node];
        break;
      }
    }

    int index;
    /**testing for all the others**/
    for (int j = i ; j < trucks.size(); j++)
    {
      if((instance.distance_matrix[trucks.at(j).route.back()][random_node] <= best_distance)/*test distance*/ &&
        ((trucks.at(i).capacity - instance.nodes.at(random_node).demand) >= 0)/*test capacity*/)
      {
        best_distance = instance.distance_matrix[trucks.at(j).route.back()][random_node];
        index = j;
      }
    }

    return trucks.at(index);
}

double CVRP::Grasp::calculate_cost(Truck truck){
  int i;
  double tmp = 0;
  for (i = 0; i < truck.route.size()-1; i++) {
    tmp += instance_.distance_matrix[truck.route[i]][truck.route[i+1]];
  }
  return tmp;
}

void CVRP::Grasp::compare_solutions(Solution found_solution, Solution &best_solution)
{
  if (best_solution.solution_cost > found_solution.solution_cost)
  {
    best_solution.solution_cost = found_solution.solution_cost;
    best_solution.trucks = found_solution.trucks;
  }

}


void CVRP::Grasp::print_solution(Solution current_solution)
{
  std::cout << "Cost:" << current_solution.solution_cost << std::endl;
  std::cout << "Routes:" << std::endl;
  for (auto &truck : current_solution.trucks)
  {
    for (auto node : truck.route)
    {
      std::cout << node <<" ";
    }

    std::cout<<"capacity: "<<truck.capacity<<std::endl;

  }

}

CVRP::Solution CVRP::Grasp::construct_greedy_solution()
{
  const int DEPOT = 0;
  Solution found_solution;
  found_solution.solution_cost = 0;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::vector<Truck> trucks(instance_.number_of_trucks);
  std::uniform_int_distribution<> dist(1, instance_.nodes.size()-1);

  //filling all trucks
  for (auto &truck : trucks)
  {
    truck.capacity = instance_.capacity;
    truck.route.push_back(DEPOT);
    truck.route_cost = 0;
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

      //greedy
      Truck &truck = get_closest_truck(trucks, instance_, random_node);
      truck.route_cost += instance_.distance_matrix[truck.route.back()][random_node];
      truck.route.push_back(random_node);
      truck.capacity -= instance_.nodes.at(random_node).demand;
      instance_.nodes.at(random_node).marked = true;

      number_of_marked++;
    }

  }

  //returning from depot
  for (auto &truck : trucks)
  {
    truck.route_cost += instance_.distance_matrix[truck.route.back()][DEPOT];
    truck.route.push_back(DEPOT);
  }

  found_solution.trucks = trucks;

  //adding each route cost into solution
  for (auto &truck : found_solution.trucks)
  {
    found_solution.solution_cost += truck.route_cost;
  }

  return found_solution;
}
