struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
 };

bool	checkSymm(struct TreeNode *left, struct TreeNode *right)
{
	if ((!left && right) || (left && !right))
		return (0);
	if (left && right)
		return (left->val == right->val)
		&& checkSymm(left->left, right->right)
		&& checkSymm(left->right, right->left);
	return (1);
}

bool	isSymmetric(struct TreeNode *root){
	struct TreeNode *left = root->left;
	struct TreeNode *right = root->right;

	if (!left && !right)
		return (1);
	if (!left || !right || left->val != right->val)
		return (0);
	if (!checkSymm(left, right))
		return (0);
	return (1);
}
