#include "Frame.h"

void display_screen() {
	if (SDL_Flip(screen) == -1)
	{
		fprintf(stderr, "ERROR: unable to init SDL: %s\n", SDL_GetError());
	}
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