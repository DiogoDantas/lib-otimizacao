#include <iostream>
#include <string>
#include "../inc/edit_distance.hpp"

int main(int argc, char const *argv[])
{
	int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {

      std::string str1, str2;

      std::cin >> str1;
      std::cin >> str2;

			std::cout << dynamic::edit_distance(str1, str2, str1.length(), str2.length()) << std::endl;

  }


    return 0;
}
