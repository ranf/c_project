#include "Position.h"

void positionToString(Position position, char* str) {
	str[0] = '<';
	str[1] = position.x + 'a';
	str[2] = ',';
	if(position.y >= 9) {
		str[3] = ((position.y + 1) / 10)  + '0';
		str[4] = ((position.y + 1) % 10)  + '0';
		str[5] = '>';
		str[6] = '\0';
	} else {
		str[3] = position.y + '1';
		str[4] = '>';
		str[5] = '\0';
	}
}
