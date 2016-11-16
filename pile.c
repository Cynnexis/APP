#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pile.h"

int depiler(Pile* P) {
	int value;
	Cell *tail = list_tail(*P);
	if (tail != NULL)
	{
		value = tail->value;
		list_remove(P, list_length(*P) - 1);
		return value;
	}
	else
	{
		return -1;
	}
}

int depiler_tete(Pile* P) {
	int value;
	Cell* tete = P->head;
	if (tete != NULL)
	{
		value = tete->value;
		P->head = tete->next;
		free(tete);
		return value;
	}
	else
		return -1;
}

void empiler(Pile* P, int value) {
	list_add(P, value);
}

void empiler_tete(Pile* P, int value) {
	Cell* cell = malloc(sizeof(Cell));
	cell->value = value;
	cell->next = P->head;
	P->head = cell;
}

