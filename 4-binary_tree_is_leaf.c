#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if a node is a leaf
 * @node: pointer to the node to check
 *
 * Description: if node is NULL, return 0
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int ret = 0;

	if (node == NULL)
	{
		return (0);
	}
	if (node->left == NULL && node->right == NULL)
	{/* A leaf node has no children */
		ret = 1;
	}

	return (ret);
}
