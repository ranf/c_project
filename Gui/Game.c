#include "Game.h"


int gui_player_turn(int current_color, int offsets[4], gui_chess game_menu, gui_chess save_menu)
{
	pboard_node moves_list,tmp_move;
	SDL_Event event;
	gui_chess promote_menu;
	char promoted_to[7];
	int x, y, is_first = 1;
	int first_i, first_j, second_i, second_j;

	moves_list = NULL;
	//todo replace with real ischeck+ismate
	if (is_mate(board, current_color, kings_positions)){
		apply_surface(CHECKMATE_LABEL, selected_pieces_sheet, screen);
		if (current_color == WHITE){
			apply_surface(BLACK_MATE_IMG, selected_pieces_sheet, screen);
		}
		else{
			apply_surface(WHITE_MATE_IMG, selected_pieces_sheet, screen);
		}
		display_screen();
		SDL_Delay(2500);
		return MAIN_MENU;
	}

	if (is_check(board, current_color, kings_positions)){
		apply_surface(CHECK_LABEL, selected_pieces_sheet, screen);
		display_screen();
		SDL_Delay(2500);
		display_board(game_menu, -1, -1,board);
	}

	while (true){
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT){
			return QUIT;
		}

		else if (event.type == SDL_MOUSEBUTTONUP){
			x = event.button.x;
			y = event.button.y;
					/*if the mouse clicked in the buttons zone*/
			if ((x > offsets[0]) && (x < (offsets[0] + offsets[2]))){
						/*main menu button selected*/
				if ((y>offsets[1]) && (y < (offsets[1] + offsets[3]))){
					return MAIN_MENU;
				}
						/*save button selected*/
				else if ((y>(offsets[1] + GAME_MENU_VERTICAL_OFFSET)) && (y < (offsets[1] + offsets[3] + GAME_MENU_VERTICAL_OFFSET))){
					load_save_menu_handler(save_menu, 1);
					is_first = 1;
					display_board(game_menu, -1, -1,board);
				}
						/*restart button selected*/
				else if ((y>(offsets[1] + 2 * GAME_MENU_VERTICAL_OFFSET)) && (y < (offsets[1] + offsets[3] + 2 * GAME_MENU_VERTICAL_OFFSET))){
					now_playing = WHITE;
					init_board();
					return GAME_MENU;
				}
						/*quit button selected*/
				else if ((y>QUIT_SIDE_Y) && (y < (QUIT_SIDE_Y + offsets[3]))){
					return QUIT;
				}
			}
			else if ((x>BOARD_TOP_CORNER) && (x<BOARD_BOTTOM_CORNER) && (y>BOARD_TOP_CORNER) && (y < BOARD_BOTTOM_CORNER)){
				//first click is source and second is target
				if (is_first){
					first_i = (x - BOARD_TOP_CORNER) / BOARD_SQUARE;
					first_j = 7 - ((y - BOARD_TOP_CORNER) / BOARD_SQUARE);
					//todo use piece color
					if (is_friendly(current_color, board[first_i][first_j])){
						//reaplace with getPieceMoves
						moves_list = piece_move(board, current_color, first_i, first_j, kings_positions);
						is_first = 0;
						display_board(game_menu, first_i, first_j,board);
						if (get_moves_allowed){
							show_possible_moves(moves_list);
							display_screen();
						}
					}
				}
				else{
					second_i = (x - BOARD_TOP_CORNER) / BOARD_SQUARE;
					second_j = 7 - ((y - BOARD_TOP_CORNER) / BOARD_SQUARE);
					if (is_friendly(current_color, board[second_i][second_j])){
						first_i = second_i;
						first_j = second_j;
						free(moves_list);
						moves_list = piece_move(board, current_color, first_i, first_j, kings_positions);
						display_board(game_menu, first_i, first_j,board);
						if (get_moves_allowed){
							show_possible_moves(moves_list);
							display_screen();
						}
					}
					else{
								/*check if the moving piece is a pawn*/
						if (tolower(board[first_i][first_j]) == 'm'){
									/*check if the pawn get a promotion*/

							if ((second_j % 7) == 0){
								if (player_move(board, first_i, first_j, second_i, second_j, promoted_to, moves_list, current_color))
								{
									promote_menu = build_promotion_menu(now_playing);
									promotion_handler(promote_menu, promoted_to);
									board[first_i][first_j] = 'm';
						}
					}
				}
				if (player_move(board, first_i, first_j, second_i, second_j, promoted_to, moves_list, current_color)){
					display_board(game_menu, -1, -1,board);
					free_list(moves_list);
					return -1;
				}
				free_list(moves_list);
			}

		}
	}

		}
	}
}

int gui_computer_turn(gui_chess game_menu)
{
	//todo convert function to use Settings
	pboard_node com_move;
	char tmp_board[BOARD_SIZE][BOARD_SIZE];
	int i, j;
	bool check;
	check = true;
	if (u_color == WHITE)
		u_color = BLACK;
	else
		u_color = WHITE;

	if (is_mate(board, u_color)) {
		apply_surface(CHECKMATE_LABEL, selected_pieces_sheet, screen);
		if (-1 * u_color == WHITE) {
			apply_surface(BLACK_MATE_IMG, selected_pieces_sheet, screen);
		}
		else {
			apply_surface(WHITE_MATE_IMG, selected_pieces_sheet, screen);
		}
		display_screen();
		SDL_Delay(2500);
		return MAIN_MENU;
	}
	if (is_check(board, u_color)){
		apply_surface(CHECK_LABEL, selected_pieces_sheet, screen);
		display_screen();
		SDL_Delay(2500);
		display_board(game_menu, -1, -1, board);
	}
	
	//todo use copyBoard
	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			tmp_board[i][j] = board[i][j];
		}
	}
	if (u_color == WHITE)
		u_color = BLACK;
	else
		u_color = WHITE;
	//todo use getMinimaxMove
	com_move = computer_move(board, u_color);
	display_board(game_menu, com_move->moved_from[0], com_move->moved_from[1], tmp_board);
	SDL_Delay(1500);
	display_board(game_menu, -1, -1,board);

	free(com_move);

	return -1;
}

void show_possible_moves(MoveList* moves)
{
	MoveList* head = moves;
	while (head != NULL){
		apply_surface(GET_MOVES_SELECT_SQURE, BOARD_SQUARE, BOARD_SQUARE, 
			head->data.to.x * BOARD_SQUARE + BOARD_TOP_CORNER, 
			(7 - head->data.to.y)*BOARD_SQUARE + BOARD_TOP_CORNER, selected_pieces_sheet, screen);
		head = head->next;
	}
}