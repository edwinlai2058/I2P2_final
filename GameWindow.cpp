#include "global.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_video.h>

// ALLEGRO Variables

Windows window = MENU;
bool draw = false;
const char *title = "nthu_thief 2.0";

int Game_establish()
{
    int msg = 0;

    game_init();
    game_begin();

    while ( msg != GAME_TERMINATE )
    {
        msg = game_run();
        if ( msg == GAME_TERMINATE )
            printf( "Game Over\n" );
    }

    game_destroy();
    return 0;
}

void game_init()
{
    printf( "Game Initializing...\n" );
    al_init();
    
    // Create display
    display = al_create_display(WIDTH, HEIGHT);
    // create event queue
    event_queue = al_create_event_queue();
    // Initialize Allegro settings
    al_set_window_position(display, 500, 300);
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_init_video_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon

    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event

    // Register event
    al_register_event_source(event_queue, al_get_display_event_source( display ));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    fps  = al_create_timer( 1.0 / FPS );
    al_register_event_source(event_queue, al_get_timer_event_source( fps ));

    // initialize the icon on the display
    ALLEGRO_BITMAP *icon = al_load_bitmap("./image/icon.png");
    al_set_display_icon(display, icon);
}

void game_begin()
{
    //Load sound
    cout << "Loading sound..." << endl;
    song = al_load_sample("./sound/bob_menu.wav");
    al_reserve_samples(10);
    menu_song = al_create_sample_instance(song);
    song = al_load_sample("./sound/bob_complete.wav");
    complete_song = al_create_sample_instance(song);
    song = al_load_sample("./sound/bob_busted.wav");
    busted_song = al_create_sample_instance(song);
    song = al_load_sample("./sound/bob_sneak.wav");
    mission = al_create_sample_instance(song);
    song = al_load_sample("./sound/coin_picked.wav");
    coin_sound = al_create_sample_instance(song);
    song = al_load_sample("./sound/button.wav");
    button = al_create_sample_instance(song);
    song = al_load_sample("./sound/finish.wav");
    finish = al_create_sample_instance(song);

    al_set_sample_instance_playmode(menu_song, ALLEGRO_PLAYMODE_LOOP);
    al_set_sample_instance_playmode(finish, ALLEGRO_PLAYMODE_ONCE);
    al_set_sample_instance_playmode(coin_sound, ALLEGRO_PLAYMODE_ONCE);
    al_set_sample_instance_playmode(button, ALLEGRO_PLAYMODE_ONCE);
    al_restore_default_mixer();
    al_attach_sample_instance_to_mixer(menu_song, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(finish, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(button, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(coin_sound, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(menu_song, 0.3) ;
    al_set_sample_instance_gain(button, 0.3) ;
    al_set_sample_instance_gain(coin_sound, 0.3);
    al_set_sample_instance_gain(finish, 0.3);
    al_play_sample_instance(menu_song);


    al_start_timer(fps);

    //Load video
    init_video("./image/opening.ogv");
    video_begin();
    // initialize the menu before entering the loop
    menu_init();
    while( 1 ){
        al_wait_for_event(event_queue, &event);
        if( event.type == ALLEGRO_EVENT_TIMER ) {
            video_display(video);
        }
        if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
            al_close_video(video);
            //cout << (video == NULL ? "Close video succeed" : "Close video failed") << endl;
            break;
        } 
        if( event.type == ALLEGRO_EVENT_VIDEO_FINISHED ) {
            al_close_video(video);
            //cout << (video == NULL ? "Close video succeed" : "Close video failed") << endl;
            break;
        }
    }
    cout << "Game begin end" << endl;
}

void game_update()
{
    if( judge_next_window == 1  && window == MENU) {
        cout << "Go from menu to stage 1\n";
        // initialize next scene
        al_destroy_sample_instance(menu_song);
        cout << "Stop menu song\n";
        game_scene_init();
        cout << "Initialize game scene\n";
        box.init();
        cout << "Initialize treasure\n";
        guard1.init(1, 0);
        guard2.init(2, 0);
        guard3.init(3, 1);
        cout << "Initialize guard\n";
        coin.init();
        cout << "Initialize coin\n";
        reducer.init();
        cout << "Initialize clock\n";
        weed.init();
        cout << "Initialize turbo\n";
        judge_next_window = 0;
        window = GAME;  //game
    }

    if( judge_next_window == 101) //stage 1 play again
    {
        thief.init();
        game_scene_init();
        box.init();
        guard1.init(1, 0);
        guard2.init(2, 0);
        guard3.init(3, 1);
        coin.init();
        reducer.init();
        weed.init();
        judge_next_window = 0;
    }

    if(judge_next_window == 2 && window == MENU)  //menu to guide
        guide_init();

    if(judge_next_window == 4)  //every scene to menu
        menu_init();

    if(judge_next_window == 3 && window == MENU)  //menu to shop
        shop_init();

    if( window == GAME && judge_next_window != 200 && judge_next_window != 300) {
        thief.update();
        //box.update();
        guard1.update();
        guard2.update();
        guard3.update();
    }
    if(judge_next_window == 100) //level up
        next_scene_init();
    if(judge_next_window == 999) { //game over
        gameover_init();
        thief.death_count++;
    }
    if(judge_next_window == 200 && level == 1) { //level up -> stage 2
        level = 2;
        thief.init();
        game_scene_init();
        box.init();
        guard1.init(1, 0);
        guard2.init(2, 0);
        guard3.init(3, 1);
        coin.init();
        reducer.init();
        weed.init();
        judge_next_window = 201;
    }
    if(judge_next_window == 300 && level == 2) { //level up -> stage 3
        level = 3;
        thief.init();
        game_scene_init();
        box.init();
        guard1.init(1, 0);
        guard2.init(2, 0);
        guard3.init(3, 1);
        coin.init();
        reducer.init();
        weed.init();
        judge_next_window = 301;
    }
    if(judge_next_window == 300 && level == 3) {

    }
}

int process_event()
{
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    // process the event of other component
    if( window == MENU )
    {
        if(judge_next_window == 2)
            guide_process(event);
        else if(judge_next_window == 3)
            shop_process(event);
        else if(judge_next_window != -1)
            menu_process(event);
    }
    else if( judge_next_window == 0 || judge_next_window == 201 || judge_next_window == 301)
    {
        thief.process(event);
    }
    else if(judge_next_window == 100)
    {
        next_scene_process(event);
        if(level == 3) {
            cout << "Time: " << (double)timing/FPS << endl;
            show_leaderboard();
            al_play_sample_instance(finish);
            init_video("./image/complete.ogv");
            video_begin();
            // initialize the menu before entering the loop
            while( 1 ) {
                al_wait_for_event(event_queue, &event);
                if( event.type == ALLEGRO_EVENT_TIMER ) {
                    video_display(video);
                } else if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
                    al_close_video(video);
                    break;
                } else if( event.type == ALLEGRO_EVENT_VIDEO_FINISHED ) {
                    al_close_video(video);
                    break;
                }
            }
            return -1;
        }
    }
    else if(judge_next_window == 999)
    {
        gameover_process(event);
    }
    else if(judge_next_window == 4)
    {
        //printf("process\n");
        menu_process(event);
    }

    if(event.type == ALLEGRO_EVENT_TIMER)
        if(event.timer.source == fps)
            draw = true;
    if(draw) game_update();
    return 0;
}

void game_draw()
{
    if( window == MENU )
    {
        if(judge_next_window == 1) {
            game_scene_draw();
            cout << "Draw game scene\n";
        }
        else if(judge_next_window == 2) {
            guide_draw();
            cout << "Draw guide\n";
        }
        else if(judge_next_window == 3) {
            shop_draw();
            cout << "Draw shop\n";
        }
        else {
            menu_draw();
            cout << "Draw menu\n";
        }
    }
    else if( window == GAME )
    {
        if(judge_next_window == 100)
            next_scene_draw();
        else if(judge_next_window == 999) {
            gameover_draw();
            thief.counted = false;
        }
        else {
            game_scene_draw();
            box.draw();
            coin.draw();
            reducer.draw();
            weed.draw();
        }
    }
    al_flip_display();
}
int game_run()
{
    int error = 0;
    if( draw )
    {
        game_update();
        game_draw();
        draw = false;
    }
    if ( !al_is_event_queue_empty(event_queue) )
    {
        error = process_event();
    }
    return error;
}

void game_destroy()
{
    // Make sure you destroy all things
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    game_scene_destroy();
}

void init_video(char* filename) {
    timer = al_create_timer(1.0 / 60);
    al_set_new_display_flags(ALLEGRO_RESIZABLE);
    //al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST);
    // linear interpolation for scaling images
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    cout << "Reading video.....\n";
    video = al_open_video(filename);
    cout << (video ? "Read video succeed" : "Read video fail!!!!") << endl;

    // register video event
    ALLEGRO_EVENT_SOURCE *temp = al_get_video_event_source(video);
    al_register_event_source(event_queue, temp);
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
}
void video_display(ALLEGRO_VIDEO *video) {
    ALLEGRO_BITMAP *frame = al_get_video_frame(video);

    // check if we get the frame successfully
    // Note the this code is necessary

    if ( !frame )  return;
    // Display the frame.
    // rescale the frame into the size of screen
    al_draw_scaled_bitmap(frame,0, 0,al_get_bitmap_width(frame),al_get_bitmap_height(frame),0, 0,al_get_display_width(display),al_get_display_height(display), 0);
    al_flip_display();
}

void video_begin() {
    al_reserve_samples(20);
    al_start_video(video, al_get_default_mixer());
    al_start_timer(timer);
}

void destroy_video() {
    al_destroy_display(display);
    al_close_video(video);
}
