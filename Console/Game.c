#include "Game.h"

Settings applyGameCommand(Settings settings, char* cmd) {
	if (startsWith(cmd, "move ")) {
		settings = moveCommand(settings, cmd);
	} else if (startsWith(cmd, "get_moves ")) {
		getMovesForPositionCommand(settings.board, settings.playingColor, cmd);
	} else if (startsWith(cmd, "get_best_moves ")) {
		getBestMovesCommand(settings.board, settings.playingColor, skipSpaces(cmd + 14));//|get_best_moves|
	} else if (startsWith(cmd, "get_score ")) {
		getScoreCommand(settings.board, settings.playingColor, cmd);
	} else if (startsWith(cmd, "save ")) {
		saveSettings(settings, skipSpaces(cmd + 4)); //|save|=4
	} else if (strcmp(cmd, "quit") == 0) {
		settings.state = TERMINATE_STATE;
	} else {
		printMessage(ILLEGAL_COMMAND);
	}
	return settings;
}

Settings moveCommand(Settings settings, char* cmd) {
	char* sourceStr = skipSpaces(cmd + 4); // |move| = 4
	Position source = parsePosition(sourceStr);
	char* targetStr = skipSpaces(skipSpaces(sourceStr + 5) + 2); // |<a,8>| = 5, |to| = 2
	Position target = parsePosition(targetStr);
	char promotion = parsePromotion(skipSpaces(targetStr + 5), settings.playingColor); // |<a,8>| = 5
	if (!validPosition(source) || !validPosition(target)) {
		printMessage(WRONG_POSITION);
	} else if (pieceOwner(settings.board[source.x][source.y]) != settings.playingColor) {
		printMessage(NOT_YOUR_PIECE);
	} else {
		Move* wantedMove = createMove(source, target, promotion);
		MoveList* pieceMoves = getPieceMoves(settings.board, source, true);
		if (moveIsInList(pieceMoves, wantedMove)) {
			settings.board = applyMove(settings.board, wantedMove);
			settings = endOfTurn(settings);
		} else {
			printMessage(ILLEGAL_MOVE);
		}
		freeMove(wantedMove);
		if (pieceMoves != NULL)
			freeMoves(pieceMoves);
	}
	return settings;
}

Settings endOfTurn(Settings settings) {
	settings.playingColor = otherPlayer(settings.playingColor);
	printBoard(settings.board);
	bool check = isInCheck(settings.board, settings.playingColor);
	bool stuck = !canMove(settings.board, settings.playingColor);
	if (check && stuck) {
		printMessage(settings.playingColor == WHITE_COLOR ? BLACK_WON : WHITE_WON);
		settings.state = TERMINATE_STATE;
	} else if (stuck) {
		printMessage(TIE);
		settings.state = TERMINATE_STATE;
	} else if (check) {
		printMessage(CHECK);
	}
	return settings;
}

void getMovesForPositionCommand(char** board, int player, char* cmd) {
	char* positionStr = skipSpaces(cmd + 9); // |get_moves| = 9
	Position piecePosition = parsePosition(positionStr);
	if (!validPosition(piecePosition)) {
		printMessage(WRONG_POSITION);
	} else if (pieceOwner(board[piecePosition.x][piecePosition.y]) != player) {
		printMessage(NOT_YOUR_PIECE);
	} else {
		MoveList* moves = getPieceMoves(board, piecePosition, true);
		printAllMoves(moves);
		freeMoves(moves);
	}
}

void getBestMovesCommand(char** board, int player, char* depth) {
	int minimaxDepth = strcmp(depth, "best") == 0 ? BEST_DEPTH : (*depth) - '0';
	MoveList* moves = getAllMinimaxMoves(board, player, minimaxDepth);
	printAllMoves(moves);
	freeMoves(moves);
}

void getScoreCommand(char** board, int player, char* cmd) {
	char* depthPtr = skipSpaces(cmd + 9); //|get_score|
	char* movePtr;
	int depth;
	if (depthPtr[0] == 'b' && depthPtr[1] == 'e' &&
		depthPtr[2] == 's' && depthPtr[3] == 't') {
		depth = BEST_DEPTH;
		movePtr = skipSpaces(depthPtr + 4);
	} else {
		depth = *depthPtr - '0';
		movePtr = skipSpaces(depthPtr + 1);
	}
	movePtr = skipSpaces(movePtr + 4);//move
	Position source = parsePosition(movePtr);
	char* targetPtr = skipSpaces(skipSpaces(movePtr + 5) + 2);
	Position target = parsePosition(targetPtr);
	char promotion = parsePromotion(skipSpaces(targetPtr + 5), player);
	Move* move = createMove(source, target, promotion);
	int score = scoreMove(board, move, player, depth);
	freeMove(move);
	printf("%d\n", score);
}

void printAllMoves(MoveList* moves) {
	MoveList* head = moves;
	while(head) {
		printMove(head->data);
		head = head->next;
	}
}

void printMove(Move* move) {
	char result[25];  // |<a,7> to <a,8> bishop| = 21
	result[0] = '\0';
	char tempPositionString[7];
	positionToString(move->from, tempPositionString);
	strcat(result, tempPositionString);
	strcat(result, " to ");
	positionToString(move->to, tempPositionString);
	strcat(result, tempPositionString);
	if(move->promotion != NO_PROMOTION) {
		strcat(result, " ");
		strcat(result, getPieceName(move->promotion));
	}
	printf("%s\n", result);
}

char parsePromotion(char* str, int player) {
	if (strcmp(str, "bishop") == 0)
		return player == WHITE_COLOR ? WHITE_B : BLACK_B;
	if (strcmp(str, "rook") == 0)
		return player == WHITE_COLOR ? WHITE_R : BLACK_R;
	if (strcmp(str, "knight") == 0)
		return player == WHITE_COLOR ? WHITE_N : BLACK_N;
	return player == WHITE_COLOR ? WHITE_Q : BLACK_Q;
}

char* getPieceName(char piece) {
	switch(piece) {
		case WHITE_P:
		case BLACK_P:
			return "pawn";
		case WHITE_B:
		case BLACK_B:
			return "bishop";
		case WHITE_N:
		case BLACK_N:
			return "knight";
		case WHITE_R:
		case BLACK_R:
			return "rook";
		case WHITE_Q:
		case BLACK_Q:
			return "queen";
		case WHITE_K:
		case BLACK_K:
			return "king";
	}
	return "";
}