#include "Board.h"

char** initBoard() {
	char** board = mallocBoard();
	int i,j;
	for (i = 2; i < BOARD_SIZE - 2; i++)
	for (j = 0; j < BOARD_SIZE; j++){
		board[i][j] = EMPTY;
	}
	board[0][0] = board[0][7] = WHITE_R;
	board[0][1] = board[0][6] = WHITE_N;
	board[0][2] = board[0][5] = WHITE_B;
	board[0][3] = WHITE_Q;
	board[0][4] = WHITE_K;
	for (int i = 0; i < BOARD_SIZE; i++) {
		board[1][i] = WHITE_P;
	}
	board[7][0] = board[7][7] = BLACK_R;
	board[7][1] = board[7][6] = BLACK_N;
	board[7][2] = board[7][5] = BLACK_B;
	board[7][3] = BLACK_Q;
	board[7][4] = BLACK_K;
	for (int i = 0; i < BOARD_SIZE; i++) {
		board[6][i] = BLACK_P;
	}
	return board;
}

void clearBoard(char* board) {
	for (i = 0; i < BOARD_SIZE; i++)
	for (j = 0; j < BOARD_SIZE; j++){
		board[i][j] = EMPTY;
	}
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