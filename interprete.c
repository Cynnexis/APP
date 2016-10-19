#include <stdio.h>
#include <stdlib.h>
#include "curiosity.h"
#include "interprete.h"

/*
 *  Auteur(s) : CERBA Guilhem - BERGER Valentin
 *  Date : 19/10/2016
 *  Suivi des Modifications :
 *
 */

void lecture(List l_commandes, List l_pile) {
	int i;
	char command;
	
	printf("Interprétation...\n");
	for (i = 0 ; i < getLength(l_commandes) ; i++)
	{
		command = (char)get(l_commandes, i);
		//afficherCarte();
		switch (command)
		{
			case 'A':
				avance();
				break;
			case 'G':
				gauche();
				break;
			case 'D':
				droite();
				break;
			default:
				break;
		}
	}
}
