#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

EXPORT_API int reverse(int *nums, int numsSize)
{
	int i = 0;
	int j = numsSize - 1;
	int tmp;

	if (!nums || numsSize <= 0)
		return -1;

	for (; i < numsSize / 2; i++, j--) {
		tmp = *(nums + i);
		*(nums + i) = *(nums + j);
		*(nums + j) = tmp;
	}

	return 0;
}

/**
 * #189
 */
EXPORT_API int rotateRight(int *nums, int numsSize, int k)
{
	if (!nums || numsSize <= 0 || k < 0)
		return -1;

	k = k % numsSize;
	reverse(nums, numsSize);
	reverse(nums, k);
	reverse(nums + k, numsSize - k);

	return 0;
}

/**
 * #26
 */
EXPORT_API int removeDuplicates(int *nums, int numsSize)
{
	int pos;
	int i;

	if (!nums || numsSize <= 0)
		return -1;

	if (numsSize < 2)
		return numsSize;

	for (i = 1, pos = 1; i < numsSize; i++) {
		if (*(nums + i - 1) == *(nums + i))
			continue;

		*(nums + pos) = *(nums + i);
		pos++;
	}

	return pos;
}

/**
 * #136
 */
EXPORT_API int singleNumber(int *nums, int numsSize)
{
	int i;
	int result = 0;

	if (!nums || numsSize <= 0)
		return -1;

	for (i = 0; i < numsSize; i++)
		result = result ^ *(nums + i);

	return result;
}

/**
 * #66
 */
EXPORT_API int *plusOne(int *digits, int digitsSize, int *returnSize)
{
	int *out;
	int i;
	int carry = 1;

	if (!digits || digitsSize <= 0 || !returnSize)
		return NULL;

	for (i = digitsSize - 1; i >= 0; i--) {
		if (*(digits + i) + carry < 10) {
			carry = 0;
			break;
		}
	}

	out = calloc(1, sizeof(int) * (digitsSize + carry));
	if (!out)
		return NULL;

	memcpy(out + carry, digits, sizeof(int) * digitsSize);
	*returnSize = digitsSize + carry;

	i += carry;
	for (; i < digitsSize + carry; i++)
		*(out + i) = (*(out + i) + 1) % 10;

	return out;
}

EXPORT_API int *twoSum(int *nums, int numsSize, int target)
{
	int *out;
	int i, j;

	if (!nums || numsSize <= 0)
		return NULL;

	out = malloc(sizeof(int) * 2);
	if (!out)
		return NULL;

	for (i = 0; i < numsSize - 1; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (*(nums + i) + *(nums + j) == target) {
				*out = i;
				*(out + 1) = j;
				return out;
			}
		}
	}

	free(out);
	return NULL;
}
