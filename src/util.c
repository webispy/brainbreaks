#include <stdio.h>
#include "util.h"

void dump_array(const char *prefix, int *array, int len)
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
