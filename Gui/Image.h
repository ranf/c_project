#ifndef GUI_IMAGE_H
#define GUI_IMAGE_H

#include <SDL.h>

/*images paths*/
#define MAIN_IMG "Gui/Images/main_img.bmp"
#define PANELS_SHEET "Gui/Images/panels sheet.bmp"
#define SETTINGS_SHEET "Gui/Images/settings sheet.bmp"
#define PIECES_SHEET "Gui/Images/pieces sheet.bmp"
#define SELECTED_PIECES_SHEET "Gui/Images/selected pieces sheet.bmp"
#define BACKROUND_IMAGE "Gui/Images/back.bmp"

void loadImages();
void freeImages();
SDL_Surface *getImage(char *path);

SDL_Surface *load_link_image(char *path);

#endif