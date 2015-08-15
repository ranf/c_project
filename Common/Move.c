#include "Move.h"

MoveList* getMoves(char** board, int player, bool verifyKingNotExposed) {
	MoveList* result = NULL;
	for (int i = 0; i < BOARD_SIZE; ++i)
	for (int j = 0; j < BOARD_SIZE; ++j) {
		if (pieceOwner(board[i][j]) == player) {
			Position position = {.x = i, .y = j};
			result = concatMoveLists(result, getPieceMoves(board, position, verifyKingNotExposed));
		}
	}
	return result;
}

bool canMove(char** board, int player) {
	MoveList* moves = getMoves(board, player, true);
	bool result = moves != NULL;
	freeMoves(moves);
	return result;
}

bool isInCheck(char** board, int player) {
	Position kingPosition = getKingPosition(board, player);
	MoveList* otherPlayerMoves = getMoves(board, otherPlayer(player), false);
	bool result = hasMoveAttackingPosition(otherPlayerMoves, kingPosition);
	freeMoves(otherPlayerMoves);
	return result;
}

Move* createMove(Position source, Position target, char promotion) {
	Move* move = safeMalloc(sizeof(Move));
	move->from = source;
	move->to = target;
	move->promotion = promotion;
	return move;
}

MoveList* createMoveList(Move* move) {
	MoveList* list = safeMalloc(sizeof(MoveList));
	list->data = move;
	list->next = NULL;
	return list;
}

MoveList* addToMoveList(MoveList* original, Move* addition) {
	if (original == NULL) {
		return createMoveList(addition);
	}
	MoveList* head = original;
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = createMoveList(addition);
	return original;
}

MoveList* concatMoveLists(MoveList* list1, MoveList* list2) {
	if (list1 == NULL) {
		return list2;
	}
	MoveList* head = list1;
	while (head->next != NULL){
		head = head->next;
	}
	head->next = list2;
	return list1;
}

MoveList* getPieceMoves(char** board, Position source, bool verifyKingNotExposed) {
	char piece = board[source.x][source.y];
	MoveList* result = NULL;
	switch (piece) {
		case WHITE_P:
		case BLACK_P:
			result = pawnMoves(board, source);
			break;
		case WHITE_B:
		case BLACK_B:
			result = bishopMoves(board, source);
			break;
		case WHITE_N:
		case BLACK_N:
			result = knightMoves(board, source);
			break;
		case WHITE_R:
		case BLACK_R:
			result = rookMoves(board, source);
			break;
		case WHITE_Q:
		case BLACK_Q:
			result = queenMoves(board, source);
			break;
		case WHITE_K:
		case BLACK_K:
			result = kingMoves(board, source);
			break;
	}
	if (verifyKingNotExposed) {
		result = removeMovesExposingKing(result, board, pieceOwner(piece));
	}
	return result;
}

MoveList* removeMovesExposingKing(MoveList* list, char** board, int player) {
	while (list != NULL && moveIsExposingKing(board, list->data, player)) {
		MoveList* temp = list;
		list = list->next;
		temp->next = NULL;
		freeMoves(temp);
	}
	MoveList* head = list;
	while (head != NULL && head->next != NULL) {
		if (moveIsExposingKing(board, head->next->data, player)) {
			MoveList* temp = head->next;
			head->next = temp->next;
			temp->next = NULL;
			freeMoves(temp);
		} else {
			head = head->next;
		}
	}
	return list;
}

bool moveIsExposingKing(char** board, Move* move, int player) {
	char** boardCopy = copyBoard(board);
	boardCopy = applyMove(boardCopy, move);
	bool isExposed = isInCheck(boardCopy, player);
	freeBoard(boardCopy);
	return isExposed;
}

bool hasMoveAttackingPosition(MoveList* list, Position target) {
	while (list != NULL) {
		if (positionEquals(list->data->to, target)) {
			return true;
		}
		list = list->next;
	}
	return false;
}

bool moveIsInList(MoveList* list, Move* move) {
	MoveList* head = list;
	while (head != NULL) {
		if(positionEquals(head->data->from, move->from) &&
			positionEquals(head->data->to, move->to)) {
			return true;
		}
		head = head->next;
	}
	return false;
}

char** applyMove(char** board, Move* move) {
	char originalPiece = board[move->from.x][move->from.y];
	board[move->from.x][move->from.y] = EMPTY;
	board[move->to.x][move->to.y] = (endOfBoard(move->to, pieceOwner(originalPiece)) && move->promotion != NO_PROMOTION)
		? move->promotion
		: originalPiece;
	return board;
}

void freeMove(Move* move) {
	free(move);
}

void freeMoves(MoveList* moves) {
	MoveList* head = moves;
	while (head != NULL) {
		MoveList* temp = head;
		head = head->next;
		freeMove(temp->data);
		free(temp);
	}
}