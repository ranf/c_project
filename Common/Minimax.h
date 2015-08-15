#ifndef COMMON_MINIMAX_H
#define COMMON_MINIMAX_H

#include "Move.h"

#define MAX_SCORE 99999
#define WHITE_WIN_SCORE 1000
#define BLACK_WIN_SCORE -1000
#define TIE_SCORE 0

typedef struct {
	Move* move;
	int score;
} ScoredMove;

Move* getMinimaxMove(char** board, int player, int minimaxDepth);

ScoredMove alphaBetaMinimax(int depth, int alpha, int beta, char** board, int player, bool maximize);
int scoreBoard(char** board, int player);
int scoreChar(char piece);

#endif