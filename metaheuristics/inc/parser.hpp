#ifndef PARSER_H
#define PARSER_H
#include <vector>

//namespace definition
namespace CVRP {
  class Parser;
  struct Instance;
  struct Node;
}

//node definition
struct CVRP::Node{
   int demand;
   int x;
   int y;
   bool marked = false;
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
      void print_nodes(Instance problem_instance);
      void print_matrix(Instance problem_instance);
};

#endif
