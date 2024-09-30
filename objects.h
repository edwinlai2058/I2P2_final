#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED
#include "global.h"

inline int boxtake = 0;
inline int timing = 0;

typedef enum Direction {UP, DOWN, LEFT, RIGHT};

void object_reset();

class Character {
    public:
        void init();
        void draw();
        void update();
        void process(ALLEGRO_EVENT event);
        void destroy();
        int death_count = 0;
        bool counted = false;

    private:
        int x, y; // the position of image
        int width, height; // the width and height of image
        int speed;
        int state; // the state of character
        Direction dir; // left: false, right: true
        ALLEGRO_BITMAP *img_move[2];
        int anime; // counting the time of animation
        int anime_time; // indicate how long the animation
};
class Police {
    public:
        void init(int in, int d);
        void draw();
        void draw(int init_x, int init_y);
        void update();
        void destroy();
        int x, y;
        int width, height;
        
    private:
        int num;
        int kind;   // 0: vertical, 1: horizontal
        double speed;
        Direction dir;
        ALLEGRO_BITMAP *guard_img;
};

class Turbo {
    public:
        bool taken = false;
        void init();
        void draw();
    public:
        int x, y;
        int width, height;
        ALLEGRO_BITMAP *weed_img = NULL;
};

class Treasure {
    public:
        void init();
        void draw();
        void update();
        void destroy();
    public:
        int x, y;
        int width, height;
        int boxtake = 0;
        ALLEGRO_BITMAP *box_img = NULL;
};
class Coin {
    public:
        bool taken = false;
        void init();
        void draw();
        int x, y;
        int width, height;
        int moneycount;
        ALLEGRO_BITMAP *coin_img = NULL;
};

class Clock {
    public:
        bool taken = false;
        void init();
        void draw();
        void collide();
        int x, y;
        int width, height;
        ALLEGRO_BITMAP *clock1 = NULL;
};

extern Character thief;
extern Police guard1, guard2, guard3, guard4;
extern Turbo weed;
extern Treasure box;
extern Coin coin;
extern Clock reducer;


void coin_update();
void coin_destroy();

#endif // OBJECTS_H_INCLUDED