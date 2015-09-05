#include "Image.h"

SDL_Surface *main_img = NULL;
SDL_Surface *panels_sheet = NULL;
SDL_Surface *settings_sheet = NULL;
SDL_Surface *pieces_sheet = NULL;
SDL_Surface *selected_pieces_sheet = NULL;
SDL_Surface *backround = NULL;

void loadImages() {
	main_img = load_link_image(MAIN_IMG);
	panels_sheet = load_link_image(PANELS_SHEET);
	settings_sheet = load_link_image(SETTINGS_SHEET);
	pieces_sheet = load_link_image(PIECES_SHEET);
	selected_pieces_sheet = load_link_image(SELECTED_PIECES_SHEET);
	backround = load_link_image(BACKROUND_IMAGE);
}

void freeImages() {
	SDL_FreeSurface(screen);
	SDL_FreeSurface(main_img);
	SDL_FreeSurface(panels_sheet);
	SDL_FreeSurface(settings_sheet);
	SDL_FreeSurface(pieces_sheet);
	SDL_FreeSurface(selected_pieces_sheet);
}

SDL_Surface *getImage(char *path) {
	if (strcmp(path, MAIN_IMG) == 0) {
		return main_img;
	} else if (strcmp(path, PANELS_SHEET) == 0) {
		return panels_sheet;
	} else if (strcmp(path, SETTINGS_SHEET) == 0) {
		return settings_sheet;
	} else if (strcmp(path, PIECES_SHEET) == 0) {
		return pieces_sheet;
	} else if (strcmp(path, SELECTED_PIECES_SHEET) == 0) {
		return SELECTED_PIECES_SHEET;
	} else if (strcmp(path, BACKROUND_IMAGE) == 0) {
		return backround;
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