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