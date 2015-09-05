#include "Gui.h"

void startGuiMode() {
	gui_chess main_menu, mode_menu, settings_menu, load_menu, save_menu, game_menu, set_color;

	main_menu = NULL;
	mode_menu = NULL;
	settings_menu = NULL;
	load_menu = NULL;
	save_menu = NULL;
	game_menu = NULL;
	set_color = NULL;

	int menu_selection = 1;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		printf("ERROR: unable to init SDL: %s\n", SDL_GetError());
		return 1;
	}

	screen = SDL_SetVideoMode(WIN_W, WIN_H, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);

	if (screen == NULL) 
	{
		printf("ERROR: failed to set video mode: %s\n", SDL_GetError());
		return 1;
	}

	SDL_WM_SetCaption("Chess Game GUI mode", NULL); /* sets the window's name*/

	atexit(SDL_Quit);

	loadImages();

	main_menu = build_main_menu();
	mode_menu = build_mode_menu();
	settings_menu = build_settings_menu();
	save_menu = build_save_menu();
	load_menu = build_load_menu();
	game_menu = build_game_menu();
	set_color = build_color_set_menu();
	Settings settings = DEFUALT_SETTINGS;

	while (settings.state != TERMINATE_STATE){
		switch (settings.state){
		case MENU_STATE:
			settings = main_menu_handler(main_menu, settings);
			break;
		case LOAD_STATE:
		case SAVE_STATE:
			settings = load_save_menu_handler(load_menu, settings);
			break;
		case CHOOSE_COLOR_STATE:
			settings = color_menu_handler(set_color, settings);
		case MODE_SETTINGS_STATE:
			settings = mode_menu_handler(mode_menu, settings);
			break;
		case SETTINGS_STATE:
			settings = settings_menu_handler(settings_menu, settings);
			break;
		case GAME_STATE:
			settings = game_menu_handler(game_menu, save_menu, settings);
			break;
		default:
			break;
		}
	}

	if (settings.board != NULL)
		freeBoard(settings.board);
	SDL_FreeSurface(screen);
	SDL_FreeSurface(main_img);
	SDL_FreeSurface(panels_sheet);
	SDL_FreeSurface(settings_sheet);
	SDL_FreeSurface(pieces_sheet);
	SDL_FreeSurface(selected_pieces_sheet);

	SDL_Quit();
}

void loadImages()
{
	main_img = load_link_image(MAIN_IMG);
	panels_sheet = load_link_image(PANELS_SHEET);
	settings_sheet = load_link_image(SETTINGS_SHEET);
	pieces_sheet = load_link_image(PIECES_SHEET);
	selected_pieces_sheet = load_link_image(SELECTED_PIECES_SHEET);
	backround = load_link_image(BACKROUND_IMAGE);
}

void display_screen() {
	if (SDL_Flip(screen) == -1)
	{
		printf("ERROR: unable to init SDL: %s\n", SDL_GetError());
	}
}

void apply_surface(int src_x, int src_y, int src_w, int src_h, int dst_x, int dst_y, SDL_Surface* source, SDL_Surface* destination){
	
	SDL_Rect src_new;
	SDL_Rect dst_new;
	src_new.x = src_x;
	src_new.y = src_y;
	src_new.w = src_w;
	src_new.h = src_h;
	dst_new.x = dst_x;
	dst_new.y = dst_y;
	SDL_BlitSurface(source, &src_new, destination, &dst_new);
}