#ifndef COMMON_SETTINGS_H
#define COMMON_SETTINGS_H

#include "Board.h"

#define TERMINATE_STATE 0
#define MAIN_MENU_STATE 1
#define LOAD_STATE 2
#define SAVE_STATE 3
#define MODE_SETTINGS_STATE 4
#define CHOOSE_COLOR_STATE 5
#define SETTINGS_STATE 6
#define SET_MENU 7
#define GAME_STATE 8
#define BEST_MOVE 9
#define CANCEL_BEST_MOVE 10

#define MULTIPLAYER_MODE 1
#define SINGLEPLAYER_MODE 2

#define BEST_DEPTH -1

typedef struct {
	int state;
	int gameMode;
	int minimaxDepth;
	int userColor;
	int playingColor;
	int can_set;
	int show_hint;
	char** board;
} Settings;

#define DEFAULT_SETTINGS {\
	.state = SETTINGS_STATE,\
	.gameMode = MULTIPLAYER_MODE,\
	.minimaxDepth = 1,\
	.show_hint = 0,\
	.can_set = 1,\
	.userColor = WHITE_COLOR,\
	.playingColor = WHITE_COLOR,\
	.board = initBoard()\
}

#endif
