#include "perso.h"


void init_animation_perso(SDL_Rect *animation){

//init width and height
for (int i=0;i<60;i++){
animation[i].w=100; //width
animation[i].h=100; //height
}

//init les x et les y
//ligne 1
for (int i=0; i<15;i++){
animation[i].x=i*100;
animation[i].y=0;
}

//ligne 2
for (int i=15; i<30;i++){
animation[i].x=(i-15)*100;
animation[i].y=100;
}

//ligne 3
for (int i=30; i<45;i++){
animation[i].x=(i-30)*100;
animation[i].y=200;
}

//ligne 4
for (int i=45; i<60;i++){
animation[i].x=(i-45)*100;
animation[i].y=300;
}

}

void initialiser_perso(perso *p, int x){
p->image_perso=IMG_Load ("graphic/run.png");
init_animation_perso(p->animation_perso);
p->position_perso.x=50;
p->position_perso.y=0;
p->direction=1;
p->etat=0;
p->mvtx=2;
p->mvty=150;
p->acc=0;
p->gravity=9.8;
p->vitesse_max_perso=45;
p->acceleration=0;
p->vie=3;
p->score=0;

if (x==1) {
  p->ground=250;
  p->pos_texte_score.x = 50;
  p->pos_texte_score.y = 50;
  p->pos_texte_vie.x = 250;
  p->pos_texte_vie.y = 50;

}
if (x==2) {
  p->ground=500;
  p->pos_texte_score.x = 50;
  p->pos_texte_score.y = 370;
  p->pos_texte_vie.x = 250;
  p->pos_texte_vie.y = 370;
}

    p->police=TTF_OpenFont("graphic/font.ttf",40);



}

void afficher_score(perso* p,SDL_Surface* screen)
{
  SDL_Color couleur_score={255,255,255}; //type RGB
  char char_score[10];
  sprintf(char_score,"%04d",p->score);
  p->texte_score=TTF_RenderText_Solid(p->police,char_score,couleur_score);
  SDL_BlitSurface(p->texte_score,NULL,screen,&p->pos_texte_score);
}

void afficher_vie(perso* p,SDL_Surface* screen)
{SDL_Color couleur_vie={255,255,255};
  char char_vie[10];
  sprintf(char_vie,"%02d",p->vie);
  p->texte_vie=TTF_RenderText_Solid(p->police,char_vie,couleur_vie);
  SDL_BlitSurface(p->texte_vie,NULL,screen,&p->pos_texte_vie);
}

void afficher_vie_score(perso* p,SDL_Surface* screen)
{
  afficher_score(p,screen);
  afficher_vie(p,screen);

}

void deplacer_perso_droite(perso *p){
p->direction=1;
p->position_perso.x+=p->mvtx;
animer_mvt_perso_droite(p);
}

void deplacer_perso_gauche(perso *p){
p->direction=2;
p->position_perso.x-=p->mvtx;
animer_mvt_perso_gauche(p);
}

void animer_mvt_perso_droite(perso *p){

p->compteur++;
//si out of range retour a la 1ere case || range de la case 0 -> 14
if (p->compteur<0 || p->compteur>14) p->compteur=0;

}

void animer_mvt_perso_gauche(perso *p){

p->compteur++;
//si out of range retour a la 1ere case || range de la case 15 -> 29
if (p->compteur<15 || p->compteur>29) p->compteur=15;

}

void animer_perso_stable(perso *p){

 p->compteur++;

//si regarde vert droite
if(p->direction==1)
//si out of range retour a la 1ere case || range de la case 30 -> 44
if (p->compteur<30 || p->compteur>44) p->compteur=30;

//si regarde vers gauche
if(p->direction==2)
//si out of range retour a la 1ere case || range de la case 45 -> 59
if (p->compteur<45 || p->compteur>59) p->compteur=45;

}

void afficher_peso(perso *p, SDL_Surface *screen){
SDL_BlitSurface(p->image_perso,&p->animation_perso[p->compteur],screen,&p->position_perso);
}

void apply_acceleration(perso *p,Uint32 dt){
  if (p->acc%2==0) p->mvtx=2;
if(p->acc%2==1) {
   if(p->mvtx<p->vitesse_max_perso)
 {
 p->acceleration+=50;
   p->mvtx+=0.5*p->acceleration*dt/1000*dt/1000+p->mvtx*dt/1000;
 }
 }

}

void apply_gravity (perso *p){
  p->position_perso.y+=p->gravity;
  if (p->position_perso.y>p->ground) p->position_perso.y=p->ground;
}

void jump_perso(perso *p){
  p->position_perso.y-=p->mvty;
}

void teleport_front(perso *p){

  p->position_perso.y-=100;
  p->position_perso.x+=100;
}
void teleport_back(perso *p){
  p->position_perso.y-=100;
  p->position_perso.x-=100;
}

int on_ground (perso *p){
if (p->position_perso.y==p->ground)
   return 1; // if true
return 0; // if false ( in the air)
}
