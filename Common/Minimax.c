#include "Minimax.h"

Move* getMinimaxMove(char** board, int player, int minimaxDepth) {
	return alphaBetaMinimax(minimaxDepth, -MAX_SCORE, MAX_SCORE, board, player, player == WHITE_COLOR).move;
}

ScoredMove alphaBetaMinimax(int depth, int alpha, int beta, char** board, int player, bool maximize) {
	ScoredMove result = {.move = NULL, .score = 0};
	MoveList* children;
	if (depth == 0 || (children = getMoves(board, player, true)) == NULL) {
		result.score = scoreBoard(board, player);
		return result;
	}
	result.score = maximize ? -MAX_SCORE : MAX_SCORE;
	bool prune = false;
	MoveList* head = children;
	while (head != NULL && !prune) {
		char** boardCopy = copyBoard(board);
		boardCopy = applyMove(boardCopy, head->data);
		ScoredMove otherPlayerMove = alphaBetaMinimax(depth - 1, alpha, beta, boardCopy, otherPlayer(player), !maximize);
		freeBoard(boardCopy);
		if (maximize) {
			if (otherPlayerMove.score > result.score) {
				if(result.move != NULL) {
					freeMove(result.move);
				}
				result.score = otherPlayerMove.score;
				result.move = copyMove(head->data);
			}
			if (result.score > alpha){
				alpha = result.score;
			}
		} else { //minimize
			if (otherPlayerMove.score < result.score) {
				if (result.move != NULL) {
					freeMove(result.move);
				}
				result.score = otherPlayerMove.score;
				result.move = copyMove(head->data);
			}
			if (result.score < beta) {
				beta = result.score;
			}
		}
		if (otherPlayerMove.move != NULL) {
			freeMove(otherPlayerMove.move);
		}
		head = head->next;
		if (beta <= alpha) {
			prune = true;
		}
	}
	freeMoves(children);
	return result;
}

int scoreBoard(char** board, int player) {
	if (!canMove(board, player)) {
		if(isInCheck(board, player)) {
			return player == WHITE_COLOR ? BLACK_WIN_SCORE : WHITE_WIN_SCORE;
		} else {
			return TIE_SCORE;
		}
	}
	int score = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	for (int j = 0; j < BOARD_SIZE; j++){
		score += scoreChar(board[i][j]);
	}
	return score;
}

int scoreChar(char piece) {
	switch (piece) {
		case WHITE_P:
			return 1;
		case BLACK_P:
			return -1;
		case WHITE_B:
			return 3;
		case BLACK_B:
			return -3;
		case WHITE_N:
			return 3;
		case BLACK_N:
			return -3;
		case WHITE_R:
			return 5;		
		case BLACK_R:
			return -5;
		case WHITE_Q:
			return 9;
		case BLACK_Q:
			return -9;
		case WHITE_K:
			return 400;
		case BLACK_K:
			return -400;
		default:
			return 0;
	}
}