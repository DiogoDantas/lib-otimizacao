all:
	g++ /inc -c src/*.cpp -o obj/*.o
	ar rcs lib/*.a obj/*.o
