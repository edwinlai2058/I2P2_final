#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED
#include "global.h"
#include "objects.h"

inline int wall[769][433];
const int block = 48;

inline ALLEGRO_BITMAP *background1;
inline ALLEGRO_BITMAP *background2;
inline ALLEGRO_BITMAP *background3;
inline ALLEGRO_BITMAP *gameover;
inline ALLEGRO_BITMAP *menu;
inline ALLEGRO_BITMAP *levelup1;
inline ALLEGRO_BITMAP *levelup2;
inline ALLEGRO_BITMAP *guide;
inline ALLEGRO_BITMAP *shop;

void menu_init();
int menu_process(ALLEGRO_EVENT event);
void menu_draw();
void menu_destroy();

void guide_init();
int guide_process(ALLEGRO_EVENT event);
void guide_draw();
void guide_destroy();

void shop_init();
int shop_process(ALLEGRO_EVENT event);
void shop_draw();
void shop_destroy();

void game_scene_init();
void game_scene_draw();
void game_scene_destroy();

void next_scene_init();
void next_scene_draw();
void next_scene_destroy();
int next_scene_process(ALLEGRO_EVENT event);

void gameover_init();
void gameover_draw();
void gameover_destroy();
int gameover_process(ALLEGRO_EVENT event);
#endif // SCENE_H_INCLUDED