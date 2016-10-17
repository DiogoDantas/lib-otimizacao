/**
 * @author     Marcos Alves
 * @date       16-10-2016
 */
#include <iostream>
#include <vector>
#include "../inc/activity_selection.hpp"

int main(int argc, char const *argv[]) {
  	int loop, size, tmp;
  	std::cin >> loop;

	for (int i = 0; i < loop; ++i) {
		std::cin >> size;
		std::vector<int> s;
		std::vector<int> f;
		for(int j = 0 ; j < size ; ++j){
			std::cin >> tmp;
			s.push_back(tmp);
		}
		for(int j = 0 ; j < size ; ++j){
			std::cin >> tmp;
			f.push_back(tmp);
		}
		std::cout << greedy::max_activities(s, f) << std::endl;
  	}
  	return 0;
}
