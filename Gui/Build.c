#include "Build.h"


/*menus building functions*/
gui_chess build_main_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANELS_SHEET), FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(SETTINGS_SHEET),MAIN_LABEL_PMT,tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), NEW_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), LOAD_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), QUIT_BUTTON_PMT, tmp_parent);

	return result;
}

gui_chess build_mode_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANELS_SHEET), FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(SETTINGS_SHEET), MODE_LABEL_PMT, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), PVP_S_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), PVC_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), CANCEL_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), START_BUTTON_PMT, tmp_parent);

	return (result);
}


gui_chess build_color_set_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANELS_SHEET), FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(SETTINGS_SHEET), COLOR_LABEL_PMT, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), WHITE_S_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), BLACK_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), CANCEL_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), NEXT_BUTTON_PMT, tmp_parent);

	return result;
	
}

gui_chess build_diffculty_menu()
{
	gui_chess result, tmp, tmp_parent;
	tmp_parent = NULL;
	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANELS_SHEET), FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(SETTINGS_SHEET), DIFFICULTY_LABEL_PMT, tmp_parent/*todo fix used uninitialized warning*/);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), ONE_S_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), TWO_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), THREE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), FOUR_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), BEST_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), CANCEL_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), START_BUTTON_PMT, tmp_parent);

	return (result);
}
gui_chess build_settings_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANELS_SHEET), FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(SETTINGS_SHEET), COLOR_LABEL_PMT, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), WHITE_S_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), BLACK_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = label_factory(getImage(SETTINGS_SHEET), DIFFICULTY_LABEL_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), ONE_S_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), TWO_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), THREE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), FOUR_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), BEST_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), CANCEL_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), START_BUTTON_PMT, tmp_parent);
	
	return (result);
}

gui_chess build_save_menu()
{
	gui_chess result, tmp, tmp_parent;
	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANELS_SHEET), FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(SETTINGS_SHEET), SAVE_LABEL_PMT, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), ONE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), TWO_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), THREE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), FOUR_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), FIVE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), CANCEL_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), SAVE_ARROW_PMT, tmp_parent);
	return (result);
}

gui_chess build_load_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(getImage(BACKGROUND_IMAGE));
	tmp = result;
	tmp->child = panel_factory(getImage(PANELS_SHEET), FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->child = label_factory(getImage(SETTINGS_SHEET), LOAD_LABEL_PMT, tmp);
	tmp_parent = tmp;
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), ONE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), TWO_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), THREE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), FOUR_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), FIVE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), CANCEL_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), LOAD_ARROW_PMT, tmp_parent);

	return (result);
}

gui_chess build_game_menu()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(getImage(MAIN_IMG));
	tmp = result;
	tmp_parent = result;
	tmp->child = button_factory(getImage(SETTINGS_SHEET), MENU_BUTTON_PMT, tmp_parent);
	tmp = tmp->child;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), SAVE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), RESTART_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), QUIT_SIDE_BUTTON_PMT, tmp_parent);
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), SET, tmp_parent);
	/*sould be replace with start*/
	tmp = tmp->next;
	tmp->next = button_factory(getImage(SETTINGS_SHEET), START, tmp_parent);
	return (result);
}

gui_chess white_player_promots()
{
	gui_chess result, tmp, tmp_parent;

	result = window_factory(getImage(MAIN_IMG));
	tmp = result;
	tmp_parent = result;
	tmp->child = panel_factory(getImage(PANELS_SHEET), FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp_parent = tmp;
	tmp->child = label_factory(getImage(PIECES_SHEET), PROMOTE_LABEL, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), W_ROOK_PMT, (PROMOTE_FIRST_POS_X + PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), W_QUEEN_PMT, PROMOTE_FIRST_POS_X, PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), W_KNIGHT_PMT, (PROMOTE_FIRST_POS_X + 3 * PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), W_BISHOP_PMT, (PROMOTE_FIRST_POS_X + 2 * PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
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
	tmp->child = panel_factory(getImage(PANELS_SHEET), FISH_PANEL_PMT, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp_parent = tmp;
	tmp->child = label_factory(getImage(PIECES_SHEET), PROMOTE_LABEL, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), B_ROOK_PMT, (PROMOTE_FIRST_POS_X + PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), B_QUEEN_PMT, PROMOTE_FIRST_POS_X, PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), B_KNIGHT_PMT, (PROMOTE_FIRST_POS_X + 3 * PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), B_BISHOP_PMT, (PROMOTE_FIRST_POS_X + 2 * PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
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
	tmp->child = label_factory(getImage(PIECES_SHEET), PROMOTE_LABEL, tmp);
	tmp = tmp->child;
	tmp->parent = tmp_parent;
	tmp_parent = tmp;
	tmp->next = button_factory(getImage(PIECES_SHEET), B_ROOK_PMT, (PROMOTE_FIRST_POS_X + PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), B_QUEEN_PMT, PROMOTE_FIRST_POS_X, PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), B_KNIGHT_PMT, (PROMOTE_FIRST_POS_X + 3 * PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), B_BISHOP_PMT, (PROMOTE_FIRST_POS_X + 2 * PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), B_KING_PMT, (PROMOTE_FIRST_POS_X + 4 * PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), B_PAWN_PMT, (PROMOTE_FIRST_POS_X + 5 * PROMOTE_OFFSET), PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), W_ROOK_PMT, (PROMOTE_FIRST_POS_X + PROMOTE_OFFSET), 2 * PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), W_QUEEN_PMT, PROMOTE_FIRST_POS_X, 2 * PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), W_KNIGHT_PMT, (PROMOTE_FIRST_POS_X + 3 * PROMOTE_OFFSET), 2 * PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), W_BISHOP_PMT, (PROMOTE_FIRST_POS_X + 2 * PROMOTE_OFFSET), 2 * PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), W_KING_PMT, (PROMOTE_FIRST_POS_X + 4 * PROMOTE_OFFSET), 2 * PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), W_PAWN_PMT, (PROMOTE_FIRST_POS_X + 5 * PROMOTE_OFFSET), 2 * PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	tmp->next = button_factory(getImage(PIECES_SHEET), EMPTY_BUTTON, (PROMOTE_FIRST_POS_X), 3 * PROMOTE_FIRST_POS_Y, tmp_parent);
	tmp = tmp->next;
	tmp->parent = tmp_parent;
	
	return result;
}

