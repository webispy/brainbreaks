#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "util.h"

#ifndef EXPORT_API
#define EXPORT_API
#endif

/**
 * Simple hash
 */
#define HASHSIZE 8192
#define GOODPRIME 2711 /* Near prime number of 8192/3 */
#define MINUSLIMIT 99 /* Assumed -99 to positive number 0 */
#define HASHFUNC(k) (((k + MINUSLIMIT) * GOODPRIME) & (HASHSIZE - 1))

static int _hash[HASHSIZE];

/**
 * pre-calculated table for 2^N
 */
static int pow2[] = {1,2,4,8,16,32,64,128};

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

/**
 * #578
 */
EXPORT_API bool containsDuplicate(int *nums, int numsSize)
{
	int i;
	char *buf;
	int max = 0, min = 9999999;
	int digit;
	bool result = false;
	int v;

	if (!nums || numsSize <= 0)
		return false;

	for (i = 0; i < numsSize; i++) {
		if (nums[i] > max)
			max = nums[i];
		if (nums[i] < min)
			min = nums[i];
	}

	if (min > 0)
		min = 0;
	else {
		min = min * -1;
		max += min;
	}

	buf = calloc(max / 8 + 1, sizeof(char));

	for (i = 0; i < numsSize; i++) {
		v = nums[i] + min;
		digit = v % 8;
		if (buf[v / 8] & pow2[digit]) {
			result = true;
			break;
		}

		buf[v / 8] |= pow2[digit];
	}

	free(buf);
	return result;
}

/**
 * #674
 */
EXPORT_API int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size,
	int *returnSize)
{
	int *result = NULL;
	int i;
	int maxcnt = 0;

	if (!nums1 || nums1Size <= 0 || !nums2 || nums2Size <= 0 || !returnSize)
		return NULL;

	if (nums1Size > nums2Size)
		result = calloc(nums1Size, sizeof(int));
	else
		result = calloc(nums2Size, sizeof(int));

	memset(_hash, 0, sizeof(_hash));

	for (i = 0; i < nums1Size; i++)
		_hash[HASHFUNC(nums1[i])]++;

	for (i = 0; i < nums2Size; i++) {
		if (_hash[HASHFUNC(nums2[i])]) {
			_hash[HASHFUNC(nums2[i])]--;
			result[maxcnt++] = nums2[i];
		}
	}

	*returnSize = maxcnt;

	return result;
}

/**
 * #567
 */
EXPORT_API void moveZeroes(int *nums, int numsSize)
{
	int i;
	int pos = 0;

	for (i = 0; i < numsSize; i++) {
		if (nums[i] == 0)
			continue;

		nums[pos] = nums[i];
		pos++;
	}

	for (i = pos; i < numsSize; i++)
		nums[i] = 0;
}

/**
 * #769
 */
EXPORT_API bool isValidSudoku(char **board, int boardRowSize, int boardColSize)
{
	int rowmap[9][10];
	int colmap[9][10];
	int submap[9][10];
	int i, j;
	int sx, sy;
	int val;

	if (!board || boardRowSize <= 0 || boardColSize <= 0)
		return false;

	memset(rowmap, 0, sizeof(rowmap));
	memset(colmap, 0, sizeof(colmap));
	memset(submap, 0, sizeof(submap));

	for (i = 0; i < boardRowSize; i++) {
		sy = (i / 3) * 3;
		for (j = 0; j < boardColSize; j++) {
			if (board[i][j] == '.')
				continue;

			val = board[i][j] - '0';
			sx = j / 3;

			if (submap[sy + sx][val])
				return false;
			submap[sy + sx][val] = 1;

			if (rowmap[i][val])
				return false;
			rowmap[i][val] = 1;

			if (colmap[j][val])
				return false;
			colmap[j][val] = 1;
		}
	}

	return true;
}