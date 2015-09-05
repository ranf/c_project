#ifndef GUI_ELEMENTFACTORY_H
#define GUI_ELEMENTFACTORY_H

#include "Gui.h"


#include "ElementFactory.h"

gui_chess window_factory(SDL_Surface* win_img);
gui_chess panel_factory(SDL_Surface* pnl_img, int sheet_x_offset, int sheet_y_offset, int sheet_width, int sheet_height, int dest_x, int dest_y, gui_chess parent);
gui_chess label_factory(SDL_Surface* lbl_img, int sheet_x_offset, int sheet_y_offset, int sheet_width, int sheet_height, int dest_x, int dest_y, gui_chess parent);
gui_chess button_factory(SDL_Surface* btn_img, int sheet_x_offset, int sheet_y_offset, int sheet_width, int sheet_height, int dest_x, int dest_y, gui_chess parent);

#endif