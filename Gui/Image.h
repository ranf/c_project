#ifndef GUI_IMAGE_H
#define GUI_IMAGE_H

#include <SDL.h>

/*images paths*/
#define MAIN_IMG "Gui/Images/main_img.bmp"
#define PANEL_BLACK_WHITE "Gui/Images/black_white_panel.bmp"
#define SETTINGS "Gui/Images/settings.bmp"
#define GAME_PIECES "Gui/Images/game_pieces.bmp"
#define GAME_PIECES_SELECT "Gui/Images/select_game_pieces.bmp"
#define BACKGROUND_IMAGE "Gui/Images/back.bmp"
#define ADD_IMAGE "Gui/Images/add.bmp"
#define LOAD_SAVE "Gui/Images/load_save_buttons.bmp"
#define SAVE "Gui/Images/save_slot.bmp"

void loadImages();
void freeImages();
SDL_Surface *getImage(char *path);
SDL_Surface *load_link_image(char *path);

#endif
