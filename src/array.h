#ifndef __BRAINBREAKS_ARRAY_H__
#define __BRAINBREAKS_ARRAY_H__

#include <stdbool.h>

int reverse(int *nums, int numsSize);
int rotateRight(int *nums, int numsSize, int k);
int removeDuplicates(int *nums, int numsSize);
int singleNumber(int *nums, int numsSize);
int *plusOne(int *digits, int digitsSize, int *returnSize);
int *twoSum(int *nums, int numsSize, int target);
int maxProfit(int *prices, int pricesSize);
bool containsDuplicate(int *nums, int numsSize);

#endif
