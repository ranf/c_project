#ifndef COMMON_PIECESQUARETABLE_H
#define COMMON_PIECESQUARETABLE_H

#include "Board.h"

int pieceSquareTable(char** board, int x, int y);

int convertToBlackPieceTable(int x, int y, int (*table)(int, int));
int pawnPieceTable(int x, int y);
int bishopPieceTable(int x, int y);
int knightPieceTable(int x, int y);

#endif
