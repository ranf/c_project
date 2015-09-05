#include "Handlers.h"


Settings main_menu_handler(gui_chess gui_window, Settings settings)
{
	gui_chess tmp;
	SDL_Event event;
	int mouse_x, mouse_y, x_bound, y_bound, width, heigth;

	blit_tree(gui_window, 0, 0);
	display_screen();
	
	//todo etract to function
	tmp = gui_window->child;
	x_bound = tmp->box.x;
	y_bound = tmp->box.y;
	tmp = tmp->child->next;
	x_bound += tmp->box.x;
	y_bound += tmp->box.y;
	width = tmp->clip.w;
	heigth = tmp->clip.h;

	bool quitting = false;
	while (!quitting)
	{
		SDL_WaitEvent(&event);
		/*player clicked new game, load or quit*/
		if (event.type == SDL_MOUSEBUTTONUP)
		{
			mouse_x = event.button.x;
			mouse_y = event.button.y;
			if ((mouse_x > x_bound) && (mouse_x<(x_bound + width)) && (mouse_y>y_bound) && (mouse_y < (y_bound + heigth)))
			{
				settings.state = MAIN_MENU_STATE;
				quitting = true;
			}
			if ((mouse_x > x_bound) && (mouse_x<(x_bound + width)) && (mouse_y>(y_bound + MAIN_VERTICAL_OFFSET)) && (mouse_y < (y_bound + MAIN_VERTICAL_OFFSET + heigth)))
			{
				settings.state = LOAD_STATE;
				quitting = true;
			}
			if ((mouse_x > x_bound) && (mouse_x<(x_bound + width)) && (mouse_y>(y_bound + 2 * MAIN_VERTICAL_OFFSET)) && (mouse_y < (y_bound + 2 * MAIN_VERTICAL_OFFSET + heigth)))
			{
				settings.state = TERMINATE_STATE;
				quitting = true;
			}
		}
		if (event.type == SDL_QUIT)
		{
			settings.state = TERMINATE_STATE;
			quitting = true;
		}
	}
	return settings;
}

Settings mode_menu_handler(gui_chess root, Settings settings)
{//todo implement playingColor selection
	SDL_Event event;
	gui_chess tmp, pvp, pvc, button;
	int x, y, x_bound, y_bound, p_vs_p_x, p_vs_p_y, p_vs_c_x, p_vs_c_y, width, heigth, s_c_width, s_c_heigth, c_x, c_y, start_x, start_y;

	/*define & find bounderies of the buttons*/
	tmp = root->child;
	x_bound = tmp->box.x;
	y_bound = tmp->box.y;
	tmp = tmp->child->next;
	pvp = tmp;
	p_vs_p_x = tmp->box.x + x_bound;
	p_vs_p_y = tmp->box.y + y_bound;
	heigth = tmp->clip.h;
	width = tmp->clip.w;
	tmp = tmp->next;
	pvc = tmp;
	p_vs_c_x = tmp->box.x + x_bound;
	p_vs_c_y = tmp->box.y + y_bound;
	tmp = tmp->next;
	s_c_width = tmp->clip.w;
	s_c_heigth = tmp->clip.h;
	c_x = tmp->box.x + x_bound;
	c_y = tmp->box.y + y_bound;
	tmp = tmp->next;
	button = tmp;
	start_x = tmp->box.x + x_bound;
	start_y = tmp->box.y + y_bound;

	//replace with Settings
	if (settings.gameMode = SINGLEPLAYER_MODE})
	{
		pvp->clip.x = PV_BUTTON_X;
		pvc->clip.x = PV_S_BUTTON_X;
		button->clip.x = NEXT_ARROW_X;
		
	}
	else
	{
		pvp->clip.x = PV_S_BUTTON_X;
		pvc->clip.x = PV_BUTTON_X;
		button->clip.x = START_ARROW_X;
	}
	blit_tree(root, 0, 0);
	display_screen();
	while (true){

		//todo check SDL_Wait return value for error
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT){
			break;
		}
		else if (event.type == SDL_MOUSEBUTTONUP){
			x = event.button.x;
			y = event.button.y;
			if ((x>p_vs_c_x) && (x<p_vs_c_x + width) && (y>p_vs_c_y) && (y<p_vs_c_y + heigth)){
				settings.gameMode = SINGLEPLAYER_MODE;
				pvp->clip.x = PV_BUTTON_X;
				pvc->clip.x = PV_S_BUTTON_X;
				button->clip.x = NEXT_ARROW_X;
			}
			else if ((x>p_vs_p_x) && (x<p_vs_p_x + width) && (y>p_vs_p_y) && (y<p_vs_p_y + heigth))
			{
				settings.gameMode = MULTIPLYER_MODE;
				pvp->clip.x = PV_S_BUTTON_X;
				pvc->clip.x = PV_BUTTON_X;
				button->clip.x = START_ARROW_X;
			}
			else if ((x>c_x) && (x<c_x + s_c_width) && (y>c_y) && (y<c_y + s_c_heigth))
			{
				freeBoard(settings.board);
				settings = DEFUALT_SETTINGS;
				settings.state = MAIN_MENU_STATE;
				return settings;
			}
			else if ((x>start_x) && (x<start_x + s_c_width) && (y>start_y) && (y<start_y + s_c_heigth)){
				settings.state = CHOOSE_COLOR_STATE;
				return settings;

			else
			{
				continue;
			}
			blit_tree(root, 0, 0);
			display_screen();
		}
	}
	return settings;
}

Settings color_menu_handler(gui_chess root, Settings settings)
{
	SDL_Event event;
	gui_chess tmp, white, black, button_1;
	int x, y, c_x, c_y, s_x, s_y, bound_x, bound_y, cb_x, cb_y, cb_w, cb_h;
	int numb_x, numb_y, numb_w, numb_h, best_w, best_h, s_c_w, s_c_h;

	tmp = root->child;
	bound_x = tmp->box.x;
	bound_y = tmp->box.y;
	tmp = tmp->child->next;
	white = tmp;
	cb_x = tmp->box.x + bound_x;
	cb_y = tmp->box.y + bound_y;
	cb_w = tmp->clip.w;
	cb_h = tmp->clip.h;
	tmp = tmp->next;
	black = tmp;
	tmp = tmp->next->next;
	button_1 = tmp;
	numb_x = tmp->box.x + bound_x;
	numb_y = tmp->box.y + bound_y;
	numb_w = tmp->clip.w;
	numb_h = tmp->clip.h;
	tmp = tmp->next;
	tmp = tmp->next;
	tmp = tmp->next;
	tmp = tmp->next;
	best_w = tmp->clip.w;
	best_h = tmp->clip.h;
	tmp = tmp->next;
	c_x = tmp->box.x + bound_x;
	c_y = tmp->box.y + bound_y;
	s_c_w = tmp->clip.w;
	s_c_h = tmp->clip.h;
	tmp = tmp->next;
	s_x = tmp->box.x + bound_x;
	s_y = tmp->box.y + bound_y;

	if (settings.userColor == WHITE_COLOR)
	{
		white->clip.y = COLOR_S_BUTTON_Y;
		black->clip.y = COLOR_BUTTON_Y;
	}
	else
	{
		white->clip.y = COLOR_BUTTON_Y;
		black->clip.y = COLOR_S_BUTTON_Y;
	}
	blit_tree(root, 0, 0);
	display_screen();
	while (true)
	{
		//check error
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT){
			break;
		}
		else if (event.type == SDL_MOUSEBUTTONUP){
			x = event.button.x;
			y = event.button.y;
			if ((x > (cb_x + COLOR_HORIZONTSL_OFFSET)) && (x<(cb_x + cb_w + COLOR_HORIZONTSL_OFFSET)) && (y>cb_y) && (y < cb_y + cb_h))
			{
				settings.userColor = BLACK_COLOR;
				white->clip.y = COLOR_BUTTON_Y;
				black->clip.y = COLOR_S_BUTTON_Y;
			}
			else if ((x > cb_x) && (x<cb_x + cb_w) && (y>cb_y) && (y < cb_y + cb_h)){
				settings.userColor = WHITE_COLOR;
				white->clip.y = COLOR_S_BUTTON_Y;
				black->clip.y = COLOR_BUTTON_Y;
			}
			else
			{
				continue;
			}
			blit_tree(root, 0, 0);
			display_screen();
		}
	}
	if (settings.gameMode == MULTIPLAYER_MODE)
		settings.state = GAME_STATE;
	else
		settings.state = MODE_SETTINGS_STATE;
	return settings;
}
Settings settings_menu_handler(gui_chess root, Settings settings){
	SDL_Event event;
	gui_chess tmp, white, black, button_1;
	int x, y, c_x, c_y, s_x, s_y, bound_x, bound_y, cb_x, cb_y, cb_w, cb_h;
	int numb_x, numb_y, numb_w, numb_h, best_w, best_h ,s_c_w, s_c_h;

	tmp = root->child;
	bound_x = tmp->box.x;
	bound_y = tmp->box.y;
	tmp = tmp->child->next;
	white = tmp;
	cb_x = tmp->box.x + bound_x;
	cb_y = tmp->box.y + bound_y;
	cb_w = tmp->clip.w;
	cb_h = tmp->clip.h;
	tmp = tmp->next;
	black = tmp;
	tmp = tmp->next->next;
	button_1 = tmp;
	numb_x = tmp->box.x + bound_x;
	numb_y = tmp->box.y + bound_y;
	numb_w = tmp->clip.w;
	numb_h = tmp->clip.h;
	tmp = tmp->next;
	tmp = tmp->next;
	tmp = tmp->next;
	tmp = tmp->next;
	best_w = tmp->clip.w;
	best_h = tmp->clip.h;
	tmp = tmp->next;
	c_x = tmp->box.x + bound_x;
	c_y = tmp->box.y + bound_y;
	s_c_w = tmp->clip.w;
	s_c_h = tmp->clip.h;
	tmp = tmp->next;
	s_x = tmp->box.x + bound_x;
	s_y = tmp->box.y + bound_y;

	if (settings.userColor == WHITE_COLOR)
	{
		white->clip.y = COLOR_S_BUTTON_Y;
		black->clip.y = COLOR_BUTTON_Y;
	}
	else
	{
		white->clip.y = COLOR_BUTTON_Y;
		black->clip.y = COLOR_S_BUTTON_Y;
	}
	if (settings.minimaxDepth == BEST_DEPTH){
		update_num_selction(button_1, 5);
	}
	else{
		update_num_selction(button_1, settings.minimaxDepth);
	}
	blit_tree(root, 0, 0);
	display_screen();

	while (true){
		//check error
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT){
			break;
		}
		else if (event.type == SDL_MOUSEBUTTONUP){
			x = event.button.x;
			y = event.button.y;
			if ((x > (cb_x + COLOR_HORIZONTSL_OFFSET)) && (x<(cb_x + cb_w + COLOR_HORIZONTSL_OFFSET)) && (y>cb_y) && (y < cb_y + cb_h))
			{
				settings.userColor = BLACK_COLOR;
				white->clip.y = COLOR_BUTTON_Y;
				black->clip.y = COLOR_S_BUTTON_Y;
			}
			else if ((x > cb_x) && (x<cb_x + cb_w) && (y>cb_y) && (y < cb_y + cb_h)){
				settings.userColor = WHITE_COLOR;
				white->clip.y = COLOR_S_BUTTON_Y;
				black->clip.y = COLOR_BUTTON_Y;
			}
			else if ((x > numb_x) && (x<numb_x + numb_w) && (y>numb_y) && (y < numb_y + numb_h))
			{
				
				difficulty = 1;
				is_best = 0;
				update_num_selction(button_1, difficulty);
			}
			else if ((x >(numb_x + NUM_HORIZONTAL_OFFSET)) && (x<(numb_x + numb_w+NUM_HORIZONTAL_OFFSET)) && (y>numb_y) && (y < numb_y + numb_h))
			{
				difficulty = 2;
				is_best = 0;
				update_num_selction(button_1, difficulty);
			}
			else if ((x >(numb_x + 2 * NUM_HORIZONTAL_OFFSET)) && (x<(numb_x + numb_w + 2 * NUM_HORIZONTAL_OFFSET)) && (y>numb_y) && (y < numb_y + numb_h))
			{
				difficulty = 3;
				is_best = 0;
				update_num_selction(button_1, difficulty);
			}
			else if ((x >(numb_x + 3 * NUM_HORIZONTAL_OFFSET)) && (x<(numb_x + numb_w + 3 * NUM_HORIZONTAL_OFFSET)) && (y>numb_y) && (y < numb_y + numb_h))
			{
				difficulty = 4;
				is_best = 0;
				update_num_selction(button_1, difficulty);
			}
			else if ((x >(numb_x + 4 * NUM_HORIZONTAL_OFFSET)) && (x<(numb_x + best_w + 4 * NUM_HORIZONTAL_OFFSET)) && (y>numb_y) && (y < numb_y + best_h))
			{
				difficulty = 4;
				is_best = 1;
				update_num_selction(button_1, 5);
			}
			else if ((x > c_x) && (x<c_x + s_c_w) && (y>c_y) && (y < c_y + s_c_h))
			{
				return MODE_MENU;
			}
			else if ((x > s_x) && (x<s_x + s_c_w) && (y>s_y) && (y < s_y + s_c_h))
			{
				return GAME_MENU;
			}
			else
			{
				continue;
			}
			blit_tree(root, 0, 0);
			display_screen();
		}
	}
	return QUIT;
}

int load_save_menu_handler(gui_chess root, int op){
	SDL_Event event;
	gui_chess tmp, button_1;
	char mem_slot[MEM_SLOT_FILE_NAME_LENGTH];
	int x, y, bound_x, bound_y, number_x, number_y, width, heigth, s_l_x, s_l_y, c_x, c_y, ch_x, ch_y;
	int current_slot = 0,save_status;

	tmp = root->child;
	bound_x = tmp->box.x;
	bound_y = tmp->box.y;
	tmp = tmp->child->next;
	button_1 = tmp;
	number_x = tmp->box.x + bound_x;
	number_y = tmp->box.y + bound_y;
	heigth = tmp->clip.h;
	width = tmp->clip.w;
	tmp = tmp->next;
	tmp = tmp->next;
	tmp = tmp->next;
	tmp = tmp->next;
	tmp = tmp->next;
	s_l_x = tmp->clip.w;
	s_l_y = tmp->clip.h;
	c_x = tmp->box.x + bound_x;
	c_y = tmp->box.y + bound_y;
	tmp = tmp->next;
	ch_x = tmp->box.x + bound_x;
	ch_y = tmp->box.y + bound_y;
	
	update_num_selction(button_1, current_slot);

	blit_tree(root, 0, 0);
	display_screen();
	while (true){

		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT){
			return QUIT;
		}
		else if (event.type == SDL_MOUSEBUTTONUP){
			x = event.button.x;
			y = event.button.y;
			if ((x > number_x) && (x<(number_x + width)) && (y>number_y) && (y<(number_y + heigth))){
				current_slot = 1;
			}
			else if ((x>(number_x + NUM_HORIZONTAL_OFFSET)) && (x<(number_x + NUM_HORIZONTAL_OFFSET + width)) && (y>number_y) && (y<(number_y + heigth)))
			{
				current_slot = 2;
			}
			else if ((x>(number_x + 2 * NUM_HORIZONTAL_OFFSET)) && (x<(number_x + 2 * NUM_HORIZONTAL_OFFSET + width)) && (y>number_y) && (y<number_y + heigth))
			{
				current_slot = 3;
			}
			else if ((x>(number_x + 3 * NUM_HORIZONTAL_OFFSET)) && (x<(number_x + 3 * NUM_HORIZONTAL_OFFSET + width)) && (y>number_y) && (y<number_y + heigth))
			{
				current_slot = 4;
			}
			else if ((x>(number_x + 4 * NUM_HORIZONTAL_OFFSET)) && (x<(number_x + 4 * NUM_HORIZONTAL_OFFSET + width)) && (y>number_y) && (y<number_y + heigth))
			{
				current_slot = 5;
			}
			else if ((x>c_x) && (x<c_x + s_l_x) && (y>c_y) && (y<c_y + s_l_y)){
				if (op){
					return -1;
				}
				else{
					return MAIN_MENU;
				}
			}
			/*choose button selected*/
			else if ((x>ch_x) && (x<ch_x + s_l_x) && (y>ch_y) && (y < ch_y + s_l_y)){
				switch (current_slot)
					{
				case 1:
					strcpy(mem_slot,MEM_SLOT_1);
					break;
				case 2:
					strcpy(mem_slot, MEM_SLOT_2);
					break;
				case 3:
					strcpy(mem_slot, MEM_SLOT_3);
					break;
				case 4:
					strcpy(mem_slot, MEM_SLOT_4);
					break;
				case 5:
					strcpy(mem_slot, MEM_SLOT_5);
					break;
				default:
					continue;
					break;
				}

				/*op=1 "save"*/
				if (op){
					if (now_playing == WHITE){
						//TODO save settings to XML
						save_status=save(mem_slot, "White");
					}
					else{
						save_status=save(mem_slot, "Black");
					}
					if (save_status){
						apply_surface(SAVE_SUCCEED_LABEL_PMT, pieces_sheet, screen);
					}
					else{
						apply_surface(SAVE_FAILED_LABEL_PMT, pieces_sheet, screen);
					}
					display_screen();
					SDL_Delay(3000);
					return -1;
					/*show massage of saving status*/
				}
				else{
					//todo reolace with loadSettings from XML
					if (load(mem_slot)){
						return MODE_MENU;
					}
					apply_surface(LOAD_FAILED_LABEL_PMT, pieces_sheet, screen);
					display_screen();
					SDL_Delay(3000);
					return LOAD_MENU;
				}
			}
			else{
				continue;
			}
			update_num_selction(button_1, current_slot);
			blit_tree(root, 0, 0);
			display_screen();
		}
	}
	return QUIT;
}

int game_menu_handler(gui_chess game_menu, gui_chess save_menu)
{
	int situation,pos[4];
	gui_chess tmp;

	tmp = game_menu;
	tmp = tmp->child;
	pos[0] = tmp->box.x;
	pos[1] = tmp->box.y;
	pos[2] = tmp->clip.w;
	pos[3] = tmp->clip.h;
	
	display_board(game_menu, -1, -1,board);
	/* p vs c */
	if (play_mode == 0){
		if (now_playing == u_color)
		{
			situation = gui_player_turn(u_color, pos, game_menu, save_menu);
			if (situation >= 0){
				return situation;
			}
			if (now_playing == BLACK)
			{
				now_playing = WHITE;
			}
			else
			{
				now_playing = BLACK;
			}
		}
		while (true){
			situation = gui_computer_turn(game_menu);
			if (now_playing == BLACK)
			{
				now_playing = WHITE;
			}
			else
			{
				now_playing = BLACK;
			}
			if (situation >= 0)
			{
				return situation;
			}
			situation = gui_player_turn(u_color, pos, game_menu, save_menu);
			if (situation >= 0){
				return situation;
			}
			if (now_playing == BLACK)
			{
				now_playing = WHITE;
			}
			else
			{
				now_playing = BLACK;
			}
		}
	}
	/*p vs p */
	if (play_mode == 1){
		while (TRUE){
			situation = gui_player_turn(now_playing, pos, game_menu, save_menu);
			if (situation >= 0)
			{
				return situation;
			}
			if (now_playing == BLACK)
			{
				now_playing = WHITE;
			}
			else
			{
				now_playing = BLACK;
			}
		}
	}
	
	return QUIT;
}

void promotion_handler(gui_chess root, char promote_to[7]){
	gui_chess tmp;
	SDL_Event event;
	int x, y, x_bound, y_bound;

	blit_tree(root, 0, 0);
	display_screen();

	tmp = root->child;
	x_bound = tmp->box.x + PROMOTE_FIRST_POS_X;
	y_bound = tmp->box.y + PROMOTE_FIRST_POS_Y;
	
	while (true){
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT){
			break;
		}
		else if (SDL_GetMouseState(&x, &y) & SDL_BUTTON_LMASK) {
			if ((y > y_bound) && (y < (y_bound + BOARD_SQUARE))){
				if ((x > x_bound) && (x<(x_bound + BOARD_SQUARE))){
					strcpy(promote_to, "queen");
					return;
				}
				if ((x >(x_bound + PROMOTE_OFFSET)) && (x<(x_bound + BOARD_SQUARE + PROMOTE_OFFSET))){
					strcpy(promote_to, "rook");
					return;
				}
				if ((x >(x_bound + 2 * PROMOTE_OFFSET)) && (x<(x_bound + BOARD_SQUARE + 2 * PROMOTE_OFFSET))){
					strcpy(promote_to, "bishop");
					return;
				}
				if ((x >(x_bound + 3 * PROMOTE_OFFSET)) && (x < (x_bound + BOARD_SQUARE + 3 * PROMOTE_OFFSET))){
					strcpy(promote_to, "knight");
					return;
				}
			}
		}
	}
}

void blit_tree(gui_chess start_point, int x, int y)
{
	gui_chess tmp;
	SDL_Rect place_in_frame;

	/*terminal case root->parent is a leaf*/
	if (start_point == NULL)
	{
		return;
	}

	if (start_point->parent != NULL)
	{
		place_in_frame.x = start_point->box.x + x;
		place_in_frame.y = start_point->box.y + y;
		SDL_BlitSurface(start_point->img, &(start_point->clip), screen, &place_in_frame);
		
	}
	else
	{
		place_in_frame.x = x;
		place_in_frame.y = y;
		SDL_BlitSurface(start_point->img, NULL, screen, NULL);
	}

	tmp = start_point->child;

	while (tmp != NULL){
		blit_tree(tmp, place_in_frame.x, place_in_frame.y);
		tmp = tmp->next;
	}
}

void update_num_selction(gui_chess number_button, int number)
{
	gui_chess tmp;
	int i;
	tmp = number_button;

	//max save slots = 5
	for (i = 1; i < 6; i++)
	{
		if (i != number)
		{
			tmp->clip.y = NUM_BUTTON_Y;
		}
		else
		{
			tmp->clip.y = NUM_S_BUTTON_Y;
		}
		tmp = tmp->next;
	}
}

void display_board(gui_chess game_menu, int selected_x, int selected_y, char** current_board)
{
	int i, j, x, y;
	SDL_Surface *current_surface;

	current_surface = pieces_sheet;
	i = 0;
	j = 0;

	blit_tree(game_menu, i, j);

	for (i = 0 ; i < BOARD_SIZE; i++)
	{
		for (j = 0 ; j < BOARD_SIZE; j++)
		{
			x = i*BOARD_SQUARE + BOARD_TOP_CORNER;
			y = (7 - j)*BOARD_SQUARE + BOARD_TOP_CORNER;
			if (selected_x != i || selected_y != j)
			{
				current_surface = pieces_sheet; // just solider on the board
			}
			else
			{
				current_surface = selected_pieces_sheet; // selsected solider on the board
			}
			switch (current_board[i][j])
			{
			case W_PAWN:
				apply_surface(W_PAWN_PMT, x, y, current_surface, screen);
				break;
			case W_BISHOP:
				apply_surface(W_BISHOP_PMT, x, y, current_surface, screen);
				break;
			case W_ROOK:
				apply_surface(W_ROOK_PMT, x, y, current_surface, screen);
				break;
			case W_KNIGHT:
				apply_surface(W_KNIGHT_PMT, x, y, current_surface, screen);
				break;
			case W_QUEEN:
				apply_surface(W_QUEEN_PMT, x, y, current_surface, screen);
				break;
			case W_KING:
				apply_surface(W_KING_PMT, x, y, current_surface, screen);
				break;
			case B_PAWN:
				apply_surface(B_PAWN_PMT, x, y, current_surface, screen);
				break;
			case B_BISHOP:
				apply_surface(B_BISHOP_PMT, x, y, current_surface, screen);
				break;
			case B_ROOK:
				apply_surface(B_ROOK_PMT, x, y, current_surface, screen);
				break;
			case B_KNIGHT:
				apply_surface(B_KNIGHT_PMT, x, y, current_surface, screen);
				break;
			case B_QUEEN:
				apply_surface(B_QUEEN_PMT, x, y, current_surface, screen);
				break;
			case B_KING:
				apply_surface(B_KING_PMT, x, y, current_surface, screen);
				break;
			default:
				break;
			}
		}
	}
	display_screen();
}