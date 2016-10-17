/**
 * @author     Marcos Alves
 * @date       16-10-2016
 */
#include <iostream>
#include <vector>
#include "../inc/coin_change.hpp"

int main(int argc, char const *argv[]) {
  	int loop, size, tmp;
  	std::cin >> loop;
	for (int i = 0; i < loop; ++i) {
		std::cin >> size;
		std::vector<int> s;
		int n;
		for(int j = 0 ; j < size ; ++j){
			std::cin >> tmp;
			s.push_back(tmp);
		}
		std::cin >> n;
		std::cout << dynamic::coin_change(s, n) << std::endl;
  	}
  	return 0;
}
