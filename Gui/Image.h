#ifndef GUI_IMAGE_H
#define GUI_IMAGE_H

#include <SDL.h>

/*images paths*/
#define MAIN_IMG "Gui/Images/main_img.bmp"
#define PANELS_SHEET "Gui/Images/panels sheet.bmp"
#define SETTINGS_SHEET "Gui/Images/settings sheet.bmp"
#define PIECES_SHEET "Gui/Images/pieces sheet.bmp"
#define SELECTED_PIECES_SHEET "Gui/Images/selected pieces sheet.bmp"
#define BACKGROUND_IMAGE "Gui/Images/back.bmp"
#define ADD_IMAGE "Gui/Images/add.bmp"
#define LOAD_SAVE "Gui/Images/load_save_buttons.bmp"
#define SAVE "Gui/Images/save_slot.bmp"
void loadImages();
void freeImages();
SDL_Surface *getImage(char *path);

SDL_Surface *load_link_image(char *path);

#endif
