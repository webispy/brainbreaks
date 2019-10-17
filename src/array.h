#ifndef __BRAINBREAKS_ARRAY_H__
#define __BRAINBREAKS_ARRAY_H__

#include <stdbool.h>

int reverseList(int *nums, int numsSize);
int rotateRight(int *nums, int numsSize, int k);
int removeDuplicates(int *nums, int numsSize);
int singleNumber(int *nums, int numsSize);
int *plusOne(int *digits, int digitsSize, int *returnSize);
int *twoSum(int *nums, int numsSize, int target);
int maxProfit(int *prices, int pricesSize);
bool containsDuplicate(int *nums, int numsSize);
int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize);
void moveZeroes(int *nums, int numsSize);
bool isValidSudoku(char **board, int boardRowSize, int boardColSize);
void rotate90(int **matrix, int matrixRowSize, int *matrixColSizes);

#endif
