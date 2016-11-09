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
	int x;
	char c;
	List l_commandes, l_pile;
	FILE* f_commandes;
	
	// Version temporaire avec execution immediate des commandes A G D.
	// A remplacer par 
	//	- une lecture des commandes/programmes avec sauvegarde dans une liste chainee
	// suivie par
	//	- une interpretation du programme lu
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
		fprintf(stderr, "\033[1;31m%s: Error: Argument necessary.\033[0m\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	afficherCarte();
	list_new(&l_commandes);
	list_new(&l_pile);
	
	for(x = fscanf(f_commandes, "%c",&c) ; x == 1 && !feof(f_commandes) && !((c == 10) || (c == 13) || (c == 32)) ; x = fscanf(f_commandes, "%c",&c))
	{
		c = toUpperCase(c);
		if (c == 'A' || c == 'G' || c == 'D' || c == 'M' || c == 'P')
			list_add(&l_commandes, (int)c);
		else if (c >= '0' && c <= '8')
			list_add(&l_pile, (int) (c - '0'));
		else
		{
			fprintf(stderr, "\033[1;31m%s: Error: \'%i\': Invalid command.\033[0m\n", argv[0], (int)c);
			exit(EXIT_FAILURE);
		}
	}
	
	printf("\033[1mListe des commandes :\033[0m ");list_print_as_char(l_commandes);printf("\n");
	printf("\033[1mPile :\033[0m ");list_print(l_pile);printf("\n");
	lecture(l_commandes, l_pile);
	
	/** TMP **
	// Initialisation
	if (argc == 2)
		lireCarte(argv[1]);
	else
		lireCarte("tests/mars.map");
	
	afficherCarte();
	
	printf("\n? > ");
	for(x = scanf("%c",&c) ; x == 1 ; x = scanf("%c",&c))
	{
		if ((c=='a')||(c=='A'))
		{
			avance();
			afficherCarte();
		}
		else if ((c=='g')||(c=='G'))
		{
			gauche();
			afficherCarte();
		}
		else if ((c=='d')||(c=='D'))
		{
			droite();
			afficherCarte();
		}
		else if ((c==10)||(c==13)||(c==32)) //caracteres non pris en compte : espace, saut de ligne
			printf("\n? > ");
		else if (c=='?')
			printf("Commande : a pour avancer, g/d pour tourner a gauche ou droite, q pour quiter.\n");
		else if (c=='q')
			return 0;
		else
			printf("Commande non reconnue.\n");
	}*/
	// Fin de la zone a remplacer
	
	return EXIT_SUCCESS;
}

char toUpperCase(char c) {
	if (c >= 'a' && c <= 'z')
		return c - 32;
	else
		return c;
}

