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
};

//cost is the total cost of the solution
//routes is a vector {max size: number of trucks} of the routes
struct CVRP::Solution{
  double cost;
  std::vector<Truck> trucks;
};

#endif
