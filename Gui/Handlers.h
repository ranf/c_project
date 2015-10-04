#ifndef GUI_HANDLERS_H
#define GUI_HANDLERS_H

#include "Frame.h"
#include "Game.h"
#include "Build.h"
#include "../Common/Settings.h"
#include "../Common/XmlParser.h"
#include "../Common/Board.h"

/* load or save slots*/
#define MEM_SLOT_1 "Saves/mem_slot_1.xml"
#define MEM_SLOT_2 "Saves/mem_slot_2.xml"
#define MEM_SLOT_3 "Saves/mem_slot_3.xml"
#define MEM_SLOT_4 "Saves/mem_slot_4.xml"
#define MEM_SLOT_5 "Saves/mem_slot_5.xml"
#define MEM_SLOT_6 "Saves/mem_slot_6.xml"
#define MEM_SLOT_7 "Saves/mem_slot_7.xml"

/* const*/
#define BOARD_TOP_CORNER 35
#define BOARD_BOTTOM_CORNER 562

#define MODE_BUTTON_X_SRC 55
#define MODE_BUTTON_SELECT_X_SRC 267
#define NEXT_BUTTON_X_SRC 553
#define STRAT_BUTTON_X_SRC 185
#define COLOR_BUTTON_Y_SRC 353
#define SELECT_COLOR_BUTTON_Y_SRC 403
#define BUTTON_NUMBER_OFFSET_HORIZ 60
#define MAIN_MENU_BUTTONS_HEIGH 70
#define COLOR_BUTTON_OFFSET_HORIZ 120
#define GAME_MENU_BUTTON_HEIGHT 70
#define MEM_SLOT_FILE_NAME_LENGTH 21
#define BOARD_SQUARE_LEN 66

/* labels*/
#define LABLE_CHAECKMAIT 119,117,325,49,170,150
#define LABLE_CHECK 379,26,133,38,250,260
#define LABLE_TIE 5,620,345,44,125,140
#define LABLE_WRONG_SET 20,540,330,44,125,140
#define LABLE_CAN_NOT_START 20,290,295,45,155,40

#define WHITE_MATE_LABLE 119,117,325,49,170,150
#define BLACK_MATE_LABLE 119,117,325,49,170,150

/*messages*/
#define CAN_NOT_GIVE_HINT_MES 20,290,295,45,155,40
#define CAN_NOT_SET_MESSAGE 20,540,330,44,125,140



Settings main_menu_handler(gui_chess gui_window, Settings settings);
Settings mode_menu_handler(gui_chess root, Settings settings);
Settings color_menu_handler(gui_chess root, Settings settings);
Settings settings_menu_handler(gui_chess root, Settings settings);
Settings load_save_menu_handler(gui_chess root, Settings settings);
Settings game_menu_handler(gui_chess game_menu, gui_chess save_menu, Settings settings);
Settings end_of_turn(Settings settings, int situation, gui_chess game_menu);
Settings reset_settings(Settings settings);
Settings set_menu_handler(gui_chess root, gui_chess game_menu, gui_chess save_menu, Settings settings);
Settings minimax_menu_handler(gui_chess root, Settings settings);
Settings best_move_handler ( Settings settings, gui_chess game_menu);
char promotion_handler(gui_chess root, int player);
char find_char(int x, int y, int x_bound, int y_bound, int i, int j, char** board);
void show_on_screen(gui_chess start_point, int x, int y);
void display_board(gui_chess game_menu, int selected_x, int selected_y, char** current_board);
void select_number_button(gui_chess number_button, int number);
char** set_piece(int x, int y, int x_bound, int y_bound, int i, int j, char** board);
char** apply_best_move(char** board, Move* move);
Settings cancel_after_best_move(Settings settings);
#endif
