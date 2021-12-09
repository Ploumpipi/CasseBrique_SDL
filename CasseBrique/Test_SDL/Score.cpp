#include "Score.h"

Score::Score()
{
	this->pointJ1 = 0;
	this->pointJ2 = 0;
}

Score::~Score()
{

}

int Score::getScoreJ1()
{
	return pointJ1;
}

int Score::getScoreJ2()
{
	return pointJ2;
}

void Score::setScoreJ1()
{
	pointJ1++;
}

void Score::setScoreJ2()
{
	pointJ2++;
}

bool Score::verifVictoireJ1()
{
	if (pointJ1 >= 10) {
		return true;
	}
	else {
		return false;
	}
}

bool Score::verifVictoireJ2()
{
	if (pointJ2 >= 10) {
		return true;
	}
	else {
		return false;
	}
}

SDL_Surface* Score::afficheScore(SDL_Color couleur, TTF_Font* police, int joueur)
{
	SDL_Surface* surfTexte = nullptr;
	SDL_Rect posiScr;
	char cScr[10] = "";


	if (joueur == 1)
	{
		sprintf_s(cScr, "%d", pointJ1);

	}
	else {
		sprintf_s(cScr, "%d", pointJ2);

	}
	surfTexte = TTF_RenderText_Blended(police, cScr, couleur);

	return surfTexte;
}

void Score::afficheVictoire(int player, SDL_Color couleur, TTF_Font* police, SDL_Renderer* renderer)
{
	SDL_Surface* surfTexte = NULL;
	char cScr[100] = "";
	SDL_Rect posi = { 450,365,600,50 };

	sprintf_s(cScr, "félicitations joueur %d , vous remportez cette partie!", player);
	surfTexte = TTF_RenderText_Blended(police, cScr, { 255, 0, 0 });

	SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, surfTexte);
	SDL_FreeSurface(surfTexte);

	SDL_RenderCopy(renderer, text, NULL, &posi);
}
