#include "Build.h"


/*menus building functions*/
gui_chess build_main_menu()
{
	gui_chess result, tmp, tmp_parent;
    tmp_parent = NULL;
	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANEL_BLACK_WHITE), BLACK_WHITE_IMAGE, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(SETTINGS),LABLE_MAIN_MENU,tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS), NEW_GAME, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), LOAD_GAME, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), QUIT_GAME, tmp_parent);
    
	return result;
}

gui_chess build_mode_menu()
{
	gui_chess result, tmp, tmp_parent;
    tmp_parent = NULL;
	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANEL_BLACK_WHITE), BLACK_WHITE_IMAGE, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(SETTINGS), LABLE_MODE_MENU, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS), P_VS_P_BUTTON_SELECT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), P_VS_C_BUTTON, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), CANCEL_BUTTON, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), START_BUTTON, tmp_parent);

	return (result);
}


gui_chess build_color_set_menu()
{
	gui_chess result, tmp, tmp_parent;
    tmp_parent = NULL;
	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANEL_BLACK_WHITE), BLACK_WHITE_IMAGE, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(LOAD_SAVE), LABLE_CHOOSE_COLOR, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS), WHITE_COLOR_BUTTON_SELECT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BLACK_COLOR_BUTTON, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), CANCEL_BUTTON, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), NEXT_BUTTON, tmp_parent);

	return result;
	
}

gui_chess build_minmax_menu()
{
    gui_chess result, tmp, tmp_parent;
    
    result = window_factory(getImage(BACKGROUND_IMAGE));
    tmp = result;
    tmp->child = panel_factory(getImage(PANEL_BLACK_WHITE), BLACK_WHITE_IMAGE, tmp);
    tmp = tmp->child;
    tmp->child = label_factory(getImage(SETTINGS), LABLE_DIFFCLTY, tmp);
    tmp_parent = tmp;
    tmp = tmp->child;
    tmp->next = button_factory(getImage(SETTINGS), BUTTON_ONE, tmp_parent);
    tmp = tmp->next;
    tmp->next = button_factory(getImage(SETTINGS), BUTTON_TWO, tmp_parent);
    tmp = tmp->next;
    tmp->next = button_factory(getImage(SETTINGS), BUTTON_THREE, tmp_parent);
    tmp = tmp->next;
    tmp->next = button_factory(getImage(SETTINGS), BUTTON_FOUR, tmp_parent);
    tmp = tmp->next;
    tmp->next = button_factory(getImage(SETTINGS), BEST_BUTTON, tmp_parent);
    tmp = tmp->next;
    tmp->next = button_factory(getImage(LOAD_SAVE), CANCEL_BUTTON, tmp_parent);
    tmp = tmp->next;
    tmp->next = button_factory(getImage(LOAD_SAVE), NEXT_BUTTON, tmp_parent);
    
    return (result);
}
gui_chess build_settings_menu()
{
	gui_chess result, tmp, tmp_parent;
    
	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANEL_BLACK_WHITE), BLACK_WHITE_IMAGE, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(SETTINGS), LABLE_CHOOSE_COLOR, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS), WHITE_COLOR_BUTTON_SELECT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BLACK_COLOR_BUTTON, tmp_parent);
	tmp = tmp->next;
	tmp->next = label_factory(getImage(SETTINGS), LABLE_DIFFCLTY, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_ONE_SELECT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_TWO, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_THREE, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_FOUR, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BEST_BUTTON, tmp_parent);
	tmp = tmp->next;
    tmp->next = button_factory(getImage(LOAD_SAVE), CANCEL_BUTTON, tmp_parent);
    tmp = tmp->next;
    tmp->next = button_factory(getImage(LOAD_SAVE), START_BUTTON, tmp_parent);
	
	return (result);
}

gui_chess build_save_menu()
{
	gui_chess result, tmp, tmp_parent;
	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANEL_BLACK_WHITE), BLACK_WHITE_IMAGE, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(SETTINGS), LABLE_SAVE_SLOT, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_ONE, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_TWO, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_THREE, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_FOUR, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_FIVE, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(ADD_IMAGE), BUTTON_SIX, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(ADD_IMAGE), BUTTON_SEVEN, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(LOAD_SAVE), CANCEL_BUTTON, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(LOAD_SAVE), SAVE_BUTTON, tmp_parent);
	return (result);
}

gui_chess build_load_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANEL_BLACK_WHITE), BLACK_WHITE_IMAGE, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(SETTINGS), LABLE_LOAD_GAME, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_ONE, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_TWO, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_THREE, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_FOUR, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), BUTTON_FIVE, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(ADD_IMAGE), BUTTON_SIX, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(ADD_IMAGE), BUTTON_SEVEN, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(LOAD_SAVE), CANCEL_BUTTON, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(LOAD_SAVE), LOAD_BUTTON, tmp_parent);
	
	return (result);
}

gui_chess build_game_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(getImage(MAIN_IMG));
	tmp = result;
	tmp_parent = result;
	tmp->child = button_factory(getImage(SETTINGS), MAIN_MENI_BUTTON, tmp_parent);
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS), SAVE_GAME_BUTTON, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), HINT_BUTTON, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS), QUIT_GAME_BUTTON, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(ADD_IMAGE), SET_GAME_BUTTON, tmp_parent);
	/*sould be replace with start*/
	tmp = tmp->next;
	tmp->next = button_factory(getImage(ADD_IMAGE), START_GAME_BUTTON, tmp_parent);
	return (result);
}

gui_chess white_player_promots()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(getImage(MAIN_IMG));
	tmp = result;
	tmp_parent = result;
	tmp->child = panel_factory(getImage(PANEL_BLACK_WHITE), BLACK_WHITE_IMAGE, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp_parent = tmp;
	tmp->child = label_factory(getImage(GAME_PIECES), LABLE_PROMOTE_MENU, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), WHITE_ROOK, (PROMOTE_X + PROMOTE_OFFSET), PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), WHITE_QUEEN, PROMOTE_X, PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), WHITE_KNIGHT, (PROMOTE_X + 3 * PROMOTE_OFFSET), PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), WHITE_BISHOP, (PROMOTE_X + 2 * PROMOTE_OFFSET), PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	return (result);
}

gui_chess black_player_promots()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(getImage(MAIN_IMG));
	tmp = result;
	tmp_parent = result;
	tmp->child = panel_factory(getImage(PANEL_BLACK_WHITE), BLACK_WHITE_IMAGE, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp_parent = tmp;
	tmp->child = label_factory(getImage(GAME_PIECES), LABLE_PROMOTE_MENU, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), BLACK_ROOK, (PROMOTE_X + PROMOTE_OFFSET), PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), BLACK_QUEEN, PROMOTE_X, PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), BLACK_KNIGHT, (PROMOTE_X + 3 * PROMOTE_OFFSET), PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), BLACK_BISHOP, (PROMOTE_X + 2 * PROMOTE_OFFSET), PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	return (result);
}

gui_chess build_promotion_menu(int now_playing)
{
	return now_playing == WHITE_COLOR ? white_player_promots() : black_player_promots();
}

gui_chess build_set_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(getImage(MAIN_IMG));
	tmp = result;
	tmp_parent = result;
	tmp->child = label_factory(getImage(ADD_IMAGE), LABLE_CHOOSE_NEW_PIECE, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp_parent = tmp;
	tmp->next = button_factory(getImage(GAME_PIECES), BLACK_ROOK, (PROMOTE_X + PROMOTE_OFFSET), PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), BLACK_QUEEN, PROMOTE_X, PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), BLACK_KNIGHT, (PROMOTE_X + 3 * PROMOTE_OFFSET), PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), BLACK_BISHOP, (PROMOTE_X + 2 * PROMOTE_OFFSET), PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), BLACK_KING, (PROMOTE_X + 4 * PROMOTE_OFFSET), PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), BLACK_PAWN, (PROMOTE_X + 5 * PROMOTE_OFFSET), PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), WHITE_ROOK, (PROMOTE_X + PROMOTE_OFFSET), 2 * PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), WHITE_QUEEN, PROMOTE_X, 2 * PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), WHITE_KNIGHT, (PROMOTE_X + 3 * PROMOTE_OFFSET), 2 * PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), WHITE_BISHOP, (PROMOTE_X + 2 * PROMOTE_OFFSET), 2 * PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), WHITE_KING, (PROMOTE_X + 4 * PROMOTE_OFFSET), 2 * PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), WHITE_PAWN, (PROMOTE_X + 5 * PROMOTE_OFFSET), 2 * PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(GAME_PIECES), EMPTY_BUTTON, (PROMOTE_X), 3 * PROMOTE_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	
	return result;
}

