#ifndef COMMON_SETTINGS_H
#define COMMON_SETTINGS_H

#include "Board.h"

#define SETTINGS_STATE 0
#define GAME_STATE 1
#define TERMINATE_STATE 2
#define MAIN_MENU_STATE 3
#define LOAD_STATE 4
#define SAVE_STATE 5
#define MODE_SETTINGS_STATE 6
#define CHOOSE_COLOR_STATE 7


#define MULTIPLAYER_MODE 1
#define SINGLEPLAYER_MODE 2

#define BEST_DEPTH -1

typedef struct {
	int state;
	int gameMode;
	int minimaxDepth;
	int userColor;
	int playingColor;
	char** board;
} Settings;

#define DEFAULT_SETTINGS {\
	.state = SETTINGS_STATE,\
	.gameMode = MULTIPLAYER_MODE,\
	.minimaxDepth = 1,\
	.userColor = WHITE_COLOR,\
	.playingColor = WHITE_COLOR,\
	.board = initBoard()\
}

#endif