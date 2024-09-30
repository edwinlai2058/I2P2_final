#include "global.h"

// variables for global usage
const float FPS = 45.0;
const int WIDTH = 768;
const int HEIGHT = 432;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *fps = NULL;
bool key_state[ALLEGRO_KEY_MAX] = {false};

int judge_next_window = 0;
Window_change judge;
int level = 1;

// Shop
int money = 10;
int blue = 0;
int tanned = 0;
