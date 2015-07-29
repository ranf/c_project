#ifndef CONSOLE_SETTINGS_H
#define CONSOLE_SETTINGS_H

#include "../Common/Settings.h"


#define GAME_MODE_CMD 3
#define DIFFICULTY_DEPTH_CMD 4
#define USER_COLOR_CMD 5
#define NEXT_PLAYER_CMD 6
#define CLEAR_CMD 7
#define RM_CMD 8
#define SET_CMD 9
#define PRINT_CMD 10
#define QUIT_CMD 11
#define START_CMD 12
#define UNKNOWN_CMD 13

#define ENTER_SETTINGS_MESSAGE "Enter game settings:\n"
#define WRONG_MINIMAX_DEPTH "Wrong value for minimax depth. The value should be between 1 to 6\n"
#define WROND_BOARD_INITIALIZATION "Wrong board initialization\n"
#define ILLEGAL_COMMAND "Illegal command, please try again\n"
#define WRONG_GAME_MODE "Wrong game mode\n"
#define RUNNING_MULTIPLAYER_MODE "Running game in 2 players mode\n"
#define RUNNING_SIMGLEPLAYER_MODE "Running game in player vs. AI mode\n"


Settings applySettingsCommand(Settings settings, char* cmd);
Settings startBoard(Settings settings);
Settings setMinimaxDepth(Settings settings, char* cmd);
Settings setUserColor(Settings settings, char* cmd);
void removePiece(char** board, char* cmd);
void setPiece(char** board, char* cmd);
int getCmdType(char* cmdString);
bool validAddition(char** board, Position position, char piece);
char parsePieceName(char* name, int color);


 #endif