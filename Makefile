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

testD7:mkdir
	g++ src/coin_change.cpp tests/test_coin_change.cpp -std=c++11 -O2 -o obj/test_coin_change.o
	./obj/test_coin_change.o < inputs/in_coin_change/001.in

testD8:mkdir
	g++ src/binomial_coefficient.cpp tests/binomial_coefficient.cpp -std=c++11 -O2 -o obj/binomial_coefficient.o
	./obj/binomial_coefficient.o < inputs/binomial_coefficient/001.in

testD9:mkdir
	g++ src/box_stacking.cpp tests/box_stacking.cpp -std=c++11 -O2 -o obj/box_stacking.o
	./obj/box_stacking.o < inputs/box_stacking/001.in

testG4: mkdir
	g++ src/graph_coloring.cpp tests/test_graph_coloring.cpp -std=c++11 -O2 -o obj/test_color_graf.o
	./obj/test_color_graf.o < inputs/input_graph_coloring.in

all: dynamic greedy
#	mkdir obj

#	g++ src/*.cpp tests/test_mochila_fracionaria.cpp -std=c++11 -O2 -o obj/test_mochila_frac.o
#	g++ src/*.cpp tests/test_dijkstra.cpp -std=c++11 -O2 -o obj/test_dijkstra.o
#	g++ src/*.cpp tests/test_prim.cpp -std=c++11 -O2 -o obj/test_prim.o

#	./obj/test_mochila_frac.o < inputs/input_mochila_fracionaria.in
#	./obj/test_dijkstra.o < inputs/in_dijkstra/input_dijkstra.in
#	./obj/test_prim.o < inputs/input_prim.in

dynamic: testD1 testD2 testD3 testD4 testD5 testD6 testD7 testD8 testD9

greedy: testG1 testG2 testG3 testG4 testG5 testG6

clean:
	rm -fr obj
