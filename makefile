all:
	g++ -c giveme.cpp -o giveme.o
	g++ giveme.o -o giveme
	rm giveme.o

clean:
	rm giveme