#ifndef back_H_INCLUDED
#define back_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct {
SDL_Surface *back ;

SDL_Rect back_pos;

}background ;
void initialiser_back (background *b) ;
void affiche_back(background *b, SDL_Surface *screen);




#endif
