#ifndef PARSER_H
#define PARSER_H
#include <vector>

//namespace definition
namespace CVRP {
  struct Node;
  struct Instance;
  class Parser;
}

//node definition
struct CVRP::Node{
   int demand;
   int x;
   int y;
};

//instance definition
struct CVRP::Instance{
   int number_of_trucks;
   int number_of_nodes;
   int capacity;
   std::vector<Node> nodes;
   std::vector<std::vector<double>> distance_matrix;
};

//parser definition
class CVRP::Parser{
    public:
      Parser();
      ~Parser();
      Instance build_problem();
      double calc_distance(Node node1, Node node2);
};

#endif
