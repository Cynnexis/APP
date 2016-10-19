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


char mars[tailleCarte][tailleCarte];
int cX=1,cY=1; // Position de curiosity (cX,cY)
int dX=1,dY=0;	// Direction de curiosity (dX,dY)=(1,0)|(-1,0)|(0,1)|(0,-1)

int main(int argc, char *argv[]) {
	int x;
	char c;

	// Initialisation
	if (argc == 2)
		lireCarte(argv[1]);
	else
		lireCarte("tests/mars.map");
	
	afficherCarte(); 
	
	// Version temporaire avec execution immediate des commandes A G D.
	// A remplacer par 
	//	- une lecture des commandes/programmes avec sauvegarde dans une liste chainee
	// suivie par
	//	- une interpretation du programme lu
	printf("\n? > ");
	for(x=scanf("%c",&c);x==1;x=scanf("%c",&c))
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
	}
	// Fin de la zone a remplacer
	
	return 0;
}

