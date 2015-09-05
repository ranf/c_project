#include "Build.h"


SDL_Surface *screen = NULL;
SDL_Surface *main_img = NULL;
SDL_Surface *panels_sheet = NULL;
SDL_Surface *settings_sheet = NULL;
SDL_Surface *pieces_sheet = NULL;
SDL_Surface *selected_pieces_sheet = NULL;
SDL_Surface *backround = NULL;

SDL_Surface *load_link_image(char *path)
{
	/*declare & initialize*/
	SDL_Surface *tmp, *result ;
	tmp = NULL;
	result = NULL;

	/*load the image*/
	tmp = SDL_LoadBMP(path);

	if (tmp != NULL)
	{
		result = SDL_DisplayFormat(tmp);
		if (result != NULL){
			//Uint32 colorkey = SDL_MapRGB(result->format, 0, 0xFF, 0xFF);
			Uint32 colorkey = SDL_MapRGB(result->format, 0xFF, 0, 0xFF);
			SDL_SetColorKey(result, SDL_SRCCOLORKEY, colorkey);
		}
		SDL_FreeSurface(tmp);
		return (result);
	}
	else
	{
		printf("ERROR: failed to load image: %s\n", SDL_GetError());
		return NULL;
	}
}


/*menus building functions*/
gui_chess build_main_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(backround); /* set backround image */
	tmp = result;
	tmp->child = panel_factory(panels_sheet, FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(settings_sheet,MAIN_LABEL_PMT,tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(settings_sheet, NEW_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, LOAD_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, QUIT_BUTTON_PMT, tmp_parent);

	return (result);
}

gui_chess build_mode_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(backround);
	tmp = result;
	tmp->child = panel_factory(panels_sheet, FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(settings_sheet, MODE_LABEL_PMT, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(settings_sheet, PVP_S_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, PVC_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, CANCEL_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, START_BUTTON_PMT, tmp_parent);

	return (result);
}

gui_chess build_settings_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(backround);
	tmp = result;
	tmp->child = panel_factory(panels_sheet, FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(settings_sheet, COLOR_LABEL_PMT, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(settings_sheet, WHITE_S_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, BLACK_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = label_factory(settings_sheet, DIFFICULTY_LABEL_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, ONE_S_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, TWO_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, THREE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, FOUR_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, BEST_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, CANCEL_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, START_BUTTON_PMT, tmp_parent);
	
	return (result);
}

gui_chess build_save_menu()
{
	gui_chess result, tmp, tmp_parent;
	result = window_factory(backround);
	tmp = result;
	tmp->child = panel_factory(panels_sheet, FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(settings_sheet, SAVE_LABEL_PMT, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(settings_sheet, ONE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, TWO_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, THREE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, FOUR_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, FIVE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, CANCEL_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, SAVE_ARROW_PMT, tmp_parent);
	return (result);
}

gui_chess build_load_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(backround);
	tmp = result;
	tmp->child = panel_factory(panels_sheet, FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(settings_sheet, LOAD_LABEL_PMT, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(settings_sheet, ONE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, TWO_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, THREE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, FOUR_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, FIVE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, CANCEL_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, LOAD_ARROW_PMT, tmp_parent);

	return (result);
}

gui_chess build_game_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(main_img);
	tmp = result;
	tmp_parent = result;
	tmp->child = button_factory(settings_sheet, MENU_BUTTON_PMT, tmp_parent);
	tmp = tmp->child;
	tmp->next = button_factory(settings_sheet, SAVE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, RESTART_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(settings_sheet, QUIT_SIDE_BUTTON_PMT, tmp_parent);

	return (result);
}

gui_chess white_player_promots()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(main_img);
	tmp = result;
	tmp_parent = result;
	tmp->child = panel_factory(panels_sheet, FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp_parent = tmp;
	tmp->child = label_factory(pieces_sheet, PROMOTE_LABEL, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(pieces_sheet, W_ROOK_PMT, (PROMOTE_FIRST_POS_X + PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(pieces_sheet, W_QUEEN_PMT, PROMOTE_FIRST_POS_X, PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(pieces_sheet, W_KNIGHT_PMT, (PROMOTE_FIRST_POS_X + 3 * PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(pieces_sheet, W_BISHOP_PMT, (PROMOTE_FIRST_POS_X + 2 * PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	return (result);
}

gui_chess black_player_promots()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(main_img);
	tmp = result;
	tmp_parent = result;
	tmp->child = panel_factory(panels_sheet, FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp_parent = tmp;
	tmp->child = label_factory(pieces_sheet, PROMOTE_LABEL, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(pieces_sheet, B_ROOK_PMT, (PROMOTE_FIRST_POS_X + PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(pieces_sheet, B_QUEEN_PMT, PROMOTE_FIRST_POS_X, PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(pieces_sheet, B_KNIGHT_PMT, (PROMOTE_FIRST_POS_X + 3 * PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(pieces_sheet, B_BISHOP_PMT, (PROMOTE_FIRST_POS_X + 2 * PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	return (result);
}

gui_chess build_promotion_menu(int now_playing)
{
	gui_chess result;
	if (now_playing == WHITE)
	{
		result = white_player_promots();
		return result;
	}
	/* black player play now*/
	else
	{
		result = black_player_promots();
		return result;
	}
}