/**
 * @name  Diogo Dantas
 * @date  15-10-2016  
 */

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include <limits>
#include <iostream>

 namespace  greed{

 	int min_distance(std::vector<int> & dist_vector, std::vector<bool> & spt_set, const int num_vertices);
 	void print_solution(std::vector<int> & dist_vector, const int num_vertices);

 	template<typename BDArray>
 	void dijkstra(BDArray & graph, int src, const int num_vertices){

 		auto int_max = std::numeric_limits<int>::max();
 		std::vector<int> dist_vector(num_vertices);

 		std::vector<bool> spt_set(num_vertices);

 		for (int i = 0; i < num_vertices; ++i)
 		{
 			dist_vector[i] = std::numeric_limits<int>::max();
 			spt_set[i] = false;
 		}

 		dist_vector[src] = 0;

 		for (int i = 0; i < num_vertices - 1; ++i)
 		{
 			int min_dist = greed::min_distance(dist_vector, spt_set, num_vertices);
 			spt_set[min_dist] = true;

 			for (int j = 0; j < num_vertices; ++j)
 			{
 				if (!spt_set[j] && graph[min_dist][j] && dist_vector[min_dist] != int_max 
 					&& dist_vector[min_dist] + graph[min_dist][j] < dist_vector[j]){
 					dist_vector[j] = dist_vector[min_dist] + graph[min_dist][j];
 			}

 		}
 	}

 	greed::print_solution(dist_vector, num_vertices);
 }

}

#endif // DIJKSTRA_HPP


