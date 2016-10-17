/**
 * @author     Marcos Alves
 * @date       16-10-2016
 */
#include <iostream>
#include "../inc/binomial_coefficient.hpp"

int main(int argc, char const *argv[]) {
  int loop, n, k;
  std::cin >> loop;
  for (int i = 0; i < loop; i++) {
      std::cin >> n >> k;
      std::cout << "Value of C("<< n << ", "<< k <<") is " 
      		   << dynamic::binomial_coeff(n, k) << std::endl;
  }
  return 0;
}
