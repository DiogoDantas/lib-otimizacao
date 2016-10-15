test:
	mkdir obj
	g++ src/*.cpp tests/test_maior_subs_comum.cpp -std=c++11 -O2 -o obj/test_msc.o
	g++ src/*.cpp tests/test_distancia_edicao.cpp -std=c++11 -O2 -o obj/test_dist_edi.o
	g++ src/*.cpp tests/test_multiplicacao_matrizes.cpp -std=c++11 -O2 -o obj/test_mult_mtx.o
	g++ src/*.cpp tests/test_mochila_fracionaria.cpp -std=c++11 -O2 -o obj/test_mochila_frac.o
	g++ src/*.cpp tests/test_soma_subconjunto.cpp -std=c++11 -O2 -o obj/test_ssp.o
	g++ src/*.cpp tests/test_mochila_binaria.cpp -std=c++11 -O2 -o obj/test_mhbin.o
	g++ src/*.cpp tests/test_coloracao_grafos.cpp -std=c++11 -O2 -o obj/test_color_graf.o
	g++ src/*.cpp tests/test_quebra_palavras.cpp -std=c++11 -O2 -o obj/test_quebra_palavras.o

	./obj/test_msc.o < inputs/input_maior_subs_comum.in
	./obj/test_mult_mtx.o < inputs/input_multiplicacao_matrizes.in
	./obj/test_dist_edi.o < inputs/input_distancia_edicao.in
	./obj/test_mochila_frac.o < inputs/input_mochila_fracionaria.in
	./obj/test_ssp.o < inputs/in_soma_subconjunto/001.in
	./obj/test_mhbin.o < inputs/in_mochila_binaria/001.in
	./obj/test_color_graf.o < inputs/input_coloracao_grafos.in
	./obj/test_quebra_palavras.o < inputs/in_quebra_palavras/input_quebra_palavras.in

clean:
	rm -fr obj
