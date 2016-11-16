#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "curiosity.h"
#include "interprete.h"

/*
 *  Auteur(s) : CERBA Guilhem - BERGER Valentin
 *  Date : 19/10/2016
 *  Suivi des Modifications :
 *
 */

void lecture(Pile commandes, Pile pile) {
	int i;
	char command;
	int length = list_length(commandes);
	
	printf("Interprétation...\n");
	for (i = 0 ; i < length ; i++)
	{
		// Affichage
		printf("------------------------------\n");
		printf("\033[1mStep n°%i:\033[0m\n", i);
		printf("\033[1mCommandes: \033[0m\n");list_print_as_char(commandes);printf("\n");
		printf("\033[1mPile: \033[0m\n");list_print(pile);printf("\n");
		afficherCarte();
		printf("------------------------------\n");
		
		command = (char) depiler_tete(&commandes);
		if (!execute_command(command, pile)) return;
		/*switch (command)
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
			case 'M':
				value = mesure(depiler(&pile));
				assert(value != -1);
				empiler(&pile, value);
				break;
			case 'P':
				value = depiler(&pile);
				assert(value != -1);
				break;
			case '?':
				F = (char)depiler(&pile);
				V = (char)depiler(&pile);
				n =  (int)depiler(&pile);
				if (n != 0)
				
				break;
			default:
				return;
		}*/
	}
	printf("Interprété.\n");
}

bool execute_command(char command, Pile pile) {
	int value;
	// Variables pour l'instruction conditionnelle :
	int n;
	char V, F;
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
		case 'M':
			value = mesure(depiler(&pile));
			assert(value != -1);
			empiler(&pile, value);
			break;
		case 'P':
			value = depiler(&pile);
			assert(value != -1);
			break;
		case '?':
			F = (char)depiler(&pile);
			V = (char)depiler(&pile);
			n =  (int)depiler(&pile);
			if (n != 0)
				execute_command(V, pile);
			else
				execute_command(F, pile);
			break;
		default:
			return false;
	}
	printf("\033[36;1mJ'execute %c.\033[0m\n", command);
	return true;
}
