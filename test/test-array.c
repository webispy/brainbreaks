#include <stdio.h>
#include <glib.h>
#include "array.h"

#define COUNT(array) (sizeof(array) / sizeof(array[0]))

static void tc_reverse()
{
	int data1[] = {1,2,3,4};
	int want1[] = {4,3,2,1};
	int data2[] = {1,2,3};
	int want2[] = {3,2,1};

	g_assert(reverse(NULL, 1) == -1);
	g_assert(reverse(data1, 0) == -1);
	g_assert(reverse(data1, COUNT(data1)) == 0);
	g_assert_cmpmem(data1, sizeof(data1), want1, sizeof(want1));
	g_assert(reverse(data2, COUNT(data2)) == 0);
	g_assert_cmpmem(data2, sizeof(data2), want2, sizeof(want2));
}

static void tc_rotateRight()
{
	int data1[] = {1,2,3,4,5,6,7};
	int want1[] = {5,6,7,1,2,3,4};
	int data2[] = {-1,-100,3,99};
	int want2[] = {3,99,-1,-100};
	int data3[] = {1,2,3,4,5,6};
	int want3[] = {5,6,1,2,3,4};

	g_assert(rotateRight(NULL, 1, 0) == -1);
	g_assert(rotateRight(data1, 0, 0) == -1);
	g_assert(rotateRight(data1, 1, -1) == -1);
	g_assert(rotateRight(data1, COUNT(data1), 3) == 0);
	g_assert_cmpmem(data1, sizeof(data1), want1, sizeof(want1));
	g_assert(rotateRight(data2, COUNT(data2), 2) == 0);
	g_assert_cmpmem(data2, sizeof(data2), want2, sizeof(want2));
	g_assert(rotateRight(data3, COUNT(data3), 8) == 0);
	g_assert_cmpmem(data3, sizeof(data3), want3, sizeof(want3));
}

static void tc_removeDuplicates()
{
	int data1[] = {1,1,2};
	int data2[] = {0,0,1,1,1,2,2,3,3,4};

	g_assert(removeDuplicates(NULL, 1) == -1);
	g_assert(removeDuplicates(data1, 0) == -1);
	g_assert(removeDuplicates(data1, COUNT(data1)) == 2);
	g_assert(removeDuplicates(data2, COUNT(data2)) == 5);
}

static void tc_singleNumber()
{
	int data1[] = {2,2,1};
	int data2[] = {4,1,2,1,2};
	int data3[] = {0,2,2,3,3};
	int data4[] = {2,2,3,3,4,4,99};

	g_assert(singleNumber(NULL, 1) == -1);
	g_assert(singleNumber(data1, 0) == -1);
	g_assert(singleNumber(data1, COUNT(data1)) == 1);
	g_assert(singleNumber(data2, COUNT(data2)) == 4);
	g_assert(singleNumber(data3, COUNT(data3)) == 0);
	g_assert(singleNumber(data4, COUNT(data4)) == 99);
}

static void tc_plusOne()
{
	int data1[] = {1,2,3};
	int want1[] = {1,2,4};
	int data2[] = {4,3,2,1};
	int want2[] = {4,3,2,2};
	int data3[] = {9};
	int want3[] = {1,0};
	int data4[] = {1,9};
	int want4[] = {2,0};
	int data5[] = {1,9,9};
	int want5[] = {2,0,0};
	int data6[] = {1,2,9,9};
	int want6[] = {1,3,0,0};
	int *out;
	int new_size = -1;

	g_assert(plusOne(NULL, 1, &new_size) == NULL);
	g_assert(new_size == -1);
	g_assert(plusOne(data1, 0, &new_size) == NULL);
	g_assert(new_size == -1);
	g_assert(plusOne(data1, 1, NULL) == NULL);
	g_assert(new_size == -1);

	out = plusOne(data1, COUNT(data1), &new_size);
	g_assert(out != NULL);
	g_assert(new_size == COUNT(data1));
	g_assert_cmpmem(out, sizeof(int) * new_size, want1, sizeof(want1));
	free(out);

	out = plusOne(data2, COUNT(data2), &new_size);
	g_assert(out != NULL);
	g_assert(new_size == COUNT(data2));
	g_assert_cmpmem(out, sizeof(int) * new_size, want2, sizeof(want2));
	free(out);

	out = plusOne(data3, COUNT(data3), &new_size);
	g_assert(out != NULL);
	g_assert(new_size == (COUNT(data3)) + 1);
	g_assert_cmpmem(out, sizeof(int) * new_size, want3, sizeof(want3));
	free(out);

	out = plusOne(data4, COUNT(data4), &new_size);
	g_assert(out != NULL);
	g_assert(new_size == COUNT(data4));
	g_assert_cmpmem(out, sizeof(int) * new_size, want4, sizeof(want4));
	free(out);

	out = plusOne(data5, COUNT(data5), &new_size);
	g_assert(out != NULL);
	g_assert(new_size == COUNT(data5));
	g_assert_cmpmem(out, sizeof(int) * new_size, want5, sizeof(want5));
	free(out);

	out = plusOne(data6, COUNT(data6), &new_size);
	g_assert(out != NULL);
	g_assert(new_size == COUNT(data6));
	g_assert_cmpmem(out, sizeof(int) * new_size, want6, sizeof(want6));
	free(out);
}

static void tc_twoSum()
{
	int data1[] = {2,7,11,15};
	int want1[] = {0,1};
	int data2[] = {1,2,3,4,5};
	int want2[] = {2,4};
	int data3[] = {3,3};
	int want3[] = {0,1};
	int data4[] = {0,4,3,0};
	int want4[] = {0,3};
	int data5[] = {-3,4,3,90};
	int want5[] = {0,2};
	int *out;

	g_assert(twoSum(NULL, 1, 0) == NULL);
	g_assert(twoSum(data1, 0, 0) == NULL);

	out = twoSum(data1, COUNT(data1), 10);
	g_assert(out == NULL);

	out = twoSum(data1, COUNT(data1), 9);
	g_assert(out != NULL);
	g_assert_cmpmem(out, sizeof(int) * 2, want1, sizeof(want1));
	free(out);

	out = twoSum(data2, COUNT(data2), 8);
	g_assert(out != NULL);
	g_assert_cmpmem(out, sizeof(int) * 2, want2, sizeof(want2));
	free(out);

	out = twoSum(data3, COUNT(data3), 6);
	g_assert(out != NULL);
	g_assert_cmpmem(out, sizeof(int) * 2, want3, sizeof(want3));
	free(out);

	out = twoSum(data4, COUNT(data4), 0);
	g_assert(out != NULL);
	g_assert_cmpmem(out, sizeof(int) * 2, want4, sizeof(want4));
	free(out);

	out = twoSum(data5, COUNT(data5), 0);
	g_assert(out != NULL);
	g_assert_cmpmem(out, sizeof(int) * 2, want5, sizeof(want5));
	free(out);
}

static void tc_maxProfit()
{
	int data1[] = {7,1,5,3,6,4};
	int data2[] = {1,2,3,4,5};
	int data3[] = {7,6,4,3,1};

	g_assert(maxProfit(NULL, 1) == 0);
	g_assert(maxProfit(data1, 0) == 0);
	g_assert(maxProfit(data1, COUNT(data1)) == 7);
	g_assert(maxProfit(data2, COUNT(data2)) == 4);
	g_assert(maxProfit(data3, COUNT(data3)) == 0);
}

static void tc_containsDuplicate()
{
	int data1[] = {1,2,3,1};
	int data2[] = {1,2,3,4};
	int data3[] = {1,1,1,3,3,4,3,2,4,2};
	int data4[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	int data5[] = {237384,348185,338816,825359,461215,315112,170091};
	int data6[] = {1,5,-2,-4,0};

	g_assert(containsDuplicate(NULL, 1) == false);
	g_assert(containsDuplicate(data1, 0) == false);

	g_assert(containsDuplicate(data1, COUNT(data1)) == true);
	g_assert(containsDuplicate(data2, COUNT(data2)) == false);
	g_assert(containsDuplicate(data3, COUNT(data3)) == true);
	g_assert(containsDuplicate(data4, COUNT(data4)) == false);
	g_assert(containsDuplicate(data5, COUNT(data5)) == false);
	g_assert(containsDuplicate(data6, COUNT(data6)) == false);
}

static void tc_intersect()
{
	int data1_1[] = {1,2,2,1};
	int data1_2[] = {2,2};
	int want1[] = {2,2};
	int data2_1[] = {4,9,5};
	int data2_2[] = {9,4,9,8,4};
	int want2[] = {9,4};
	int data3_1[] = {1,2};
	int data3_2[] = {2,1};
	int want3[] = {2,1};
	int data4_1[] = {9,1};
	int data4_2[] = {7,8,3,9,0,0,9,1,5};
	int want4[] = {9,1};

	int *out;
	int outsize;

	g_assert(intersect(NULL, 1, NULL, 2, NULL) == NULL);
	g_assert(intersect(data1_1, 0, data1_2, 0, NULL) == NULL);

	outsize = 0;
	out = intersect(data1_1, COUNT(data1_1), data1_2,
			COUNT(data1_2), &outsize);
	g_assert(outsize == COUNT(want1));
	g_assert(out != NULL);
	g_assert_cmpmem(out, sizeof(int) * outsize, want1, sizeof(want1));
	free(out);

	outsize = 0;
	out = intersect(data2_1, COUNT(data2_1), data2_2,
			COUNT(data2_2), &outsize);
	g_assert(outsize == COUNT(want2));
	g_assert(out != NULL);
	g_assert_cmpmem(out, sizeof(int) * outsize, want2, sizeof(want2));
	free(out);

	outsize = 0;
	out = intersect(data3_1, COUNT(data3_1), data3_2,
			COUNT(data3_2), &outsize);
	g_assert(outsize == COUNT(want3));
	g_assert(out != NULL);
	g_assert_cmpmem(out, sizeof(int) * outsize, want3, sizeof(want3));
	free(out);

	outsize = 0;
	out = intersect(data4_1, COUNT(data4_1), data4_2,
			COUNT(data4_2), &outsize);
	g_assert(outsize == COUNT(want4));
	g_assert(out != NULL);
	g_assert_cmpmem(out, sizeof(int) * outsize, want4, sizeof(want4));
	free(out);
}

static void tc_moveZeroes()
{
	int data1[] = {0,1,0,3,12};
	int want1[] = {1,3,12,0,0};
	int data2[] = {0,0,1};
	int want2[] = {1,0,0};

	moveZeroes(data1, COUNT(data1));
	g_assert_cmpmem(data1, sizeof(data1), want1, sizeof(want1));

	moveZeroes(data2, COUNT(data2));
	g_assert_cmpmem(data2, sizeof(data2), want2, sizeof(want2));
}

static void tc_isValidSudoku()
{
	char *data1[] = {
		"53..7....",
		"6..195...",
		".98....6.",
		"8...6...3",
		"4..8.3..1",
		"7...2...6",
		".6....28.",
		"...419..5",
		"....8..79" };

	g_assert(isValidSudoku(NULL, 0, 0) == false);
	g_assert(isValidSudoku(data1, 9, 9) == true);

	data1[0] = "83..7....";
	g_assert(isValidSudoku(data1, 9, 9) == false);
}

int main(int argc, char *argv[])
{
	g_test_init(&argc, &argv, NULL);

	g_test_add_func("/array/reverse", tc_reverse);
	g_test_add_func("/array/rotateRight", tc_rotateRight);
	g_test_add_func("/array/removeDuplicates", tc_removeDuplicates);
	g_test_add_func("/array/singleNumber", tc_singleNumber);
	g_test_add_func("/array/plusOne", tc_plusOne);
	g_test_add_func("/array/twoSum", tc_twoSum);
	g_test_add_func("/array/maxProfit", tc_maxProfit);
	g_test_add_func("/array/containsDuplicate", tc_containsDuplicate);
	g_test_add_func("/array/intersect", tc_intersect);
	g_test_add_func("/array/moveZeroes", tc_moveZeroes);
	g_test_add_func("/array/isValidSudoku", tc_isValidSudoku);

	return g_test_run();
}
