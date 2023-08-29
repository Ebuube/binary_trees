#include "binary_trees.h"

/**
 * binary_tree_is_full - check if a binary tree is full
 * @tree: a pointer to the root node of the tree
 *
 * Description: if 'tree' is NULL, return 0
 * balance tree - all nodes except the leaf nodes has either 0 or 2 nodes
 *
 * Return: 1 if tree is full else, 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int ret = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{/* a leaf node is balanced */
		return (1);
	}

	if (binary_tree_is_full(tree->left) &&
		binary_tree_is_full(tree->right))
	{
		ret = 1;
	}
	else
		ret = 0;

	return (ret);
}
