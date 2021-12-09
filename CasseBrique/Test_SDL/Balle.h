#include <SDL.h>
//#include "Raquette.h"
#include "Enum.h"
#include "Score.h"

class Balle {
private :
	int posX, posY, Hauteur, Largeur;
	float vx = 0, vy = 5;
public :
	//Constructeur
	Balle(int x, int y, int hauteur, int largeur);

	//Accesseurs
	int getX();
	int getY();
	int getVX();
	int getVY();
	int getHauteur();
	int getLargeur();


	//Mutateurs
	void setVX(int vx);
	void setVY(int vy);
	
	void setX(int x);
	void setY(int y);

	void setPlusX(int vx);
	void setMoinsX(int vx);
	void setFoisX(int vx);

	void setPlusY(int vy);
	void setMoinsY(int vy);
	void setFoisY(int vy);

	void setPlusVX(int vx);
	void setMoinsVX(int vx);
	void setFoisVX(int vx);

	void setPlusVY(int vy);
	void setMoinsVY(int vy);
	void setFoisVY(int vy);

	void draw(SDL_Renderer* Renderer)const;

	/*void colisionJoueur(Raquette J1, Raquette J2);
	void colisionMur(int x);
	void Point(Raquette* j1, Raquette* j2, Score* scr, int h, int w);*/

};
