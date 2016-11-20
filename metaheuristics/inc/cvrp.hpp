#ifndef CVRP_H
#define  CVRP_H
#include <vector>
#include <list>

namespace CVRP {
  struct Solution;
}

//cost is the total cost of the solution
//routes is a vector {max size: number of trucks} of the routes
struct CVRP::Solution{
  double cost;
  std::vector<std::list<int>> routes;
};

#endif
