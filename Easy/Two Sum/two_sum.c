#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	*returnSize = 2;
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if (target - nums[i] == nums[j])
			{
				int *sumI = (int *)malloc(sizeof(int) * *returnSize);
				sumI[0] = i;
				sumI[1] = j;
				return (sumI);
			}
		}
	}
	return NULL;
}