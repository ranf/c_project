#ifndef SETTINGS_H
#define SETTINGS_H

#define SETTINGS_STATE 0
#define GAME_STATE 1
#define TERMINATE_STATE 2

#define MULTIPLAYER_MODE 1
#define SINGLEPLAYER_MODE 2

typedef struct {
	int state;
	int gameMode;
	int minimaxDepth;
	int userColor;
	int playingColor;
	char** board;
} Settings;

#endif