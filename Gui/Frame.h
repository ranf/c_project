#ifndef GUI_FRAME_H
#define GUI_FRAME_H

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

} game_frame;

typedef game_frame* gui_chess;

void create_screen();
SDL_Surface* get_screen();
void display_screen();
void free_screen();
void apply_surface(int src_x, int src_y, int src_w, int src_h, int dst_x, int dst_y, SDL_Surface* source, SDL_Surface* destination);
void free_element(gui_chess element);

#endif
