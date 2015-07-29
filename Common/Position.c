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

bool validPosition(Position p) {
	return position.x > -1 && position.x < BOARD_SIZE &&
		position.y > -1 && position.y < BOARD_SIZE;
}