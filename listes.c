#include <stdio.h>
#include <stdlib.h>

#include "boolean.h"
#include "listes.h"

/*
 *  Auteur(s) : CERBA Guilhem - BERGER Valentin
 *  Date : 19/10/2016
 *  Suivi des Modifications :
 *
 */

void initList(List* l) {
	l->head = NULL;
}

int getLength(List l) {
	int length = 0;
	Cell* cell = l.head;
	
	while (cell != NULL)
	{
		length++;
		cell = cell->next;
	}
	return length;
}

Cell* getHead(List l) {
	return l.head;
}

Cell* getTail(List l) {
	if (l.head == NULL)
		return NULL;
	Cell* cell = l.head;
	while (cell->next != NULL)
		cell = cell->next;
	return cell;
}

Cell * getCell(List l, int index) {
	Cell* cell = l.head;
	int i;
	
	for (i = 0 ; i < index || cell != NULL ; i++)
		cell = cell->next;
	
	if (cell == NULL)
		return NULL;
	
	return cell;
}

int get(List l, int index) {
	int i;
	Cell* cell = l.head;
	
	for (i = 0 ; i < index || cell != NULL ; i++)
		cell = cell->next;
	
	if (cell == NULL)
		return 0;
	
	return cell->value;
}

void add(List* l, int value) {
	Cell* tail = getTail(*l);
	
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
bool addAt(List* l, int index, int value) {
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

bool delete(List* l, int index) {
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

bool set(List* l, int index, int value) {
	int i;
	Cell* cell = l->head;
	
	for (i = 0 ; i < index && cell != NULL ; i++)
		cell = cell->next;
	
	if (cell == NULL)
		return false;
	
	cell->value = value;
	return true;
	
}

bool belongs(List l, int value) {
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

void printList(List l) {
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

void freeList(List* l) {
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

