#pragma once
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

class cVisu
{
	SDL_Window* win;
	SDL_Renderer* rend;
	SDL_Texture* barreJoueur;
	SDL_Texture* textJ1;
	SDL_Texture* textJ2;
	SDL_Surface* image;

public:

	//constructeur
	cVisu();
	cVisu(int w, int h);

	//destructeur
	~cVisu();

	//accesseur
	SDL_Renderer* getRenderer();
	SDL_Texture* getImgJoueur();
	SDL_Texture* getScoreJ1();
	SDL_Texture* getScoreJ2();
	SDL_Window* getWindow();

	void initBarrePlayer();
	void cleanRenderer();
	void afficheRenderer();
	void destroyWindow();
	void destroyRenderer();
	void initScoreJ1(SDL_Surface* surf);
	void initScoreJ2(SDL_Surface* surf);



};
