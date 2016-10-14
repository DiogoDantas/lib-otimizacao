#include <iostream>
#include "../inc/mochila_fracionaria.hpp"

int main(int argc, char const *argv[]) {

  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
		int totalWeight, nElements;
		std::cin >> totalWeight;
		std::cin >> nElements;

		std::vector<gulosos::Item> arr;

		for (int i = 0; i < nElements; i++) {
			int value, weight;
			std::cin >> value;
			std::cin >> weight;
			gulosos::Item item {value, weight};
			arr.push_back(item);
		}

		std::cout << gulosos::mochila_fracionaria(totalWeight, arr, nElements) << std::endl;


	}

  return 0;
}
