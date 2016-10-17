/**
 * @name  Diogo Dantas
 * @date  15-10-2016  
 */

#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include <limits>
#include <iostream>

 namespace  greedy{

 	/**
 	 * @brief      { Função que encontra o vertice com a menor distância que ainda não está adicionado
 	 *             	 a árvore do menor caminho (SPT) }
 	 *
 	 * @param      dist_vector   Vetor que armazena a menor distância do vertice inicial a os n outros vertices
 	 * @param[in]  spt_set       Vetor que armazena os vertices estão na árvore do menor caminho (SPT)
 	 * @param[in]  num_vertices  Número de vertices
 	 *
 	 */
 	int min_distance(std::vector<int> & dist_vector, std::vector<bool> & spt_set, const int num_vertices);
 	
 	/**
 	 * @brief      { Função que exibe o vetor de distâncias }
 	 *
 	 * @param      dist_vector      Vetor que armazena a menor distância do vertice inicial a os n outros vertices
   	 * @param[in]  num_vertices  	Número de vertices
 	 *
 	 */
 	void print_solution(std::vector<int> & dist_vector, const int num_vertices);

 	/**
 	 * @brief      { Função que implementa o clássico algoritmo de Dijkstra utilizado 
 	 *             	 para encontrar o menor caminho a partir de um único vertice inicial
 	 *             	 em um grafo representado como uma matriz de adjacência }
 	 *
 	 * @param      graph         Grafo
 	 * @param[in]  src           Vertice inicial
 	 * @param[in]  num_vertices  Número de vertices
 	 *
 	 * @tparam     BDArray       { description }
 	 */
 	template<typename BDArray>
 	void dijkstra(BDArray & graph, int src, const int num_vertices){

 		auto int_max = std::numeric_limits<int>::max();
 		
 		/**
 		 * Vetor que vai armazenar as menores distâncias do vertice inicial até
 		 * dist_vector[i]
 		 */
 		std::vector<int> dist_vector(num_vertices);

 		/**
 		 * Vetor que vai armazenar os vertices que que estão na SPT
 		 */
 		std::vector<bool> spt_set(num_vertices);

 		//Inicializando todas as distâncias como INF e marcando os vertices como não inclusos na SPT
 		for (int i = 0; i < num_vertices; ++i)
 		{
 			dist_vector[i] = std::numeric_limits<int>::max();
 			spt_set[i] = false;
 		}

 		//A distância do vertice inicial para ele mesmo é zero
 		dist_vector[src] = 0;

 		//Encontrado o menor caminho para todos os vertices
 		for (int i = 0; i < num_vertices - 1; ++i)
 		{
 			//Selecionado o vertice, que possui a menor distância, do conjunto de vertices ainda não adicionados a SPT 
 			int min_dist = greedy::min_distance(dist_vector, spt_set, num_vertices);
 			//Marcando o vertice selecionado como processado
 			spt_set[min_dist] = true;

 			/**
 			 * O dist_vector[j] só é atualizado se ele ainda não estiver na SPT
 			 * Deve existir uma aresta de u para j (graph[u][j])
 			 * A distância total do vertice inicial para v, passando por u deve ser menor que o valor atual de dist_vector[j]
 			 */
 			for (int j = 0; j < num_vertices; ++j)
 			{
 				if (!spt_set[j] && graph[min_dist][j] && dist_vector[min_dist] != int_max 
 					&& dist_vector[min_dist] + graph[min_dist][j] < dist_vector[j]){
 					dist_vector[j] = dist_vector[min_dist] + graph[min_dist][j];
 			}

 		}
 	}

 	//Exibe o vetor de distâncias 
 	greedy::print_solution(dist_vector, num_vertices);
 }

}

#endif // DIJKSTRA_HPP


