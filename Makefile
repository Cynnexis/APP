CC=gcc
CFLAGS=-Wall -Werror -g
PROGRAM=main

all: $(PROGRAM)

main: main.o curiosity.o listes.o interprete.o pile.o
	$(CC) main.o curiosity.o listes.o interprete.o pile.o -o $@

main.o: main.c curiosity.h listes.h interprete.h
	$(CC) $(CFLAGS) -c $<

curiosity.o: curiosity.c curiosity.h
	$(CC) $(CFLAGS) -c $<

listes.o: listes.c listes.h boolean.h
	$(CC) $(CFLAGS) -c $<

interprete.o: interprete.c interprete.h pile.h curiosity.h
	$(CC) $(CFLAGS) -c $<

pile.o: pile.c pile.h listes.h
	$(CC) $(CFLAGS) -c $<

check: $(PROGRAM)
	./$(PROGRAM) tests/mars.map tests/mars.prog
	./$(PROGRAM) tests/1_simple.map tests/1_simple.prog
	./$(PROGRAM) tests/2_simple.map tests/2_simple.prog
	./$(PROGRAM) tests/3_simple.map tests/3_simple.prog
	./$(PROGRAM) tests/4_marque.map tests/4_marque.prog
	./$(PROGRAM) tests/5_marque.map tests/5_marque.prog
	./$(PROGRAM) tests/15_if.map tests/15_if.prog
	./$(PROGRAM) tests/16_if.map tests/16_if.prog

clean:
	rm -f *.o $(PROGRAM) 2> /dev/null
