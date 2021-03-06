#ifndef CONSOLE_GAME_H
#define CONSOLE_GAME_H

#include "Settings.h"
#include "Position.h"
#include "../Common/Move.h"
#include "../Common/XmlParser.h"
#include "../Common/Minimax.h"

#define NOT_YOUR_PIECE "The specified position does not contain your piece\n"
#define ILLEGAL_MOVE "Illegal move\n"
#define WHITE_WON "Mate! White player wins the game\n"
#define BLACK_WON "Mate! Black player wins the game\n"
#define TIE "The game ends in a tie\n"
#define CHECK "Check!\n"

Settings applyGameCommand(Settings settings, char* cmd);
Settings moveCommand(Settings settings, char* cmd);
Settings endOfTurn(Settings settings);
void getMovesForPositionCommand(char** board, int player, char* cmd);
void getBestMovesCommand(char** board, int player, char* depth);
void getScoreCommand(char** board, int player, char* cmd);
void printAllMoves(MoveList* moves);
void printMove(Move* move);
char parsePromotion(char* str, int player);
char* getPieceName(char piece);

#endif
