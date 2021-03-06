#ifndef COMMON_H
#define COMMON_H

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define printMessage(message) (printf("%s", message))
#define printErrorMessage(func_name) (fprintf(stderr, "Error: standard function %s has failed\n", func_name))

void* safeMalloc(size_t size);
void* safeRealloc(void* ptr, size_t size);
bool startsWith(const char *str, const char *pre);
char* skipSpaces(char* str);

#define BOARD_SIZE 8

#endif
