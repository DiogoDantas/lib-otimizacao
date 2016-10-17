#ifndef GRAPH_COLORING_HPP
#define  GRAPH_COLORING_HPP
#include <list>

namespace greedy {
  class Graph {
  private:
    int numberV_;
    std::list<int>* adjList_;

  public:
    Graph (int v);
    virtual ~Graph ();

    void addEdge(int v, int w);
    void coloring();
  };

}
#endif
