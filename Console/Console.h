#ifndef CONSOLE_H
#define CONSOLE_H

#include "Settings.h"
#include "Board.h"

#define printMessage(message) (printf("%s", message))

void startConsoleMode();
Settings userTurn(Settings settings);
Settings computerTurn(Settings settings);
char* readString();

#endif