#include "../inc/prim.hpp"

int main(int argc, char const *argv[])
{
	int T = 0;

    std::cin >> T;

    while(T) {
        
        int num_vertices = 0;

        std::cin >> num_vertices;

        std::vector< std::vector<int> > graph(num_vertices, std::vector<int>(num_vertices));

        for (int i = 0; i < num_vertices; ++i)
        {
        	for (int j = 0; j < num_vertices; ++j)
        	{
        		int tmp = 0;

        		std::cin >> tmp;

        		graph[i][j]  = tmp;
        	}
        }

    	greedy::MST_prim(graph,num_vertices);

    	T--;
    }

	return 0;
}