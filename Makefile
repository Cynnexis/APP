CC=gcc

main: main.o curiosity.o listes.o interprete.o

clean:
	rm -f main *.o
