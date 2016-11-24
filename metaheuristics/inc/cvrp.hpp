#ifndef CVRP_H
#define  CVRP_H
#include <vector>
#include <list>

namespace CVRP {
  struct Solution;
  struct Truck;
}


struct CVRP::Truck{
  int capacity;
  std::vector<int> route;
  double route_cost;
};

//cost is the total cost of the solution
//routes is a vector {max size: number of trucks} of the routes
struct CVRP::Solution{
  double solution_cost;
  std::vector<Truck> trucks;
};

#endif
