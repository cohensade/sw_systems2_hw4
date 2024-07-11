all: demo test

demo: main.o Complex.o
	g++ -std=c++11 -Wall -o demo main.o Complex.o -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp Tree.hpp HeapIterator.hpp Node.hpp
	g++ -std=c++11 -Wall -I/usr/include -c main.cpp

Complex.o: Complex.cpp Complex.hpp
	g++ -std=c++11 -Wall -I/usr/include -c Complex.cpp

test: test.o Complex.o
	g++ -std=c++11 -Wall -o test test.o Complex.o -lsfml-graphics -lsfml-window -lsfml-system

test.o: test.cpp Tree.hpp HeapIterator.hpp Node.hpp
	g++ -std=c++11 -Wall -I/usr/include -c test.cpp

clean:
	rm -f *.o demo test

valgrind: demo
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./demo

tree: demo
	./demo
