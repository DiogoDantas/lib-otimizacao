/**
 * @author     Marcos Alves
 * @date       16-10-2016
 */
#include <iostream>
#include <vector>
#include "../inc/box_stacking.hpp"

int main(int argc, char const *argv[]) {
  	int loop, size, tmp;
  	std::cin >> loop;
  	int h, w, d; 

	for (int i = 0; i < loop; ++i) {
		std::cin >> size;
		
		std::vector<dynamic::box_t> boxes;

		for(int j = 0 ; j < size ; ++j){
			std::cin >> h >> w >> d;
			boxes.push_back({h, w, d});
		}
		std::cout << dynamic::box_stacking(boxes) << std::endl; 
  	}
  	return 0;
}
