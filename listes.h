#ifndef __LIST_H__
#define __LIST_H__

#include "boolean.h"

typedef struct Cell {
	int value;
	struct Cell* next;
} Cell;

typedef struct {
	Cell* head;
} List;

void initList(List* l);
int getLength(List l);
Cell* getHead(List l);
Cell* getTail(List l);
Cell* getCell(List l, int index);
int get(List l, int index);
void add(List* l, int value);
bool addAt(List* l, int index, int value);
bool delete(List* l, int index);
bool set(List* l, int index, int value);
bool belongs(List l, int value);
void printList(List l);
void freeList(List* l);

#endif

