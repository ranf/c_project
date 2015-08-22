#include "Minimax.h"

Move* getMinimaxMove(char** board, int player, int minimaxDepth) {
	ScoredMoves bestMoves = (minimaxDepth == BEST_DEPTH)
		? bestMinimax(board, player)
		: alphaBetaMinimax(minimaxDepth, -MAX_SCORE, MAX_SCORE, board, player, player == WHITE_COLOR);
	if(bestMoves.moves == NULL)
		return NULL;
	Move* result = copyMove(bestMoves.moves->data);
	freeMoves(bestMoves.moves);
	return result;
}

MoveList* getAllMinimaxMoves(char** board, int player, int minimaxDepth) {
	ScoredMoves bestMoves = (minimaxDepth == BEST_DEPTH)
		? bestMinimax(board, player)
		: alphaBetaMinimax(minimaxDepth, -MAX_SCORE, MAX_SCORE, board, player, player == WHITE_COLOR);
	return bestMoves.moves;
}

int scoreMove(char** board, Move* move, int player, int minimaxDepth) {
	char** boardCopy = copyBoard(board);
	boardCopy = applyMove(boardCopy, move);
	ScoredMoves minimaxResult = (minimaxDepth == BEST_DEPTH)
		? bestMinimax(boardCopy, otherPlayer(player))
		: alphaBetaMinimax(minimaxDepth - 1, -MAX_SCORE, MAX_SCORE, boardCopy, otherPlayer(player), player == BLACK_COLOR);
	int score = minimaxResult.score;
	freeBoard(boardCopy);
	if(minimaxResult.moves != NULL)
		freeMoves(minimaxResult.moves);
	return score;
}

ScoredMoves alphaBetaMinimax(int depth, int alpha, int beta, char** board, int player, bool maximize) {
	ScoredMoves result = {.moves = NULL, .score = 0};
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
		ScoredMoves otherPlayerMoves = alphaBetaMinimax(depth - 1, alpha, beta, boardCopy, otherPlayer(player), !maximize);
		freeBoard(boardCopy);
		if (maximize) {
			if (otherPlayerMoves.score > result.score) {
				if (result.moves != NULL) {
					freeMoves(result.moves);
				}
				result.score = otherPlayerMoves.score;
				result.moves = createMoveList(copyMove(head->data));
			} else if (otherPlayerMoves.score == result.score) {
				result.moves = concatMoveLists(result.moves, createMoveList(copyMove(head->data)));
			}
			if (result.score > alpha){
				alpha = result.score;
			}
		} else { //minimize
			if (otherPlayerMoves.score < result.score) {
				if (result.moves != NULL) {
					freeMoves(result.moves);
				}
				result.score = otherPlayerMoves.score;
				result.moves = createMoveList(copyMove(head->data));
			}
			else if (otherPlayerMoves.score == result.score) {
				result.moves = concatMoveLists(result.moves, createMoveList(copyMove(head->data)));
			}
			if (result.score < beta) {
				beta = result.score;
			}
		}
		if (otherPlayerMoves.moves != NULL) {
			freeMoves(otherPlayerMoves.moves);
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

ScoredMoves bestMinimax(char** board, int player) {
	// get max number of moves for round i -> n_i
	// one board per move
	// therefore for depth x, evaluating at most (n_1*...*n_x) -> y boards
	// maximize(x) s.t.{ y <= BEST_MINIMAX_UPPER_BOUND }
	int upperBound = BEST_MINIMAX_UPPER_BOUND;
	int depth = 0;
	int currentPlayer = player;
	int maxMoves = getMaxMoves(board, currentPlayer, 0);
	while (upperBound >= maxMoves) {
		depth++;
		upperBound /= maxMoves;
		currentPlayer = otherPlayer(currentPlayer);
		// |_depth/2_| is number previous moves by this player
		maxMoves = getMaxMoves(board, currentPlayer, depth / 2);
	}
	return alphaBetaMinimax(depth, -MAX_SCORE, MAX_SCORE, board, player, player == WHITE_COLOR);
}

int getMaxMoves(char** board, int player, int possibleMovesAlready) {
	//since in chess you cannot obtain additional pieces, the upper bound (using simple counting)
	//	on the number of moves the player can make cannot increase (except promotion, see below).
	int max = 0;
	for(int i = 0; i < BOARD_SIZE; i++)
	for(int j = 0; j < BOARD_SIZE; j++) {
		char piece = board[i][j];
		if(player == WHITE_COLOR){
			switch(piece) {
				case WHITE_P:
							//==cannot be promoted
					max += (j + possibleMovesAlready < BOARD_SIZE - 1) ? P_MAX_MOVES : Q_MAX_MOVES;
					break;
				case WHITE_B:
					max += B_MAX_MOVES;
					break;
				case WHITE_N:
					max += N_MAX_MOVES;
					break;
				case WHITE_R:
					max+= R_MAX_MOVES;
					break;
				case WHITE_Q:
					max += Q_MAX_MOVES;
					break;
				case WHITE_K:
					max += K_MAX_MOVES;
					break;
			}
		} else {
			switch(piece) {
				case BLACK_P:
					max += (j - possibleMovesAlready > 0) ? P_MAX_MOVES : Q_MAX_MOVES;
					break;
				case BLACK_B:
					max += B_MAX_MOVES;
					break;
				case BLACK_N:
					max += N_MAX_MOVES;
					break;
				case BLACK_R:
					max+= R_MAX_MOVES;
					break;
				case BLACK_Q:
					max += Q_MAX_MOVES;
					break;
				case BLACK_K:
					max += K_MAX_MOVES;
					break;
			}
		}
	}
	return max;
}