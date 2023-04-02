int search(int* nums, int numsSize, int target){
	int	middle;
	int	difference;
	int	currIndex;

	middle = numsSize / 2;
	difference = target - nums[middle];
	if (!middle && difference)
		return (-1);
	if (difference < 0)
	{
		currIndex = search(nums, middle, target);
		if (currIndex != -1)
			return (currIndex);
		return (-1);
	}
	if (difference > 0)
	{
		currIndex = numsSize % 2 == 0 ? search(nums + middle, middle, target) : search(nums + middle + 1, middle, target);
		if (currIndex != -1)
			return (numsSize % 2 == 0 ? currIndex + middle : currIndex + middle + 1);
		return (-1);
	}
	return (middle);
}
