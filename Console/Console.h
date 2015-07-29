#ifndef CONSOLE_H
#define CONSOLE_H

#include "Settings.h"

#define printMessage(message) (printf("%s", message))

void startConsoleMode();
Settings userTurn(Settings settings);
Settings computerTurn(Settings settings);
char* readString();

#endif