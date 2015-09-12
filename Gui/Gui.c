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

	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		fprintf(stderr, "ERROR: unable to init SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	atexit(SDL_Quit);

	SDL_Surface *screen = SDL_SetVideoMode(WIN_W, WIN_H, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);

	if (screen == NULL) 
	{
		fprintf(stderr, "ERROR: failed to set video mode: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_WM_SetCaption("Chess Game GUI mode", NULL); /* sets the window's name*/

	loadImages();

	main_menu = build_main_menu();
	mode_menu = build_mode_menu();
	settings_menu = build_settings_menu();
	save_menu = build_save_menu();
	load_menu = build_load_menu();
	game_menu = build_game_menu();
	set_color = build_color_set_menu();

	Settings settings = DEFAULT_SETTINGS;
	settings.state = MAIN_MENU_STATE;

	while (settings.state != TERMINATE_STATE){
		switch (settings.state){
		case MAIN_MENU_STATE:
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
			perror("illegal code path");
			exit(EXIT_FAILURE);//should never happen
			break;
		}
	}

	if (settings.board != NULL)
		freeBoard(settings.board);
	freeImages();
	SDL_FreeSurface(screen);
}