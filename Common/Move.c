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

MoveList* getPieceMoves(char** board, Position source) {
	return NULL; //TODO
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

void applyMove(char** board, Move* move) {
	char originalPiece = board[move->from.x][move->from.y];
	board[move->to.x][move->to.y] = endOfBoard(move->to, pieceOwner(originalPiece))
		? move->promotion
		: originalPiece;
}

void freeMove(Move* move) {
	free(move)
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