#ifndef __INTERPRETE_H__
#define __INTERPRETE_H__

#include "pile.h"

#define AVANCE 65
#define GAUCHE 71
#define DROITE 68

void lecture(Pile commandes, Pile pile);
bool execute_command(char command, Pile pile);

#endif
