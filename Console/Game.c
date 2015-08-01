#include "Game.h"

Settings applyGameCommand(Settings settings, char* cmd) {
	if (startsWith(cmd, "move ")) {
		settings = moveCommand(settings, cmd);
		settings.playingColor = otherPlayer(settings.playingColor);
	} else if (strcmp(cmd, "get_moves") == 0) {
		MoveList* moves = getMoves(settings.board, settings.playingColor);
		printAllMoves(moves);
		freeMoves(moves);
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