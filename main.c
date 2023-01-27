#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

#include"st1.h"




int main()
{
    int hauteur_fenetre = 650,
        largeur_fenetre = 1100;


  TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);

    //FENETRE PRINCIPALE
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(largeur_fenetre, hauteur_fenetre, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("My Game", NULL); // titre de la fenetre

stage1(screen);


    SDL_Quit();

    return 0;
}
