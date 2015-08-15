#ifndef COMMON_BOARD_H
#define COMMON_BOARD_H

#include "Position.h"

#define WHITE_P 'm'
#define WHITE_B 'b'
#define WHITE_N 'n'
#define WHITE_R 'r'
#define WHITE_Q 'q'
#define WHITE_K 'k'

#define BLACK_P 'M'
#define BLACK_B 'B'
#define BLACK_N 'N'
#define BLACK_R 'R'
#define BLACK_Q 'Q'
#define BLACK_K 'K'

#define EMPTY ' '

#define WHITE_COLOR 1
#define BLACK_COLOR 2
#define otherPlayer(x) (3-x)

char** initBoard();
void clearBoard();
char** mallocBoard();
void freeBoard();
int countPiecesOfType(char** board, char pieceType);
int maxAllowedPiecesOfType(char pieceType);
int pieceOwner(char pieceType);
bool endOfBoard(Position position, int player);
Position getKingPosition(char** board, int player);

#endif