#include <iostream>
#include "../inc/triangulo_pascal.hpp"
int main(int argc, char const *argv[]) {
  int loop, n, k;
  std::cin >> loop;
  for (int i = 0; i < loop; i++) {
      std::cin >> n >> k;

      std::cout<< "Value of C("<< n << ", "<< k <<") is " << dinamica::triangulo_pascal(n, k) << std::endl;

  }

  return 0;
}
