#include "Board.h"

void printBoard(char** board) {
	int i,j;
	printBoardLineSeperator();
	for (j = BOARD_SIZE-1; j >= 0 ; j--)
	{
		printf((j < 9 ? " %d" : "%d"), j+1);
		for (i = 0; i < BOARD_SIZE; i++){
			printf("| %c ", board[i][j]);
		}
		printf("|\n");
		printBoardLineSeperator();
	}
	printf("   ");
	for (j = 0; j < BOARD_SIZE; j++){
		printf(" %c  ", (char)('a' + j));
	}
	printf("\n");
}

void printBoardLineSeperator() {
	int i;
	printf("  |");
	for (i = 1; i < BOARD_SIZE*4; i++){
		printf("-");
	}
	printf("|\n");
}