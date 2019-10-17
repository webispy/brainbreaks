#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"
#include "util.h"

/**
 * #879
 */
char *reverseString(char* s)
{
	int i = 0, len = 0;
	char buf;

	if (!s)
		return NULL;

	if (s[0] == '\0')
		return s;

	while(s[len] != '\0')
		len++;
	len--;

	while(i < len) {
		buf = s[len];
		s[len] = s[i];
		s[i] = buf;

		len--;
		i++;
	}

	return s;
}

/**
 * #880
 */
int reverseDigits(int x)
{
	unsigned int v;
	unsigned int result = 0;

	if (x == 0)
		return x;

	if (x < 0)
		v = (unsigned int)(x * -1);
	else
		v = (unsigned int)x;

#define NUM_LIMIT (((unsigned int)(1 << 31) - 1) / 10)

	while (v) {
		if (result > NUM_LIMIT)
			return 0;

		result = result * 10 + v % 10;
		v = v / 10;
	}

#undef NUM_LIMIT

	if (x < 0)
		return (int)result * -1;

	return (int)result;
}
