#include <stdio.h>
#include <string.h>

#include "util.h"

#ifndef EXPORT_API
#define EXPORT_API
#endif

EXPORT_API void dump_array(const char *prefix, int *array, int len)
{
	int i;

	if (!array || len <= 0)
		return;

	printf("%s: ", prefix);
	for (i = 0; i < len; i++) {
		printf("%d", array[i]);
		if (i != len - 1)
			printf(", ");
	}
	printf("\n");
}

EXPORT_API void dump_array2d(const char *prefix, int **array, int row, int col)
{
	int i, j;
	int *ptr = (int *)array;

	printf("%s (row=%d, col=%d)\n", prefix, row, col);

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%2d ", *((ptr + i * col) + j));
		}
		printf("\n");
	}
}
