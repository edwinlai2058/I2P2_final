#ifndef GAMEWINDOW_H_INCLUDED
#define GAMEWINDOW_H_INCLUDED
#include "global.h"
#include "objects.h"
#include "scene.h"

typedef enum {MENU, SHOP, GUIDE, GAME} Windows;
typedef enum {TO_MENU, TO_GUIDE, TO_SHOP,  TO_LEVEL1, TO_LEVEL2, TO_LEVEL3, FAIL} Window_change;

inline ALLEGRO_SAMPLE *song = NULL;
inline ALLEGRO_SAMPLE_INSTANCE *menu_song;
inline ALLEGRO_SAMPLE_INSTANCE *complete_song;
inline ALLEGRO_SAMPLE_INSTANCE *busted_song;
inline ALLEGRO_SAMPLE_INSTANCE *mission;
inline ALLEGRO_SAMPLE_INSTANCE *coin_sound;
inline ALLEGRO_SAMPLE_INSTANCE *button;
inline ALLEGRO_SAMPLE_INSTANCE *finish;

inline ALLEGRO_EVENT_QUEUE *queue;
inline ALLEGRO_EVENT event;

int Game_establish();
int process_event();
void game_init();
void game_begin();
void game_update();
void game_draw();
int game_run();
void game_destroy();

#endif // GAMEWINDOW_H_INCLUDED