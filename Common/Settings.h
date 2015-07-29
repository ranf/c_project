#ifndef COMMON_SETTINGS_H
#define COMMON_SETTINGS_H

#include "Board.h"

#define SETTINGS_STATE 0
#define GAME_STATE 1
#define TERMINATE_STATE 2

#define MULTIPLAYER_MODE 1
#define SINGLEPLAYER_MODE 2

#define WHITE_COLOR 1
#define BLACK_COLOR 2

typedef struct {
	int state;
	int gameMode;
	int minimaxDepth;
	int userColor;
	int playingColor;
	char** board;
} Settings;

#define DEFUALT_SETTINGS {\
	.state = SETTINGS_STATE,\
	.gameMode = MULTIPLAYER_MODE,\
	.minimaxDepth = 1,\
	.userColor = WHITE_COLOR,\
	.playingColor = WHITE_COLOR,\
	.board = initBoard()\
}

#endif