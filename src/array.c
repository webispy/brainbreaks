#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

#ifndef EXPORT_API
#define EXPORT_API
#endif

#define HASHSIZE 8192
#define GOODPRIME 2711 /* Near prime number of 8192/3 */
#define MINUSLIMIT 99 /* Assumed -99 to positive number 0 */
#define HASHFUNC(k) (((k + MINUSLIMIT) * GOODPRIME) & (HASHSIZE - 1))

static int _hash[HASHSIZE];

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
 * #646
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
 * #727
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
 * #549
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
 * #559
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

/**
 * #546
 */
EXPORT_API int *twoSum(int *nums, int numsSize, int target)
{
	int *out;
	int i, j;
	int need;

	if (!nums || numsSize <= 0)
		return NULL;

	memset(_hash, 0, sizeof(_hash));

	out = malloc(sizeof(int) * 2);
	if (!out)
		return NULL;

	for (i = 0; i < numsSize; i++) {
		need = target - *(nums + i);
		j = _hash[HASHFUNC(need)] - 1;
		if (j >= 0) {
			if (i < j) {
				*out = i;
				*(out + 1) = j;
			} else {
				*out = j;
				*(out + 1) = i;
			}
			return out;
		}

		_hash[HASHFUNC(*(nums + i))] = i + 1;
	}

	free(out);
	return NULL;
}

/**
 * #564
 */
EXPORT_API int maxProfit(int *prices, int pricesSize)
{
	int profit = 0;
	int i;
	int stash = -1;

	if (!prices || pricesSize <= 0)
		return 0;

	for (i = 0; i < pricesSize - 1; i++) {
		if (stash == -1) {
			if (prices[i] > prices[i + 1])
				continue;
			stash = prices[i];
		} else {
			if (prices[i] < prices[i + 1])
				continue;
			profit += prices[i] - stash;
			stash = -1;
		}
	}

	if (stash != -1)
		profit += prices[i] - stash;

	return profit;
}