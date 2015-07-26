#include "Console.h"

void startConsoleMode() {
	Settings settings = DEFAULT_SETTINGS;
	settings.board = initBoard();
	printBoard(settings.board);
	
	while (settings.state == SETTINGS_STATE) {
		printMessage(ENTER_SETTINGS_MESSAGE);
		char* cmd = readString();
		settings = applySettingsCommand(settings, cmd);
		free(cmd);
	}
	
	// while (settings.state == GAME_STATE) {
	// 	if(settings.gameMode == MULTIPLAYER_MODE || settings.userColor == settings.playingColor) {
	// 		settings = userTurn(settings);
	// 	} else {
	// 		settings = computerTurn(settings);
	// 	}
	// }

	freeBoard(settings.board);
}

Settings userTurn(Settings settings) {
	/*printMessage(settings.playingColor == WHITE_COLOR
		? WHITE_ENTER_YOUR_MOVE
		: BLACK_ENTER_YOUR_MOVE);
	char* cmd = readString();
	settings = applyGameCommand(settings, cmd);
	free(cmd);*/
	return settings;
}

Settings computerTurn(Settings settings) {
	/*Move* computerMove = getComputerMove(settings);
	printMove(computerMove);
	settings.board = applyMove(settings.board);
	printBoard(settings.board);
	settings = endOfTurnLogic(settings);*/
	return settings;
}

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