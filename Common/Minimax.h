#ifndef COMMON_MINIMAX_H
#define COMMON_MINIMAX_H

#include "Move.h"
#include "Settings.h"

#define MAX_SCORE 99999
#define WHITE_WIN_SCORE 1000
#define BLACK_WIN_SCORE -1000
#define TIE_SCORE 0

#define BEST_MINIMAX_UPPER_BOUND 1000000
#define P_MAX_MOVES 3
#define B_MAX_MOVES 13
#define N_MAX_MOVES 8
#define R_MAX_MOVES 14
#define Q_MAX_MOVES 27
#define K_MAX_MOVES 8

typedef struct {
	Move* move;
	int score;
} ScoredMove;

Move* getMinimaxMove(char** board, int player, int minimaxDepth);

ScoredMove alphaBetaMinimax(int depth, int alpha, int beta, char** board, int player, bool maximize);
int scoreBoard(char** board, int player);
int scoreChar(char piece);

Move* bestMinimax(char** board, int player);
int getMaxMoves(char** board, int player, int possibleMovesAlready);

#endif