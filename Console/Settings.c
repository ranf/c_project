#include "Settings.h"

Settings applySettingsCommand(Settings settings, char* cmd) {
	switch (getCmdType(cmd)) {
		case GAME_MODE_CMD:
			settings = setGameMode(settings, cmd);
			break;
		case DIFFICULTY_DEPTH_CMD:
			settings = setMinimaxDepth(settings, cmd);
			break;
		case USER_COLOR_CMD:
			settings = setUserColor(settings, cmd);
			break;
		case CLEAR_CMD:
			clearBoard(settings.board);
			break;
		case RM_CMD:
			removePiece(settings.board, cmd);
			break;
		case SET_CMD:
			setPiece(settings.board, cmd);
			break;
		case PRINT_CMD:
			printBoard(settings.board);
			break;
		case QUIT_CMD:
			settings.state = TERMINATE_STATE;
			break;
		case START_CMD:
			settings = startBoard(settings);
			break;
		default:
			printMessage(ILLEGAL_COMMAND);
			break;
		}

	return settings;
}

Settings startBoard(Settings settings) {
	if (countPiecesOfType(settings.board, WHITE_K) != 1 ||
		countPiecesOfType(settings.board, BLACK_K) != 1) {
		printMessage(WROND_BOARD_INITIALIZATION);
	} else {
		settings.state = GAME_STATE;
	}
	return settings;
}

Settings setMinimaxDepth(Settings settings, char* cmd) {
	if(settings.gameMode == MULTIPLAYER_MODE){
		printMessage(ILLEGAL_COMMAND);
		return settings;
	}
	int minimaxDepth = atoi(cmd + 17); // |difficulty depth | = 17
	if (minimaxDepth <= 4 && minimaxDepth >= 1){
		settings.minimaxDepth = minimaxDepth;
	} else {
		printMessage(WRONG_MINIMAX_DEPTH);
	}
	return settings;
}

Settings setGameMode(Settings settings, char* cmd) {
	char* mode = cmd + 10;// |game_mode | = 10
	if (*mode == '1' && *(mode + 1) == '\0') {
		settings.gameMode = MULTIPLAYER_MODE;
		printMessage(RUNNING_MULTIPLAYER_MODE);
	} else if (*mode == '2' && *(mode + 1) == '\0') {
		settings.gameMode = SINGLEPLAYER_MODE;
		printMessage(RUNNING_SIMGLEPLAYER_MODE);
	} else {
		printMessage(WRONG_GAME_MODE);
	}
	return settings;
}

Settings setUserColor(Settings settings, char* cmd) {
	if(settings.gameMode == MULTIPLAYER_MODE){
		printMessage(ILLEGAL_COMMAND);
		return settings;
	}
	char* cmdValue = strchr(cmd, ' ') + 1;
	settings.userColor = strcmp(cmdValue, "white") == 0 ? WHITE_COLOR : BLACK_COLOR;
	return settings;
}

void removePiece(char** board, char* cmd) {
	char* cmdValue = strchr(cmd, ' ');
	Position p = parsePosition(cmdValue + 1);
	if (validPosition(p))
		board[p.x][p.y] = EMPTY;
	else
		printMessage(WRONG_POSITION);
}

void setPiece(char** board, char* cmd) {
	char* cmdValue = strchr(cmd, ' ') + 1;
	Position p = parsePosition(cmdValue);
	if (!validPosition(p)) {
		printMessage(WRONG_POSITION);
	 } else {
	 	char v = EMPTY;
		cmdValue  = strchr(cmdValue, ' ') + 1;
		char* pieceType = strchr(cmdValue, ' ') + 1;
	 	if (startsWith(cmdValue, "white "))
	 		v = parsePieceName(pieceType, WHITE_COLOR);
	 	else
	 		v = parsePieceName(pieceType, BLACK_COLOR);
	 	if (validAddition(board, p, v))
	 		board[p.x][p.y] = v;
	 	else
	 		printMessage(NO_PIECE);
	 }
}

int getCmdType(char* cmdString) {
	if(startsWith(cmdString, "game_mode "))
		return GAME_MODE_CMD;
	if(startsWith(cmdString, "difficulty depth "))
		return DIFFICULTY_DEPTH_CMD;
	if(startsWith(cmdString, "user_color "))
		return USER_COLOR_CMD;
	if(startsWith(cmdString, "next_player "))
		return NEXT_PLAYER_CMD;
	if(strcmp(cmdString, "clear") == 0)
		return CLEAR_CMD;
	if(startsWith(cmdString, "rm "))
		return RM_CMD;
	if(startsWith(cmdString, "set "))
		return SET_CMD;
	if(strcmp(cmdString, "print") == 0)
		return PRINT_CMD;
	if(strcmp(cmdString, "quit") == 0)
		return QUIT_CMD;
	if(strcmp(cmdString, "start") == 0)
		return START_CMD;
	return UNKNOWN_CMD;
}

bool validAddition(char** board, Position position, char piece) {
	//does not verify resulting board is valid, only that it can add
	return true;//TODO
}

char parsePieceName(char* name, int color) {
	if (strcmp(name, "king") == 0)
		return color == WHITE_COLOR ? WHITE_K : BLACK_K;
	if (strcmp(name, "queen") == 0)
		return color == WHITE_COLOR ? WHITE_Q : BLACK_Q;
	if (strcmp(name, "rook") == 0)
		return color == WHITE_COLOR ? WHITE_R : BLACK_R;
	if (strcmp(name, "knight") == 0)
		return color == WHITE_COLOR ? WHITE_N : BLACK_N;
	if (strcmp(name, "bishop") == 0)
		return color == WHITE_COLOR ? WHITE_B : BLACK_B;
	if (strcmp(name, "pawn") == 0)
		return color == WHITE_COLOR ? WHITE_P : BLACK_P;
	return EMPTY;
}