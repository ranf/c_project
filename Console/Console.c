#include "Console.h"

void startConsoleMode() {
	/*Settings settings = DEFAULT_SETTINGS;
	settings.board = initBoard();
	
	while (settings.state == SETTINGS_STATE) {
		printBoard(settings.board);
		printMessage(ENTER_SETTINGS_MESSAGE);
		char* cmd = readString();
		settings = applySettingsCommand(settings, cmd);
		free(cmd);
	}
	
	while (settings.state == GAME_STATE) {
		if(settings.gameMode == MULTIPLAYER_MODE || settings.userColor == settings.playingColor) {
			settings = userTurn(settings);
		} else {
			settings = computerTurn(settings);
		}
	}

	freeBoard(settings.board);*/
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