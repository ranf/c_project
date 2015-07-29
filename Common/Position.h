#ifndef COMMON_POSITION_H
#define COMMON_POSITION_H

#include "Common.h"

#define BOARD_SIZE 8

typedef struct {
	int x;
	int y;
} Position;

Position parsePosition(char* positionString);
bool validPosition(Position position);

#endif