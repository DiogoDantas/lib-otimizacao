#include "../inc/knapsack.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	int T = 0;

	std::cin >> T;

	while(T) {
	    int num_elements = 0;
	    int weight = 0;
	    std::vector<int> weights;
	    std::vector<int> values;

	    std::cin >> num_elements;
	    std::cin >> weight;

	    for (int i = 0; i < num_elements; ++i)
	    {
	    	int tmp = 0;
	    	std::cin >> tmp;
	    	weights.push_back(tmp);
	    }

	    for (int i = 0; i < num_elements; ++i)
	    {
	    	int tmp = 0;
	    	std::cin >> tmp;
	    	values.push_back(tmp);
	    }

	    std::cout << dynamic::knapsack(weight, weights, values, num_elements) << std::endl;

	    T--;
	}


	return 0;
}
