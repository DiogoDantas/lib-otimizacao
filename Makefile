test:
	g++ src/*.cpp tests/test_maior_subs_comum.cpp -std=c++11 -O2 -o test_msc
	cd tests
	./test_msc < inputs/input_maior_subs_comum.in
	g++ src/*.cpp tests/test_multiplicacao_matrizes.cpp -std=c++11 -O2 -o test_mult_mtx
	cd tests
	./test_mult_mtx < inputs/input_multiplicacao_matrizes.in
	g++ src/*.cpp tests/test_triangulo_pascal.cpp -std=c++11 -O2 -o test_tri_pasc
	cd tests
	./test_tri_pasc < inputs/input_triangulo_pascal.in