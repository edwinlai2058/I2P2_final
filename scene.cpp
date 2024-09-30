#include "global.h"

void boundary()
{
    if(level == 1) {
        for (int i = 0; i < block*16; i++) { 
            for (int j = 0; j < block*9; j++) 
                wall[i][j] = 1; 
        } 
        for (int i = 0; i < block*16; i++) { 
            for (int j = 0; j < block*1; j++) 
                wall[i][j] = 0; 
        } 
        for (int i = 0; i < block*16; i++) { 
            for (int j = block*8; j < block*9; j++) 
                wall[i][j] = 0; 
        } 
        for (int i = 0; i < block/3; i++) { 
            for (int j = 0; j < block*9; j++) 
                wall[i][j] = 0; 
        } 
        for (int i = block*16-block/3; i < block*16; i++) { 
            for (int j = 0; j < block*9; j++) 
                wall[i][j] = 0; 
        } 
        for (int i = 0; i < block*3; i++) { 
            for (int j = block*2; j < block*3; j++) 
                wall[i][j] = 0; 
        } 
        for (int i = block*4; i < block*4+block/3; i++) { 
            for (int j = 0; j < block*7; j++) 
                wall[i][j] = 0; 
        } 
        for (int i = block*11; i < block*16; i++) { 
            for (int j = block*4; j < block*5; j++) 
                wall[i][j] = 0; 
        } 
        for (int i = block*11; i < block*11+block/3; i++) { 
            for (int j = block*4; j < block*7; j++) { 
                wall[i][j] = 0; 
            } 
        }
    } else if(level == 2) {
        //initialize 
        for(int i = 0; i < block*16; i++) { 
            for(int j = 0; j < block*9; j++) 
                wall[i][j] = 0; 
        } 
        for(int i = 0; i < block*4; i++) { 
            for(int j = 0; j < block*1; j++) 
                wall[i][j] = 1;//acceptable to walk1 
        } 
        for (int i = 0; i < block*1; i++) { 
            for (int j = block*1; j < block*3; j++) 
                wall[i][j] = 1; // acceptable to walk2 
        } 
        for (int i = block*1; i < block*2; i++) { 
            for (int j = block*2; j < block*3; j++) 
                wall[i][j] = 1; // acceptable to walk3 
        } 
        for (int i = block*3; i < block*4; i++) 
        { 
            for (int j = block*1; j < block*9; j++) 
                wall[i][j] = 1; // acceptable to walk4 
        } 
        for (int i = block*1; i < block*2; i++) 
        { 
            for (int j = block*4; j < block*9; j++) 
                wall[i][j] = 1; // acceptable to walk5 
        } 
        for (int i = block*2; i < block*3; i++) { 
            for (int j = block*4; j < block*5; j++) 
                wall[i][j] = 1; // acceptable to walk6 
        } 
        for (int i = block*4; i < block*6; i++) { 
            for (int j = block*6; j < block*8; j++) 
                wall[i][j] = 1; // acceptable to walk7 
        } 
        for (int i = block*4; i < block*16; i++) { 
            for (int j = block*4; j < block*5; j++) 
                wall[i][j] = 1; // acceptable to walk8 
        } 
        for (int i = 336; i < 384; i++) { 
            for (int j = 0; j < 432; j++) 
                wall[i][j] = 1; // acceptable to walk9 
        } 
        for (int i = 240; i < 336; i++) { 
            for (int j = 0; j < 96; j++) 
                wall[i][j] = 1; // acceptable to walk10 
        } 
        for (int i = block*6; i < block*7; i++) { 
            for (int j = block*2; j < block*4; j++) 
                wall[i][j] = 1; // acceptable to walk11 
        } 
        for (int i = block*5; i < block*6; i++) { 
            for (int j = block*3; j < block*4; j++) 
                wall[i][j] = 1; // acceptable to walk12 
        } 
        for (int i = block*9; i < block*11; i++) { 
            for (int j = 0; j < block*3; j++) 
                wall[i][j] = 1; // acceptable to walk13 
        } 
        for (int i = block*11; i < block*15; i++) { 
            for (int j = 0; j < block*1; j++)  
                wall[i][j] = 1; // acceptable to walk14 
        } 
        for (int i = block*12; i < block*16; i++) { 
            for (int j = block*1; j < block*4; j++) 
                wall[i][j] = 1; // acceptable to wall15 
        }
    } else if(level == 3) {
        //initialize
        for(int i = 0; i < 768; i++) {
            for(int j = 0; j < 432; j++)
                wall[i][j] = 0;
        }
        for(int i = 0; i < 432; i++) {
            for(int j = 0; j < 48; j++)
                wall[i][j] = 1;//acceptable to walk
        }
        for(int i = 0; i < 48; i++) {
            for(int j = 96; j < 384; j++)
                wall[i][j] = 1;//acceptable to walk2
        }
        for(int i = 96; i < 236; i++) {
            for(int j = 236; j < 288; j++)
                wall[i][j] = 1;//acceptable to walk4
        }
        for(int i = 192; i < 336; i++) {
            for(int j = 192; j < 236; j++)
                wall[i][j] = 1;//acceptable to walk3
        }
        for(int i = 288; i < 336; i++) {
            for(int j = 96; j < 240; j++)
                wall[i][j] = 1;//acceptable to walk5
        }
        for(int i = 96; i < 240; i++) {
            for(int j = 96; j < 192; j++)
                wall[i][j] = 1;//acceptable to walk6
        }
        for(int i = 48; i < 96; i++) {
            for(int j = 96; j < 144; j++)
                wall[i][j] = 1;//acceptable to walk7
        }
        for(int i = 0; i < 624; i++) {
            for(int j = 336; j < 384; j++)
                wall[i][j] = 1;//acceptable to walk8
        }
        for(int i = 384; i < 432; i++) {
            for(int j = 0; j < 384; j++)
                wall[i][j] = 1;//acceptable to walk9
        }
        for(int i = 288; i < 624; i++) {
            for(int j = 288; j < 336; j++)
                wall[i][j] = 1;//acceptable to walk10
        }
        for(int i = 480; i < 528; i++) {
            for(int j = 192; j < 240; j++)
                wall[i][j] = 1;//acceptable to walk 11
        }
        for(int i = 480; i < 624; i++) {
            for(int j = 144; j < 192; j++)
                wall[i][j] = 1;//acceptable to walk12
        }
        for(int i = 576; i < 624; i++) {
            for(int j = 144; j < 384; j++)
                wall[i][j] = 1;//acceptable to walk13
        }
        for(int i = 432; i < 768; i++) {
            for(int j = 48; j < 96; j++)
                wall[i][j] = 1;//acceptable to walk14
        }
        for(int i = 672; i < 768; i++) {
            for(int j = 48; j < 432; j++)
                wall[i][j] = 1;//acceptable to walk1r
        }
    }
}

// function of menu
void menu_init()
{
    menu = al_load_bitmap("./image/menu.jpg");
}
int menu_process(ALLEGRO_EVENT event)
{
    if( event.type == ALLEGRO_EVENT_KEY_UP )
    {
        if( event.keyboard.keycode == ALLEGRO_KEY_ENTER ) {
            al_play_sample_instance(button);
            judge_next_window = 1; //menu -> level 1
            //judge = TO_LEVEL1;
            cout << "Game start!\n";
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_P) {
            al_play_sample_instance(button);
            judge_next_window = 2; //menu -> guide
            //judge = TO_GUIDE;
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_S) {
            al_play_sample_instance(button);
            judge_next_window = 3; //menu -> shop
            //judge = TO_SHOP;
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            al_play_sample_instance(button);
            game_destroy();
            return GAME_TERMINATE;
        }
    }
}
void menu_draw()
{
    al_draw_bitmap(menu,0,0,0);
}
void menu_destroy()
{
    al_destroy_bitmap(menu);
}

//guide(complete)//
void guide_init()
{
    guide = al_load_bitmap("./image/guide.jpg");
}
int guide_process(ALLEGRO_EVENT event)
{
    if(event.type == ALLEGRO_EVENT_KEY_UP)
    {
        if(event.keyboard.keycode == ALLEGRO_KEY_P) {
            al_play_sample_instance(button);
            judge_next_window = 4;
        }
    }
    return 0;
}
void guide_draw()
{
    al_draw_bitmap(guide, 0, 0, 0);
}
void guide_destroy()
{
    al_destroy_bitmap(guide);
}

//shop(not yet)//
void shop_init()
{
    if(blue == 0 && tanned == 0) shop = al_load_bitmap("./image/shop.jpg");
    if(blue == 1 && tanned == 0) shop = al_load_bitmap("./image/shop_L.png");
    if(blue == 0 && tanned == 1) shop = al_load_bitmap("./image/shop_R.png");
    if(blue == 1 && tanned == 1) shop = al_load_bitmap("./image/shop_LR.png");
}
int shop_process(ALLEGRO_EVENT event)
{
    if(event.type == ALLEGRO_EVENT_KEY_UP) {
        if(event.keyboard.keycode == ALLEGRO_KEY_B) {
            al_play_sample_instance(button);
            judge_next_window = 4;
        } else if(event.keyboard.keycode == ALLEGRO_KEY_L && blue == 0) {
            al_play_sample_instance(button);
            al_play_sample_instance(coin_sound);
            blue = 1; //buy hair
            if(money >= 10)  money -= 10;
            else cout << "Money decreased by 10!\n";
            judge_next_window = 3;
        } else if(event.keyboard.keycode == ALLEGRO_KEY_R && tanned == 0) {
            al_play_sample_instance(button);
            al_play_sample_instance(coin_sound);
            tanned = 1; //buy skin
            if(money >= 100)  money -= 100;
            else cout << "Money decreased by 100!\n";
            judge_next_window = 3;
        }
    } else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        return GAME_TERMINATE;
}

void shop_draw()
{
    al_draw_bitmap(shop, 0, 0, 0);
}
void shop_destroy()
{
    al_destroy_bitmap(shop);
}


// function of game_scene
void game_scene_init()
{
    thief.init();
    background1 = al_load_bitmap("./image/Map001.png");
    cout << (background1 ? "Load background1 successfully!\n" : "Fail to load background1!\n");

    background2 = al_load_bitmap("./image/Map002.png");
    cout << (background2 ? "Load background2 successfully!\n" : "Fail to load background2!\n");

    background3 = al_load_bitmap("./image/Map003.png");
    cout << (background3 ? "Load background3 successfully!\n" : "Fail to load background3!\n");

    // Loop the song until the display closes
    al_set_sample_instance_playmode(mission, ALLEGRO_PLAYMODE_LOOP);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(mission, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(mission, 0.3);

    boundary();
    object_reset();
}
void game_scene_draw()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    al_play_sample_instance(mission);
    if(level == 1) {
        al_draw_bitmap(background1, 0, 0, 0);
    }
    else if(level == 2) {
        al_draw_bitmap(background2, 0, 0, 0);
    }
    else if(level == 3) {
        al_draw_bitmap(background3, 0, 0, 0);
    }
    thief.draw();
    guard1.draw();
    guard2.draw();
    guard3.draw();
}
void game_scene_destroy()
{
    if(level == 1)
        al_destroy_bitmap(background1);
    else if(level == 2)
        al_destroy_bitmap(background2);
    else if(level == 3)
        al_destroy_bitmap(background3);
    thief.destroy();
    guard1.destroy();
    guard2.destroy();
    guard3.destroy();

}

void next_scene_init()
{
    levelup1 = al_load_bitmap("./image/levelup1.jpg");
    levelup2 = al_load_bitmap("./image/levelup2.jpg");

    al_stop_sample_instance(mission);
    al_set_sample_instance_playmode(complete_song, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(complete_song, al_get_default_mixer());
    al_set_sample_instance_gain(complete_song, 0.3);
}
int next_scene_process(ALLEGRO_EVENT event)
{
    if(judge_next_window == 100 && level == 3) {
        save_scores();
        printf("You finish the game!\n");
        judge_next_window = 400;
    }

    if(event.type == ALLEGRO_EVENT_KEY_UP)
    {
        if(event.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            key_state[ALLEGRO_KEY_D] = false;
            key_state[ALLEGRO_KEY_W] = false;
            key_state[ALLEGRO_KEY_A] = false;
            key_state[ALLEGRO_KEY_S] = false;
            key_state[ALLEGRO_KEY_UP] = false;
            key_state[ALLEGRO_KEY_DOWN] = false;
            key_state[ALLEGRO_KEY_RIGHT] = false;
            key_state[ALLEGRO_KEY_LEFT] = false;
            if(level == 1) {
                judge_next_window = 200;
            } else if(level == 2) {
                judge_next_window = 300;
                printf("Level now = %d\n", level);
            }
            al_stop_sample_instance(complete_song);
        }
        if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            cout << "You sucks!\n";
            return GAME_TERMINATE;
            game_destroy();
        }
    }
}
void next_scene_draw()
{
    if(level == 1){
        al_draw_bitmap(levelup1, 0, 0, 0);
        al_play_sample_instance(complete_song);
    }
    else if(level == 2){
        al_draw_bitmap(levelup2, 0, 0, 0);
        al_play_sample_instance(complete_song);
    }
}
void next_scene_destroy()
{
    if(level == 2) {
        al_destroy_bitmap(levelup1);
        al_stop_sample_instance(complete_song);
    }
    else if(level == 3) {
        al_destroy_bitmap(levelup2);
        al_stop_sample_instance(complete_song);
    }
}
void gameover_init()
{
    gameover = al_load_bitmap("./image/gameover.jpg");
    al_stop_sample_instance(mission);
    al_set_sample_instance_playmode(busted_song, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(busted_song, al_get_default_mixer());
    al_set_sample_instance_gain(busted_song, 0.3);
}
int gameover_process(ALLEGRO_EVENT event)
{
    if(event.type == ALLEGRO_EVENT_KEY_UP)
    {
        if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            al_play_sample_instance(button);
            game_destroy();
            return GAME_TERMINATE;
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
            key_state[ALLEGRO_KEY_D] = false;
            key_state[ALLEGRO_KEY_W] = false;
            key_state[ALLEGRO_KEY_A] = false;
            key_state[ALLEGRO_KEY_S] = false;
            key_state[ALLEGRO_KEY_UP] = false;
            key_state[ALLEGRO_KEY_DOWN] = false;
            key_state[ALLEGRO_KEY_RIGHT] = false;
            key_state[ALLEGRO_KEY_LEFT] = false;
            al_play_sample_instance(button);
            judge_next_window = 101;
            al_stop_sample_instance(busted_song);
        }
    }
}
void gameover_draw()
{
    al_draw_bitmap(gameover, 0, 0, 0);
    al_play_sample_instance(busted_song);

}
void gameover_destroy()
{
    al_destroy_bitmap(gameover);
}
