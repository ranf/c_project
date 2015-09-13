#ifndef GUI_GAME_H
#define GUI_GAME_H

#include "../Common/Move.h"
#include "../Common/Settings.h"
#include "../Common/Minimax.h"
#include "Frame.h"
#include "Image.h"

/* Game states*/
#define GS_PLAYER_TURN 1
#define GS_QUIT 2
#define GS_PLAYER_FINISHED 3
#define GS_MAIN_MENU 4
#define GS_RESTART 5

int gui_player_turn(Settings settings, int offsets[4], gui_chess game_menu, gui_chess save_menu);
int gui_computer_turn(Settings settings, gui_chess game_menu);
int apply_player_click(Settings settings, SDL_Event event, int offsets[4],
	gui_chess game_menu, gui_chess save_menu, bool* moving_piece_selected, Move* move);
int apply_board_click(gui_chess game_menu, Position clicked, Settings settings, Move* move, bool* moving_piece_selected);
void show_possible_moves(MoveList* moves);
bool player_clicked_buttons_zone(int x, int offsets[4]);
bool player_clicked_main_menu(int x, int y, int offsets[4]);
bool player_clicked_save(int x, int y, int offsets[4]);
bool player_clicked_restart(int x, int y, int offsets[4]);
bool player_clicked_quit(int x, int y, int offsets[4]);
bool player_clicked_board(int x, int y, int offsets[4]);
Position board_clicked_position(int x, int y);

#include "Handlers.h"

#endif
