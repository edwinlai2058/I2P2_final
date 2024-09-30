#include "global.h"

// the state of character
enum {STOP, MOVE};

Character thief;
Police guard1, guard2, guard3, guard4;
Turbo weed;
Treasure box;
Coin coin;
Clock reducer;

ALLEGRO_SAMPLE *sample = NULL;

void Character::init() {
    // load character images
    for(int i = 1 ; i <= 2 ; i++)
    {
        char temp[50];
        if(level == 1 && blue == 0 && tanned == 0) sprintf( temp, "./image/char_move1.png");
        else if(level == 1 && blue == 1 && tanned == 0) sprintf( temp, "./image/char_move2.png");
        else if(level == 2 && blue == 0 && tanned == 0) sprintf( temp, "./image/char_move3.png");
        else if(level == 2 && blue == 1 && tanned == 0) sprintf( temp, "./image/char_move4.png");
        else if(level == 3 && blue == 0 && tanned == 0) sprintf( temp, "./image/char_move5.png");
        else if(level == 3 && blue == 1 && tanned == 0) sprintf( temp, "./image/char_move6.png");
        else if(tanned == 1) sprintf( temp, "./image/char_move7.png");
        img_move[i-1] = al_load_bitmap(temp);
    }

    // initial the geometric information of character
    width = al_get_bitmap_width(img_move[0]);
    height = al_get_bitmap_height(img_move[0]);
    x = 72, y = 360, dir = LEFT;

    // initial the animation component
    state = STOP, anime = 0, anime_time = 1;
}
void Character::process(ALLEGRO_EVENT event) {
    // process the animation
    if( event.type == ALLEGRO_EVENT_TIMER ) {
        if( event.timer.source == fps ) {
            anime++;
            anime %= anime_time;
            timing++;
        }
    // process the keyboard event
    } else if( event.type == ALLEGRO_EVENT_KEY_DOWN ) {
        key_state[event.keyboard.keycode] = true;
        anime = 0;
    } else if( event.type == ALLEGRO_EVENT_KEY_UP ) {
        key_state[event.keyboard.keycode] = false;
    }
}
void Character::update() {
    if(OP == 1)  speed = 10;
    else if(weed.taken == true)  speed = 4;
    else  speed = 2;

    // use the idea of finite state machine to deal with different state
    if( key_state[ALLEGRO_KEY_W] || key_state[ALLEGRO_KEY_UP]) {
        if(wall[x][y-speed]) {
            y -= speed;
            state = MOVE;
        }
    } else if( key_state[ALLEGRO_KEY_A] || key_state[ALLEGRO_KEY_LEFT]) {
        dir = LEFT;
        if(wall[x-speed][y]) {
            x -= speed;
            state = MOVE;
        }
    } else if( key_state[ALLEGRO_KEY_S] || key_state[ALLEGRO_KEY_DOWN]) {
        if(wall[x][y+24+speed]) {
            y += speed;
            state = MOVE;
        }
    }else if( key_state[ALLEGRO_KEY_D] || key_state[ALLEGRO_KEY_RIGHT]) {
        dir = RIGHT;
        if(wall[x+24+speed][y]) {
            x += speed;
            state = MOVE;
        }
    }
    else if(anime == anime_time-1) {
        anime = 0;
        state = STOP;
    }
    else if (anime == 0) {
        state = STOP;
    }
    if(abs(box.x - x) < 30 && abs(box.y - y) < 30) {
        judge_next_window = 100;
    }
    // OP : overpower mode
    if(OP == 0) {
        if(abs((guard1.x + guard1.width/2) - x) < guard1.width/2+7 && abs((guard1.y + guard1.height/2) - y) < guard1.height/2+7) {
            judge_next_window = 999;
        }
        if(abs((guard2.x + guard2.width/2) - x) < guard2.width/2+7 && abs((guard2.y + guard2.height/2) - y) < guard2.height/2+7) {
            judge_next_window = 999;
        }
        if(abs((guard3.x + guard3.width/2) - x) < guard3.width/2+7 && abs((guard3.y + guard3.height/2) - y) < guard3.height/2+7) {
            judge_next_window = 999;
        }
    }
    if(abs((coin.x+18) - (x+12)) < 25 && abs((coin.y+18) - (y+12)) < 25) {
        coin.x = 999, coin.y = 999;
        al_play_sample_instance(coin_sound);
        coin.moneycount++;
    }
    if(abs((reducer.x+18) - (x+12)) < 25 && abs((reducer.y+18) - (y+12)) < 25) {
        reducer.x = 999, reducer.y = 999;
        reducer.taken = 1;
    }
    if(abs((weed.x+25) - (x+12)) < 25 && abs((weed.y+25) - (y+12)) < 25) {
        weed.x = 999, weed.y = 999;
        weed.taken = true;
    }
}
void Character::draw() {
    // with the state, draw corresponding image
    if( state == STOP ) {
        if(dir == RIGHT)
            al_draw_bitmap(img_move[0], x, y, ALLEGRO_FLIP_HORIZONTAL);
        else
            al_draw_bitmap(img_move[0], x, y, 0);
    } else if( state == MOVE ) {
        if(dir == RIGHT) {
            if( anime < anime_time/2 ) {
                al_draw_bitmap(img_move[0], x, y, ALLEGRO_FLIP_HORIZONTAL);
            } else {
                al_draw_bitmap(img_move[1], x, y, ALLEGRO_FLIP_HORIZONTAL);
            }
        } else { 
            if(anime < anime_time/2) {
                al_draw_bitmap(img_move[0], x, y, 0);
            } else {
                al_draw_bitmap(img_move[1], x, y, 0);
            }
        }
    }
}
void Character::destroy() {
    al_destroy_bitmap(img_move[0]);
    al_destroy_bitmap(img_move[1]);
}

//d for direction: 0 for vertical, 1 for horizontal
void Police::init(int in, int d) {
    kind = d;
    if(DEBUG == 1) return;

    if(d == 0)
        guard_img = al_load_bitmap("./image/guard_vertical.png");
    else
        guard_img = al_load_bitmap("./image/guard_horizontal.png");

    width = al_get_bitmap_width(guard_img);
    height = al_get_bitmap_height(guard_img);

    num = in;

    if(level == 1) {
        if(num == 1)  x = 150, y = 48;
        if(num == 2)  x = 450, y = 250;
        if(num == 3)  x = 600, y = 340;
    } else if(level == 2) {
        if(num == 1)  x = 340, y = 200;
        if(num == 2)  x = 140, y = 300;
        if(num == 3)  x = 700, y = 185;
    } else if(level == 3) {
        if(num == 1)  x = 390, y = 150;
        if(num == 2)  x = 700, y = 300;
        if(num == 3)  x = 600, y = 350;
    }
    dir = UP;
}
void Police::update() {
    if(reducer.taken == 1) speed = 2;
    else speed = 4;

    if(y <= 50 && kind == 0) {
        // 如果警衛已經到達畫面的頂部，則改變方向讓警衛向下移動
        dir = DOWN;
    } else if(y >= 320 && kind == 0) {
        // 如果警衛已經到達畫面的底部，則改變方向讓警衛向上移動
        dir = UP;
    } else if(x <= 50 && kind == 1) {
        // 如果警衛已經到達畫面的左邊，則改變方向讓警衛向右移動
        dir = RIGHT;
    } else if(x >= 550 && kind == 1) {
        // 如果警衛已經到達畫面的右邊，則改變方向讓警衛向左移動
        dir = LEFT;
    }

    if(dir == DOWN)  y += speed;
    if(dir == UP)  y -= speed;
    if(dir == LEFT)  x -= speed;
    if(dir == RIGHT)  x += speed;
}
void Police::draw() {
    if(DEBUG == 1) return;

    if(dir == DOWN)
        al_draw_bitmap(guard_img, x, y, 0);
    else if(dir == UP)
        al_draw_bitmap(guard_img, x, y, ALLEGRO_FLIP_VERTICAL);
    else if(dir == LEFT)
        al_draw_bitmap(guard_img, x, y, 0);
    else
        al_draw_bitmap(guard_img, x, y, ALLEGRO_FLIP_HORIZONTAL);
}

void Police::destroy() {
    al_destroy_bitmap(guard_img);
}
void Coin::init() {
    coin_img = al_load_bitmap("./image/money.png");
    width = al_get_bitmap_width(coin_img);
    height = al_get_bitmap_height(coin_img);
    if(level == 1)
        x = 560, y = 245;
    else if(level == 2)
        x = 436, y = 100;
    else
        x = 485, y = 197;
}
void Coin::draw() {
    al_draw_bitmap(coin_img, x, y, 0);
}
void Treasure::init() {
    box_img = al_load_bitmap("./image/treasure_box.png");
    width = al_get_bitmap_width(box_img);
    height = al_get_bitmap_height(box_img);
    x = 703, y = 140;
}
void Treasure::draw() {
    al_draw_bitmap(box_img, x, y, 0);
}
void Treasure::destroy() {
    al_destroy_bitmap(box_img);
}

void Clock::init() {
    clock1 = al_load_bitmap("./image/timer.png");
    width = al_get_bitmap_width(clock1);
    height = al_get_bitmap_height(clock1);
    if(level == 1)
        x = 60, y = 60;
    else if(level == 2)
        x = 53, y = 103;
    else
        x = 101, y = 244;
}
void Clock::draw() {
    al_draw_bitmap(clock1, x, y, 0);
}

void Turbo::init() {
    weed_img = al_load_bitmap("./image/turbo.png");
    width = al_get_bitmap_width(weed_img);
    height = al_get_bitmap_width(weed_img);
    if(level == 1)
        x = 145, y = 295;
    if(level == 2)
        x = 250, y = 298;
    else
        x = 292, y = 100;
}
void Turbo::draw() {
    al_draw_bitmap(weed_img, x, y, 0);
}

void object_reset() {
    weed.taken = false;
    reducer.taken = false;
}