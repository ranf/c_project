#include "Frame.h"

SDL_Surface* screen;

void create_screen() {
	screen = SDL_SetVideoMode(WIN_W, WIN_H, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (screen == NULL) 
	{
		fprintf(stderr, "ERROR: failed to set video mode: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("Chess Game GUI mode", NULL);
}

void display_screen() {
	if (SDL_Flip(screen) == -1)
	{
		fprintf(stderr, "ERROR: unable to init SDL: %s\n", SDL_GetError());
	}
}

void free_screen() {
	SDL_FreeSurface(screen);
}

void apply_surface(int src_x, int src_y, int src_w, int src_h, int dst_x, int dst_y, SDL_Surface* source, SDL_Surface* destination) {
	SDL_Rect src_new;
	SDL_Rect dst_new;
	src_new.x = src_x;
	src_new.y = src_y;
	src_new.w = src_w;
	src_new.h = src_h;
	dst_new.x = dst_x;
	dst_new.y = dst_y;
	SDL_BlitSurface(source, &src_new, destination, &dst_new);
}