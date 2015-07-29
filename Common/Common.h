#ifndef COMMON_H
#define COMMON_H

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define printErrorMessage(func_name) (fprintf(stderr, "Error: standard function %s has failed\n", func_name))

void* safeMalloc(size_t size);
void* safeRealloc(void* ptr, size_t size);
bool startsWith(const char *str, const char *pre);

#endif