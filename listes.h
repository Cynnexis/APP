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

/* The keyword 'extern' stands for 'public function'. I use it to export these
 * functions as library. If you compiled this program by using 'make' (from the
 * Makefile in this directory/project), you can see the file 'liblist.a', which
 * is the static library of list.c
 * In other words, don't mind this keyword. It won't change the source code
 * if I wouldn't create a library.
 * Note: You can compile list.c and list.h as a normal C file, 'extern' won't
 * interfer with gcc.
 */

/** CONSTRUCTOR **/
extern void list_new(List* l);

/** DESTRUCTOR **/
extern void list_delete(List* l);

/** ACCESSORS **/
extern int list_length(List l);
extern Cell* list_head(List l);
extern Cell* list_tail(List l);
extern Cell* list_getCell(List l, int index);
extern int list_get(List l, int index);
extern bool list_contains(List l, int value);

/** MUTATORS **/
extern void list_add(List* l, int value);
extern bool list_addAt(List* l, int index, int value);
extern bool list_remove(List* l, int index);
extern bool list_removeAll(List* l);
extern bool list_set(List* l, int index, int value);

/** OTHERS **/
extern int* listToArray(List l);
extern void listFromArray(List* l, int* array, int n);
extern void list_sort(List *l);
extern void list_print(List l);
extern void list_print_as_char(List l);

#endif
