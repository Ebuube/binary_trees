#include "binary_trees.h"


/**
 * binary_tree_size - measure the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure
 *
 * Description: if 'tree' is NULL
 *
 * Return: the size i.e. number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0, right_size = 0;

	if (tree == NULL)
	{
		return (0);
	}

	/* The size of a leaf node is zero (0) */
	if (tree->right == NULL && tree->left == NULL)
	{
		return (1);
	}

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}
