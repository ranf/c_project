#ifndef GUI_H
#define GUI_H

#include <SDL.h>
#include <SDL_video.h>

/*screen size*/
#define WIN_W 800
#define WIN_H 600

typedef struct game_frame{
	
	SDL_Surface *img;
	int type;
	SDL_Rect box;
	SDL_Rect clip;
	struct game_frame *child;
	struct game_frame *next;
	struct game_frame *parent;

}game_frame;

typedef game_frame* gui_chess;

void startGuiMode();

#include "Build.h"


#endif