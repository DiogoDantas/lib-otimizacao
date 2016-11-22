#include "parser.hpp"
#include "cvrp.hpp"

namespace sorting{

	/**
	 * @name 			quickSort
	 * @parameter 		std::vector<T> &, const int begin, const int end
	 * @return 			void
	 *
	 * @author 			Diogo Dantas
	 *
	 * Implementation of classic sort algorithm called quick sort.
	 * The pivot is always chosen as the last element of the vector.
	 */

	void quickSort(std::vector<CVRP::Truck> &unordered_vector ,const int begin, const int end, CVRP::Instance &instance, int node)
	{
		int pivot = end;

		int i = begin;
		int j = end-1;

		while(true){
			while(instance.distance_matrix[unordered_vector.at(i).route.back()][node] <= instance.distance_matrix[unordered_vector.at(pivot).route.back()][node] && i < end)
				i++;

			while(instance.distance_matrix[unordered_vector.at(j).route.back()][node] > instance.distance_matrix[unordered_vector.at(pivot).route.back()][node] && j >= begin)
				j--;

			if(i < j){
				std::swap(unordered_vector.at(j), unordered_vector.at(i));
			}
			else{
				std::swap(unordered_vector.at(pivot), unordered_vector.at(i));
				break;
			}
		}

		if(begin < i-1)
			quickSort(unordered_vector, begin, i-1, instance, node);
		if(i+1 < end)
			quickSort(unordered_vector, i+1, end, instance, node);
	}
}
