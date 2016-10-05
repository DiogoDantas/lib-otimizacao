test:
	g++ src/*.cpp tests/test_maior_subs_comum.cpp -O2 -o test_msc
	cd tests
	./test_msc < inputs/input_maior_subs_comum.in
	
