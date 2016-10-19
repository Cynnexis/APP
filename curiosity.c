#include "curiosity.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *	Auteur(s) : CERBA Guilhem - BERGER Valentin
 *	Date : 19/10/2016
 *	Suivi des Modifications :
 *
 */

void lireCarte(char *carte) {
	int i,j,x;
	char c;
	FILE * f;

	printf("Lecture carte de mars : ");
	for(i=0;i<tailleCarte;i++)
	{
		for(j = 0 ; j < tailleCarte ; j++)
			mars[i][j] = 0;
	}
	
	f = fopen(carte,"r");
	if (f==NULL)
	{
		printf("%s indisponible.\n",carte);
		exit(1);
	
	}
	for(j = 0 ; j < tailleCarte ;)
	{
		for(i=0;i<tailleCarte;i++)
		{
			x=fscanf(f,"%c",&c);
			if ((x==1)&&(c!=10)&&(c!=13))
				mars[i][j]=c;
			else if (x!=1)
				j=tailleCarte;
			else if (i>0)
			{
				i=tailleCarte;
				j++;
			}
			else
				i=tailleCarte;
		}
	}
	printf(" Fait.\n");
}

void afficherCarte() {
	int i,j;
	char c;

	printf("\n\nCarte de mars.\n");
	
	printf("--------------\n\n");
	for(j=0;j < tailleCarte;j++)
	{
		for(i=0;i < tailleCarte;i++)
		{	
			c = mars[i][j];
			if (c==0)
			{ //hors carte
				if (i==0)
				{
					i=tailleCarte;
					j=tailleCarte;
				}
				else
				{
					printf("\n");
					i=tailleCarte;
				}
			}
			else
			{
				if ((i==cX)&&(j==cY))
				{ //position curiosity
					if (dX==1)
						printf(">");
					else if (dX==-1)
						printf("<");
					else if (dY==1)
						printf("V");
					else
						printf("^");
				}
				else
					printf("%c",c);
			}
		}
	}	
	printf("\n\n--------------\n\n");
}


void avance() {
int tmpX = cX + dX;
int tmpY = cY + dY;
char c=mars[tmpX][tmpY];

if (c=='~') {
	printf("Plouf !?!\n");
	exit(1);}
else if (c=='@') {
	printf("**************************\n");
	printf("*                        *\n");
	printf("*       Victoire !!!     *\n");
	printf("*                        *\n");
	printf("**************************\n");
	exit(0);}
else if ((c!='.')&&(c!='M')&&(c!='m')) {
 cX=tmpX;
 cY=tmpY;	printf("Oups ! Curiosity est sur %c ?!?\n\n",c);}
else {
 cX=tmpX;
 cY=tmpY;}
return;}


void droite() {
if (dX==1) {
	dX=0;
	dY=1;}
else if (dX==-1) {
	dX=0;
	dY=-1;}
else if (dY==1) {
	dX=-1;
	dY=0;}
else {
	dX=1;
	dY=0;}	
return;}


void gauche() {
if (dX==1) {
	dX=0;
	dY=-1;}
else if (dX==-1) {
	dX=0;
	dY=1;}
else if (dY==1) {
	dX=1;
	dY=0;}
else {
	dX=-1;
	dY=0;}	
return;}
