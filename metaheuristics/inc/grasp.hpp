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
    Solution construct_greedy_solution(int alpha);
    //Solution check_and_repair_solution(Solution found_solution);
    void compare_solutions(Solution found_solution, Solution* best_solution);
    //Solution local_search(Solution current_solution);
    std::vector<std::tuple<int,int,double>> get_candidates(void);
    std::pair<double,double> get_min_and_max(std::vector<std::tuple<int,int,double>> candidates_list);
    void insert_into_solution(std::tuple<int,int,double> candidate, Solution* current_solution);
    void add_return_route(Solution* current_solution);
    void print_solution(Solution current_solution);
};


#endif
