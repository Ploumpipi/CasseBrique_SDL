#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>

class Score {
private:
	int pointJ1, pointJ2;

public:
	//constructeur
	Score();

	//destructeur
	~Score();

	//accesseur
	int getScoreJ1();
	int getScoreJ2();
	
	//mutateur
	void setScoreJ1();
	void setScoreJ2();

	//Verification de victoire
	bool verifVictoireJ1();
	bool verifVictoireJ2();
	
	//fonction qui affiche le score des 2 joueurs
	SDL_Surface* afficheScore(SDL_Color couleur, TTF_Font* police, int joueur);

	//fonction qui affiche qui est le vainqueur
	void afficheVictoire(int player, SDL_Color couleur, TTF_Font* police, SDL_Renderer* renderer);


};