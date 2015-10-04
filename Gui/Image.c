#include "Image.h"

SDL_Surface *main_img = NULL;
SDL_Surface *panel = NULL;
SDL_Surface *set = NULL;
SDL_Surface *pieces = NULL;
SDL_Surface *game_pices_select = NULL;
SDL_Surface *backround = NULL;
SDL_Surface *add = NULL;
SDL_Surface *load_save = NULL;
SDL_Surface *save_slot = NULL;
SDL_Surface *messages = NULL;
SDL_Surface *black_mate = NULL;
SDL_Surface *white_mate = NULL;
void loadImages() {
	main_img = load_link_image(MAIN_IMG);
	panel = load_link_image(PANEL_BLACK_WHITE);
	set = load_link_image(SETTINGS);
	pieces = load_link_image(GAME_PIECES);
	game_pices_select = load_link_image(GAME_PIECES_SELECT);
	backround = load_link_image(BACKGROUND_IMAGE);
	add = load_link_image(ADD_IMAGE);
	load_save = load_link_image(LOAD_SAVE);
    save_slot = load_link_image(SAVE);
    messages = load_link_image(MES);
    black_mate = load_link_image(BLACK_MATE);
    white_mate = load_link_image(WHITE_MATE);
}

void freeImages() {
	SDL_FreeSurface(main_img);
	SDL_FreeSurface(panel);
	SDL_FreeSurface(set);
	SDL_FreeSurface(pieces);
	SDL_FreeSurface(game_pices_select);
	SDL_FreeSurface(backround);
	SDL_FreeSurface(add);
	SDL_FreeSurface(load_save);
    SDL_FreeSurface(save_slot);
    SDL_FreeSurface(messages);
    SDL_FreeSurface(black_mate);
    SDL_FreeSurface(white_mate);
}

SDL_Surface *getImage(char *path) {
	if (strcmp(path, MAIN_IMG) == 0) {
		return main_img;
	} else if (strcmp(path, PANEL_BLACK_WHITE) == 0) {
		return panel;
	} else if (strcmp(path, SETTINGS) == 0) {
		return set;
	} else if (strcmp(path, GAME_PIECES) == 0) {
		return pieces;
	} else if (strcmp(path, GAME_PIECES_SELECT) == 0) {
		return game_pices_select;
	} else if (strcmp(path, BACKGROUND_IMAGE) == 0) {
		return backround;
	} else if (strcmp(path, ADD_IMAGE) == 0) {
		return add;
	} else if (strcmp(path, LOAD_SAVE) == 0) {
		return load_save;
    } else if (strcmp(path, SAVE) == 0) {
        return save_slot;
    }
    else if (strcmp(path, MES) == 0) {
        return messages;
    }
    else if (strcmp(path, BLACK_MATE) == 0) {
        return black_mate;
    }
    else if (strcmp(path, WHITE_MATE) == 0) {
        return white_mate;
    }

	return NULL; //should never happen
}

SDL_Surface *load_link_image(char *path)
{
	/*declare & initialize*/
	SDL_Surface *tmp, *result ;
	tmp = NULL;
	result = NULL;

	/*load the image*/
	tmp = SDL_LoadBMP(path);

	if (tmp != NULL)
	{
		result = SDL_DisplayFormat(tmp);
		if (result != NULL){
			unsigned colorkey = SDL_MapRGB(result->format, 0xFF, 0, 0xFF);
			SDL_SetColorKey(result, SDL_SRCCOLORKEY, colorkey);
		}
		SDL_FreeSurface(tmp);
		return (result);
	}
	else
	{
		printf("ERROR: failed to load image: %s\n", SDL_GetError());
		return NULL;
	}
}
