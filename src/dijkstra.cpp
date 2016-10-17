#include "../inc/dijkstra.hpp"

int greedy::min_distance(std::vector<int> & dist_vector, std::vector<bool> & spt_set, const int num_vertices){
  // Inicializando o min como INF
 int min = std::numeric_limits<int>::max(), min_index;

 for (int i = 0; i < num_vertices; i++)
   if (spt_set[i] == false && dist_vector[i] <= min)
     min = dist_vector[i], min_index = i;

   return min_index;
 }

 void greedy::print_solution(std::vector<int> & dist_vector, const int num_vertices){
  std::cout << "Vertex" << "\t" << "Distance from Source" << std::endl;
  for (int i = 0; i < num_vertices; ++i)
    std::cout << i <<"\t"<< dist_vector[i] << std::endl;
 }
