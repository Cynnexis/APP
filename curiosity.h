#define tailleCarte 100

extern char mars[tailleCarte][tailleCarte];
extern int cX,cY,dX,dY; //position et direction de curiosity


void lireCarte();
void afficherCarte();
void avance();
void droite();
void gauche();
int mesure(int value);
void pose(int value);
