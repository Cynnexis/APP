#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pile.h"

int depiler(Pile P) {
	int value;
	Cell *tail = list_tail(P);
	value = tail->value;
	list_remove(&P, list_length(P) - 1);
	return value;
}

void empiler(Pile P, int value) {
	list_add(&P, value);
}

