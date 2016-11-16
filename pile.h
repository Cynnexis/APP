#ifndef __PILE_H__
#define __PILE_H__

#include "listes.h"

typedef List Pile;

int depiler(Pile* P);
int depiler_tete(Pile* P);
void empiler(Pile* P, int value);
void print_pile(Pile p);

#endif
