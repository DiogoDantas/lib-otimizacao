test:
	mkdir obj
	g++ src/*.cpp tests/test_maior_subs_comum.cpp -std=c++11 -O2 -o obj/test_msc.o
	g++ src/*.cpp tests/test_distancia_edicao.cpp -std=c++11 -O2 -o obj/test_dist_edi.o
	g++ src/*.cpp tests/test_multiplicacao_matrizes.cpp -std=c++11 -O2 -o obj/test_mult_mtx.o
	g++ src/*.cpp tests/test_mochila_fracionaria.cpp -std=c++11 -O2 -o obj/test_mochila_frac.o
	g++ src/*.cpp tests/test_soma_subconjunto.cpp -std=c++11 -O2 -o obj/test_ssp.o
	./obj/test_msc.o < inputs/input_maior_subs_comum.in
	./obj/test_mult_mtx.o < inputs/input_multiplicacao_matrizes.in
	./obj/test_dist_edi.o < inputs/input_distancia_edicao.in
	./obj/test_mochila_frac.o < inputs/input_mochila_fracionaria.in
	./obj/test_ssp.o < inputs/in_soma_subconjunto/001.in

clean:
	rm -fr obj
