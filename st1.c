#include "st1.h"

int stage1(SDL_Surface* screen){

//declaration & int perso
perso p;
initialiser_perso(&p,1);

//declaration & int perso
perso p2;
initialiser_perso(&p2,2);

//declaration & init background
background bg;
initialiser_back(&bg);
int a=1,a2=1; //a -> affichage entite (good)


//declaration et init fps
Uint32 t_dep,t_fin,dt=1;
int fps=30;

//boucle pseudo infinie
SDL_EnableKeyRepeat(200,0); //refresh imput : (duree de la pression du boutton,intervalle de repetition)
int continuer=1;
SDL_Event event;
while (continuer) {
t_dep=SDL_GetTicks();

  p.etat=0;
  p2.etat=0;

if(SDL_PollEvent(&event))
{
  switch(event.type)
  {
    case SDL_QUIT:
continuer=0;
    break;

    case SDL_KEYDOWN:

switch(event.key.keysym.sym){
//perso 1
  case SDLK_RIGHT: //appuie sur fleche droite
    apply_acceleration(&p,dt);
    p.etat=1;

    if (p.position_perso.x<1000)
    deplacer_perso_droite(&p);
      break;

    case SDLK_LEFT : //appuie sur fleche gauche
    p.etat=1;
    apply_acceleration(&p,dt);
    deplacer_perso_gauche(&p);
    break;

    case SDLK_UP : //jump
if(on_ground(&p))  jump_perso(&p);
    break;

    case SDLK_p : //teleport front
if(on_ground(&p)) teleport_front(&p);
    break;

    case SDLK_o : //teleport back
if(on_ground(&p)) teleport_back(&p);
    break;


    case SDLK_v : //vie ++
p.vie++;
    break;

    case SDLK_c : //vie --
p.vie--;
    break;

    case SDLK_x : //score ++
p.score++;
    break;

    case SDLK_w : //score --
p.score--;
    break;


//perso 2

case SDLK_d: //appuie sur fleche droite
  apply_acceleration(&p2,dt);
  p2.etat=1;

  if (p2.position_perso.x<1000)
  deplacer_perso_droite(&p2);
    break;

  case SDLK_q : //appuie sur fleche gauche
  p2.etat=1;
  apply_acceleration(&p2,dt);
  deplacer_perso_gauche(&p2);
  break;

  case SDLK_z : //jump
if(on_ground(&p2))  jump_perso(&p2);
  break;

  case SDLK_r : //teleport front
if(on_ground(&p2)) teleport_front(&p2);
  break;

  case SDLK_e : //teleport back
if(on_ground(&p2)) teleport_back(&p2);
  break;

//pour les 2 perso
    case SDLK_a : //activer/desactiver acceleration
p.acc++;
p2.acc++;
    break;

}

    break;
  }
}


//affichage background
affiche_back(&bg,screen);



//mise a jour et affichage personnage
afficher_vie_score(&p,screen);
afficher_vie_score(&p2,screen);

//p1
apply_gravity(&p);
if (!p.etat) {
animer_perso_stable(&p);
p.mvtx=2; //remove acceleration when not moving
}
afficher_peso(&p,screen);

//p2
apply_gravity(&p2);
if (!p2.etat) {
animer_perso_stable(&p2);
p2.mvtx=2; //remove acceleration when not moving
}
afficher_peso(&p2,screen);

//rafraichir l'affichage
SDL_Flip(screen);

//appliquer fps
t_fin=SDL_GetTicks();
dt=t_fin-t_dep;
if (1000/fps>dt) SDL_Delay (1000/fps-dt);

}

}
