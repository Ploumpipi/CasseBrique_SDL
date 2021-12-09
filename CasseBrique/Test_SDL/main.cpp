#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <cstdlib>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Raquette.h"
#include "Balle.h"
#include "Enum.h"
#include "Score.h"
#include "Visuel.h"


using namespace std;

int main(int argc, char** argv)
{

    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return -1;
    }

    if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    {
        /* Création de la fenêtre */
        SDL_Window* pWindow = NULL;
        SDL_Renderer* pRenderer = NULL;

        Score scoreJoueur;

        TTF_Font* police = TTF_OpenFont("../fonts/sample.ttf", 65);

        if (police == nullptr)
        {
            fprintf(stderr, "Erreur %s\n", SDL_GetError());
            return -1;
        }

        if (SDL_CreateWindowAndRenderer(WIDTHSCREEN<unsigned int>, HEIGHTSCREEN<unsigned int>, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
            SDL_Quit();
            return EXIT_FAILURE;
        }
        SDL_SetWindowTitle(pWindow, " Casse brique en SDL");


        if (pWindow)
        {
            SDL_Event events;
            Raquette Joueur1(20, 150, WIDTHSCREEN<int> / 2 - 75, HEIGHTSCREEN<int> - 20, 255, 255,255,0);
            Balle balle(WIDTHSCREEN<int> / 2, HEIGHTSCREEN<int>-100, 10, 10);

            

            bool isOpen = true;

            while (isOpen && (!scoreJoueur.verifVictoireJ1()))

            {
                while (SDL_PollEvent(&events))
                {
                    switch (events.type) {

                    case SDL_QUIT:
                        // handling of close button
                        isOpen = false;
                        break;

                    case SDL_KEYDOWN:
                        // keyboard API for key pressed
                        switch (events.key.keysym.sym) {
                        case SDLK_LEFT:
                            Joueur1.setEtatJoueur(joueur::gauche);
                            break;
                        case SDLK_RIGHT:
                            Joueur1.setEtatJoueur(joueur::droite);
                            break;
                        }
                        break;
                    case SDL_KEYUP:
                        switch (events.key.keysym.sym) {
                        case SDLK_LEFT:
                        case SDLK_RIGHT:
                            Joueur1.setEtatJoueur(joueur::none);
                            break;
                        }
                        break;
                    }
                }
                Joueur1.modifPosX();
                

                balle.setPlusX(balle.getVX());
                balle.setPlusY(balle.getVY());
                if (balle.getX() > WIDTHSCREEN<int> - balle.getLargeur() || balle.getX() < 0) {
                    balle.setFoisVX(-1); // horiz wall hit
                }
                if (balle.getY() > HEIGHTSCREEN<int> - balle.getHauteur() || balle.getY() < 0) balle.setFoisVY(-1);// vert wall hit
                    if (balle.getX() >= Joueur1.getX() && balle.getX() <= Joueur1.getX() + Joueur1.getLargeur() && balle.getY() >= Joueur1.getY() - Joueur1.getHauteur() && balle.getY() <= Joueur1.getY()) {
                        // paddle hit
                        int CentreJoueur1 = Joueur1.getY() + (Joueur1.getHauteur() / 2);
                        int d = CentreJoueur1 - balle.getX();
                        balle.setPlusVX(d * -0.01); // here's the trick
                        balle.setFoisVY(-1);
                    }

                    if (balle.getY() > HEIGHTSCREEN<int> -balle.getLargeur()) {
                        scoreJoueur.setScoreJ1();
                        balle.setVX(0);
                        balle.setVY(5);
                        balle.setX(WIDTHSCREEN<int> / 2);
                        balle.setY(HEIGHTSCREEN<int> / 2);
                        Joueur1.setX(WIDTHSCREEN<int> / 2);
                        printf("Le joueur 1 a : %d points\n", scoreJoueur.getScoreJ1());
                    }



                if (Joueur1.getX() == 0) {
                    Joueur1.setDroiteX(15);
                }
                if (Joueur1.getX() >= WIDTHSCREEN<int> - Joueur1.getLargeur()) {
                    Joueur1.setGaucheX(15);
                }
                
                Joueur1.draw(pRenderer);
                balle.draw(pRenderer);
                SDL_RenderPresent(pRenderer);
                SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
                SDL_RenderClear(pRenderer);


                SDL_Delay(1000 / 60);
            }
        }
        else
        {
            fprintf(stderr, "Erreur de création de la fenêtre: %s\n", SDL_GetError());
        }
    }

    SDL_Quit();

    return 0;
}