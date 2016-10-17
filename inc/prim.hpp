#ifndef PRIM_HPP
#define PRIM_HPP

#include <iostream>
#include <vector>
#include <limits>

namespace greedy{

	/**
	 * @brief      { Função que encontra o vertex com a menor chave no conjunto de vertices
	 *             	 que ainda não estão na MST}
	 *
	 * @param[in]  parent        Vetor que representa a MST
	 * @param[in]  num_vertices  Número de vertices
	 * @param      graph         Grafo
	 *
	 * @tparam     BDArray       { Vetor bidimensional que representa o grafo}
	 */
	int min_key(std::vector<int> & key, std::vector<bool> & mst_set, const int num_vertices);

	/**
	 * @brief      { Função utilizada para imprimir a MST construida na vetor parent }
	 *
	 * @param[in]  parent        Vetor que representa a MST
	 * @param[in]  num_vertices  Número de vertices
	 * @param      graph         Grafo
	 *
	 * @tparam     BDArray       { Vetor bidimensional que representa o grafo }
	 */
	template<typename BDArray>
	void print_mst(std::vector<int> parent, const int num_vertices, BDArray & graph ){
		std::cout << "Edge" << "\t" << "Weight" << std::endl;
		for (int i = 1; i < num_vertices; ++i)
		{
			std::cout << parent[i] << "\t" << i << "\t" << graph[i][parent[i]] << std::endl;
		}
	}

	/**
	 * @brief      { Função que constroi a MST e utilizando um grafo representado em uma matriz de adjacência }
	 *
	 * @param      graph         Grafo
	 * @param[in]  num_vertices  Número de vertices
	 *
	 * @tparam     BDArray       { Vetor bidimensional que representa o grafo }
	 */
	template<typename BDArray>
	void MST_prim(BDArray & graph, const int num_vertices){
		
		std::vector<int> parent(num_vertices); // Vetor que armazena a MST
		std::vector<int> key(num_vertices); // Vetor que armazena os pesos dos vertices
		std::vector<bool> mst_set(num_vertices); //Conjunto que armazena os vertices que ainda não estão na MST

		/**
		 * Inicializando o vetor keys com INF e marcando que os vertice como não inclusos na MST
		 */
		for (int i = 0; i < num_vertices; ++i){
			key[i] = std::numeric_limits<int>::max();
			mst_set[i] = false;
		}

		/**
		 * O primeiro vertice sempre é adicionado a MST
		 */
		key[0] = 0; // seu peso é marcado como zero, dessa forma a função min ira adicioná-lo a MST
		parent[0] = -1; // o primeiro nó e utilizado, sempre, como a raiz da MST

		for (int i = 0; i < num_vertices - 1 ; ++i)
		{
			//Selecionando o vertice com o menor peso do conjunto de vertices que ainda não foram adicionados a MST
			int u = min_key(key, mst_set, num_vertices);

			//Adicionado o vertice selecionado a MST
			mst_set[u] = true;

			/**
			 * Atualizando o pesos dos vertices adjacentes ao vertice selecionado
			 */
			for (int v = 0; v < num_vertices; ++v)
			{
				/**
				 * graph[u][v] só não é zero para vertices adjacentes 
				 * mst_set[v] é falso para vertices que ainda não estão adicionados na MST
				 * o peso dos vertices só é atualizado se graph[u][v] < key[v]
				 */
				if (graph[u][v] && mst_set[v] == false && graph[u][v] <  key[v]){
             		parent[v]  = u;
             		key[v] = graph[u][v];
				}
			}
		}
		
		//Exibe a MST construida
		print_mst(parent, num_vertices, graph);
	}
}


#endif // PRIM_HPP