mkdir:
	mkdir obj

testD1: mkdir
	g++ src/subset_sum.cpp tests/test_subset_sum.cpp -std=c++11 -O2 -o obj/test_ssp.o
	./obj/test_ssp.o < inputs/in_subset_sum/001.in

testD2: mkdir
	g++ src/knapsack.cpp tests/test_knapsack.cpp -std=c++11 -O2 -o obj/test_knapsack.o
	./obj/test_knapsack.o < inputs/in_knapsack/001.in

testD3: mkdir
	g++ src/word_break.cpp tests/test_word_break.cpp -std=c++11 -O2 -o obj/test_word_break.o
	./obj/test_word_break.o < inputs/in_word_break/input_word_break.in

testD4: mkdir
	g++ src/lcs.cpp tests/test_lcs.cpp -std=c++11 -O2 -o obj/test_lcs.o
	./obj/test_lcs.o < inputs/input_lcs.in

testD5: mkdir
	g++ src/matrix_chain_mult.cpp tests/test_matrix_chain_mult.cpp -std=c++11 -O2 -o obj/test_matrix_chain_mult.o
	./obj/test_matrix_chain_mult.o < inputs/input_matrix_chain_mult.in

testD6:mkdir
	g++ src/edit_distance.cpp tests/test_edit_distance.cpp -std=c++11 -O2 -o obj/test_dist_edi.o
	./obj/test_dist_edi.o < inputs/input_edit_distance.in

testG4: mkdir
	g++ src/graph_coloring.cpp tests/test_graph_coloring.cpp -std=c++11 -O2 -o obj/test_color_graf.o
	./obj/test_color_graf.o < inputs/input_graph_coloring.in

all: testD1 testD2 testD3 testD4 testD5 testD6 testD7 testD8 testD9 testG1 testG2 testG3 testG4 testG5 testG6 testG7 testG8
	mkdir obj
	g++ src/*.cpp tests/test_multiplicacao_matrizes.cpp -std=c++11 -O2 -o obj/test_mult_mtx.o
	g++ src/*.cpp tests/test_mochila_fracionaria.cpp -std=c++11 -O2 -o obj/test_mochila_frac.o
	g++ src/*.cpp tests/test_dijkstra.cpp -std=c++11 -O2 -o obj/test_dijkstra.o
	g++ src/*.cpp tests/test_prim.cpp -std=c++11 -O2 -o obj/test_prim.o

	./obj/test_mult_mtx.o < inputs/input_multiplicacao_matrizes.in
	./obj/test_mochila_frac.o < inputs/input_mochila_fracionaria.in
	./obj/test_dijkstra.o < inputs/in_dijkstra/input_dijkstra.in
	./obj/test_prim.o < inputs/input_prim.in

dynamic: mkdir testD4 testD6

greedy: mkdir testG4

clean:
	rm -fr obj
