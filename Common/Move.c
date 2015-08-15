#include "Move.h"

MoveList* getMoves(char** board, int player) {
	return NULL; //TODO
}

Move* createMove(Position source, Position target, char promotion, bool isCastling) {
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

MoveList* getPieceMoves(char** board, Position source) {
	char piece = board[source.x][source.y];
	switch (piece) {
		case WHITE_P:
		case BLACK_P:
			return pawnMoves(board, source);
		case WHITE_B:
		case BLACK_B:
			return bishopMoves(board, source);
		case WHITE_N:
		case BLACK_N:
			return knightMoves(board, source);
		case WHITE_R:
		case BLACK_R:
			return rookMoves(board, source);
		case WHITE_Q:
		case BLACK_Q:
			return queenMoves(board, source);
		case WHITE_K:
		case BLACK_K:
			return kingMoves(board, source);
	}
	return NULL;
}

bool moveIsInList(MoveList* list, Move* move) {
	MoveList* head = list;
	while (head != NULL) {
		if(positionEquals(head->data->from, move->from) &&
			positionEquals(head->data->to, move->to)) {
			return true;
		}
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