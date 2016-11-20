#include "../inc/grasp.hpp"
#include <utility>
#include <vector>
#include <random>
#include <limits>
#include <iostream>

CVRP::Grasp::Grasp(Instance instance)
{
  std::clog << "LOG:  Creating Grasp.." << std::endl;
  instance_ = instance;

}

CVRP::Grasp::~Grasp(){}

CVRP::Solution CVRP::Grasp::run()
{
  int MAX = 10;
  int ALPHA = 1;
  Solution best_solution;
  best_solution.cost = std::numeric_limits<double>::max();
  Solution found_solution;

  std::clog << "LOG:  Running Grasp "<<MAX<<" times .." << std::endl;
  for (int i = 0; i < MAX; i++) {
    std::clog << "LOG:  Iteration "<<i<<"\n ----------------" << std::endl;
    found_solution = construct_greedy_solution(ALPHA);
    //found_solution = check_and_repair_solution(found_solution);
    //found_solution = local_search(found_solution);
    compare_solutions(found_solution, &best_solution);
    print_solution(best_solution);
  }

  return best_solution;
}

void CVRP::Grasp::compare_solutions(Solution found_solution, Solution* best_solution)
{
  // std::clog << "LOG: comparing solutions.."<<std::endl;
  // std::clog << "LOG: found:"<<std::endl;
  // print_solution(found_solution);
  // std::clog << "LOG: best:"<<std::endl;
  // print_solution(*(best_solution));

  Solution returned_solution;

  if (best_solution->cost > found_solution.cost)
  {
    best_solution->cost = found_solution.cost;
    best_solution->routes = found_solution.routes;
  }

}


void CVRP::Grasp::print_solution(Solution current_solution)
{
  std::cout << "Cost:" << current_solution.cost << std::endl;
  std::cout << "Routes:" << std::endl;
  for (auto &route : current_solution.routes)
  {
    for (auto node : route)
    {
      std::cout << node <<" ";
    }

    std::cout << std::endl;
  }

}

/*
procedure Greedy Randomized Construction(Seed)
  Solution ← 0;
  Initialize the set of candidate elements;
  Evaluate the incremental costs of the candidate elements;
  while there exists at least one candidate element do
    Build the restricted candidate list (RCL);
    Select an element s from the RCL at random;
    Solution ← Solution ∪ {s};
    Update the set of candidate elements;
    Reevaluate the incremental costs;
  end;
 return Solution;
end Greedy Randomized Construction.
*/

CVRP::Solution CVRP::Grasp::construct_greedy_solution(int alpha)
{
  int DEPOT = 0;
  std::clog << "LOG:  Construction greedy solution.." << std::endl;
  //Solution ← 0;
  Solution found_solution;
  // std::clog << "LOG:  Initializing solution.." << std::endl;
  found_solution.cost = 0;
  for (int i = 0; i < instance_.number_of_trucks; i++)
  {
    std::list<int> tmp;
    tmp.push_back(DEPOT);
    found_solution.routes.push_back(tmp);
  }
  // print_solution(found_solution);

  //Initialize the set of candidate elements;
  std::vector<std::tuple<int,int,double>> candidates_list = get_candidates();
  std::vector<std::tuple<int,int,double>> restricted_candidates_list;
  std::random_device rd;
  std::mt19937 gen(rd());

  while (candidates_list.size() != 0)
  {
      // std::clog << "LOG:  Getting mininmum and maximum from list.." << std::endl;
      std::pair<double, double> min_max = get_min_and_max(candidates_list);
      double minimum = min_max.first;
      double maximum = min_max.second;
      // std::clog << "LOG:  min:  " <<minimum<<std::endl;
      // std::clog << "LOG:  max:  " <<maximum<<std::endl;

      // std::clog << "LOG:  choosing candidates for RCL list.."<<std::endl;
      for (auto &candidate : candidates_list) // access by reference to avoid copying
      {
        if (std::get<1>(candidate) <= minimum + alpha * (maximum - minimum))
        {
          // std::clog << "LOG:  chosen candidate for RCL list:  [" <<std::get<0>(candidate)<<" "<<std::get<1>(candidate)<<" "<<std::get<2>(candidate)<<"]"<<std::endl;
          restricted_candidates_list.push_back(candidate);
        }

      }

      std::uniform_int_distribution<> dis(0, restricted_candidates_list.size()-1);
      int random = dis(gen);
      std::tuple<int, int, double> random_candidate = restricted_candidates_list.at(random);
      // std::clog << "LOG:  chosen candidate from RCL to solution:  [" <<std::get<0>(random_candidate)<<" "<<std::get<1>(random_candidate)<<" "<<std::get<2>(random_candidate)<<"]"<<std::endl;
      insert_into_solution(random_candidate, &found_solution);

      // print_solution(found_solution);
      candidates_list.erase(candidates_list.begin()+random);
      // std::clog << "LOG:  candidate erased from candidates list.."<<std::endl;
      // Reevaluate the incremental costs;
      // std::clog << "LOG:  Reevaluating the incremental costs.."<<std::endl;
      for (int i=0; i < candidates_list.size(); i++)
      {
        if(std::get<1>(candidates_list.at(i)) == std::get<1>(random_candidate))
        {
            double new_cost = instance_.distance_matrix[std::get<0>(random_candidate)][std::get<0>(candidates_list.at(i))];
            candidates_list[i] = std::make_tuple(std::get<0>(candidates_list.at(i)), std::get<1>(candidates_list.at(i)), new_cost);
        }
      }

      // std::vector<std::tuple<int, int, double>> update_candidates;
      // std::vector<std::tuple<int, int, double>> insert_candidates;
      // for (auto &candidate : candidates_list)
      // {
      //       if(std::get<1>(candidate) == std::get<1>(random_candidate))
      //         update_candidates.push_back(candidate)
      // }
      //
      for (auto &candidate : candidates_list)
      {
        if(std::get<1>(candidate) == std::get<1>(random_candidate))
        {
          double new_cost = instance_.distance_matrix[std::get<0>(random_candidate)][std::get<1>(candidate)];
          std::get<2>(candidate) = new_cost;
        }

      }

      // std::clog << "LOG:  Clearing RCL list.."<<std::endl;
      restricted_candidates_list.clear();
  }

  add_return_route(&found_solution);

  // std::clog << "LOG:  After return route.." << std::endl;
  // print_solution(found_solution);
  return found_solution;
}



//getting candidates
std::vector<std::tuple<int,int,double>> CVRP::Grasp::get_candidates()
{
  // std::clog << "LOG:  Getting candidates list.." << std::endl;
  int DEPOT = 0;

  std::vector<std::tuple<int,int,double>> candidates;

  for (int i = 1; i <= this->instance_.number_of_nodes; i++) {
    for (int k = 0; k < this->instance_.number_of_trucks; k++) {
      candidates.push_back(std::make_tuple(i,k,instance_.distance_matrix[DEPOT][i]));
    }
  }

  return candidates;

}

//getting min and max from candidates list
std::pair<double,double> CVRP::Grasp::get_min_and_max(std::vector<std::tuple<int,int,double>> candidates_list)
{
  const double greatest_double = std::numeric_limits<double>::max();
  double minimum = greatest_double;
  double maximum = -greatest_double;
  for (auto &candidate : candidates_list)
  {
      if (minimum > std::get<1>(candidate))
          minimum = std::get<1>(candidate);

      if(maximum < std::get<1>(candidate))
          maximum = std::get<1>(candidate);
  }

   return std::make_pair(minimum, maximum);
}

void CVRP::Grasp::add_return_route(Solution* current_solution)
{
  // std::clog << "LOG:  Adding return route .." << std::endl;
  const int DEPOT = 0;
  for (int i = 0; i < instance_.number_of_trucks; i++) {
    int last_client = current_solution->routes[i].back();
    current_solution->routes[i].push_back(DEPOT);
    current_solution->cost += instance_.distance_matrix[last_client][DEPOT];
    // print_solution(*(current_solution));
  }
}

void CVRP::Grasp::insert_into_solution(std::tuple<int,int,double> candidate, Solution* current_solution)
{

  // std::clog << "LOG:  Inserting into solution .." << std::endl;
  int client = std::get<0>(candidate);
  int route = std::get<1>(candidate);
  double cost = std::get<2>(candidate);
  current_solution->routes[route].push_back(client);
  current_solution->cost += cost;
  // print_solution(*(current_solution));
}
