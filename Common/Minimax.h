#ifndef COMMON_MINIMAX_H
#define COMMON_MINIMAX_H

#include "Move.h"
#include "Settings.h"
#include "PieceSquareTable.h"

#define MAX_SCORE 99999
#define WHITE_WIN_SCORE 1000
#define BLACK_WIN_SCORE -1000
#define WHITE_TIE_SCORE -999
#define BLACK_TIE_SCORE 999

#define BEST_MINIMAX_UPPER_BOUND 1000000
#define P_MAX_MOVES 3
#define B_MAX_MOVES 13
#define N_MAX_MOVES 8
#define R_MAX_MOVES 14
#define Q_MAX_MOVES 27
#define K_MAX_MOVES 8

typedef struct {
	MoveList* moves;
	int score;
} ScoredMoves;

Move* getMinimaxMove(char** board, int player, int minimaxDepth);
MoveList* getAllMinimaxMoves(char** board, int player, int minimaxDepth);
int scoreMove(char** board, Move* move, int player, int minimaxDepth);

ScoredMoves alphaBetaMinimax(int depth, int alpha, int beta, char** board, int player,
	bool maximize, int (*scoreFunction)(char**,int));
int scoreBoard(char** board, int player);
int scoreChar(char piece);

ScoredMoves bestMinimax(char** board, int player);
int getMaxMoves(char** board, int player, int possibleMovesAlready);
int bestScoreBoard(char** board, int player);
int bestScoreChar(char piece);
ScoredMoves bestFirstLevelScore(char** board, ScoredMoves scoredMoves, int player);

#endif
