#include "Handlers.h"

Settings main_menu_handler(gui_chess gui_window, Settings settings)
{
	gui_chess tmp;
	SDL_Event event;
	int mouse_x, mouse_y, x_bound, y_bound, width, heigth;

	show_on_screen(gui_window, 0, 0);
	display_screen();
	
	//todo etract to function
	/*define & find bounderies of the buttons*/
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
			settings.can_set = 1;
			if ((mouse_x > x_bound) && (mouse_x<(x_bound + width)) && (mouse_y>y_bound) && (mouse_y < (y_bound + heigth)))
			{ /* new game*/
				settings.state = MODE_SETTINGS_STATE;
				quitting = true;
				return settings;
			}
			if ((mouse_x > x_bound) && (mouse_x<(x_bound + width)) && (mouse_y>(y_bound + MAIN_MENU_BUTTONS_HEIGH)) && (mouse_y < (y_bound + MAIN_MENU_BUTTONS_HEIGH + heigth)))
			{ /* load game*/
				settings.state = LOAD_STATE;
				quitting = true;
                settings.can_set = 1;
				return settings;
			}
			if ((mouse_x > x_bound) && (mouse_x<(x_bound + width)) && (mouse_y>(y_bound + 2 * MAIN_MENU_BUTTONS_HEIGH)) && (mouse_y < (y_bound + 2 * MAIN_MENU_BUTTONS_HEIGH + heigth)))
			{ /* quit game*/
				settings.state = TERMINATE_STATE;
				quitting = true;
				return settings;
			}
		}
		if (event.type == SDL_QUIT)
		{
			settings.state = TERMINATE_STATE;
			quitting = true;
			return settings;
		}
	}
	return settings;
}

Settings mode_menu_handler(gui_chess root, Settings settings)
{
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

	if (settings.gameMode == SINGLEPLAYER_MODE)
	{
		pvp->clip.x = MODE_BUTTON_X_SRC;
		pvc->clip.x = MODE_BUTTON_SELECT_X_SRC;
		button->clip.x = NEXT_BUTTON_X_SRC;
		
	}
	else
	{
		pvp->clip.x = MODE_BUTTON_SELECT_X_SRC;
		pvc->clip.x = MODE_BUTTON_X_SRC;
		button->clip.x = STRAT_BUTTON_X_SRC;
	}
	show_on_screen(root, 0, 0);
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
			if ((x>p_vs_c_x) && (x<p_vs_c_x + width) && (y>p_vs_c_y) && (y<p_vs_c_y + heigth))
			{
				settings.gameMode = SINGLEPLAYER_MODE;
				pvp->clip.x = MODE_BUTTON_X_SRC;
				pvc->clip.x = MODE_BUTTON_SELECT_X_SRC;
				button->clip.x = NEXT_BUTTON_X_SRC;
			}
			else if ((x>p_vs_p_x) && (x<p_vs_p_x + width) && (y>p_vs_p_y) && (y<p_vs_p_y + heigth))
			{
				settings.gameMode = MULTIPLAYER_MODE;
				pvp->clip.x = MODE_BUTTON_SELECT_X_SRC;
				pvc->clip.x = MODE_BUTTON_X_SRC;
				button->clip.x = STRAT_BUTTON_X_SRC;
			}
			// 3.10
			else if ( ( x >= 183 ) && ( x <= 266 ) && ( y >= 413 ) && ( y <= 465 ) )
			{
				//freeBoard(settings.board);
				//settings = (Settings) DEFAULT_SETTINGS;
				settings.state = MAIN_MENU_STATE;
				return settings;
			}
			else if ( ( x >= 523 ) && ( x <= 606 ) && ( y >= 413 ) && ( y <= 465 ) )
			{
				//freeBoard(settings.board);
				//settings = (Settings) DEFAULT_SETTINGS;
				settings.state = CHOOSE_COLOR_STATE;
				return settings;
			}
			else
			{
				continue;
			}
			show_on_screen(root, 0, 0);
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
	int numb_x, numb_y, numb_w, numb_h, s_c_w, s_c_h;

	/*define & find bounderies of the buttons*/
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
	c_x = tmp->box.x + bound_x;
	c_y = tmp->box.y + bound_y;
	s_c_w = tmp->clip.w;
	s_c_h = tmp->clip.h;
	s_x = tmp->box.x + bound_x;
	s_y = tmp->box.y + bound_y;

	if (settings.userColor == WHITE_COLOR)
	{
		white->clip.y = SELECT_COLOR_BUTTON_Y_SRC;
		black->clip.y = COLOR_BUTTON_Y_SRC;
	}
	else
	{
		white->clip.y = COLOR_BUTTON_Y_SRC;
		black->clip.y = SELECT_COLOR_BUTTON_Y_SRC;
	}
	show_on_screen(root, 0, 0);
	display_screen();
	while (true)
	{
		//todo check error
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT){
			break;
		}
		else if (event.type == SDL_MOUSEBUTTONUP){
			x = event.button.x;
			y = event.button.y;
			if ((x > (cb_x + COLOR_BUTTON_OFFSET_HORIZ)) && (x<(cb_x + cb_w + COLOR_BUTTON_OFFSET_HORIZ)) && (y>cb_y) && (y < cb_y + cb_h))
			{
				// 3.10
				//settings.userColor = BLACK_COLOR;
				settings.playingColor = BLACK_COLOR;
				white->clip.y = COLOR_BUTTON_Y_SRC;
				black->clip.y = SELECT_COLOR_BUTTON_Y_SRC;
			}
			else if ((x > cb_x) && (x<cb_x + cb_w) && (y>cb_y) && (y < cb_y + cb_h))
			{
				// 3.10
				//settings.userColor = WHITE_COLOR;
				settings.playingColor = WHITE_COLOR;
				white->clip.y = SELECT_COLOR_BUTTON_Y_SRC;
				black->clip.y = COLOR_BUTTON_Y_SRC;
			}
			else if ( ( x >= 523 ) && ( x <= 606 ) && ( y >= 413 ) && ( y <= 465 ) )
			{
				if (settings.gameMode == MULTIPLAYER_MODE)
				{
					settings.state = GAME_STATE;
					return settings;
					
				}
				else if (settings.gameMode == SINGLEPLAYER_MODE)
				{
					settings.state = SETTINGS_STATE;
					return settings;
				}
			}
			// cancel
			else if ( ( x >= 183 ) && ( x <= 266 ) && ( y >= 413 ) && ( y <= 465 ) )
			{
				settings.state = MODE_SETTINGS_STATE;
				return settings;
				
			}
			else
			{
				continue;
			}
			show_on_screen(root, 0, 0);
			display_screen();
		}
	}
	
	return settings;
}

Settings settings_menu_handler(gui_chess root, Settings settings){
	SDL_Event event;
	gui_chess tmp, white, black, button_1;
	int x, y, c_x, c_y, s_x, s_y, bound_x, bound_y, cb_x, cb_y, cb_w, cb_h;
	int numb_x, numb_y, numb_w, numb_h, best_w, best_h ,s_c_w, s_c_h;

	/*define & find bounderies of the buttons*/
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
		white->clip.y = SELECT_COLOR_BUTTON_Y_SRC;
		black->clip.y = COLOR_BUTTON_Y_SRC;
	}
	else
	{
		white->clip.y = COLOR_BUTTON_Y_SRC;
		black->clip.y = SELECT_COLOR_BUTTON_Y_SRC;
	}
	if (settings.minimaxDepth == BEST_DEPTH){
		select_number_button(button_1, 5);
	}
	else{
		select_number_button(button_1, settings.minimaxDepth);
	}
	show_on_screen(root, 0, 0);
	display_screen();

	while (true){
		//check error
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT){
			settings.state = TERMINATE_STATE;
			break;
		}
		else if (event.type == SDL_MOUSEBUTTONUP){
			x = event.button.x;
			y = event.button.y;
			if ((x > (cb_x + COLOR_BUTTON_OFFSET_HORIZ)) && (x<(cb_x + cb_w + COLOR_BUTTON_OFFSET_HORIZ)) && (y>cb_y) && (y < cb_y + cb_h))
			{
				settings.userColor = BLACK_COLOR;
				white->clip.y = COLOR_BUTTON_Y_SRC;
				black->clip.y = SELECT_COLOR_BUTTON_Y_SRC;
			}
			else if ((x > cb_x) && (x<cb_x + cb_w) && (y>cb_y) && (y < cb_y + cb_h)){
				settings.userColor = WHITE_COLOR;
				white->clip.y = SELECT_COLOR_BUTTON_Y_SRC;
				black->clip.y = COLOR_BUTTON_Y_SRC;
			}
			else if ((x > numb_x) && (x<numb_x + numb_w) && (y>numb_y) && (y < numb_y + numb_h))
			{
				settings.minimaxDepth = 1;
				select_number_button(button_1, settings.minimaxDepth);
			}
			else if ((x >(numb_x + BUTTON_NUMBER_OFFSET_HORIZ)) && (x<(numb_x + numb_w+BUTTON_NUMBER_OFFSET_HORIZ)) && (y>numb_y) && (y < numb_y + numb_h))
			{
				settings.minimaxDepth = 2;
				select_number_button(button_1, settings.minimaxDepth);
			}
			else if ((x >(numb_x + 2 * BUTTON_NUMBER_OFFSET_HORIZ)) && (x<(numb_x + numb_w + 2 * BUTTON_NUMBER_OFFSET_HORIZ)) && (y>numb_y) && (y < numb_y + numb_h))
			{
				settings.minimaxDepth = 3;
				select_number_button(button_1, settings.minimaxDepth);
			}
			else if ((x >(numb_x + 3 * BUTTON_NUMBER_OFFSET_HORIZ)) && (x<(numb_x + numb_w + 3 * BUTTON_NUMBER_OFFSET_HORIZ)) && (y>numb_y) && (y < numb_y + numb_h))
			{
				settings.minimaxDepth = 4;
				select_number_button(button_1, settings.minimaxDepth);
			}
			else if ((x >(numb_x + 4 * BUTTON_NUMBER_OFFSET_HORIZ)) && (x<(numb_x + best_w + 4 * BUTTON_NUMBER_OFFSET_HORIZ)) && (y>numb_y) && (y < numb_y + best_h))
			{
				settings.minimaxDepth = BEST_DEPTH;
				select_number_button(button_1, 5);
			}
			else if ( ( x >= 183 ) && ( x <= 266 ) && ( y >= 413 ) && ( y <= 465 ) )
			{
				settings.state = CHOOSE_COLOR_STATE;
				return settings;
			}
			else if ( ( x >= 523 ) && ( x <= 606 ) && ( y >= 413 ) && ( y <= 465 ) )
			{
				settings.state = GAME_STATE;
				return settings;
			}
			else
			{
				continue;
			}
			show_on_screen(root, 0, 0);
			display_screen();
		}
	}
	return settings;
}

Settings load_save_menu_handler(gui_chess root, Settings settings){
	SDL_Event event;
	gui_chess tmp, button_1;
	char mem_slot[MEM_SLOT_FILE_NAME_LENGTH];
	int x, y, bound_x, bound_y, number_x, number_y, width, heigth, s_l_x, s_l_y, c_x, c_y, ch_x, ch_y;
	int current_slot = 0;

	/*define & find bounderies of the buttons*/
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
	
	select_number_button(button_1, current_slot);

	show_on_screen(root, 0, 0);
	display_screen();
	while (true){

		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT){
			settings.state = TERMINATE_STATE;
			return settings;
		}
		else if (event.type == SDL_MOUSEBUTTONUP){
			x = event.button.x;
			y = event.button.y;
			if ((x > number_x) && (x<(number_x + width)) && (y>number_y) && (y<(number_y + heigth))){
				current_slot = 1;
			}
			else if ((x>(number_x + BUTTON_NUMBER_OFFSET_HORIZ)) && (x<(number_x + BUTTON_NUMBER_OFFSET_HORIZ + width)) && (y>number_y) && (y<(number_y + heigth)))
			{
				current_slot = 2;
			}
			else if ((x>(number_x + 2 * BUTTON_NUMBER_OFFSET_HORIZ)) && (x<(number_x + 2 * BUTTON_NUMBER_OFFSET_HORIZ + width)) && (y>number_y) && (y<number_y + heigth))
			{
				current_slot = 3;
			}
			else if ((x>(number_x + 3 * BUTTON_NUMBER_OFFSET_HORIZ)) && (x<(number_x + 3 * BUTTON_NUMBER_OFFSET_HORIZ + width)) && (y>number_y) && (y<number_y + heigth))
			{
				current_slot = 4;
			}
			else if ((x>(number_x + 4 * BUTTON_NUMBER_OFFSET_HORIZ)) && (x<(number_x + 4 * BUTTON_NUMBER_OFFSET_HORIZ + width)) && (y>number_y) && (y<number_y + heigth))
			{
				current_slot = 5;
			}
			else if ((x>(number_x + 5 * BUTTON_NUMBER_OFFSET_HORIZ)) && (x<(number_x + 5 * BUTTON_NUMBER_OFFSET_HORIZ + width)) && (y>number_y) && (y<number_y + heigth))
			{
				current_slot = 6;
			}
			else if ((x>(number_x + 6 * BUTTON_NUMBER_OFFSET_HORIZ)) && (x<(number_x + 6 * BUTTON_NUMBER_OFFSET_HORIZ + width)) && (y>number_y) && (y<number_y + heigth))
			{
				current_slot = 7;
			}
			//cancel
			else if ( ( x >= 183 ) && ( x <= 266 ) && ( y >= 413 ) && ( y <= 465 ) )
			{
				if (settings.state == SAVE_STATE)
				{
					settings.state = GAME_STATE;
					return settings;
				}
				else
				{
					settings.state = MAIN_MENU_STATE;
					return settings;
				}
			}
			
			/*choose button selected*/
			else if ( ( x >= 523 ) && ( x <= 606 ) && ( y >= 413 ) && ( y <= 465 ) )
			{
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
				case 6:
					strcpy(mem_slot, MEM_SLOT_6);
					break;
				case 7:
					strcpy(mem_slot, MEM_SLOT_7);
					break;
				default:
					continue;
					break;
                    };

				/*op=1 "save"*/
				if (settings.state == SAVE_STATE)
				{
					saveSettings(settings, mem_slot);
					settings.state = GAME_STATE;
                    if (settings.can_set == 1)
                        settings.can_set = 1;
                    else
                        settings.can_set = 0;
					// 3.10
					//settings.can_set = 0; // can NOT set any more
					return settings;
				}
				else 
				{
					settings = loadSettings(settings, mem_slot);
					// 3.10
					settings.can_set = 1; // can set after load
					settings.state = MODE_SETTINGS_STATE;
					return settings;
				}
			}
			else
			{
				continue;
			}
			select_number_button(button_1, current_slot);
			show_on_screen(root, 0, 0);
			display_screen();
		}
	}
	return settings;
}

Settings game_menu_handler(gui_chess game_menu, gui_chess save_menu, Settings settings)
{
	int offsets[4], x, y;
	gui_chess tmp;
	SDL_Event event;
	tmp = game_menu;
	tmp = tmp->child;
	//todo replace pos with meaningful struct/existing data. used combination of box+clip is not clear.
	offsets[0] = tmp->box.x;
	offsets[1] = tmp->box.y;
	offsets[2] = tmp->clip.w;
	offsets[3] = tmp->clip.h;
	
	display_board(game_menu, -1, -1,settings.board);

	while (settings.can_set)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT){
			settings.state = TERMINATE_STATE;
			return settings;
		}
		else if (event.type == SDL_MOUSEBUTTONUP)
		{			
			x = event.button.x;
			y = event.button.y;
			fprintf(stdout,"x = %d\n",x);
			fprintf(stdout,"y = %d\n",y);
			fflush(stdout);
			if (player_clicked_set(x,y,offsets))
			{ /* set button was selected */
				//set = 0;
				fprintf(stdout,"%s\n","game_handler -- set");
				fflush(stdout);
				settings.state = SET_MENU;
				return settings;
			}
			else if (player_clicked_start(x,y,offsets))
			{ /* start button was selected */
					fprintf(stdout,"%s\n","game_handler -- start");
					fflush(stdout);
					if (countPiecesOfType(settings.board, WHITE_K) != 1 ||
						countPiecesOfType(settings.board, BLACK_K) != 1)
					{	//todo - add correct illegal board message
						apply_surface(CHECKMATE_LABEL, getImage(SELECTED_PIECES_SHEET), get_screen());
						SDL_Delay(2500);
					}
					else 
					{
						settings.can_set = 0;
						settings.show_hint = 1;
					}
					continue;
			}
			else if (player_clicked_restart(x, y, offsets))
				{
					fprintf(stdout,"%s\n","game_handler -- hint");
					fflush(stdout);
					if (settings.show_hint == 1)
					{
						int situation = gui_player_turn(settings, offsets, game_menu, save_menu);
						settings = end_of_turn(settings, situation, game_menu);
						break;
					}
					else
					{
						apply_surface(CAN_NOT_GIVE_HINT_MES, getImage(LOAD_SAVE), get_screen());
						display_screen();
						SDL_Delay(2500);
						display_board(game_menu, -1,-1, settings.board);
						display_screen();
						continue;
					}
			}
			else if (player_clicked_quit(x, y, offsets))
			{
				fprintf(stdout,"%s\n","game_handler -- quit");
				fflush(stdout);
				settings.state = TERMINATE_STATE;
				return settings;
			}
			else if (player_clicked_save(x, y, offsets))
			{
				fprintf(stdout,"%s\n","game_handler -- save");
				fflush(stdout);
				settings.state = SAVE_STATE;
                fprintf(stdout,"can_set = %d\n",settings.can_set);
				return settings;
			}
			else if (player_clicked_main_menu(x, y, offsets))
			{
				fprintf(stdout,"%s\n","game_handler -- main_menu");
				fflush(stdout);
				settings.state = MAIN_MENU_STATE;
				return settings;
			}
			else
			{
				fprintf(stdout,"%s\n","game_handler -- contionu");
				fflush(stdout);
				continue;
			}
		}
	}
	while (settings.state == GAME_STATE) {
		int situation = settings.gameMode == MULTIPLAYER_MODE || settings.userColor == settings.playingColor
			? gui_player_turn(settings, offsets, game_menu, save_menu)
			: gui_computer_turn(settings, game_menu);
		settings = end_of_turn(settings, situation, game_menu);

	}
	//show_on_screen(game_menu, 0, 0);
	//display_screen();
	
	return settings;
}

Settings cancel_after_best_move(Settings settings)
{
	if (settings.playingColor == WHITE_COLOR)
	{
		settings.playingColor = BLACK_COLOR;
	}
	else
	{
		settings.playingColor = WHITE_COLOR;
	}
	settings.state = GAME_STATE;
	return settings;
}

Settings minimax_menu_handler(gui_chess root, Settings settings)
{
	SDL_Event event;
	gui_chess tmp, white, black, button_1;
	int x, y, c_x, c_y, s_x, s_y, bound_x, bound_y, cb_x, cb_y, cb_w, cb_h;
	int numb_x, numb_y, numb_w, numb_h, best_w, best_h ,s_c_w, s_c_h;
	
	/*define & find bounderies of the buttons*/
	tmp = root->child;
	bound_x = tmp->box.x;
	bound_y = tmp->box.y;
	tmp = tmp->child->next;
	white = tmp;
	cb_x = tmp->box.x + bound_x;
	cb_y = tmp->box.y + bound_y;
	cb_w = tmp->clip.w;
	cb_h = tmp->clip.h;
	//tmp = tmp->next;
	//black = tmp;
	//tmp = tmp->next->next;
	button_1 = tmp;
	numb_x = tmp->box.x + bound_x;
	numb_y = tmp->box.y + bound_y;
	numb_w = tmp->clip.w;
	numb_h = tmp->clip.h;
	//tmp = tmp->next;
	//tmp = tmp->next;
	//tmp = tmp->next;
	//tmp = tmp->next;
	best_w = tmp->clip.w;
	best_h = tmp->clip.h;
	//tmp = tmp->next;
	c_x = tmp->box.x + bound_x;
	c_y = tmp->box.y + bound_y;
	s_c_w = tmp->clip.w;
	s_c_h = tmp->clip.h;
	tmp = tmp->next;
	s_x = tmp->box.x + bound_x;
	s_y = tmp->box.y + bound_y;

	if (settings.minimaxDepth == BEST_DEPTH){
		select_number_button(button_1, 5);
	}
	else{
		select_number_button(button_1, settings.minimaxDepth);
	}
	
    
	show_on_screen(root, 0, 0);
	display_screen();
    fprintf(stdout,"%s\n","soso");
	while (true){
		//check error
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT){
			settings.state = TERMINATE_STATE;
			break;
		}
		else if (event.type == SDL_MOUSEBUTTONUP){
			x = event.button.x;
			y = event.button.y;
            if ( ( x > 241) && ( x < 284) && (y > 343) && (y < 394)  )
			{
                
				settings.minimaxDepth = 1;
				select_number_button(button_1, settings.minimaxDepth);
                fprintf(stdout,"minimax_defth = %d\n",settings.minimaxDepth);
			}
            else if ((x > 300) && (x<344) && (y>342) && (y < 394))
			{
				settings.minimaxDepth = 2;
				select_number_button(button_1, settings.minimaxDepth);
                fprintf(stdout,"minimax_defth = %d\n",settings.minimaxDepth);
			}
            else if ((x > 361) && (x<403) && (y>342) && (y < 394))
			{
				settings.minimaxDepth = 3;
				select_number_button(button_1, settings.minimaxDepth);
                fprintf(stdout,"minimax_defth = %d\n",settings.minimaxDepth);
			}
            else if ((x > 421) && (x<463) && (y>342) && (y < 394))
			{
				settings.minimaxDepth = 4;
				select_number_button(button_1, settings.minimaxDepth);
                fprintf(stdout,"minimax_defth = %d\n",settings.minimaxDepth);
			}
            else if ((x > 483) && (x<553) && (y>342) && (y < 394))
			{
				settings.minimaxDepth = BEST_DEPTH;
				select_number_button(button_1, 5);
                fprintf(stdout,"minimax_defth = %d\n",settings.minimaxDepth);
			}
	
			else if ((x > 181) && (x<267) && (y>411) && (y < 467))
			{
                settings.state = CANCEL_BEST_MOVE;
                return settings;
			}
			else if ((x > 521) && (x<608) && (y>411) && (y < 467))
			{
                settings.state = BEST_MOVE;
                return settings;
				
			}
			else
			{
				continue;
			}
			show_on_screen(root, 0, 0);
			display_screen();
		}
	}
	return settings;

}
Settings set_menu_handler(gui_chess root, gui_chess game_menu, gui_chess save_menu, Settings settings)
{
	SDL_Event event;
	int x, y, i, j, x2, y2, x_bound, y_bound, offsets[4];
	gui_chess tmp, tmp2;
	
	tmp2 = root->child;
	x_bound = tmp2->box.x + PROMOTE_X;
	y_bound = tmp2->box.y + PROMOTE_Y;
	tmp = game_menu;
	tmp = tmp->child;
	offsets[0] = tmp->box.x;
	offsets[1] = tmp->box.y;
	offsets[2] = tmp->clip.w;
	offsets[3] = tmp->clip.h;
	
	while (true)
	{
		SDL_WaitEvent(&event);//todo - check return value
		if (event.type == SDL_QUIT){
			settings.state = TERMINATE_STATE;
			return settings;
		}
		else if (event.type == SDL_MOUSEBUTTONUP)
		{			
			x2 = event.button.x;
			y2 = event.button.y;
			if (( x2 > 34) && ( x2 < 561) && (y2 < 561) && ( y2 > 35) ) 
			{
				i = (x2 - BOARD_TOP_CORNER) / BOARD_SQUARE_LEN;
				j = 7 - ((y2 - BOARD_TOP_CORNER) / BOARD_SQUARE_LEN);
			fprintf(stdout,"%s\n","check");
			fprintf(stdout,"x2 = %d\n",x2);
			fprintf(stdout,"y2 = %d\n",y2);
			fprintf(stdout,"i = %d\n",i);
			fprintf(stdout,"j = %d\n",j);
			fflush(stdout);
			show_on_screen(root, 0, 0);
			display_screen();
			while (i >= 0 && j >= 0 && i < BOARD_SIZE && j < BOARD_SIZE)
				{
				SDL_WaitEvent(&event);
				if (event.type == SDL_QUIT){
					settings.state = TERMINATE_STATE;
					return settings;
				}
				else if (event.type == SDL_MOUSEBUTTONUP)
				{
					fprintf(stdout,"%s\n","check 1");
					fflush(stdout);
						x = event.button.x;
						y = event.button.y;
						if (x >= x_bound - 3 * BOARD_SQUARE_LEN && x <= x_bound - 3 * 66 + 7 * PROMOTE_OFFSET)
						{
							settings.board = set_piece(x, y, x_bound, y_bound, i, j, settings.board);
							display_board(game_menu, -1, -1,settings.board);
							settings.state = GAME_STATE;
							return settings;
						}
					}
					else
					{
						continue;
					}
				}
			}
			else if (player_clicked_start(x2,y2,offsets))
			{ /* start button was selected */
					fprintf(stdout,"%s\n","game_handler -- start");
					fflush(stdout);
					settings.can_set = 0;
					settings.show_hint = 1;
					settings.state = GAME_STATE;
					return settings;
			}
			else if (player_clicked_restart(x2, y2, offsets))//todo - change any var/func name with restart to hint
				{
					fprintf(stdout,"%s\n","set_handler -- hint");
					fflush(stdout);
					if (settings.show_hint == 1)
					{
						settings.state = BEST_MOVE;
						return settings;
					}
					else
					{
						apply_surface(CAN_NOT_GIVE_HINT_MES, getImage(LOAD_SAVE), get_screen());
						display_screen();
						SDL_Delay(2500);
						display_board(game_menu, -1,-1, settings.board);
						display_screen();
						if (settings.playingColor == WHITE_COLOR)
						{
							settings.playingColor = BLACK_COLOR;
						}
						else
						{
							settings.playingColor = WHITE_COLOR;
						}
						settings.state = GAME_STATE;
						return settings;
					}
			}
			else if (player_clicked_quit(x2, y2, offsets))
			{
				fprintf(stdout,"%s\n","set_handler -- quit");
				fflush(stdout);
				settings.state = TERMINATE_STATE;
				return settings;
			}
			else if (player_clicked_save(x2, y2, offsets))
			{
				fprintf(stdout,"%s\n","set_handler -- save");
				fflush(stdout);
				settings.state = SAVE_STATE;
				return settings;
			}
			else if (player_clicked_main_menu(x2, y2, offsets))
			{
				fprintf(stdout,"%s\n","set handler -- main_menu");
				fflush(stdout);
				settings.state = MAIN_MENU_STATE;
				return settings;
			}
			else
			{
				continue;
			}
		}
	}
	return settings;
}

char** set_piece(int x, int y, int x_bound, int y_bound, int i, int j, char** board)
{
	//todo - use validAddition(char** board, Position position, char piece) to verify we can set
	//			if not, present appropriate message
	if (x < x_bound - 66 &&  x > x_bound - 3 * 66)
	{
		if (y > y_bound - 2* 66 && y < y_bound)
		{
			board[i][j] = 'Q';
		}
		else if ((y > y_bound - 2*66) && (y<(y_bound +2*66)))
		{
			board[i][j] = 'q';
		}
		else if ((y > y_bound -2* 66) && (y<(y_bound + 5 * 66)))
		{
			board[i][j] = EMPTY;
		}
	}
	else if ( (x<x_bound + 66) && (x > (x_bound - 2 * 66 ))   )
	{
		if ((y > y_bound -2* 66) && (y<(y_bound)))
		{
			board[i][j] = 'R';
		}
		else if ((y > y_bound - 2*66) && (y<(y_bound +2*66)))
		{
			board[i][j] = 'r';
		}
	}
	else if ((x >(x_bound + 2 * PROMOTE_OFFSET - 2 * 66)) && (x<(x_bound -  66 + 2 * PROMOTE_OFFSET))){
		if ((y > y_bound -2* 66) && (y<(y_bound)))
		{
			board[i][j] = 'B';
		}
		else if ((y > y_bound - 2*66) && (y<(y_bound +2*66)))
		{
			board[i][j] = 'b';
		}
	}
	else if ((x >(x_bound - 3 * 66 + 3 * PROMOTE_OFFSET)) && (x < (x_bound + 3 * PROMOTE_OFFSET - 66 ))){
		if ((y > y_bound -2* 66) && (y<(y_bound)))
		{
			board[i][j] = 'N';
		}
		else if ((y > y_bound - 2*66) && (y<(y_bound +2*66)))
		{
			board[i][j] = 'n';
		}
	}
	else if ((x >(x_bound - 3 * 66 + 4 * PROMOTE_OFFSET)) && (x < (x_bound + 4 * PROMOTE_OFFSET- 66)))
	{
		if ((y > y_bound -2* 66) && (y<(y_bound)))
		{
			board[i][j] = 'K';
		}
		else if ((y > y_bound - 2*66) && (y<(y_bound +2*66)))
		{
			board[i][j] = 'k';
		}
	}
	else if ((x >(x_bound - 3 * 66 + 5 * PROMOTE_OFFSET)) && (x < (x_bound + 5 * PROMOTE_OFFSET)))
	{
		if ((y > y_bound -2* 66) && (y<(y_bound)))
		{
			board[i][j] = 'M';
		}
		else if ((y > y_bound - 2*66) && (y<(y_bound +2*66)))
		{
			board[i][j] = 'm';
		}
	}
	
	return board;
}

Settings end_of_turn(Settings settings, int situation, gui_chess game_menu) 
{
	// 3.10
	settings.playingColor = otherPlayer(settings.playingColor);
	bool check = isInCheck(settings.board, settings.playingColor);
	bool stuck = !canMove(settings.board, settings.playingColor);
	if (check && stuck /*mate*/)
 	{
		apply_surface(LABLE_CHAECKMAIT, getImage(GAME_PIECES_SELECT), get_screen());
		if (settings.playingColor == WHITE_COLOR) {
			apply_surface(BLACK_MATE, getImage(GAME_PIECES_SELECT), get_screen());
		}
		else {
			apply_surface(WHITE_MATE, getImage(GAME_PIECES_SELECT), get_screen());
		}
		display_screen();
		SDL_Delay(1500);
		settings = reset_settings(settings);
		settings.state = MAIN_MENU_STATE;
		return settings;
	} else if (stuck) 
	{
		apply_surface(LABLE_TIE, getImage(ADD_IMAGE), get_screen());
		display_screen();
		SDL_Delay(1500);
		settings.state = MAIN_MENU_STATE;
		return settings;
	} else if (check) 
	{
		apply_surface(LABLE_CHECK, getImage(GAME_PIECES_SELECT), get_screen());
		display_screen();
		SDL_Delay(1500);
		return settings;
	}
	if (situation == GS_MAIN_MENU /*todo fix restart logic*/) 
	{
		settings = reset_settings(settings);
		settings.state = MAIN_MENU_STATE;
		return settings;
	}
	if (situation == GS_RESTART)
	{
		if (settings.show_hint == 1)
		{
			if (settings.gameMode == SINGLEPLAYER_MODE)
			{
				settings.state = BEST_MOVE;
				return settings;
			}
			else
			{
				gui_chess minimax_depth = build_minmax_menu();
				settings = minimax_menu_handler(minimax_depth, settings);
				return settings;
			}
		}
		// rotem_to_change massage tipe
		else // can show settings after start!
		{
			apply_surface(LABLE_MODE_MENU, getImage(LOAD_SAVE), get_screen());
			display_screen();
			SDL_Delay(2500);
			display_board(game_menu, -1,-1, settings.board);
			display_screen();

			settings.state = GAME_STATE;
			return settings;
		}
		
	}
	if (situation == GS_CAN_NOT_SET)
	{
		fprintf(stdout,"%s\n","end of turn6");
		fflush(stdout);
		if (settings.can_set == 1)
		{
			
			apply_surface(BLACK_MATE, getImage(GAME_PIECES_SELECT), get_screen());
			display_screen();
			SDL_Delay(1500);
			display_board(game_menu, -1,-1, settings.board);
			display_screen();
		}
		else
		{
			// 3.10
			// rotem_to_change massage tipe
			apply_surface(CAN_NOT_SET_MESSAGE, getImage(LOAD_SAVE), get_screen());
			display_screen();
			SDL_Delay(1500);
			display_board(game_menu, -1,-1, settings.board);
			display_screen();
			
		}
		if (settings.playingColor == WHITE_COLOR)
			{
				settings.playingColor = BLACK_COLOR;
			}
			else
			{
				settings.playingColor = WHITE_COLOR;
			}	
		settings.state = GAME_STATE;
		return settings;
	}
	if (situation == GS_QUIT) 
	{
		settings.state = TERMINATE_STATE;
		return settings;
	}
	
	return settings;
}

Settings best_move_handler ( Settings settings, gui_chess game_menu)
{
	show_on_screen(game_menu, 0, 0);
	//display_screen();
	
	if (settings.playingColor == WHITE_COLOR)
	{
		settings.playingColor = BLACK_COLOR;
	}
	else
	{
		settings.playingColor = WHITE_COLOR;
	}
	char ** prev_board = copyBoard(settings.board);
	Move* com_move = getMinimaxMove(settings.board, settings.playingColor, settings.minimaxDepth);
	char** temp_board = copyBoard(settings.board);
	settings.board = apply_best_move(settings.board, com_move);
	display_board(game_menu, com_move->from.x, com_move->from.y, temp_board);
	SDL_Delay(1500);
	display_board(game_menu, com_move->to.x, com_move->to.y, settings.board);
	SDL_Delay(1500);
	freeMove(com_move);
	freeBoard(temp_board);
	settings.board = prev_board;
	display_board(game_menu, -1, -1, settings.board);
	settings.state = GAME_STATE;
	return settings;
}

char** apply_best_move(char** board, Move* move)
{
	char originalPiece = BLUE;
	board[move->to.x][move->to.y] = (endOfBoard(move->to, pieceOwner(originalPiece)) && move->promotion != NO_PROMOTION)
		? move->promotion
		: originalPiece;
	return board;
}

Settings reset_settings(Settings settings) {
	freeBoard(settings.board);
	settings = (Settings) DEFAULT_SETTINGS;
	return settings;
}

char promotion_handler(gui_chess root, int player) {
	gui_chess tmp;
	SDL_Event event;
	int x, y, x_bound, y_bound;

	show_on_screen(root, 0, 0);
	display_screen();

	tmp = root->child;
	x_bound = tmp->box.x + PROMOTE_X;
	y_bound = tmp->box.y + PROMOTE_Y;
	
	while (true){
		SDL_WaitEvent(&event); // todo - check return value
		if (event.type == SDL_QUIT){
			return NO_PROMOTION;
		}
		else if (SDL_GetMouseState(&x, &y) & SDL_BUTTON_LMASK) {
			if ((y > y_bound) && (y < (y_bound + BOARD_SQUARE_LEN))){
				if ((x > x_bound) && (x<(x_bound + BOARD_SQUARE_LEN))) {
					return player == WHITE_COLOR ? WHITE_Q : BLACK_Q;
				}
				if ((x >(x_bound + PROMOTE_OFFSET)) && (x<(x_bound + BOARD_SQUARE_LEN + PROMOTE_OFFSET))) {
					return player == WHITE_COLOR ? WHITE_R : BLACK_R;
				}
				if ((x >(x_bound + 2 * PROMOTE_OFFSET)) && (x<(x_bound + BOARD_SQUARE_LEN + 2 * PROMOTE_OFFSET))){
					return player == WHITE_COLOR ? WHITE_B : BLACK_B;
				}
				if ((x >(x_bound + 3 * PROMOTE_OFFSET)) && (x < (x_bound + BOARD_SQUARE_LEN + 3 * PROMOTE_OFFSET))){
					return player == WHITE_COLOR ? WHITE_N : BLACK_N;
				}
			}
		}
	}
}

void show_on_screen(gui_chess start_point, int x, int y)
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
		SDL_BlitSurface(start_point->img, &(start_point->clip), get_screen(), &place_in_frame);
		
	}
	else
	{
		place_in_frame.x = x;
		place_in_frame.y = y;
		SDL_BlitSurface(start_point->img, NULL, get_screen(), NULL);
	}

	tmp = start_point->child;

	while (tmp != NULL){
		show_on_screen(tmp, place_in_frame.x, place_in_frame.y);
		tmp = tmp->next;
	}
}

void select_number_button(gui_chess number_button, int number)
{
	gui_chess tmp;
	int i = 1;
	tmp = number_button;

	while (tmp != NULL)
	{
		if (i != number)
		{
			tmp->clip.y = HIGH_BUTTON_NUMBER;
		}
		else
		{
			tmp->clip.y = HIGH_BUTTON_NUMBER_SELECT;
		}
		i++;
		tmp = tmp->next;
	}
}

void display_board(gui_chess game_menu, int selected_x, int selected_y, char** current_board)
{
	int i, j, x, y;
	SDL_Surface *current_surface;

	current_surface = getImage(GAME_PIECES);
	i = 0;
	j = 0;
	char * debug;

	show_on_screen(game_menu, i, j);

	for (i = 0 ; i < BOARD_SIZE; i++)
	{
		for (j = 0 ; j < BOARD_SIZE; j++)
		{
			x = i*BOARD_SQUARE_LEN + BOARD_TOP_CORNER;
			y = (7 - j)*BOARD_SQUARE_LEN + BOARD_TOP_CORNER;
			if (selected_x != i || selected_y != j)
			{
				debug = "noo";
				current_surface = getImage(GAME_PIECES); // just solider on the board
			}
			else
			{
				debug = "rotem";
				current_surface = getImage(GAME_PIECES_SELECT); // selsected solider on the board
			}
			switch (current_board[i][j])
			{
			case WHITE_P:
				apply_surface(WHITE_PAWN, x, y, current_surface, get_screen());
				break;
			case WHITE_B:
				apply_surface(WHITE_BISHOP, x, y, current_surface, get_screen());
				break;
			case WHITE_R:
				apply_surface(WHITE_ROOK, x, y, current_surface, get_screen());
				break;
			case WHITE_N:
				apply_surface(WHITE_KNIGHT, x, y, current_surface, get_screen());
				break;
			case WHITE_Q:
				apply_surface(WHITE_QUEEN, x, y, current_surface, get_screen());
				break;
			case WHITE_K:
				apply_surface(WHITE_KING, x, y, current_surface, get_screen());
				break;
			case BLACK_P:
				apply_surface(BLACK_PAWN, x, y, current_surface, get_screen());
				break;
			case BLACK_B:
				apply_surface(BLACK_BISHOP, x, y, current_surface, get_screen());
				break;
			case BLACK_R:
				apply_surface(BLACK_ROOK, x, y, current_surface, get_screen());
				break;
			case BLACK_N:
				apply_surface(BLACK_KNIGHT, x, y, current_surface, get_screen());
				break;
			case BLACK_Q:
				apply_surface(BLACK_QUEEN, x, y, current_surface, get_screen());
				break;
			case BLACK_K:
				apply_surface(BLACK_KING, x, y, current_surface, get_screen());
				break;
			case BLUE:
				fprintf(stdout,"%s\n","BLUE");
				fflush(stdout);
				fprintf(stdout,"%s\n",debug);
				fflush(stdout);
				apply_surface(RED_FRAME, x, y, current_surface, get_screen());
				break;
			default:
				break;
			}
		}
	}
	display_screen();
}
