#include "MoveLogic.h"

MoveList* pawnMoves(char** board, Position source) {
	MoveList* result = NULL;
	int player = pieceOwner(board[source.x][source.y]);
	Position forwardPosition = player == WHITE_COLOR
		? (Position) {.x = source.x, .y = source.y + 1}
		: (Position) {.x = source.x, .y = source.y - 1};
	Position leftDiagonal = player == WHITE_COLOR
		? (Position) {.x = source.x - 1, .y = source.y + 1}
		: (Position) {.x = source.x - 1, .y = source.y - 1};
	Position rightDiagonal = player == WHITE_COLOR
		? (Position) {.x = source.x + 1, .y = source.y + 1}
		: (Position) {.x = source.x + 1, .y = source.y - 1};

	if (validPosition(forwardPosition) && board[forwardPosition.x][forwardPosition.y] == EMPTY) {
		result = endOfBoard(forwardPosition, player)
			? addPromotionMoves(result, source, forwardPosition, player)
			: addToMoveList(result, createMove(source, forwardPosition, NO_PROMOTION, false));
	}

	if (validPosition(leftDiagonal) && pieceOwner(board[leftDiagonal.x][leftDiagonal.y]) == otherPlayer(player)) {
		result = endOfBoard(leftDiagonal, player)
			? addPromotionMoves(result, source, leftDiagonal, player)
			: addToMoveList(result, createMove(source, leftDiagonal, NO_PROMOTION, false));
	}

	if (validPosition(rightDiagonal) && pieceOwner(board[rightDiagonal.x][rightDiagonal.y]) == otherPlayer(player)) {
		result = endOfBoard(rightDiagonal, player)
			? addPromotionMoves(result, source, rightDiagonal, player)
			: addToMoveList(result, createMove(source, rightDiagonal, NO_PROMOTION, false));
	}

	return result;
}

MoveList* bishopMoves(char** board, Position source) {
	MoveList* result = NULL;
	int player = pieceOwner(board[source.x][source.y]);

	result = addMovesUntilBlocked(result, board, source, player, &upperLeftDiagonalPosition);
	result = addMovesUntilBlocked(result, board, source, player, &upperRightDiagonalPosition);
	result = addMovesUntilBlocked(result, board, source, player, &lowerLeftDiagonalPosition);
	result = addMovesUntilBlocked(result, board, source, player, &lowerRightDiagonalPosition);

	return result;
}

MoveList* knightMoves(char** board, Position source) {
	MoveList* result = NULL;
	int player = pieceOwner(board[source.x][source.y]);

	Position target1 = {.x = source.x + 2, .y = source.y + 1};
	Position target2 = {.x = source.x + 2, .y = source.y - 1};
	Position target3 = {.x = source.x - 2, .y = source.y + 1};
	Position target4 = {.x = source.x - 2, .y = source.y - 1};
	Position target5 = {.x = source.x + 1, .y = source.y + 2};
	Position target6 = {.x = source.x + 1, .y = source.y - 2};
	Position target7 = {.x = source.x - 1, .y = source.y + 2};
	Position target8 = {.x = source.x - 1, .y = source.y - 2};

	result = addIfNotOccupiedByPlayer(result, board, source, player, target1);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target2);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target3);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target4);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target5);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target6);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target7);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target8);
	
	return result;
}

MoveList* rookMoves(char** board, Position source) {
	MoveList* result = NULL;
	int player = pieceOwner(board[source.x][source.y]);

	result = addMovesUntilBlocked(result, board, source, player, &upperDirectionPosition);
	result = addMovesUntilBlocked(result, board, source, player, &rightDirectionPosition);
	result = addMovesUntilBlocked(result, board, source, player, &leftDirectionPosition);
	result = addMovesUntilBlocked(result, board, source, player, &lowerDirectionPosition);

	return result;
}

MoveList* queenMoves(char** board, Position source) {
	MoveList* result = NULL;
	int player = pieceOwner(board[source.x][source.y]);

	result = addMovesUntilBlocked(result, board, source, player, &upperLeftDiagonalPosition);
	result = addMovesUntilBlocked(result, board, source, player, &upperRightDiagonalPosition);
	result = addMovesUntilBlocked(result, board, source, player, &lowerLeftDiagonalPosition);
	result = addMovesUntilBlocked(result, board, source, player, &lowerRightDiagonalPosition);
	result = addMovesUntilBlocked(result, board, source, player, &upperDirectionPosition);
	result = addMovesUntilBlocked(result, board, source, player, &rightDirectionPosition);
	result = addMovesUntilBlocked(result, board, source, player, &leftDirectionPosition);
	result = addMovesUntilBlocked(result, board, source, player, &lowerDirectionPosition);

	return result;
}

MoveList* kingMoves(char** board, Position source) {
	MoveList* result = NULL;
	int player = pieceOwner(board[source.x][source.y]);

	Position target1 = {.x = source.x, .y = source.y + 1};
	Position target2 = {.x = source.x, .y = source.y - 1};
	Position target3 = {.x = source.x + 1, .y = source.y + 1};
	Position target4 = {.x = source.x + 1, .y = source.y - 1};
	Position target5 = {.x = source.x + 1, .y = source.y};
	Position target6 = {.x = source.x - 1, .y = source.y + 1};
	Position target7 = {.x = source.x - 1, .y = source.y - 1};
	Position target8 = {.x = source.x - 1, .y = source.y};

	result = addIfNotOccupiedByPlayer(result, board, source, player, target1);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target2);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target3);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target4);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target5);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target6);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target7);
	result = addIfNotOccupiedByPlayer(result, board, source, player, target8);
	
	return result;
}

MoveList* addPromotionMoves(MoveList* list, Position source, Position target, int player) {
	return player == WHITE_COLOR
		? addToMoveList(addToMoveList(addToMoveList(addToMoveList(list,
			createMove(source, target, WHITE_Q, false)),
			createMove(source, target, WHITE_R, false)),
			createMove(source, target, WHITE_N, false)),
			createMove(source, target, WHITE_B, false))
		: addToMoveList(addToMoveList(addToMoveList(addToMoveList(list,
			createMove(source, target, BLACK_Q, false)),
			createMove(source, target, BLACK_R, false)),
			createMove(source, target, BLACK_N, false)),
			createMove(source, target, BLACK_B, false));
}

MoveList* addMovesUntilBlocked(MoveList* list, char** board, Position source, int player, Position (*direction)(Position)) {
	Position target = direction(source);
	
	while (validPosition(target) && board[target.x][target.y] == EMPTY) {
		list = addToMoveList(list, createMove(source, target, NO_PROMOTION, false));
		target = direction(target);
	}
	
	if (validPosition(target) && pieceOwner(board[target.x][target.y]) == otherPlayer(player)) {
		list = addToMoveList(list, createMove(source, target, NO_PROMOTION, false));
	}
	
	return list;
}

MoveList* addIfNotOccupiedByPlayer(MoveList* list, char** board, Position source, int player, Position target) {
	if (validPosition(target) && pieceOwner(board[target.x][target.y]) != player) {
		return addToMoveList(list, createMove(source, target, NO_PROMOTION, false));
	}
	return list;
}