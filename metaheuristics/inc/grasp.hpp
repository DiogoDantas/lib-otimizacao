#ifndef GRASP_H
#define  GRASP_H
#include "parser.hpp"
#include "cvrp.hpp"
#include <vector>
#include <list>
#include <utility>
#include <tuple>

namespace CVRP
{
  class Grasp;
}

class CVRP::Grasp
{
  private:
    Instance instance_;
  public:
    Grasp(Instance instance);
    ~Grasp();
    Solution run(void);
    Solution construct_greedy_solution();
    bool compare_distance(Truck &a, Truck &b);
    //Solution check_and_repair_solution(Solution found_solution);
    void compare_solutions(Solution found_solution, Solution &best_solution);
    void local_search(Solution &current_solution);
    int get_closest_truck(std::vector<Truck> &trucks, Instance instance, int random_node);
    Truck two_opt_swap(Truck &truck, int i, int k);
    void two_opt(Truck &truck);
    double calculate_cost(Truck truck);
    //Solution local_search(Solution current_solution);
    std::vector<std::tuple<int,int,double>> get_candidates(void);
    std::pair<double,double> get_min_and_max(std::vector<std::tuple<int,int,double>> candidates_list);
    void insert_into_solution(std::tuple<int,int,double> candidate, Solution* current_solution);
    void add_return_route(std::vector<Truck> &trucks);
    void print_solution(Solution current_solution);
};


#endif
