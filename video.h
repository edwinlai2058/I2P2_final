#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED
#include "global.h"

static ALLEGRO_DISPLAY *display;
static char const *filename;
inline ALLEGRO_VIDEO *video;
inline ALLEGRO_TIMER *timer;


void video_display(ALLEGRO_VIDEO *video);
void init_video(char *filename);
void video_begin();
void destroy_video();
void video_play();

#endif // VIDEO_H_INCLUDED
