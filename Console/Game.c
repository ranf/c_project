#include "Game.h"

Settings applyGameCommand(Settings settings, char* cmd) {
	if (startsWith(cmd, "move ")) {
		settings = moveCommand(settings, cmd);
		settings.playingColor = otherPlayer(settings.playingColor);
	} else if (startsWith(cmd, "get_moves ")) {
		getMovesForPositionCommand(settings.board, settings.playingColor, cmd);
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
	char promotion = parsePromotion(skipSpaces(targetStr + 5)); // |<a,8>| = 5
	if (!validPosition(source) || !validPosition(target)) {
		printMessage(WRONG_POSITION);
	} else if (pieceOwner(settings.board[source.x][source.y]) != settings.playingColor) {
		printMessage(NOT_YOUR_PIECE);
	} else {
		Move* wantedMove = createMove(source, target, promotion);
		MoveList* pieceMoves = getPieceMoves(settings.board, source);
		if (moveIsInList(pieceMoves, wantedMove)) {
			settings.board = applyMove(settings.board, wantedMove);
		} else {
			printMessage(ILLEGAL_MOVE);
		}
		freeMove(wantedMove);
		if (pieceMoves != NULL)
			freeMoves(pieceMoves);
	}
	return settings;
}

void getMovesForPositionCommand(char** board, int player, char* cmd) {
	char* positionStr = skipSpaces(cmd + 9); // |get_moves| = 9
	Position piecePosition = parsePosition(positionStr);
	if (!validPosition(piecePosition)) {
		printMessage(WRONG_POSITION);
	} else if (pieceOwner(board[piecePosition.x][piecePosition.y] != player)) {
		printMessage(NOT_YOUR_PIECE);
	} else {
		MoveList* moves = getPieceMoves(board, piecePosition);
		printAllMoves(moves);
		freeMoves(moves);
	}
}

void printAllMoves(MoveList* moves) {
	MoveList* head = moves;
	while(head) {
		printMove(head->data);
		head = head->next;
	}
}

void printMove(Move* move) {
	char result[MAX_MOVE_LENGTH];
	result[0] = '\0';
	char tempPositionString[7];
	positionToString(move->from, tempPositionString);
	strcat(result, tempPositionString);
	strcat(result, " to ");
	positionToString(move->to, tempPositionString);
	strcat(result, tempPositionString);
	PositionList* dest = move->to;
	while(dest){
		positionToString(dest->data, tempPositionString);
		strcat(result, tempPositionString);
		dest = dest->next;
	}
	printf("%s\n", result);
}