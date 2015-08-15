#ifndef CONSOLE_GAME_H
#define CONSOLE_GAME_H

#include "Settings.h"
#include "../Common/Move.h"

#define NOT_YOUR_PIECE "The specified position does not contain your piece\n"
#define ILLEGAL_MOVE "Illegal move\n"

Settings applyGameCommand(Settings settings, char* cmd);
Settings moveCommand(Settings settings, char* cmd);
void getMovesForPositionCommand(char** board, int player, char* cmd);
void printAllMoves(MoveList* moves);
void printMove(Move* move);
char parsePromotion(char* str, int player);
char* getPieceName(char piece);

#endif