# compiler
CC = g++
# flags
FLAGS = -O2 -g3 -std=c++11

mkdir:
	mkdir -p obj

#TESTS FOR DYNAMIC PROBLEMS#

testD1: mkdir
	$(CC) src/subset_sum.cpp tests/test_subset_sum.cpp $(FLAGS) -o obj/test_ssp.o
	./obj/test_ssp.o < inputs/in_subset_sum/001.in

testD2: mkdir
	$(CC) src/knapsack.cpp tests/test_knapsack.cpp $(FLAGS) -o obj/test_knapsack.o
	./obj/test_knapsack.o < inputs/in_knapsack/001.in

testD3: mkdir
	$(CC) src/word_break.cpp tests/test_word_break.cpp $(FLAGS) -o obj/test_word_break.o
	./obj/test_word_break.o < inputs/in_word_break/input_word_break.in

testD4: mkdir
	$(CC) src/lcs.cpp tests/test_lcs.cpp $(FLAGS) -o obj/test_lcs.o
	./obj/test_lcs.o < inputs/input_lcs.in

testD5: mkdir
	$(CC) src/matrix_chain_mult.cpp tests/test_matrix_chain_mult.cpp $(FLAGS) -o obj/test_matrix_chain_mult.o
	./obj/test_matrix_chain_mult.o < inputs/input_matrix_chain_mult.in

testD6:mkdir
	$(CC) src/edit_distance.cpp tests/test_edit_distance.cpp $(FLAGS) -o obj/test_dist_edi.o
	./obj/test_dist_edi.o < inputs/input_edit_distance.in

testD7:mkdir
	$(CC) src/coin_change.cpp tests/test_coin_change.cpp $(FLAGS) -o obj/test_coin_change.o
	./obj/test_coin_change.o < inputs/in_coin_change/001.in

testD8:mkdir
	$(CC) src/binomial_coefficient.cpp tests/test_binomial_coefficient.cpp $(FLAGS) -o obj/test_bino.o
	./obj/test_bino.o < inputs/in_binomial_coefficient/001.in

testD9:mkdir
	$(CC) src/box_stacking.cpp tests/test_box_stacking.cpp $(FLAGS) -o obj/test_box_stacking.o
	./obj/test_box_stacking.o < inputs/in_box_stacking/001.in

#TESTS FOR GREEDY ALGORITHMS PROBLEMS#

testG1: mkdir
	$(CC) src/dijkstra.cpp tests/test_dijkstra.cpp $(FLAGS) -o obj/test_dijkstra.o
	./obj/test_dijkstra.o < inputs/in_dijkstra/input_dijkstra.in

testG2: mkdir
	$(CC) src/prim.cpp tests/test_prim.cpp $(FLAGS) -o obj/test_prim.o
	./obj/test_prim.o < inputs/in_prim/input_prim.in

testG3: mkdir
	$(CC) src/fractional_knapsack.cpp tests/test_fractional_knapsack.cpp $(FLAGS) -o obj/test_fractional_knapsack.o
	./obj/test_fractional_knapsack.o < inputs/input_fractional_knapsack.in

testG4: mkdir
	$(CC) src/graph_coloring.cpp tests/test_graph_coloring.cpp $(FLAGS) -o obj/test_color_graf.o
	./obj/test_color_graf.o < inputs/input_graph_coloring.in

testG5: mkdir
	$(CC) src/huffman.cpp tests/test_huffman.cpp $(FLAGS) -o obj/test_huffman.o
	./obj/test_huffman.o < inputs/in_huffman/001.in

testG6: mkdir
	$(CC) src/activity_selection.cpp tests/test_activity_selection.cpp $(FLAGS) -o obj/test_activity_selection.o
	./obj/test_activity_selection.o < inputs/in_activity_selection/001.in

all: dynamic greedy

dynamic: testD1 testD2 testD3 testD4 testD5 testD6 testD7 testD8 testD9

greedy: testG1 testG2 testG3 testG4 testG5 testG6

.PHONY: clean

clean:
	rm -fr obj
