#ifndef COMMON_POSITION_H
#define COMMON_POSITION_H

#include "Common.h"

typedef struct {
	int x;
	int y;
} Position;

Position parsePosition(char* positionString);
bool validPosition(Position position);

Position upperLeftDiagonalPosition(Position source);
Position upperDirectionPosition(Position source);
Position upperRightDiagonalPosition(Position source);
Position leftDirectionPosition(Position source);
Position rightDirectionPosition(Position source);
Position lowerLeftDiagonalPosition(Position source);
Position lowerDirectionPosition(Position source);
Position lowerRightDiagonalPosition(Position source);

#endif