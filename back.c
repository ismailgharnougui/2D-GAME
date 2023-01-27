#include "back.h"

int width_bg=1380;

void initialiser_back (background *b)
{
b->back=IMG_Load("graphic/11.jpg");
}


void affiche_back(background *b, SDL_Surface *screen)
{
   SDL_BlitSurface(b->back,NULL, screen, NULL);
}
