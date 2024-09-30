#include "video.h"
#include "GameWindow.h"

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
}
