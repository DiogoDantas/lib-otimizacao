#include "../inc/graph_coloring.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
  int nTests;
  std::cin >> nTests;

  for (int i = 0; i < nTests; i++) {
    int sizeGraph;
    std::cin >> sizeGraph;

    greedy::Graph graph(sizeGraph);

    int node1;
    while (std::cin>>node1) {
      if(node1 == -1)
        break;
      int node2;
      std::cin >> node2;
      graph.addEdge(node1, node2);
    }

    graph.coloring();
    std::cout<<"\n";
  }
  return 0;
}
