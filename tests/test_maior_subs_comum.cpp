#include <iostream>
#include "../inc/maior_subs_comum.hpp"
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {

      int m, n;
      std::cin >> m;
      std::cin >> n;
      char X[m];
      char Y[n];

      std::cin >> X;
      std::cin >> Y;

      std::cout<< "Length of LCS is " << dinamica::lcs( X, Y, m, n ) << std::endl;

  }

  return 0;
}
