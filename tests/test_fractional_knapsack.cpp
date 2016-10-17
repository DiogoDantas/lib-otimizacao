#include <iostream>
#include "../inc/fractional_knapsack.hpp"

int main(int argc, char const *argv[]) {

  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
		int totalWeight, nElements;
		std::cin >> totalWeight;
		std::cin >> nElements;

		std::vector<greedy::Item> arr;

		for (int i = 0; i < nElements; i++) {
			int value, weight;
			std::cin >> value;
			std::cin >> weight;
			greedy::Item item {value, weight};
			arr.push_back(item);
		}

		std::cout << greedy::fractional_knapsack(totalWeight, arr, nElements) << std::endl;


	}

  return 0;
}
