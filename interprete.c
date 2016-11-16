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

void execute(Pile commandes, Pile pile) {
	int i;
	char command;
	int length = list_length(commandes);
	
	printf("Interprétation...\n");
	for (i = 0 ; i < length ; i++)
	{
		// Affichage
		printf("------------------------------\n");
		printf("\033[1mStep n°%i:\033[0m\n", i);
		printf("\033[1mCommandes: \033[0m\n");print_pile(commandes);printf("\n");
		printf("\033[1mPile: \033[0m\n");print_pile(pile);printf("\n");
		afficherCarte();
		printf("------------------------------\n");
		
		command = (char) depiler_tete(&commandes);
		/* Si c'est un chiffre ou une instruction conditionnelle, on stack dans
		   la pile. On n'ajoute pas les accolades dans la pile, et on remplace
		   les instructions vides par le caractère '.' */
		if (command >= 0 && command <= 9)
		{
			empiler(&pile, (int)command);
		}
		else if (((char)command) == '{')
		{
			// On récupère V
			command = (char) depiler_tete(&commandes);
			empiler(&pile, command);
			// On récupère }
			command = (char) depiler_tete(&commandes);
			// On récupère {
			command = (char) depiler_tete(&commandes);
			// On récupère F
			command = (char) depiler_tete(&commandes);
			// Si F est vide
			if (command == '}')
			{
				empiler(&pile, (int)'.');
			}
			else
			{
				empiler(&pile, (int)command);
				// On récupère }
				command = (char) depiler_tete(&commandes);
			}
		}
		else
		{
			if (!execute_command(command, &pile)) return;
		}
	}
	printf("Interprété.\n");
}

bool execute_command(char command, Pile* pile) {
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
			n = depiler(pile);
			value = mesure(n);
			printf("M(%i) = %i\n", n, value);
			assert(value != -1);
			empiler(pile, value);
			break;
		case 'P':
			value = depiler(pile);
			assert(value != -1);
			break;
		case '?':
			F = (char)depiler(pile);
			V = (char)depiler(pile);
			n =  (int)depiler(pile);
			if (n != 0)
				execute_command(V, pile);
			else
				execute_command(F, pile);
			break;
		case '.':
			break;
		default:
			return false;
	}
	return true;
}

