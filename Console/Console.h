#ifndef CONSOLE_H
#define CONSOLE_H

#include "Settings.h"
#include "Board.h"
#include "Game.h"

#define WHITE_ENTER_YOUR_MOVE "White player - enter your move:\n"
#define BLACK_ENTER_YOUR_MOVE "Black player - enter your move:\n"

void startConsoleMode();
Settings userTurn(Settings settings);
Settings computerTurn(Settings settings);
char* readString();

#endif