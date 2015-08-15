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

MoveList* getMoves(char** board, int player, bool verifyKingNotExposed);
bool canMove(char** board, int player);
bool isInCheck(char** board, int player);
Move* createMove(Position source, Position target, char promotion);
Move* copyMove(Move* original);
MoveList* createMoveList(Move* move);
MoveList* concatMoveLists(MoveList* list1, MoveList* list2);
MoveList* addToMoveList(MoveList* original, Move* addition);
MoveList* getPieceMoves(char** board, Position source, bool verifyKingNotExposed);
bool moveIsInList(MoveList* list, Move* move);
MoveList* removeMovesExposingKing(MoveList* list, char** board, int player);
bool moveIsExposingKing(char** board, Move* move, int player);
bool hasMoveAttackingPosition(MoveList* list, Position target);
char** applyMove(char** board, Move* move);
void freeMove(Move* move);
void freeMoves(MoveList* moves);

#include "MoveLogic.h"

#endif
