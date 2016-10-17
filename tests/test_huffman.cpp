/**
 * @author     Marcos Alves
 * @date       16-10-2016
 */
#include <iostream>
#include <vector>
#include "../inc/huffman.hpp"

int main(int argc, char const *argv[]) {
  	int loop, size, tmp;
  	char c;
  	std::cin >> loop;

	for (int i = 0; i < loop; ++i) {
		std::cin >> size;
		std::vector<char> ch;
		std::vector<int> f;
		for(int j = 0 ; j < size ; ++j){
			std::cin >> c;
			ch.push_back(c);
		}
		for(int j = 0 ; j < size ; ++j){
			std::cin >> tmp;
			f.push_back(tmp);
		}
		greedy::node_t *a = greedy::huff_encode(ch, f);
		greedy::code_puts(a);
  	}
  	return 0;
}
