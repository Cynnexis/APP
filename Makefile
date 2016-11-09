CC=gcc

main: main.o curiosity.o listes.o interprete.o pile.o

clean:
	rm -f main *.o
