#include "../inc/coloracao_grafos.hpp"
#include <vector>
#include <iostream>

gulosos::Graph::Graph(int v){
  this->numberV_ = v;
  this->adjList_ = new std::list<int>[v];
}

gulosos::Graph::~Graph(){
    delete [] adjList_;
}

//Grafico não direcionado fica simetrico na lista
void gulosos::Graph::addEdge(int v, int w){
  this->adjList_[v].push_back(w);
  this->adjList_[w].push_back(v);
}


void gulosos::Graph::coloring(){

  //arrays de resultado e de disponibilidade
  std::vector<int> result;
  std::vector<bool> available;
  //primeira cor ao primeiro elemento
  result.push_back(0);

  available.push_back(false);

  for (int i = 1; i < this->numberV_; i++) {
    available.push_back(false);
    result.push_back(-1);
  }

  // colorindo os outros elementos
    for (int u = 1; u < this->numberV_; u++)
    {

        std::list<int>::iterator i;

        for (i = this->adjList_[u].begin(); i != this->adjList_[u].end(); ++i)
            if (result.at(*i) != -1)
                available.at(result.at(*i)) = true;

        //procura a primeira cor disponivel
        int color;
        for (color = 0; color < this->numberV_; color++)
            if (available.at(color) == false)
                break;

        //encontra, atribui
        result.at(u) = color;

        //reseta os valores para a próxima iteração
        for (i = this->adjList_[u].begin(); i != this->adjList_[u].end(); ++i)
            if (result.at(*i) != -1)
                available.at(result.at(*i)) = false;
    }

    //mostra o resultado
    for (int i = 0; i < this->numberV_; i++)
        std::cout << "V[" << i << "] - " << result.at(i) << std::endl;

}
