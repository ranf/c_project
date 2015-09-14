#include "Game.h"
#include "Handlers.h"

int gui_player_turn(Settings settings, int offsets[4], gui_chess game_menu, gui_chess save_menu)
{
	//todo - should probably convert to return settings as well (here and every internal function)
	SDL_Event event;
	bool moving_piece_selected = false;
	Position from, to;
	from.x = 0;
	from.y = 0;
	to.x = 0;
	to.y = 0;
	Move* move = createMove(from, to, NO_PROMOTION);
	int game_state = GS_PLAYER_TURN;

	while (game_state == GS_PLAYER_TURN) {
		if (SDL_WaitEvent(&event) == 0) {
			fprintf(stderr, "ERROR: SDL_WaitEvent failed: %s\n", SDL_GetError());
			exit(EXIT_FAILURE);
		}
		game_state = apply_player_click(settings, event, offsets,
			game_menu, save_menu, &moving_piece_selected, move);
	}
	freeMove(move);
	return game_state;
}

int gui_computer_turn(Settings settings, gui_chess game_menu)
{
	Move* com_move = getMinimaxMove(settings.board, settings.playingColor, settings.minimaxDepth);
	char** temp_board = copyBoard(settings.board);
	settings.board = applyMove(settings.board, com_move);
	display_board(game_menu, com_move->from.x, com_move->from.y, temp_board);
	SDL_Delay(1500);
	display_board(game_menu, -1, -1, settings.board);

	freeMove(com_move);
	freeBoard(temp_board);
	return GS_PLAYER_TURN;
}

int apply_player_click(Settings settings, SDL_Event event, int offsets[4],
	gui_chess game_menu, gui_chess save_menu, bool* moving_piece_selected, Move* move)
{
	if (event.type == SDL_QUIT) {
		return GS_QUIT;
	}
	if (event.type != SDL_MOUSEBUTTONUP) {
		return GS_PLAYER_TURN;
	}
	//Mouse Click
	int x = event.button.x;
	int y = event.button.y;
	if (player_clicked_main_menu(x, y, offsets)) {
		return GS_MAIN_MENU;
	}
	if (player_clicked_save(x, y, offsets)) {
		load_save_menu_handler(save_menu, settings); //todo - use settings return value
		moving_piece_selected = false;
		display_board(game_menu, -1, -1, settings.board);
		return GS_PLAYER_TURN;
	}
	if (player_clicked_restart(x, y, offsets)) {
		return GS_RESTART;
	}
	if (player_clicked_quit(x, y, offsets)) {
		return GS_QUIT;
	}
	if (player_clicked_board(x, y ,offsets)) {
		Position clicked = board_clicked_position(x, y);
		return apply_board_click(game_menu, clicked, settings,move, moving_piece_selected);
	}
	return GS_PLAYER_TURN;
}

int apply_board_click(gui_chess game_menu, Position clicked, Settings settings, Move* move, bool* moving_piece_selected)
{
	if (pieceOwner(settings.board[clicked.x][clicked.y]) == settings.playingColor) {
		move->from = clicked;
		move->promotion = NO_PROMOTION;
		*moving_piece_selected = true;
		display_board(game_menu, move->from.x, move->from.y, settings.board);
		MoveList* moves = getPieceMoves(settings.board, clicked, true);
		show_possible_moves(moves);
		freeMoves(moves);
		display_screen();
	} else if (*moving_piece_selected) {
		if (isPawn(settings.board[clicked.x][clicked.y] && endOfBoard(clicked, settings.playingColor))) {
			gui_chess promote_menu = build_promotion_menu(settings.playingColor);
			move->promotion = promotion_handler(promote_menu, settings.playingColor);
			if (move->promotion == NO_PROMOTION) //must promote pawn
				return GS_QUIT;
		}
		move->to = clicked;
		MoveList* valid_moves = getPieceMoves(settings.board, move->from, true);
		if (moveIsInList(valid_moves, move)) {
			settings.board = applyMove(settings.board, move);
			display_board(game_menu, -1, -1, settings.board);
			freeMoves(valid_moves);
			return GS_PLAYER_FINISHED;
		}
		freeMoves(valid_moves);
	}
	return GS_PLAYER_TURN;
}

void show_possible_moves(MoveList* moves)
{
	MoveList* head = moves;
	while (head != NULL){
		apply_surface(GET_MOVES_SELECT_SQURE, BOARD_SQUARE, BOARD_SQUARE, 
			head->data->to.x * BOARD_SQUARE + BOARD_TOP_CORNER, 
			(7 - head->data->to.y)*BOARD_SQUARE + BOARD_TOP_CORNER, getImage(SELECTED_PIECES_SHEET), get_screen());
		//todo replace 7 with meaningful const
		head = head->next;
	}
}

bool player_clicked_buttons_zone(int x, int offsets[4])
{
	return x > offsets[0] && x < offsets[0] + offsets[2];
}

bool player_clicked_main_menu(int x, int y, int offsets[4])
{
	return player_clicked_buttons_zone(x,offsets) &&
		y > offsets[1] && y < offsets[1] + offsets[3];
}

bool player_clicked_save(int x, int y, int offsets[4])
{
	return player_clicked_buttons_zone(x,offsets) &&
		y > offsets[1] + GAME_MENU_VERTICAL_OFFSET &&
		y < offsets[1] + offsets[3] + GAME_MENU_VERTICAL_OFFSET;
}

bool player_clicked_restart(int x, int y, int offsets[4])
{
	return player_clicked_buttons_zone(x,offsets) &&
		y > offsets[1] + 2 * GAME_MENU_VERTICAL_OFFSET &&
		y < offsets[1] + offsets[3] + 2 * GAME_MENU_VERTICAL_OFFSET;
}

bool player_clicked_quit(int x, int y, int offsets[4])
{
	return player_clicked_buttons_zone(x,offsets) &&
		y > QUIT_SIDE_Y && y < QUIT_SIDE_Y + offsets[3];
}

bool player_clicked_board(int x, int y, int offsets[4])
{
	return x > BOARD_TOP_CORNER && x < BOARD_BOTTOM_CORNER &&
		y > BOARD_TOP_CORNER && y < BOARD_BOTTOM_CORNER;
}

Position board_clicked_position(int x, int y)
{
	Position p;
	p.x = (x - BOARD_TOP_CORNER) / BOARD_SQUARE;
	p.y = 7 - ((y - BOARD_TOP_CORNER) / BOARD_SQUARE);
	return p;
}

