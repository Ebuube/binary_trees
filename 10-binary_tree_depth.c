#include "binary_trees.h"

/**
 * binary_tree_depth - measure the depth of a node in a binary tree
 * @tree: tree to measure
 *
 * Description: the root node has a depth of zero (0)
 * If 'tree' is NULL, return 0
 *
 * Return: the depth of the node in the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	if (tree->parent == NULL)
	{/* root node has a depth of zero (0) */
		return (0);
	}

	return (binary_tree_depth(tree->parent) + 1);
}
