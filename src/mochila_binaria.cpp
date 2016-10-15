/**
 * @author     Diogo Dantas
 * @date       14-10-2016
 */

#include "../inc/mochila_binaria.hpp"
#include <algorithm> 

int dinamica::mochila_binaria(const int weight, std::vector<int> & weight_vector, std::vector<int> & values_vector, const int num_itens)
{
   int i, w;
   int K[num_itens+1][weight+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= num_itens; i++)
   {
       for (w = 0; w <= weight; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (weight_vector[i-1] <= w)
                 K[i][w] = std::max(values_vector[i-1] + K[i-1][w-weight_vector[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[num_itens][weight];
}