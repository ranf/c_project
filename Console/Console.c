#include "Console.h"

void startConsoleMode() {
	Settings settings = DEFAULT_SETTINGS;
	printBoard(settings.board);
	
	while (settings.state == SETTINGS_STATE) {
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

	freeBoard(settings.board);
}

Settings userTurn(Settings settings) {
	printMessage(settings.playingColor == WHITE_COLOR
		? WHITE_ENTER_YOUR_MOVE
		: BLACK_ENTER_YOUR_MOVE);
	char* cmd = readString();
	settings = applyGameCommand(settings, cmd);
	free(cmd);
	return settings;
}

Settings computerTurn(Settings settings) {
	Move* computerMove = getMinimaxMove(settings.board, settings.playingColor, settings.minimaxDepth);
	printMessage(COMPUTER_MOVE);
	printMove(computerMove);
	settings.board = applyMove(settings.board, computerMove);
	settings = endOfTurn(settings);
	return settings;
}

char* readString() {
	size_t size = 10;
	char *str;
	int ch;
	size_t len = 0;
    str = safeRealloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(stdin)) && ch != '\n'){
    	str[len++]=ch;
    	if(len==size){
    		str = safeRealloc(str, sizeof(char)*(size+=16));
    		if(!str)return str;
    	}
    }
    str[len++]='\0';
    return safeRealloc(str, sizeof(char)*len);
}