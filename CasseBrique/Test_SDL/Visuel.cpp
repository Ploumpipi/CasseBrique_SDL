#include "Visuel.h"

cVisu::cVisu()
{
    win = nullptr;
    rend = nullptr;
    barreJoueur = nullptr;
    image = nullptr;
    textJ1 = nullptr;
    textJ2 = nullptr;
}

cVisu::cVisu(int w, int h)
{
    win = SDL_CreateWindow("JEU", // creates a window
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        w, h, 0);

    // creation du renderer
    rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    barreJoueur = nullptr;
    image = nullptr;
    textJ2 = nullptr;
    textJ1 = nullptr;
}

cVisu::~cVisu()
{

}

SDL_Renderer* cVisu::getRenderer()
{
    return rend;
}

SDL_Texture* cVisu::getImgJoueur()
{
    return barreJoueur;
}

SDL_Texture* cVisu::getScoreJ1()
{
    return textJ1;
}

SDL_Texture* cVisu::getScoreJ2()
{
    return textJ2;
}

SDL_Window* cVisu::getWindow()
{
    return win;
}

void cVisu::initBarrePlayer()
{
    SDL_Surface* image = IMG_Load("../img/Monster.png");
    if (!image)
    {
        printf("Erreur de chargement de l'image : %s", SDL_GetError());
    }
    barreJoueur = SDL_CreateTextureFromSurface(rend, image);
}

void cVisu::cleanRenderer()
{
    SDL_RenderClear(rend);
}

void cVisu::afficheRenderer()
{
    SDL_RenderPresent(rend);
}

void cVisu::destroyWindow()
{
    SDL_DestroyWindow(win);
}

void cVisu::destroyRenderer()
{
    SDL_DestroyRenderer(rend);
}

void cVisu::initScoreJ1(SDL_Surface* surf)
{
    if (surf == nullptr)
    {
        printf("Erreur de chargement de la surface : %s", SDL_GetError());
    }
    textJ1 = SDL_CreateTextureFromSurface(rend, surf);
}

void cVisu::initScoreJ2(SDL_Surface* surf)
{
    if (!surf)
    {
        printf("Erreur de chargement de la surface : %s", SDL_GetError());
    }
    textJ2 = SDL_CreateTextureFromSurface(rend, surf);
}
