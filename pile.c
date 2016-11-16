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

void print_pile(Pile p) {
	Cell* cell = p.head;
	
	if (p.head != NULL)
	{
		printf("[");
		while (cell->next != NULL)
		{
			if (cell->value >= 0 && cell->value <= 9)
				printf("%i, ", cell->value);
			else if (((char)cell->value) == '{')
			{
				// {
				printf("%c", cell->value);
				// V
				cell = cell->next;
				printf("%c", cell->value);
				// }
				cell = cell->next;
				printf("%c", cell->value);
				// {
				cell = cell->next;
				printf("%c", cell->value);
				// F or }
				cell = cell->next;
				if (cell->value == '}')
					printf("%c, ", cell->value);
				else
				{
					// F
					printf("%c", cell->value);
					// }
					cell = cell->next;
					printf("%c, ", cell->value);
				}
			}
			else
				printf("%c, ", cell->value);
			cell = cell->next;
		}
		if (cell->value >= 0 && cell->value <= 9)
			printf("%i]", cell->value);
		else
			printf("%c]", cell->value);
	}
	else
	{
		printf("[]");
	}
}

