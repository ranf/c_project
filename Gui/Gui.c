#include "Gui.h"

void startGuiMode() {
	gui_chess main_menu, mode_menu, settings_menu, load_menu, save_menu, game_menu, set_color, set_menu;

	main_menu = NULL;
	mode_menu = NULL;
	settings_menu = NULL;
	load_menu = NULL;
	save_menu = NULL;
	game_menu = NULL;
	set_color = NULL;
	set_menu = NULL;
	
if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		fprintf(stderr, "ERROR: unable to init SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	atexit(SDL_Quit);

	create_screen();
	loadImages();

	main_menu = build_main_menu();
	mode_menu = build_mode_menu();
	settings_menu = build_settings_menu();
	save_menu = build_save_menu();
	load_menu = build_load_menu();
	game_menu = build_game_menu();
	set_color = build_color_set_menu();
	set_menu = build_set_menu();

	Settings settings = DEFAULT_SETTINGS;
	settings.state = MAIN_MENU_STATE;
	fprintf(stdout,"%s\n","start");
	fflush(stdout);

	while (settings.state != TERMINATE_STATE){
		switch (settings.state){
		case MAIN_MENU_STATE:
			printf("main_menu\n");
			fflush(stdout);
			settings = main_menu_handler(main_menu, settings); 
			break;		
		case LOAD_STATE:
		case SAVE_STATE:
			printf("load_save_menu\n");
			fflush(stdout);
			settings = load_save_menu_handler(load_menu, settings);
			break;
		case MODE_SETTINGS_STATE:
			printf("mode_menu\n");
			fflush(stdout);
			settings = mode_menu_handler(mode_menu, settings);
			break;
		case CHOOSE_COLOR_STATE:
			printf("choose_color_menu\n");
			fflush(stdout);
			settings = color_menu_handler(set_color, settings);
			break;
		case SETTINGS_STATE:
			printf("setting_state\n");
			fflush(stdout);
			settings = settings_menu_handler(settings_menu, settings);
			break;	
		case SET_MENU:
			settings = set_menu_handler(set_menu, game_menu, save_menu, settings);
			break;
		case GAME_STATE:
			printf("game_state\n");
			fflush(stdout);
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
	free_screen();
}
