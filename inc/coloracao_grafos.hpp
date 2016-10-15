#ifndef COLOR_GRAF_H_
#define  COLOR_GRAF_H_
#include <list>

namespace gulosos {
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
