#include "Raquette.h"
#include "Enum.h"
#include <SDL.h>

Raquette::Raquette(int h, int w, int x, int y, int R, int G, int B, int A)
{
	this->hauteur = h;
	this->largeur = w;
	this->posX = x;
	this->posY = y;
	this->vraiR = R;
	this->vraiG = G;
	this->vraiB = B;
	this->vraiA = A;
	etatJoueur = joueur::none;
}

void Raquette::draw(SDL_Renderer* Renderer) const
{
	SDL_Rect Rect;
	Rect.w = largeur;
	Rect.h = hauteur;
	Rect.x = posX;
	Rect.y = posY;
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255,0);
	SDL_RenderFillRect(Renderer, &Rect);
}

int Raquette::getHauteur()
{
	return hauteur;
}

int Raquette::getLargeur()
{
	return largeur;
}

int Raquette::getX()
{
	return posX;
}

int Raquette::getY()
{
	return posY;
}

joueur Raquette::getEtat()
{
	return etatJoueur;
}

void Raquette::modifPosX()
{
	switch (etatJoueur)
	{
	case joueur::gauche :
		posX -= 15;
		break;
	case joueur::droite :
		posX += 15;
		break;
	case joueur::none:
		break;
	}
}

void Raquette::setDroiteX(int x)
{
	this->posX += x;
}

void Raquette::setGaucheX(int x)
{
	this->posX -= x;
}

void Raquette::setX(int x)
{
	this->posX = x;
}

void Raquette::setEtatJoueur(joueur etat)
{
	etatJoueur = etat;
}
