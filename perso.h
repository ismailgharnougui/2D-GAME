#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct
{

    //image (spritesheet)
    SDL_Surface *image_perso;
    //position
    SDL_Rect position_perso;
    //tableau animation
    SDL_Rect animation_perso[60];
    //compteur du tableau animation
    int compteur;
    //direction
    int direction; //droite : 1 || gauche : 2
        //en mvt ou stable
    int etat; // mvt : 1 || stable : 0


    SDL_Rect pos_texte_score,pos_texte_vie;


    //texte
       TTF_Font *police;
      SDL_Surface *texte_score,*texte_vie;


    int mvtx;
    int mvty;

    int vie;
    int score;

    int ground;
    int gravity;

    int acc; // active / desactive acceleration
    double acceleration; // active / desactive acceleration
     int vitesse_max_perso;
} perso;

void init_animation_perso(SDL_Rect *animation);
void initialiser_perso(perso *p, int x);
void deplacer_perso_droite(perso *p);
void deplacer_perso_gauche(perso *p);
void animer_mvt_perso_droite(perso *p);
void animer_mvt_perso_gauche(perso *p);
void animer_perso_stable(perso *p);
void afficher_peso(perso *p, SDL_Surface *screen);
void apply_acceleration(perso *p,Uint32 dt);
void apply_gravity (perso *p);
void jump_perso(perso *p);
void teleport_back(perso *p);
void teleport_front(perso *p);
int on_ground (perso *p);
void afficher_vie_score(perso* p,SDL_Surface* screen);
void afficher_vie(perso* p,SDL_Surface* screen);
void afficher_score(perso* p,SDL_Surface* screen);

#endif
