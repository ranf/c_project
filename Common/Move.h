#ifndef COMMON_MOVE_H
#define COMMON_MOVE_H

#include "Board.h"

#define NO_PROMOTION '\0'

typedef struct {
	Position from;
	Position to;
	char promotion;
} Move;

typedef struct move_list_struct {
	Move* data;
	struct move_list_struct* next;
} MoveList;

MoveList* getMoves(char** board, int player);
Move* createMove(Position source, Position target, char promotion, bool isCastling);
MoveList* createMoveList(Move* move);
MoveList* addToMoveList(MoveList* original, Move* addition);
MoveList* getPieceMoves(char** board, Position source);
bool moveIsInList(MoveList* list, Move* move);
char** applyMove(char** board, Move* move);
void freeMove(Move* move);
void freeMoves(MoveList* moves);

#include "MoveLogic.h"

#endif
