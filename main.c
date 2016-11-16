#include <stdio.h>
#include <stdlib.h>
#include "curiosity.h"
#include "listes.h"
#include "interprete.h"

/*
 *	Auteur(s) : CERBA Guilhem - BERGER Valentin
 *	Date : 19/10/2016
 *	Suivi des Modifications :
 *
 */
 
char toUpperCase(char c);

char mars[tailleCarte][tailleCarte];
int cX=1,cY=1; // Position de curiosity (cX,cY)
int dX=1,dY=0;	// Direction de curiosity (dX,dY)=(1,0)|(-1,0)|(0,1)|(0,-1)

int main(int argc, char *argv[]) {
	char c;
	List l_commandes, l_pile;
	FILE* f_commandes;
	
	/** Nouvelle Implémentation **/
	// Initialisation
	
	if (argc == 3)
	{
		lireCarte(argv[1]);
		f_commandes = fopen(argv[2], "r");
		
		if (f_commandes == NULL)
		{
			perror(argv[2]);
			exit(EXIT_FAILURE);
		}
	}
	else if (argc == 2)
	{
		lireCarte("tests/mars.map");
		f_commandes = fopen(argv[1], "r");
		if (f_commandes == NULL)
		{
			perror(argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "\033[1;31m%s: Error: Please enter at least 1 argument.\033[0m\n", argv[0]);
		printf("Usage: %s [\033[1;4mmap-file\033[0m] \033[1;4mprog-file\033[0m\n", argv[0]);
		printf("\t\033[1mmap-file\033[0m : file containing the map.\n");
		printf("\t\033[1mprog-file\033[0m: file containing the prog to go to the object in \033[1mmap-file\033[0m.\n");
		exit(EXIT_FAILURE);
	}
	
	afficherCarte();
	list_new(&l_commandes);
	list_new(&l_pile);
	
	for(c = fgetc(f_commandes) ; !((c == EOF) || (c == 10) || (c == 13)) ; c = fgetc(f_commandes))
	{
		c = toUpperCase(c);
		// On passe les espaces:
		while (c == ' ') c = fgetc(f_commandes);
		
		// Verification
		if (c == 'A' || c == 'G' || c == 'D' || c == 'M' || c == 'P' || c == '?')
			list_add(&l_commandes, (int)c);
		else if (c >= '0' && c <= '8')
			list_add(&l_commandes, (int) (c - '0'));
		// Si c'est une instruction conditionnelle:
		else if (c == '{')
		{
			/* On lit toute la commande de format {V}{F}. Si le format n'est pas
			   respecté, on affiche un message d'erreur et on quite. */
			list_add(&l_commandes, (int)c);
			// On récupère V
			c = fgetc(f_commandes);
			while (c == ' ') c = fgetc(f_commandes);
			list_add(&l_commandes, (int)c);
			// On récupère '}'
			c = fgetc(f_commandes);
			while (c == ' ') c = fgetc(f_commandes);
			if (c != '}')
			{
				fprintf(stderr, "\033[31;m1Erreur: Format invalide: \'%c\' (code ascii %i).\033[0m\n", c, (int) c);
				return EXIT_FAILURE;
			}
			list_add(&l_commandes, (int)c);
			// On récupère '{'
			c = fgetc(f_commandes);
			if (c != '{')
			{
				fprintf(stderr, "\033[31;1mErreur: Format invalide: \'%c\' (code ascii %i).\033[0m\n", c, (int) c);
				return EXIT_FAILURE;
			}
			list_add(&l_commandes, (int)c);
			// On récupère F
			c = fgetc(f_commandes);
			while (c == ' ') c = fgetc(f_commandes);
			// Si F est vide, on ne stock rien.
			if (c == '}')
				list_add(&l_commandes, (int)c);
			else
			{
				list_add(&l_commandes, (int)c);
				// On récupère '}'
				c = fgetc(f_commandes);
				while (c == ' ') c = fgetc(f_commandes);
				if (c != '}')
				{
					fprintf(stderr, "\033[31;1mErreur: Format invalide: \'%c\' (code ascii %i).\033[0m\n", c, (int) c);
					return EXIT_FAILURE;
				}
				list_add(&l_commandes, (int)c);
			}
		}
	}
	
	printf("\033[1mListe des commandes :\033[0m ");print_pile(l_commandes);printf("\n");
	printf("\033[1mPile :\033[0m ");print_pile(l_pile);printf("\n");
	
	execute(l_commandes, l_pile);
	
	return EXIT_SUCCESS;
}

char toUpperCase(char c) {
	if (c >= 'a' && c <= 'z')
		return c - 32;
	else
		return c;
}

