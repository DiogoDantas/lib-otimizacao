#include "../inc/prim.hpp"

int greedy::min_key(std::vector<int> & key, std::vector<bool> & mst_set, const int num_vertices){

	//Inicializando min como INF
	int min = std::numeric_limits<int>::max();
	int min_index;

	for (int i = 0; i < num_vertices; ++i)
	{
		if(mst_set[i] == false && key[i] < min){
			min = key[i];
			min_index = i;
		}	
	}

	return min_index;
}