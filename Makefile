testG4:
	mkdir obj
	g++ src/graph_coloring.cpp tests/test_graph_coloring.cpp -std=c++11 -O2 -o obj/test_color_graf.o
	./obj/test_color_graf.o < inputs/input_graph_coloring.in

testD6:
	mkdir obj
	g++ src/edit_distance.cpp tests/test_edit_distance.cpp -std=c++11 -O2 -o obj/test_dist_edi.o
	./obj/test_dist_edi.o < inputs/input_edit_distance.in

test:
	mkdir obj
	g++ src/*.cpp tests/test_maior_subs_comum.cpp -std=c++11 -O2 -o obj/test_msc.o
	g++ src/*.cpp tests/test_multiplicacao_matrizes.cpp -std=c++11 -O2 -o obj/test_mult_mtx.o
	g++ src/*.cpp tests/test_mochila_fracionaria.cpp -std=c++11 -O2 -o obj/test_mochila_frac.o
	g++ src/*.cpp tests/test_soma_subconjunto.cpp -std=c++11 -O2 -o obj/test_ssp.o
	g++ src/*.cpp tests/test_mochila_binaria.cpp -std=c++11 -O2 -o obj/test_mhbin.o
	g++ src/*.cpp tests/test_quebra_palavras.cpp -std=c++11 -O2 -o obj/test_quebra_palavras.o
	g++ src/*.cpp tests/test_dijkstra.cpp -std=c++11 -O2 -o obj/test_dijkstra.o
	g++ src/*.cpp tests/test_prim.cpp -std=c++11 -O2 -o obj/test_prim.o

	./obj/test_msc.o < inputs/input_maior_subs_comum.in
	./obj/test_mult_mtx.o < inputs/input_multiplicacao_matrizes.in
	./obj/test_mochila_frac.o < inputs/input_mochila_fracionaria.in
	./obj/test_ssp.o < inputs/in_soma_subconjunto/001.in
	./obj/test_mhbin.o < inputs/in_mochila_binaria/001.in
	./obj/test_quebra_palavras.o < inputs/in_quebra_palavras/input_quebra_palavras.in
	./obj/test_dijkstra.o < inputs/in_dijkstra/input_dijkstra.in
	./obj/test_prim.o < inputs/input_prim.in

clean:
	rm -fr obj
