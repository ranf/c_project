#include "PieceSquareTable.h"

int pieceSquareTable(char** board, int x, int y) {
	char piece = board[x][y];
	switch (piece) {
		case WHITE_P:
			return pawnPieceTable(x, y);
		case BLACK_P:
			return convertToBlackPieceTable(x, y, &pawnPieceTable);
		case WHITE_B:
			return bishopPieceTable(x, y);
		case BLACK_B:
			return convertToBlackPieceTable(x, y, &bishopPieceTable);
		case WHITE_N:
			return knightPieceTable(x, y);
		case BLACK_N:
			return convertToBlackPieceTable(x, y, &knightPieceTable);
		default:
			return 0; //not implemented for all piece types - it's less effective for them
	}
}

int convertToBlackPieceTable(int x, int y, int (*table)(int, int)){
	return -table(x, 7 - y);
}

int pawnPieceTable(int x, int y) {
	static int pawnTable[BOARD_SIZE][BOARD_SIZE]  = {
		{0,  0,  0,  0,  0,  0,  0,  0},
		{50, 50, 50, 50, 50, 50, 50, 50},
		{10, 10, 20, 30, 30, 20, 10, 10},
		{5,  5, 10, 25, 25, 10,  5,  5},
		{0,  0,  0, 20, 20,  0,  0,  0},
		{5, -5,-10, 10, 10,-10, -5,  5},
		{5, 10, 10,-20,-20, 10, 10,  5},
		{0,  0,  0,  0,  0,  0,  0,  0}
	};
	return pawnTable[x][y];
}

int bishopPieceTable(int x, int y) {
	static int bishopTable[BOARD_SIZE][BOARD_SIZE]  = {
		{-20,-10,-10,-10,-10,-10,-10,-20},
		{-10,  0,  0,  0,  0,  0,  0,-10},
		{-10,  0,  5, 10, 10,  5,  0,-10},
		{-10,  5,  5, 10, 10,  5,  5,-10},
		{-10,  0, 10, 10, 10, 10,  0,-10},
		{-10, 10, 10, 10, 10, 10, 10,-10},
		{-10,  5,  0,  0,  0,  0,  5,-10},
		{-20,-10,-10,-10,-10,-10,-10,-20}
	};
	return bishopTable[x][y];
}

int knightPieceTable(int x, int y) {
	static int knightTable[BOARD_SIZE][BOARD_SIZE]  = {
		{-50,-40,-30,-30,-30,-30,-40,-50},
		{-40,-20,  0,  0,  0,  0,-20,-40},
		{-30,  0, 10, 15, 15, 10,  0,-30},
		{-30,  5, 15, 20, 20, 15,  5,-30},
		{-30,  0, 15, 20, 20, 15,  0,-30},
		{-30,  5, 10, 15, 15, 10,  5,-30},
		{-40,-20,  0,  5,  5,  0,-20,-40},
		{-50,-40,-30,-30,-30,-30,-40,-50}
	};
	return knightTable[x][y];
}
