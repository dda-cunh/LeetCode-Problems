int uniqueLen(int *nums, int numsSize, int *nState)
{
	int len = 0;

	for (int i = 0; i < numsSize; i++)
	{
		int absolute = nums[i];
		if (absolute < 0)
			absolute = (absolute * -1) + 100;
		if (!nState[absolute])
		{
			nState[absolute] = 1;
			len++;
		}
	}
	return (len);
}

int removeDuplicates(int *nums, int numsSize)
{
	int i;
	int absolute = 200;
	int nState[201] = {0};
	int len = uniqueLen(nums, numsSize, nState);

	for (i = 0; i < len; i++)
	{
		while (absolute > 100 && !nState[absolute])
			absolute--;
		if (absolute == 100)
			break ;
		nums[i] = (absolute-- * -1) + 100;
	}
	absolute = 0;
	for (i = i; i < len; i++)
	{
		while (absolute <= 100 && !nState[absolute])
			absolute++;
		nums[i] = absolute++;
	}
	return (len);
}
