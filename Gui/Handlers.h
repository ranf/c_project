#ifndef GUI_HANDLERS_H
#define GUI_HANDLERS_H

#include "Frame.h"
#include "../Common/Settings.h"


#define NUM_HORIZONTAL_OFFSET 60
#define MAIN_VERTICAL_OFFSET 70
#define COLOR_HORIZONTSL_OFFSET 120
#define GAME_MENU_VERTICAL_OFFSET 70
/*files for saving*/
#define MEM_SLOT_FILE_NAME_LENGTH 15
#define MEM_SLOT_1 "mem_slot_1.xml"
#define MEM_SLOT_2 "mem_slot_2.xml"
#define MEM_SLOT_3 "mem_slot_3.xml"
#define MEM_SLOT_4 "mem_slot_4.xml"
#define MEM_SLOT_5 "mem_slot_5.xml"

#define BOARD_TOP_CORNER 35
#define BOARD_BOTTOM_CORNER 562
#define BOARD_SQUARE 66


Settings main_menu_handler(gui_chess gui_window, Settings settings);
Settings mode_menu_handler(gui_chess root, Settings settings);
Settings color_menu_handler(gui_chess root, Settings settings);
Settings settings_menu_handler(gui_chess root, Settings settings);
Settings load_save_menu_handler(gui_chess root, Settings settings);
Settings game_menu_handler(gui_chess game_menu, gui_chess save_menu, Settings settings);
Settings end_of_turn(Settings settings, int situation);
Settings reset_settings(Settings settings);
char promotion_handler(gui_chess root, int player);
void blit_tree(gui_chess start_point, int x, int y);
void display_board(gui_chess game_menu, int selected_x, int selected_y, char** current_board);

#endif