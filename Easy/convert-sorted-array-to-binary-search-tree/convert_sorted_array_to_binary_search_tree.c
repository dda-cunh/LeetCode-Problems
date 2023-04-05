#include <stdlib.h>

struct TreeNode {
	int             val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *toBST(int *nums, int start, int size)
{
	if (size <= 0) {
		return (NULL);
	}
	int mid = start + size / 2;
	struct TreeNode *node = malloc(sizeof(struct TreeNode));
	node->val = nums[mid];
	node->left = toBST(nums, start, mid - start);
	node->right = toBST(nums, mid + 1, size - (mid - start) - 1);
	return node;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize){
	return toBST(nums, 0, numsSize);
}
