#include "Position.h"

Position parsePosition(char* positionString) {
	Position p = {.x = -1, .y = -1};
	if(positionString == NULL || strlen(positionString) < 5 ||
		positionString[0] != '<' || positionString[2] != ','||
		(positionString[4] != '>'  && positionString[5] != '>')) {
		return p;
	}
	char xLetter = positionString[1];
	p.y = atoi(positionString + 3) - 1;
	p.x = xLetter - 'a';
	return p;
}

bool validPosition(Position position) {
	return position.x > -1 && position.x < BOARD_SIZE &&
		position.y > -1 && position.y < BOARD_SIZE;
}

bool positionEquals(Position p1, Position p2) {
	return p1.x == p2.x && p1.y == p2.y;
}

Position upperLeftDiagonalPosition(Position source) {
	return (Position) {.x = source.x - 1, .y = source.y + 1};
}

Position upperDirectionPosition(Position source) {
	return (Position) {.x = source.x, .y = source.y + 1};
}

Position upperRightDiagonalPosition(Position source) {
	return (Position) {.x = source.x + 1, .y = source.y + 1};
}

Position leftDirectionPosition(Position source) {
	return (Position) {.x = source.x - 1, .y = source.y};
}

Position rightDirectionPosition(Position source) {
	return (Position) {.x = source.x + 1, .y = source.y};
}

Position lowerLeftDiagonalPosition(Position source) {
	return (Position) {.x = source.x - 1, .y = source.y - 1};
}

Position lowerDirectionPosition(Position source) {
	return (Position) {.x = source.x, .y = source.y - 1};
}

Position lowerRightDiagonalPosition(Position source) {
	return (Position) {.x = source.x + 1, .y = source.y - 1};
}
