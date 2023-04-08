int	ind = 0;
int	nodeSize = 0;

struct TreeNode
{
	int				val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

void  nodeCount(struct TreeNode *root)
{
	if (root)
	{
		nodeCount(root->left);
		nodeSize++;
		nodeCount(root->right);
	}
}

void	inorder(struct TreeNode *root, int *arr)
{
	if (root)
	{
		inorder(root->left, arr);
		arr[ind++] = root->val;
		inorder(root->right, arr);
	}
}

int	*inorderTraversal(struct TreeNode *root, int *returnSize)
{
	int *inorderArr;

	nodeCount(root);
	*returnSize = nodeSize;
	inorderArr = (int *)malloc(sizeof(int) * nodeSize);
	nodeSize = 0;
	inorder(root, inorderArr);
	ind = 0;
	return(inorderArr);
}
