#include <SDL.h>
#include "Enum.h"

class Raquette {
private :
	int hauteur;
	int largeur;
	int posX;
	int posY;
	int vraiR;
	int vraiG;
	int vraiB;
	int vraiA;

	joueur etatJoueur;


public : 
	Raquette(int h, int w, int x, int y, int R, int G, int B, int A);
	void draw(SDL_Renderer* Renderer)const;

	int getHauteur();
	int getLargeur();
	int getX();
	int getY();
	joueur getEtat();

	void modifPosX();

	void setDroiteX(int x);
	void setGaucheX(int x);
	void setX(int x);
	void setEtatJoueur(joueur etat);
	
};