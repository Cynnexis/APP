#include <stdio.h>
#include <stdlib.h>

#include "listes.h"

/** CONSTRUCTOR **/
void list_new(List* l) {
	l->head = NULL;
}

/** DESTRUCTOR **/
void list_delete(List* l) {
	Cell* head = l->head;
	Cell* tmp;

	if (head != NULL)
	{
		tmp = head;
		head = head->next;
		tmp->next = NULL;
		free(tmp);
	}
	l->head = NULL;
}

/** ACCESSORS **/
int list_length(List l) {
	int length = 0;
	Cell* cell = l.head;
	
	while (cell != NULL)
	{
		length++;
		cell = cell->next;
	}
	return length;
}

Cell* list_head(List l) {
	return l.head;
}

Cell* list_tail(List l) {
	if (l.head == NULL)
		return NULL;
	Cell* cell = l.head;
	while (cell->next != NULL)
		cell = cell->next;
	return cell;
}

Cell * list_getCell(List l, int index) {
	Cell* cell = l.head;
	int i;
	
	for (i = 0 ; i < index && cell != NULL ; i++)
		cell = cell->next;
	
	if (cell == NULL)
		return NULL;
	
	return cell;
}

int list_get(List l, int index) {
	int i;
	Cell* cell = l.head;
	
	for (i = 0 ; i < index && cell != NULL ; i++)
		cell = cell->next;
	
	if (cell == NULL)
		return 0;
	
	return cell->value;
}

bool list_contains(List l, int value) {
	Cell* cell = l.head;
	bool result = false;
	
	if (cell == NULL)
		return false;
	
	while (cell != NULL && result == false)
	{
		result = (cell->value == value);
		cell = cell->next;
	}
	
	return result;
}

/** MUTATORS **/
void list_add(List* l, int value) {
	Cell* tail = list_tail(*l);
	
	if (tail != NULL)
	{
		Cell* new = malloc(sizeof(Cell));
		new->value = value;
		new->next = NULL;
		tail->next = new;
	}
	else // if tail is the head (first element):
	{
		tail = malloc(sizeof(Cell));
		tail->value = value;
		tail->next = NULL;
		l->head = tail;
	}
}
bool list_addAt(List* l, int index, int value) {
	int i;
	Cell* cell = l->head;
	Cell* new = malloc(sizeof(Cell));
	new->value = value;
	
	for (i = 0 ; i < index && cell != NULL ; i++)
		cell = cell->next;
	
	if (cell == NULL)
		return false;
	
	new->next = cell->next;
	cell->next = new;
	return true;
}

bool list_remove(List* l, int index) {
	int i;
	Cell* cell1 = l->head;
	Cell* cell2 = NULL;
	
	if (cell1 == NULL)
		return false;
	
	if (index == 0)
	{
		l->head = l->head->next;
		return true;
	}
	
	for (i = 0 ; i < index && cell1 != NULL ; i++)
	{
		cell2 = cell1;
		cell1 = cell1->next;
	}
	
	if (cell1 == NULL)
		return false;
	
	
	cell2->next = cell1->next;
	
	return true;
}

bool list_removeAll(List* l) {
	list_delete(l);
	list_new(l);
}

bool list_set(List* l, int index, int value) {
	int i;
	Cell* cell = l->head;
	
	for (i = 0 ; i < index && cell != NULL ; i++)
		cell = cell->next;
	
	if (cell == NULL)
		return false;
	
	cell->value = value;
	return true;
}

/** OTHERS **/
int* listToArray(List l) {
	int i;
	Cell* cell = l.head;
	int* array;
	
	if (cell == NULL)
		array = NULL;
	else
	{
		array = malloc(sizeof(int) * list_length(l));
		
		for (i = 0 ; cell != NULL ; i++)
		{
			array[i] = cell->value;
			cell = cell->next;
		}
	}
	return array;
}

void listFromArray(List* l, int* array, int length) {
	int i;
	
	list_removeAll(l);
	
	for (i = 0 ; i < length ; i++)
		list_add(l, array[i]);
}

// WARNING: Insertion Sort: There is probably a better way to sort a linked list
void list_sort(List *l) {
	int i, j, ind_min, length = list_length(*l), tmp;
	
	for (i = 0 ; i < length-1 ; i++)
	{
		ind_min = i;
		for (j = i+1 ; j < length ; j++)
			if (list_get(*l, j) < list_get(*l, ind_min))
				ind_min = j;
		
		if (i != ind_min)
		{
			tmp = list_get(*l, ind_min);
			list_set(l, ind_min, list_get(*l, i));
			list_set(l, i, tmp);
		}
	}
}

void list_print(List l) {
	Cell* cell = l.head;
	
	if (l.head != NULL)
	{
		printf("[");
		while (cell->next != NULL)
		{
			printf("%i, ", cell->value);
			cell = cell->next;
		}
		printf("%i]", cell->value);
	}
	else
	{
		printf("[]");
	}
}

void list_print_as_char(List l) {
	Cell* cell = l.head;
	
	if (l.head != NULL)
	{
		printf("[");
		while (cell->next != NULL)
		{
			printf("%c, ", (char) cell->value);
			cell = cell->next;
		}
		printf("%c]", (char) cell->value);
	}
	else
	{
		printf("[]");
	}
}

