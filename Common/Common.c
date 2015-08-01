#include "Common.h"

void* safeMalloc(size_t size) {
	void* ptr = malloc(size);
	if(ptr == NULL) {
		printErrorMessage("malloc");
		exit(EXIT_FAILURE);
	}
	return ptr;
}

void* safeRealloc(void* ptr, size_t size) {
	void* newPtr = realloc(ptr, size);
	if(newPtr == NULL) {
		printErrorMessage("realloc");
		exit(EXIT_FAILURE);
	}
	return newPtr;
}

bool startsWith(const char *str, const char *pre) {
	size_t lenpre = strlen(pre);
	size_t lenstr = strlen(str);
	return lenstr < lenpre ? false : strncmp(pre, str, lenpre) == 0;
}

char* skipSpaces(char* str) {
	while (*str == ' ') {
		str = str + 1;
	}
	return str;
}