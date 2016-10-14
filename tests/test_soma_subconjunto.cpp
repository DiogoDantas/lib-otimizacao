#include "../inc/soma_subconjunto.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	//code
  int sum  = 0;
  int T = 0, N = 0;

  std::cin >> T;
  while(T){

    std::cin >> N;
    std::vector<int> set;
    for(int i = 0; i < N; i++){
      int tmp = 0;
      std::cin >> tmp;
      set.push_back(tmp);
    }

    std::cin >> sum;

    if (dinamica::soma_subconjunto(set, N, sum))
      std::cout << "Yes" << std::endl;
    else
      std::cout << "No" << std::endl;

    T--;
  }
  return 0;
}