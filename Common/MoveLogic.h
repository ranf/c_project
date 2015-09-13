#ifndef COMMON_MOVELOGIC_H
#define COMMON_MOVELOGIC_H

#include "Move.h"

MoveList* pawnMoves(char** board, Position source);
MoveList* bishopMoves(char** board, Position source);
MoveList* knightMoves(char** board, Position source);
MoveList* rookMoves(char** board, Position source);
MoveList* queenMoves(char** board, Position source);
MoveList* kingMoves(char** board, Position source);

MoveList* addPromotionMoves(MoveList* list, Position source, Position target, int player);
MoveList* addMovesUntilBlocked(MoveList* list, char** board, Position source, int player, Position (*direction)(Position));
MoveList* addIfNotOccupiedByPlayer(MoveList* list, char** board, Position source, int player, Position target);

#endif
