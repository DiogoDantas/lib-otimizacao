test:
	g++ tests/test_maior_subs_comum.cpp -03 -o test_msc
	./tests/test_msc < inputs/input_maior_subs_comum.in
