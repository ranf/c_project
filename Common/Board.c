#include "Board.h"

char** initBoard() {
	char** board = mallocBoard();
	int i,j;
	for (i = 0; i < BOARD_SIZE; i++)
	for (j = 2; j < BOARD_SIZE - 2; j++){
		board[i][j] = EMPTY;
	}
	board[0][0] = board[7][0] = WHITE_R;
	board[1][0] = board[6][0] = WHITE_N;
	board[2][0] = board[5][0] = WHITE_B;
	board[3][0] = WHITE_Q;
	board[4][0] = WHITE_K;
	for (int i = 0; i < BOARD_SIZE; i++) {
		board[i][1] = WHITE_P;
	}
	board[0][7] = board[7][7] = BLACK_R;
	board[1][7] = board[6][7] = BLACK_N;
	board[2][7] = board[5][7] = BLACK_B;
	board[3][7] = BLACK_Q;
	board[4][7] = BLACK_K;
	for (int i = 0; i < BOARD_SIZE; i++) {
		board[i][6] = BLACK_P;
	}
	return board;
}

void clearBoard(char** board) {
	for (int i = 0; i < BOARD_SIZE; i++)
	for (int j = 0; j < BOARD_SIZE; j++){
		board[i][j] = EMPTY;
	}
}

char** copyBoard(char** original) {
	char** copy = mallocBoard();
	for (int i = 0; i < BOARD_SIZE; i++)
	for (int j = 0; j < BOARD_SIZE; j++){
		copy[i][j] = original[i][j];
	}
	return copy;
}

char** mallocBoard() {
	char** board = safeMalloc(BOARD_SIZE*sizeof(char*));
	for (int i = 0; i < BOARD_SIZE; ++i) {
		board[i] = safeMalloc(BOARD_SIZE*sizeof(char));
	}
	return board;
}

void freeBoard(char** board) {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		free(board[i]);
	}
	free(board);
}

int countPiecesOfType(char** board, char pieceType) {
	int count = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	for (int j = 0; j < BOARD_SIZE; j++) {
		if (board[i][j] == pieceType)
			count++;
	}
	return count;
}

int maxAllowedPiecesOfType(char pieceType) {
	switch (pieceType) {
		case WHITE_P:
		case BLACK_P:
			return 8;
		case WHITE_B:
		case WHITE_N:
		case WHITE_R:
		case BLACK_B:
		case BLACK_N:
		case BLACK_R:
			return 2;
		case WHITE_Q:
		case WHITE_K:
		case BLACK_Q:
		case BLACK_K:
			return 1;
		default:
			return BOARD_SIZE * BOARD_SIZE;
	}
}

int pieceOwner(char pieceType) {
	switch (pieceType) {
		case WHITE_P:
		case WHITE_B:
		case WHITE_N:
		case WHITE_R:
		case WHITE_Q:
		case WHITE_K:
			return WHITE_COLOR;
		case BLACK_P:
		case BLACK_B:
		case BLACK_N:
		case BLACK_R:
		case BLACK_Q:
		case BLACK_K:
			return BLACK_COLOR;
		default:
			return 0;
	}
}

bool endOfBoard(Position position, int player) {
	return (player == BLACK_COLOR && position.y == 0) ||
		(player == WHITE_COLOR && position.y == BOARD_SIZE - 1);
}

Position getKingPosition(char** board, int player) {
	char king = player == WHITE_COLOR ? WHITE_K : BLACK_K;
	for (int i = 0; i < BOARD_SIZE; i++)
	for (int j = 0; j < BOARD_SIZE; j++) {
		if (board[i][j] == king) {
			return (Position) {.x = i, .y = j};
		}
	}
	return (Position) {.x = -1, .y = -1};
}

bool isPawn(char piece) {
	return piece == WHITE_P || piece == BLACK_P;
}