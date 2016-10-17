#include "../inc/word_break.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	std::vector<std::string> dictionary  = {"mobile","samsung","sam","sung","man","mango","icecream","and",
											"go","i","like","ice","cream"};

	int T = 0;

	std::cin >> T;

	while(T) {

		std::string str;

		std::cin >> str;

		dynamic::word_break(dictionary, str) ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;

	    T--;
	}



	return 0;
}
