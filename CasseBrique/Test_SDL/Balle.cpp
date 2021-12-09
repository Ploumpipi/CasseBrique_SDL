#include "Balle.h"

Balle::Balle(int x, int y, int hauteur, int largeur)
{
	this->posX = x;
	this->posY = y;
	this->Hauteur = hauteur;
	this->Largeur = largeur;
}

int Balle::getX()
{
	return posX;
}

int Balle::getY()
{
	return posY;
}

int Balle::getVX()
{
	return vx;
}

int Balle::getVY()
{
	return vy;
}

int Balle::getHauteur()
{
	return Hauteur;
}

int Balle::getLargeur()
{
	return Largeur;
}

void Balle::setVX(int vx)
{
	this->vx = vx;
}

void Balle::setVY(int vy)
{
	this->vy = vy;
}

void Balle::setX(int x)
{
	this->posX = x;
}

void Balle::setY(int y)
{
	this->posY = y;
}

void Balle::setPlusX(int vx)
{
	this->posX += vx;
}

void Balle::setMoinsX(int vx)
{
	this->posX -= vx;
}

void Balle::setFoisX(int vx)
{
	this->posX *= vx;
}

void Balle::setPlusY(int vy)
{
	this->posY += vy;
}

void Balle::setMoinsY(int vy)
{
	this->posY -= vy;
}

void Balle::setFoisY(int vy)
{
	this->posY *= vy;
}

void Balle::setPlusVX(int vx)
{
	this->vx += vx;
}

void Balle::setMoinsVX(int vx)
{
	this->vx -= vx;
}

void Balle::setFoisVX(int vx)
{
	this->vx *= vx;
}

void Balle::setPlusVY(int vy)
{
	this->vy += vy;
}

void Balle::setMoinsVY(int vy)
{
	this->vy -= vy;
}

void Balle::setFoisVY(int vy)
{
	this->vy *= vy;
}

void Balle::draw(SDL_Renderer* Renderer) const
{
	SDL_Rect Rect;
	Rect.w = Largeur;
	Rect.h = Hauteur;
	Rect.x = posX;
	Rect.y = posY;
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 0);
	SDL_RenderFillRect(Renderer, &Rect);
}

/*void Balle::colisionJoueur(Raquette J1, Raquette J2)
{
	//calcul permetant le rebond de la balle pour le joueur 1
	if ((posX >= J1.getX()) && (posX <= J1.getX() + J1.getLargeur()) && (posY >= J1.getY()) && (posY <= J1.getY() + J1.getHauteur()))
	{
		int centreJoueur1 = J1.getY() + (J1.getHauteur() / 2);
		int d = centreJoueur1 - posY;
		vy += d * -0.1;
		vx *= -1;
	}
	//calcul permetant le rebond de la balle pour le joueur 2
	if ((posX >= J2.getX()) && (posX <= J2.getX() + J2.getLargeur()) && (posY >= J2.getY()) && (posY <= J2.getY() + J2.getHauteur()))
	{
		int centreJoueur2 = J2.getY() + (J2.getHauteur() / 2);
		int d = centreJoueur2 - posY;
		vy += d * -0.1;
		vx *= -1;
	}
}

void Balle::colisionMur(int x)
{
	if (posX > WIDTHSCREEN<int> - Largeur || posX < 0) {
		vy *= -1;
	}
}

void Balle::Point(Raquette* j1, Raquette* j2, Score* scr, int h, int w)
{
	if (posX < 0)
	{
		scr->setScoreJ2();
		vx = 5;
		vy = 0;
		posY = h / 2;
		posX = w / 2;
		j1->setY(HEIGHTSCREEN<int> /2);

		j2->setY(HEIGHTSCREEN<int> / 2);
	}
	else if (posX > w) {
		scr->setScoreJ1();
		vx = -5;
		vy = 0;
		posX = w - 20;
		posY = h / 2;
		j1->setY(HEIGHTSCREEN<int> / 2);

		j2->setY(HEIGHTSCREEN<int> / 2);
	}
}*/


